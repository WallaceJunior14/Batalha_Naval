#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define TAM 20

#define MAR '.'
#define TIRO_NA_AGUA '#'

#define ID_BOIA '0'
#define ID_AVIAO '1'
#define ID_SUBMARINO '2'
#define ID_ESPIAO1 '3'
#define ID_ESPIAO2 '4'
#define ID_PORTA_AVIOES '5'

#define QTD_BOIA 10
#define QTD_AVIAO 5
#define QTD_SUBMARINO 5
#define QTD_ESPIAO1 4
#define QTD_ESPIAO2 4
#define QTD_PORTA_AVIOES 2

struct Peca
{
    int linha;
    int coluna; 
    char direcao;
    char id;
};

bool TIRO_ALEATORIO = true;
struct Peca peca_temp_IA;
int qtd_chances_IA;

void limpa_tela()
{
    char comando[10];

    #ifdef __linux__
        strcpy(comando, "clear");
        system(comando);
    #elif _WIN32
        strcpy(comando, "cls");
        system(comando);
    #endif
}

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

void cria_posicoes_pecas(char id, int posicoes[][2], struct Peca peca)
{
    int linha = peca.linha, coluna = peca.coluna; 
    char direcao = peca.direcao;

    switch (id)
    {
    case '0':
        posicoes[0][0] = linha;
        posicoes[0][1] = coluna;
        break;
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
    case '4':
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
    
    case 'T':
        posicoes[0][0] = linha-1;
        posicoes[0][1] = coluna;
        posicoes[1][0] = linha+1;
        posicoes[1][1] = coluna;
        posicoes[2][0] = linha;
        posicoes[2][1] = coluna-1;
        posicoes[3][0] = linha;
        posicoes[3][1] = coluna+1;

        posicoes[4][0] = linha-1;
        posicoes[4][1] = coluna+1;
        posicoes[5][0] = linha-1;
        posicoes[5][1] = coluna-1;
        posicoes[6][0] = linha+1;
        posicoes[6][1] = coluna+1;
        posicoes[7][0] = linha+1;
        posicoes[7][1] = coluna-1;
        break;
    default:
        break;
    }
}

