%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% IRT Regelunsgtechnisches Labor
% Inverses Pendel
% Aufgabe 6 (Parameter-identifikation) - Vorlage
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Messwerte des Sprungversuchs laden
load Aufgabe_6_Sprungversuch.mat

% Zeitverlauf
t = sprungversuch.t;

% Stellgrößenverlauf
u = sprungversuch.uy(:,1);

% Ausgangsgrößenverlauf
y = sprungversuch.uy(:,2);

% Verläufe plotten
figure('name','Sprungversuch für den Wagen')
plot(t,[u, y]);
legend('Soll-Geschwindigkeit','Ist-Geschwindigkeit')
xlabel('t in s')
ylabel('v in m/s')

% System Identification Tool öffnen
ident % oder: systemIdentification