function y = my_conv(f,g)
y=[];
for n=0:(length(f)+length(g)-2)
    value=0;
    for k = 0:length(f)-1
        if (n-k)>=0 && (n-k)<length(g)
            value=value+f(k+1)*g(n-k+1);
        end
    end
    y(n+1)=value;
end