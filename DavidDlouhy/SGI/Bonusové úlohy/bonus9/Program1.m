%START
clear all;
close all;
clc;
%START
xCentrum=16;
yCentrum=16;
stradac1=[];
stradac2=[];
%------------------------
%Cteni ze souboru
%------------------------
fileReader = fopen('FileList.txt','r');
textdata = textscan(fileReader,'%s');
fclose(fileReader);
fileNames = string(textdata{:});
numFiles = size (fileNames, 1);
%------------------------
%Cteni ze souboru
%------------------------
%------------------------
%Procházení jednotlivých obrázků
%------------------------
counterOfPlot=1;
for i = 1:numFiles
%for i = 1:2
    clear y;
    clear maxPixel;

    actualLoadedImage=imread(fileNames(i));
    %------------------------
    %oprava tmavosti
    %------------------------
    y=actualLoadedImage;
    temp_y=actualLoadedImage;
    if(size(max(actualLoadedImage),3)==1)
        maxPixel=double(max(max(actualLoadedImage)));
    else
        %Vtipná vadná data s barvou
        maxPixel=double(max(rgb2gray(max(actualLoadedImage))));
        y=rgb2gray(actualLoadedImage);
        temp_y=rgb2gray(actualLoadedImage);
    end
    
    %maxPixel=max(rgb2gray(max(actualLoadedImage)));
    koeficientNasobeni= double(255/maxPixel);
    for j=1:32
        for k=1:32
            y(j,k)=uint8(actualLoadedImage(j,k)*koeficientNasobeni);
        end
    end
    %imshow(y);
    %pause;
    %------------------------
    %oprava tmavosti
    %------------------------
    %------------------------
    %odstranění šumu
    %------------------------
    for radek=2:31
        for sloupec=2:31
            %vynásobit okolí a centrum jádrem po prvcích a sečíst
            subMatice=double([y(radek-1,sloupec-1) y(radek-1,sloupec) y(radek-1,sloupec+1);y(radek,sloupec-1) y(radek,sloupec) y(radek,sloupec+1);y(radek+1,sloupec-1) y(radek+1,sloupec) y(radek+1,sloupec+1);]);
            %jadro=(1/9*[1 1 1; 1 1 1; 1 1 1]);
            %jadro=(1/10*[1 1 1; 1 2 1; 1 1 1]);
            jadro=(1/16*[1 2 1; 2 4 2; 1 2 1]);
            y(radek, sloupec)=sum(sum(subMatice.*jadro));
        end
    end
    %imshow(y);
    %pause;
    %------------------------
    %odstranění šumu
    %------------------------
    %------------------------
    %vycentrování motivu
    %------------------------
    indexMinRadku=0;
    indexMinSloupce=0;
    hodnotaMinRadku=0;
    hodnotaMinSloupce=0;
    %Urceni posunu
    %sum(y,1)
    [hodnotaMinRadku indexMinRadku]=min(sum(y,1));
    [hodnotaMinSloupce indexMinSloupce]=min(sum(y,2).');
    posunX=(indexMinRadku-16);
    posunY=(indexMinSloupce-16);

    %návrh algoritmu
    %---------------
    %1. hrandu nejdu tak, že budud čekat na prví nalezení přechodu
    %nájít levou hrandu
    %najít pravou hranu
    %najít vrchni hranu
    %najít spodní hranu
    %horizontalni centrum = (prava hrana - leva hrana)/2
    %vertikalni centrum = (spodni hrana - horni hrana)/2
    %float případně zaokrouhlit na celé číslo
    %dostanu souřadnice centrea od kterých odečtu 16 a dpostanu tak odhad
    %pozice centra X
    levaHrana=32;
    pravaHrana=0;
    for radek=1:32
        for sloupec=2:32
            %levaHrana
            if((y(radek, sloupec-1)-y(radek, sloupec))>8)
                detekceHrany=sloupec;
                if(levaHrana>detekceHrany)
                    levaHrana=detekceHrany;
                end
            end
            
        end
    end
    horniHrana=32;
    for sloupec=1:32
        for radek=2:32
            %horniHrana
            if((y(radek-1, sloupec)-y(radek, sloupec))>8)
                detekceHrany=radek;
                if(horniHrana>detekceHrany)
                    horniHrana=detekceHrany;
                end
            end
        end
    end
    %prava hrana
    for radek=1:32
        for sloupec=levaHrana:32
            if((y(radek, sloupec-1)-y(radek, sloupec))>8)
                detekceHrany=sloupec;
                if(pravaHrana<detekceHrany)
                    pravaHrana=detekceHrany;
                end
            end
        end
    end
    %spodnihrana hrana
    spodniHrana=0;
    for sloupec=1:32
        for radek=horniHrana:32
            if((y(radek-1, sloupec)-y(radek, sloupec))>8)
                detekceHrany=radek;
                if(spodniHrana<detekceHrany)
                    spodniHrana=detekceHrany;
                end
            end
        end
    end
    stredX=(pravaHrana+levaHrana)/2;
    stredY=(spodniHrana+horniHrana)/2;
    posunY=-(round(16-(stredY)));
    posunX=-(round(16-(stredX)));
    %disp("LH: "+levaHrana+"  PH: "+pravaHrana+" PH-LH: "+((pravaHrana-levaHrana)));
    %Urceni posunu
    finalMatrix=y;
    %XCENTER
    for radek=1:32
        for sloupec=1:32
            if (posunX>0)
                if(sloupec>(32-posunX))
                    budouciIndex=sloupec-(32-posunX);
                    finalMatrix(radek, sloupec)=y(radek,budouciIndex);
                else
                    finalMatrix(radek, sloupec)=y(radek,sloupec+posunX);
                end
            end
            if (posunX<0)
                if(sloupec<(-posunX+1))
                    budouciIndex=32+(sloupec+posunX);
                    finalMatrix(radek, sloupec)=y(radek,budouciIndex);
                else

                    finalMatrix(radek, sloupec)=y(radek,sloupec+posunX);
                end
            end
        end
    end
    %XCENTER
    finalMatrix2=finalMatrix;
    %YCENTER
    for sloupec =1:32
        for radek= 1:32
            if (posunY>0)
                if(radek>(32-posunY))
                    budouciIndex=radek-(32-posunY);
                    finalMatrix2(radek, sloupec)=finalMatrix(budouciIndex,sloupec);
                else
                    finalMatrix2(radek, sloupec)=finalMatrix(radek+posunY,sloupec);
                end
            end
            if (posunY<0)
                if(radek<(-posunY+1))
                    budouciIndex=32+(radek+posunY);
                    finalMatrix2(radek, sloupec)=finalMatrix(budouciIndex,sloupec);
                else

                    finalMatrix2(radek, sloupec)=finalMatrix(radek+posunY,sloupec);
                end
            end
        end
    end
    
    
    %YCENTER
    %subplot(2,2,1);
    %imshow(actualLoadedImage);
    %subplot(2,2,2);
    %imshow(y);
    %hold on;
    %plot([levaHrana levaHrana],[0 100])
    %plot([pravaHrana pravaHrana],[0 100])
    %plot([0 100],[horniHrana horniHrana])
    %plot([0 100],[spodniHrana spodniHrana])
    %hold off;
    %subplot(2,2,3);
    %imshow(finalMatrix);
    %subplot(2,2,4);
    %imshow(finalMatrix2);
    %pause(0.5);
    %------------------------
    %vycentrování motivu
    %------------------------
    
    if(counterOfPlot==1)
        stradac1_1=temp_y;
        stradac2_1=finalMatrix2;
    end
    if(counterOfPlot==2)
        stradac1_2=temp_y;
        stradac2_2=finalMatrix2;
    end
    if(counterOfPlot==3)
        stradac1_3=temp_y;
        stradac2_3=finalMatrix2;
    end
    if(counterOfPlot==4)
        stradac1_4=temp_y;
        stradac2_4=finalMatrix2;
    end
    if(counterOfPlot==5)
        stradac1_5=temp_y;
        stradac2_5=finalMatrix2;
    end
    if(counterOfPlot==6)
        stradac1_6=temp_y;
        stradac2_6=finalMatrix2;
    end
    if(counterOfPlot==7)
        stradac1_7=temp_y;
        stradac2_7=finalMatrix2;
    end
    if(counterOfPlot==8)
        stradac1_8=temp_y;
        stradac2_8=finalMatrix2;
    end
    if(counterOfPlot==9)
        stradac1_9=temp_y;
        stradac2_9=finalMatrix2;
    end
    if(counterOfPlot==10)
        stradac1_10=temp_y;
        stradac2_10=finalMatrix2;
    end
    

    if(counterOfPlot==10)
        subplot(10,2,1);
        imshow(stradac1_1);
        subplot(10,2,2);
        imshow(stradac2_1);
        
        subplot(10,2,3);
        imshow(stradac1_2);
        subplot(10,2,4);
        imshow(stradac2_2);
        
        
        subplot(10,2,5);
        imshow(stradac1_3);
        subplot(10,2,6);
        imshow(stradac2_3);
        
        subplot(10,2,7);
        imshow(stradac1_4);
        subplot(10,2,8);
        imshow(stradac2_4);
        
        subplot(10,2,9);
        imshow(stradac1_5);
        subplot(10,2,10);
        imshow(stradac2_5);
        
        subplot(10,2,11);
        imshow(stradac1_6);
        subplot(10,2,12);
        imshow(stradac2_6);
        
        subplot(10,2,13);
        imshow(stradac1_7);
        subplot(10,2,14);
        imshow(stradac2_7);
        
        
        subplot(10,2,15);
        imshow(stradac1_8);
        subplot(10,2,16);
        imshow(stradac2_8);
        
        subplot(10,2,17);
        imshow(stradac1_9);
        subplot(10,2,18);
        imshow(stradac2_9);
        
        subplot(10,2,19);
        imshow(stradac1_10);
        subplot(10,2,20);
        imshow(stradac2_10);
        
        pause();
        counterOfPlot=1;
    else
        counterOfPlot=counterOfPlot+1;
    end
    
end
%------------------------
%Procházení jednotlivých obrázků
%------------------------