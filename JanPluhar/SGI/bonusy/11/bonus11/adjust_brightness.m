function [outputImage] = adjust_brightness(inputImage)
bMax=max(max(inputImage));
bMax=255/bMax;
imageRows=size(inputImage,1);
imageColumns=size(inputImage,2);
outputImage=zeros(imageRows,imageColumns);
for row=1:imageRows
    for column=1:imageColumns
        outputImage(row,column)=inputImage(row,column)*bMax;
    end
end
end

