// Faça um programa que defina se um número é divisível por 11

#include <stdio.h>

int div_11(int num) {
    int soma_impares = 0, soma_pares = 0, eh_impar = 1;

    while (num > 0) {
        if (eh_impar) {
            soma_impares += num % 10;
        } else {
            soma_pares += num % 10;
        }
        num /= 10;
        eh_impar = !eh_impar;
    }

    return (soma_pares - soma_impares) % 11 == 0;
}

int main() {
    int n;
    printf("Insira seu número: ");
    scanf("%d", &n);
    if (div_11(n)) {
        printf("Seu número é divisível por 11\n");
    } else {
        printf("Seu número NÃO é divisível por 11\n");
    }

    return 0;
}
