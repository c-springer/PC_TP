#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
int getLista(float array[1000], int* ptr_arraySize){
    int i;

    do{
        printf("Insira a quantidade de valores: ");
        scanf("%d", &*ptr_arraySize);

        if ((*ptr_arraySize)>1000) {
            printf("Numero demasiado grande\n\n");
        }

        else if ((*ptr_arraySize)<1) {
            printf("Numero demasiado pequeno\n\n");
        }

    } while ((*ptr_arraySize)>1000 || (*ptr_arraySize)<1);
    
    printf("Insira os valores:\n");
    for(i=0; i < (*ptr_arraySize); i++) {
        scanf("%f", &array[i]);
    }
    return(array, *ptr_arraySize);
}
*/

int returnLista(float array[1000], int *ptr_arraySize /*tamanho da array*/) {
    int i; //posição na array
    int n=1; //contador para fazer print da array
    char r;

    for(i=0; i<=*ptr_arraySize; i++){ ///////////rever
        printf("%f\n", array[i]);
        if(n<20) n++;

        else if(n==20){
            printf("Quer continuar? Y ou N\n");
            scanf("%c", &r);
            if(r == 'Y'){
                n=0;
            }
            else if(r =='N') break;
        }
    }
    
} 

int changeLista() {
    
} 

int getMedia() {
    
} 

int getDesvio() {
    
} 

int getMediana() {
    
}

int main() {
    setlocale(LC_ALL, "pt_PT.UTF-8");
    setlocale(LC_NUMERIC, "c");

    int i; // # para o case
    /*
    float myLista[1000]; //array
    int arraySize;
    int *ptr_arraySize = &arraySize;
    */

    float myLista[21] = {1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
    int arraySize = 21;
    int *ptr_arraySize = &arraySize;
    ptr_arraySize = &arraySize;


    do {
        printf("1 – Inserir valores\n2 – Listar valores inseridos\n3 – Alterar um valor inserido\n4 – Calcular o valor médio\n5 – Calcular o desvio-padrão\n6 – Calcular a mediana\n7 – Sair/Terminar\n\nEscolha uma das opções: "); //promt pro utilizador
        scanf("%d", &i); //# para o case
        switch(i){
            case 1:
                //getLista(myLista, ptr_arraySize); ////////////////////////////////
                printf("\n");
                break;
            case 2:
                returnLista(myLista, ptr_arraySize); 
                printf("\n");
                break;
            case 3:
                changeLista();
                printf("\n");
                break;
            case 4:
                getMedia();
                printf("\n");
                break;
            case 5:
                getDesvio();
                printf("\n");
                break;
            case 6:
                getMediana();
                printf("\n");
                break;
            case 7:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
   } while(i!=7);
    printf("FIM DO PROGRAMA!!");
}
