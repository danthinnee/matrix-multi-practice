# matrix-multi-practice

## Summary

This short program timed the amount of seconds it took to multiply randomly populated (from 1-100) 1000x1000  and 1000x1 matrix together not in parallel. It iterated the process several times to improve accuracy in timing, accomplished by the C++ time object.

## Results

The matlab script and accompanying graphs show amount of time taken for a set of iterations and averaged for a single matrix multiplication.
The average calculated from the most iterations, presumably the most accurate, times about **0.00629 s per matrix multiplication.**
Initially calculations were intended to eliminate effect of using ctime to determine difference in time. However, the prograam to this end showed that defining and printing the time elapsed took a negligible portion of time, even for 48,010 iterations.
