%%
%%%LAB B

load('Gmatrix.mat')
load('Fmatrix.mat')
H = [ 0 0 1 0];
J = 0;

[num,den] = ss2tf(F,G,H,J);
%%
%Dominant second order pole placement design
poles_ol = eig(F);
Mp = 0.15;          %overshoot in %
ts = 1;             %settling time

zeta = 0.5;         %damping coefficient
             
Sigma = 4.6/ts;      %Sigma     
Mpcalc = exp(-pi*zeta/sqrt(1-zeta^2))       %overshoot from damping coefficient 
zcalc = sqrt(log(Mp)/(log(Mp)-pi()^2))      %Damping factor from overshoot specification
co1 = 2*zeta*Sigma;             %coefficients s^1
co2 = Sigma^2;                  %coefficient s^0
syms a
D2poles = solve(a^2 + co1*a + co2,'a') ;       %second order dominant poles
cpD2 = [D2poles(1),D2poles(2),poles_ol(3), poles_ol(2)];
cpD2 = double(cpD2)
save('cpD2.mat','cpD2');
%The two dominante poles are replacing the pole at the origin and the pole
%in the RHP.

%%
%===========Controllability and observability
%===controllability index
[Actrb,Bctrb,Cbstrb,Tctrb,kctrb] = ctrbf(F,G,H); 
Co=sum(kctrb);
%n_ctrb = rank(ctrb(F,G));

%Number of uncontrollable states
unCo = length(F)-Co
%===observability index
[Aobsv,Bobsv,Cobsv,Tobsv,kobsv] = obsvf(F,G,H)
Ob=sum(kobsv);
%ob= rank(obsv(F,H));

%number of unobservable states
unOb = length(F) - Ob

%Controllability matrix with numerical values
C_matrix = [G F*G (F^2)*G (F^3)*G];
%Observability matrix with numerical values
O_matrix = [H;H*F;H*F^2;H*F^3];

%%
%================LQR design

% weight matrix (designer defined) used to penalize undesirable states.
H1 = [10000, 0, 1000, 0];
syms s rho
% Identity matrix
I = eye(size(F));
% Open loop poles
N = det([s*I-F -G;H1 0]); 
D = det (s*I-F);
% Negative open loop poles
Nn = det([-s*I-F -G;H1 0]);
Dn = det(-s*I-F);

% Transferfunction for symmetric root locus plot
num = sym2poly(N);
den = sym2poly(D);
numSRL = sym2poly(Nn*N);
denSRL = sym2poly(Dn*D);
G_SRL= tf(numSRL,denSRL);

% Choose an suitable value for rho from the root locus plot.
figure()
rlocus(G_SRL)
axis([-13 13 -6 6]);

% Performance index matrix
R =1;
% State-cost matrix
%Q = transpose(H1)*H1;
Q = [H1(1) 0 0 0;
    0 0 0 0;
    0 0 H1(3) 0;
    0 0 0 0];
rho = 0.01;

%=======Transfer function
denPZ = sym2poly(Dn*D+rho*Nn*N);
den = sym2poly(D+rho*N);
Gsys = tf(numSRL,denPZ);

poles = pole(Gsys);
if sum(poles<0) < 4;
    poles = [0;poles(poles<0)];
else
    poles = [poles(poles<0)];
end

%Gain matrix 
Kacker  = acker(F,G,poles)

save('Kacker.mat','Kacker')

%%
%=============Full order Luenberger observer
% New output matrix 
Hnew = [1 0 0 0; 0 0 1 0];
%Pole speed factor (2-6 times faster than the closed loop poles)
Speed=10;
cpEST = Speed*poles;

Qlqr = Q*rho;
Qest = Qlqr*Speed;
denEST = sym2poly(Dn*D+Speed*rho*Nn*N);
ESTsys = tf(numSRL,denEST);

% Derives the EST poles and extracts the desired poles from the LHP.
polesEST = pole(ESTsys);
if sum(polesEST<0) < 4
    polesEST = [0;polesEST(polesEST<0)]
else
    polesEST = [polesEST(polesEST<0)]
end

%Gain matrix 
Kest  = acker(F,G,polesEST)
Kelqr = lqr(F,G,Qest,R)

% L := full order observer gain matrix 
[Lest, precest, msgest] = place(transpose(F), transpose(Hnew), cpEST)

%Lelqr = lqr(transpose(F),transpose(Hnew),Qest,[1 1])
L = transpose(Lest);
%%
%%============Reduced order Luenberger observer
syms x1 x2 theta1 theta2 x_dot X theta theta_dot u yacc_dot 

