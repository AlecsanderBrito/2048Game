<h1>2048</h1> 

> Status do Projeto: concluído

### Tópicos 

[Descrição do projeto](#descrição-do-projeto)

[Funcionalidades](#funcionalidades)

[Pré-requisitos](#pré-requisitos)

[Como rodar a aplicação](#como-rodar-a-aplicação-arrow_forward)

... 

## Descrição do projeto 

<p align="justify">
  O projeto é baseado no jogo 2048, criado por Gabriele Cirull. É utilizado a linguagem C para criar o desafio de raciocínio O objetivo é alcançar a pontuação máxima, ou seja, 2048 combinando os valores da grade. Caso ocupe todo o espaço, impossibilitando o progresso, você perde o jogo.
</p>

## Funcionalidades

<p align="justify">
O código é divido em quatro partes como: variáveis globais, controles, parte lógica e o principal.
</p>

<p align="justify">
Variáveis globais, ao todo, o código possui 3 váriaveis globais do tipo inteiro, a variável "matriz[][]" que consiste na matriz que irá gerar a mesa do tamanho 4x4, a variável "pontuacao" que armazena a pontuacao e variável "pfinal" que armazena o estado final da pontuação. 
</p>

<p align="justify">
Controles, há subdivisões de funções, dentre elas, quatro são encarregados das direções como direita, esquerda, cima, baixo e a função "controles()" que reune as funções de direção e válida a interação com o usuário. 
</p>

<p align="justify">
Parte lógica, é divido entre a função sorteador() que aleatoriza os locais dentro da matriz onde pode adiciona-los, foi necessário o uso do comando rand e srand para possibilitar valores aleatórios. A função display() é encarregada de definir o tamanho e as informações na tela do usuário. A função contador() calcula e soma os valores para que possa definir o jogo.
</p>

## Pré-requisitos

[GCC](https://sourceforge.net/projects/mingw/)

...

Todas as bibliotecas usadas no projeto são bibliotecas padrões da linguagem como stdio.h, stdlib.h, time.h e conio.h.

## Desenvolvedores/Contribuintes

[Alecsander de Sousa Brito](https://github.com/alecsbrito)

## Licença 

The [MIT License]() (MIT)

Copyright :copyright: 2022 - 2048