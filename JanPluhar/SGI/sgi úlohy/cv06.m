close all;
clear all;
[x,Fs] = audioread("ovcaci-housle.wav");
ZCR=zeros(floor(length(x)/128),1);
index=1;
w=[w,1/2*(1-cos(2*pi*x/255))]
for i = 1:128:length(x)-255
    suma=0;
    for j= i+1:1:i+255
        suma=suma+abs(sign(x(j))-sign(x(j-1)));
    end
    ZCR(index)=(1/2*(j-i))*suma;
    index=index+1;
end