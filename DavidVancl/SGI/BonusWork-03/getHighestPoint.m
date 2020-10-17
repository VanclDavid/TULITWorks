function [x,y] = getHighestPoint(sound)
    x = 1;
    y = sound(1);
    
    for i = 1:length(sound)
        if sound(i) > y
            y = sound(i);
            x = i;
        end
    end
end

