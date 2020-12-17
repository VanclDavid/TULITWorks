function [outputImage] = adjust_brightness(inputImage)
bMax=max(max(inputImage));
bMax=255/bMax;
outputImage=inputImage.*(bMax);

end

