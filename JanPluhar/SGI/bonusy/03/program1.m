
close all;
clear all;
energie=[];
str = ["nahravky/J01.wav","nahravky/J02.wav","nahravky/J03.wav","nahravky/J04.wav","nahravky/Z01.wav","nahravky/Z02.wav","nahravky/Z03.wav","nahravky/Z04.wav"];
index=[1,3,5,7,2,4,6,8];
for i = 1:8
        [x,Fs] = audioread(str(i));
    energie=[];
for j = 1:160:16000   % zde uz jen nacitam zvuky z jednotlivych souboru
        energie=[energie,(sum((x(j:1:j+159)).^2))];  
        
end
subplot(4,2,index(i));
plot(energie)
end