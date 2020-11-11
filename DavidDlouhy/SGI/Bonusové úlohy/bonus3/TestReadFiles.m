clear all;
close all;
clc;
% ukazkovy program, jak nacist nazvy testovacich souboru ze seznamu 
% a jak s nimi pak pracovat.
fileID = fopen('FilesList.txt','r');  % seznam otevren pro cteni
textdata = textscan(fileID,'%s')  % nacten to textdata
fclose(fileID); % seznam zavren 
fileNames = string(textdata{:}) % zde je vytvoreno stringove pole, obsahujici nazvy souboru
numFiles = size (fileNames, 1);
for i = 1:numFiles   % zde uz jen nacitam zvuky z jednotlivych souboru
    disp(fileNames(i));
    [x,Fs] = audioread(fileNames(i));
    plot (x);        % a delam s nimi, co ptrebuji
    sound (x, Fs);
    pause;
end

