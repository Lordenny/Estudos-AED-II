# 01.1 - Resolução
O problema nos exige alguns conhecimentos (provavelmente) adquiridos em AED I, então vamos direto para a main. Conforme inserirmos os numeros precisaremos de um contador `quantidade`que diz pra gente quantos números teremos, além de algumas variáveis de valores inteiros(maior, menor, total).


A primeira iteração `continua` será nosso validador se a função entrará em loop ou se finalizará sem número.
> Observe que usamos dois `continua` diferentes


Ao entrarmos no loop `while` ocorre escaneamento do número que será adicionado. Em seguida o `if`verifica se foi o primeiro numero inserido (caso quantidade seja 0), se for o caso então ele se tornará o maior e menor ao mesmo tempo.


**E se não for o primeiro número inserido?**


Nesse caso, o `else` fará uma pequena verificação se esse valor é maior ou menor que o armazenado anteriormente


No final de cada iteração, ocorre a soma do numero ao `total` que havia sido iniciado com 0; Além da adição de uma unidade a `quantidade`. Agora temos o segundo `continua`, onde esse se repete pois está dentro do loop.


Antes de fecharmos a main, precisamos ir para a função `ehprimo()` que **retorna 1** caso seja primo e **retorna 0** caso não seja, esse cara funciona da seguinte forma
- inicialmente temos a condição de ele ser maior que 2, caso contrário ele imediatamente não é primo (conceito base de número primo)
- um loop for com índice inicial = 2, que iterar incrementando enquanto ele for menor ou igual ao n (no caso a quantidade de números)
- se durante as iterações, o valor de uma divisão por qualquer que seja os índices der 0 (ou seja, ocorra uma divisão exata), então esse número não é primo, pois é divisível por alguém.
- se durante essas iterações isso não ocorrer, então ele é primo (retorna 1)


A função `ehpar()` é bem mais simples, se numa divisão por 2 restar 0 (ou seja, ocorra uma divisão exata), então ele é par.


Voltando a `main` na linha 50, ele faz as condicionais finais verificando e produzindo conforme pedido na questão
> Não é necessário a função para ímpares, visto que se o número não é par, ele é ímpar