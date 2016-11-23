clear all
close all
clc

%%
%====State Space Form=======
%===========================


syms theta theta_dot theta_ddot x x_dot x_ddot v g b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t V_m

%Constant values
% g = 9.8;
% b_f = 0;
% m_b = 0.381;
% l_b = 0.112;
% I_b = 0.00616;
% 
% m_w = 0.036;
% l_w = 0.021;
% I_w = 0.00000746;
% R_m = 4.4;
% L_m = 0;
% b_m = 0;
% K_e = 0.444;
% K_t = 0.470;

c1 = K_t/(R_m*l_w)
c2 = (K_t*K_e+R_m*b_f)/(R_m*l_w^2)
c3 = (K_t*K_e+R_m*b_f)/(R_m*l_w)
c4 = m_b*l_b
c5 = c4
c6 = (m_w+m_b+(I_b/(l_w^2)))
c7 = (K_t/R_m)
c8 = ((K_t*K_e)+(R_m*b_f))/R_m
c9 = c4*g
c10 = (I_b+m_b*l_b^2)

test = c4*c6*c9*c10/(1-c6*c10*c4*c4);
%test = double(eval(test))


a_11 = 0
a_12 = -c2
a_13 = 0
a_14 = c3
a_21 = 0
a_22 = c3
a_23 = c9
a_24 = -c8

A=[a_11 a_12 a_13 a_14; a_21 a_22 a_23 a_24]

gamma_11 = c6
gamma_12 = c4
gamma_21 = c4
gamma_22 = c10
GAMMA=[gamma_11 gamma_12; gamma_21 gamma_22]

beta_1 = c1
beta_2 = -c7
B=[beta_1;beta_2]

X = [x;x_dot;theta;theta_dot]

A_new = inv(GAMMA)*A
B_new = inv(GAMMA)*B

F=[0 1 0 0;
    A_new(1,:);
    0 0 0 1;
    A_new(2,:)];
G=[0;
    B_new(1);
    0;
    B_new(2)];
    
H=[0 0 1 0]

J=[0]

g = 9.8;
b_f = 0;
m_b = 0.381;
l_b = 0.112;
I_b = 0.00616;

m_w = 0.036;
l_w = 0.021;
I_w = 0.00000746;
R_m = 4.4;
L_m = 0;
b_m = 0;
K_e = 0.444;
K_t = 0.470;

F = double(eval(F))
G = double(eval(G))
 
[num, den] = ss2tf(F,G,H,J)
%% 
%=======Check num & den for strange values
num  =[num(1:3) 0 0 ]
%%
D = tf(num,den);
D = minreal(D)

%============ Poles and zeros
syms s kP kI kD

poles_ol = eig(F)
zeros_ol = [s*eye(size(F))-F -G; H J];
zeros_ol = det(zeros_ol)

%pole zero map
figure()
pzmap(D)
k=num(3)
p1=poles_ol(2)
p2=poles_ol(3)
p3=poles_ol(4)
p_1=p1;
p_2=p2;
p_3=-p3;
kD = (p3-p_3)/k
kP = (p_2*p_3+p_1*p_3-p2*p3-p1*p3)/k
kI = (p1*p2*p3-p_1*p_2*p_3)/k

%C=(kP*s + kI +kD*(s^2))/s

%CP = 1 + C*D