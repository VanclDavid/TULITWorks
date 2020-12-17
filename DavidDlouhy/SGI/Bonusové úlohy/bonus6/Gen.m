clear all;
close all;
clc;
%-------------------------------
Fs=8000;
delka=100;
A=1/2;
N=800;
klavesa0=generateKeyTone(941,1336, N, Fs, A);%[941 1336];
klavesa1=generateKeyTone(697,1209, N, Fs, A);%[697 1209];
klavesa2=generateKeyTone(697,1336, N, Fs, A);%[697 1336];
klavesa3=generateKeyTone(697,1477, N, Fs, A);%[697 1477];
klavesa4=generateKeyTone(770,1209, N, Fs, A);%[770 1209];
klavesa5=generateKeyTone(770,1336, N, Fs, A);%[770 1336];
klavesa6=generateKeyTone(770,1477, N, Fs, A);%[770 1477];
klavesa7=generateKeyTone(852,1209, N, Fs, A);%[852 1209];
klavesa8=generateKeyTone(852,1336, N, Fs, A);%[852 1336];
klavesa9=generateKeyTone(852,1477, N, Fs, A);%[852 1477];
klavesnik=[[klavesa0]; [klavesa1]; [klavesa2]; [klavesa3]; [klavesa4]; [klavesa5]; [klavesa6]; [klavesa7]; [klavesa8]; [klavesa9]];
numers=zeros(1,10);
for i=1:10
    pocetCifer = randi([4 9],1,1);
    seq="";
    cifra = randi([0 9],1,pocetCifer+1);
    outArray=[];
    for j=1:pocetCifer
        seq=seq+""+cifra(j);
        pa=zeros(1,round(800+400.*rand(1,1)));
        outArray=[outArray klavesnik(cifra(j)+1,:) pa];
    end
    sumeni=0+(0.05-0).*rand(1,1);
    outArray=(outArray+sumeni.*(rand(size(outArray))))/max(abs(outArray));
    numers(i)=seq;
    
    audiowrite("./data/"+"dtmf_"+seq+".wav",outArray, Fs);
    
end
