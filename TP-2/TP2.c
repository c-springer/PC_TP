#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int getLista(float **ptr_array, int *ptr_arraySize)
{
    int i;

    do
    {
        printf("Insira a quantidade de valores: ");
        scanf("%d", &*ptr_arraySize);

        if ((*ptr_arraySize) < 1)
        {
            printf("Numero demasiado pequeno\n\n");
        }

        *ptr_array = (float*) malloc((*ptr_arraySize) * sizeof(float));

        if (ptr_array == NULL)
        {
            printf("Memoria não alocada.\n\n");

        }
    } while ((*ptr_arraySize) < 1 || ptr_array == NULL);
    
    printf("Insira os valores:\n");
    for (i = 0; i < (*ptr_arraySize); i++)
    {
        scanf("%f", &(*ptr_array)[i]);
    }
    return 0;
}

int returnLista(float *ptr_array, int *ptr_arraySize)
{
    int i;     // posição na array
    int n = 0; // contador para fazer print da array
    char r;    // resposta do utilizador

    for (i = 0; i < (*ptr_arraySize); i++)
    {
        printf("%.2f\n", ptr_array[i]);
        if (n < 20) n++;

        if (n == 20)
        {
            printf("\n");
            printf("Quer continuar? y ou n\n");
            scanf("%*c");
            
            scanf("%c", &r);
            printf("\n");
            
            if (r == 'y')
            {
                n = 0;
            }

            else if (r == 'n') break;
            else printf("Resposta invalida\n\n");
        }
    }
    return 0;
} 

int changeLista(float *ptr_array, int *ptr_arraySize)
{
    int i;
    int novoValor;

    printf("Qual é a posição do número que quer alterar? ");
    scanf("%d", &i);
    
    if (i < 0 || i > (*ptr_arraySize)) printf("Posição inválida\n\n");
    else
    {
        printf("O valor que quer mudar é: %.2f\n", ptr_array[i]);
        printf("\n");

        printf("Qual é o novo valor? ");
        scanf("%d", &novoValor);

        ptr_array[i] = novoValor;

        printf("O valor foi alterado para: %d\n", novoValor);
    }
    return 0;
}

float getMedia(float *ptr_array, int *ptr_arraySize, float media)
{
    float soma = 0;
    int i;
    
    for (i = 0; i < (*ptr_arraySize); i++)
    {
        soma = soma + ptr_array[i];
    }

    media = (float) soma / (*ptr_arraySize);
    printf("A média dos %d elementos desta Array é: %.2f\n", *ptr_arraySize, media);

    return media;
}

int getDesvio(float *ptr_array, int *ptr_arraySize, float media)
{
    int i;
    float somatorio = 0;
    float desvio;

    if (media == 0)
    {
        getMedia(ptr_array, ptr_arraySize, media);
        printf("\n");
    }

    for (i = 0; i < (*ptr_arraySize); i++)
    {
        somatorio += ((double) (ptr_array[i] - media, 2));
    }
    desvio = sqrt(somatorio / (*ptr_arraySize));
    printf("O desvio-padrão é: %.4f\n", desvio);

    return desvio;
}

int getMediana(float *ptr_array, int *ptr_arraySize)
{
    int i;
    float mediana;
    int temp, ntrocas;

    do
    {
        ntrocas = 0;
        for (i = 0; i < ((*ptr_arraySize) - 1); i++)
        {
            if (ptr_array[i] > ptr_array[i + 1])
            {
                temp = ptr_array[i];
                ptr_array[i] = ptr_array[i + 1];
                ptr_array[i + 1] = temp;
                ntrocas++;
            }
        }
    } while (ntrocas > 0);

    if (((*ptr_arraySize) % 2) == 0) // se arraySize par
    {
        mediana = (ptr_array[(*ptr_arraySize) / 2] + ptr_array[(*ptr_arraySize) / 2 - 1])/ 2.0;
    }

    if (((*ptr_arraySize) % 2) != 0)
    {
        mediana = ptr_array[(*ptr_arraySize) / 2];
    }
    
    printf("A mediana é: %.2f\n", mediana);

    return 0;
}

int changeSize(float **ptr_array, int *ptr_arraySize)
{
    float *new_ptr_array;

    do
    {
        printf("Insira a nova quantidade de valores: ");
        scanf("%d", &*ptr_arraySize);

        new_ptr_array = (float*) realloc(*ptr_array, (*ptr_arraySize) * sizeof(float));

        if (new_ptr_array == NULL)
        {
            printf("Memoria não alocada.\n\n");

        }
    } while (new_ptr_array == NULL);

    *ptr_array = new_ptr_array;


    return (**ptr_array, *ptr_arraySize);
}

int main()
{
    setlocale(LC_ALL, "pt_PT.UTF-8");
    setlocale(LC_NUMERIC, "c");

    FILE *fptr;

    int i; // # para o case
    float *myLista = NULL; // array

    int arraySize;
    // int *ptr_arraySize;
    // ptr_arraySize = &arraySize;
 
    float media;
    float desvio;

    do
    {
        printf("1 - Inserir valores\n2 - Listar valores inseridos\n3 - Alterar um valor inserido\n4 - Calcular o valor médio\n5 - Calcular o desvio-padrão\n6 - Calcular a mediana\n7 - Alterar quantidade de valores\n8 - Sair/Terminar\n\nEscolha uma das opções: "); // promt para o utilizador
        scanf("%d", &i);
        
        switch (i)
        {
            case 1:
                getLista(&myLista, &arraySize);
                printf("\n\n");
                break;

            case 2:
                returnLista(myLista, &arraySize); 
                printf("\n\n");
                break;

            case 3:
                changeLista(myLista, &arraySize);
                printf("\n\n");
                break;

            case 4:
                getMedia(myLista, &arraySize, media);
                printf("\n\n");
                break;

            case 5:
                getDesvio(myLista, &arraySize, media);
                printf("\n\n");
                break;

            case 6:
                getMediana(myLista, &arraySize);
                printf("\n\n");
                break;

            case 7:
                changeSize(&myLista, &arraySize);
                printf("\n\n");
                break;

            case 8:
                break;
            
            default:
                printf("Opção inválida. Tente novamente.\n\n");
                break;
        }
   } while (i != 8);
   
    printf("FIM DO PROGRAMA!!");
}
