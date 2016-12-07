clear all
close all

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
Bd = [beta_11 beta_12;beta_21 beta_22];

X = [x;x_dot;theta;theta_dot];

A_new = inv(GAMMA)*A;
B_new = inv(GAMMA)*B;
%input matrix with d (aka poke disturbance) as an additional system input
Bd_new = inv(GAMMA)*Bd;

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

save('Gmatrix.mat','G')
save('Fmatrix.mat','F')


%state space representation 
[num, den] = ss2tf(F,G,H,J);

%%
D_bad = tf(num,den);
%Checks num & den for strange values and eliminates them. 
%Compare D with D_bad.
D = minreal(D_bad);

%============Root locus plot
figure()
subplot(2,2,1)
rlocus(D)

%============ Poles and zeros
syms s kP kI kD

poles_ol = eig(F)
% zeros_ol = [s*eye(size(F))-F -G; H J];
% zeros_ol = det(zeros_ol);

%pole zero map

%figure()
subplot(2,2,2)
pzmap(D)

%Bode plot
%figure()
subplot(2,2,3)
bode(D)

%Nyquist plot
%figure()
subplot(2,2,4)
nyquist(D)
%%
%Pole allocation method, may be in need of some tuning?
k=num(3);
p1=poles_ol(2);
p2=poles_ol(3);
p3=poles_ol(4);
p_1=p1
p_2=p2 
p_3=-p3
kD = (p3-p_3)/k;
kP = (p_2*p_3+p_1*p_3-p2*p3-p1*p3)/k;
kI = (p1*p2*p3-p_1*p_2*p_3)/k;

s = tf('s');
C = (kP*s + kI + kD*s^2)/s;
%C = pid(kP,kI,kD,tf)
%Matlab method for calculating sys1 * sys2 (sys = tf system)
W = series(C,D);

Gsys = W/(1+W);
pc = [0;p_1; p_2; p_3]

K = acker(F,G,pc);

save('pc.mat','pc')
figure()
subplot(2,2,1)
bode(Gsys)


subplot(2,2,2)
nyquist(Gsys)


subplot(2,2,3)
margin(Gsys)


subplot(2,2,4)
impulse(Gsys)
%%
%===========Discretization
%Sample time calculations

bf = bandwidth(Gsys)
TsM = 25; %Sample time scalar (rule of thumb for ZOH approximation) 
Ts = 1/( TsM*bf)

%%
%Dominant second order pole placement design
Mp = 0.15;          %overshoot in %
ts = 1;             %settling time

zeta = 0.5;         %damping coefficient
             
Sigma = 4.6/ts      %Sigma     
Mpcalc = exp(-pi*zeta/sqrt(1-zeta^2))       %overshoot from damping coefficient 
zcalc = sqrt(log(Mp)/(log(Mp)-pi()^2))      %Damping factor from overshoot specification
co1 = 2*zeta*Sigma;             %coefficients s^1
co2 = Sigma^2;                  %coefficient s^0
syms a
solve(a^2 + co1*a + co2,'a')        %second order dominant poles

%The two dominante poles are replacing the two poles closest to the origin

%%
%{
%============Plot figures 
afFigurePosition = [1 1 10 6]

figure()
plot(x_w.time, x_w.data);
title('x_w'); xlabel('time'); ylabel('meters')
legend('Non Linear Continuous', 'Linear Continuous ', 'Non Linear Discrete', 'Linear Discrete', 'Location','northwest')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabA_LinearizedBot_Simulink_x_w.eps');

% 
% figure()
% plot(theta_b.time, theta_b.data * 180 / pi);
% title('\theta_b'); xlabel('time'); ylabel('degrees')
% set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
% set(gcf, 'PaperPositionMode', 'auto');
% print('-depsc2', '-r300', 'LabA_LinearizedBot_Simulink_theta_b.eps');

figure()
plot(theta_btest.time, theta_btest.signals.values * 180 / pi);
title('\theta_b'); xlabel('time'); ylabel('degrees');
legend('Non Linear Continuous', 'Linear Continuous ', 'Non Linear Discrete', 'Linear Discrete', 'Location','northwest');
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
print('-depsc2', '-r300', 'LabA_LinearizedBot_Simulink_theta_b.eps');

figure()
plot(d.time, d.data);
title('d'); xlabel('time'); ylabel('Newton');
legend('Non Linear Continuous', 'Linear Continuous ', 'Non Linear Discrete', 'Linear Discrete', 'Location','northwest')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
axis([0, 0.2, 0.828, 0.83]);
print('-depsc2', '-r300', 'LabA_LinearizedBot_Simulink_d.eps');

figure()
plot(v_m.time, v_m.data);
title('v_m'); xlabel('time'); ylabel('Volt')
legend('Non Linear Continuous', 'Linear Continuous ', 'Non Linear Discrete', 'Linear Discrete', 'Location','northwest')
set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
axis([-inf, inf, 0, 250]);
print('-depsc2', '-r300', 'LabA_LinearizedBot_Simulink_v_m.eps');

%}