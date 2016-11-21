clear all;
close all;
clc;

% DO NOT MODIFY THIS!
iNumberOfEncoderSteps	= 720;
fGyroConversionFactor	= -1/131;
fWheelRadius			= 0.0216; % [m]
load('GyroBias.mat');

% if you want, modify this
fSamplingPeriod			= 0.005; % note: 0.005 is the fastest sampling time with the default mpu5060 library settings

% load the PID values
% kP = -67.2266;
% kI = -375.9749;
% kD = -0.1413;
kP = -67.2266;
kI = -375.9749;
kD = -0.1413;

