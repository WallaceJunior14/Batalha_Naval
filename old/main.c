#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define TAM 20

#define MAR '.'

#define ID_BOIA '0'
#define ID_AVIAO '1'
#define ID_SUBMARINO '2'
#define ID_ESPIAO1 '3'
#define ID_ESPIAO2 '4'
#define ID_PORTA_AVIOES '5'

struct Peca_Principal
{
    int linha;
    int coluna; 
    char direcao;
};

void inicializa_tabuleiro(char tabuleiro[][TAM])
{
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++) 
            tabuleiro[i][j] = MAR;
}

void mostra_tabuleiro(char tabuleiro[][TAM])
{
    for (int i=0; i<1; i++) 
    {
        printf("   ");
        for (int j = 0; j < TAM; j++) printf("%2d ", j);
        printf("\n\n");
    }   

    for (int i = 0; i < TAM; i++)
    {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++)
        {
            printf("%2c ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

bool verifica_posicao(char tabuleiro[][TAM], int tamanho, int posicoes[][2])
{
    int linha, coluna;

    for (int i = 0; i < tamanho; i++)
    {
        linha = posicoes[i][0];
        coluna = posicoes[i][1];

        if((linha < 0 || linha > TAM-1) || (coluna < 0 || coluna > TAM-1)) return false;

        if (tabuleiro[linha][coluna] != MAR) return false; 
    }
    return true;
}

void cria_pecas(int id, int posicoes[][2], int linha, int coluna, char direcao)
{
    switch (id)
    {
    case '1':
        if (direcao == 'C'|| direcao == 'c')
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna-1;
            posicoes[2][0] = linha;
            posicoes[2][1] = coluna+1;
            posicoes[3][0] = linha-1;
            posicoes[3][1] = coluna;
        } else if (direcao == 'B'|| direcao == 'b')
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna-1;
            posicoes[2][0] = linha;
            posicoes[2][1] = coluna+1;
            posicoes[3][0] = linha+1;
            posicoes[3][1] = coluna;
        } else if (direcao == 'D'|| direcao == 'd')
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha-1;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha+1;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna+1;
        } else if(direcao == 'E'|| direcao == 'E')
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha-1;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha+1;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna-1;
        }
        break;
    case '2':
        if (direcao == 'C'|| direcao == 'c') //cima
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha-1;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha-2;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha-3;
            posicoes[3][1] = coluna;
        } else if (direcao == 'B'|| direcao == 'b') //baixo
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha+1;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha+2;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha+3;
            posicoes[3][1] = coluna;
        } else if (direcao == 'D'|| direcao == 'd') //direita
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna+1;
            posicoes[2][0] = linha;
            posicoes[2][1] = coluna+2;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna+3;
        } else if (direcao == 'E'|| direcao == 'e')//esquerda
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna-1;
            posicoes[2][0] = linha;
            posicoes[2][1] = coluna-2;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna-3;
        }
        break;
    case '3':
        if (direcao == 'C'|| direcao == 'c') // cima
        {
            posicoes[0][0] = linha-3;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha-2;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha-1;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna;
            posicoes[4][0] = linha;
            posicoes[4][1] = coluna+1;
            posicoes[5][0] = linha;
            posicoes[5][1] = coluna-1;
        } else if (direcao == 'B'|| direcao == 'b') //baixo
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna-1;
            posicoes[2][0] = linha;
            posicoes[2][1] = coluna+1;
            posicoes[3][0] = linha+1;
            posicoes[3][1] = coluna;
            posicoes[4][0] = linha+2;
            posicoes[4][1] = coluna;
            posicoes[5][0] = linha+3;
            posicoes[5][1] = coluna;
        } else if (direcao == 'D'|| direcao == 'd') //direita
        {
            posicoes[0][0] = linha-1;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha+1;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna+1;
            posicoes[4][0] = linha;
            posicoes[4][1] = coluna+2;
            posicoes[5][0] = linha;
            posicoes[5][1] = coluna+3;
        } else if (direcao == 'E'|| direcao == 'e') //esquerda
        {
            posicoes[0][0] = linha-1;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha+1;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna-1;
            posicoes[4][0] = linha;
            posicoes[4][1] = coluna-2;
            posicoes[5][0] = linha;
            posicoes[5][1] = coluna-3;
        }
        break;
    case '5':
        if (direcao == 'C'|| direcao == 'c') //cima
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha-1;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha-2;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha-3;
            posicoes[3][1] = coluna;
            posicoes[4][0] = linha-4;
            posicoes[4][1] = coluna;
            posicoes[5][0] = linha;
            posicoes[5][1] = coluna+1;
            posicoes[6][0] = linha-1;
            posicoes[6][1] = coluna+1;
            posicoes[7][0] = linha-2;
            posicoes[7][1] = coluna+1;
            posicoes[8][0] = linha-3;
            posicoes[8][1] = coluna+1;
            posicoes[9][0] = linha-4;
            posicoes[9][1] = coluna+1;
        } else if (direcao == 'B'|| direcao == 'b') //baixo
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha+1;
            posicoes[1][1] = coluna;
            posicoes[2][0] = linha+2;
            posicoes[2][1] = coluna;
            posicoes[3][0] = linha+3;
            posicoes[3][1] = coluna;
            posicoes[4][0] = linha+4;
            posicoes[4][1] = coluna;
            posicoes[5][0] = linha;
            posicoes[5][1] = coluna+1;
            posicoes[6][0] = linha+1;
            posicoes[6][1] = coluna+1;
            posicoes[7][0] = linha+2;
            posicoes[7][1] = coluna+1;
            posicoes[8][0] = linha+3;
            posicoes[8][1] = coluna+1;
            posicoes[9][0] = linha+4;
            posicoes[9][1] = coluna+1;
        } else if (direcao == 'D'|| direcao == 'd') //direita
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna+1;
            posicoes[2][0] = linha;
            posicoes[2][1] = coluna+2;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna+3;
            posicoes[4][0] = linha;
            posicoes[4][1] = coluna+4;
            posicoes[5][0] = linha-1;
            posicoes[5][1] = coluna;
            posicoes[6][0] = linha-1;
            posicoes[6][1] = coluna+1;
            posicoes[7][0] = linha-1;
            posicoes[7][1] = coluna+2;
            posicoes[8][0] = linha-1;
            posicoes[8][1] = coluna+3;
            posicoes[9][0] = linha-1;
            posicoes[9][1] = coluna+4;
        } else if(direcao == 'E'|| direcao == 'e') //esquerda
        {
            posicoes[0][0] = linha;
            posicoes[0][1] = coluna;
            posicoes[1][0] = linha;
            posicoes[1][1] = coluna-1;
            posicoes[2][0] = linha;
            posicoes[2][1] = coluna-2;
            posicoes[3][0] = linha;
            posicoes[3][1] = coluna-3;
            posicoes[4][0] = linha;
            posicoes[4][1] = coluna-4;
            posicoes[5][0] = linha-1;
            posicoes[5][1] = coluna;
            posicoes[6][0] = linha-1;
            posicoes[6][1] = coluna-1;
            posicoes[7][0] = linha-1;
            posicoes[7][1] = coluna-2;
            posicoes[8][0] = linha-1;
            posicoes[8][1] = coluna-3;
            posicoes[9][0] = linha-1;
            posicoes[9][1] = coluna-4;
        }
        break;
    default:
        break;
    }
}

