clear all;
clc;

%% Clear Sounds_Dynamic
files = dir(fullfile("Sounds_Dynamic", '*.wav'));
for k = 1 : length(files)
  delete(fullfile("Sounds_Dynamic", files(k).name));
end

%% Generator
DTMF = [[0 941 1336];[1 697 1209]; [2 697 1336];
        [3 697 1477];[4 770 1209]; [5 770 1336];
        [6 770 1477];[7 852 1209]; [8 852 1336];
        [9 852 1477];[10 941 1209]; [11 941 1477]];
    
Fs = 8000; % vzorkovací frekvence
A = 0.5; % hlasitost 
N = 800;

for t = 1:10
    tonesNumbers = round(0 + (9-0) .* rand(round(4 + (9-4) .* rand(1,1)),1));
    tonesNumbersString = convertCharsToStrings(int2str(tonesNumbers));
    allTones = [];
    for i = 1:length(tonesNumbers)
        ton = zeros(1,N);
        for j = 1: N
            ton(j) = A*sin((2*pi*(j-1)*DTMF(tonesNumbers(i)+1,2))/Fs) + A*sin((2*pi*(j-1)*DTMF(tonesNumbers(i)+1,3))/Fs);
        end
        space = zeros(1,round(800 + (1200-800) .* rand(1,1)));
        allTones = [allTones ton space];
    end
    
    %šum
    ampl = 0 + (0.05-0) .* rand(1,1);
    finalSignal = allTones + ampl .* rand(size(allTones));
    finalSignal = finalSignal / max(abs(finalSignal));
    
    audiowrite("Sounds_Dynamic/" + "dtmf_" + tonesNumbersString + ".wav",finalSignal,Fs);
end