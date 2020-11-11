function [sound] = Generator(string,Fs,volume,isNoise)
    charArray = convertStringsToChars(string);
    sound=0;
        for i = charArray
            sound=[sound,generate_tone(i,Fs,volume,isNoise)];
            sound=[sound,generate_pause(Fs,isNoise)];
        end
end

