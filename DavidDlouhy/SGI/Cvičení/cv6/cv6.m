clear all;
close all;
clc;
%-----------------------
file='./ovcaci-housle.wav';
[x, Fs]=audioread(file);
N=256;
w=zeros(1,N);

for i=0:(N-1)
    w(i+1)=(1/2)*(1-cos((2*pi*i)/(N-1)));
end

ZCR = zeros(1, round(length(x)/128));
s=1;
e=N;
x=x';

for i=1:length(ZCR)
    celkem=0;
    if e>length(x)
        e=length(x);
    end
    for j =(s+1):e
        celkem=celkem+abs(sign(x(j))-sign(x(j-1)));
    end
    ZCR(i)=(1/(2*(N-1)))*celkem;
    s=s+128;
    e=e+128;
end
subplot(2,1,1);
plot(w);
subplot(2,1,2);
plot(ZCR);