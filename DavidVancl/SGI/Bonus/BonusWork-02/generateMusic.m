qConst = 2 ^ (1/12); % konstanta Q

Fs = 16000; % vzorkovací frekvence
A = 0.5; % hlasitost 
T = 0.2; % delka tonu (rychlost)
q = qConst ^ 0; % posun na stupnici 
TMoved = 320; %delka dozvuku

play = true; % parametr na prehrani
save = false; % parametr na save

%         E5  D5# E5  D5# E5  B4  D5  C5  A4    0 C4  E4  A4  B4    0 E4
TArray = [T   T   T   T   T   T   T   T   T*1.5 T T   T   T   T*1.5 T T]; % délky tonu
FArray = [659 622 659 622 659 493 587 523 440   0 261 329 440 493   0 329]; % frekvence
%                 G4# B4  C5    0 E4  E5  D5# E5  D5# E5  B4  D5  C5
TArray = [TArray [T   T   T*1.5 T T   T   T   T   T   T   T   T   T]];
FArray = [FArray [415 493 523   0 329 659 622 659 622 659 493 587 523]];
%                 A4    0 C4  E4  A4  B4    0 E4  C5  B4  A4  0
TArray = [TArray [T*1.5 T T   T   T   T*1.5 T T   T   T   T*2 T]];
FArray = [FArray [440   0 261 329 440 493   0 329 523 493 440 0]];

%REPAT START
TArray = [TArray TArray];
FArray = [FArray FArray];
% REPEAT STOP

%                 B4  C5  D5  E5  0 G4  F5  E5  D5  0 F4  E5  D5  C5  0
TArray = [TArray [T   T   T   T*2 T T   T   T   T*2 T T   T   T   T*2 T]];
FArray = [FArray [493 523 587 659 0 415 698 659 587 0 349 659 587 523 0]];
%                 E4  D5  C5  B4  0 E4  E5    E5  C6    D5# E5   
TArray = [TArray [T   T   T   T*2 T T   T*1.5 T   T*1.5 T   T*1.5]];
FArray = [FArray [329 587 523 493 0 329 659   659 1174  622 659  ]];
%                 D5# E5  D5  E5  D5# B4  D5  C5  A4    0 C4  E4  A4  B4    0
TArray = [TArray [T   T   T   T   T   T   T   T   T*1.5 T T   T   T   T*1.5 T]];
FArray = [FArray [622 659 587 659 622 493 587 523 440   0 261 329 440 493   0]];
%                 E4  G4# B4  C5    0 E4  E5  D5# E5  D5# E5  B4  D5  C5  A4    0
TArray = [TArray [T   T   T   T*1.5 T T   T   T   T   T   T   T   T   T   T*1.5 T]];
FArray = [FArray [329 415 493 523   0 329 659 622 659 622 659 493 587 523 440   0]];
%                 C4  E4  A4  B4    0 E4  C5  B4  A4
TArray = [TArray [T   T   T   T*1.5 T T   T   T   T*3]];
FArray = [FArray [261 329 440 493   0 329 523 493 440]];

music = [];
for index = 1:length( TArray )
    t = 0:1/Fs:TArray(index); %časová osa
    ton = A * sin (2 * pi * (FArray(index) * q) * t);
    music = [music ton];
end

% přidání dozvuku
s = size(music);
movedMusic = zeros(1,TMoved);
movedMusic((TMoved + 1):(s(2) + TMoved)) = music(1:s(2));
finalMusic = music(1:s(2)) + (0.5 * movedMusic(1:s(2)));

if play == true
    sound(finalMusic,Fs);
end
if save == true
    audiowrite("music.wav",finalMusic,Fs);
end