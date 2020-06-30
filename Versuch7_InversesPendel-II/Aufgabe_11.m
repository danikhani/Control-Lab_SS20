clear all;
%% Zustandsraum erzeugen
A = [ 0,            1,                               0,           0;
            0,          -50,                               0,           0;
            0,            0,                               0,           1;
            0, 2954700/5813, 7017652722578037/70368744177664, -22000/5813];
B = [ 0 ; 50 ; 0 ; -2954700/5813];
C = [ 1 , 0 , 0 , 0 ; 
      0 , 0 , 1 , 0 ];
D = [0;0];

sys = ss(A,B,C,D);

%% Zustandsregler mit LQR
Ts = 0.005;

%Gewichte
Q = diag([1, 0.1, 10, 0.1]);
R = 100;

[K,S,E] = lqrd(A,B,Q,R,Ts)





