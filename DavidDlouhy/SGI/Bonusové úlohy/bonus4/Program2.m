clear all;
close all;
clc;
%------------------------
%Cteni ze souboru
fileReader = fopen('MojeReseni.txt','r');
textdata = textscan(fileReader,'%s');
fclose(fileReader);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);

fileReader2 = fopen('SpravneReseni.txt','r');
textdata2 = textscan(fileReader2,'%s');
fclose(fileReader2);
fileNames2 = string(textdata2{:});
numFiles2 = size (fileNames2, 1);
%------------------------
counter = 0;
for i = 1:numFiles
 if fileNames(i)==fileNames2(i)
     counter=counter+1;
 end
end
disp("Uhodnuto "+counter+" z "+numFiles);
disp("To je "+(counter/(numFiles)*100)+"%");