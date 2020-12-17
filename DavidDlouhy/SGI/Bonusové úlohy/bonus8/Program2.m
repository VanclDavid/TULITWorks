%Vykresleni signalu jedna sada vždy signál, energie, spektrogram
%START
clear all;
close all;
clc;
%START
slozka="Osoba4/";
%slozka="Osoba5/";
pocetSad=5;
for sadyRepeter=1:pocetSad
posit=1;
for repeter=0:9    
fileName=slozka+"c"+repeter+"_pjjjj_s0"+sadyRepeter+".wav";
wawFile=audioread(fileName);
energie = [];
diff=[];
for i=1:100:length(wawFile)
    pos=0;
    if i+99>=length(wawFile)
       pos=length(wawFile);
    else
       pos=i+99;
    end
    suma = sum((wawFile(i:1:pos)).^2);
    energie=[energie,suma];
end

% zvol vzorkovaci frekvenci
Fs = 16000;








subplot(10,3, posit);
posit=posit+1;
plot(wawFile);
subplot(10,3, posit);
posit=posit+1;
plot(energie );
subplot(10,3, posit);
posit=posit+1;
spectrogram(wawFile, hamming(256), 128, 256, Fs, 'yaxis');
end
pause();
end