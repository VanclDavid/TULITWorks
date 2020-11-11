clear all;
close all;
tableImage=imread("tabulka.jpg");
tableImage=rgb2gray(tableImage);
[rows columns numberOfColorBands] = size(tableImage);
blockSizeRow=floor(rows/10);
blockSizeColumn=floor(columns/10);

rowBlocks = [blockSizeRow * ones(1, floor(rows / blockSizeRow)), rem(rows, blockSizeRow)];
columnBlocks = [blockSizeColumn * ones(1, floor(columns / blockSizeColumn)), rem(columns, blockSizeColumn)];

finalBlocks = mat2cell(tableImage, rowBlocks, columnBlocks);

numPlotsR = 10;
numPlotsC = 10;
for r = 1 : numPlotsR
    for c = 1 : numPlotsC
        separatedBlock = finalBlocks{r,c};
        offsetRow=floor(blockSizeRow*0.1);
        offsetColumn=floor(blockSizeColumn*0.1);
        separatedBlock = separatedBlock(offsetRow:end-offsetRow,offsetColumn:end-offsetColumn);
        separatedBlock=imresize(separatedBlock,[32 32]);
        imwrite(separatedBlock,"c"+(r-1)+"_p0000_s"+sprintf('%02d',c)+".jpg");
    end
end