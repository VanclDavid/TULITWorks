clc;
clear all;
Fs = 8;
N = 4;

t = zeros(1,N);
for i = 0:N - 1
	t(i + 1) = i / Fs;
end

x = zeros(1,N);
for i = 0:N - 1
    x(i + 1) = round(sin(2*pi*2*t(i+1)));
end

k = 0:N - 1;
f = k * (Fs/N);
X = DFT(x,N);
plot(f,X,'o');


function X = DFT(x,N)
    X = zeros(1,N);
    for k = 0:(N - 1)
        suma = 0;
        for n = 0:(N - 1)
            suma = suma + x(n + 1) * exp((-1*((1i * 2 * pi * n * k)) / N));
        end
        X(k + 1) = abs(imag((1/N) * suma));
    end
end