void salva_posicoes(char *local_arquivo, int linha, int coluna, char orientacao, char id)
{
    FILE *arquivo = fopen(local_arquivo, "a+");

    if (arquivo != NULL)
    {
        fprintf(arquivo, "%d %d %c %c\n", linha, coluna, orientacao, id);
    } else 
    {
        printf("Nao foi possivel abrir o arquivo: %s", local_arquivo);
    }
    
    fclose(arquivo);
}

char gera_direcao_randomico()
{
    srand(time(NULL));

    int posicao = rand() % 4;
    char direcao[4] = {'C', 'B', 'D', 'E'};

    return direcao[posicao];
}

struct Peca_Principal solicita_posicao_direaco(bool pega_direcao)
{
    struct Peca_Principal peca; 
    char confirmacao;

    printf("\n-------------------------------------------\n");

    fflush(stdin);
    printf("Informe a Linha: ");
    scanf("%d", &peca.linha);

    printf("Informe a Coluna: ");
    scanf("%d", &peca.coluna);

    fflush(stdin);
    if (pega_direcao){
        printf("Informe a direcao (C, B, D, E): ");
        scanf("%c", &peca.direcao);
    }

    fflush(stdin);
    printf("voce confirma estas posicoes [s/n]? ");
    scanf("%c", &confirmacao);

    printf("-------------------------------------------\n");

    if (confirmacao == 's' || confirmacao == 'S' ) return peca;
    else solicita_posicao_direaco(pega_direcao);
}

