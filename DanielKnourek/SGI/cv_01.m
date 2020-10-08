clear all;
T = 2; %s
f1 = 4; %Hz
f2 = 2; %Hz
A1 = 2;
A2 = 4;
fi1 = pi/3;
fi2 = pi/4;
Fs = 20; %Hz


t = 0:1/Fs:2;
t = t(2:end);

% f1
sig1  = A1 * cos (2 * pi * f1 * t + fi1) ;
subplot(3,1,1);
stem(t, sig1);

% f2
sig2  = A2 * cos (2 * pi * f2 * t + fi2) ;
subplot(3,1,2);
stem(t, sig2);

% f1 + f2
sig12 = sig1 + sig2;
subplot(3,1,3);
stem(t, sig12);

saveas(gcf, 'output.png')