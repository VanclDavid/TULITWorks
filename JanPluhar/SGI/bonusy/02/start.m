clear all;
A = 0.1; %sound volume 0 - 1
Fs = 16000; %frequency sapling
s = 0.75; %speed >1 faster 1< slower
stupnice = 0; %+ zvyšuje - sniuje vıšku tónù
shift= 320; %posunutí dozvuku
shiftVolume=0.1; %hlasitost dozvuku
musicSheet = [3 1/4; 3 1/4; 3 1/2; 3 1/4; 3 1/4 ;3 1/2; 3 1/4; 5 1/4; 1 3/8; 2 1/8;3 1;4 1/4; 4 1/4; 4 3/8; 4 1/8; 4 1/4; 3 1/4; 3 1/4; 3 1/8; 3 1/8;3 1/4; 2 1/4; 2 1/4; 3 1/4;2 1/2;5 1/2;3 1/4;3 1/4;3 1/2;3 1/4;3 1/4;3 1/2;3 1/4; 5 1/4; 1 3/8;2 1/8;3 1;4 1/4;4 1/4;4 1/4;4 1/4;4 1/4; 3 1/4; 3 1/4; 3 1/8; 3 1/8;5 1/4;5 1/4;4 1/4;2 1/4;1 1]';   
output=createSong(stupnice,A,Fs,s,shift,shiftVolume,musicSheet); %volume 0 - 1, frequency sapling, speed, music sheet
plot(output);
audiowrite("song.wav",output,16000);
