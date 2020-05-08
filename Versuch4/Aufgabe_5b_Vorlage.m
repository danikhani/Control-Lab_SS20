%% Messdaten einlesen
load('Aufgabe_5_Kennlinie_Rohr.mat')

V2 = kennlinie_Rohr.V2;     % [%]
V3 = kennlinie_Rohr.V3;     % [%]


%% Erforderliche Variablen im Workspace
%A_Beh = 0.0287;
%B102_Initial_Volumen = 9.2*10^-3;
%B103_Initial_Volumen = 2.6*10^-3;
if ~exist('Ts');
    error('Variable Ts nicht im Workspace. Führen Sie zunächst das Simulink-Modell aus.');
end;

if ~exist('V2sim');
    error('Variable V2sim nicht im Workspace. Führen Sie zunächst das Simulink-Modell aus.');
end;

if ~exist('V3sim');
    error('Variable V3sim nicht im Workspace. Führen Sie zunächst das Simulink-Modell aus.');
end;
% T-Sim-Vektor

tsim = [0:Ts:(Ts*(length(V2)-1))]';

% Plots

figure(211);

plot(tsim,[V2sim(1:length(V2)),V3sim(1:length(V2)),V2,V3]);
grid on;
set(gca,'XMinorTick','on');
set(gca,'YMinorTick','on');
legend('V2Sim','V3Sim','V2Mess','V3Mess');
xlabel('Zeit /s');

% Simu-Modell wurde angepasst. Es müssen so lange iteraiert werden bis die
% beiden geraphen passen 
% -> Arohr = 550*10^-6