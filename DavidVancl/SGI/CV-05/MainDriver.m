f = 2;
Fs = 1000;
N = 1000;
t = 0:1/Fs:1;
t = t(1:N);

subplot(2,2,1);
x1 = sin(2*pi*t*0);
i = 1;
for n = 1:N
   x1 = x1 + ((1/i) * cos(2*pi*t*i*f - (pi/2)));
   i = i + 2;
end
plot(t,x1);

subplot(2,2,2);
F = 0:Fs/N:Fs/2-Fs/N;
X = fft(x1,N);
stem(F(1:40),1/(N/2)*abs(X(1:40)),'.');

subplot(2,2,3);
x2 = sin(2*pi*t*0);
for n = 1:N
   x2 = x2 + ((1/n) * cos(2*pi*t*n*f - (pi/2)));
end
plot(t,x2);

subplot(2,2,4);
F = 0:Fs/N:Fs/2-Fs/N;
X = fft(x2,N);
stem(F(1:40),1/(N/2)*abs(X(1:40)),'.');

saveas(gcf, 'output.png');