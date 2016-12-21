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

fSampling = 300;
fSamplingPeriod = 1/fSampling;

ContinuousModel = ss(A,B,C,D)
DiscreteModel = c2d(ContinuousModel,fSamplingPeriod,'zoh')
[Ad, Bd, Cd, Dd] = ssdata(DiscreteModel)
Kd = dlqr(Ad,Bd,Qlqr,R)
Poles = eig(Ad)
save('Kd.mat','Kd','fSamplingPeriod','Ad','Bd','Cd','Dd')


%%
%======= Design of the discrete full order observer 

dPoles = exp(
dPoles = dPoles^speed;