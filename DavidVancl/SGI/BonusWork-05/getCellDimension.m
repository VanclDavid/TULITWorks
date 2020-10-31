function [x,y] = getCellDimension(table,horizontalLine, veritcalLine)
    xTMP = table(horizontalLine, :);
    yTMP = table(:, veritcalLine);
    
    nowIS = "WHITE";
    whiteCounter = 0;
    
    x = 0;
    for i = 1:length(xTMP)
        if xTMP(i) < 150 && nowIS ~= "BLACK"
            nowIS = "BLACK";
        end
        
        if xTMP(i) > 150 && nowIS ~= "WHITE"
            nowIS = "WHITE";
        end
        
        if nowIS == "WHITE"
            whiteCounter = whiteCounter + 1;
        else
            if whiteCounter > x
                x = whiteCounter;
            end
            whiteCounter = 0;
        end
    end
    
    nowIS = "WHITE";
    whiteCounter = 0;
    y = 0;
    for i = 1:length(yTMP)
        if xTMP(i) < 150 && nowIS ~= "BLACK"
            nowIS = "BLACK";
        end
        
        if xTMP(i) > 150 && nowIS ~= "WHITE"
            nowIS = "WHITE";
        end
        
        if nowIS == "WHITE"
            whiteCounter = whiteCounter + 1;
        else
            if whiteCounter > y
                y = whiteCounter;
            end
            whiteCounter = 0;
        end
    end
end