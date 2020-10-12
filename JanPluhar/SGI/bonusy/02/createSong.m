function [output] = createSong(stupnice,volume,frequencySampling,speed,shift,shiftVolume,musicSheet)
    output=[];
    for i = musicSheet
        frequency=convertToFrequency(i(1));
        frequency=frequency*((2^(1/12))^stupnice); %zmìna stupnice
        output=[output,getTone(volume,frequencySampling,frequency,i(2)/speed,shift,shiftVolume)];
        %dozvuk
    end
end

