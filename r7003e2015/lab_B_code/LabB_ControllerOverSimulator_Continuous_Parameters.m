%close all;
%clear all;
%clc;

load('Lab_A.mat');

%the following functions were used and a locus near 5 was chosen. three
%poles could be used and the fourth was set to -3. Simulations with
%different disturbances were tested and the miniseg recovered from all of
%them. success. selected_point = -4.9261 + 0.0623i

% rlocus(Gs*Gns)
% [Kopt,Poles_opt]=rlocfind(Gs*Gns)
Kopt = 75.4503 %this will be roh in the next task
%p = [-475.0523 -7.4450 -4.3458 -3 ];
%K = place(A, B, p)
K = [ -10.0000  -57.4908 -105.0371  -19.5009 ]
%K = [-9.6283  -27.0437  -12.6976   -1.6377]
W = [20 0 0 0;
    0 1 0 0;
    0 0 1000 0;
    0 0 0 2];

%[K] = lqr(A,B,W*Kopt,1,0);
