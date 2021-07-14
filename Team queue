#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000
#define MAXTEAMS 10001
#define CMDLEN 20

typedef struct no
{
	int n;
	int team;
	struct no *proximo;
}no;
typedef no *lista_lista;

int table[MAX];
no *no_tab[MAXTEAMS];
no *fim;

void enqueue(int n,lista_lista *l);
void inicializar_tab(no *tab[]);
int dequeue(lista_lista *l);
void inicializar(lista_lista *l);
void destruir(lista_lista *l);

void enqueue(int n,lista_lista *l)
{
	no *aux,*p=*l;
	aux=(no *)malloc(sizeof(no));
	aux->n=n;
	aux->team=table[n];
	aux->proximo=NULL;
	if(!p)
	{
		*l=aux;
		fim=aux;
		no_tab[aux->team]=aux;
		return;
	}
	else
	{
		p=no_tab[aux->team];
		if(!p)
		{
			fim->proximo=aux;
			fim=aux;
			no_tab[aux->team]=fim;
		}
		else
		{
			if(p==fim)
				fim=aux;
			aux->proximo=p->proximo;
			p->proximo=aux;
			no_tab[aux->team]=aux;
		}
	}
}

void inicializar_tab(no *tab[])
{
	int i;
	for(i=0;i<MAXTEAMS;i++)
	{
		tab[i]=NULL;
	}	
}

int dequeue(lista_lista *l)
{
	int n;
	if(!(*l))
		return -1;
	no *aux;
    aux=*l;
	*l=(*l)->proximo;
	n=aux->n;
	if(no_tab[aux->team]==aux)
		no_tab[aux->team]=NULL;
	free(aux);
	return n;
}

void inicializar(lista_lista *l)
{
	*l=NULL;
	fim=NULL;
}

void destruir(lista_lista *l)
{
	no *aux;
	while(*l)
	{
		aux=*l;
		*l=(*l)->proximo;
		free(aux);
	}
}

int main()
{
	lista_lista l;
	int teams,n,val,count=1,case_count=1,primeiro=1,case1=1,x;
	char comando[CMDLEN];
	inicializar(&l);
	
	do
	{
		scanf("%d",&teams);
		if(!teams) {
		    printf("\n");
			break;
		}
		else
		{
			inicializar_tab(no_tab);
			if(!case1)
			{
				printf("\n");
			}
			case1=0;
		}
		while(teams)
		{
			scanf("%d",&n);
			while(n)
			{
				scanf("%d",&val);
				table[val]=count;
				n--;
			}
			count++;
			teams--;
		}
		while(1)
		{
			scanf("%s",comando);
			if(comando[0]=='E')
			{
			    if(primeiro)
                {
                	printf("Scenario #%d\n",case_count);
                	primeiro=0;
                }
				scanf("%d",&val);
				enqueue(val,&l);
			}
			else if(comando[0]=='D')
			{
				if(primeiro)
				{
					printf("Scenario #%d\n",case_count);
					primeiro=0;
				}
				x=dequeue(&l);
				if(x!=-1)
					printf("%d\n",x);
			}
			else if(comando[0]=='S')
			{
				destruir(&l);
				case_count++;
				count=1;
				primeiro=1;
				break;
			}
		}
	}while(1);
	return 0;
}
