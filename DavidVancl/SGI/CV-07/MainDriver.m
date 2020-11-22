clear all;
clc;

Fs = 10;
N = 10; 
t = 0:1/Fs:(2 - 1/Fs);

X1_10 = DFT(cos(2*pi*4*t),N);
X2_10 = DFT(cos(2*pi*2.5*t),N);
X3_10 = DFT(cos(2*pi*12*t),N);
X4_10 = DFT(cos(2*pi*7.25*t),N);

subplot(4,2,1);
stem(0:9,abs(X1_10));
subplot(4,2,2);
stem(0:9,abs(X2_10));
subplot(4,2,3);
stem(0:9,abs(X3_10));
subplot(4,2,4);
stem(0:9,abs(X4_10));

N = 20;
X1_20 = DFT(cos(2*pi*4*t),N);
X2_20 = DFT(cos(2*pi*2.5*t),N);
X3_20 = DFT(cos(2*pi*12*t),N);
X4_20 = DFT(cos(2*pi*7.25*t),N);

subplot(4,2,5);
stem(0:0.5:9.5,abs(X1_20));
subplot(4,2,6);
stem(0:0.5:9.5,abs(X2_20));
subplot(4,2,7);
stem(0:0.5:9.5,abs(X3_20));
subplot(4,2,8);
stem(0:0.5:9.5,abs(X4_20));

function X = DFT(x,N)
    X = zeros(1,N);
    for k = 0:(N - 1)
        suma = 0;
        for n = 0:(N - 1)
            suma = suma + x(n + 1) * exp((-1*((1i * 2 * pi * n * k)) / N));
        end
        X(k + 1) = (1/N) * suma;
    end
end