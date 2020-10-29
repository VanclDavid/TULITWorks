clear
%% Hodnoty
inputFile = "TableOfNumbers.png";
workingFolder = "data";
% workingFolder = ".";


%% Nactení obrázku
inputImg = imread(strcat(workingFolder, "/", inputFile));
inputImg = img2gray(inputImg);
imshow(inputImg);

%% Zjištění velikosti buňky
Cells = getCells(inputImg, [1,1]);

%%
border = 5;
for x = 1:(length(Cells(1,:))/2)
    for y = 1:(length(Cells(2,:))/2)
        tmpImg = inputImg( border+ Cells(1,x*2-1):Cells(1,x*2) -border, border+ Cells(2,y*2-1):Cells(1,y*2)-border );
        tmpImg = imresize(tmpImg, [32, NaN]);
%         imshow(tmpImg);
        imwrite(tmpImg, sprintf('%s/c%d_p0000_s%02d.jpg',workingFolder,(x-1),y));
%         pause();
    end
end


%% Pro obázek a pozici zjitím jak moc můzu jít než narazím na čáru
function cells = getCells(image, position)

% [X1,X2...; Y1 Y2....]
cells = [];

    
%         find(inputImg(1:end,1)>5);
tmpPos = [1];
isWhite = true;
wasWhite = true;

    for x = position(1):size(image,1)
        isWhite = image( x,2 ) >= 200;
        if(isWhite ~= wasWhite) % hrana buňky
            tmpPos(end+1) = x;
        end
%         if(isWhite == false && wasWhite == true) % konec buňky
%             tmpPos(end+1) = x;
%         end
%         if(isWhite == true && wasWhite == false) % začátek buňky
%             
%         end
        wasWhite = isWhite;
    end    
    tmpPos(end+1) = x;
    
    cells = tmpPos;
    tmpPos = [1];
    for y = position(2):size(image,2)
        isWhite = image( 2,y ) >= 200;
        if(isWhite ~= wasWhite) % hrana buňky
            tmpPos(end+1) = y;
        end
        wasWhite = isWhite;
    end
    tmpPos(end+1) = y;
        
    cells = [cells; tmpPos];
        
end

function img = img2gray(imgIN)
    img = uint8(sum( double(imgIN) ,3)./3);
end