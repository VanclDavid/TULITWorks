function [answer] = recognize(maximum,peakSums)
if(length(peakSums)==1)
    answer="J";
    return;
end
if(length(peakSums)>1)
    for i = 1:length(peakSums)
               percentage=peakSums(i)/maximum;
               if percentage > 0.2
                   answer="Z";
                    return;
                end       
    end
    answer="J";
    return;
end
end

