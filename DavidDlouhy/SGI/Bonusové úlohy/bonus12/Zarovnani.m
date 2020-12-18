function [oy] = Zarovnani(y)
    indexMinRadku=0;
    indexMinSloupce=0;
    hodnotaMinRadku=0;
    hodnotaMinSloupce=0;
    [hodnotaMinRadku indexMinRadku]=min(sum(y,1));
    [hodnotaMinSloupce indexMinSloupce]=min(sum(y,2).');
    posunX=(indexMinRadku-16);
    posunY=(indexMinSloupce-16);
    levaHrana=32;
    pravaHrana=0;
    for radek=1:32
        for sloupec=2:32
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
            if((y(radek-1, sloupec)-y(radek, sloupec))>8)
                detekceHrany=radek;
                if(horniHrana>detekceHrany)
                    horniHrana=detekceHrany;
                end
            end
        end
    end
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
    finalMatrix=y;
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
    finalMatrix2=finalMatrix;
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
    oy=finalMatrix2;
end