int informa_qtd_por_peca(char id)
{
    if(id == '0') return 1;
    if(id == '1') return 4;
    if(id == '2') return 4;
    if(id == '3' || id == '4') return 6;
    if(id == '5') return 10;
    else return 0;
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

void salva_posicoes_iniciais(char *local_arquivo, struct Peca peca)
{
    FILE *arquivo = fopen(local_arquivo, "a+");

    if (arquivo != NULL)
    {
        fprintf(arquivo, "%d %d %c %c\n", peca.linha, peca.coluna, peca.direcao, peca.id);
    } else 
    {
        printf("Nao foi possivel abrir o arquivo: %s", local_arquivo);
    }
    
    fclose(arquivo);
}

bool salva_posicoes_ataque(char *local_arquivo, struct Peca peca)
{
    FILE *arquivo = fopen(local_arquivo, "a+");

    if (arquivo != NULL)
    {
        fprintf(arquivo, "%d %d %c\n", peca.linha, peca.coluna, peca.id);
    } else 
    {
        printf("Nao foi possivel abrir o arquivo: %s", local_arquivo);
        return false;
    }
    
    fclose(arquivo);
    return true;
}

bool carrega_posicoes_iniciais(char *local_arquivo, char tabuleiro[][TAM])
{
    struct Peca peca;

    FILE *arquivo = fopen(local_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo: %s", local_arquivo);
        return false;
    }
    
    inicializa_tabuleiro(tabuleiro);

    while (fscanf(arquivo, "%d%d%s%s", &peca.linha, &peca.coluna, &peca.direcao, &peca.id) != EOF)
    {
        int qtd_por_peca = informa_qtd_por_peca(peca.id);
        int parte_pecas[qtd_por_peca][2];

        fflush(stdin);

        cria_posicoes_pecas(peca.id, parte_pecas, peca);

        for (int i = 0; i < qtd_por_peca; i++)
            tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = peca.id;
        
    }

    fclose(arquivo);
    return true;
}

bool carrega_posicoes_jogadas(char *local_arquivo, char tabuleiro[][TAM])
{
    struct Peca peca;

    inicializa_tabuleiro(tabuleiro);

    FILE *arquivo = fopen(local_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo: %s", local_arquivo);
        return false;
    }

    while (fscanf(arquivo, "%d%d%s", &peca.linha, &peca.coluna, &peca.id) != EOF)
    {
        fflush(stdin);

        tabuleiro[peca.linha][peca.coluna] = peca.id;
    }

    fclose(arquivo);
    return true;
}

char gera_direcao_randomico()
{
    srand(time(NULL));

    int posicao = rand() % 4;
    char direcao[4] = {'C', 'B', 'D', 'E'};

    return direcao[posicao];
}

struct Peca solicita_posicao_direaco(bool pega_direcao)
{
    struct Peca peca; 
    char confirmacao;

    printf("\n-------------------------------------------\n");

    fflush(stdin);
    printf("Informe a Linha: ");
    scanf("%d", &peca.linha);

    printf("Informe a Coluna: ");
    scanf("%d", &peca.coluna);

    fflush(stdin);
    if (pega_direcao){
        printf("Informe a direcao (-, C, B, D, E): ");
        scanf("%c", &peca.direcao);
    }

    fflush(stdin);
    printf("voce confirma estas posicoes [s/n]? ");
    scanf("%c", &confirmacao);

    printf("-------------------------------------------\n");

    if (confirmacao == 's' || confirmacao == 'S' ) return peca;
    else solicita_posicao_direaco(pega_direcao);
}

void posiciona_peca(char tabuleiro[][TAM], char id, int quantidade, int qtd_posicoes_peca, bool posicionamento_automatico, char *local_arquivo)
{   
    srand(time(NULL));

    int contador = 0, parte_pecas[qtd_posicoes_peca][2];
    struct Peca peca;

    if (posicionamento_automatico)
    {
        do
        {
            peca.linha = rand() % 19;
            peca.coluna = rand() % 19;
            peca.direcao = id=='0' ? '-': gera_direcao_randomico();
            peca.id = id;

            cria_posicoes_pecas(id, parte_pecas, peca);

            if (verifica_posicao(tabuleiro, qtd_posicoes_peca, parte_pecas))
            {
                for (int i = 0; i < qtd_posicoes_peca; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = id;

                salva_posicoes_iniciais(local_arquivo, peca);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    } else
    {
        printf("\n----------------------------\n");
        printf("Peca a ser posicionada: %c", id);
        printf("\n----------------------------\n");
        do
        {
            mostra_tabuleiro(tabuleiro);

            peca = solicita_posicao_direaco(true);
            peca.id = id;

            cria_posicoes_pecas(id, parte_pecas, peca);

            if (verifica_posicao(tabuleiro, qtd_posicoes_peca, parte_pecas))
            {
                for (int i = 0; i < qtd_posicoes_peca; i++)
                    tabuleiro[parte_pecas[i][0]][parte_pecas[i][1]] = id;

                salva_posicoes_iniciais(local_arquivo, peca);

            } else continue;

            contador++; 
        } while (contador < quantidade);
    }
}

void inicializa_player(char tabuleiro[][TAM], bool posicionamento_automatico, char *local_salvamento)
{
    printf("\n-------------------PLAYER------------------\n\n");
    inicializa_tabuleiro(tabuleiro);
    posiciona_peca(tabuleiro, ID_BOIA, QTD_BOIA, 1, posicionamento_automatico, local_salvamento);
    posiciona_peca(tabuleiro, ID_AVIAO, QTD_AVIAO, 4, posicionamento_automatico, local_salvamento);
    posiciona_peca(tabuleiro, ID_SUBMARINO, QTD_SUBMARINO, 4, posicionamento_automatico, local_salvamento);
    posiciona_peca(tabuleiro, ID_ESPIAO1, QTD_ESPIAO1, 6, posicionamento_automatico, local_salvamento);
    posiciona_peca(tabuleiro, ID_ESPIAO2, QTD_ESPIAO2, 6, posicionamento_automatico, local_salvamento);
    posiciona_peca(tabuleiro, ID_PORTA_AVIOES, QTD_PORTA_AVIOES, 10, posicionamento_automatico, local_salvamento);
}

char verifica_ataque(bool jogador, char tabuleiro_real[][TAM], char tabuleiro_sombra[][TAM], struct Peca peca)
{
    if (tabuleiro_sombra[peca.linha][peca.coluna] != MAR )
    {
        if (jogador) printf("\nPosicao ja jogada. Informe outra posicao!\n");
        return ' ';
    } else 
    {
        return tabuleiro_real[peca.linha][peca.coluna] == MAR ? TIRO_NA_AGUA : tabuleiro_real[peca.linha][peca.coluna];
    }
}

bool ataque(bool jogador, char tabuleiro_real[][TAM], char tabuleiro_sombra[][TAM])
{
    int posicoes_ataque_IA[7][2], posicoes_temp[7], cont = 0, posicao;
    struct Peca peca;

    srand(time(NULL));

    if (jogador)
    {
        // ALGORITIMO DE ATAQUE DO JOGADOR

        mostra_tabuleiro(tabuleiro_sombra);

        printf("\n--------------------");
        printf("\n-> Linha: ");
        scanf("%d", &peca.linha);
        printf("\n-> Coluna: ");
        scanf("%d", &peca.coluna);
        printf("\n--------------------\n");

        peca.id = verifica_ataque(true, tabuleiro_real, tabuleiro_sombra, peca);

        if (peca.id == ' ')
        {
            return ataque(true, tabuleiro_real, tabuleiro_sombra);
        }

        tabuleiro_sombra[peca.linha][peca.coluna] = peca.id;

        salva_posicoes_ataque("./ATAQUES_JOGADOR.TXT", peca);

        mostra_tabuleiro(tabuleiro_sombra);
    } else
    {
        // ALGORITIMO DE ATAQUE DA IA
        
        if(TIRO_ALEATORIO) 
        {
            peca.linha = rand() % 19;
            peca.coluna = rand() % 19;
            peca.id = verifica_ataque(false, tabuleiro_real, tabuleiro_sombra, peca);

            if (peca.id == ' ') {
                return ataque(false, tabuleiro_real, tabuleiro_sombra);
            } else if (peca.id != '#' && peca.id != '0')
            {
                peca_temp_IA = peca;
                TIRO_ALEATORIO = false;
                qtd_chances_IA = 7;
            }

            tabuleiro_sombra[peca.linha][peca.coluna] = peca.id;

            salva_posicoes_ataque("./ATAQUES_INIMIGO.TXT", peca);
            
            mostra_tabuleiro(tabuleiro_sombra);
        } else 
        {
            if (qtd_chances_IA <=0)
            {
                TIRO_ALEATORIO = true;
                qtd_chances_IA = 7;
                return ataque(false, tabuleiro_real, tabuleiro_sombra);
            } else
            {
                cria_posicoes_pecas('T', posicoes_ataque_IA, peca_temp_IA );

                do
                {
                    posicao = rand() % 7;

                    for (int i = 0; i < 7; i++)
                    {
                        if (posicoes_temp[i] == posicao) posicao = rand() % 7;
                        else 
                        {
                            posicoes_temp[cont] = posicao;
                            break;
                        }
                    }    
                    
                    peca.linha = posicoes_ataque_IA[posicao][0];
                    peca.coluna = posicoes_ataque_IA[posicao][1];

                    printf("l: %d, c: %d\n", peca.linha, peca.coluna);
                    
                    peca.id = verifica_ataque(false, tabuleiro_real, tabuleiro_sombra, peca);
                    printf("id: %c\n", peca.id);
                    cont++;
                } while (peca.id == ' ');
                

                if (peca.id != '#')
                {
                    peca_temp_IA = peca;
                    TIRO_ALEATORIO = false;
                    qtd_chances_IA = 7;
                }

                tabuleiro_sombra[peca.linha][peca.coluna] = peca.id;

                salva_posicoes_ataque("./ATAQUES_INIMIGO.TXT", peca);
                
                
                mostra_tabuleiro(tabuleiro_sombra);
            }
        }

    }
}

int verifica_pontuacao(char tabuleiro[][TAM])
{
    int contador = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if(tabuleiro[i][j] != MAR && tabuleiro[i][j] != TIRO_NA_AGUA) contador++; 
        }
        
    }
    return contador;
}

void anuncia_vencedor(bool jogador)
{
    if (jogador)
    {
        printf("\n==============================================\n");
        printf("||                JOGADOR VENCEU             ||\n");
        printf("==============================================\n\n");
        exit(0);
    } else
    {
        printf("\n==============================================\n");
        printf("||                  IA VENCEU                ||\n");
        printf("==============================================\n\n");
        exit(0);
    }
    
    
}

void menu_batalha(char tabuleiro_IA[][TAM],char tab_sombra_IA[][TAM], char tabuleiro_jogador[][TAM], char tab_sombra_jogador[][TAM])
{
    int opcoes_menu_guerra, pontos_jogador, pontos_IA;

    pontos_IA = verifica_pontuacao(tab_sombra_jogador);
    pontos_jogador = verifica_pontuacao(tab_sombra_IA);

    printf("\n==============================================\n");
    printf("||               MENU DE GUERRA             ||\n");
    printf("==============================================\n\n");


    if (pontos_IA == 30) anuncia_vencedor(false);
    else if(pontos_jogador == 30) anuncia_vencedor(true);
    else{
        printf("Pontos Jogador: %d\n", pontos_jogador);
        printf("Pontos IA: %d\n", pontos_IA);
    }


    printf("-- MENU --\n");
    printf("1) Atacar\n2) Sair\n");
    scanf("%d", &opcoes_menu_guerra);

    switch (opcoes_menu_guerra)
    {
    case 1:
        printf("\n================ VEZ DO JOGADOR ================\n");
        ataque(true, tabuleiro_IA, tab_sombra_IA); // vez do jogador
        printf("\n================ VEZ DA IA ================\n");
        ataque(false, tabuleiro_jogador, tab_sombra_jogador); // vez da IA

        menu_batalha(tabuleiro_IA, tab_sombra_IA, tabuleiro_jogador, tab_sombra_jogador);
        break;
    case 2:
        menu_inicial(tabuleiro_IA, tabuleiro_jogador);
        break;
    
    default:
        printf("__Mensagem__\n");
        printf("Erro: Opcao Invalida!\n");
        menu_batalha(tabuleiro_IA, tab_sombra_IA, tabuleiro_jogador, tab_sombra_jogador);
        break;
    }
}

void menu_inicial(char tabuleiro_IA[][TAM], char tabuleiro_jogador[][TAM])
{
    int opcao_menu_inicial;
    char tab_sombra_IA[TAM][TAM], tab_sombra_jogador[TAM][TAM];

    limpa_tela();

    printf("\n============================================\n");
    printf("||              BATALHA NAVAL             ||\n");
    printf("============================================\n\n");

    printf("-- MENU --\n");
    printf("1) Novo Jogo\n2) Continuar...\n3) Sair\n");
    scanf("%d", &opcao_menu_inicial);

    switch (opcao_menu_inicial)
    {
    case 1:
        inicializa_player(tabuleiro_IA, true, "./MATRIZ_INIMIGO.TXT");
        inicializa_player(tabuleiro_jogador, true, "./MATRIZ_JOGADOR.TXT");

        menu_batalha(tabuleiro_IA, tab_sombra_IA, tabuleiro_jogador, tab_sombra_jogador);
        break;
    case 2:
        carrega_posicoes_iniciais("./MATRIZ_INIMIGO.TXT", tabuleiro_IA);
        carrega_posicoes_iniciais("./MATRIZ_JOGADOR.TXT", tabuleiro_jogador);

        carrega_posicoes_jogadas("./ATAQUES_INIMIGO.TXT", tab_sombra_jogador);
        carrega_posicoes_jogadas("./ATAQUES_JOGADOR.TXT", tab_sombra_IA);

        menu_batalha(tabuleiro_IA, tab_sombra_IA, tabuleiro_jogador, tab_sombra_jogador);
        break;
    case 3:

        break;
    default:
        printf("__Mensagem__\n");
        printf("Erro: Opcao Invalida!\n");
        menu_inicial(tabuleiro_IA, tabuleiro_jogador);
        break;
    }
}

int main()
{
    char tabuleiro_IA[TAM][TAM];
    char tabuleiro_jogador[TAM][TAM];

    menu_inicial(tabuleiro_IA, tabuleiro_jogador);

    return 0;
}