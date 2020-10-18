clear all;
close all;
% ukazkovy program, jak nacist nazvy testovacich souboru ze seznamu 
% a jak s nimi pak pracovat.
fileID = fopen('FilesList.txt','r');  % seznam otevren pro cteni
textdata = textscan(fileID,'%s');  % nacten to textdata
fclose(fileID); % seznam zavren 
fileNames = string(textdata{:}); % zde je vytvoreno stringove pole, obsahujici nazvy souboru
numFiles = size (fileNames, 1);
correctAnswers=0;
IncorrectAnswers=0;
for i = 1:numFiles
    [x,Fs] = audioread(fileNames(i));
    energie=[];
    for j = 1:160:16000
        energie=[energie,(sum((x(j:1:j+159)).^2))];          
    end
    %plot(energie);
    %hold on;
    y=sum(energie(:))/length(energie);
    z(1:100)=y;
    start=0;
    finish=0;
    peakSums=[];
    areasum=0;
    maximum=0;
    for k = 1:length(energie)
        if energie(k)>y
            if start == 0
                start=k;
            end
            areasum=areasum+energie(k);
            else 
            if start ~=0
                start=0;
                finish=k;
                if(areasum>maximum)
                   peakSums=[peakSums,maximum];
                   maximum=areasum;
                    else
                   peakSums=[peakSums,areasum];
                end
                areasum=0;
            end
        end
    end
    [filepath,name,ext] = fileparts(fileNames(i));

    if (regexpi(name,'[a-z]+','match','once'))==recognize(maximum,peakSums)
       correctAnswers=correctAnswers+1;
       display("správný");
    else 
        %hold on
        %name
        %plot(energie);
        %plot(z);
        display("chybný");
        IncorrectAnswers=IncorrectAnswers+1;
        %pause
        %hold off;
    end
    %sound (x, Fs);
end
display((correctAnswers/(IncorrectAnswers+correctAnswers))*100+"% úspìšnost");