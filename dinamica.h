#ifndef DINAMICA_H
#define DINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

// Fibonacci
long long fib_recursivo(int n);
long long fib_top_down(int n, long long memo[]);
long long fib_bottom_up(int n);

// LIS - Longest Increasing Subsequence
int lis_recursivo_aux(int num[], int i);
int lis_recursivo(int num[], int n);

int lis_top_down_aux(int num[], int i, int L[]);
int lis_top_down(int num[], int n);

int lis_bottom_up(int num[], int n);

#endif