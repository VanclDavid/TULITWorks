function [frequency] = convertToFrequency(char)
notes=[1,2,3,4,5,6,7]; % c d e f ..
frequencies= [261.626, 293.665, 329.628, 349.228, 391.995, 440, 493.883];
frequency = notes==char;
frequency = frequencies(frequency);
return
end

