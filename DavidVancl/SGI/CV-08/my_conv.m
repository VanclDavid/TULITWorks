function y = my_conv(f,g)
    if length(g) > length(f)
        tp = g;
        g = f;
        f = tp;
    end
    tmpMatrix = zeros(length(f),length(g) + (length(g) - 1));
    
    stockLine = 0;
    for i = 1:length(f)
        for j = 1:length(g)
           tmpMatrix(i,j + stockLine) = f(i) * g(j);
        end
        stockLine = stockLine + 1;
    end
    
    y = zeros(1,size(tmpMatrix,2));
    for m = 1:size(tmpMatrix,2)
       y(m) = sum(tmpMatrix(:,m));
    end
end