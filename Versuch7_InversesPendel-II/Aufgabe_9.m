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

sys = ss(A,B,C,D)

%% Polvorgabe
p=[-2, -1, -20-6.5j, -20+6.5j]
K = place(A,B,p)

%% Validierung
s = tf('s');
G = C*(s*eye(4)-(A-B*K))^-1*B;
%figure(1)
%step(G)
%figure(3)
%pzmap(G)
%bode(G)




