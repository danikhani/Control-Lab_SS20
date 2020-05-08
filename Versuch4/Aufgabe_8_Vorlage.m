
%% Messdaten einlesen
load('Aufgabe_8_Sprungantwort_Pumpe.mat');
%y = cell2mat(Sprungantwort_Pumpe.OutputData);
%u = cell2mat(Sprungantwort_Pumpe.InputData);
%Ts = cell2mat(Sprungantwort_Pumpe.Ts);
%% Eingangs- und Ausgangsverläufe plotten
figure('name','Sprungantwort')
plot(Sprungantwort_Pumpe)
grid on

%% Parameteridentifikation für PT1Tt-Verhalten mit der Funktion "tfest"
np = 1;
nz = 0;
iodelay = NaN;
sys = tfest(Sprungantwort_Pumpe,np,nz,iodelay)
[K_Pumpe,T_Pumpe] = tfdata(sys);
%Kpumpe = 0.1015
%Tpumpe = 0.1991
%Tt = 0.29

% Zum überprüfen
opt = stepDataOptions('InputOffset',50,'StepAmplitude',30);
[y,t] = step(sys,opt);
figure(2);
plot(y);








