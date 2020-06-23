clear all

mp = 0.0804
l = 0.147
jd = 0.5813*10^-3
mup = 2.2*10^-3
ls = 0.5

%jd = mp*(l/2)^2 + 1/12*mp*l^2 + 1/4*mp*(d/2)^2

syms x_pp x_p x fi_pp fi_p fi v_soll T k
%x_pp = f/(mw + mp) - 0.5*(mp*l)/(mw + mp)*cos(fi)*fi_pp + 0.5*(mp*l)/(mw + mp)*sin(fi)*fi_p^2
x_pp = - x_p/T + K/T*v_soll
fi_pp = 0.5*(mp*g*l)/jd*sin(fi) - 0.5*(mp*l)/jd*cos(fi)*x_pp - mup/jd*fi_p



A = jacobian([x_pp,fi_pp],[V_2,V_3,V_4])
B = jacobian([V_punkt_2,V_punkt_3,V_punkt_4],[U_P101,U_V101,U_V106])