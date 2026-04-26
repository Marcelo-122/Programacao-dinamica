#include "dinamica.h"
//  FIBONACCI

// Versão Recursiva
// Recorrência (slide 7):
//   fib(0) = 0
//   fib(1) = 1
//   fib(n) = fib(n-1) + fib(n-2),  n > 1
//
// Tempo: O(2^n) — exponencial, pois recalcula os mesmos subproblemas
long long fib_recursivo(int n) {
    if (n == 0 || n == 1)
        return n;
    return fib_recursivo(n - 1) + fib_recursivo(n - 2);
}

// Versão Top-Down (Memoization) — slide 9
// Armazena em memo[] o resultado de cada fib(n) já calculado.
// memo[] deve ser inicializado com -1 antes da primeira chamada.
//
// Tempo: O(n)
long long fib_top_down(int n, long long memo[]) {
    if (memo[n] != -1)          /* caso já calculado */
        return memo[n];
    if (n == 0 || n == 1)
        memo[n] = n;
    else
        memo[n] = fib_top_down(n - 1, memo) + fib_top_down(n - 2, memo);
    return memo[n];
}

// Versão Bottom-Up (Tabulation) — slide 12
// Inicia os casos base e preenche a tabela de baixo para cima.
//
// Tempo: O(n)
long long fib_bottom_up(int n) {
    if (n == 0 || n == 1)
        return n;

    long long f[MAX_N + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}


//  LIS — Longest Increasing Subsequence

// Versão Recursiva — slide 34
// LIS(i): tamanho da maior subsequência crescente que termina no índice i.
//
//   LIS(0) = 1
//   LIS(i) = max{ LIS(j) + 1 } para todo j < i onde num[j] < num[i]
//
// Tempo: Exponencial (recalcula subproblemas repetidamente)
int lis_recursivo_aux(int num[], int i) {
    if (i == 0)
        return 1;

    int maior = 1;
    for (int j = 0; j < i; j++) {
        if (num[j] < num[i]) {
            int val = lis_recursivo_aux(num, j) + 1;
            if (val > maior)
                maior = val;
        }
    }
    return maior;
}

// Função principal recursiva — percorre todos os índices e retorna o maior LIS
int lis_recursivo(int num[], int n) {
    int maior = 1;
    for (int i = 1; i < n; i++) {
        int val = lis_recursivo_aux(num, i);
        if (val > maior)
            maior = val;
    }
    return maior;
}

// Versão Top-Down (Memoization) — slide 37
// L[i] armazena o LIS que termina no índice i; inicializado com -1.
//
// Tempo: O(n^2)
int lis_top_down_aux(int num[], int i, int L[]) {
    if (L[i] != -1)             /* caso já calculado */
        return L[i];
    if (i == 0)
        return (L[i] = 1);

    int maior = 1;
    for (int j = 0; j < i; j++) {
        if (num[j] < num[i]) {
            int val = lis_top_down_aux(num, j, L) + 1;
            if (val > maior)
                maior = val;
        }
    }
    return (L[i] = maior);
}

// Função principal top-down — slide 38
int lis_top_down(int num[], int n) {
    int L[MAX_N];
    for (int i = 0; i < n; i++)
        L[i] = -1;

    int maior = 1;
    for (int i = 1; i < n; i++) {
        int val = lis_top_down_aux(num, i, L);
        if (val > maior)
            maior = val;
    }
    return maior;
}

// Versão Bottom-Up (Tabulation) 
// L[i] = tamanho da maior subsequência crescente que termina em num[i].
// Preenche L[] da esquerda para direita, usando resultados anteriores.
//
// Tempo: O(n^2)
int lis_bottom_up(int num[], int n) {
    int L[MAX_N];

    /* inicializa todos com 1 (cada elemento sozinho é uma subsequência) */
    for (int i = 0; i < n; i++)
        L[i] = 1;

    int maior = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                if (L[j] + 1 > L[i])
                    L[i] = L[j] + 1;
            }
        }
        if (L[i] > maior)
            maior = L[i];
    }
    return maior;
}