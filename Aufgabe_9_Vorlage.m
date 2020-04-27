%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% IRT Regelunsgtechnisches Labor
% Aufgabe 9 - Vorlage
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

close all
clear

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
b2_u = -0.9;
b1_u = 0;
b0_u = -885;

% Koeffizienten des Nennerpolynoms
a4_u = 4.05;
a3_u = 76.68;
a2_u = 4938;
a1_u = 1.257e4;
a0_u = 156645;

Gsu = tf([b2_u,b1_u,b0_u],[a4_u,a3_u,a2_u,a1_u,a0_u])

%--------------------------------------------
% Reglerauslegung mit dem SISO-Tool
sisotool(Gsu);
%sistool(g,c,h,f)
s = tf('s');
G_pid= -888.93 * (1+0.15*s)*(1+0.24*s)/s
G = feedback(Gsu,G_pid)
