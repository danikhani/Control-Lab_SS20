%% Messdaten einlesen
load('Aufgabe_8_Sprungantwort_Pumpe.mat');

%% Eingangs- und Ausgangsverläufe plotten
figure('name','Sprungantwort')
plot(Sprungantwort_Pumpe)
grid on

%% Parameteridentifikation für PT1Tt-Verhalten mit der Funktion "tfest"
%
% Achtung: Die Ausgangsgröße wird in Liter (dm^3) angegeben



