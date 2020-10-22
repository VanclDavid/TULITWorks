[x,Fs] = audioread("cv04_00.wav");

energie = zeros(1,round(length(x) / 100));
index = 1;
suma = 0;
for i=1:length(x) 
    suma = suma + (x(i) * x(i));
    if i == 100*index || i == length(x)
        energie(index) = suma;
        suma = 0;
        index = index + 1;
    end
end

diff = zeros(1,round(length(x) / 100) - 1);
for i=2:length(energie)
    diff(i - 1) = energie(i) - energie(i - 1);
end

subplot(3,1,1);
plot(x);
subplot(3,1,2);
plot(energie);
subplot(3,1,3);
plot(diff);

saveas(gcf, 'output.png')