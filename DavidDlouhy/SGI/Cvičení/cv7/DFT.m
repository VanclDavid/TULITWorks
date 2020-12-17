function X = DFT(x, N)
for k = 0:1:N-1
    tmp=0;
    for n = 0:1:N-1
        tmp=tmp+(x(n+1)*exp(-(1j*2*pi*n*k)/N));
    end
    X(k+1)=1/N*tmp;
end
end