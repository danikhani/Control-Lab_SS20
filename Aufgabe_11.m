%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% IRT Regelunsgtechnisches Labor
% Aufgabe 9 - Vorlage
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

%% Aufgabe 11

%--------------------------------------------
% G_(z,u)(s)

% Koeffizienten des Zählerpolynoms
% b1_z = ;
% b0_z = ;
% 
% % Koeffizienten des Nennerpolynoms
% a4_z = ;
% a3_z = ;
% a2_z = ;
% a1_z = ;
% a0_z = ;

% Gsz = tf([b1_z,b0_z],[a4_z,a3_z,a2_z,a1_z,a0_z]);
Gsz = c_u*(d_s*s+c_s)/((m_s*s^2+d_s*s+c_s)*(m_u*s^2+d_s*s+c_s+c_u)-(d_s*s+c_s)^2);
%--------------------------------------------
% Reglerauslegung mit dem SISO-Tool
sisotool(Gsz);
G_PID = 2.5502*(1+0.15*s+ 0.077^2*s^2)/s