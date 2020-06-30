aufschwingen


function u = Aufschwingen(x) %#codegen

%% Konstanten definieren

% Umrechnungsfaktor von deg in rad
DEG_ZU_RAD = pi/180;

% Wagengeschwindigkeit zum Aufschwingen [m/s]
AUFSCHWING_ACC = 0.2;


%% Umrechnung in reale Messgrößen: phi = (-180,180]
phi = x(3);
dphi = x(4);

phi = mod(phi,2*pi);

if (phi>pi) 
    phi = -2*pi+phi;
elseif(phi<-pi)
    phi = 2*pi+phi;
end


%% Pendel aufschwingen

if (abs(phi) >= 15*DEG_ZU_RAD) && (abs(dphi) < 975*DEG_ZU_RAD)
    if (abs(phi) > 178*DEG_ZU_RAD) && (abs(dphi) < 20*DEG_ZU_RAD)
        u = AUFSCHWING_ACC; % Initialbewegung
    elseif (phi > 90*DEG_ZU_RAD) && (dphi < 0)
    % Pendel ist im rechten unteren Quadranten und bewegt sich nach rechts
        u = -AUFSCHWING_ACC;
    elseif (phi < -90*DEG_ZU_RAD) && (dphi > 0) 
    % Pendel ist im linken unteren Quadranten und bewegt sich nach links
        u = AUFSCHWING_ACC;
    else
        u = 0; % Warten
    end
else
    u = 0; % Warten
end