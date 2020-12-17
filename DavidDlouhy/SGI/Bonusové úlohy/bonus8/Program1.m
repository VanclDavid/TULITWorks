%START
clear all;
close all;
clc;
%START
%3a je vadná


%OSOBA 1 "data/na_1.wav" "data/na_2.wav" "data/na_3.wav" "data/na_4.wav" "data/na_5.wav" 
%OSOBA 2 "data/nb_1.wav" "data/nb_2.wav" "data/nb_3.wav" "data/nb_4.wav" "data/nb_5.wav"
%OSOBA 3 "data/nc_1.wav" "data/nc_2.wav" "data/nc_3.wav" "data/nc_4.wav" "data/nc_5.wav"
%OSOBA 4 "data/nd_1.wav" "data/nd_2.wav" "data/nd_3.wav" "data/nd_4.wav" "data/nd_5.wav"
%OSOBA 5 "data/ne_1.wav" "data/ne_2.wav" "data/ne_3.wav" "data/ne_4.wav" "data/ne_5.wav"
fileName=["data/ne_1.wav" "data/ne_2.wav" "data/ne_3.wav" "data/ne_4.wav" "data/ne_5.wav"];
sada = 1;
for fn=1:length(fileName)
clear wawFile;
clear fs;
clear energie;
clear nalezeno;
clear suma;
clear counter;
clear nalezeno;
clear tmp_prostredek;

[wawFile, fs]=audioread(fileName(fn));
energie = [];
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


for i=1:length(energie)
    nalezeno(i)=false;
    if(energie(i)>0.5)
        nalezeno(i)=true;
    end
end
pole_poce_vzorku=0;
pocet_vzorku_od_zmeny=0;
last=1;
sumarray=[];
for i=61:60:length(nalezeno)-60
    counter=0;
    for j=1:60
        if(nalezeno(i-j))
            counter=counter+1;
        end
    end
    if(counter>2)
       for j=1:60
        nalezeno(i-j)=true;
        end
    end
end
zacatek=[];
konec=[];
detektor_sig=false;
tmp_zacatek=-20;
tmp_konec=-20;
detectedNum=0;
for i=2:length(nalezeno)
    %pokud je vzestupná hrana tak započítej nový zacatek na tru
    %pokud je sestuna hrana tak započitej nový konec
    if((nalezeno(i-1))~=nalezeno(i))
        detektor_sig=~detektor_sig;
        if(detektor_sig)
            %vzes
            zacatek(i)=true;
            tmp_zacatek=i;
        else
            %ses
            konec(i)=true;
            tmp_konec=i;
        end
    end
    if((tmp_zacatek>=0)&&(tmp_konec>=0))
        tmp_prostredek=(tmp_zacatek+tmp_konec)/2;
        %disp("Zacatek: "+(tmp_prostredek*100-fs));
        %disp("Prostredek: "+(tmp_prostredek*100));
        %disp("Konec: "+(tmp_prostredek*100+fs));
        tmp_zacatek=-20;
        tmp_konec=-20;
        sss=wawFile((tmp_prostredek*100-fs):(tmp_prostredek*100+fs));
        
        if(sada>9)
            audiowrite("c"+detectedNum+"_pjjjj_s"+sada+".wav",sss,fs);
        else
            disp("c"+detectedNum+"_pjjjj_s0"+sada);
            audiowrite("c"+detectedNum+"_pjjjj_s0"+sada+".wav",sss,fs);
        end
        
        
        detectedNum=detectedNum+1;
        
        %ci_pjjjj_snn.wav
        %snn je sada 01-10       
        %c je cislo 0-9          = detectedNum
        %sound(sss,fs);
        %pause(1);
    end
    
end
sada=sada+1;
end

%
%plot(energie);
%hold on;
%lineup=[1:length(energie)];
%plot(nalezeno.*20);