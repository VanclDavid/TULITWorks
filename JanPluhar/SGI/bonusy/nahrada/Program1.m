close all;
clear all;
%training data
load('digits_tren.mat');
M=9000;
tridy_vzoru=zeros(1,M);
trainingData=zeros(9000,32,32);
disp("starting process of training data");
for j = 1:M
    trainImage = tren_data(j,:,:);
    trainImage=squeeze(trainImage);
    trainImage=centerImage(trainImage);
    trainImage=fir([1/16 1/8 1/16;1/8 1/4 1/8;1/16 1/8 1/16],trainImage);
    trainImage=adjust_brightness(trainImage);
    trainingData(j,:,:)=trainImage;
    v_trida = tren_trida(j);
    tridy_vzoru(j) = v_trida;
end
disp("training data processed");

Files=dir('data/*.jpg');
for f=1:length(Files)
inputImg=imread(Files(f).folder+"\"+Files(f).name);
subplot(1,10,[1 2 3 4 5]);
imshow(inputImg);
inputImg=rgb2gray(inputImg);
table=findTable(inputImg,true);
rows=size(table,1);
columns=size(table,2);
blockSizeRow=rows;
blockSizeColumn=floor(columns/5);
rowBlocks = [blockSizeRow * ones(1, floor(rows / blockSizeRow)), rem(rows, blockSizeRow)];
columnBlocks = [blockSizeColumn * ones(1, floor(columns / blockSizeColumn)), rem(columns, blockSizeColumn)];
finalBlocks = mat2cell(table, rowBlocks, columnBlocks);
psc="";

for i=1:5
    cell=cell2mat(finalBlocks(1,i));
    cell=cell(round(size(cell,1)*0.15):round(size(cell,1)*0.85),round(size(cell,2)*0.15):round(size(cell,2)*0.85));
    cell=adjust_brightness(cell);
    cell=imresize(findTable(cell,false),[32 32]);
    cell=centerImage(double(cell));
    cell=fir([1/16 1/8 1/16;1/8 1/4 1/8;1/16 1/8 1/16],cell);
    cell=adjust_brightness(cell);
    subplot(1,10,5+i);
    imshow(uint8(cell));
    dist=zeros(1,M);
    for k = 1:M 
    dist(k)=sum(sum(abs(cell-(squeeze(trainingData(k,:,:))))));
    end
    [min_distances,Indexes]=sort(dist);
    Indexes=Indexes(1:10);
    lowest_classes=tridy_vzoru(Indexes);
    values=zeros(1,10);
    for m = 1:10
        values(lowest_classes(m)+1)=values(lowest_classes(m)+1)+1/m;
    end
    [MaxValue,I] = max(values);
    psc=psc+(I-1);
end
disp("PSÈ: "+psc);
pause
end

