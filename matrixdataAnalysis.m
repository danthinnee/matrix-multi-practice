filename1 = 'matrixtimer.csv';
xlrange = 'A:C';
matrixdata = xlsread(filename1, xlrange);

filename2 = 'matrixtimerlower.csv';
xlrange2 = 'B:C';
matrixdata2 = xlsread(filename2, xlrange2);

for(i = 1:length(matrixdata2(:,1)))
    singletime2(i) = matrixdata2(i,1) / matrixdata2(i,2);
end

plot(matrixdata(:,1), matrixdata(:,2));
xlabel('Number of Iterations');
ylabel('Total Program Time');
title('Iterations vs Total Program Time');
figure;
plot(matrixdata(:,1), matrixdata(:,3));
xlabel('Number of Iterations');
ylabel('Single Multiplication Time');
title('Iterations vs Time to Multiply Single Matrix');

figure;
plot(matrixdata2(:,2), matrixdata2(:,1));
xlabel('Number of Iterations');
ylabel('Total Program Time');
title('Iterations vs Total Program Time');
figure;
plot(matrixdata2(:,2), singletime2);
xlabel('Number of Iterations');
ylabel('Single Multiplication Time');
title('Iterations vs Time to Multiply Single Matrix');