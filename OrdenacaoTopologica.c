#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Lista encadeada
struct nos{
 int conteudo;
 struct nos *prox;
};
typedef struct nos no;

//Com cabeça
void insereNaLista (int x, no *lista){
 no *nova;
 nova = malloc (sizeof (no));
 nova->conteudo = x;
 nova->prox = lista->prox;
 lista->prox = nova;}

void removeLista(no *lista){
 no *temporaria;
 if(lista != NULL){
   temporaria = lista->prox;
   while(temporaria != NULL){
     lista->prox = temporaria->prox;
     free(temporaria);
     temporaria = lista->prox;}
   free(lista);}
}

void insereNaFila (int x, no * fila){
 if(fila != NULL){
   no *nova = malloc(sizeof(no));
   nova->conteudo = x;
   nova->prox = fila->prox;
   fila->prox = nova;}
}
// Recebe fila, devolve o conteudo do primeiro e tira ele da fila. Devolve -1 quando vazia
int proximoDaFila (no * fila){
 int valorDeDevolucao;
 no *anterior;
 no *percorre;
 anterior = fila;
 percorre = fila->prox;
 while(percorre != NULL){
   if(percorre->prox == NULL){
     anterior->prox = NULL;
     valorDeDevolucao = percorre->conteudo;
     free(percorre);
     return valorDeDevolucao;}
   anterior = percorre;
   percorre = percorre->prox;}
 return -1;
}
//Com cabeça
void inicializaLista(no ** ptrLista) {
 *ptrLista = malloc(sizeof(no));
 (*ptrLista)->prox = NULL;
 (*ptrLista)->conteudo = -1;}

int main(){
 int a;
 int i;
 no *sucessores[50]; // Vetor com as listas
 int antecessores[50];  // Vetor que guarda em [i] o número de antecessores de i
 no *fila; //Fila para guardar os vertices sem predecessor antes de imprimir

 // Variaveis de leitura
 char nota[50]="Precisa apertar barra";
 char vertices[50];

 int vertice;
 int numero, sucessor;
 char letra[50];

 no *varreSucessores; //Percorre as listas
 int valorDoProxDaFila;

 // Leitura  dos dados e preenchimento do vetor de listas
 fgets (vertices,50,stdin); //Para não ter problema de misturar scanfs e fgets, usei apenas fgets e fiz a conversao para inteiro
 vertice=(intptr_t)vertices[0]-48;

 for(i = 1; i < (vertice+1); i++){
   inicializaLista(&(sucessores[i]));
   antecessores[i] = 0;}

 inicializaLista(&fila);

 // Montagem das listas
 for(i = 1; i < (vertice + 1); i++){
   numero=i;
   fgets (letra,50,stdin);
   if((int)strlen(letra)==1){
        sucessor=((intptr_t)letra)-48;
        if((intptr_t) letra!=32){
            printf("%s",nota);}}
    else{
        for(a=0;a<(int)strlen(letra);a++){
            if((intptr_t)letra[a]!=32){ //Ignora espaço em branco
                    sucessor=((intptr_t)letra[a])-48;
                    insereNaLista(sucessor, sucessores[numero]);
                    antecessores[sucessor]++;}}
    }
}
 for(i = 1; i < (vertice+1); i++){
   if(antecessores[i] == 0)
     insereNaFila(i, fila);}

 valorDoProxDaFila = proximoDaFila(fila);
 while(valorDoProxDaFila != -1){ //Até ficar vazia
   varreSucessores = sucessores[valorDoProxDaFila]->prox;
   printf("%d ", (valorDoProxDaFila));
   while(varreSucessores != NULL){
     antecessores[varreSucessores->conteudo]--;
     if(antecessores[varreSucessores->conteudo] == 0)
       insereNaFila(varreSucessores->conteudo, fila);
     varreSucessores = varreSucessores->prox;}
   valorDoProxDaFila = proximoDaFila(fila);}
 removeLista(fila);
 return 0;
}

/*
3 2
2

1

3 1 2*/

/*
5 7
2 3
4 5
2 5

4
1 3 2 5 4*/

/*
5 6
2 3

2 4
5
2

1 3 4 5 2*/
