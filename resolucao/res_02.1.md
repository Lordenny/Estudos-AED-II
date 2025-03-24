# 02.1 - Resolução

> [Código](/src/02-ideias_de-problemas/02.1_divisibilidade-por-11.C)

Vamos lá, para sabermos se um número é divisível por 11 usamos uma propriedade matemática:
> A soma dos dígitos nas posições ímpares e a soma dos dígitos nas posições pares, quando subtraídas, deve ser múltiplo de 11 ou zero.

E é justamente essas operações lógicas que fazemos em `div_11`, iniciamos as variáveis de soma e o mais importante: o `eh_impar`, esse cara vai dizer pra gente se estamos num algarismo par ou ímpar, inicialmente estamos num ímpar (primeiro algarismo) e no final de cada iteração do loop invertemos para não-impar (par).

---

O loop funciona assim, enquanto o número se mantiver maior que 0:
- **Caso seja algarismo ímpar**: adicionamos o último algarismo à soma total dos ímpares.
- **Caso seja algarismo par (else)**: adicionamos o último algarismo à soma total dos pares.

Por fim, dividimos o número por 10 para pegar o próximo algarismo e invertemos o valor de `eh_impar`.

---

Será `True` (divisível por 11), quando a operação `(soma_pares - soma_impares)` for exata, sendo a main a responsável por imprimir pra gente cada uma das situações.
