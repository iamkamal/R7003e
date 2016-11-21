clear all
close all
clc
%% 
%===============State - space form
%Parametric representation

syms theta theta_dot theta_ddot x x_dot x_ddot v g b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t V_m

%  x_ddot = (l_w*b_f*theta_dot + (K_e*K_t*l_w*theta_dot/R_m) ...
%     + m_b*l_b*(l_w^2)*sin(theta)*(theta_dot^2)...
%     - m_b*l_b*(l_w^2)*cos(theta)*theta_ddot - b_f*x_dot...
%     - (K_t*K_e*x_dot/R_m) )*1/((m_b+m_w)*(l_w^2)+I_w)
% 
%  x_ddot= -(b_f*x_dot - b_f*l_w*theta_dot + (K_e*K_t*x_dot)/R_m + l_b*l_w^2*m_b*theta_ddot*cos(theta)...
%     - (K_e*K_t*l_w*theta_dot)/R_m - l_b*l_w^2*m_b*theta_dot^2*sin(theta))/((m_b + m_w)*l_w^2 + I_w)


T_m = K_t*(V_m-K_e*(+(x_dot/l_w)-theta_dot))/R_m

T_f = b_f*((x_dot/l_w)-theta_dot)


% x_ddot = ( ((T_m-T_f)/l_w) - m_b*l_b*cos(theta)*theta_ddot ... 
%      +m_b*l_b*sin(theta)*theta_dot^2 );
% theta_ddot = T_f - T_m + m_b*l_b*g*sin(theta) - m_b*l_b*cos(theta)*x_ddot;

x_ddot = ( ((T_m-T_f)/l_w) - m_b*l_b*cos(theta)*(T_f - T_m + m_b*l_b*g*sin(theta) - m_b*l_b*cos(theta)*x_ddot) ... 
     +m_b*l_b*sin(theta)*theta_dot^2 );
theta_ddot = T_f - T_m + m_b*l_b*g*sin(theta) - m_b*l_b*cos(theta)* (( ((T_m-T_f)/l_w) - m_b*l_b*cos(theta)*theta_ddot ... 
      +m_b*l_b*sin(theta)*theta_dot^2 ));

% sin(theta)= theta
% cos(theta)= 1  
% sin(theta)*theta_dot^2 = ignored

% x_ddot_l = ((T_m-T_f)/l_w) - m_b*l_b*theta_ddot_l% + m_b*l_b*sin(theta)*theta_dot^2 
% theta_ddot_l = T_f - T_m + m_b*l_b*g*theta - m_b*l_b* 

% x_ddot_l = ((T_m-T_f)/l_w) - m_b*l_b* ( T_f - T_m + m_b*l_b*g*theta - m_b*l_b*x_ddot_l )
% 
% theta_ddot_l = T_f - T_m + m_b*l_b*g*theta  - m_b*l_b*((T_m-T_f)/l_w) + m_b*l_b* m_b*l_b*theta_ddot_l

%Nya koefficienter från equations of motion
c1 = K_t*l_w/ ( R_m * (I_b + (l_w^2)*(m_w+m_b)));
c2 = (K_t*K_e + R_m*b_f)/( R_m * (I_b + (l_w^2)*(m_w+m_b)));
c3 = l_w*c2;
c4 = m_b*l_b*(l_w^2)/((I_b + (l_w^2)*(m_w+m_b)));
c5 = K_t/(R_m*(I_b+(l_b^2)*m_b));
c6 = (b_f*R_m+K_t*K_e)/(l_w*R_m*(I_b+(l_b^2)*m_b));
c7 = (b_f*R_m+K_t*K_e)/(R_m*(I_b+(l_b^2)*m_b));
c8 = m_b*l_b*g/(I_b+(l_b^2)*m_b);
c9 = m_b*l_b/(I_b+(l_b^2)*m_b);
c10= c4;
%%

