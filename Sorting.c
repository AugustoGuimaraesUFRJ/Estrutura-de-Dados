#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubble_sort (int vetor[], int n);
void merge_sort(int vetor[], int esquerda, int direita);
void merge(int a[], int esquerda, int meio, int direita);
void quick_sort(int *a, int inicio, int fim);
int particionar(int *a, int inicio, int final);

int main(int argc, char *argv[ ]){
    int tamanho_da_lista = 10000, posicao = 0, tam = 0, numero = 0;
    int *array = (int *)malloc(tamanho_da_lista*sizeof(int));

    while(scanf("%d", &numero) != EOF){
    	if(posicao < tamanho_da_lista){
    		array[posicao] = numero;
    	}
    	else{
    		tamanho_da_lista = 2*tamanho_da_lista;
    		array = (int *)realloc(array, tamanho_da_lista*sizeof(int));

    		if(array != NULL) array[posicao] = numero;
    		else break; //Não há mais memória para alocar.
    	}
    	posicao++;
    }

    tam = posicao;

    if(argc==1) {
        bubble_sort(array, tam);
    }
    else if(strcmp(argv[1], "-m") == 0) {
        merge_sort(array, 0, tam);
    }
    else if(strcmp(argv[1], "-q") == 0) {
        quick_sort(array, 0, tam-1);
    }

    // exibindo o resultado
    for(int i = 0; i < tam; i++)
    {
        printf("%d \n", array[i]);
    }
     return 0;
}

void merge(int a[], int esquerda, int meio, int direita) {
    int i, j, k, tam;
    i = esquerda;
    j = meio;
    k = 0;
    tam = direita - esquerda;
    int *temp = malloc(tam*sizeof(int));

    while(i < meio && j < direita) {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i < meio)
        temp[k++] = a[i++];

    while(j < direita)
        temp[k++] = a[j++];

    for (i = esquerda; i < direita; ++i)
        a[i] = temp[i-esquerda];

    free(temp);
}

void merge_sort(int vetor[], int esquerda, int direita)
{
    int meio;
    if (esquerda < direita -1) {
        meio = (esquerda + direita) / 2;

        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio, direita);

        merge(vetor, esquerda, meio, direita);
    }
}

void quick_sort(int *a, int inicio, int fim) {
    int pivo;

    if(fim > inicio) {
        pivo = particionar(a, inicio, fim);
        quick_sort(a, inicio, pivo-1);
        quick_sort(a, pivo+1, fim);
    }
}

int particionar(int *a, int inicio, int final) {
    int esquerda, direita, pivo, aux;
    esquerda = inicio;
    direita = final;
    pivo = a[inicio];

    while(esquerda < direita) {
        while(a[esquerda] <= pivo)
            esquerda++;
        while(a[direita] > pivo)
            direita--;
        if(esquerda < direita) {
            aux = a[esquerda];
            a[esquerda] = a[direita];
            a[direita] = aux;
        }
    }

    a[inicio] = a[direita];
    a[direita] = pivo;
    return direita;
}

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - k; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
