clc;
clear all;
close all;

Fs=1000;%Hz
T=1;%s
t = 0:1/Fs:T-1/Fs;
N=1000;

%100;200;300;400
x=0;
x=x+cos(2*pi*(100)*t);
x=x+cos(2*pi*(200)*t);
x=x+cos(2*pi*(300)*t);
x=x+cos(2*pi*(400)*t);

f = 0:Fs/N:Fs-Fs/N;
X = fft(x,N);
subplot(2,1,1);
stem(f,abs(X)/N);
title('Spektrum signálu x');
xlabel('f[Hz]');
ylabel('|A|');

% a) průmerovací filtr délky 3
p = -2*cos(2/5*pi);
A = [1 0]; 
B = [1 p 1];

Y = filter(B, A, x);
Y = fft(Y,N);
subplot(2,1,2);
stem(f,abs(Y)/N);
title('Spektrum signálu y');
xlabel('f[Hz]');
ylabel('|A|');

%freqz( B , A , N )
%zplane(roots(B),roots(A));

saveas(gcf, 'output.png')