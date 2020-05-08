
syms U_P101 U_V101 U_V106 f(U_P101) f(U_V101) f(U_V106) c V_2 V_3 V_4
V_punkt_2 = f(U_P101) - f(U_V101)*c*(V_2 - V_3)^0.5;
V_punkt_3 = f(U_V101)*c*(V_2 - V_3)^0.5 - c*(V_3 - V_4)^0.5;
V_punkt_4 = c*(V_3 - V_4)^0.5 - f(U_V106);

A = jacobian ([V_punkt_2,V_punkt_3,V_punkt_4],[V_2,V_3,V_4]);
B = jacobian ([V_punkt_2,V_punkt_3,V_punkt_4],[U_P101,U_V101,U_V106]);
%give number to variables
A_rohr = 550e-6;
A_beh = 0.0287;
c_zahl = A_rohr*((2*9.81)/A_beh)^0.5


% calculate the matrix A
A_zahl = subs(A, {f(U_P101),f(U_V101),f(U_V106),V_2, V_3, V_4, c},...
                {0.7972, 0.43313, 0.44772, 8e-3, 6e-3, 5e-3, c_zahl});
A_rounded = vpa(A_zahl)
% calculate the matrix B
B_zahl = subs(B, {diff(f(U_P101),U_P101), diff(f(U_V101), U_V101), diff(f(U_V106), U_V106), V_2, V_3, V_4, c},...
                 {0.0159, -0.016, 0.0228, 8e-3, 6e-3, 5e-3, c_zahl});
B_rounded = vpa(B_zahl)

x_0 = [8*10^-3; 6*10^-3;5*10^-3]
