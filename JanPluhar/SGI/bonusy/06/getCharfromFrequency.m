function [char] = getCharfromFrequency(twoFrequencies)
    if(twoFrequencies(1)>twoFrequencies(2))
        temp=twoFrequencies(1);
        twoFrequencies(1)=twoFrequencies(2);
        twoFrequencies(2)=temp;
    end
    chars=['1','2','3','4','5','6','7','8','9','*','0','#'];
    frequencies=[697 1209;697 1336;697 1477;770 1209;770 1336;770 1477;852 1209;852 1336;852 1477;941 1209;941 1336;941 1477];
    differencies=[];
    for i=1:length(frequencies);
    chosenFrequencies=frequencies(i,:);
    differencies=[differencies,[abs(chosenFrequencies(1,1)-twoFrequencies(1)) abs(chosenFrequencies(1,2)-twoFrequencies(2))]];
    end
    differenciesSum=[];
    for i=1:2:length(differencies)-1
        differenciesSum=[differenciesSum,differencies(i)+differencies(i+1)];
    end
    [minValues,minIndeces]=sort(differenciesSum,'ascend');
    char=chars(minIndeces(1));
    
end 

