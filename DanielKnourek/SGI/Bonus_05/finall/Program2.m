clear
%% Hodnoty
workingFolder = "data";
% workingFolder = ".";

%% nactení názvu obrázků
fileNames = string({dir("data").name});
fileNames = fileNames(contains(fileNames,".jpg"));

for i = 1:length(fileNames)
   subplot(10,10,i);
   imshow( imread( strcat(workingFolder, "/", fileNames(i)) ));
   title(fileNames(i));
end