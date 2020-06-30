clear all;

mp = 0.0804;
l = 0.147;
jd = 0.5813*10^-3;
mup = 2.2*10^-3;
ls = 0.5;
g = 9.81;

%jd = mp*(l/2)^2 + 1/12*mp*l^2 + 1/4*mp*(d/2)^2


syms x_pp x_p x fi_pp fi_p fi v_soll T K lambda

x_pp = - x_p/T + K/T*v_soll;
fi_pp = 0.5*(mp*g*l)/jd*sin(fi) - 0.5*(mp*l)/jd*cos(fi)*x_pp - mup/jd*fi_p;


A = jacobian([x_p,x_pp,fi_p,fi_pp],[x,x_p,fi,fi_p]);
B = jacobian([x_p,x_pp,fi_p,fi_pp],[v_soll]);

%% Stablität
A1 = subs(A, fi,0);
A2 = subs(A1, x_p,0)
B1 = subs(B, fi,0)

A_new = [0 , 1 , 0 , 0;
        0, -1/T, 0 , 0;
        0, 0 , 0 , 1;
        0, 59094/5813, 7017652722578037/70368744177664, -22000/5813]
B_new = [0; K/T ; 0 ; -59094/5813 * K/T];
%stablität überprüfen
d = det(lambda*eye(4)-A_new)
gleichung = solve(d==0)


%% steuerbar
ctrb(A_new,B_new)
%% Beobachtbar
%obsv(A,B)

