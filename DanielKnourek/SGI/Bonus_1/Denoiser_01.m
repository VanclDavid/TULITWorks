%% Denoiser 0.1
clear;
fileName = "hudba_praskani.wav";

[y,Fs] = audioread(fileName);

%% dev content


ytmp = y;
ytmp(strfind(ytmp', zeros(1,5))) = "NaN";
y2 = ytmp(~isnan(ytmp));
strfind(y', zeros(1,10));

for i = 2:(length(y2)-1)
    expected = mean([y2(i-1) y2(i+1)]);
    toleration = abs(y2(i-1) - y2(i+1));
    if(abs(expected - y2(i)) > 5*toleration)
       y2(i) =  expected;
    end
end

%% plot

% figure(1)
% plot(1:length(y), y, 'r');
% 
% hold on;
% plot(1:length(y2), y2, 'g');
% hold off

% audio test
% sound(y2,Fs);

%% output
outFileName = (strsplit(fileName,'.'));
outFileName = strcat( outFileName(1), "_clear.wav" );

audiowrite(outFileName, y2, Fs)
  
