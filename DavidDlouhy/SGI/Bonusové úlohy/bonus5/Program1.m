clear all;
close all;
clc;
%-------------------------------
filename="tabulka.png";
loadedImage=imread(filename);
%image(loadedImage)
%pause
x=10;
y=10;
sizeX=221;
sizeY=221;
sizeLineX=16;
sizeLineY=30;
croppedImage = imcrop(loadedImage,[15 15 221 221]);
for i=0:y-1
    
    shiftY=i*(sizeLineY+sizeY);
    %15+(shiftY)
    
    for j=0:x-1
        num = j+1;
        if num>0
            if num<10
                num="0"+num;
            end
        end
        newFileName="c"+i+"_p0000_s"+num+".jpg";
        shiftX=j*(sizeLineX+sizeX);
        croppedImage = imcrop(loadedImage,[15+shiftX+1.5 15+shiftY+1.5 sizeX-5.5 sizeY-4]);
        image(croppedImage);
        imwrite(imresize(croppedImage, [32 32]), "Cisla/"+newFileName,'jpg');
        %disp(i+" "+j)
        %pause(0.5);
    end
end