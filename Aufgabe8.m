%% Gruppe 21
% Viertelfahrzeug

%% Regelstrecke
% Parameter
m_u = .9; %kg
m_s = 4.5; %kg
c_s = 177;
d_s = 14.2;
c_u = 885;

s = tf('s');
G_su = (m_u * s^2-c_u)/...
    ((d_s^2 - m_s ) * s^2 + (2*d_s*c_s - d_s )*s + (c_s^2 - c_s))

[Polstellen,z] = pzmap(G_su);
pzmap(G_su)

%%
% um das zu kompensieren muss die Nullstelle von Regler der Postelle der
% Regelstrecke entsprechen damit sie sich aufheben:

T1 = Polstellen(1);
T2 = Polstellen(2);
T_V = -(T1 + T2);
T_N = 4* T_V/((1 - (T1 - T2)^2 *(T_V^2)));

% T1,2 = (-T +- wurz(T_N^2 - 4*T_v * T_N))  / (2*T_v * T_N)
% T1 + T2 = -2/(2*T_V); 
% --> T_V = -(T1 + T2)
% T1 - T2 = (- wurz(T_N^2 - 4* T_V * T_N))/(T_v * T_N)
% (T1 - T2)^2 = (T_N^2 - 4* T_V * T_N)/(T_v * T_N)^2
% (T1 - T2)^2 = (T_N) (T_N - 4* T_V)/(T_v^2 * T_N^2)
% (T1 - T2)^2 =  (T_N - 4* T_V)/(T_v^2 * T_N)
% (T1 - T2)^2 =  (1 - 4* T_V/T_N)/(T_v^2)
% (T1 - T2)^2 *(T_v^2) =  (1 - 4* T_V/T_N)
% 4* T_V/T_N  =  (1 - (T1 - T2)^2 *(T_v^2))
% T_N  =  4* T_V/((1 - (T1 - T2)^2 *(T_v^2)))


% T1*T2 = (4*T_v * T_N) /(2* T_V* T_N)

%% Regler (PID)
KP = 1; 
s = tf('s');
G_r = KP*( 1+ 1/ (T_N*s) +s*T_V)
[p, N] = pzmap(G_r) % überprüfe ob T_v und T_N richtig bestimmt wurden
% und ob die N1 und N2 den Polstellen von blabla....

%% Phasenreserve
alpha_r = 30% grad, laut Aufgabenstellung
[Gm,Pm,Wcg,Wcp] = margin(G_r)


%% backup
%G_rk =  feedback(G_su, G_r);
%pzmap(G_rk)
%G_su_zpk = zpk(G_su)