void posiciona_boia(char tabuleiro[][TAM], int quantidade, bool posicionamento_automatico, char *local_arquivo)
{   
    srand(time(NULL));

    int contador = 0, parte_pecas[1][2];
    struct Peca_Principal peca;

    if (posicionamento_automatico)
    {
        do
        {
            peca.linha = rand() % 20;
            peca.coluna = rand() % 20;

            parte_pecas[0][0] = peca.linha;
            parte_pecas[0][1] = peca.coluna;
            
            if (verifica_posicao(tabuleiro, 1, parte_pecas))
            {
                tabuleiro[peca.linha][peca.coluna] = ID_BOIA;
                salva_posicoes(local_arquivo, peca.linha, peca.coluna, '-', ID_BOIA);
            } else continue;

            contador++; 
        } while (contador < quantidade);
    } else
    {
        do
        {   
            peca = solicita_posicao_direaco(false);

            parte_pecas[0][0] = peca.linha;
            parte_pecas[0][1] = peca.coluna;
            
            if (verifica_posicao(tabuleiro, 1, parte_pecas))
            {
                tabuleiro[peca.linha][peca.coluna] = ID_BOIA;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, '-', ID_BOIA);

                mostra_tabuleiro(tabuleiro);
            } else continue;

            contador++; 
        } while (contador < quantidade);
    }
    
}

