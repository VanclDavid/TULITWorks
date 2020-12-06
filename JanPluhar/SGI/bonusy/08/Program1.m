clear all;
close all;
fileNames = [];
for i=3
    for j=1:5
        fileNames=[fileNames,"Osoba"+i+"/os"+i+"_puvodni"+j+".wav"];
    end
end
folder="osoba3/";
sada=1;
for k=1:length(fileNames)
[x,Fs] = audioread(fileNames(k));
    %energie
    energie=[];
    for m = 1:400:length(x)
        step=399;
        if m+399 > length(x)
            step=length(x)-m;
        end
        energie=[energie,(sum((x(m:1:m+step)).^2))];            
    end
        %hledání signálù
        averageValue=sum(energie(:))/length(energie);
        tonesPositions=[];
        start=0;
            for n = 1:length(energie)
                if start ~=0 && n-start==80
                    tonesPositions=[tonesPositions,[start-25 n-25]];
                    start=0;
                end
            if energie(n)>averageValue
                if start == 0
                    start=n;
                    
                end 
            end
            end
            tonesPositions=(tonesPositions-1)*400;
            length(tonesPositions)
            index=0;
            if(k==6)
                folder="osoba2/";
                sada=1;
            end
            for o=1:2:length(tonesPositions)
                audiowrite(folder+"c"+index+"_pjjjj_s0"+sada+".wav",x(tonesPositions(o):tonesPositions(o+1)),16000); 
                index=index+1;
            end
            sada=sada+1;
end