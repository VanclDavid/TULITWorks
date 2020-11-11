%START
clear all;
close all;
clc;
%START
%----------------------
%základní definice
Fs=16000;
%NOTY
c4=nota(40,4,Fs,1);
e4=nota(44,4,Fs,1);
g4=nota(47,4,Fs,1);
g4g4=nota(47,2,Fs,1);
g5=nota(59,4,Fs,1);
g5g5=nota(59,2,Fs,1);
e5=nota(56,4,Fs,1);
e5e5=nota(56,2,Fs,1);
f5=nota(57,4,Fs,1);
f5f5=nota(57,2,Fs,1);
d4=nota(42,4,Fs,1);
h4=nota(51,4,Fs,1);
h4h4=nota(51,2,Fs,1);
h5=nota(63,4,Fs,1);
h5h5=nota(63,2,Fs,1);
xx=nota(0,4,Fs,1);
%NOTY
%hudba = [c4 e4 g4 g4 ? g5 g5 ? e5];
%hudba2 = [e5 ? c4 c4 e4 g4 g4 ? g5];
%hudba3 = [g5 ? f5 f5 ? c4 c4 d4 h4];
%hudba4 = [h4 ? h5 h5 ? f5 f5 ? c4];
hudba = [voNo(c4,1) voNo(e4,1) voNo(g4g4,1) voNo(g5,1) voNo(g5g5,1) voNo(e5,1) voNo(e5e5, 1) voNo(c4, 1) voNo(c4, 1) voNo(e4, 1) voNo(g4, 1) voNo(g4g4, 1) voNo(g5, 1) voNo(g5g5, 1) voNo(f5, 1) voNo(f5f5, 1) voNo(c4, 1) voNo(c4, 1) voNo(d4, 1) voNo(h4, 1) voNo(h4h4, 1) voNo(h5, 1) voNo(h5h5, 1) voNo(f5, 1) voNo(f5f5, 1) voNo(c4,1) voNo(c4,1) voNo(e4,1) voNo(g4g4,1) voNo(g5,1) voNo(g5g5,1) voNo(e5,1) voNo(e5e5,1) voNo(c4,1) voNo(c4,1) voNo(e4,1) voNo(g4,1) voNo(g4g4,1) voNo(g5,1) voNo(g5g5,1) voNo(f5,1) voNo(f5f5,1) voNo(c4,0.9) voNo(c4,0.8) voNo(d4,0.7) voNo(h4,0.6) voNo(h4h4,0.5) voNo(h5,0.4) voNo(h5h5,0.3) voNo(f5,0.2) voNo(f5f5,0.1) voNo(c4,0.05)];
sound(hudba, Fs, 24);
%audiowrite('hudba.wav', hudba, Fs);
function ton = nota(p, n, Fs, A)
    T=1/n;
    t = 0:1/Fs:T;
    F=440*2^((p-49)/12);
    ton = A*(sin(2*pi*F*t));
end

function nota = voNo(no, vo)
nota = no*vo;
end