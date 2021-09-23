#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Cores {
  RED,
  BLACK
};

struct no {
  int chave, cor;
  struct no *link[2];
};

struct no *raiz = NULL;

// Criando Arvore
struct no *construcao(int chave) {
  struct no *novo;
  novo = (struct no *)malloc(sizeof(struct no));
  novo->chave = chave;
  novo->cor = RED;
  novo->link[0] = novo->link[1] = NULL;
  return novo;
}

int contador=0;
void insercao(int chave) {
  contador++;
  struct no *stack[100], *ptr, *novo, *xPtr, *yPtr;
  int dir[100], ht = 0, i;
  ptr = raiz;
  if (!raiz) {
    raiz = construcao(chave);
    return;
  }
  stack[ht] = raiz;
  dir[ht++] = 0;
  while (ptr != NULL) {
    if (ptr->chave == chave) {
      printf("Sem repetição!!\n");
      return;
    }
    i = (chave - ptr->chave) > 0 ? 1 : 0;
    stack[ht] = ptr;
    ptr = ptr->link[i];
    dir[ht++] = i;
  }
  stack[ht - 1]->link[i] = novo = construcao(chave);
  while ((ht >= 3) && (stack[ht - 1]->cor == RED)) {
    if (dir[ht - 2] == 0) {
      yPtr = stack[ht - 2]->link[1];
      if (yPtr != NULL && yPtr->cor == RED) {
        stack[ht - 2]->cor = RED;
        stack[ht - 1]->cor = yPtr->cor = BLACK;
        ht = ht - 2;
      } else {
        if (dir[ht - 1] == 0) {
          yPtr = stack[ht - 1];
        } else {
          xPtr = stack[ht - 1];
          yPtr = xPtr->link[1];
          xPtr->link[1] = yPtr->link[0];
          yPtr->link[0] = xPtr;
          stack[ht - 2]->link[0] = yPtr;
        }
        xPtr = stack[ht - 2];
        xPtr->cor = RED;
        yPtr->cor = BLACK;
        xPtr->link[0] = yPtr->link[1];
        yPtr->link[1] = xPtr;
        if (xPtr == raiz) {
          raiz = yPtr;
        } else {
          stack[ht - 3]->link[dir[ht - 3]] = yPtr;
        }
        break;
      }
    } else {
      yPtr = stack[ht - 2]->link[0];
      if ((yPtr != NULL) && (yPtr->cor == RED)) {
        stack[ht - 2]->cor = RED;
        stack[ht - 1]->cor = yPtr->cor = BLACK;
        ht = ht - 2;
      } else {
        if (dir[ht - 1] == 1) {
          yPtr = stack[ht - 1];
        } else {
          xPtr = stack[ht - 1];
          yPtr = xPtr->link[0];
          xPtr->link[0] = yPtr->link[1];
          yPtr->link[1] = xPtr;
          stack[ht - 2]->link[1] = yPtr;
        }
        xPtr = stack[ht - 2];
        yPtr->cor = BLACK;
        xPtr->cor = RED;
        xPtr->link[1] = yPtr->link[0];
        yPtr->link[0] = xPtr;
        if (xPtr == raiz) {
          raiz = yPtr;
        } else {
          stack[ht - 3]->link[dir[ht - 3]] = yPtr;
        }
        break;}}}
  raiz->cor = BLACK;
}
void unico(struct no *n){ //Imprimir so um no
    if(contador==1){
        printf("%d", n->chave);
        printf("R ");
    }
}
int count=0;
int nota=0;
void recolori(struct no *n){
    if(n) {
    count++;
    if(n->cor==1 && count==1){
        nota++;}
    if(n->cor && (count==2 || count ==3)){
        nota++;}
    recolori(n->link[0]);
    recolori(n->link[1]);}
}

void ordem(struct no *n) { //Para imprimir em pre ordem
if(n) {
  if (nota==3 && contador>3) {
    printf("%d", n->chave);
    printf("R ");
    nota=0;
    ordem(n->link[0]);
    ordem(n->link[1]);}
  else{
    printf("%d", n->chave);
    if(n->cor==0){
        printf("R ");}
    if(n->cor==1){
        printf("N ");}
    ordem(n->link[0]);
    ordem(n->link[1]);
  }}
  return;
}
int main() {
  char leitura[50];
  int numeros [50];
  int x=0;
  while(fgets (leitura,50,stdin)!=NULL){
        numeros[x]=0;
        int y = atoi(leitura);
        numeros[x]=y;
        insercao(numeros[x]);}
  unico(raiz);
  recolori(raiz);
  if(contador>1){
    ordem(raiz);}
  return 0;
}
