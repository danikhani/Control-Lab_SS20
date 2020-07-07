function u = Sliding_Mode_Regler(x) %#codegen

%% Auswahl des Schaltgesetzes für den Sliding-Mode-Regler

auswahl = 1;    % 1 ... mit sign-Funktion
                % 2 ... mit sat-Funktion

                
%% Definitionen und Initialisierung interner Variablen                 
persistent s_alt    % Speichert den Wert der Schaltfläche vom letzen Aufruf
                    % zur Behandlung des Falls s=0 der Signum-Funktion

if isempty(s_alt)   % Beim ersten Aufruf wird die Variable initialisiert 
    s_alt = 0;
end


%% Implementierung des Sliding-Mode-Reglers

u = 0;