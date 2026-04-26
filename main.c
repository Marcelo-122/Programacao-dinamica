#include "dinamica.h"

int main() {
    int opcao;

    printf("Escolha o algoritmo de programacao dinamica:\n");
    printf("1 - Fibonacci (todas as versoes)\n");
    printf("2 - LIS - Subsequencia Crescente Mais Longa (todas as versoes)\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {

        case 1: {
            int n;
            printf("Digite o valor de n para Fibonacci: ");
            scanf("%d", &n);

            if (n < 0 || n > MAX_N) {
                printf("Valor invalido. Use entre 0 e %d.\n", MAX_N);
                break;
            }

            // Recursivo (evita n grande pois é exponencial)
            if (n <= 40) {
                printf("\n[Recursivo]   fib(%d) = %lld\n", n, fib_recursivo(n));
            } else {
                printf("\n[Recursivo]   n = %d muito grande (exponencial). Pulando.\n", n);
            }

            // Top-Down
            long long memo[MAX_N + 1];
            for (int i = 0; i <= n; i++) memo[i] = -1;
            printf("[Top-Down]    fib(%d) = %lld\n", n, fib_top_down(n, memo));

            // Bottom-Up
            printf("[Bottom-Up]   fib(%d) = %lld\n", n, fib_bottom_up(n));
            break;
        }

        case 2: {
            int n;
            printf("Digite o tamanho da sequencia: ");
            scanf("%d", &n);

            if (n <= 0 || n > MAX_N) {
                printf("Valor invalido. Use entre 1 e %d.\n", MAX_N);
                break;
            }

            int num[MAX_N];
            printf("Digite os %d elementos da sequencia: ", n);
            for (int i = 0; i < n; i++)
                scanf("%d", &num[i]);

            printf("\nSequencia: [");
            for (int i = 0; i < n; i++)
                printf("%d%s", num[i], i < n - 1 ? ", " : "");
            printf("]\n");

            // Recursivo (evita n grande)
            if (n <= 25) {
                printf("\n[Recursivo]  LIS = %d\n", lis_recursivo(num, n));
            } else {
                printf("\n[Recursivo]  n = %d muito grande (exponencial). Pulando.\n", n);
            }

            // Top-Down
            printf("[Top-Down]   LIS = %d\n", lis_top_down(num, n));

            // Bottom-Up
            printf("[Bottom-Up]  LIS = %d\n", lis_bottom_up(num, n));
            break;
        }
        
        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}