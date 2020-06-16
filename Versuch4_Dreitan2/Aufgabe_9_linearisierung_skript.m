clear all
load('Aufgabe_9_linearisiertes_system.mat');

%Um die Totzeit zu beachten:
s = tf('s');
k = 1
T_t = 1.1
G_T = k*exp(-s*T_t)

G_0 = linsys1 * G_T
sisotool(G_0)