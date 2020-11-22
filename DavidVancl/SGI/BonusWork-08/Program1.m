clear all;
clc;

fileID = fopen('FilesList.txt','r');
textdata = textscan(fileID,'%s');
fclose(fileID);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);

for q = 1:numFiles
    [record,recordFs] = audioread(fileNames(q));
    energy = getArrayEnergy(record);
    actualStuff = "DOWN";
    downLength = 0;
    startIndex = 0;
    indexes = [];
    for i = 1:length(energy)
        if energy(i) > 0.01 && actualStuff == "DOWN"
            startIndex = i;
            actualStuff = "UP";
        end
        if energy(i) < 0.01 && actualStuff == "UP"
            downLength = downLength + 1;
        else
            downLength = 0;
        end
        if downLength > 30 
            indexes = [indexes [startIndex (i - 30)]];
            actualStuff = "DOWN";
            downLength = 0;
        end
    end
    if q < 10
        folder = "0" + q;
    else
        folder = q;
    end
    fname = 0;
    for i = 1:2:length(indexes)
        startI = indexes(i) * 400;
        endI = indexes(i + 1) * 400;
        spaceLeft = (32000 - (endI - startI)) / 2;
        spaceRight = (32000 - (endI - startI + spaceLeft)) - 1;
        cut = record((startI - spaceLeft):(endI + spaceRight));
        audiowrite("Records/Cuttings/"+folder+"/c" + fname + "_pjjjj_s"+folder+".wav",cut,recordFs);
        fname = fname + 1;
    end
end