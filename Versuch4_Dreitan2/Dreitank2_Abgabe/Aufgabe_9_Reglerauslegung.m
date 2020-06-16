clear all
load('Aufgabe_9_linsys1.mat')

s = tf('s');
G_0 = linsys1*exp(-s*1.1); %Totzeit 1,1sec beachten
sisotool(G_0);