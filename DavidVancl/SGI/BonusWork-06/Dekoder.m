clear all;
clc;

DTMF = [[0 941 1336];[1 697 1209]; [2 697 1336];
        [3 697 1477];[4 770 1209]; [5 770 1336];
        [6 770 1477];[7 852 1209]; [8 852 1336];
        [9 852 1477];[10 941 1209]; [11 941 1477]];

fileID = fopen('FilesList.txt','r');
textdata = textscan(fileID,'%s');
fclose(fileID);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);
goodResult = 0;

odchylka = 20;

for i = 1:numFiles
    [filepath,name,ext] = fileparts(fileNames(i));
    narray = convertStringsToChars(name);
    dataSequence = narray(6:length(narray));
    
    [s,Fs] = audioread(fileNames(i));
    energy = getArrayEnergy(s);
    tonsIntervals = [];
    up = 0;
    is = "DOWN";
    signalCount = 0;
    for j = 1:length(energy)
        if round(energy(j)) > 0 && is ~= "UP"
            is = "UP";
            if (j - 1) == 0
                up = 1;
            else 
                up = (j - 1);
            end
        end
        
        if round(energy(j)) == 0 && is == "UP"
            is = "DOWN";
            signalCount = signalCount + 1;
            tonsIntervals = [tonsIntervals [up * 160 (j - 1) * 160]];
        end
    end
    
    mySequence = [];
    for t = 1:2:length(tonsIntervals)
        intervalSignal = s( tonsIntervals(t):tonsIntervals(t + 1) );
        L = length(intervalSignal);
        Y = fft(intervalSignal);
        p = abs(Y/L);
        F = p(1:round(L/2)+1);
        F(2:end-1) = 2*F(2:end-1);

        f = Fs*(0:round(L/2))/L;
        plot(f,F);
        
        maxF = max(F);
        indexOfFirstMax = find(F == maxF, 1, 'first');
        firstMax = round(f(indexOfFirstMax));
        
        F(indexOfFirstMax) = 0;
        maxF = max(F);
        indexOfFirstMax = find(F == maxF, 1, 'first');
        secondMax = round(f(indexOfFirstMax));
        
        if firstMax > secondMax
            tmp = secondMax;
            secondMax = firstMax;
            firstMax = tmp;
        end
        
        resultNumber = 0;
        for q = 1:length(DTMF)
            if firstMax > DTMF(q,2) - odchylka && firstMax < DTMF(q,2) + odchylka && secondMax > DTMF(q,3) - odchylka && secondMax < DTMF(q,3) + odchylka
                resultNumber = DTMF(q,1);
                break;
            end
        end
        mySequence = [mySequence int2str(resultNumber)];
    end 

% parameters
% signalCount - pocet cisel
% tonsIntervals - dvojice souradnic (od do) v puvodnim signalu
% dataSequence - sekvence cisel z nazvu
% mySequence - muj vysledek

dsp = ['[Muj výsledek : Očekávaný výsledek] ',mySequence,' : ',dataSequence];
disp(dsp);
if dataSequence == mySequence
    goodResult = goodResult + 1;
end

%     subplot(2,1,1);
%     plot(s);
%     subplot(2,1,2);
%     plot(energy);
%     signalCount
%     sound(s,Fs);
end
dsp = ['Dobře z: ',num2str(numFiles),' / ',num2str(goodResult)];
disp(dsp);