%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% IRT Regelunsgtechnisches Labor
% Aufgabe 7 und 8 - Vorlage
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

close all

% Parameter der Regelstrecke Viertelfahrzeug

% Massen
m_s = 4.5;             % Aufbaumasse [kg]
m_u = 0.9;             % Radmasse [kg]

% Federsteifigkeiten
c_s = 177;             % Federsteifigkeit c_s [N/m]
c_u = 885;             % Federsteifigkeit c_u [N/m]

% Dämpferkonstanten
d_s = 0.142*10^3*0.1;  % Dämpferkonstante d_s [Ns/m]


%% Teilübertragungsfunktion aufstellen

% Koeffizienten des Zählerpolynoms
b2_u = ...;
b1_u = ...;
b0_u = ...;

% Koeffizienten des Nennerpolynoms
a4_u = ...;
a3_u = ...;
a2_u = ...;
a1_u = ...;
a0_u = ...;

Gsu = tf([b2_u,b1_u,b0_u],[a4_u,a3_u,a2_u,a1_u,a0_u]);

%% Reglerauslegung

% P-Regler
Gr_P = 1;

% Offenen Regelkreis aufstellen
G0P = Gsu*Gr_P;

% Bode Plot für offenen Regelkreis
figure(1)
bode(G0P);

% Reglerauslegung ergänzen...



