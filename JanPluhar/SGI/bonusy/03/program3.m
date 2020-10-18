clear all;
close all;
fileID = fopen('FilesList.txt','r');
textdata = textscan(fileID,'%s');
fclose(fileID);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);
correctAnswers=0;
IncorrectAnswers=0;
fileID = fopen('Protokol_Pluhaø.txt','w');
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
    answer=recognize(maximum,peakSums);
    fprintf(fileID,'%0s %12s\r\n',name+ext,answer);
    if (regexpi(name,'[a-z]+','match','once'))==answer
       correctAnswers=correctAnswers+1;
    else 
        %hold on
        %name
        %plot(energie);
        %plot(z);
        IncorrectAnswers=IncorrectAnswers+1;
        %pause
        %hold off;
    end
    %sound (x, Fs);
end
fprintf(fileID,'%1s \r\n',(correctAnswers/(IncorrectAnswers+correctAnswers))*100+"% úspìšnost");
fclose(fileID);