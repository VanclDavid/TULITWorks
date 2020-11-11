clc;
close all;
clear all;
f=2;%Hz
Fs = 1000;
pocet = 1000;
t=0:1/Fs:1;
t=t(1:pocet);
x1=sin(2*pi*t*0);
conterx1=1;
for n=1:pocet
    x1=x1+((1/conterx1)*cos(2*pi*t*conterx1*f-(pi/2)));
    conterx1=conterx1+2;
end
subplot(2,2,1);
plot(t,x1);
subplot(2,2,2);
N = 1000;
F = 0:Fs/N:Fs/2-Fs/N;
X = fft(x1,N);
stem(F(1:40),1/(N/2)*abs(X(1:40)),'.');

x2=sin(2*pi*t*0);
conterx2=1;
for n=1:pocet
    x2=x2+((1/conterx2)*cos(2*pi*t*conterx2*f-(pi/2)));
    conterx2=conterx2+1;
end
subplot(2,2,3);
plot(t,x2);
subplot(2,2,4);
N = 1000;
F = 0:Fs/N:Fs/2-Fs/N;
X = fft(x2,N);
stem(F(1:40),1/(N/2)*abs(X(1:40)),'.');
%(1/n)*cos(2*pi*n*f*t-(pi*2))
saveas(gcf, 'output.png');