%%
%============= Labb C 
load('Fmatrix.mat')%
load('Gmatrix.mat')
load('Qlqr.mat')
A = F;
B = G;
C = [1 0 0 0;0 0 1 0];
D = [0];
R = [1];

%%
%======= LQR design of the discrete controller 
Qlqr = rho*Q;

fSamplingFrequency = 10;
fSamplingPeriod = 1/fSamplingFrequency;
ContinuousModel = ss(A,B,C,D)
DiscreteModel = c2d(ContinuousModel,fSamplingPeriod,'zoh')
[Ad, Bd, Cd, Dd] = ssdata(DiscreteModel)

[Kd,S,e ]= dlqr(Ad,Bd,Qlqr,R)
Poles = eig(Ad-Bd*Kd)

save('Kd.mat','Kd','fSamplingPeriod','Ad','Bd','Cd','Dd')

%%
%================= Task 5.3.1 =============

% Design of the discrete full order observer
% Choose the speed factor as we did in task 4.8.1, in other words
FEstSpeed = 2;

% formula for making the discrete poles X times faster.
dPoles = Poles.^FEstSpeed

% L := full order observer gain matrix 
[L, precest, msgest] = place(transpose(Ad), transpose(Cd), dPoles)
Ld = transpose(L);

% Design of the discrete reduced order observer
% Choose Speed as we did in task 4.8.1, in other words
REstSpeed = 10;

dROPoles = Poles(2:4).^REstSpeed

Cdacc = [1 0 0 0] %% only 1 accurate measurement, xw
Cdnacc = [0 0 1 0]

V = [0 1 0 0; 0 0 1 0 ; 0 0 0 1];
Ti = [Cdacc;V];
T = transpose(Ti);

Ad_tilde = Ti*Ad*T
Bd_tilde = Ti*Bd
Cdacc_tilde = Cdacc*T
Cdnacc_tilde = Cdnacc*T

Adyy_tilde = [Ad_tilde(1,1)];
Adyx_tilde = [Ad_tilde(1,2:4)];
Adxy_tilde = [Ad_tilde(2:4,1)];
Adxx_tilde = [Ad_tilde(2:4,2:4)];
Bdy_tilde = [Bd_tilde(1,1)];
Bdx_tilde = [Bd_tilde(2:4,1)];

Cdx_tilde = Cdnacc_tilde(1,2:4);
Cdy_tilde = Cdnacc_tilde(1,1);

Ldred =transpose(place(transpose(Adxx_tilde),transpose([Adyx_tilde;Cdx_tilde]),dROPoles))
Ldacc = [Ldred(:,1)]
Ldnacc = [Ldred(:,2)]

Md1 = (Adxx_tilde - Ldacc*Adyx_tilde - Ldnacc*Cdx_tilde)
Md2 = (Bdx_tilde-Ldacc*Bdy_tilde)
Md3 = (Adxy_tilde - Ldacc*Adyy_tilde - Ldnacc*Cdy_tilde)
Md4 = (Ldnacc)
Md5 = Ldacc
Md6 = T(1:4,1)
Md7 = T(1:4,2:4)


%%

%[Nxd;Nud] = [ (Ad-eye(size(Ad))) Bd; Cd Dd ]^-1 * [0;1]