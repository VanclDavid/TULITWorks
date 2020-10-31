directoryName = 'Numbers';
files = dir(fullfile(directoryName,'*.jpg'));

for i = 1:numel(files)
    subplot(10,10,i);
    imagePath = fullfile(directoryName,files(i).name);
    image = imread(imagePath);
    imshow(image);
end