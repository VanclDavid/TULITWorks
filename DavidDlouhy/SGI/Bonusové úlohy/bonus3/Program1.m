clear all;
close all;
clc;
%------------------------
%Cteni ze souboru
fileReader = fopen('FilesListTester.txt','r');
textdata = textscan(fileReader,'%s');
fclose(fileReader);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);
%------------------------
%Procházení jednotlivých povelů
for i = 1:numFiles
    [x1,Fs] = audioread(fileNames(i));
    arrayEnergie=zeros(size(x1)-1);
    counter=0;
    for j=0:10:(size(x1)-10)
        interval = x1((j+1):(j+11)-1);
        energie = sum(interval.^2);
        arrayEnergie(counter+1)=energie;
        counter=counter+1;
    end
    if(numFiles==8)
        if(i==1)
            subplot(4,2,i);
            plot(arrayEnergie);
        end
       if(i==2)
            subplot(4,2,3);
            plot(arrayEnergie);
       end
        if(i==3)
            subplot(4,2,5);
            plot(arrayEnergie);
        end
        if(i==4)
            subplot(4,2,7);
            plot(arrayEnergie);
        end
       if(i==5)
            subplot(4,2,2);
            plot(arrayEnergie);
        end
       if(i==6)
            subplot(4,2,4);
            plot(arrayEnergie);
       end
        if(i==7)
            subplot(4,2,6);
            plot(arrayEnergie);
        end
        if(i==8)
            subplot(4,2,8);
            plot(arrayEnergie);
       end
    else
        disp("Souborů není 8");
    end
    arrayEnergie
end