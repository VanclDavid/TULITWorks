function [outputImage] = fir(mask,inputImage)
    imageRows=size(inputImage,1);
    imageColumns=size(inputImage,2);
    outputImage=zeros(imageRows,imageColumns);
    maskRows=size(mask,1);
    maskColumns=size(mask,2);
    if mod(maskRows,2)~=0 || mod(maskColumns,2)~=0
        center=[round(maskRows/2) round(maskColumns/2)];
        %image
        for row=1:imageRows
            for column=1:imageColumns
                newPixelSum=0;
                %mask
                for mrow=1:maskRows
                    for mcolumn=1:maskColumns
                        tempRow=row-mrow+center(1);
                        tempColumn=column-mcolumn+center(2);
                        if tempRow < 1 
                            tempRow=1;
                        else
                            if tempRow > imageRows
                                tempRow=imageRows;
                            end
                        end
                        if tempColumn < 1
                            tempColumn=1;
                        else
                            if tempColumn > imageColumns
                                tempColumn=imageColumns;
                            end
                        end
                           newPixelSum=newPixelSum+inputImage(tempRow,tempColumn)*mask(mrow,mcolumn);                       
                    end
                end
                outputImage(row,column)=newPixelSum;
            end
        end
    else
        disp("bad mask dimensions");
    end
    outputImage=uint8(outputImage);
end

