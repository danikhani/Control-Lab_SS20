clear all

syms U_P101 U_V101 U_V106 f(U_P101) f(U_V101) f(U_V106)  c V_2 V_3 V_4
V_punkt_2 = f(U_P101) - f(U_V101)*c*(V_2 - V_3)^0.5
V_punkt_3 = f(U_V101)*c*(V_2 - V_3)^0.5 - c*(V_3 - V_4)^0.5
V_punkt_4 = c*(V_3 - V_4)^0.5 - f(U_V106)


A = jacobian([V_punkt_2,V_punkt_3,V_punkt_4],[V_2,V_3,V_4])
B = jacobian([V_punkt_2,V_punkt_3,V_punkt_4],[U_P101,U_V101,U_V106])