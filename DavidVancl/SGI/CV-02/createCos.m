clear all;
close all;
clc;

Fs = 20;
T = 2;
A1 = 2;
A2 = 4;
fi1 = pi/3;
fi2 = pi/4;
f1 = 4;
f2 = 2;
M = 0;

t = 0:1/Fs:T - 1/Fs;

sig1 = A1 * cos(2 * pi * f1 * t + fi1) + M;
sig2 = A2 * cos(2 * pi * f2 * t + fi2) + M;
sig12 = sig1 + sig2;

subplot(3,1,1);
stem(t,sig1);
subplot(3,1,2);
stem(t,sig2);
subplot(3,1,3);
stem(t,sig12);