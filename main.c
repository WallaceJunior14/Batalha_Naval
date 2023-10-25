#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 20
#define MAR '.'

char tab_inimigo[TAM][TAM];

void gerar_tabuleiro(char tabuleiro[][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++) tabuleiro[i][j] = MAR;
    }
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

void posiciona_boia(char tabuleiro[][TAM], int quantidade, int x, int y)
{  
    char id = '0';
    
    srand(time(NULL));

    while (quantidade != 0)
    {
        x = x>=0 ? x : rand() % TAM;
        y = y>=0 ? y : rand() % TAM;

        //VERIFICA LIMITES
        if ((x>=0 && x<=(TAM-1)) && (y>=0 && y<= (TAM-1)))
        {
            if (tabuleiro[x][y] == MAR) 
            {
                tabuleiro[x][y] = id;
                x = y = -1;
            } else continue;
        } else continue;
        
        quantidade--;
    }
}

void posiciona_aviao(char tabuleiro[][TAM], int quantidade)
{
    int x, y, direcao;
    char id = '1';

    srand(time(NULL));

    while (quantidade != 0)
    {
        x = rand() % TAM;
        y = rand() % TAM;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && x<=(TAM-1)) && (y>=0 && y-1>=0 && y+1<=(TAM-1)))
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

void posiciona_submarino(char tabuleiro[][TAM], int quantidade)
{
    int x, y, direcao;
    char id = '2';

    srand(time(NULL));

    while (quantidade != 0)
    {
        x = rand() % TAM;
        y = rand() % TAM;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && x-3>=0 && x+3>=(TAM-1) && x<=(TAM-1)) && (y>=0 && y-3>=0 && y+3<=(TAM-1)))
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

void posiciona_espiao1(char tabuleiro[][TAM], int quantidade)
{
    int x, y, direcao;
    char id = '3';

    srand(time(NULL));

    while (quantidade != 0)
    {
        x = rand() % TAM;
        y = rand() % TAM;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && x-3>=0 && x+3<=(TAM-1)) && (y>=0 && y-3>=0 && y+3<=(TAM-1)))
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

void posiciona_espiao2(char tabuleiro[][TAM], int quantidade)
{
    int x, y, direcao;
    char id = '4';

    srand(time(NULL));

    while (quantidade != 0)
    {
        x = rand() % TAM;
        y = rand() % TAM;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && x-3>=0 && x+3<=(TAM-1)) && (y>=0 && y-3>=0 && y+3<=(TAM-1)))
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

void posiciona_porta_avioes(char tabuleiro[][TAM], int quantidade)
{
    int x, y, direcao;
    char id = '5';

    srand(time(NULL));

    while (quantidade != 0)
    {
        x = rand() % TAM;
        y = rand() % TAM;
        direcao = 1 + rand() % 4;

        //Limites
        if((x>=0 && (x-1>=0 && x+1<=(TAM-1)) && (x-4>=0 && x+4<=(TAM-1))) && (y>=0 && (y-1>=0 && y+1<=(TAM-1)) && (y-4>=0 && y+4<=(TAM-1))))
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
    printf("Aviao: %d \n", aviao);
    printf("Submarino: %d \n", submarino);
    printf("Espiao 1: %d \n", espiao1);
    printf("Espiao 2: %d \n", espiao2);
    printf("P. Avioes: %d \n", p_avioes);
}

int main()
{
    srand(time(NULL));
    gerar_tabuleiro(tab_inimigo);

    posiciona_boia(tab_inimigo, 10, -1, -1);
    posiciona_aviao(tab_inimigo, 5);
    posiciona_submarino(tab_inimigo, 5);
    posiciona_espiao1(tab_inimigo, 4);
    posiciona_espiao2(tab_inimigo, 4);
    posiciona_porta_avioes(tab_inimigo, 2);

    mostra_tabuleiro(tab_inimigo);    

    //conta_pecas_tabuleiro(tab_inimigo);
    
    return 0; 
}