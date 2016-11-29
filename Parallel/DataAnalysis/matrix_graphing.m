filename = 'ParallelTimes_8pt8192x.csv';
xlrange = 'A:B'; 
parallel88 = xlsread(filename, xlrange);

filename1 = 'ParallelTimes_8pt4096x.csv';
xlrange = 'A:B'; 
parallel84 = xlsread(filename1, xlrange);

filename2 = 'ParallelTimes_8pt2048x.csv';
xlrange = 'A:B'; 
parallel82 = xlsread(filename2, xlrange);

filename3 = 'ParallelTimes_8pt1024x.csv';
xlrange = 'A:B'; 
parallel81 = xlsread(filename3, xlrange);

filename4 = 'ParallelTimes_4pt8192x.csv';
xlrange = 'A:B'; 
parallel48 = xlsread(filename4, xlrange);

filename5 = 'ParallelTimes_4pt4096x.csv';
xlrange = 'A:B'; 
parallel44 = xlsread(filename5, xlrange);

filename6 = 'ParallelTimes_4pt2048x.csv';
xlrange = 'A:B'; 
parallel42 = xlsread(filename6, xlrange);

filename7 = 'ParallelTimes_4pt1024x.csv';
xlrange = 'A:B'; 
parallel41 = xlsread(filename7, xlrange);

filename8 = 'ParallelTimes_2pt8192x.csv';
xlrange = 'A:B'; 
parallel28 = xlsread(filename8, xlrange);

filename9 = 'ParallelTimes_2pt4096x.csv';
xlrange = 'A:B'; 
parallel24 = xlsread(filename9, xlrange);

filename10 = 'ParallelTimes_2pt2048x.csv';
xlrange = 'A:B'; 
parallel22 = xlsread(filename10, xlrange);

filename11 = 'ParallelTimes_2pt1024x.csv';
xlrange = 'A:B'; 
parallel21 = xlsread(filename11, xlrange);

filename12 = 'Sequential_1k.csv';
xlrange = 'A:B'; 
sequential1 = xlsread(filename12, xlrange);

filename13 = 'Sequential_2k.csv';
xlrange = 'A:B'; 
sequential2 = xlsread(filename13, xlrange);

filename14 = 'Sequential_4k.csv';
xlrange = 'A:B'; 
sequential4 = xlsread(filename14, xlrange);

filename15 = 'Sequential_8k.csv';
xlrange = 'A:B'; 
sequential8 = xlsread(filename15, xlrange);

filename16 = 'ParallelTimes_16pt1024x.csv';
xlrange = 'A:B'; 
parallel161 = xlsread(filename16, xlrange);

filename17 = 'ParallelTimes_16pt2048x.csv';
xlrange = 'A:B'; 
parallel162 = xlsread(filename17, xlrange);

filename18 = 'ParallelTimes_16pt4096x.csv';
xlrange = 'A:B'; 
parallel164 = xlsread(filename18, xlrange);

filename19 = 'ParallelTimes_16pt8192x.csv';
xlrange = 'A:B'; 
parallel168 = xlsread(filename19, xlrange);

plot(parallel168(:,1), parallel168(:,2), '-o', parallel88(:,1), parallel88(:,2), '-o',parallel48(:,1),parallel48(:,2),'-o',parallel28(:,1),parallel28(:,2),'-o',sequential8(:,1),sequential8(:,2),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time for an 8192x8192 matrix');
legend('16 pthreads','8 pthreads','4 pthreads','2 pthreads','sequential');

figure;
plot(parallel164(:,1), parallel164(:,2), '-o', parallel84(:,1), parallel84(:,2), '-o',parallel44(:,1),parallel44(:,2),'-o',parallel24(:,1),parallel24(:,2),'-o',sequential4(:,1),sequential4(:,2),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time for an 4096x4096 matrix');
legend('16 pthreads','8 pthreads','4 pthreads','2 pthreads','sequential');

figure;
plot(parallel162(:,1), parallel162(:,2), '-o', parallel82(:,1), parallel82(:,2), '-o',parallel42(:,1),parallel42(:,2),'-o',parallel22(:,1),parallel22(:,2),'-o',sequential2(:,1),sequential2(:,2),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time for an 2048x2048 matrix');
legend('16 pthreads','8 pthreads','4 pthreads','2 pthreads','sequential');

figure;
plot(parallel161(:,1), parallel161(:,2), '-o', parallel81(:,1), parallel81(:,2), '-o',parallel41(:,1),parallel41(:,2),'-o',parallel21(:,1),parallel21(:,2),'-o',sequential1(:,1),sequential1(:,2),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time for an 1024x1024 matrix');
legend('16 pthreads','8 pthreads','4 pthreads','2 pthreads','sequential');

figure;
plot(parallel88(:,1), parallel88(:,2), '-o',parallel44(:,1),parallel44(:,2),'-o',parallel22(:,1),parallel22(:,2),'-o',sequential1(:,1),sequential1(:,2),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time for varying matrices and pthreads');
legend('8 pthreads, 8192x matrix','4 pthreads, 4096x matrix','2 pthreads, 2048x matrix','sequential, 1024xmatrix');

figure;
plot(parallel88(:,1), parallel88(:,2), '-o',parallel84(:,1),parallel84(:,2),'-o',parallel82(:,1),parallel82(:,2),'-o',parallel81(:,1),parallel81(:,2),'-o',sequential1(:,1),sequential1(:,2),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time for varying matrices and 8pthreads');
legend('8 pthreads, 8192x matrix','8 pthreads, 4096x matrix','8 pthreads, 2048x matrix','8 pthreads, 1024x matrix', 'sequential, 1024xmatrix');

figure;
plot(sequential8(:,1),sequential8(:,2),'-o', sequential4(:,1),sequential4(:,2),'-o', sequential2(:,1),sequential2(:,2),'-o', sequential1(:,1),sequential1(:,2),'-o');
xlabel('Number of Iterations');
ylabel('Total Program Time (s)');
title('Iterations vs Total Program Time for varying matrices, sequentially multiplied');
legend('8192x matrix','4096x matrix','2048x matrix','1024x matrix');
