function y = my_conv(f,g)
    y=[];
    velikostF=length(f);
    velikostG=length(g);
    posun=1;
    for n=0:((velikostF+velikostG)-2)
        tmp=0;
        for k = 0:(velikostF-1)
            if (n-k)>=0
                if((n-k)<velikostG)
                    tmp=tmp+f(k+posun)*g(n-k+posun);
                end
            end
        end
        y(n+posun)=tmp;
    end
end