%linjäriserat system kring theta=0
%matriserna nedan ges på formen [x x_dot theta theta_dot Vm]
theta_ddot_l2 = [0, (c6+c9)*c2/(1-c9*c4), (-c9*c3)/(1-c9*c4), (-c9*c1)/(1-c9*c4), (-c5-c9*c1)/(1-c9*c4)]
x_ddot_l2 = [0 , -(c2+c4*c6)/(1-c4*c9), c4*c8/(1-c4*c9), (c3+c4*c7)/(1-c4*c9), (c4*c5)/(1-c4*c9) ] 


%x_ddotm är system matrisen 
% [x_ddotm] = equationsToMatrix([x_ddot_l],[x x_dot theta theta_dot V_m])
% 
% [theta_ddotm] = equationsToMatrix([theta_ddot_l],[x x_dot theta theta_dot V_m])

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


%räknar ut numeriska värden
x_ddot_l2n = vpa(subs(x_ddot_l2))
theta_ddot_l2n = vpa(subs(theta_ddot_l2))
M3n = [0 1 0 0;
    x_ddot_l2n(1:4);
    0 0 0 1;
    theta_ddot_l2n(1:4)]
N3n = [0 ; x_ddot_l2n(5) ; 0; theta_ddot_l2n(5)];

%konverterar från SYM till double precision
M3n = double(M3n)
N3n = double(N3n)

O1 = [ 0 0 1 0];
P1 = [0];
% Zero pole gain representation av systemet
[z3,p3,k3]=ss2zp(M3n,N3n,O1,P1)
pzmap(M3n,N3n,O1,P1)


%%

syms s ze theta theta_dot theta_ddot x x_dot v kP kD kI


% M = system matrix
% N = input matrix
% O = output matrix
% P = scalar matrix aka direct transmission term.
% X,u = system state variables
% x_dot = M*x + N*u
% y = O*x + P*u
% M = [0 1 0 0;
%     0 -(D+G*C)/(1-C*H) -(C*I)/(1-C*H) (A-C*F)/(1-C*H);
%     0 0 0 1;
%     0 (G+H*D)/(1-C*H) (I)/(1-C*H) (F-H*A)/(1-C*H)]
% %X = [x; x_dot; theta; theta_dot]
% N = [ 0; (E-C*J)/(1-C*H); 0; -(J+H*E)/(1-C*H)]
% O = [0 0 1 0]   % önskad output är vinkeln
% P = [0]     % Önskat output beror ej på input
% %u = [v]§

%==== State space form to transfer function form
% a=ss(M,N,O,P)       %
a1=ss(M3n,N3n,O1,P1)

% b = transfer function numerator
% c = Transfer function denumerator
% [b,c] = ss2tf(M,N,O,P)
[b1,c1] = ss2tf(M3n,N3n,O1,P1)

% Characteristic polynomial deffined with det(s*I-M)=0 eq 7.59a 6ed
% cP = simplify(det(s*eye(size(M))-M))
cP1 = simplify(det(s*eye(size(M3n))-M3n))

%==============Zeros of the system
% zMa = [ (s*eye(size(M))-M) -N; O P]
% zeros = simplify(det(zMa)) 

zMa1 = [ (s*eye(size(M3n))-M3n) -N3n; O1 P1]
zeros1 = simplify(det(zMa1)) 

%==============State space rep to zero pole gain rep.
% [z,p,k]=ss2zp(M,N,O,P)

Cn = kP*s + kI + kD*s^2
Cd = s

% Dd = cP
% Dn = zeros

Dd1 = cP1
Dn1 = zeros1

Dd11=s*(s+21.4031)*(s-12.4884)*(s+0.6639)
Dn11= s*(s+4.0477)
% CDnd = Cd*Dd + Cn*Dn
CDnd1 = Cd*Dd1 + Cn*Dn1
CDnd11 = Cd*Dd11 + Cn*Dn11
%%


[a1,b1] = coeffs(cP1,s)
[a2,b2] = coeffs(collect(CDnd1),s)

%funkar inte
%[a3,b3]=equationsToMatrix([a1,a2(1:4)],[kP,kI,kD])
%ki = linsolve(a3,b3)