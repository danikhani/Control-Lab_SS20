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
%% Gsu aufstellen
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

%% Gsz aufstellen
% Koeffizienten des Zählerpolynoms
 b1_z = 1.257e04;
 b0_z = 156645;
 
 % Koeffizienten des Nennerpolynoms
 a4_z = 4.05 ;
 a3_z = 76.68;
 a2_z = 4938;
 a1_z = 1.257e04;
 a0_z = 156645;

Gsz = tf([b1_z,b0_z],[a4_z,a3_z,a2_z,a1_z,a0_z])

%--------------------------------------------
%% Reglerauslegung mit dem SISO-Tool
s = tf('s');
G_PID = -12639*(1+ 0.2*s +(0.12*s)^2)/s

sisotool(Gsu,G_PID,1,Gsz);
%sistool(g,c,h,f)
%controlSystemDesigner(plant,comp,sensor,prefilt) initializes the prefilter model, F, to the SISO LTI model prefilt.

%Führungsübertragungsfunktion (wenn störgröße z = 0)
%  Gsu = G0/(1+G0) = GR*Gs/(1+GR*GS)
%Störübertragungsfunktion (wenn führungsgröße w = 0)
%  Gsz = GS/(1+G0) = GS/(1+GR*GS)

%Passender PID-Regler:




