%% Modellparameter laden

g = 9.81;               % [m/s^2]

%% Parameter des Pendels
m_p = 0.0804;           % Masse ab Drehpunkt [kg]
l_p = 0.147;            % Pendell�nge [m]
J_d = 5.8134e-4;        % Tr�gheitsmoment mit Steineranteil [kgm^2]
mu = 8.5e-6;            % Reibwert [Nms]

l_s = 0.5;              % Schienenl�nge [m]

% Abstastzeit der Regelung
Ts = 0.005;             % [s]

%% Parameter des Wagens

% ohne Totzeit
K = 1;                  % PT1 �bertragungsfaktor 
T1 = 0.043;             % PT1 Zeitkonstante [s]

% mit Totzeit
Km = 1;                 % PT1 �bertragungsfaktor 
T1m = 0.014;            % PT1 Zeitkonstante [s]

Tt = 0.03;              % Totzeit [s]

v_max = 0.73;           % max. Geschwindigkeit des Wagens [m/s]

%% Analytisch linearisierte Zustandsraummodell aufstellen

A = [0 1 0 0; 
     0 -1/T1 0 0; 
     0 0 0 1; 
     0 m_p*l_p/(2*J_d*T1) m_p*g*l_p/(2*J_d) -mu/J_d;
     ];
 
B = [0 K/T1 0 -m_p*l_p*K/(2*J_d*T1)]';

C = [1 0 0 0; 
     0 0 1 0 
     ];

D = 0;

sys = ss(A,B,C,D)


%% Zum Vergleich: Linearisierung mit Linmod

% Anfangswerte f�r die Systemgr��en definieren
x0 = 0;
dx0 = 0;
phi0 = 0;
dphi0 = 0;

[A2,B2,C2,D2,Daten] = linmod('Aufgabe_7_Pendel_Loesung',[x0, dx0, phi0, dphi0],0)

% Achtung: Das resultierende Modell ist abh�ngig davon, ob f�r den Wagen
% ein PT1 oder PT1Tt mit den entsprechenden Parametern gew�hlt wird

