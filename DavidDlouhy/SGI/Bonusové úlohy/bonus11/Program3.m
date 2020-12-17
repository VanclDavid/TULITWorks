%rozpoznání ručně psaných číslic
clear all;
close all;
clc;
tic;
load ('spoken_tren.mat'); 
load ('spoken_test.mat');

N = 1000; %MAX = 1000 = testovací data = na nich se alg. testuje
M = 4000; %MAX = 9000 = trénovací data = na nich se alg. učí
%90.1%
%84.9%
%1205.6868
pocet_pokusu = 0; pocet_spravnych = 0;
disp("trenuju");
tmp_counter_pocet_spravnych=0;
for j = 1:M % cyklus pro tren. vzory, M max.9000
v = double(squeeze(tren_data (j,:,:))); % načti tren. obrázek
%v=OpravaTmavosti((v));
v=FiltrovaniSpoken(v);
v=ZarovnaniSpoken(v);
tren_data(j,:,:)=v;
end
disp("testuju");
for i = 1:N % cyklus pro test. obrázky, N max.1000
x = double(squeeze(test_data (i,:,:))); % načti test. obrázek
x=FiltrovaniSpoken(x);
x=ZarovnaniSpoken(x);
x_trida = test_trida(i); % jeho třída
for j = 1:M % cyklus pro tren. vzory, M max.9000
v = double(squeeze(tren_data (j,:,:))); % načti tren. obrázek
v_trida = tren_trida(j); % jeho třída
tridy_vzoru(j) = v_trida; % ulož číslo třídy do pole tridy_vzoru
dist(j) = sum(sum((x - v).^2));

end
[min_dist, index] = min(dist); % nejmenší vzdálenost a její index
nejblizsi_trida = tridy_vzoru(index); % třída nejbližšího vzoru

if x_trida == nejblizsi_trida % je shoda?
pocet_spravnych = pocet_spravnych + 1; % pokud ano, započítej
end
pocet_pokusu = pocet_pokusu + 1; % započítej pokus
detekce=0;
if(tmp_counter_pocet_spravnych<pocet_spravnych)
    detekce=1;
end
disp("TEST: "+i+"/"+N+"    U: "+((pocet_spravnych/pocet_pokusu)*100)+"    U: "+detekce+"   "+x_trida+" je "+nejblizsi_trida);
tmp_counter_pocet_spravnych=pocet_spravnych;
end
uspesnost = pocet_spravnych/pocet_pokusu * 100; % urči úspěšnost
endTime = datetime('now');
disp(['Úspěšnost: ', num2str(uspesnost), '%']); % a vypiš ji
disp("Čas      : "+(toc));

load ('spoken_test_nez.mat');
test_data=test_nez_data;
test_person=test_nez_person;
test_sada=test_nez_sada;
test_trida=test_nez_trida;
disp("testuju nez");
for i = 1:N % cyklus pro test. obrázky, N max.1000
x = double(squeeze(test_data (i,:,:))); % načti test. obrázek
x=FiltrovaniSpoken(x);
x=ZarovnaniSpoken(x);
x_trida = test_trida(i); % jeho třída
for j = 1:M % cyklus pro tren. vzory, M max.9000
v = double(squeeze(tren_data (j,:,:))); % načti tren. obrázek
v_trida = tren_trida(j); % jeho třída
tridy_vzoru(j) = v_trida; % ulož číslo třídy do pole tridy_vzoru
dist(j) = sum(sum((x - v).^2));

end
[min_dist, index] = min(dist); % nejmenší vzdálenost a její index
nejblizsi_trida = tridy_vzoru(index); % třída nejbližšího vzoru

if x_trida == nejblizsi_trida % je shoda?
pocet_spravnych = pocet_spravnych + 1; % pokud ano, započítej
end
pocet_pokusu = pocet_pokusu + 1; % započítej pokus
detekce=0;
if(tmp_counter_pocet_spravnych<pocet_spravnych)
    detekce=1;
end
disp("TEST: "+i+"/"+N+"    U: "+((pocet_spravnych/pocet_pokusu)*100)+"    U: "+detekce+"   "+x_trida+" je "+nejblizsi_trida);
tmp_counter_pocet_spravnych=pocet_spravnych;
end
disp(['Úspěšnost SD: ', num2str(uspesnost), '%']); % a vypiš ji
uspesnost = pocet_spravnych/pocet_pokusu * 100; % urči úspěšnost
endTime = datetime('now');
disp(['Úspěšnost SI: ', num2str(uspesnost), '%']); % a vypiš ji
disp("Čas      : "+(toc));