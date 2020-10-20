clear
%% Nastení dat
% ukazkovy program, jak nacist nazvy testovacich souboru ze seznamu 
% a jak s nimi pak pracovat.
fileID = fopen('FilesListPR1.txt','r');  % seznam otevren pro cteni
textdata = textscan(fileID,'%s');  % nacten to textdata
fclose(fileID); % seznam zavren 
fileNames = string(textdata{:}); % zde je vytvoreno stringove pole, obsahujici nazvy souboru
numFiles = size (fileNames, 1);
for i = 1:numFiles   % zde uz jen nacitam zvuky z jednotlivych souboru
    [y,Fs] = audioread(fileNames(i));
    
    %% Práce s nahrávkami
    y = Denoise(y);    
    subplot(4,2,i);
    plot(getEnergy(y , Fs, 0.01));
    title(fileNames(i));
%     sound (y, Fs);
%     pause;
end

function y = getEnergy(yIN, Fs, Elength)
    FsEnergy = Fs .* Elength;
    y = zeros(length(yIN)/FsEnergy,1);
    
    for i = 0:( length(yIN)/FsEnergy -1)
        y(i+1) =  sum( yIN((i*FsEnergy)+1 : (i+1)*FsEnergy).^2, 'all');
    end
end

function y2 = Denoise(y)
    y2 = y;  
    
    for i = 2:(length(y)-1)
        expected = mean([y2(i-1) y2(i+1)]);
        toleration = abs(y2(i-1) - y2(i+1));
        if(abs(expected - y2(i)) > 5*toleration)
           y2(i) =  expected;
        end
    end
end