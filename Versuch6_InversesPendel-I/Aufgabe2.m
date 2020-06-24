clear all

%mp = 0.0804
%l = 0.147
%jd = 0.5813*10^-3
%mup = 2.2*10^-3
%ls = 0.5

%jd = mp*(l/2)^2 + 1/12*mp*l^2 + 1/4*mp*(d/2)^2


syms x_pp x_p x fi_pp fi_p fi v_soll T K g mp l jd mup ls
%x_pp = f/(mw + mp) - 0.5*(mp*l)/(mw + mp)*cos(fi)*fi_pp + 0.5*(mp*l)/(mw + mp)*sin(fi)*fi_p^2
x_pp = - x_p/T + K/T*v_soll
fi_pp = 0.5*(mp*g*l)/jd*sin(fi) - 0.5*(mp*l)/jd*cos(fi)*x_pp - mup/jd*fi_p


A = jacobian([x_p,x_pp,fi_p,fi_pp],[x,x_p,fi,fi_p])
B = jacobian([x_p,x_pp,fi_p,fi_pp],[v_soll])
