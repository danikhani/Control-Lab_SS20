%% Gruppe 21
m_u = .9; %kg
m_s = 4.5; %kg
c_s = 177;
d_s = 14.2;
c_u = 885;

s = tf('s');
G_su = (m_u * s^2-c_u)/...
    ((d_s^2 - m_s ) * s^2 + (2*d_s*c_s - d_s )*s + (c_s^2 - c_s))


KP = 1; 
T_N = 10;
T_V = 2;
s = tf('s');
G_r = KP*( 1+ 1/ (T_N*s) +s*T_V);

G_rk =  feedback(G_su, G_r);
pzmap(G_rk)

[p,z] = pzmap(G_su)
pzmap(G_su)
G_su_zpk = zpk(G_su)