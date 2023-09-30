#include<stdio.h>
#include <stdlib.h>
#include <time.h>


#define TAM 20
#define MAR ' '

char tabuleiro[TAM][TAM];

void gerar_tabuleiro()
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++) tabuleiro[i][j] = MAR;
    }
}

void mostra_tabuleiro(char tabuleiro[TAM][TAM]) 
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++) printf("%c ", tabuleiro[i][j]);
        printf("\n");
    }
}

/*
int verifica_tabuleiro(char tabuleiro[TAM][TAM], int x, int y, char id) 
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++){
            
        }
    }
}
*/

void inicializa_boia(char tabuleiro[TAM][TAM])
{
    int x, y, quantidade;
    char id;
    
    srand(time(NULL));
    quantidade = 10;
    id = '0';

    while (quantidade != 0)
    {
        x = rand() % 19;
        y = rand() % 19;

        if ((x>=0 && x<=19) && (y>=0 && y<= 19))
        {
            if (tabuleiro[x][y] == MAR) 
            {
                tabuleiro[x][y] = id;
            } else continue;
        } else continue;
        
        quantidade--;
    }
}

void inicializa_aviao(char tabuleiro[TAM][TAM])
{
    int x, y, quantidade, direcao;
    char id;

    srand(time(NULL));
    quantidade = 5;
    id = '1';

    while (quantidade != 0)
    {
        x = rand() % 19;
        y = rand() % 19;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && x<=19) && (y>=0 && y-1>=0 && y+1<=19))
        {
            //Direcao do posicionamento: Norte
            if (direcao == 1)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x][y-1] == MAR && tabuleiro[x][y+1] == MAR && tabuleiro[x-1][y] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x][y-1] = tabuleiro[x][y+1] = id;
                } else continue;
            } 
            //Direcao do posicionamento: Sul
            else if (direcao == 2)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x][y-1] == MAR && tabuleiro[x][y+1] == MAR && tabuleiro[x+1][y] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y-1] = tabuleiro[x][y+1] = tabuleiro[x+1][y] = id;
                } else continue;
            }
            //Direcao do posicionamento: Leste
            else if (direcao == 3)
            {
                if (tabuleiro[x][y] == MAR && tabuleiro[x-1][y] == MAR && tabuleiro[x+1][y] == MAR && tabuleiro[x][y+1] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x+1][y] = tabuleiro[x][y+1] = id;
                } else continue;
            }
            //Direcao Posicionamento: Oeste
            else {
                if (tabuleiro[x][y] == MAR && tabuleiro[x-1][y] == MAR && tabuleiro[x+1][y] == MAR && tabuleiro[x][y-1] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x+1][y] = tabuleiro[x][y-1] = id;
                } else continue;
            }
        }
        else continue;

        quantidade--;
    }
    
}

void inicializa_submarino(char tabuleiro[TAM][TAM])
{
    int x, y, quantidade, direcao;
    char id;

    srand(time(NULL));
    quantidade = 5;
    id = '2';

    while (quantidade != 0)
    {
        x = rand() % 19;
        y = rand() % 19;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && x-3>=0 && x+3>=19 && x<=19) && (y>=0 && y-3>=0 && y+3<=19))
        {
            //Direcao do posicionamento: Norte
            if (direcao == 1)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x-1][y] == MAR && tabuleiro[x-2][y-2] == MAR && tabuleiro[x-3][y] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x-2][y] = tabuleiro[x-3][y] = id;
                } else continue;
            } 
            //Direcao do posicionamento: Sul
            else if (direcao == 2)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x+1][y] == MAR && tabuleiro[x+2][y] == MAR && tabuleiro[x+3][y] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x+1][y] = tabuleiro[x+2][y] = tabuleiro[x+3][y] = id;
                } else continue;
            }
            //Direcao do posicionamento: Leste
            else if (direcao == 3)
            {
                if (tabuleiro[x][y] == MAR && tabuleiro[x][y+1] == MAR && tabuleiro[x][y+2] == MAR && tabuleiro[x][y+3] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y+1] = tabuleiro[x][y+2] = tabuleiro[x][y+3] = id;
                } else continue;
            }
            //Direcao Posicionamento: Oeste
            else {
                if (tabuleiro[x][y] == MAR && tabuleiro[x][y-1] == MAR && tabuleiro[x][y-2] == MAR && tabuleiro[x][y-3] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y-1] = tabuleiro[x][y-2] = tabuleiro[x][y-3] = id;
                } else continue;
            }
        }
        else continue;

        quantidade--;
    }
    
}

