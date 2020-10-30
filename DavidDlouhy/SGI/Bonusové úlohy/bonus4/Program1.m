clear all;
close all;
clc;
%------------------------
%Cteni ze souboru
fileReader = fopen('data.txt','r');
textdata = textscan(fileReader,'%s');
fclose(fileReader);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);
%------------------------
for i = 1:numFiles
    [fileName,Fs] = audioread(fileNames(i));
    %výpočet spektrogramu a vykreslení
    %fileName, Fs máme
    %n(počet vzorků v úseku), m(překryv úseků), nfft(parametr FFT, rozlišení frekvencí je nfft/2+1)?
    [s,f,t,ps]=spectrogram(fileName,160,0,128,Fs);
    %subplot(5,2,i);
    spectrogram(fileName,160,0,128,Fs,'yaxis');
    disp(i-1);
    pause
end