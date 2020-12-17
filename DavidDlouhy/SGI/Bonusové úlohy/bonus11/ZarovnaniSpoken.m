function [oy] = ZarovnaniSpoken(y)
    indexMinRadku=0;
    indexMinSloupce=0;
    hodnotaMinRadku=0;
    hodnotaMinSloupce=0;
    [hodnotaMinRadku indexMinRadku]=min(sum(y,1));
    [hodnotaMinSloupce indexMinSloupce]=min(sum(y,2).');
    posunX=(indexMinRadku-32);
    posunY=(indexMinSloupce-32);
    levaHrana=64;
    pravaHrana=0;
    for radek=1:64
        for sloupec=2:64
            if((y(radek, sloupec-1)-y(radek, sloupec))>8)
                detekceHrany=sloupec;
                if(levaHrana>detekceHrany)
                    levaHrana=detekceHrany;
                end
            end
            
        end
    end
    horniHrana=64;
    for sloupec=1:64
        for radek=2:64
            if((y(radek-1, sloupec)-y(radek, sloupec))>8)
                detekceHrany=radek;
                if(horniHrana>detekceHrany)
                    horniHrana=detekceHrany;
                end
            end
        end
    end
    for radek=1:64
        for sloupec=levaHrana:64
            if((y(radek, sloupec-1)-y(radek, sloupec))>8)
                detekceHrany=sloupec;
                if(pravaHrana<detekceHrany)
                    pravaHrana=detekceHrany;
                end
            end
        end
    end
    spodniHrana=0;
    for sloupec=1:64
        for radek=horniHrana:64
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
    posunY=-(round(32-(stredY)));
    posunX=-(round(32-(stredX)));
    finalMatrix=y;
    for radek=1:64
        for sloupec=1:64
            if (posunX>0)
                if(sloupec>(64-posunX))
                    budouciIndex=sloupec-(64-posunX);
                    finalMatrix(radek, sloupec)=y(radek,budouciIndex);
                else
                    finalMatrix(radek, sloupec)=y(radek,sloupec+posunX);
                end
            end
            if (posunX<0)
                if(sloupec<(-posunX+1))
                    budouciIndex=64+(sloupec+posunX);
                    finalMatrix(radek, sloupec)=y(radek,budouciIndex);
                else

                    finalMatrix(radek, sloupec)=y(radek,sloupec+posunX);
                end
            end
        end
    end
    finalMatrix2=finalMatrix;
    for sloupec =1:64
        for radek= 1:64
            if (posunY>0)
                if(radek>(64-posunY))
                    budouciIndex=radek-(64-posunY);
                    finalMatrix2(radek, sloupec)=finalMatrix(budouciIndex,sloupec);
                else
                    finalMatrix2(radek, sloupec)=finalMatrix(radek+posunY,sloupec);
                end
            end
            if (posunY<0)
                if(radek<(-posunY+1))
                    budouciIndex=64+(radek+posunY);
                    finalMatrix2(radek, sloupec)=finalMatrix(budouciIndex,sloupec);
                else

                    finalMatrix2(radek, sloupec)=finalMatrix(radek+posunY,sloupec);
                end
            end
        end
    end
    oy=finalMatrix2;
end