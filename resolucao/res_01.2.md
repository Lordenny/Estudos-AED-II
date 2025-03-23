# 01.2 - Resolução

> Testado com valores até 100000000000000001

Apesar da questão ser a mesma, a solução adotada aqui é bem diferente. Caso deseje, você pode tentar outra abordagem, mas esta foi a minha solução.

## Estrutura do Código

### Função `processar_numeros`

A função `processar_numeros` é recursiva e recebe os seguintes parâmetros:
- `quantidade`: conta quantos números foram lidos.
- `soma`: soma total dos números lidos.
- `menor`: menor número encontrado.
- `maior`: maior número encontrado.

A função continua a ser chamada recursivamente até que o valor lido seja `-1` (condição de parada). Ao atingir esse ponto, ela verifica:
- Se a quantidade de números lidos é primo.
- Se os números são pares ou ímpares.
- Se é o primeiro número lido, para definir maior e menor.
- Atualiza os valores e faz nova chamada recursiva com os dados ajustados.

---

## Função `EhPrimo`

Esta função verifica se um número é primo com base nas seguintes regras:
- Qualquer valor menor que `2` não é primo.
- Define diretamente os primos menores que `10`.
- Verifica divisibilidade por:
  - `2`
  - `3`
  - `5` (se o último algarismo for `5`)
  - `7`
  - `11`
  - `13`
  - `17`
  - `19`
  - `23`
  - `29`
  - `31`

Se for divisível por qualquer um desses, não é primo.

---

## Funções de Divisibilidade

Estas funções verificam se um número é divisível por certos primos usando técnicas recursivas.

### `div_3`

Utiliza recursão para somar os algarismos do número até que reste um único dígito e verifica se esse dígito é `3`, `6` ou `9`.

#### Exemplo:
Verificando se `312` é divisível por `3`:
- `312` → `31 + 2 = 33`
- `33` → `3 + 3 = 6`
- `6` é um dos valores aceitos → **Divisível por 3**

---

### `div_7`

Baseia-se na propriedade:
> Um número é divisível por 7 se a diferença entre o número sem o último dígito e o dobro do último dígito também for divisível por 7.

#### Exemplo:
Verificando se `343` é divisível por `7`:
- `343` → `34 - (2 × 3) = 28`
- `28` → `2 - (2 × 8) = -14`
- `-14` torna-se `14` → `1 - (2 × 4) = -7`
- `-7` torna-se `7`, e `7` é divisível por `7` → **Divisível por 7**

---

### `div_11`

Baseia-se na propriedade:
> Um número é divisível por 11 se a diferença entre a soma dos dígitos em posições ímpares e a soma dos dígitos em posições pares também for divisível por 11.

#### Exemplo:
Verificando se `121` é divisível por `11`:
- `121` → `12 - 1 = 11`
- `11` → `1 - 1 = 0`
- `0` é divisível por `11` → **Divisível por 11**

---

### `div_geral`

Esta função verifica divisibilidade de um número por qualquer divisor primo.

#### Exemplo:
```cpp
int div_geral(int num, int divisor) {
    return (num % divisor == 0);
}
```
Essa abordagem é mais genérica e eficiente para verificar a divisibilidade de um número.

---

## Conclusão

Este código utiliza recursão para verificar a divisibilidade de números por diferentes primos de forma otimizada. Ele também inclui uma abordagem geral (`div_geral`) que permite verificar a divisibilidade de qualquer número sem precisar de regras específicas para cada caso. A documentação foi organizada para facilitar a compreensão e futura manutenção do código.

