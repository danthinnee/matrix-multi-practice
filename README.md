# matrix-multi-practice

## Summary

This short program timed the amount of seconds it took to multiply randomly populated (from 1-100) 1000x1000  and 1000x1 matrix together *not in parallel*. It iterated the process several times to improve accuracy in timing, accomplished by the C++ time object.

## Results

The MATLAB script and accompanying graphs show amount of time taken for a set of iterations and averaged for a single matrix multiplication. I looked at the differences between smaller scale and larger scale comparisons - as expected, more variation on the smaller scale. 
The average calculated from the most iterations, presumably the most accurate, times about **0.00629 seconds per matrix multiplication.**
Initially calculations were intended to eliminate effect of using ctime to determine difference in time. However, the program to this end showed that defining and printing the time elapsed took a negligible portion of time, even when repeated 48,010 times.
