function [tone] = generate_tone(char,Fs,volume,isNoise)
    chars=['1','2','3','4','5','6','7','8','9','*','0','#'];
    frequencies={697 1209;697 1336;697 1477;770 1209;770 1336;770 1477;852 1209;852 1336;852 1477;941 1209;941 1336;941 1477};
    freqIndex = find(chars==char);
    chosenFrequencies=frequencies(freqIndex,:);
    t=0:1/Fs:0.1-1/Fs;
    signal1=volume*sin(2*pi*chosenFrequencies{1}*t);
    signal2=volume*sin(2*pi*chosenFrequencies{2}*t);
    if(isNoise)
        noise =(rand(1,length(signal1))*0.05);
        tone=(0.475)*signal1+(0.475)*signal2;
        tone=tone+noise;
    else
        tone=0.5*signal1+0.5*signal2;
    end
    
end

