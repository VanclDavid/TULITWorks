function tone = generateKeyTone(f1,f2, N, Fs, A)

tone=zeros(1,N);
for i=1:N
    tone(i)=A*sin((2*pi*(i-1)*f1)/Fs)+A*sin((2*pi*(i-1)*f2)/Fs);
end
end

