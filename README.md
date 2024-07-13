# FIR Filter Project

## Project Description

This project implements a FIR (Finite Impulse Response) filter in C, operating on fixed-point data (Q15 format). The filtering is performed using coefficients defined in a header file.

## Project Files

- `main.c`: The main source file containing the implementation of the FIR filter.
- `fdacoefs_float_double.h`: Header file containing the filter coefficients in floating point format.

## Compilation and Execution

To compile the project, use the following command (example for GCC):

```bash
gcc -o fir_filter main.c
