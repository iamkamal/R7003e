clear all
close all
clc
%% 
%===============State - space form
%Parametric representation

syms theta theta_dot x x_dot v g b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t V_m

%  x_ddot = (l_w*b_f*theta_dot + (K_e*K_t*l_w*theta_dot/R_m) ...
%     + m_b*l_b*(l_w^2)*sin(theta)*(theta_dot^2)...
%     - m_b*l_b*(l_w^2)*cos(theta)*theta_ddot - b_f*x_dot...
%     - (K_t*K_e*x_dot/R_m) )*1/((m_b+m_w)*(l_w^2)+I_w)
% 
%  x_ddot= -(b_f*x_dot - b_f*l_w*theta_dot + (K_e*K_t*x_dot)/R_m + l_b*l_w^2*m_b*theta_ddot*cos(theta)...
%     - (K_e*K_t*l_w*theta_dot)/R_m - l_b*l_w^2*m_b*theta_dot^2*sin(theta))/((m_b + m_w)*l_w^2 + I_w)

% A = (R_m*l_w*b_f+K_e*K_t*l_w)/(((m_b+m_w)*(l_w^2)+I_w)*R_m);
% B = (m_b*l_b*(l_w^2))/((m_b+m_w)*(l_w^2)+I_w);
% C = B;
% D = (R_m*b_f-K_t*K_e)/(((m_b+m_w)*(l_w^2)+I_w)*R_m);
% E = (K_t*l_w)/(((m_b+m_w)*(l_w^2)+I_w)*R_m);
% F = (b_f*R_m+K_t*K_e)/(R_m*(I_b+m_b*l_b^2));
% G = (K_t*K_e+b_f*R_m) / (l_w*R_m*(I_b+m_b*(l_b^2)));
% H = (m_b*l_b) / (I_b+m_b*(l_b^2));
% I = (m_b*l_b*g) / (I_b+m_b*(l_b^2));
% J = (K_t) / ((I_b+m_b*l_b^2)*R_m);

T_m = K_t*(V_m-K_e*(+(x_dot/l_w)-theta_dot))/R_m

T_f = b_f*((x_dot/l_w)-theta_dot)


% x_ddot = ( ((T_m-T_f)/l_w) - m_b*l_b*cos(theta)*theta_ddot ... 
%     +m_b*l_b*sin(theta)*theta_dot^2 );
% theta_ddot = T_f - T_m + m_b*l_b*g*sin(theta) - m_b*l_b*cos(theta)*x_ddot;
% sin(theta)= theta
% cos(theta)= 1  
% sin(theta)*theta_dot^2 = ignored

% x_ddot_l = ((T_m-T_f)/l_w) - m_b*l_b*theta_ddot_l% + m_b*l_b*sin(theta)*theta_dot^2 
% theta_ddot_l = T_f - T_m + m_b*l_b*g*theta - m_b*l_b* 

% x_ddot_l = ((T_m-T_f)/l_w) - m_b*l_b* ( T_f - T_m + m_b*l_b*g*theta - m_b*l_b*x_ddot_l )
% 
% theta_ddot_l = T_f - T_m + m_b*l_b*g*theta  - m_b*l_b*((T_m-T_f)/l_w) + m_b*l_b* m_b*l_b*theta_ddot_l
a1 = m_b+m_w+(I_w/l_w^2);
a2 = m_b*l_b
a3 = m_b*l_b*g;
a4 = I_b+m_b*l_b^2
x_ddot_l =( (T_m-T_f)*(l_w*a1)^-1 -  (a2*a1^-1)*(T_f-T_m+a3*theta)*a4^-1 )*(1+a2*a4^-1)

theta_ddot_l = (((T_f-T_m+a3*theta)*a4^-1) - (a2*a4^-1)*(T_m-T_f)*(l_w*a1)^-1) * (1-(a2^2)*(a4*a1)^-1)


% x_ddot_l = ((T_m-T_f)/l_w) -  a2*( T_f - T_m + a3*theta - a2*x_ddot_l )

%x_ddotm är system matrisen 
[x_ddotm] = equationsToMatrix([x_ddot_l],[x x_dot theta theta_dot V_m])

[theta_ddotm] = equationsToMatrix([theta_ddot_l],[x x_dot theta theta_dot V_m])