void inicializa_espiao1(char tabuleiro[TAM][TAM])
{
    int x, y, quantidade, direcao;
    char id;

    srand(time(NULL));
    quantidade = 4;
    id = '3';

    while (quantidade != 0)
    {
        x = rand() % 19;
        y = rand() % 19;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && x-3>=0 && x+3<=19) && (y>=0 && y-3>=0 && y+3<=19))
        {
            //Direcao do posicionamento: Norte
            if (direcao == 1)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x][y-1] == MAR && tabuleiro[x][y+1] == MAR && 
                tabuleiro[x-1][y] == MAR && tabuleiro[x-2][y] == MAR && tabuleiro[x-3][y] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y-1] = tabuleiro[x][y+1] = tabuleiro[x-1][y] = tabuleiro[x-2][y] = tabuleiro[x-3][y] = id;
                } 
                else continue;
            } 
            //Direcao do posicionamento: Sul
            else if (direcao == 2)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x][y-1] == MAR && tabuleiro[x][y+1] == MAR && 
                tabuleiro[x+1][y] == MAR && tabuleiro[x+2][y] == MAR && tabuleiro[x+3][y] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y-1] = tabuleiro[x][y+1] = tabuleiro[x+1][y] = tabuleiro[x+2][y] = tabuleiro[x+3][y] = id;
                } 
                else continue;
            }
            //Direcao do posicionamento: Leste
            else if (direcao == 3)
            {
                if (tabuleiro[x][y] == MAR && tabuleiro[x-1][y] == MAR && tabuleiro[x+1][y] == MAR && 
                tabuleiro[x][y+1] == MAR && tabuleiro[x][y+2] == MAR && tabuleiro[x][y+3] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x+1][y] = tabuleiro[x][y+1] = tabuleiro[x][y+2] = tabuleiro[x][y+3] = id;
                } 
                else continue;
            }
            //Direcao Posicionamento: Oeste
            else {
                if (tabuleiro[x][y] == MAR && tabuleiro[x-1][y] == MAR && tabuleiro[x+1][y] == MAR && 
                tabuleiro[x][y-1] == MAR && tabuleiro[x][y-2] == MAR && tabuleiro[x][y-3] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x+1][y] = tabuleiro[x][y-1] = tabuleiro[x][y-2] = tabuleiro[x][y-3] = id;
                }
                else continue;
            }
        }
        else continue;

        quantidade--;
    }
    
}

void inicializa_espiao2(char tabuleiro[TAM][TAM])
{
    int x, y, quantidade, direcao;
    char id;

    srand(time(NULL));
    quantidade = 4;
    id = '4';

    while (quantidade != 0)
    {
        x = rand() % 19;
        y = rand() % 19;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && x-3>=0 && x+3<=19) && (y>=0 && y-3>=0 && y+3<=19))
        {
            //Direcao do posicionamento: Norte
            if (direcao == 1)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x][y-1] == MAR && tabuleiro[x][y+1] == MAR && 
                tabuleiro[x-1][y] == MAR && tabuleiro[x-2][y] == MAR && tabuleiro[x-3][y] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y-1] = tabuleiro[x][y+1] = tabuleiro[x-1][y] = tabuleiro[x-2][y] = tabuleiro[x-3][y] = id;
                } 
                else continue;
            } 
            //Direcao do posicionamento: Sul
            else if (direcao == 2)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x][y-1] == MAR && tabuleiro[x][y+1] == MAR && 
                tabuleiro[x+1][y] == MAR && tabuleiro[x+2][y] == MAR && tabuleiro[x+3][y] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y-1] = tabuleiro[x][y+1] = tabuleiro[x+1][y] = tabuleiro[x+2][y] = tabuleiro[x+3][y] = id;
                } 
                else continue;
            }
            //Direcao do posicionamento: Leste
            else if (direcao == 3)
            {
                if (tabuleiro[x][y] == MAR && tabuleiro[x-1][y] == MAR && tabuleiro[x+1][y] == MAR && 
                tabuleiro[x][y+1] == MAR && tabuleiro[x][y+2] == MAR && tabuleiro[x][y+3] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x+1][y] = tabuleiro[x][y+1] = tabuleiro[x][y+2] = tabuleiro[x][y+3] = id;
                } 
                else continue;
            }
            //Direcao Posicionamento: Oeste
            else {
                if (tabuleiro[x][y] == MAR && tabuleiro[x-1][y] == MAR && tabuleiro[x+1][y] == MAR && 
                tabuleiro[x][y-1] == MAR && tabuleiro[x][y-2] == MAR && tabuleiro[x][y-3] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x+1][y] = tabuleiro[x][y-1] = tabuleiro[x][y-2] = tabuleiro[x][y-3] = id;
                }
                else continue;
            }
        }
        else continue;

        quantidade--;
    }
}

