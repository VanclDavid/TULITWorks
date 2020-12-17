clear all;
close all;
clc;
%2x cosinus a zobrazit pomocí stemu
%Nejprve definice hodnot
Fs = 16;
T = 2;
A = 1;
fi = 0;
f = 2;
t = 0:1/Fs:T-1/Fs;%odečíst poslední vzorek
sig1 = A*cos(2*pi*f*t+fi)+0;%vzorec

%Vykreslení do grafu
stem(t, sig1);
subplot(2,1,1);
plot(t, sig1);
subplot(2,1,2);
stem(t, sig1);