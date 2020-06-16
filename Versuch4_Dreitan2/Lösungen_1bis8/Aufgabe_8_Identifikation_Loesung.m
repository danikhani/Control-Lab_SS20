%% Messdaten einlesen
load('Aufgabe_8_Sprungantwort_Pumpe.mat');

%% Eingangs- und Ausgangsverläufe plotten
figure('name','Sprungantwort')
plot(Sprungantwort_Pumpe)
grid on

%% Parameteridentifikation für PT1Tt-Verhalten mit der Funktion "tfest"
%
% Achtung: Die Ausgangsgröße wird in Liter (dm^3) angegeben

% Die für die Identifikation relevante Sprungantwort beginnt zum Zeitpunkt 
% t = 5 s. Dementsprechend müssen die Messdaten vor der Identifikation
% angepasst werden

u = Sprungantwort_Pumpe.u(500:end);
y = Sprungantwort_Pumpe.y(500:end);
data = iddata(y,u,Sprungantwort_Pumpe.Ts);

% Ausgabe der angepassten Messdaten
figure('name','cutted data')
plot(data)

% Parameteridentifikation
PT1_Pumpe = tfest(data,1,0,1.1);

% Paremeter ausgeben
T1_Pumpe = 1/PT1_Pumpe.den(2)   % T1[s]
K_Pumpe = PT1_Pumpe.num / PT1_Pumpe.den(2) % Verstärkungsfaktor
T_t_Pumpe = PT1_Pumpe.iodelay   % Totzeit

% identifiziertes System simulieren
figure('name','simData')
lsim(PT1_Pumpe,u,0:Sprungantwort_Pumpe.Ts:length(u)*Sprungantwort_Pumpe.Ts-Sprungantwort_Pumpe.Ts);
