close all;
clear all;
clc;
load('pc.mat')
load('Gmatrix.mat')
load('Fmatrix.mat')
K = acker(F,G,pc)
%K = [ -10.0000  -57.4908 -105.0371  -19.5009 ]


