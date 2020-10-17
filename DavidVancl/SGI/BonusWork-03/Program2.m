clear all;
clc

fileID = fopen('FilesList.txt','r');
textdata = textscan(fileID,'%s');
fclose(fileID);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);

goodAnswers = 0;
for i = 1:numFiles
    [sound,Fs] = audioread(fileNames(i));
    energy = getArrayEnergy(sound);
    [x,y] = getHighestPoint(energy);
    
    path = convertStringsToChars(fileNames(i));
    type = path(length(path) - 6:length(path) - 6);
    
    jumps = 0;
    isUp = false;
    for j=1:length(energy)
        energy(j) = energy(j) - (y * 0.5);
        if energy(j) < 0
        energy(j) = 0;
        end
        
        if energy(j) > 0 && isUp == false
            isUp = true;
        end
        if energy(j) == 0 && isUp == true
            jumps = jumps + 1;
            isUp = false;
        end
    end
    
    if jumps > 1
        myResult = 'Z';
    else
        myResult = 'J';
    end
    
    if myResult == type
        goodAnswers = goodAnswers + 1;
        "dobre"
    else 
        "spatne"
    end
%     plot (energy);
%     pause;
end

goodAnswers / (numFiles / 100)