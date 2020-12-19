function [outputImage] = center_image(inputImage)
    alteredImage=255-inputImage;
    imageRows=size(alteredImage,1);
    imageColumns=size(alteredImage,2);
    [x, y] = meshgrid(1:imageRows, 1:imageColumns);
    weightedx = x .* alteredImage;
    weightedy = y .* alteredImage;
    cogX = round(sum(weightedy(:)) / sum(alteredImage(:)));
    cogY = round(sum(weightedx(:)) / sum(alteredImage(:)));
    outputImage=circshift(alteredImage,[16-cogX 16-cogY]);
end

