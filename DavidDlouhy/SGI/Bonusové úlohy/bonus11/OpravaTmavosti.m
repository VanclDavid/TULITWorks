function [oy] = OpravaTmavosti(y)
    temp_y=y;
    if(size(max(y),3)==1)
        maxPixel=double(max(max(y)));
    else
        maxPixel=double(max(rgb2gray(max(y))));
        y=rgb2gray(y);
        temp_y=rgb2gray(y);
    end
    koeficientNasobeni= double(255/maxPixel);
    for j=1:32
        for k=1:32
            y(j,k)=double(y(j,k)*koeficientNasobeni);
        end
    end
  oy=y;
oy=double(Filtrovani(oy));
end

