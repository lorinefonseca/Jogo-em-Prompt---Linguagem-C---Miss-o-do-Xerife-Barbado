# Jogo em Prompt - Linguagem C - Missão do Xerife Barbado

Este Jogo foi Criado no Primeiro Semestre da Graduação de Jogos Digitais, na disciplina de Programação I.
A idéia era desenvolver um jogo que pudesse ser jogado diretamente no Prompt.

O professor nos entregou um código base, onde realizamos algumas alterações para deixar tudo mais interativo e divertido para o usuário.

Seguem os pontos alterados:
A partir do código base, implementamos um menu de início de jogo, uma carta de apresentação da história e um sistema de pontuação baseado em coleta de itens, além de um monstro adicional, totalizando 2 inimigos.
A ideia do jogo é coletar os tesouros espalhados pelos níveis da caverna, enquanto evita os inimigos e tenta chegar a saída.

<h3>EXPLICANDO O CÓDIGO</h3>
• Linha 13 – altera a cor do prompt<br>
• Linha 19 – cria uma variável de confirmação de início do jogo<br>
• Linha 22 – cria a variável da saída com as coordenadas para o centro da matriz/mapa<br>
• Linha 23 a 25 – cria as variáveis de itens em posições aleatórias da matriz/mapa<br>
• Linha 28 a 30 – cria variáveis para identificar se o item está presente ou não<br>
• Linha 33 – cria uma variável que armazena a pontuação<br>
• Linha 34 – cria uma variável que armazena o nível do jogo<br>
• Linha 35 – cria variável de coordenadas<br>
• Linha 38 a 40 – cria as variáveis do jogador<br>
• Linha 43 e 44 – cria as variáveis dos monstros <br>
• Linha 48 a 52 – exibe um menu de início do jogo<br>
• Linha 54 a 66 – exibe uma carta de introdução a história do jogo<br>
• Linha 73 – inicia um loop infinito<br>
• Linha 75 – limpa a tela<br>
• Linha 77 a 109 – desenha o jogo, exibindo paredes, tesouros, o jogador, monstros e a saída<br>
• Linha 112 a 114 – exibe uma caixa de inserir o comando do movimento<br>
• Linha 117 a 156 – recebe o comando de movimento e move o jogador<br>
• Linha 157 a 171 – uma sequência de if e else que confere se o tesouro foi pego ou não, e adiciona uma pontuação baseada no tipo de tesouro<br>
• Linha 174 a 239 – sequência de switch case responsável pela movimentação de ambos os monstros<br>
• Linha 241 a 243 – identifica se o jogador se encontrou com o monstro e encerra o jogo caso o mesmo tenha ocorrido<br>
• Linha 244 a 271 – identifica se o jogador pegou o tesouro principal e passou pela saída, em caso afirmativo, aumenta o nível e redefine as posições<br>
• Linha 274 a 276 – identifica se o jogador passou pela saída sem possuir o tesouro principal, em caso afirmativo, o jogador não passa para o próximo item até passar pela saída com o tesouro em mãos<br>
• Linha 277 a 280 – identifica se o nível do jogo é igual a 6, em caso afirmativo, encerra o jogo e exibe a sua pontuação<br>
• Linha 286 a 287 – reseta o jogo<br>
