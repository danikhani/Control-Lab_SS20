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
%% Totzeit
Ts = 0.005;
sys.inputdelay = 0.3

%% Diskretierieren
sys_z = c2d(sys,Ts)
