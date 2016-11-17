clear all
close all
clc
%% 
%===============State - space form
%Parametric representation

syms theta theta_dot theta_ddot x x_dot v g b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t

x_ddot = (l_w*b_f*theta_dot + (K_e*K_t*l_w*theta_dot/R_m) ...
    + m_b*l_b*(l_w^2)*sin(theta)*(theta_dot^2)...
    - m_b*l_b*(l_w^2)*cos(theta)*theta_ddot - b_f*x_dot...
    - (K_t*K_e*x_dot/R_m) )*1/((m_b+m_w)*(l_w^2)+I_w)

x_ddot= -(b_f*x_dot - b_f*l_w*theta_dot + (K_e*K_t*x_dot)/R_m + l_b*l_w^2*m_b*theta_ddot*cos(theta)...
    - (K_e*K_t*l_w*theta_dot)/R_m - l_b*l_w^2*m_b*theta_dot^2*sin(theta))/((m_b + m_w)*l_w^2 + I_w)

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

M = [0 1 0 0;
    0 -(D+G*C)/(1-C*H) -(C*I)/(1-C*H) (A-C*F)/(1-C*H);
    0 0 0 1;
    0 (G+H*D)/(1-C*H) (I)/(1-C*H) (F-H*A)/(1-C*H)]
x = [x; x_dot; theta; theta_dot]
N = [ 0; (E-C*J)/(1-C*H); 0; -(J+H*E)/(1-C*H)]
u = [v]

P = M*x + N*u
%%
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
theta_b=0;

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

syms theta theta_dot theta_ddot x x_dot v

% M = system matrix
% N = input matrix
% O = output matrix
% P = scalar matrix aka direct transmission term.
% X,u = system state variables

M = [0 1 0 0;
    0 -(D+G*C)/(1-C*H) -(C*I)/(1-C*H) (A-C*F)/(1-C*H);
    0 0 0 1;
    0 (G+H*D)/(1-C*H) (I)/(1-C*H) (F-H*A)/(1-C*H)]
%X = [x; x_dot; theta; theta_dot]
N = [ 0; (E-C*J)/(1-C*H); 0; -(J+H*E)/(1-C*H)]
O = [0 0 1 0]   % önskad output är vinkeln
P = [0]     % Önskat output beror ej på input
%u = [v]

%==== State space form to transfer function form
% a = transfer function numerator
% b = Transfer function denumerator
[a,b] = ss2tf(M,N,O,P)
% x_ddot= -(b_f*x_dot - b_f*l_w*theta_dot + (K_e*K_t*x_dot)/R_m + l_b*l_w^2*m_b*theta_ddot*cos(theta)...
%     - (K_e*K_t*l_w*theta_dot)/R_m - l_b*l_w^2*m_b*theta_dot^2*sin(theta))/((m_b + m_w)*l_w^2 + I_w)
