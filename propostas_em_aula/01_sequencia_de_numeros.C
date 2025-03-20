//  Elabore um programa que leia uma sequência de números, e:
//1) se a quantidade de numeros lidos for uma numero primo calcule e exiba a media dos valores obtidos
//2) senão, se a quantidade for par, apresente o maior numero lido; ou se for impar, apresenta o menor
//   lido

#include <stdio.h>

// Função para verificar se um número é primo
int ehprimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Função para verificar se um número é par
int ehpar(int n) {
    return n % 2 == 0;
}

int main() {
    int quantidade = 0, maior, menor, continua, total = 0;
    
    printf("Quer botar numero? (1 para sim, 0 para não): ");
    scanf("%d", &continua);
    
    if (continua == 0) {
        printf("Nenhum número inserido.\n");
        return 0;
    }

    while (continua == 1) {
        int num;
        printf("Digite um número: ");
        scanf("%d", &num);

        if (quantidade == 0) {
            maior = menor = num;  // Primeiro número define maior e menor
        } else {
            if (num > maior) maior = num;
            if (num < menor) menor = num;
        }

        total += num;
        quantidade += 1;

        printf("Quer continuar? (1 para sim, 0 para não): ");
        scanf("%d", &continua);
    }

    if (ehprimo(quantidade)) {
        printf("Média: %.2f\n", (float) total / quantidade);
    } else if (ehpar(quantidade)) {
        printf("Maior número: %d\n", maior);
    } else {
        printf("Menor número: %d\n", menor);
    }

    return 0;
}