%%
M = [0 1 0 0;
    0 -(D+G*C)/(1-C*H) -(C*I)/(1-C*H) (A-C*F)/(1-C*H);
    0 0 0 1;
    0 (G+H*D)/(1-C*H) (I)/(1-C*H) (F-H*A)/(1-C*H)]
%x = [x; x_dot; theta; theta_dot]
N = [ 0; (E-C*J)/(1-C*H); 0; -(J+H*E)/(1-C*H)]
%u = [v]

%P = M*x + N*u

%Parametric numeric form

%Constant values
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

x_ddotm=subs(x_ddotm)
theta_ddotm=subs(theta_ddotm)

x_ddotmn = vpa(subs(x_ddotm))
theta_ddotmn = vpa(subs(theta_ddotm))
M1 = [0 1 0 0;
    x_ddotm(1:4);
    0 0 0 1;
    theta_ddotm(1:4)]
N1 = [0;x_ddotm(5);0;theta_ddotm(5)]

M1n=vpa(M1)
N1n=vpa(N1)

O1 = [ 0 0 1 0];

P1 = [0];

[z1,p1,k1]=ss2zp(M1n,N1n,O1,P1)

% theta_b=0;
%%
A = (R_m*l_w*b_f+K_e*K_t*l_w)/(((m_b+m_w)*(l_w^2)+I_w)*R_m);
B = (m_b*l_b*(l_w^2))/((m_b+m_w)*(l_w^2)+I_w);
C = B;
D = (R_m*b_f-K_t*K_e)/(((m_b+m_w)*(l_w^2)+I_w)*R_m);
E = (K_t*l_w)/(((m_b+m_w)*(l_w^2)+I_w)*R_m);
F = (b_f*R_m+K_t*K_e)/(R_m*(I_b+m_b*l_b^2));
G = (K_t*K_e+b_f*R_m) / (l_w*R_m*(I_b+m_b*(l_b^2)));
H = (m_b*l_b) / (I_b+m_b*(l_b^2));
I = (m_b*l_b*g) / (I_b+m_b*(l_b^2));
J = (K_t) / ((I_b+m_b*l_b^2)*R_m);

syms s ze theta theta_dot theta_ddot x x_dot v kP kD kI

% M = system matrix
% N = input matrix
% O = output matrix
% P = scalar matrix aka direct transmission term.
% X,u = system state variables
% x_dot = M*x + N*u
% y = O*x + P*u
M = [0 1 0 0;
    0 -(D+G*C)/(1-C*H) -(C*I)/(1-C*H) (A-C*F)/(1-C*H);
    0 0 0 1;
    0 (G+H*D)/(1-C*H) (I)/(1-C*H) (F-H*A)/(1-C*H)]
%X = [x; x_dot; theta; theta_dot]
N = [ 0; (E-C*J)/(1-C*H); 0; -(J+H*E)/(1-C*H)]
O = [0 0 1 0]   % önskad output är vinkeln
P = [0]     % Önskat output beror ej på input
%u = [v]§

%==== State space form to transfer function form
a=ss(M,N,O,P)       %
% b = transfer function numerator
% c = Transfer function denumerator
[b,c] = ss2tf(M,N,O,P)
% Characteristic polynomial deffined with det(s*I-M)=0 eq 7.59a 6ed
cP = simplify(det(s*eye(size(M))-M))
%==============Zeros of the system
zMa = [ (s*eye(size(M))-M) -N; O P]
zeros = simplify(det(zMa)) 
%==============State space rep to zero pole gain rep.
[z,p,k]=ss2zp(M,N,O,P)

Cn = kP*s + kI + kD*s^2
Cd = s
Dd = cP
Dn = zeros

CDnd = Cd*Dd + Cn*Dn

%%


[a1,b1] = coeffs(cP,s)
[a2,b2] = coeffs(collect(CDnd),s)

[a3,b3]=equationsToMatrix([a1,a2(2:5)],[kP,kI,kD])
% x_ddot= -(b_f*x_dot - b_f*l_w*theta_dot + (K_e*K_t*x_dot)/R_m + l_b*l_w^2*m_b*theta_ddot*cos(theta)...
%     - (K_e*K_t*l_w*theta_dot)/R_m - l_b*l_w^2*m_b*theta_dot^2*sin(theta))/((m_b + m_w)*l_w^2 + I_w)