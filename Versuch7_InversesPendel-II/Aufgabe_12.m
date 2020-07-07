clear all;
%% Zustandsraum erzeugen
A = [ 0,            1,                               0,           0;
            0,          -50,                               0,           0;
            0,            0,                               0,           1;
            0, 2954700/5813, 7017652722578037/70368744177664, -22000/5813];
B = [ 0 ; 50 ; 0 ; -2954700/5813];
C = [ 1 , 0 , 0 , 0 ; 
      0 , 0 , 1 , 0 ];
D = [0;0];

sys = ss(A,B,C,D);

%% Regelungsnormalform für Sliding-Mode-Regler berechnen
[sysR,Tr] = transformation_RNF(sys)

%sysR: Zustandsraummodell in Regelungsnormalform
%Tr: Transformationsmatrix zum Überführen eines linearen
%           Zustandsraummodells in Regelungsnormalform



