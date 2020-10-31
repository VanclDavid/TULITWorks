for i = 0 : 9
    for j = 1 : 10
    subplot(10,10,(i*10)+j);
    name="c"+i+"_p0000_s"+sprintf('%02d',j)+".jpg"
    image=imread(name);
    imshow(image);
    end
end