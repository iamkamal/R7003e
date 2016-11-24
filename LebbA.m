clear all
close all
clc

%%
%====State Space Form=======
%===========================

syms theta theta_dot theta_ddot x x_dot x_ddot v g b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t V_m

c1 = K_t/(R_m*l_w);
c2 = (K_t*K_e+R_m*b_f)/(R_m*l_w^2);
c3 = (K_t*K_e+R_m*b_f)/(R_m*l_w);
c4 = m_b*l_b;
c5 = c4;
c6 = (m_w+m_b+(I_w/(l_w^2)));
c7 = (K_t/R_m);
c8 = ((K_t*K_e)+(R_m*b_f))/R_m;
c9 = c4*g;
c10 = (I_b+m_b*l_b^2);

a_11 = 0;
a_12 = -c2;
a_13 = 0;
a_14 = c3;
a_21 = 0;
a_22 = c3;
a_23 = c9;
a_24 = -c8;

A=[a_11 a_12 a_13 a_14; a_21 a_22 a_23 a_24];

gamma_11 = c6;
gamma_12 = c4;
gamma_21 = c4;
gamma_22 = c10;
GAMMA=[gamma_11 gamma_12; gamma_21 gamma_22];

beta_11 = c1;
beta_12 = 1;
beta_21 = -c7;
beta_22 = l_b;
B=[beta_11;beta_21];
%new input matrix with d
Bd = [beta_11 beta_12;beta_21 beta_22]

X = [x;x_dot;theta;theta_dot];

A_new = inv(GAMMA)*A;
B_new = inv(GAMMA)*B;
%input matrix with d (aka poke disturbance) as an additional system input
Bd_new = inv(GAMMA)*Bd

F=[0 1 0 0;
    A_new(1,:);
    0 0 0 1;
    A_new(2,:)];
G=[0;
    B_new(1);
    0;
    B_new(2)];

%input matrix with d (aka poke disturbance) as an additional system input
Gd = [0 0; Bd_new(1,:);0 0;Bd_new(2,:)];

H=[0 0 1 0];
Hd = H;
%new matrix for task 3.7.1
H2 = [eye(size(F))];

J=[0];
Jd = [0 0];
%new matrix for task 3.7.1
J2 = [ 0 0; 0 0; 0 0; 0 0;];

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

F = double(eval(F));
G = double(eval(G));
Gd  = double(eval(Gd));

%state space representation 
[num, den] = ss2tf(F,G,H,J);
%Not relevant for the lab.
%[numd, dend] = ss2tf(F,Gd,Hd,Jd,2);

%Lab B uppgift
%Observability and controlability with ranks
% Rank_ctrb = rank(ctrb(F,G))
% Rank_obsv = rank(obsv(F,H))

%%
D_bad = tf(num,den)
%Checks num & den for strange values and eliminates them. 
%Compare D with D_bad.
D = minreal(D_bad)

%============Root locus plot
figure()
rlocus(D)

%============ Poles and zeros
syms s kP kI kD

poles_ol = eig(F)
% zeros_ol = [s*eye(size(F))-F -G; H J];
% zeros_ol = det(zeros_ol);

%pole zero map
figure()
pzmap(D)

%Bode plot
figure()
bode(D)

%Nyquist plot
figure()
nyquist(D)

%Pole allocation method, may be in need of some tuning?
k=num(3)
p1=poles_ol(2)
p2=poles_ol(3)
p3=poles_ol(4)
p_1=p1
p_2=p2
p_3=-p3
kD = (p3-p_3)/k
kP = (p_2*p_3+p_1*p_3-p2*p3-p1*p3)/k
kI = (p1*p2*p3-p_1*p_2*p_3)/k

s = tf('s');
%C = (kP*s + kI + kD*s^2)/s;
C = pid(kP,kI,kD)
%Matlab method for calculating sys1 * sys2 (sys = tf system)
W = series(C,D)

G = W/(1+W)

figure()
bode(G)

figure()
nyquist(G)