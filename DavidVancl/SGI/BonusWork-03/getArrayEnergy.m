function [arrayEnergy] = getArrayEnergy(record)
    arrayEnergy = zeros(1,100);
    index = 1;
    sum = 0;
    for i=1:length(record)
        sum = sum + (record(i) * record(i));
        if i == 160*index
            arrayEnergy(index) = sum;
            sum = 0;
            index = index + 1;
        end
    end
end
