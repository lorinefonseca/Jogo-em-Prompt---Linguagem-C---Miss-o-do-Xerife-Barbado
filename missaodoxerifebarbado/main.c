#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_LINHA 16
#define MAX_COLUNA 32

int main() {
//comando de regionalização - permite acentos e caracteres especiais - loca tudo como português
//setlocale(LC_ALL, "Portuguese");

//mudando a cor do prompt
system("color 06");


srand(time(NULL));

//Confirmaão
int confirmacao;

// Variavel itens e saida
int ox = (MAX_COLUNA * 0.5), oy = (MAX_LINHA * 0.5);
int ix = 1 + (rand() % 30), iy = 1 + (rand() % 14);
int ax = 1 + (rand() % 30), ay = 1 + (rand() % 14);
int bx = 1 + (rand() % 30), by = 1 + (rand() % 14);

// 1 indica que o item está presente, 0 indica que o item não está mais presente
int item_presente = 1;
int item_presente_a = 1;
int item_presente_b = 1;

// pontuação, nivel e coordenada padrão
int ponto = 0;
int nivel = 1;
int x, y;

// Variáveis player 1
int px = MAX_COLUNA / MAX_COLUNA, py = MAX_LINHA / MAX_LINHA;
char comando;
int movimentoRealizado;

// variaveis monstro
int mx = (int)(MAX_COLUNA * 0.7), my = (int)(MAX_LINHA * 0.5);
int m2x = (int)(MAX_COLUNA * 0.3), m2y = (int)(MAX_LINHA * 0.5);


//Modo de jogo
 printf("=== MISSAO DO XERIFE BARBADO ===\n");
 printf("\nSeja bem-vindo(a) a MISSAO DO XERIFE BARBADO!\n");
 printf("Esta preparado para iniciar essa aventura?\n\n");
 printf("Digite 1 se estiver preparado.\n\n");
 scanf("\n%i", &confirmacao);
 if (confirmacao=1){
    system("CLS");
    printf("=== CARTA AO AVENTUREIRO(A) ===\n\n\n");
    printf("Caro aventureiro(a), voce esta prestes a mergulhar em uma perigosa aventura.\n");
    printf("Os tesouros do castelo foram roubados por criaturas estranhas,\n e soubemos que eles vivem dentro desta caverna.\n");
    printf("Seu objetivo eh coletar o tesouro (!) de cada fase e chegar na saida (@).\n");
    printf("Em cada andar da caverna, se encontram dois guardas esquisitos,\n podemos dizer que sao dois monstros asqueirosos(M) que nao exitam em dilascerar intrusos.\n");
    printf("Dentro dessa caverna tambem eh possivel encontrar duas joias roubadas dos cidadaos (♦),");
    printf("elas nao sao essenciais, mas caso conseguir recupera-las,\n tenho certeza que irao aumentar muito a sua reputacao na cidade.\n");
    printf("Tome cuidado! Nao deixe os monstros te tocar! Eu confio em voce!");
    printf("\n\nSaudacoes,\n\n");
    printf("- Xerife Barbado\n\n");
    printf("\nAperte 1 para fechar a carta e prosseguir.\n\n");
    scanf("\n%i", &confirmacao);
 }


 // CÓDIGO JOGO

    // LOOP INFINITO
    for (;;){
        // limpa a tela
        system("CLS");
        // desenha o jogo
        printf("Caverna das Profundezas - Nivel: %d\n\n", nivel);
        printf("Voce: %c    || Tesouro: !    || Saida: %c    || Monstros: M    || Joias Bonus: %c    \n\n", 1, 254, 4);
        printf("Pontuacao: %i\n\n", ponto);
        for (y = 0; y < MAX_LINHA; y++){
            for (x = 0; x < MAX_COLUNA; x++){
                if (y == 0 || x == 0 || x == MAX_COLUNA - 1 || y == MAX_LINHA - 1)
                    printf("%c", 177);
                else if (x == ix && y == iy && item_presente == 1)
                    printf("!");
                else if (x == px && y == py)
                    printf("%c", 1);
                else if (x == ix && y == iy && item_presente == 0)
                    printf(" ");
                else if (x == ox && y == oy)
                    printf("%c", 254);
                else if (x == mx && y == my)
                    printf("M");
                else if (x == m2x && y == m2y)
                    printf("M");
                else if (x == ax && y == ay && item_presente_a == 1)
                    printf("%c", 4);
                else if (x == ax && y == ay && item_presente_a == 0)
                    printf(".");
                else if (x == bx && y == by && item_presente_b == 1)
                    printf("%c",4);
                else if (x == bx && y == by && item_presente_b == 0)
                    printf(" ");
                else
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");

        // inserir comando
        printf("Comando: W (cima)\tD (direita)\tS (baixo)\tA (esquerda)\n");
        printf("Sua vez! Digite um comando: ");
        scanf(" %c", &comando);

        //movimento jogador
        movimentoRealizado = 1;
        switch(comando){
            case 'w':
                py -= 1;
                if (py < 1){
                    py = 1;
                    movimentoRealizado = 0;
                }
                break;

            case 's':
                py += 1;
                if (py >= MAX_LINHA - 1){
                    py = MAX_LINHA - 2;
                    movimentoRealizado = 0;
                }
                break;

            case 'a':
                px -= 1;
                if (px < 1){
                    px = 1;
                    movimentoRealizado = 0;
                }
                break;

            case 'd':
                px += 1;
                if (px >= MAX_COLUNA - 1){
                    px = MAX_COLUNA - 2;
                    movimentoRealizado = 0;
                }
                break;

            default:
                movimentoRealizado = 0;
                printf("Comando invalido!\n");
                printf("Pressione uma tecla para continuar!\n");
                system("PAUSE");
        }
        if (px == ix && py == iy && item_presente) {
            item_presente = 0; // Item desaparece
            printf("\nVocê pegou o Tesouro!\n");
            ponto = ponto + 2;
         }
        else if (px == ax && py == ay && item_presente_a) {
            item_presente_a = 0;
            printf("\nGanhou 1 ponto\n");
            ponto ++;
        }
        else if (px == bx && py == by && item_presente_b) {
            item_presente_b = 0;
            printf("\nGanhou 1 ponto\n");
            ponto ++;
        }

        // movimento monstro
        if (movimentoRealizado == 1){
            int direcao = rand() % 4;
            switch(direcao){
                case 0:
                    my -= 1;
                    if (my < 1){
                        my = 1;
                    }
                    break;

                case 1:
                    my += 1;
                    if (my >= MAX_LINHA - 1){
                        my = MAX_LINHA - 2;
                    }
                    break;

                case 2:
                    mx -= 1;
                    if (mx < 1){
                        mx = 1;
                    }
                    break;

                case 3:
                    mx += 1;
                    if (mx >= MAX_COLUNA - 1){
                        mx = MAX_COLUNA - 2;
                    }
                    break;
            }

        }
        if (movimentoRealizado == 1){
            int direcao = rand() % 4;
            switch(direcao){
                case 0:
                    m2y -= 1;
                    if (m2y < 1){
                        m2y = 1;
                    }
                    break;

                case 1:
                    m2y += 1;
                    if (m2y >= MAX_LINHA - 1){
                        m2y = MAX_LINHA - 2;
                    }
                    break;

                case 2:
                    m2x -= 1;
                    if (m2x < 1){
                        m2x = 1;
                    }
                    break;

                case 3:
                    m2x += 1;
                    if (m2x >= MAX_COLUNA - 1){
                        m2x = MAX_COLUNA - 2;
                    }
                    break;
            }
        }

        // vitoria e derrota
        if (px == mx && py == my || px == m2x && py == m2y){
            printf("\n\nFim de jogo!\n");
            break;
        } else if (!item_presente && px == ox && py == oy) {
            printf("\n\nProxima fase!\n");
            system("PAUSE");

            // aumenta o nivel
            nivel++;

            // redefine as posições
            px = MAX_COLUNA / MAX_COLUNA;
            py = MAX_LINHA / MAX_LINHA;

            mx = (int)(MAX_COLUNA * 0.7);
            my = (int)(MAX_LINHA * 0.5);
            m2x = (int)(MAX_COLUNA * 0.3);
            m2y = (int)(MAX_LINHA * 0.5);

            ox = (MAX_COLUNA * 0.5);
            oy = (MAX_LINHA * 0.5);
            ix = (rand() % 32);
            iy = (rand() % 16);
            ax = (rand() % 32);
            ay = (rand() % 16);
            bx = (rand() % 32);
            by = (rand() % 16);
            // Reseta o item para estar presente novamente
            item_presente = 1;
            item_presente_a = 1;
            item_presente_b = 1;

        // saida sem item
        } else if (px == ox && py == oy) {
            printf("\nVoce precisa pegar o Tesouro antes de ir para a saida!\n");
            system("PAUSE");
} else if (nivel == 6){
    printf("Você ganhou!\n");
    printf("Sua pontuacao final eh: %i", ponto);
    break;
}

    }

    // reseta
    system("PAUSE");
    return 0;
}
