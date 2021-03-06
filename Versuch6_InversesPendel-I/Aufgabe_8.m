clear all
%% Zustandsraum aus der Aufgabe 2
A = [ 0,            1,                               0,           0;
            0,          -50,                               0,           0;
            0,            0,                               0,           1;
            0, 2954700/5813, 7017652722578037/70368744177664, -22000/5813];
B = [ 0 ; 50 ; 0 ; -2954700/5813];
C= [ 1 , 0 , 0 , 0 ; 
            0 , 0 , 1 , 0 ];
D = [ 0 ; 0 ];
        
sys = ss(A,B,C,D)
%% Stablitšt
pzmap(sys)

%% Steuerbarkeit
rank(ctrb(sys))
% voller Rang mit n =4

%% Beobachtbarkeit
rank(obsv(sys))
% voller Rang mit n =4
