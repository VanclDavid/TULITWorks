clear all;
close all;
fileID = fopen('FileList.txt','r');
textdata = textscan(fileID,'%s');
fclose(fileID);
fileNames = string(textdata{:});
numFiles = size(fileNames, 1);
index=1;
for i = 1:length(fileNames)
    image=imread(fileNames(i));
    [rows columns numberOfColorBands] = size(image);
    if numberOfColorBands ~=1
    image=rgb2gray(image);
    end
    subplot(10,2,index);
    imshow(image);
    subplot(10,2,index+1);
    index=index+2;
    newImage=fir([1/16 1/8 1/16;1/8 1/4 1/8;1/16 1/8 1/16],image);
    newImage=adjust_brightness(newImage);
    newImage=center_image(newImage);
    imshow(newImage);
    if(mod(index,21)==0 || i==length(fileNames))
    pause
    index=1;
    end
end