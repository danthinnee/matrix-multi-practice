filename1 = 'paralleldata.csv';
xlrange = 'A:B'; 
matrixdata = xlsread(filename1, xlrange);

filename2 = 'paralleldata_long.csv';
xlrange2 = 'A:B';
matrixdata2 = xlsread(filename2, xlrange2);

for(i = 1:length(matrixdata(:,1)))
    singletime1(i) = matrixdata(i,2) / matrixdata(i,1);
end

for(i = 1:length(matrixdata2(:,1)))
    singletime2(i) = matrixdata2(i,2) / matrixdata2(i,1);
end

plot(matrixdata(:,1), matrixdata(:,2),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time');
figure;
plot(matrixdata(:,1), singletime1,'-o');
xlabel('Number of Iterations');
ylabel('Single Multiplication Time (s)');
title('Iterations vs Time to Multiply Single Matrix');

figure;
plot(matrixdata2(:,1), matrixdata2(:,1),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time');
figure;

plot(matrixdata2(:,1), singletime2,'-o');
xlabel('Number of Iterations');
ylabel('Single Multiplication Time (s)');
title('Iterations vs Time to Multiply Single Matrix');