clear all;
close all;
load('spoken_test.mat');load('spoken_tren.mat');
N =1000; M=4000; pocet_pokusu=0; pocet_spravnych=0;
tic
tridy_vzoru=zeros(1,M);
trainingData=zeros(9000,64,64);
for j = 1:M                   % cyklus pro tren. vzory, M max.9000
    v = tren_data(j,:,:);      % na�ti tren. obr�zek
    v=squeeze(v);
    v=adjust_brightness(v);
    v=center_image2(v);
    %v=imfilter(v,[1/16 1/8 1/16;1/8 1/4 1/8;1/16 1/8 1/16]);
    v=fir([1/16 1/8 1/16;1/8 1/4 1/8;1/16 1/8 1/16],v);
    v=adjust_brightness(v);
    trainingData(j,:,:)=v;
    v_trida = tren_trida(j);    % jeho t��da
    tridy_vzoru(j) = v_trida;   % ulo� ��slo t��dy do pole tridy_vzoru
end
for i = 1:N                     % cyklus pro test. obr�zky, N max.1000
x = test_data(i,:,:);        % na�ti test. obr�zek
x=squeeze(x);
x=adjust_brightness(x);
x=center_image2(x);
%x=imfilter(x,[1/16 1/8 1/16;1/8 1/4 1/8;1/16 1/8 1/16]);
x=fir([1/16 1/8 1/16;1/8 1/4 1/8;1/16 1/8 1/16],x);
x=adjust_brightness(x);
x_trida= test_trida(i);      % jeho t��da

    dist=zeros(1,M);
    for l = 1:M 
    dist(l)=sum(sum(abs((x)-(squeeze(trainingData(l,:,:)))))); % ur�i vzd�lenost a ulo� do pole dist
    end
    [min_distances,Indexes]=sort(dist);
    Indexes=Indexes(1:10);
    lowest_classes=tridy_vzoru(Indexes);
    values=zeros(1,10);
    for k = 1:10
        values(lowest_classes(k)+1)=values(lowest_classes(k)+1)+1/k;
    end
    [MaxValue,I] = max(values);
    nejblizsi_trida=I-1;
    %nejblizsi_trida= tridy_vzoru(index); % t��da nejbli���ho vzoru
    if x_trida== nejblizsi_trida % je shoda?
        pocet_spravnych = pocet_spravnych + 1;  % pokud ano, zapo��tej
    end
        pocet_pokusu = pocet_pokusu + 1;         % zapo��tej pokus
end
toc
uspesnost= pocet_spravnych/pocet_pokusu* 100;% ur�i �sp�nost
disp(['�sp�nost: ', num2str(uspesnost), '%']);% a vypi� ji