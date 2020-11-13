close all;
clear all;
[x,Fs] = audioread("ovcaci-housle.wav");
N=256;
ZCR=zeros(floor(length(x)/128),1);
w = zeros(1,N);
for n = 1:N
    w(n) = (1/2)*(1-cos((2*pi*(n-1))/(N-1)));
end
startIndex=1;
endIndex=128;
for i = 1:length(ZCR)
    suma=0;
    endIndex=endIndex+128;
    if(endIndex>length(x))
        endIndex=length(x);
    end
    for j = startIndex+1:1:endIndex
    suma=suma+abs(sign(x(j))-sign(x(j-1)));
    end
    ZCR(i)=(1/(2*(N-1)))*suma;
    startIndex=startIndex+128;
end
subplot(2,1,1);
plot(x);
subplot(2,1,2);
plot(ZCR);
%saveas(gcf, 'output.png');