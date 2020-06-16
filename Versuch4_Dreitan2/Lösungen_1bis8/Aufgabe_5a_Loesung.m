%% --- Behältergrundfläche berechnen ---

%% Messdaten einlesen

load('Aufgabe_5_Kennlinie_Behaelter.mat')

V = kennlinie_behaelter.V;      % [m^3]
h = kennlinie_behaelter.h;      % [m]

%% Kennlinie ausgeben

figure('name','Behälterkennlinie')
plot(V, h);
ylabel('Höhe h/m');
xlabel('Volumen V/m^3');
title('Kennlinie Behälter B102, B103, B104');
grid on;

%% Grundfläche der Behälter berechnen

A_Behaelter = V./h;    % [m^2]

A = mean(V(4:end)./h(4:end))    % [m^2]


