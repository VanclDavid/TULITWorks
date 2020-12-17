
%predikovat od 1.9. do 30.10.
clc;
clear all;
close all;
xls_table = readtable('Covid20201110.xls');
dates = table2array(xls_table(:,1));
cases = table2array(xls_table(:,2));
s = size (cases,1);

% vyhlazeni dat tydennim klouzavym prumerem
cases_smoothed = zeros (s,1);
for d = 4:s-4
    cases_smoothed(d)= floor(sum(cases(d-3:d+3))/7);
end

plot (cases,'g')
hold on
plot (cases_smoothed,'r')
xline(219) % 1. zari
xline(278) % 30. rijen

x = cases_smoothed; % zkopirujeme do vektoru x

% definovani poli pro vysledky
pred = zeros (7,1);   % predikce pro dny D, D+1, ... D+6
abs_error = zeros (7,1);  % absol. hodnoty odchylek
sum_errors = zeros (7,1);  % soucty odchylek

%x%prirustek1=1;
%x%%x%prirustek2=1;
%x%prirustek6=1;
% nyni cyklus vypoctu pro dny od 1.9. do 30.10.
preCounting = 0;
counter=0;
for d = 219:278
    % minulost tvori 7 dni pred dnem D 
    % a z jejich hodnot chceme predikovat pocty pripadu pro dny D, D+2 a D+6
    
    % zde bude vas vypocet predicniho modelu
    %-----------------------------------------
    % ja zde jako priklad uvadim velmi trivialni model kdy kazdy den pribyde
    % o 1 pripad vice
    
        disp (dates(d))
        % trivialni predikce pro den d
        %pred(1) = floor (x(d-1)+1); % floor proto, ze chceme aby odhad byl vzdy celociselny
        %pred(1)=floor (x(d-1)+((x(d-7)+x(d-14))+(x(d-21)+x(d-28))+(x(d-35)+x(d-42))+(x(d-49)+x(d-(7*8))+x(d-(7*9))+x(d-(7*10))+x(d-(7*11))+x(d-(7*12))+x(d-(7*13))+x(d-(7*14))+x(d-(7*15))+x(d-(7*16))+x(d-(7*17))+x(d-(7*18))+x(d-(7*19))+x(d-(7*20))+x(d-(7*21))+x(d-(7*22))+x(d-(7*23))+x(d-(7*24))+x(d-(7*25))+x(d-(7*26))+x(d-(7*27))+x(d-(7*28))+x(d-(7*29))+x(d-(7*30))))/90);
        %pred(1)=floor (x(d-1)-(x(d-2)));
        countingActual = x(d-1) - x(d-2);
        odchylka=5;
        
        if(abs(abs(preCounting)-abs(countingActual))>50)
            odchylka=90;
        end
        if(abs(abs(preCounting)-abs(countingActual))>60)
            odchylka=00;
        end
        if(abs(abs(preCounting)-abs(countingActual))>80)
            odchylka=50;
        end
        if(abs(abs(preCounting)-abs(countingActual))>90)
            odchylka=00;
        end
        if(abs(abs(preCounting)-abs(countingActual))>100)
            odchylka=30;
            
        end
        if(abs(abs(preCounting)-abs(countingActual))>150)
            odchylka=20;
            counter=counter+1;
        end
        if(abs(abs(preCounting)-abs(countingActual))>200)
            odchylka=30;
        end
        if(abs(abs(preCounting)-abs(countingActual))>250)
            odchylka=15;
        end
        if(abs(abs(preCounting)-abs(countingActual))>300)
            odchylka=00;
        end
        if(abs(abs(preCounting)-abs(countingActual))>400)
            odchylka=200;
        end
        preCounting=countingActual;
        
        if(countingActual>0)
            odchylka=odchylka*(-1);
        end
        countingActual = countingActual+ odchylka ;
        pred(1) = floor( (countingActual) + (x(d-1)));
        %x%prirustek1=pred(1)-prirustek1;
        abs_error(1) = abs(pred(1) - x(d));
        fprintf ('den d   - real: %d  pred: %d  abs_error: %d\n',x(d), pred(1), abs_error(1));

        % trivialni predikce pro den d+2
        %pred(3) = floor (x(d-1) + 1 + 2);
        pred(3)=floor(3*(countingActual) + x(d-1));
        %x%prirustek2=pred(3);
        abs_error(3) = abs(pred(3) - x(d+2));
        fprintf ('den d+2 - real: %d  pred: %d  abs_error: %d\n',x(d+2), pred(3), abs_error(3));

        % trivialni predikce pro den d+6
        %pred(7) = floor (x(d-1) + 1 + 6);
        pred(7)=floor(7*(countingActual) + x(d-1));
        %x%prirustek3=pred(7);
        abs_error(7) = abs(pred(7) - x(d+6));
        fprintf ('den d+6 - real: %d  pred: %d  abs_error: %d\n\n',x(d+6), pred(7), abs_error(7));
    
    sum_errors = sum_errors + abs_error; % nascitani chyb za kazdy den
    %-----------------------------------------
    %pause
end

fprintf ('\nSoucet chyb \nden d: %d  \nden d+2: %d   \nden d+6: %d\n\n',sum_errors(1), sum_errors(3), sum_errors(7))

counter
    


