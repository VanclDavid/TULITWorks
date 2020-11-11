clear all;
clc;

table = rgb2gray(imread('table.png'));

horizontalCheckLine = 20;
vericalCheckLine = 50;

[widthCell, heigthCell] = getCellDimension(table,horizontalCheckLine,vericalCheckLine);

cutBorder = 30;
widthCell = widthCell - cutBorder;
heigthCell = heigthCell - cutBorder;

marginTop = 35;
marginLeft = 45;

lineHorWidth = 34;
lineVerWidth = 39;

for i = 1:10
    for j = 1:10
        tmp = table(marginTop + ((i - 1) * (heigthCell + lineVerWidth)):marginTop + ((i - 1) * (heigthCell + lineVerWidth)) + heigthCell,marginLeft + ((j - 1) * (widthCell + lineHorWidth)) : marginLeft + ((j - 1) * (widthCell + lineHorWidth)) + widthCell);
        if j < 10
            imwrite(imresize(tmp, [32 32]),"Numbers/c"+(i - 1)+"_"+"p0000_s" + "0" + j + ".jpg");
        else 
            imwrite(imresize(tmp, [32 32]),"Numbers/c"+(i - 1)+"_"+"p0000_s" + j + ".jpg");
        end
    end
end