void inicializa_porta_avioes(char tabuleiro[TAM][TAM])
{
    int x, y, quantidade, direcao;
    char id;

    srand(time(NULL));
    quantidade = 2;
    id = '5';

    while (quantidade != 0)
    {
        x = rand() % 19;
        y = rand() % 19;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && (x-1>=0 && x+1<=19) && (x-4>=0 && x+4<=19)) && (y>=0 && (y-1>=0 && y+1<=19) && (y-4>=0 && y+4<=19)))
        {
            //Direcao do posicionamento: Norte
            if (direcao == 1)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x-1][y] == MAR && tabuleiro[x-2][y] == MAR && tabuleiro[x-3][y] == MAR && tabuleiro[x-4][y] == MAR && 
                tabuleiro[x][y-1] == MAR && tabuleiro[x-1][y-1] == MAR && tabuleiro[x-2][y-1] == MAR && tabuleiro[x-3][y-1] == MAR && tabuleiro[x-4][y-1] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x-1][y] = tabuleiro[x-2][y] = tabuleiro[x-3][y] = tabuleiro[x-4][y] = 
                    tabuleiro[x][y-1] = tabuleiro[x-1][y-1] = tabuleiro[x-2][y-1] = tabuleiro[x-3][y-1] = tabuleiro[x-4][y-1] = id;
                } 
                else continue;
            } 
            //Direcao do posicionamento: Sul
            else if (direcao == 2)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x+1][y] == MAR && tabuleiro[x+2][y] == MAR && tabuleiro[x+3][y] == MAR && tabuleiro[x+4][y] == MAR && 
                tabuleiro[x][y+1] == MAR && tabuleiro[x+1][y+1] == MAR && tabuleiro[x+2][y+1] == MAR && tabuleiro[x+3][y+1] == MAR && tabuleiro[x+4][y+1] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x+1][y] = tabuleiro[x+2][y] = tabuleiro[x+3][y] = tabuleiro[x+4][y] = 
                    tabuleiro[x][y+1] = tabuleiro[x+1][y+1] = tabuleiro[x+2][y+1] = tabuleiro[x+3][y+1] = tabuleiro[x+4][y+1] = id;
                } 
                else continue;
            }
            //Direcao do posicionamento: Leste
            else if (direcao == 3)
            {
                if(tabuleiro[x][y] == MAR && tabuleiro[x][y+1] == MAR && tabuleiro[x][y+2] == MAR && tabuleiro[x][y+3] == MAR && tabuleiro[x][y+4] == MAR && 
                tabuleiro[x-1][y] == MAR && tabuleiro[x-1][y+1] == MAR && tabuleiro[x-1][y+2] == MAR && tabuleiro[x-1][y+3] == MAR && tabuleiro[x-1][y+4] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y+1] = tabuleiro[x][y+2] = tabuleiro[x][y+3] = tabuleiro[x][y+4] = 
                    tabuleiro[x-1][y] = tabuleiro[x-1][y+1] = tabuleiro[x-1][y+2] = tabuleiro[x-1][y+3] = tabuleiro[x-1][y+4] = id;
                } 
                else continue;
            }
            //Direcao Posicionamento: Oeste
            else {
                if(tabuleiro[x][y] == MAR && tabuleiro[x][y-1] == MAR && tabuleiro[x][y-2] == MAR && tabuleiro[x][y-3] == MAR && tabuleiro[x][y-4] == MAR && 
                tabuleiro[x+1][y] == MAR && tabuleiro[x+1][y-1] == MAR && tabuleiro[x+1][y-2] == MAR && tabuleiro[x+1][y-3] == MAR && tabuleiro[x+1][y-4] == MAR)
                {
                    tabuleiro[x][y] = tabuleiro[x][y-1] = tabuleiro[x][y-2] = tabuleiro[x][y-3] = tabuleiro[x][y-4] = 
                    tabuleiro[x+1][y] = tabuleiro[x+1][y-1] = tabuleiro[x+1][y-2] = tabuleiro[x+1][y-3] = tabuleiro[x+1][y-4] = id;
                } 
                else continue;
            }
        }
        else continue;

        quantidade--;
    }
    
}

void conta_pecas_tabuleiro(char tabuleiro[TAM][TAM])
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

    printf("\n---------------------------------\n");
    printf("Boias: %d \n", boia);
    printf("Aviao: %d \n", aviao);
    printf("Submarino: %d \n", submarino);
    printf("Espiao 1: %d \n", espiao1);
    printf("Espiao 2: %d \n", espiao2);
    printf("P. Avioes: %d \n", p_avioes);
}

int main()
{
    srand(time(NULL));
    gerar_tabuleiro();

    inicializa_boia(tabuleiro);
    inicializa_aviao(tabuleiro);
    inicializa_submarino(tabuleiro);
    inicializa_espiao1(tabuleiro);
    inicializa_espiao2(tabuleiro);
    inicializa_porta_avioes(tabuleiro);

    mostra_tabuleiro(tabuleiro);    

    conta_pecas_tabuleiro(tabuleiro);
    
    return 0; 
}
