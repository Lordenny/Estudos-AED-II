// Elabore um programa que leia uma sequência de números, e:
// 1)se a quantidade de numeros lidos for uma numero primo calcule e exiba a media dos valores obtidos
// 2)senão, se a quantidade for par, apresente o maior numero lido; ou se for impar, apresenta o menor
// lido
// OBS:. A resolução será recursiva utilizando os axiomas de divisibilidade ao invés de iterações com cálculos


#include <stdio.h>

// Função que retorna o último algarismo de um número
int ultimo_alg(int num) {
    return num % 10;
}

// Função para verificar divisibilidade por 3 (soma dos algarismos é múltiplo de 3)
int div_3(int num) {
    if (num < 10) return (num == 3 || num == 6 || num == 9);
    return div_3(num / 10 + num % 10);
}

// Função para verificar divisibilidade por 7 (método recursivo baseado em 2x último dígito)
int div_7(int num) {
    if (num < 0) num = -num;  // Transforma em positivo
    if (num < 10) return (num == 0 || num == 7);
    return div_7((num / 10) - 2 * (num % 10));
}


// Função para verificar divisibilidade por 11 (diferença entre soma de índices pares e ímpares)
int div_11(int num) {
    if (num < 10) return (num == 0);
    return div_11((num / 10) - (num % 10));
}

// Função genérica para verificar divisibilidade por números primos > 5 (div_13, div_17, etc.)
int div_geral(int num, int divisor) {
    return (num % divisor == 0);
}


// Função que verifica se um número é primo de forma recursiva usando axiomas de divisibilidade
int ehprimo(int n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3 || n == 5 || n == 7) return 1;
    if (n % 2 == 0 || div_3(n) || ultimo_alg(n) == 5 || div_7(n) || div_11(n) ||
        div_geral(n, 13) || div_geral(n, 17) || div_geral(n, 19) ||
        div_geral(n, 23) || div_geral(n, 29) || div_geral(n, 31)) {
        return 0;
    }
    return 1;
}

// Função recursiva para processar os números e calcular os resultados
void processar_numeros(int qtd, int soma, int min, int max) {
    int num;
    printf("Digite um número (-1 para parar): ");
    scanf("%d", &num);

    if (num == -1) { // Condição de parada
        printf("\nQuantidade de números lidos: %d\n", qtd);
        if (ehprimo(qtd)) {
            printf("A quantidade de números é PRIMO, média dos valores: %.2f\n", (float)soma / qtd);
        } else if (qtd % 2 == 0) {
            printf("A quantidade de números é PAR, maior número lido: %d\n", max);
        } else {
            printf("A quantidade de números é ÍMPAR, menor número lido: %d\n", min);
        }
        return;
    }

    // Atualiza soma, min e max
    if (qtd == 0) { // Primeiro número lido
        min = max = num;
    } else {
        if (num < min) min = num;
        if (num > max) max = num;
    }

    // Chama recursivamente com os valores atualizados
    processar_numeros(qtd + 1, soma + num, min, max);
}

int main() {
    processar_numeros(0, 0, 0, 0);
    return 0;
}
