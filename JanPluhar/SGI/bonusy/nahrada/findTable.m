function [table] = findTable(image,invert)
tempImage=image > 80;
if invert
tempImage=1-tempImage;
end   
[rows, columns]=find(tempImage);
row1 = min(rows);
row2 = max(rows);
col1 = min(columns);
col2 = max(columns);
table = image(row1:row2, col1:col2);
end



