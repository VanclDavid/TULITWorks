clear all;
close all;
Fs=10;
t=0:1/Fs:(2-1/Fs);
N=10;
X1_10=DFT(cos(2*pi*4*t),10);
subplot(4,2,1)
stem(abs(X1_10));
X1_20=DFT(cos(2*pi*4*t),20);
subplot(4,2,2)
stem(abs(X1_20));

X2_10=DFT(cos(2*pi*2.5*t),10);
subplot(4,2,3)
stem(abs(X2_10));

X2_20=DFT(cos(2*pi*2.5*t),20);
subplot(4,2,4)
stem(abs(X2_20));

X3_10=DFT(cos(2*pi*12*t),10);
subplot(4,2,5)
stem(abs(X3_10));

X3_20=DFT(cos(2*pi*12*t),20);
subplot(4,2,6)
stem(abs(X3_20));

X4_10=DFT(cos(2*pi*7.25*t),10);
subplot(4,2,7)
stem(abs(X4_10));

X4_20=DFT(cos(2*pi*7.25*t),20);
subplot(4,2,8)
stem(abs(X4_20));