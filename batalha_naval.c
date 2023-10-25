#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define TAM 20

#define MAR '.'

#define ID_BOIA '0'
#define ID_AVIAO '1'
#define ID_SUBMARINO '2'
#define ID_ESPIAO1 '3'
#define ID_ESPIAO2 '4'
#define ID_PORTA_AVIOES '5'

char tabuleiro_inimigo[TAM][TAM];
char tabuleiro_player[TAM][TAM];

void inicializa_tabuleiro(char tab_inimigo[][TAM], char tab_player[][TAM])
{
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++) 
        {
            tab_inimigo[i][j] = MAR;
            tab_player[i][j] = MAR;
        }
}

void mostra_tabuleiro(char tabuleiro[][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%2c", tabuleiro[i][j]);
        }
        printf("\n");   
    }
}

bool verifica_posicao(char tabuleiro[][TAM], char id, int posicoes[][2])
{
    int linha, coluna;

    switch (id)
    {
    case '0':
        for (int i = 0; i < 1; i++)
        {
            linha = posicoes[i][0];
            coluna = posicoes[i][1];

            if ((linha < 0 || linha > TAM-1) || (coluna < 0 || coluna > TAM-1))

            if (tabuleiro[linha][coluna] != MAR) return false; 
        }
        return true;
        
        break;
    case '1':
        for (int i = 0; i < 4; i++)
        {
            linha = posicoes[i][0];
            coluna = posicoes[i][1];

            if((linha < 0 || linha > TAM-1) || (coluna < 0 || coluna > TAM-1)) return false;

            if (tabuleiro[linha][coluna] != MAR) return false; 
        }
        return true;        
        break;
    case '2':
        for (int i = 0; i < 4; i++)
        {
            linha = posicoes[i][0];
            coluna = posicoes[i][1];

            if((linha < 0 || linha > TAM-1) || (coluna < 0 || coluna > TAM-1)) return false;

            if (tabuleiro[linha][coluna] != MAR) return false; 
        }
        return true;
        break;
    case '3':
        for (int i = 0; i < 6; i++)
        {
            linha = posicoes[i][0];
            coluna = posicoes[i][1];

            if((linha < 0 || linha > TAM-1) || (coluna < 0 || coluna > TAM-1)) return false;

            if (tabuleiro[linha][coluna] != MAR) return false; 
        }
        return true;
        break;
    case '4':
        for (int i = 0; i < 6; i++)
        {
            linha = posicoes[i][0];
            coluna = posicoes[i][1];

            if((linha < 0 || linha > TAM-1) || (coluna < 0 || coluna > TAM-1)) return false;

            if (tabuleiro[linha][coluna] != MAR) return false; 
        }
        return true;
        break;
    case '5':
        for (int i = 0; i < 10; i++)
        {
            linha = posicoes[i][0];
            coluna = posicoes[i][1];

            if((linha < 0 || linha > TAM-1) || (coluna < 0 || coluna > TAM-1)) return false;

            if (tabuleiro[linha][coluna] != MAR) return false; 
        }
        return true;
        break;
    
    default:
        return false;
        break;
    }
}

void rotaciona_peca(int tamanho, int posicoes[][2], int linha, int coluna)
{
    int direcao = rand() % 4;
    for (int i = 0; i < tamanho; i++)
    {
        if (direcao == 0)
        {
            posicoes[i][0] = -(-linha + posicoes[i][0]);
            posicoes[i][1] = coluna + posicoes[i][1];
        }
        else if (direcao == 1)
        {
            posicoes[i][0] = linha + posicoes[i][0];
            posicoes[i][1] = coluna + posicoes[i][1];
        }
        else if (direcao == 2)
        {
            int cache = posicoes[i][0];
            posicoes[i][0] = coluna + posicoes[i][1];
            posicoes[i][1] = -(-linha + cache);
        }
        else if (direcao == 3)
        {
            int cache = posicoes[i][0];
            posicoes[i][0] = coluna + posicoes[i][1];
            posicoes[i][1] = linha + cache;
        }
    }
}

void posiciona_boia(char tabuleiro[][TAM], int quantidade, bool pos_automatico)
{   
    srand(time(NULL));

    int contador = 0, linha, coluna, posicoes[1][2];

    do
    {
        linha = rand() % 20;
        coluna = rand() % 20;

        posicoes[0][0] = linha;
        posicoes[0][1] = coluna;

        if (verifica_posicao(tabuleiro, ID_BOIA, posicoes))
        {
            tabuleiro[linha][coluna] = ID_BOIA;
        } else continue;

        contador++; 
    } while (contador < quantidade);
}

void posiciona_aviao(char tabuleiro[][TAM], int quantidade, bool pos_automatico)
{   
    srand(time(NULL));

    int contador = 0, linha, coluna, posicoes[4][2];

    do
    {
        linha = rand() % 19;
        coluna = rand() % 19;

        posicoes[0][0] = linha;
        posicoes[0][1] = coluna;
        posicoes[1][0] = linha;
        posicoes[1][1] = coluna-1;
        posicoes[2][0] = linha;
        posicoes[2][1] = coluna+1;
        posicoes[3][0] = linha-1;
        posicoes[3][1] = coluna;

        rotaciona_peca(4, posicoes, linha, coluna);
        if (verifica_posicao(tabuleiro, ID_AVIAO, posicoes))
        {
            for (int i = 0; i < 4; i++)
                tabuleiro[posicoes[i][0]][posicoes[i][1]] = ID_AVIAO;

        } else continue;

        contador++; 
    } while (contador < quantidade);
}

