clear all;
close all;
clc;
klavesa0=[941 1336];
klavesa1=[697 1209];
klavesa2=[697 1336];
klavesa3=[697 1477];
klavesa4=[770 1209];
klavesa5=[770 1336];
klavesa6=[770 1477];
klavesa7=[852 1209];
klavesa8=[852 1336];
klavesa9=[852 1477];
klavesnik=[[klavesa0]; [klavesa1]; [klavesa2]; [klavesa3]; [klavesa4]; [klavesa5]; [klavesa6]; [klavesa7]; [klavesa8]; [klavesa9]];
%-------------------------------
%ve spektru najdeme 2 maxima a podle jejich frevence určíme cifru
%cifry porovnat s názvem
%------------------------
%Cteni ze souboru
con=0;
conx=0;
fileReader = fopen('FileList.txt','r');
textdata = textscan(fileReader,'%s');
fclose(fileReader);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);


if isfile('protokol.txt')
     fid=fopen('protokol.txt','a');
else
     fid=fopen('protokol.txt','w');
end




for i = 1:numFiles
[outArray,Fs]=audioread(fileNames(i));
energie=[];
index=1;
countSum=0;
%výpočet enerige
for y=1:length(outArray)
    countSum= countSum+(outArray(y)^2);
    if y==100*index%upravit je nápadné
        energie(index)=countSum;
        countSum=0;
        index=index+1;
    end 
end
%výpočet enerige
%zjištění kde jsou tóny
containsTone=[];
isTone=0;
detector=0;
signalCounter=0;
for j = 1:length(energie)
        if round(energie(j)) > 0 && detector ~= 1
            detector = 1;
            if (j - 1) == 0
                isTone = 1;
            else 
                isTone = (j - 1);
            end
        end
        
        if round(energie(j)) == 0 && detector == 1
            detector = 0;
            signalCounter = signalCounter + 1;
            containsTone= [containsTone [isTone * 100 (j - 1) * 100]];
        end
end
%zjištění kde jsou tóny
decoded = [];
    for index_tone = 1:2:length(containsTone)
        signal = outArray( containsTone(index_tone):containsTone(index_tone + 1) );
        abssignal = abs(fft(signal)/length(signal));
        F = abssignal(1:round(length(signal)/2)+1);
        F(2:end-1) = 2*F(2:end-1);
        f = Fs*(0:round(length(signal)/2))/length(signal);
        %druhé max
        maxF = max(F);
        indexOfFirstMax = find(F == maxF, 1, 'first');
        firstMax = round(f(indexOfFirstMax));
        %první max
        F(indexOfFirstMax) = 0;
        %druhe max
        maxF = max(F);
        indexOfFirstMax = find(F == maxF, 1, 'first');
        secondMax = round(f(indexOfFirstMax));
        
        if firstMax > secondMax
            tmp = secondMax;
            secondMax = firstMax;
            firstMax = tmp;
        end
        
        resultNumber = 0;
        for x = 1:length(klavesnik)
            if firstMax > klavesnik(x,1) - 10 && firstMax < klavesnik(x,1) + 10
                if secondMax > klavesnik(x,2) - 10 && secondMax < klavesnik(x,2) + 10
                    resultNumber = x-1;
                    break;
                end
            end
        end
        decoded = [decoded int2str(resultNumber)];
    end 
%sound(outArray);
%disp("číslo je: "+decoded);
%disp("stiskni mezernik a pokracuj (fce pause)");
%pause;
[filepath,name,ext] = fileparts(fileNames(i));
if name==("dtmf_"+decoded)
    disp("OK - číslo je: "+decoded);
    fprintf(fid, [ "OK - číslo je: "]);
    fprintf(fid, [ decoded]);
    fprintf(fid, [ '\n']);
    con=con+1;
else
    disp("KO - číslo je: "+decoded);
    fprintf(fid, [ "KO - číslo je: "]);
    fprintf(fid, [ decoded]);
    fprintf(fid, [ '\n']);
    conx=conx+1;
end
end
disp(datetime());
fprintf(fid, [datestr(clock,'YYYY/mm/dd HH:MM:SS:FFF')]);
fprintf(fid, [ '\n']);
celkovypocet=con+conx;
disp("Počet celkem: "+celkovypocet+" souborů");
fprintf(fid, [ "Počet celkem: "]);
fprintf(fid, [ int2str(celkovypocet)]);
fprintf(fid, [ " souborů"]);
fprintf(fid, [ '\n']);
disp("Úspěšně rozpoznalo: "+con+" souborů");
fprintf(fid, [ "Úspěšně rozpoznalo: "]);
fprintf(fid, [ int2str(con)]);
fprintf(fid, [ " souborů"]);
fprintf(fid, [ '\n']);
disp("Neúspěšně: "+conx+" souborů");
fprintf(fid, [ "Úspěšně rozpoznalo: "]);
fprintf(fid, [ int2str(conx)]);
fprintf(fid, [ " souborů"]);
fprintf(fid, [ '\n']);
fprintf(fid, [ '-------------------------']);
fprintf(fid, [ '\n']);
fclose(fid);