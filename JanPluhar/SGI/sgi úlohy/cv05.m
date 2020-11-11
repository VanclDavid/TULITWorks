clear all;
close all;
N = 1000;
Fs=1000;
f=2;
t=0:1/Fs:1;
t=t(1:end-1);
x1=0;
x2=0;
index=1;
for i = 1:N
    x1=x1+(1/index*cos(2*pi*index*f*t-pi/2));
    x2=x2+(1/i*cos(2*pi*i*f*t-pi/2));
    index=index+2;
end
subplot(2,2,1)
plot(t,x1);
F = 0:Fs/N:Fs/2-Fs/N;
X = fft(x1,N);
subplot(2,2,2)
stem(F(1:40),1/(N/2)*abs(X(1:40)),'.');

subplot(2,2,3)
plot(t,x2);
X2 = fft(x2,N);
subplot(2,2,4)
stem(F(1:40),1/(N/2)*abs(X(1:40)),'.');
%saveas(gcf, 'output.png');