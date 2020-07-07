function u = Sliding_Mode_Regler(x_in) %#codegen

%% Auswahl des Schaltgesetzes für den Sliding-Mode-Regler

auswahl = 1;    % 1 ... mit sign-Funktion
                % 2 ... mit sat-Funktion

                
%% Definitionen und Initialisierung interner Variablen                 
persistent s_alt    % Speichert den Wert der Schaltfläche vom letzen Aufruf
                    % zur Behandlung des Falls s=0 der Signum-Funktion

if isempty(s_alt)   % Beim ersten Aufruf wird die Variable initialisiert 
    s_alt = 0;
end


%% Benötigte Größen der Regelungsnormalform berechnen

% Letzte Zeile der Regelungsnormalform (Berechnung mit der Funktion 
% 'transformation_RNF')
f = [0, 2.32e3, 11.71, -27.04];

% Transformationsmatrix zum Überführen der linearen Zustandsraumdarstellung
% in die Regelungsnormalform (Berechnung mit der Funktion 
% 'transformation_RNF')
TR = [-4.21e-4, -1.63e-5, -4.85e-5, -1.61e-6;
      0, -4.31e-4, -1.61e-4, -4.24e-5;
      0, 1.73e-18, -4.2e-3, 2.98e-19;
      0, -2.78e-17, 3.12e-17, -4.2e-3;
     ];

% Zustände in Regelungsnormalform überführen
x = TR*x_in;  
  

%% Sliding Mode Regler

% Reglerparameter
LAMBDA = 10;
ETA = 0.05;

% Breite des linearen Bereichs für die Begrenzung (sat-Funktion)
SCHLAUCH = 0.004;

%Definition der Schaltfläche
s = x(4) + 3*LAMBDA*x(3) + 3*LAMBDA^2*x(2) + LAMBDA^3*x(1);
   
if auswahl == 2 % Sat-Funktion
    if (s < -SCHLAUCH)
        sat = -1;
    elseif (s > SCHLAUCH)
        sat = 1;
    else
        sat = s/SCHLAUCH;
    end
    % Regelgesetz
    u = -(f(1)*x(1) + (f(2)+LAMBDA^3)*x(2) + (f(3)+3*LAMBDA^2)*x(3) + (f(4)+3*LAMBDA)*x(4)) - ETA*sat;
else % Sign-Funktion
    if (s < 0)
        sign = -1;
    elseif (s > 0)
        sign = 1;
    else
        if (s_alt < 0) %falls s=0 springt sign um
            sign = 1;
        else
            sign = -1;
        end
    end

    % Regelgesetz
    u = -(f(1)*x(1) + (f(2)+LAMBDA^3)*x(2) + (f(3)+3*LAMBDA^2)*x(3) + (f(4)+3*LAMBDA)*x(4)) - ETA*sign;
end