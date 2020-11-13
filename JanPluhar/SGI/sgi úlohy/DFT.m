function X = DFT(x, N)
for k = 0:1:N-1
    suma=0;
    for n = 0:1:N-1
        suma=suma+(x(n+1)*exp(-(j*2*pi*n*k)/N));
    end
    X(k+1)=1/N*suma;
end
end

