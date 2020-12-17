function [outputImage] = center_image(inputImage)
    alteredImage=255-inputImage;
    imageRows=size(alteredImage,1);
    imageColumns=size(alteredImage,2);
    [x, y] = meshgrid(1:imageRows, 1:imageColumns);
    weightedx = x .* alteredImage;
    weightedy = y .* alteredImage;
    cogX = round(sum(weightedy(:)) / sum(alteredImage(:)));
    cogY = round(sum(weightedx(:)) / sum(alteredImage(:)));
    outputImage=zeros(imageRows,imageColumns);
        for row=1:imageRows
                    for column=1:imageColumns
                        tempRow=row+cogX-16;
                        tempColumn=column+cogY-16;
                        if tempRow > 0 && tempColumn > 0
                            if tempRow <= imageRows && tempColumn <= imageColumns
                                 outputImage(row,column)=inputImage(tempRow,tempColumn);
                            else
                            indexRow=mod(tempRow,imageRows+1);
                            if indexRow==0 indexRow=1; end
                            indexColumn=mod(tempColumn,imageColumns+1);
                            if indexColumn==0 indexColumn=1; end
                             outputImage(row,column)=inputImage(indexRow,indexColumn);
                            end
                        else
                            outputImage(row,column)=inputImage(imageRows+1-row,imageColumns+1-column);
                        end
                    end
        end
end

