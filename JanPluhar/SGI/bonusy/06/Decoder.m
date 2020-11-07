clear all;
close all;
fileID = fopen('FileList.txt','r');
textdata = textscan(fileID,'%s');
fclose(fileID);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);
correctAnswers=0;
IncorrectAnswers=0;
fileID = fopen('Protokol_Pluhar.txt','w');
for i = 1:length(fileNames)
    [x,Fs] = audioread(fileNames(i));
    energie=[];
    %energie
    for j = 1:100:length(x)
        step=99;
        if j+99 > length(x)
            step=length(x)-j;
        end
        energie=[energie,(sum((x(j:1:j+step)).^2))];            
    end
        %hledání signálù
        averageValue=sum(energie(:))/length(energie);
        tonesPositions=[];
        start=0;
            for k = 1:length(energie)
            if energie(k)>averageValue
                if start == 0
                    start=k;
                    
                end
                else 
                if start ~=0
                    tonesPositions=[tonesPositions,[start k]];
                    start=0;
                end
            end
            end
            tonesPositions=(tonesPositions-1)*100;
            tonesPositions(1)=tonesPositions(1)+1;
            %Fast Fourier transform
            outputString=[];
                for m = 1:2:(length(tonesPositions)-1)
                singleTone=x(tonesPositions(m):1:tonesPositions(m+1)); %úsek tonu
                Y = fft(singleTone); 
                P2 = abs(Y/length(singleTone)); %dvoustranný graf
                P1 = P2(1:floor(length(singleTone)/2)+1);
                P1(2:end-1) = 2*P1(2:end-1); %jednostranný graf
                f = Fs*(0:(length(singleTone)/2))/length(singleTone);
                plot(f,P1)
                [maxValues,maxIndeces]=sort(P1,'descend');
                max1=round(f(maxIndeces(1)));
                max2=round(f(maxIndeces(2)));
                outputString=[outputString,getCharfromFrequency([max1 max2])];
                end
                    [filepath,name,ext] = fileparts(fileNames(i));
                    if (regexpi(name,'[0-9]+','match','once'))==outputString
                        correctAnswers=correctAnswers+1;
                        display("správný");
                    else
                        display("chybný");
                        IncorrectAnswers=IncorrectAnswers+1;
                    end
end
display((correctAnswers/(IncorrectAnswers+correctAnswers))*100+"% úspìšnost");
fprintf(fileID,'%1s \r\n',(correctAnswers/(IncorrectAnswers+correctAnswers))*100+"% úspìšnost");
fclose(fileID);