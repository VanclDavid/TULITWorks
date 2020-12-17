%START
clear all;
close all;
clc;
%START
fileName="D:\David\Documents\Vysoká škola\SGI\Cvičení\cv4\cv04_00.wav";
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
for l = 2:length(energie)
    d=energie(l)-energie(l-1);
    diff=[diff,d];
end
subplot(3,1, 1);
plot(wawFile);
subplot(3,1, 2);
plot(energie );
subplot(3,1, 3);
plot(diff);
saveas(gcf, 'output.png')