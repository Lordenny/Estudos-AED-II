// Faça um programa que defina se um número é divisível por 11

int div_11(int num) {
    if (num < 10) return (num == 0);
    return div_11((num / 10) - (num % 10));
}