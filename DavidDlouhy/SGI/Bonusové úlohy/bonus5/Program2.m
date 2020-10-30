clear all;
close all;
clc;
%-------------------------------
%image(loadedImage)
%pause
x=10;
y=10;

for i=0:y-1
    for j=0:x-1
        num = j+1;
        if num>0
            if num<10
                num="0"+num;
            end
        end
        newFileName="c"+i+"_p0000_s"+num+".jpg";
        filename="Cisla/"+newFileName;
        loadedImage=imread(filename);
        image(loadedImage);
        disp(i+" "+j)
        pause(0.5);
    end
end