X = [x1;x2;theta1;theta2]
A = F;
B = G;
Cacc = [1 0 0 0]; %% only 1 accurate measurement, xw
%Cnacc represents the unaccurate signal
Cnacc = [0 0 1 0];
% V matrix basis completion 
V = [0 1 0 0; 0 0 1 0 ; 0 0 0 1];
Ti = [Cacc;V];
T = transpose(Ti);
z = Ti*X;

A_tilde = Ti*A*T;
B_tilde = Ti*B;
Cacc_tilde = Cacc*T;
Cnacc_tilde = Cnacc*T;

z_dot = A_tilde*z+B_tilde*u;
yacc = Cacc_tilde*z;
ynacc = Cnacc_tilde*z;

Ayy_tilde = [A_tilde(1,1)];
Ayx_tilde = [A_tilde(1,2:4)];
Axy_tilde = [A_tilde(2:4,1)];
Axx_tilde = [A_tilde(2:4,2:4)];
By_tilde = [B_tilde(1,1)];
Bx_tilde = [B_tilde(2:4,1)];
Cx_tilde = Cnacc_tilde(1,2:4);
Cy_tilde = Cnacc_tilde(1,1);

%======= Poles for the reduced order estimator
Speedd = 2
polesREST = Speedd * poles(2:4);
Lred =transpose(place(transpose(Axx_tilde),transpose([Ayx_tilde;Cx_tilde]),polesREST));
Lacc = [Lred(:,1)]
Lnacc = [Lred(:,2)]

M1 = (Axx_tilde - Lacc*Ayx_tilde - Lnacc*Cx_tilde)
M2 = (Bx_tilde-Lacc*By_tilde)
M3 = (Axy_tilde - Lacc*Ayy_tilde - Lnacc*Cy_tilde)
M4 = (Lnacc)
M5 = Lacc
M6 = T(1:4,1)
M7 = T(1:4,2:4)

kP = -61.0819;
kI = -341.4799;
kD = -0.1271;
D=[0];
C = [1 0 0 0; 0 0 1 0];

%saves all necessary paramters so it can be loaded in the simulation
%scripts.

save('M.mat','M1','M2','M3','M4','M5','M6','M7','kP','kI','kD','A','B','C','D','L')

%%
%%==========Make it discrete%%
fSamplingPeriod = 0.0050;
ContinuousModel = ss(A,B,C,D)
DiscreteModel = c2d(ContinuousModel,fSamplingPeriod,'zoh')
[Ad, Bd, Cd, Dd] = ssdata(DiscreteModel)
Kd = dlqr(Ad,Bd,Qlqr,R)

save('Kd.mat','Kd', 'fSamplingPeriod');
dPoles = exp(fSamplingPeriod.*polesEST)
dRPoles = dPoles(2:4)
[Ldest, precestd, msgestd] = place(transpose(Ad), transpose(Hnew), dPoles)
Ld = transpose(Ldest);

Cdacc = [1 0 0 0] %% only 1 accurate measurement, xw

Cdnacc = [0 0 1 0]

Ad_tilde = Ti*Ad*T
Bd_tilde = Ti*Bd
Cdacc_tilde = Cdacc*T
Cdnacc_tilde = Cdnacc*T

z_dot = Ad_tilde*z+Bd_tilde*u;
ydacc = Cdacc_tilde*z;
ydnacc = Cdnacc_tilde*z;

Adyy_tilde = [Ad_tilde(1,1)];
Adyx_tilde = [Ad_tilde(1,2:4)];
Adxy_tilde = [Ad_tilde(2:4,1)];
Adxx_tilde = [Ad_tilde(2:4,2:4)];
Bdy_tilde = [Bd_tilde(1,1)];
Bdx_tilde = [Bd_tilde(2:4,1)];

Cdx_tilde = Cdnacc_tilde(1,2:4);
Cdy_tilde = Cdnacc_tilde(1,1);

Ldred =transpose(place(transpose(Adxx_tilde),transpose([Adyx_tilde;Cdx_tilde]),dRPoles))
Ldacc = [Ldred(:,1)]
Ldnacc = [Ldred(:,2)]

Md1 = (Adxx_tilde - Ldacc*Adyx_tilde - Ldnacc*Cdx_tilde)
Md2 = (Bdx_tilde-Ldacc*Bdy_tilde)
Md3 = (Adxy_tilde - Ldacc*Adyy_tilde - Ldnacc*Cdy_tilde)
Md4 = (Ldnacc)
Md5 = Ldacc
Md6 = T(1:4,1)
Md7 = T(1:4,2:4)

%saves all necessary paramters so it can be loaded in the simulation
%scripts.
save('Md.mat','Md1','Md2','Md3','Md4','Md5','Md6','Md7','kP','kI','kD','Ad','Bd','Cd','Dd','Ld','fSamplingPeriod')
