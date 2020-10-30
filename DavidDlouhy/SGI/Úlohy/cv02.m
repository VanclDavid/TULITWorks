clear all; %#ok<CLALL>
close all;
clc;
%Zápis hodnot do proměnných
T = 2;%2s
f1 = 4;%4Hz
f2 = 2;%2Hz
A1 = 2;
A2 = 4;
fi1 = pi/3;
fi2 = pi/4;
Fs = 20;%20s
%Zápis hodnot do proměnných
%Kalkulace
t = 0:1/Fs:T-1/Fs;
sig1 = A1*cos(2*pi*f1*t+fi1)+0;
sig2 = A2*cos(2*pi*f2*t+fi2)+0;
sig12 = sig1+sig2;
%Kalkulace
%Vykreslení do grafu
subplot(3,1,1);
stem(t, sig1);
subplot(3,1,2);
stem(t, sig2);
subplot(3,1,3);
stem(t, sig12);
%Vykreslení do grafu