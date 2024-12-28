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
    } while ((*ptr_arraySize) < 1);

    *ptr_array = (float*) malloc((*ptr_arraySize) * sizeof(float));

    if (ptr_array == NULL)
    {
        printf("Memoria não alocada.\n\n");
        return 1;
    }
    
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

        if ((*ptr_arraySize) < 1)
        {
            printf("Numero demasiado pequeno\n\n");
        }
    } while ((*ptr_arraySize) < 1);

    new_ptr_array = (float*) realloc(*ptr_array, (*ptr_arraySize) * sizeof(float));

    if (new_ptr_array == NULL)
    {
        printf("Memoria não alocada.\n\n");
        return 1;
    }

    *ptr_array = new_ptr_array;

    return (**ptr_array, *ptr_arraySize);
}

float readFicheiro(float **ptr_array, int *ptr_arraySize) 
{
    FILE *fptr;
    char file_name[200];
    char r, formato;
    float *new_ptr_array;
    int i;

    printf("Qual é o ficheiro que usar? ");
    scanf("%s", file_name);

    fptr = fopen(file_name, "r");

    if (fptr == NULL)
    {
        printf("Ficheiro não aberto.\n");
        return 1;
    }

    fscanf( fptr, "%s %d", &formato, &*ptr_arraySize);

    if (formato != '#')
    {
        printf("Ficheiro com formato invalido.\n");
        return 1;
    }

    new_ptr_array = (float*) realloc(*ptr_array, (*ptr_arraySize) * sizeof(float));

    if (new_ptr_array == NULL)
    {
        printf("Memoria não alocada.\n\n");
        return 1;
    }

    for (i = 0; i < (*ptr_arraySize); i++)
    {
        fscanf(fptr, "%f", &(*ptr_array)[i]);
    }

    *ptr_array = new_ptr_array;

    fclose(fptr);

    return (**ptr_array, *ptr_arraySize);
}

void saveFicheiro()
{
    FILE *fptr;

}

void filtroValores(float *valores, int arraySize, float maximo, float minimo)
{
    if (arraySize == 0) 
    {
        printf("Nenhum valor a filtrar. Insira valores para prosseguir.\n");
        return;
    }

    printf("Insira o valor máximo: ");
    scanf("%f", &maximo);
    printf("Insira o valor mínimo: ");
    scanf("%f", &minimo);

    printf("Os valores entre %.2f e %.2f são:\n", minimo, maximo); // %.2f para max e mkin terem 2 casas décimais //
    for (int i = 0; i < arraySize; i++)
    {
        if (valores[i] >= minimo && valores[i] <= maximo) 
        {
            printf("Valor na posição %d: %.2f\n", i + 1, valores[i]);
        }
    }
}

void getPassaBaixo(float *valores, int arraySize) 
{
    if (arraySize == 0) 
    {
        printf("Nenhum valor a filtrar. Insira valores para prosseguir.\n");
        return;
    }

    int n_consegutivas;
    printf("Insira o valor de N (entre 2 e 100): ");
    scanf("%d", &n_consegutivas);

    if (n_consegutivas < 2 || n_consegutivas > 100)
    {
        printf("Valor de N inválido. O valor inserido tem de estar entre 2 e 100.\n");
        return;
    }

    float* n_filtrados = (float*)malloc(arraySize * sizeof(float));
    if (n_filtrados == NULL) 
    {
        printf("ERRO. Não foi possível alocar memória para os valores filtrados!\n");
        return;
    }

    for (int i = 0; i < arraySize; i++)
    {
        float soma = 0;
        int count = 0;

        if (i < n_consegutivas)
        {
            for (int k = 0; k <= i; k++) 
            {
                soma += valores[k];
            }
            n_filtrados[i] = soma / (i + 1);
        }
        else 
        {
            for (int k = i - n_consegutivas + 1; k <= i; k++) 
            {
                soma += valores[k];
            }
            n_filtrados[i] = soma / n_consegutivas;
        }
    }

     free(valores);
    valores = n_filtrados;
    printf("O Filtro passa-baixo foi aplicado :) \n");
}

int getIntegrador()
{

}

void getGrafico()
{

}

int main()
{
    setlocale(LC_ALL, "pt_PT.UTF-8");
    setlocale(LC_NUMERIC, "c");

    int i; // # para o case
    float *myLista = NULL; // array
    int arraySize;
 
    float media;
    float desvio;
    // char formato = '#';

    do
    {
        printf("1 - Inserir valores\n2 - Listar valores inseridos\n3 - Alterar um valor inserido\n4 - Calcular o valor médio\n5 - Calcular o desvio-padrão\n6 - Calcular a mediana\n7 - Alterar quantidade de valores\n8 - Ler valores de um ficheiro\n9 - Guadar valores num ficheiro\n10 - Filtrar valores num intervalo\n11 - Aplicar filtro Passa-Baixo\n12 - Calcular integrador\n13 - Visualização gráfica do ficheiro\n14 - Sair/Terminar\n\nEscolha uma das opções: "); // promt para o utilizador
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
                readFicheiro(&myLista, &arraySize);
                printf("\n\n");
                break;

            case 9:
                saveFicheiro();
                printf("\n\n");
                break;

            case 10:
                filtroValores(&arraySize, );
                printf("\n\n");
                break;

            case 11:
                getPassaBaixo();
                printf("\n\n");
                break;

            case 12:
                getIntegrador();
                printf("\n\n");
                break;

            case 13:
                getGrafico();
                printf("\n\n");
                break;

            case 14:
                break;
            
            default:
                printf("Opção inválida. Tente novamente.\n\n");
                break;
        }
   } while (i != 14);
   
    printf("FIM DO PROGRAMA!!");
}