void posiciona_submarino(char tabuleiro[][TAM], int quantidade, bool pos_automatico)
{   
    srand(time(NULL));

    int contador = 0, linha, coluna, posicoes[4][2];

    do
    {
        linha = rand() % 19;
        coluna = rand() % 19;

        posicoes[0][0] = coluna;
        posicoes[0][1] = linha;
        posicoes[1][0] = coluna+1;
        posicoes[1][1] = linha;
        posicoes[2][0] = coluna+2;
        posicoes[2][1] = linha;
        posicoes[3][0] = coluna+3;
        posicoes[3][1] = linha;

        rotaciona_peca(4, posicoes, linha, coluna);
        if (verifica_posicao(tabuleiro, ID_SUBMARINO, posicoes))
        {
            for (int i = 0; i < 4; i++)
                tabuleiro[posicoes[i][0]][posicoes[i][1]] = ID_SUBMARINO;

        } else continue;

        contador++; 
    } while (contador < quantidade);
}

void posiciona_espiao1(char tabuleiro[][TAM], int quantidade, bool pos_automatico)
{   
    srand(time(NULL));

    int contador = 0, linha, coluna, posicoes[6][2];

    do
    {
        linha = rand() % 19;
        coluna = rand() % 19;

        posicoes[0][1] = linha;
        posicoes[0][0] = coluna;
        posicoes[1][1] = linha;
        posicoes[1][0] = coluna+1;
        posicoes[2][1] = linha;
        posicoes[2][0] = coluna+2;
        posicoes[3][1] = linha;
        posicoes[3][0] = coluna+3;
        posicoes[4][1] = linha+1;
        posicoes[4][0] = coluna;
        posicoes[5][1] = linha-1;
        posicoes[5][0] = coluna;
        

        rotaciona_peca(6, posicoes, linha, coluna);
        if (verifica_posicao(tabuleiro, ID_ESPIAO1, posicoes))
        {
            for (int i = 0; i < 6; i++)
                tabuleiro[posicoes[i][0]][posicoes[i][1]] = ID_ESPIAO1;

        } else continue;

        contador++; 
    } while (contador < quantidade);
}

void posiciona_espiao2(char tabuleiro[][TAM], int quantidade, bool pos_automatico)
{   
    srand(time(NULL));

    int contador = 0, linha, coluna, posicoes[6][2];

    do
    {
        linha = rand() % 19;
        coluna = rand() % 19;

        posicoes[0][1] = linha;
        posicoes[0][0] = coluna;
        posicoes[1][1] = linha;
        posicoes[1][0] = coluna+1;
        posicoes[2][1] = linha;
        posicoes[2][0] = coluna+2;
        posicoes[3][1] = linha;
        posicoes[3][0] = coluna+3;
        posicoes[4][1] = linha+1;
        posicoes[4][0] = coluna;
        posicoes[5][1] = linha-1;
        posicoes[5][0] = coluna;
        

        rotaciona_peca(6, posicoes, linha, coluna);
        if (verifica_posicao(tabuleiro, ID_ESPIAO2, posicoes))
        {
            for (int i = 0; i < 6; i++)
                tabuleiro[posicoes[i][0]][posicoes[i][1]] = ID_ESPIAO2;

        } else continue;

        contador++; 
    } while (contador < quantidade);
}

void posiciona_porta_avioes(char tabuleiro[][TAM], int quantidade, bool pos_automatico)
{   
    srand(time(NULL));

    int contador = 0, linha, coluna, posicoes[10][2];

    do
    {
        linha = rand() % 19;
        coluna = rand() % 19;

        posicoes[0][1] = linha;
        posicoes[0][0] = coluna;
        posicoes[1][1] = linha;
        posicoes[1][0] = coluna+1;
        posicoes[2][1] = linha;
        posicoes[2][0] = coluna+2;
        posicoes[3][1] = linha;
        posicoes[3][0] = coluna+3;
        posicoes[4][1] = linha;
        posicoes[4][0] = coluna+4;
        posicoes[5][1] = linha-1;
        posicoes[5][0] = coluna;
        posicoes[6][1] = linha-1;
        posicoes[6][0] = coluna+1;
        posicoes[7][1] = linha-1;
        posicoes[7][0] = coluna+2;
        posicoes[8][1] = linha-1;
        posicoes[8][0] = coluna+3;
        posicoes[9][1] = linha-1;
        posicoes[9][0] = coluna+4;
        

        rotaciona_peca(10, posicoes, linha, coluna);
        if (verifica_posicao(tabuleiro, ID_PORTA_AVIOES, posicoes))
        {
            for (int i = 0; i < 10; i++)
                tabuleiro[posicoes[i][0]][posicoes[i][1]] = ID_PORTA_AVIOES;

        } else continue;

        contador++; 
    } while (contador < quantidade);
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


int main()
{
    inicializa_tabuleiro(tabuleiro_inimigo, tabuleiro_player);

    posiciona_boia(tabuleiro_inimigo, 10, true);
    posiciona_aviao(tabuleiro_inimigo,  5, true);
    posiciona_submarino(tabuleiro_inimigo, 5, true);
    posiciona_espiao1(tabuleiro_inimigo, 4, true);
    posiciona_espiao2(tabuleiro_inimigo, 4, true);
    posiciona_porta_avioes(tabuleiro_inimigo, 2, true);

    mostra_tabuleiro(tabuleiro_inimigo);
    conta_pecas_tabuleiro(tabuleiro_inimigo);
    
    /* code */
    return 0;
}