void posiciona_aviao(char tabuleiro[][TAM], int quantidade, bool posicionamento_automatico, char *local_arquivo)
{   
    srand(time(NULL));

    int contador = 0, parte_pecas[4][2];
    struct Peca_Principal peca;

    if (posicionamento_automatico)
    {
        do
        {
            peca.linha = rand() % 19;
            peca.coluna = rand() % 19;
            peca.direcao = gera_direcao_randomico();

            cria_pecas(ID_AVIAO, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 4, parte_pecas))
            {
                for (int i = 0; i < 4; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_AVIAO;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_AVIAO);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    } else
    {
        do
        {
            mostra_tabuleiro(tabuleiro);

            peca = solicita_posicao_direaco(true);

            
            cria_pecas(ID_AVIAO, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 4, parte_pecas))
            {
                for (int i = 0; i < 4; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_AVIAO;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_AVIAO);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    }
}

void posiciona_submarino(char tabuleiro[][TAM], int quantidade, bool posicionamento_automatico, char *local_arquivo)
{   
    srand(time(NULL));

    int contador = 0, parte_pecas[4][2];
    struct Peca_Principal peca;

    if (posicionamento_automatico)
    {
        do
        {
            peca.linha = rand() % 19;
            peca.coluna = rand() % 19;
            peca.direcao = gera_direcao_randomico();

            cria_pecas(ID_SUBMARINO, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 4, parte_pecas))
            {
                for (int i = 0; i < 4; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_SUBMARINO;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_SUBMARINO);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    } else
    {
        do
        {
            mostra_tabuleiro(tabuleiro);

            peca = solicita_posicao_direaco(true);

            
            cria_pecas(ID_SUBMARINO, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 4, parte_pecas))
            {
                for (int i = 0; i < 4; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_SUBMARINO;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_SUBMARINO);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    }
}

void posiciona_espiao1(char tabuleiro[][TAM], int quantidade, bool posicionamento_automatico, char *local_arquivo)
{   
    srand(time(NULL));

    int contador = 0, parte_pecas[6][2];
    struct Peca_Principal peca;

    if (posicionamento_automatico)
    {
        do
        {
            peca.linha = rand() % 19;
            peca.coluna = rand() % 19;
            peca.direcao = gera_direcao_randomico();

            cria_pecas(ID_ESPIAO1, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 6, parte_pecas))
            {
                for (int i = 0; i < 6; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_ESPIAO1;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_ESPIAO1);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    } else
    {
        do
        {
            mostra_tabuleiro(tabuleiro);

            peca = solicita_posicao_direaco(true);

            
            cria_pecas(ID_ESPIAO1, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 6, parte_pecas))
            {
                for (int i = 0; i < 6; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_ESPIAO1;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_ESPIAO1);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    }
}

void posiciona_espiao2(char tabuleiro[][TAM], int quantidade, bool posicionamento_automatico, char *local_arquivo)
{   
    srand(time(NULL));

    int contador = 0, parte_pecas[6][2];
    struct Peca_Principal peca;

    if (posicionamento_automatico)
    {
        do
        {
            peca.linha = rand() % 19;
            peca.coluna = rand() % 19;
            peca.direcao = gera_direcao_randomico();

            cria_pecas(ID_ESPIAO1, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 6, parte_pecas))
            {
                for (int i = 0; i < 6; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_ESPIAO2;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_ESPIAO2);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    } else
    {
        do
        {
            mostra_tabuleiro(tabuleiro);

            peca = solicita_posicao_direaco(true);
            
            cria_pecas(ID_ESPIAO1, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 6, parte_pecas))
            {
                for (int i = 0; i < 6; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_ESPIAO2;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_ESPIAO2);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    }
}

void posiciona_porta_avioes(char tabuleiro[][TAM], int quantidade, bool posicionamento_automatico, char *local_arquivo)
{   
    srand(time(NULL));

    int contador = 0, parte_pecas[10][2];
    struct Peca_Principal peca;

    if (posicionamento_automatico)
    {
        do
        {
            peca.linha = rand() % 19;
            peca.coluna = rand() % 19;
            peca.direcao = gera_direcao_randomico();

            cria_pecas(ID_PORTA_AVIOES, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 10, parte_pecas))
            {
                for (int i = 0; i < 10; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_PORTA_AVIOES;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_PORTA_AVIOES);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    } else
    {
        do
        {
            mostra_tabuleiro(tabuleiro);

            peca = solicita_posicao_direaco(true);
            
            cria_pecas(ID_PORTA_AVIOES, parte_pecas, peca.linha, peca.coluna, peca.direcao);

            if (verifica_posicao(tabuleiro, 10, parte_pecas))
            {
                for (int i = 0; i < 10; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = ID_PORTA_AVIOES;

                salva_posicoes(local_arquivo, peca.linha, peca.coluna, peca.direcao, ID_PORTA_AVIOES);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    }
}

void conta_pecas_tabuleiro(char tabuleiro[][TAM])
{
    int boia, aviao, submarino, espiao1, espiao2, p_avioes;
    boia=aviao=submarino=espiao1=espiao2=p_avioes=0;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (tabuleiro[i][j] == '0') boia++;
            if (tabuleiro[i][j] == '1') aviao++;
            if (tabuleiro[i][j] == '2') submarino++;
            if (tabuleiro[i][j] == '3') espiao1++;
            if (tabuleiro[i][j] == '4') espiao2++;
            if (tabuleiro[i][j] == '5') p_avioes++;
        }
    }

    printf("\n--------------------------------------------\n");
    printf("Boias: %d \n", boia);
    printf("Aviao: %d \n", aviao/4);
    printf("Submarino: %d \n", submarino/4);
    printf("Espiao 1: %d \n", espiao1/6);
    printf("Espiao 2: %d \n", espiao2/6);
    printf("P. Avioes: %d \n", p_avioes/10);
}

void inicializa_inimigo(char tabuleiro[][TAM])
{
    char *arquivo_de_salvamento = "../DB/MATRIZ_INIMIGO.txt";

    inicializa_tabuleiro(tabuleiro);
    posiciona_boia(tabuleiro, 10, true, arquivo_de_salvamento);
    posiciona_aviao(tabuleiro,  5, true, arquivo_de_salvamento);
    posiciona_submarino(tabuleiro, 5, true, arquivo_de_salvamento);
    posiciona_espiao1(tabuleiro, 4, true, arquivo_de_salvamento);
    posiciona_espiao2(tabuleiro, 4, true, arquivo_de_salvamento);
    posiciona_porta_avioes(tabuleiro, 2, true, arquivo_de_salvamento);
    
    //mostra_tabuleiro(tabuleiro);
}

void inicializa_player(char tabuleiro[][TAM])
{
    char *arquivo_de_salvamento = "../DB/MATRIZ_PLAYER.txt";

    printf("\n-------------------PLAYER------------------\n\n");
    inicializa_tabuleiro(tabuleiro);
    posiciona_boia(tabuleiro, 10, true, arquivo_de_salvamento);
    posiciona_aviao(tabuleiro,  5, true, arquivo_de_salvamento);
    posiciona_submarino(tabuleiro, 5, true, arquivo_de_salvamento);
    posiciona_espiao1(tabuleiro, 4, true, arquivo_de_salvamento);
    posiciona_espiao2(tabuleiro, 4, true, arquivo_de_salvamento);
    posiciona_porta_avioes(tabuleiro, 2, false, arquivo_de_salvamento);

    mostra_tabuleiro(tabuleiro);
}


void menu_inicial(char tabuleiro_inimigo[][TAM], char tabuleiro_player[][TAM])
{
    int opcao_menu_inicial;

    printf("\n============================================\n");
    printf("||              BATALHA NAVAL             ||\n");
    printf("============================================\n\n");

    printf("-- MENU --\n");
    printf("1) Novo Jogo\n2) Continuar...\n3) Sair\n");
    scanf("%d", &opcao_menu_inicial);

    switch (opcao_menu_inicial)
    {
    case 1:
        inicializa_inimigo(tabuleiro_inimigo);
        inicializa_player(tabuleiro_player);
        break;
    
    default:
        printf("__Mensagem__\n");
        printf("Erro: Opcao Invalida!\n");
        menu_inicial(tabuleiro_inimigo, tabuleiro_player);
        break;
    }
}

int main()
{
    char tabuleiro_inimigo[TAM][TAM];
    char tabuleiro_player[TAM][TAM];

    menu_inicial(tabuleiro_inimigo, tabuleiro_inimigo);

    return 0;
}