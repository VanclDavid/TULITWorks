clc; clear;
%%
Fs = 1000;
N = 1000;
f = 2;

format long

fx1 = @(x,t,f)( (1/(1+2.*(x-1))) .*cos((1+2.*(x-1)).*2.*pi.*f.*t-(pi/2) ));

fx2 = @(x,t,f)( (1/(x)) .*cos(x.*2.*pi.*f.*t-(pi/2) ));

%%
t=0:1/Fs:1-1/Fs;
x1=sin(2*pi*t*0); % nuly
x2=sin(2*pi*t*0); % nuly

%%
for n = 1:N
%    s=s+cos(2*pi*t*n);
   x1 = x1+ fx1(n,t,f);
   x2 = x2+ fx2(n,t,f);
   
%    pause;
end
x1(1) = 0; x2(1) = 0;

%% fX1
subplot(2,2,1);
plot(t,x1);
title(n);

subplot(2,2,2);
F = 0:Fs/N:Fs/2-Fs/N;
X = fft(x1,N);
stem(F(1:40),1/(N/2)*abs(X(1:40)),'.');

%% fX2
subplot(2,2,3);
plot(t,x2);
title(n);

subplot(2,2,4);
F = 0:Fs/N:Fs/2-Fs/N;
X = fft(x2,N);
stem(F(1:40),1/(N/2)*abs(X(1:40)),'.');


%% output
saveas(gcf, 'output.png');

