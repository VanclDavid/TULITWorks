clear all;
close all;
fileNames = [];
for i=1:2
    for j=1:5
        for k=0:9
            subplot(10,3,k*3+1)
            [x,Fs]=audioread("Osoba"+i+"/c"+k+"pjjjj_s0"+j+".wav");
            plot(x);
            subplot(10,3,k*3+2)
            energie=[];
            for m = 1:400:length(x)
                step=399;
                if m+399 > length(x)
                    step=length(x)-m;
                end
                energie=[energie,(sum((x(m:1:m+step)).^2))];            
            end
            plot(energie);
            subplot(10,3,k*3+3)
            spectrogram(x,'yaxis');
        end
        pause;
    end
end
