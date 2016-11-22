format short;

syms gamma alfa beta;
syms I_w l_w m_b l_b g b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t;

gamma = zeros(2,2);
alfa = zeros(2,4);
beta = zeros(2,1);

% Gamma
g11 = (I_w/l_w)+l_w*m_b+l_w*m_w ;
g12 = m_b*l_w*l_b;
g21 = m_b*l_b;
g22 = I_b+(m_b*l_b^2);

% Alfa
a11 = 0;
a12 = -((K_e*K_t)/(R_m*l_w)) - (b_f/l_w);
a13 = 0;
a14 = b_f+((K_e*K_t)/R_m);
a21 = 0;
a22 = (K_e*K_t)/(R_m*l_w)+(b_f/l_w);
a23 = m_b*l_b*g;
a24 = -b_f-((K_e*K_t)/R_m);

% Beta
b1 = K_t/R_m;
b2 = -K_t/R_m;


b11 = K_t/R_m;
b21 = -K_t/R_m;
b12 = l_w;
b22 = l_b;

gamma = [g11 g12;
        g21 g22];

alfa = [a11 a12 a13 a14;
        a21 a22 a23 a24];

beta = [b1;
        b2];

beta_d = [b11 b12;
        b21 b22];



%A, B, C = 0;

%sym(gamma) = 0;
%sym(alfa) = 0;
%sym(beta) = 0;

g   = 9.8;
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

beta_new = inv(gamma) * beta;
alfa_new = inv(gamma) * alfa;
beta_d_new = inv(gamma) * beta_d;


A = [0 1 0 0;
    alfa_new(1,:);
    0 0 0 1;
    alfa_new(2,:)];

B = [0;
    beta_new(1);
    0;
    beta_new(2)];
Bd = [0 0; 
    beta_d_new(1, :);
    0 0;
    beta_d_new(2, :)];
A=double(eval(A));    
B=double(eval(B));
Bd=double(eval(Bd)); 
C = [0 0 1 0];
Cf = [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1];
D = 0;
Dd = [0 0; 0 0;0 0; 0 0];

% Observability and controlability with ranks
% Rank_ctrb = rank(ctrb(A,B));
% Rank_obsv = rank(obsv(A,C));

stateSpace = ss(A,B,C,0);
[num,den] = ss2tf(A,B,C,D);

% Poles
poles = eig(A);

% Plot poles and zeros
transferFunction = tf(num,den);
%pzmap(transferFunction);
Gs=tf(ss(A,B,C,D));

s=tf('s')
 
  Gs=      ( -90.03*s)/(  s^3 + 475*s^2 - 62.02*s -1.5371e04);
  Gns=  ( 90.03*s)/(  -s^3 + 475*s^2 + 62.02*s -1.5371e04);

%[b,a] = ss2tf(A,B,C,D);

%b = [0 0 -90.027543571354485 0]
%a = [1 475 -62 -15371]
%sys = tf(b,a);

p1=-470;
p2=-5.66;
p_1=p1;
p_2=p2;
p3=5.72;
p_3=-7;

kD = (p3-p_3)/-90
kP = (p_2*p_3+p_1*p_3-p2*p3-p1*p3)/-90
kI = (p1*p2*p3-p_1*p_2*p_3)/-90


%kP = -51.9083;
%kD = 10.6629;
%kI = -51.3611;
PID = pid(kP, kI, kD);
pidSystem = feedback(transferFunction, PID);

%figure
%bodeplot(pidSystem)
%figure
%impulse(pidSystem)
%figure
%nyquist(pidSystem)

% Phase Margin (?)
bode((PID*transferFunction)/(1+(PID*transferFunction)));

%[z,x]=ss2tf( A, Bd, Cf,Dd,1)
%tf([0 20.5759 0 -727.0209],[1 475 -62 -15371 0])

