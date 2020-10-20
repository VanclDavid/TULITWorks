clear
%% Nastení dat
% ukazkovy program, jak nacist nazvy testovacich souboru ze seznamu 
% a jak s nimi pak pracovat.
fileID = fopen('FilesList.txt','r');  % seznam otevren pro cteni
textdata = textscan(fileID,'%s');  % nacten to textdata
fclose(fileID); % seznam zavren 
fileNames = string(textdata{:}); % zde je vytvoreno stringove pole, obsahujici nazvy souboru
numFiles = size (fileNames, 1);
Successful = 0;
delete ProtokolProgram2.txt
diary ProtokolProgram2.txt;
for i = 1:numFiles   % zde uz jen nacitam zvuky z jednotlivych souboru
    [y,Fs] = audioread(fileNames(i));
    
    %% zpracování nahrávek
    y = Denoise(y);    
    y = getEnergy(y , Fs, 0.01);
    y = getEnergy(y, 100, 0.1);
    y = y+1;
    power = log(2) / log(max(y));
    y = (y).^power;
    
    
    %% Určení nahrávky
    slabikaCount = 0;
    insideSlabika = false;
    for j = 1:length(y)
        if y(j) > 1.08
            if insideSlabika == false
            slabikaCount = slabikaCount + 1;
            insideSlabika = true;
            end
        else            
            insideSlabika = false;
        end    
    end
    
    
    subplot(length(fileNames)/2,2,i);    
    plot(y);
    title([fileNames(i) slabikaCount]);
%     sound (y, Fs);
%     pause;

    %% výsledek rozpoznávání
    disp(join(["---" fileNames(i) "---"]));
    if slabikaCount == 1
        detected = "J";
    else
        detected = "Z";
    end
    disp(join(["Detected: " detected]));
    if length(strfind(fileNames(i), detected)) == 1
        Successful = Successful + 1;
        disp("Successful");
    else        
        disp("Failure");
    end
disp("-----------");
end
disp("success rate");
disp(join([Successful "/" numFiles " = " (Successful/numFiles * 100)]));

diary off;



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