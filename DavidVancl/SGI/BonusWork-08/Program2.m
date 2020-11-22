clear all;
clc;

for f = 1:10
    if f < 10
        folder = "0" + f;
    else 
        folder = "" + f;
    end
    folder
    files=dir('I:\Matlab_scripts\Signaly_a_Informace\BonusWork-08\Records\Cuttings\'+folder+'\*.wav');
    plotIndex = 1;
    for k=1:length(files)
       filename = files(k).folder + "\" + files(k).name;
       [audio,Fs] = audioread(filename);
       subplot(10,3,plotIndex);
       plot(audio);
       subplot(10,3,plotIndex + 1);
       plot(getArrayEnergy(audio));
       subplot(10,3,plotIndex + 2);
       spectrogram(audio,Fs);
       plotIndex = plotIndex + 3;
    end
    pause
end