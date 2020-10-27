close all;
clear all;
[x,Fs] = audioread("cv04_00.wav");
energie=[];
for j = 1:100:length(x)
        delka=0;
        if j+99>=length(x)
            delka=length(x)
        else
            delka=j+99
        end
        energie=[energie,(sum((x(j:1:delka)).^2))];
end
diff=[];
for l = 2:length(energie)
    diff=[diff,(energie(l)-energie(l-1))];
end
subplot(3,1,1)
plot(x)
subplot(3,1,2)
plot(energie)
subplot(3,1,3)
plot(diff)