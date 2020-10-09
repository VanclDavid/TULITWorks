clear;
clc;

[x, Fs] = audioread ('hudba_praskani.wav');
x = x ./ 1.5;

%%IDEA 1
% Přelepení chybného místa nejbližším možným

% crashes = 0;
% zerocounter = 0;
% startIndex = 0;
% for c = 2:length(x)
%     if x(c) == 0 && zerocounter == 0
%         startIndex = c;
%     end
%     
%     if x(c) == 0 
%         zerocounter = zerocounter + 1;
%     end
%     
%     if x(c) ~= 0 && zerocounter >= 100
%          diff = c - startIndex;
%          
%          x(startIndex - 1:c + 1) = x(startIndex - 1:c + 1) + (x(c + 1: c + 1 + diff + 2));
%          crashes = crashes + 1;
%          zerocounter = 0;
%     elseif x(c) ~= 0
%         zerocounter = 0;
%     end
%     
%     if x(c) > 0.18 || x(c) < -0.18
%         x(c) = x(c - 1);
%     end
% end
% plot(x);
% sound(x);
% audiowrite("output.wav",x,Fs)

%% IDEA 2
%vymazání chybného místa (zkrácení nahrávky)

newSound = zeros(1,length(x));
newIndex = 1;
zerocounter = 0;

for c = 1:length(x)
     if x(c) > 0.18 || x(c) < -0.18
        continue;
     end
    
     if x(c) == 0 
         zerocounter = zerocounter + 1;
     end
    
     if x(c) ~= 0 && zerocounter >= 100
        newIndex = newIndex - zerocounter;
        zerocounter = 0;
        continue;
     elseif x(c) ~= 0
         zerocounter = 0;
     end
    
    newSound(newIndex) = x(c);
    newIndex = newIndex + 1;
end

plot(newSound);
sound(newSound);
audiowrite("output.wav",newSound,Fs)