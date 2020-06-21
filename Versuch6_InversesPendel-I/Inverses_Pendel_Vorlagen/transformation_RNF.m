function [sysR, Tr] = transformation_RNF(sys)
%transformation_RNF überführt ein lineares Zustandsraummodell mit einer
%Steuergröße in die Regelungsnormalform
%
% SYNOPSIS: [sysR, Tr] = transformation_RNF(sys)
%
% INPUT     sys: Lineares Zustandsraummodell
%         
% OUTPUT    sysR: Zustandsraummodell in Regelungsnormalform
%           Tr: Transformationsmatrix zum Überführen eines linearen
%           Zustandsraummodells in Regelungsnormalform



[A,B,C,D] = ssdata(sys);
[n,m] = size(B);
r = size(C);
r = r(1);

%Beschränkung auf eine Steuergröße, Auswahl der ersten Zeilen
b = B(:,1); 
d = D(:,1);

M = zeros(size(A));
Tr = zeros(size(A));

for k = 1:size(A)
    M(k,:) = (A^(k-1)*b)'; 
end

tz(n,1) = 1; 
t1 = M^(-1)*tz;

for k = 1:size(A)
    Tr(k,:) = t1'*A^(k-1); 
end


Ar = Tr*A*Tr^(-1);
br = Tr*b;
Cr = C*Tr^(-1);
dr = d;
         
% Ersetzen von Werten < 1e-5 durch 0
for k = 1:n
    for j= 1:n
        if abs(Ar(k,j)) < 1e-5, Ar(k,j) = 0; end
    end
    
    if abs(br(k,1)) < 1e-5, br(k,1) = 0; end
end

% Ersetzen von Werten < 1e-5 durch 0
for k = 1:r
    for j = 1:n
        if abs(Cr(k,j)) < 1e-5, Cr(k,j) = 0; end
    end
end

sysR = ss(Ar,br,Cr,dr);
