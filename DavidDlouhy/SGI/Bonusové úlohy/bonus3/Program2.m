clear all;
close all;
clc;
%------------------------
%Cteni ze souboru
fileReader = fopen('FilesList.txt','r');
textdata = textscan(fileReader,'%s');
fclose(fileReader);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);
%------------------------
uspech=0;
neuspech=0;
%Procházení jednotlivých povelů
for i = 1:numFiles
    [x1,Fs] = audioread(fileNames(i));
    enTmp1=0;
    counterRoste=0;
    counterKlesa=0;
    roste=0;

    for j=8000:100:(size(x1)-100-1000)
        interval = x1((j+1):(j+11)-1);
        energie = sum(interval.^2);
        if(enTmp1<energie &&roste==0)
            counterRoste=counterRoste+1;
            roste=1;
        end
        if(enTmp1>energie&&roste==1)
            counterKlesa=counterKlesa+1;
            roste=0;
        end
        enTmp1=energie;
    end
    nameSplit = strsplit(fileNames(i),'\');
    [lasIndX,lastIndY]=size(nameSplit);
    fileNameSplit=nameSplit(lastIndY);
    if(counterRoste>counterKlesa)
        if(strncmpi(fileNameSplit,'J',1))
            uspech=uspech+1;
        else
            neuspech=neuspech+1;
        end
    end
    if(counterRoste<counterKlesa)
        %disp("klesa");
        %finalCounterKlesa=finalCounterKlesa+1;
    end
    if(counterRoste==counterKlesa)
        if(strncmpi(fileNameSplit,'Z',1))
            uspech=uspech+1;
        else
            neuspech=neuspech+1;
        end
    end
    disp("");
end
disp("VÝSLEDEK:");
disp("Počet souborů: "+numFiles);
disp("Úpěch: "+uspech);
disp("Neúspěch: "+neuspech);
disp("Úspěšnost: "+(uspech/(numFiles)*100)+'%');