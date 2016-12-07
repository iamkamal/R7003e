%close all;
% clear all;
clc;
load('cpD2.mat')
load('Kacker.mat')
load('Gmatrix.mat')
load('Fmatrix.mat')
%%
KD2 = acker(F,G,cpD2)
K = Kacker;
%K = KD2;
%K = [ -10.0000  -57.4908 -105.0371  -19.5009 ]
open_system('C:\Users\Johan\Documents\R7003E\R7003e\lab_B_code\LabB_ControllerOverSimulator_Continuous.slx')
set_param('LabB_ControllerOverSimulator_Continuous','SimulationCommand','start')

pause(8)

str = sprintf('Angle, Plot with rho = %f',rho);
figure()
subplot(3,1,1)
plot(x.time, x.signals.values(:,3));
title(str); xlabel('time'); ylabel('Theta')
%set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
%print('-depsc2', '-r300', 'LabB_Task461_Simulink_Theta.eps');

subplot(3,1,2)
plot(x.time, x.signals.values(:,1));
title('Distance'); xlabel('time'); ylabel('meters')
%set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
%print('-depsc2', '-r300', 'LabB_Task461_Simulink_x_w.eps');
%print('-depsc2', '-r300', 'LabB_Task461_Simulink.eps');

subplot(3,1,3)
plot(u.time, u.signals.values(:,1));
title('Motor voltage'); xlabel('time'); ylabel('voltage')
%set(gcf, 'Units', 'centimeters'); set(gcf,'Position',afFigurePosition);
set(gcf, 'PaperPositionMode', 'auto');
%print('-depsc2', '-r300', 'LabB_Task461_Simulink_x_w.eps');
print('-depsc2', '-r300', 'LabB_Task461_Simulink.eps');