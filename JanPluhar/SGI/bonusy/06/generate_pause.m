function [sound] = generate_pause(Fs,isNoise)
t=round(rand*50)+100;
if(isNoise)
    sound=zeros(1,t*Fs/1000);
    sound=sound+(rand(1,length(sound)))*0.05;
else 
    sound=zeros(1,t*Fs/1000);
end
end

