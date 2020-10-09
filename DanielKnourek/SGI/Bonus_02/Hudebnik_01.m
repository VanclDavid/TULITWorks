clear;

%% settings
Fs = 16000; % vzorkovací frekvence
speed = 1; %Hz rychlost skladby
volumeA = 0.25; % hlasitost skladby
echo = [0.7 18000]; %dozvuk hlasitost|posunutí

% 0=Cdur 1=CISdur 2=Ddur 3=DISdur 4=Edur 5=Fdur 6=FISdur 7=Gdur 8=GISdur 9=Adur 10=AISdur 11=Hdur
% 0=Cmoll -1=Hmoll -2=AISmoll -3=Amoll -4=GISmoll -5=Gmoll -6=FISmoll -7=Fmoll -8=Emoll -9=DISmoll -10=Dmoll -11=CISmoll
scale = -2;

 % óda na radost
 composition = "2.66-e1 2.66-e1 2.66-f1 2.66-g1 2.66-g1 2.66-f1 2.66-e1 2.66-d1 2.66-c1 2.66-c1 2.66-d1 2.66-e1 1.6-e1 8-d1 2.66-d1 2.66-p 2.66-e1 2.66-e1 2.66-f1 2.66-g1 2.66-g1 2.66-f1 2.66-e1 2.66-d1 2.66-c1 2.66-c1 2.66-d1 2.66-e1 1.6-d1 8-c1 2.66-c1 2.66-p 2.66-d1 2.66-d1 2.66-e1 2.66-c1 2.66-d1 4-e1 8-f1 2.66-e1 2.66-c1 2.66-d1 4-e1 8-f1 2.66-e1 2.66-d1 2.66-c1 2.66-d1 2.66-g0 1.33-e1 2.66-e1 2.66-f1 2.66-g1 2.66-g1 2.66-f1 2.66-e1 4-f1 8-d1 2.66-c1 2.66-c1 2.66-d1 2.66-e1 1.6-d1 8-c1 2.66-c1 2.66-p 2.66-d1 2.66-d1 2.66-e1 2.66-c1 2.66-d1 4-e1 8-f1 2.66-e1 2.66-c1 2.66-d1 4-e1 8-f1 2.66-e1 2.66-d1 2.66-c1 2.66-d1 2.66-g0 1.33-e1 2.66-e1 2.66-f1 2.66-g1 2.66-g1 2.66-f1 2.66-e1 4-f1 8-d1 2.66-c1 2.66-c1 2.66-d1 2.66-e1 1.6-d1 8-c1 2.66-c1 2.66-p";

 %% Note creation
cDur = ["p", "g0", "gis0", "a0", "ais0", "h0", "c1", "cis1", "d1", "dis1", "e1", "f1", "fis1", "g1", "gis1", "a1", "ais1", "h1", "c2", "cis2", "d2", "dis2", "e2"]; % table of notes
Dur = cDur;
nPos = @(note)(find(~cellfun(@isempty,regexpi(Dur,note))));
nFreq = @(note)(f( (nPos(note) - nPos("a1")), scale ));
note2freq = @(notes) (cell2mat(cellfun(nFreq, notes, 'UniformOutput', false )));



%% sound symthesis
% [note, len] = str2note("4-c1 4-d1 4-e1 4-f1 4-g1 4-a1 4-h1"); % First test!

[note, len] = str2note(composition);
y1 = freq2tone(note2freq(note), len, speed, Fs, volumeA);
y2 = [zeros(1,echo(2)) echo(1).*y1];
y = y1 + y2(length(y1));
%%
% audio test
% sound(y1,Fs);
pause(2);

sound(y,Fs);

pause(2);

audiowrite("oda.wav", y, Fs)

%%
function [y] = f(tLevel, scale)
    q = 2^(1/12); a1 = 440;
    if(tLevel <= -15)
        y = 0;
    else
        y = (q.^(tLevel + scale) * a1);
    end
end

function [y] = freq2tone(freq, len, speed, Fs, volume)
 y = [];
    for i = 1:length(len)
        T = len(i) .* speed;
        t = 0: 1./Fs : T;
    
        y = [y (volume .* sin(2.*pi.* freq(i) .* t))];
    end    
end

function [note, len] = str2note( composition )
    tmp = split(split(composition, " "),"-");
    len = str2double(tmp(:,1)).^(-1);
    note = tmp(:,2);
    
end