% Parameter
clear;
m_u = .9; %kg
m_s = 4.5; %kg
c_s = 177;
d_s = 14.2;
c_u = 885;


s = tf('s');
G_su_old = (m_u * s^2-c_u)/...
    ((d_s^2 - m_s ) * s^2 + (2*d_s*c_s - d_s )*s + (c_s^2 - c_s))
G_su = (m_u*s^2 + c_u)/...
    ((d_s*s + c_s)^2 - (m_s*s^2 + d_s*s + c_s)*(m_u*s^2 + d_s*s + c_s + c_u))

% skript seite 174
%Phasenreserve -30 mit P-Regler
G_r = 126.5
G_o = G_su * G_r
G_s = feedback(G_su, G_r)
m = allmargin(G_o)

figure(1)
margin(G_o)
grid
%sisotool(G_o)

%Phasenreserve 30 mit I-Regler
G_ri = 1/s * 5.8846e+06
G_oi = G_su * G_ri
n = allmargin(G_oi)

figure(2)
margin(G_oi)
grid

%sisotool(G_oi)
