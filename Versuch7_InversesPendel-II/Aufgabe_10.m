clear all;
%% Modellparameter laden

g = 9.81;               % [m/s^2]

%% Parameter des Pendels
m_p = 0.0804;           % Masse ab Drehpunkt [kg]
l_p = 0.147;            % Pendellänge [m]
J_d = 5.8134e-4;        % Trägheitsmoment mit Steineranteil [kgm^2]
mu = 8.5e-6;            % Reibwert [Nms]

l_s = 0.5;              % Schienenlänge [m]

% Abstastzeit der Regelung
Ts = 0.005;             % [s]

%% Parameter des Wagens

% ohne Totzeit
K = 1;                  % PT1 Übertragungsfaktor 
T1 = 0.043;             % PT1 Zeitkonstante [s]

% mit Totzeit
Km = 1;                 % PT1 Übertragungsfaktor 
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

sys = ss(A,B,C,D);
%% Diskretiesirung ohne Totzeit
sys_z = c2d(sys,Ts)
%% Diskretiesirung mit Totzeit
sys_Tt = ss(A,B,C,D,'InputDelay',Tt);
sys_zTt = c2d(sys_Tt,Ts)


