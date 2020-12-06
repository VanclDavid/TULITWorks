Files=dir('**/*.wav');
fileID = fopen('FileList.txt','w');
for k=1:length(Files)
   fprintf(fileID,'%s\r\n',Files(k).folder+"\"+Files(k).name);
end
fclose('all');