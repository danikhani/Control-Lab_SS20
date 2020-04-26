% Parameter
clear;
m_u = .9; %kg
m_s = 4.5; %kg
c_s = 177;
d_s = 14.2;
c_u = 885;


s = tf('s');

%Phasenreserve 30 mit P-Regler
G_su = (m_u * s^2-c_u)/...
    ((d_s^2 - m_s ) * s^2 + (2*d_s*c_s - d_s )*s + (c_s^2 - c_s))
G_r = 37.362
G_o = G_su * G_r
G_s = feedback(G_su, G_r)
m = allmargin(G_o)

figure(1)
margin(G_su)
grid
figure(2)
margin(G_o)
grid

%Phasenreserve 30 mit PI-Regler
G_ri = 1/s
G_oi = G_su * G_r
n = allmargin(G_oi)

figure(3)
margin(G_oi)
grid

%sisotool(G_su)

%[Gm,Pm,Wcg,Wcp] = margin(G_s)
