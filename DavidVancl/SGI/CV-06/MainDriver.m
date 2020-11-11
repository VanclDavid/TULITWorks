clear all;
clc;

[y,Fs] = audioread('ovcaci-housle.wav');
N = 256;
w = zeros(1,N);

for n = 0:(N - 1)
    w((n + 1)) = (1/2)*(1-cos((2*pi*n)/(N - 1)));
end

ZCR = zeros(1,round(length(y) / 128));
s = 1;
e = 256;

y = y';

for n = 1:length(ZCR)
    suma = 0;
    if e > length(y)
        e = length(y);
    end
    for i = (s + 1):e
        suma = suma + abs(sign(y(i)) - sign(y(i - 1)));
    end
    ZCR(n) = (1/(2*(N - 1))) * suma;
    s = s + 128;
    e = e + 128;
end

subplot(2,1,1);
plot(w);
subplot(2,1,2);
plot(ZCR);