%Amplituda,Vzorkovací frekvence, frekvence, doba trvání
function [signal] = getTone(A,Fs,f,T,shift,shiftVolume)
t=0:1/Fs:T-1/Fs;
signal=A*sin(2*pi*f*t);
s=length(signal);
shiftedSignal=zeros(shift);
shiftedSignal(shift+1:(s(1)))=signal(shift+1:s(1));
signal=signal+shiftVolume*shiftedSignal(1:s);
end

