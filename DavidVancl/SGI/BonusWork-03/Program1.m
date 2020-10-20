clear all
clc

subplot(4,2,1);
plot(getArrayEnergy(audioread("My/J01.wav")));
title('J01');

subplot(4,2,2);
plot(getArrayEnergy(audioread("My/Z01.wav")));
title('Z01');

subplot(4,2,3);
plot(getArrayEnergy(audioread("My/J02.wav")));
title('J02');

subplot(4,2,4);
plot(getArrayEnergy(audioread("My/Z02.wav")));
title('Z02');

subplot(4,2,5);
plot(getArrayEnergy(audioread("My/J03.wav")));
title('J03');

subplot(4,2,6);
plot(getArrayEnergy(audioread("My/Z03.wav")));
title('Z03');

subplot(4,2,7);
plot(getArrayEnergy(audioread("My/J04.wav")));
title('J04');

subplot(4,2,8);
plot(getArrayEnergy(audioread("My/Z04.wav")));
title('Z04');