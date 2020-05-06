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


s = tf('s');
G_su = (m_u*s^2 + c_u)/...
    ((d_s*s + c_s)^2 - (m_s*s^2 + d_s*s + c_s)*(m_u*s^2 + d_s*s + c_s + c_u))


% skript seite 174
% Phasenreserve -30 mit P-Regler
G_r = 104.2
G_o = G_su * G_r
G_s = feedback(G_su, G_r)
m = allmargin(G_o)

figure(3)
pzmap(G_su)

figure(1)
margin(G_o)
grid
%sisotool(G_su)
%sisotool(G_o)

%Phasenreserve 30 mit I-Regler
G_ri = 1/s * 800000
G_oi = G_su * G_ri
n = allmargin(G_oi)
G_si = feedback(G_oi,G_ri)


figure(2)
margin(G_oi)
grid
%sisotool(G_oi)
