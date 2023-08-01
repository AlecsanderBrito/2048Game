#include "lib/header.h" // definicoes de teclas e variaveis

// variaveis globais
int matriz[TAMANHO + 1][TAMANHO + 1] = {0};
int pontuacao = 2048, pfinal = 0;

// controles
void controles(int *controladores) // controles
{
    if (controladores == CIMA)
        cima();
    if (controladores == BAIXO)
        baixo();
    if (controladores == DIREITA)
        direita();
    if (controladores == ESQUERDA)
        esquerda();

    pontuacao--;
    sorteador();
    display();
}

void baixo() // move a mesa para baixo
{
    int i, j;

    for (j = 0; j < TAMANHO; j++)
    {
        i = 2;
        while (1)
        {
            while (matriz[i][j] == 0)
            {
                if (i == -1)
                    break;
                i--;
            }

            if (i == -1)
                break;

            while (i < TAMANHO - 1 && (matriz[i + 1][j] == 0 || matriz[i][j] == matriz[i + 1][j]))
            {
                matriz[i + 1][j] += matriz[i][j];
                matriz[i][j] = 0;
                i++;
            }

            i--;
        }
    }
}

void cima() // move a mesa para cima
{
    int i, j;

    for (j = 0; j < TAMANHO; j++)
    {
        i = 1;

        while (1)
        {
            while (matriz[i][j] == 0)
            {
                if (i == TAMANHO)
                    break;

                i++;
            }

            if (i == TAMANHO)
                break;

            while (i > 0 && (matriz[i - 1][j] == 0 || matriz[i][j] == matriz[i - 1][j]))
            {
                matriz[i - 1][j] += matriz[i][j];
                matriz[i][j] = 0;
                i--;
            }

            i++;
        }
    }
}

void direita() // move a mesa para direita
{
    int i, j;

    for (i = 0; i < TAMANHO; i++)
    {
        j = 2;

        while (1)
        {
            while (matriz[i][j] == 0)
            {
                if (j == -1)
                    break;

                j--;
            }

            if (j == -1)
                break;

            while (j < TAMANHO - 1 && (matriz[i][j + 1] == 0 || matriz[i][j] == matriz[i][j + 1]))
            {
                matriz[i][j + 1] += matriz[i][j];
                matriz[i][j] = 0;
                j++;
            }

            j--;
        }
    }
}

void esquerda() // move a mesa para esquerda
{
    int i, j;

    for (i = 0; i < TAMANHO; i++)
    {
        j = 1;

        while (1)
        {

            while (matriz[i][j] == 0)
            {
                if (j == TAMANHO)
                    break;
                j++;
            }

            if (j == TAMANHO)
                break;

            while (j > 0 && (matriz[i][j - 1] == 0 || matriz[i][j] == matriz[i][j - 1]))
            {
                matriz[i][j - 1] += matriz[i][j];
                matriz[i][j] = 0;
                j--;
            }

            j++;
        }
    }
}

// parte logica
void sorteador() // calcula as areas de adicao
{
    int adicionar, sort1, sort2, i, j;

    srand(time(NULL)); // i
    sort1 = rand() % TAMANHO; // i

    srand(time(NULL)); // i
    sort2 = rand() % TAMANHO; // j

    if ((sort1 + sort2) % 2 == 0)
        adicionar = 2;
    else
        adicionar = 4;

    for (i = 0; i < sort1; i++)
    {
        for (j = sort2; j < TAMANHO; j++)
        {
            if (matriz[i][j] == 0)
            {
                matriz[i][j] = adicionar;
                return;
            }
        }
    }
}

void display() // criar area da mesa
{
    int i, j;

    system("cls");

    printf("\t\t\t2048\n");
    printf("PARA JOGAR USE AS TECLAS: CIMA, BAIXO, ESQUERDA, DIREITA\n\n");

    for (i = 0; i < TAMANHO; i++)
    {
        for (j = 0; j < TAMANHO; j++)
        {
            if (matriz[i][j] == 0)
                printf("      "); // SUBSTITUIR 0 POR ESPACO
            else
                printf(" %4d ", matriz[i][j]);
        }

        printf("\n\n");
    }
}

int contador() // parte logica, calcula o tamanho da matriz
{
    int temp = 0, i, j;

    for (i = 0; i < TAMANHO; i++)
    {
        for (j = 0; j < TAMANHO; j++)
        {
            if (matriz[i][j] == 2048)
                return (1);
            if (matriz[i][j] == 0)
                temp = 1;
        }
    }

    if (temp == 1)
    {
        pfinal = 0;
        return (-99);
    }

    else
    {
        if (pfinal == 1)
            return (0);

        pfinal = 1;
        return (-99);
    }
}

// principal
main()
{
    int crtlBruto;
    char controladores;
    int temp;

    display();

    controladores = BAIXO;

    while (1) //  ENCERRAR PROCESSO
    {
        controladores = getch();
        crtlBruto = controladores;

        controles(controladores);

        temp = contador();

        if (temp == 1)
        {
            printf("\nVOCE VENCEU :)");
            break;
        }

        if (temp == 0 || pontuacao < 0)
        {
            printf("\nVOCE PERDEU :(");
            break;
        }
    }
}
