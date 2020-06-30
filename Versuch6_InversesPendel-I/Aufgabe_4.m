clear all;
%% Matrix A und B aufstellen
mp = 0.0804;
l = 0.147;
jd = 0.5813*10^-3;
mup = 2.2*10^-3;
ls = 0.5;
g = 9.81;


syms x_pp x_p x fi_pp fi_p fi v_soll T K

x_pp = - x_p/T + K/T*v_soll;
fi_pp = 0.5*(mp*g*l)/jd*sin(fi) - 0.5*(mp*l)/jd*cos(fi)*x_pp - mup/jd*fi_p;


A = jacobian([x_p,x_pp,fi_p,fi_pp],[x,x_p,fi,fi_p]);
B = jacobian([x_p,x_pp,fi_p,fi_pp],[v_soll]);


%% Werte in Variabeln setzten:
A1 = subs(A, fi,0);
A2 = subs(A1, T, 0.02);
A_new = subs(A2, x_p,0)
B1 = subs(B, T, 0.02);
B2 = subs(B1, K, 1);
B_new = subs(B2, fi,0)

%% Polvorgabe
syms k1 k2 k3 k4 s
% wuensch polynom
nullstellen = [-2 ; -10 ; -5+6.5i ; -5-6.5i];
wuensch_koef = poly(nullstellen);
wuensch_gl = s^4 + s^3 * wuensch_koef(2) + s^2 * wuensch_koef(3) + s^1 * wuensch_koef(4) + + s^0 * wuensch_koef(5)
% char. polynom
K_R = [ k1; k2 ; k3; k4];
char_glei = det(s*eye(4) - (A_new - B_new*transpose(K_R)));
char_glei_sortiert = collect(char_glei,s)
%% Koeffizieten vergleich
char_glei_s3 =(50*k2 - (2954700*k4)/5813 + 312650/5813);
char_glei_s2 = (50*k1 + (1100000*k2)/5813 - (2954700*k3)/5813 + 36612003319084270919/409053509904760832);
char_glei_s1 = ((1100000*k1)/5813 - (175441318064450925*k2)/35184372088832 - 175441318064450925/35184372088832);
char_glei_s0 = -(175441318064450925*k1)/35184372088832;

[k1,k2,k3,k4]=solve(char_glei_s3 == wuensch_koef(2) , char_glei_s2 == wuensch_koef(3), ...
    char_glei_s1==wuensch_koef(4), char_glei_s0==wuensch_koef(5));
 k1_rund = vpa(k1,5)
 k2_rund = vpa(k2,5)
 k3_rund = vpa(k3,5)
 k4_rund = vpa(k4,5)
 
 %% Validierung
A_valid = [ 0,            1,                               0,           0;
            0,          -50,                               0,           0;
            0,            0,                               0,           1;
            0, 2954700/5813, 7017652722578037/70368744177664, -22000/5813];
B_valid = [ 0 ; 50 ; 0 ; -2954700/5813];
C_valid = [ 1 , 0 , 0 , 0 ; 
            0 , 0 , 1 , 0 ];
K_valid = [-0.26974,-1.2122,-0.70947,-0.056709];
g = tf('s');
G = C_valid*(g*eye(4)-(A_valid-B_valid*K_valid))^-1*B_valid;
pzmap(G)




