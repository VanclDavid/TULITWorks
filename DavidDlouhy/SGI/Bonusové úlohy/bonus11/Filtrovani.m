function [oy] = Filtrovani(y)
    for radek=2:31
        for sloupec=2:31
            subMatice=double([y(radek-1,sloupec-1) y(radek-1,sloupec) y(radek-1,sloupec+1);y(radek,sloupec-1) y(radek,sloupec) y(radek,sloupec+1);y(radek+1,sloupec-1) y(radek+1,sloupec) y(radek+1,sloupec+1);]);
            jadro=(1/16*[1 2 1; 2 4 2; 1 2 1]);
            y(radek, sloupec)=sum(sum(subMatice.*jadro));
        end
    end
    oy=y;
end