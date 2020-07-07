function m = Modusauswahl(Regler,x) %#codegen

%% Umrechnung in reale Messgrößen: phi = (-180,180]
phi = x(3);
dphi = x(4);

phi = mod(phi,2*pi);

if (phi>pi) 
    phi = -2*pi+phi;
elseif(phi<-pi)
    phi = 2*pi+phi;
end


%% Konstanten definieren

% Umrechnungsfaktor von deg in rad
DEG_ZU_RAD = pi/180;

% Winkelbereich, für den Regler aktiviert [rad]
PHI_REG_AKTIV = 20*DEG_ZU_RAD;

% Winkelgeschwindigkeitsbereich, für den Regler aktiv [rad/s]
DPHI_REG_AKTIV = 180*DEG_ZU_RAD;

% Winkelgeschwindigkeitsbereich, für den Aufschwingen aktiv [rad/s]
DPHI_AUF_AKTIV = 970*DEG_ZU_RAD;


%% Modusauswahl

if ((abs(phi) < PHI_REG_AKTIV) && (abs(dphi) < DPHI_REG_AKTIV))
    m = Regler; % Zustandsregler, LQR-Regler oder Sliding Mode Regler aktiv
elseif ((abs(phi) >= PHI_REG_AKTIV) && (abs(dphi) < DPHI_AUF_AKTIV))
    m = 2; % Aufschwingen aktiv
else
    m = 0; % Warten
end