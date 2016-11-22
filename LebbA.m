clear all
close all
clc
%%
%====State Space Form=======
%===========================

syms theta theta_dot theta_ddot x x_dot x_ddot v g b_f m_b l_b I_b m_w l_w I_w R_m L_m b_m K_e K_t V_m

c1 = K_t/(R_m*l_w)
c2 = (K_t*K_e+R_m*b_f)/(R_m*l_w^2)
c3 = (K_t*K_e+R_m*b_f)/(R_m*l_w)
c4 = m_b*l_b
c5 = c4
c6 = 1/(m_w+m_b+(I_b/(l_w^2))
c7 = (K_t/R_m)
c8 = ((K_t*K_e)+(R_m*b_f))/R_m
c9 = c4*g
c10 = 1/(I_b+m_b*l_b^2)

