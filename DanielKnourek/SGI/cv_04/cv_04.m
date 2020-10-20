clear;
%%
% fileID = fopen('FilesList.txt','r');
% textdata = textscan(fileID,'%s');
% fclose(fileID);
% fileNames = string(textdata{:}); 

fileNames = ["cv04_00.wav"];
numFiles = size (fileNames, 1);

for i = 1:numFiles   % zde uz jen nacitam zvuky z jednotlivych souboru
    [y,Fs] = audioread(fileNames(i));
    energie = getEnergy(y , Fs, 0.01);
    diff = getEnergy(energie , 50, 0.1);
    
    subplot(3,1,1);
    plot(y);
    xlabel("t"); ylabel("Level"); title(fileNames(i))
    
    subplot(3,1,2);
    plot(energie);
    xlabel("t"); ylabel("Level");
    
    
    subplot(3,1,3);
    plot(diff);
    xlabel("t"); ylabel("Level");
    
    saveas(gcf, 'output.png');
%     pause;
end




function y = getEnergy(yIN, Fs, Elength)
    FsEnergy = Fs .* Elength;
    y = zeros(ceil(length(yIN)/FsEnergy),1);
    
    for i = 0:( length(yIN)/FsEnergy -1)
        y(i+1) =  sum( yIN((i*FsEnergy)+1 : (i+1)*FsEnergy).^2, 'all');
    end
end