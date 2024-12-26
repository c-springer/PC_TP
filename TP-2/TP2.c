#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// TODO - mudar a array para ter size dinamico
int getLista(float *ptr_array, int *ptr_arraySize)
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

        ptr_array = (float*)malloc((*ptr_arraySize) * sizeof(float));

        if (ptr_array == NULL)
        {
            printf("Memoria não alocada.\n\n");

        }
    } while ((*ptr_arraySize) < 1 || ptr_array == NULL);
    
    printf("Insira os valores:\n");
    for (i = 0; i < (*ptr_arraySize); i++)
    {
        scanf("%f", &ptr_array[i]);
    }
    return (ptr_array, *ptr_arraySize);
}

int returnLista(float array[1000], int *ptr_arraySize)
{
    int i;     // posição na array
    int n = 0; // contador para fazer print da array
    char r;    // resposta do utilizador

    for (i = 0; i < (*ptr_arraySize); i++)
    {
        printf("%.2f\n", array[i]);
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

int changeLista(float array[1000], int *ptr_arraySize)
{
    int i;
    int novoValor;

    printf("Qual é a posição do número que quer alterar? ");
    scanf("%d", &i);
    
    if (i < 0 || i > (*ptr_arraySize)) printf("Posição inválida\n\n");
    else
    {
        printf("O valor que quer mudar é: %.2f\n", array[i]);
        printf("\n");

        printf("Qual é o novo valor? ");
        scanf("%d", &novoValor);

        array[i] = novoValor;

        printf("O valor foi alterado para: %d\n", novoValor);
    }
    return 0;
}

float getMedia(float array[1000], int *ptr_arraySize, float media)
{
    float soma = 0;
    int i;
    
    for (i = 0; i < (*ptr_arraySize); i++)
    {
        soma = soma + array[i];
    }

    media = (float) soma / (*ptr_arraySize);
    printf("A média dos %d elementos desta Array é: %.2f\n", *ptr_arraySize, media);

    return media;
}

int getDesvio(float array[1000], int *ptr_arraySize, float media)
{
    int i;
    float somatorio = 0;
    float desvio;

    if (media == 0)
    {
        getMedia(array, ptr_arraySize, media);
        printf("\n");
    }

    for (i = 0; i < (*ptr_arraySize); i++)
    {
        somatorio += ((double) (array[i] - media, 2));
    }
    desvio = sqrt(somatorio / (*ptr_arraySize));
    printf("O desvio-padrão é: %.4f\n", desvio);

    return desvio;
}

int getMediana(float array[1000], int *ptr_arraySize)
{
    int i;
    float mediana;
    int temp, ntrocas;

    // bubble sort
    do // for (j = 0; j < (*ptr_arraySize); j++)
    {
        ntrocas = 0;
        for (i = 0; i < ((*ptr_arraySize) - 1); i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                ntrocas++;
            }
        }
    } while (ntrocas > 0);

    if (((*ptr_arraySize) % 2) == 0) // se arraySize par
    {
        mediana = (array[(*ptr_arraySize) / 2] + array[(*ptr_arraySize) / 2 - 1])/ 2.0;
    }

    if (((*ptr_arraySize) % 2) != 0)
    {
        mediana = array[(*ptr_arraySize) / 2];
    }
    
    printf("A mediana é: %.2f\n", mediana);

    return 0;
}

changeSize(float *ptr_array, int *ptr_arraySize)
{
    //int n = ptr_arraySize;

    do
    {
        printf("INsira a nova quantidade de valores: ");
        scanf("%d", &*ptr_arraySize);

        ptr_array = (float*) realloc(ptr_array, *ptr_arraySize * sizeof(float));

        if (ptr_array == NULL)
        {
            printf("Memoria não alocada.\n\n");

        }
    } while (ptr_array == NULL);

}

int main()
{
    setlocale(LC_ALL, "pt_PT.UTF-8");
    setlocale(LC_NUMERIC, "c");

    int i; // # para o case
    float *myLista; // array

    int arraySize;
    int *ptr_arraySize;
    ptr_arraySize = &arraySize;
 
    float media;
    float desvio;

    do
    {
        printf("1 - Inserir valores\n2 - Listar valores inseridos\n3 - Alterar um valor inserido\n4 - Calcular o valor médio\n5 - Calcular o desvio-padrão\n6 - Calcular a mediana\n7 - Sair/Terminar\n\nEscolha uma das opções: "); // promt para o utilizador
        scanf("%d", &i);
        
        switch (i)
        {
            case 1:
                getLista(myLista, ptr_arraySize);
                printf("\n\n");
                break;

            case 2:
                returnLista(myLista, ptr_arraySize); 
                printf("\n\n");
                break;

            case 3:
                changeLista(myLista, ptr_arraySize);
                printf("\n\n");
                break;

            case 4:
                getMedia(myLista, ptr_arraySize, media);
                printf("\n\n");
                break;

            case 5:
                getDesvio(myLista, ptr_arraySize, media);
                printf("\n\n");
                break;

            case 6:
                getMediana(myLista, ptr_arraySize);
                printf("\n\n");
                break;

            case 7:
                changeSize(myLista, ptr_arraySize);
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
