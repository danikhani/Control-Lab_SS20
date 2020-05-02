%% Regelungstechnisches Labor
% Viertelfahrzeug Aufgabe 8
% ©Autor: Gruppe 21
%         Florian Eichhorn
%         Danial Hezarkhani
%         Kholoud Ghlissi
%         Hossein Omid Beiki

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
[Polstellen_Regelstrecke,z] = pzmap(Gsu);
pzmap(Gsu)

%% Regler (PID)
% um die Pollstellen der Regelstrecke zu kompensieren müssen die Nullstelle vom Regler den Postellen der
% Regelstrecke entsprechen, damit sie sich aufheben wenn G_r mit G_s
% multipliziert wird.

% PID-Regler im Allgemeinen:
% G_r = KP*( 1+ 1/ (T_N*s) +s*T_V)
% G_r = KP*( T_N * s + 1 + s^2 *T_V*T_N)/T_N*s
% Nullstellen:  T_N * s + 1 + s^2 *T_V*T_N = 0
% T1,2 = (-T_N +- wurz(T_N^2 - 4*T_v * T_N))  / (2*T_v * T_N)
% T1 + T2 = -2/(2*T_V); 
% --> T_V = -1/(T1 + T2)
% T1 - T2 = (- wurz(T_N^2 - 4* T_V * T_N))/(T_v * T_N)
% (T1 - T2)^2 = (T_N^2 - 4* T_V * T_N)/(T_v * T_N)^2
% (T1 - T2)^2 = (T_N) (T_N - 4* T_V)/(T_v^2 * T_N^2)
% (T1 - T2)^2 =  (T_N - 4* T_V)/(T_v^2 * T_N)
% (T1 - T2)^2 =  (1 - 4* T_V/T_N)/(T_v^2)
% (T1 - T2)^2 *(T_v^2) =  (1 - 4* T_V/T_N)
% 4* T_V/T_N  =  (1 - (T1 - T2)^2 *(T_v^2))
% --> T_N  =  4* T_V/((1 - (T1 - T2)^2 *(T_v^2)))

T1 = Polstellen_Regelstrecke(1);
T2 = Polstellen_Regelstrecke(2);
T_V = -1/(T1 + T2);
T_N = 4* T_V/((1 - (T1 - T2)^2 *(T_V^2)));


KP = 1; 

s = tf('s');
G_r = KP*( 1+ 1/ (T_N*s) +s*T_V)
[p, N] = pzmap(G_r) % überprüfe ob T_v und T_N richtig bestimmt wurden

%% Phasenreserve
%offene Regelkreis mit Go
Go = Gsu*G_r
sisotool(Go)
%für -30 Grad Phasenreserve wäre Kp = -8.6783
G_pid = -8.6783 *( 1+ 1/ (T_N*s) +s*T_V)
Go=Gsu*G_pid
margin(Go)
%Hier sieht man die -30 Grad phasenreserve
G = feedback(Go,1)
%Schrittantwort von geschlossenen Regelkreis deutet auf einem Instabilen
%verhalten.
step(G)

%% backup
%G_rk =  feedback(G_su, G_r);
%pzmap(G_rk)
%G_su_zpk = zpk(G_su)