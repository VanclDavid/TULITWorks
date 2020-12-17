clear all;
close all;
clc;
%---------------------------
%musim si udělat x[n]
t=0:1/10:(2-(1/10));

fre=4;

X1_10=DFT(cos(2*pi*fre*t),10);
subplot(4,2,1)
stem(0:9,abs(X1_10));

X1_20=DFT(cos(2*pi*fre*t),20);
subplot(4,2,2)
stem(0:0.5:9.5,abs(X1_20));

fre=2.5;

X2_10=DFT(cos(2*pi*fre*t),10);
subplot(4,2,3)
stem(0:9,abs(X2_10));

X2_20=DFT(cos(2*pi*fre*t),20);
subplot(4,2,4)
stem(0:0.5:9.5,abs(X2_20));

fre=12;

X3_10=DFT(cos(2*pi*fre*t),10);
subplot(4,2,5)
stem(0:9,abs(X3_10));

X3_20=DFT(cos(2*pi*fre*t),20);
subplot(4,2,6)
stem(0:0.5:9.5,abs(X3_20));

fre=7.25;

X4_10=DFT(cos(2*pi*fre*t),10);
subplot(4,2,7)
stem(0:9,abs(X4_10));

X4_20=DFT(cos(2*pi*fre*t),20);
subplot(4,2,8)
stem(0:0.5:9.5,abs(X4_20));