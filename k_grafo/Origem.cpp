#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct vtc
{
	char r;
	struct adj *a;
	struct vtc *p;
};

struct adj
{
	struct vtc *d;
	struct adj *p;
};

struct vtc *g;
char menu();
void pausa();
void inserir_vertice();
void pesquisar_vertice();
void listar_vertices();
void inserir_adjacencia();
void pesquisar_adjacencia();
void listar_adjacencias();
struct vtc * inserir_vertice_no(char);
struct vtc * pesquisar_vertice_no(char);
struct adj * inserir_adjacencia_no(struct vtc *, struct vtc *);
struct adj * pesquisar_adjacencia_no(struct vtc *, struct vtc *);
void listar_adjacencias_vertice(struct vtc *);

int main()
{
	char op;
	g = NULL;
	do
	{
		op = menu();
	} while (op != '0');
}

char menu()
{
	char op;
	printf("\n---------------------------------------\n");
	printf("\tMENU\n");
	printf("---------------------------------------\n");
	printf("0 - ENCERRAR\n");
	printf("1 - INSERIR VERTICE\n");
	printf("2 - LISTAR VERTICES\n");
	printf("3 - PESQUISAR VERTICES\n");
	printf("4 - INSERIR ADJACENCIA\n");
	printf("5 - PESQUISAR ADJACENCIA\n");
	printf("6 - LISTAR ADJACENCIAS\n");
	printf("\nEscolha uma opcao\n");
	op = _getch();
	switch (op)
	{
	case '0':
		break;
	case '1':
		inserir_vertice();
		break;
	case '2':
		listar_vertices();
		break;
	case '3':
		pesquisar_vertice();
		break;
	case '4':
		inserir_adjacencia();
		break;
	case '5':
		pesquisar_adjacencia();
		break;
	case '6':
		listar_adjacencias();
		break;
	default:
		printf("\nEscolha uma opcao\n");
		pausa();
		break;
	}
	return op;
}

void pausa()
{
	printf("\nTecle algo...");
	_getch();
}



/*void titulo(char *texto)
{
	system("cls");
	printf("---------------------------------------\n");
	printf("%s\n", texto);
	printf("---------------------------------------\n");
}*/

void inserir_vertice()
{
	struct vtc *aux;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tINSERIR VERTICE\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo: ");
	scanf_s("%p", &r);
	_getche();
	printf("\n");
	aux = inserir_vertice_no(r);
	if (aux != NULL)
		printf("\nInserido com sucesso no endereco: %p", aux);
	else
		printf("\nErro na insercao!\n");
	pausa();
}


void listar_vertices()
{
	struct vtc*aux;
	printf("\n---------------------------------------\n");
	printf("\tLISTAR VERTICES\n");
	printf("---------------------------------------\n");
	aux = g;
	while (aux != NULL)
	{
		printf("\n%p - %c", aux, aux->r);
		aux = aux->p;
	}
	pausa();
}

void pesquisar_vertice()
{
	struct vtc *aux;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tPESQUISAR VERTICE\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo: ");
	scanf_s("%p", &r);
	_getche();
	printf("\n");
	aux = pesquisar_vertice_no(r);
	if (aux != NULL)
		printf("\nInserido com sucesso no endereco: %p", aux);
	else
		printf("\nNao encontrado!\n");
	pausa();
}

void inserir_adjacencia()
{
	struct vtc *o, *d;
	struct adj *aux;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tINSERIR ADJACENCIA\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo de origem: ");
	scanf_s("%p", &r);
	_getche();
	printf("\n");
	o = pesquisar_vertice_no(r);
	if (o != NULL)
	{
		printf("Informe o rotulo de destino: ");
		scanf_s("%p", &r);
		_getche();
		printf("\n");
		d = pesquisar_vertice_no(r);
		if (d != NULL)
		{
			aux = pesquisar_adjacencia_no(o, d);
			if (aux == NULL)
			{
				aux = inserir_adjacencia_no(o, d);
				if (aux != NULL)
					printf("\nInserido com sucesso no endereco: %p", aux);
				else
					printf("\nNao inserido!\n");
			}
			else
				printf("\nAdjacencia ja existe!");
			pausa();
		}
		else
			printf("\nDestino nao existe!");
	}
	else
		printf("\nOrigem nao existe!");
}

/*void pesquisar_caminho()
{
	struct vtc *o, *d, *aux, *novo;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tINSERIR ADJACENCIA\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo de origem: ");
	r = _getche();
	printf("\n");
	o = pesquisar_vertice_no(r);
	if (o == NULL)
	{
		printf("Informe o rotulo de destino: ");
		r = _getche();
		printf("\n");
		d = pesquisar_vertice_no(r);
		if (d != NULL)
		{
			if (existe_caminho(o, d))
				printf("Caminho existe!");
			else
				printf("Caminho inexistente!");
		}
	}
	else
		printf("Origem inexistente!");

}*/

void pesquisar_adjacencia()
{
	struct vtc *o, *d;
	struct adj *aux;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tPESQUISAR ADJACENCIA\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo de origem: ");
	scanf_s("%p", &r);
	_getche();
	printf("\n");
	o = pesquisar_vertice_no(r);
	if (o != NULL)
	{
		printf("Informe o rotulo de destino: ");
		scanf_s("%p", &r);
		_getche();
		printf("\n");
		d = pesquisar_vertice_no(r);
		if (d != NULL)
		{
			aux = inserir_adjacencia_no(o, d);
			if (aux != NULL)
				printf("\nEncontrado com sucesso no endereco: %p", aux);
			else
				printf("\nNao encontrado!\n");
			pausa();
		}
	}
}

struct vtc * pesquisar_vertice_no(char r)
{
	struct vtc *aux;
	aux = g;
	while (aux != NULL && aux->r != r)
		aux = aux->p;
	return aux;
}

void listar_adjacencias()
{
	struct vtc *aux;
	char r;
	printf("\n---------------------------------------\n");
	printf("\tLISTAR ADJACENCIA\n");
	printf("---------------------------------------\n");
	printf("Informe o rotulo de origem: ");
	scanf_s("%p", &r);
	_getche();
	printf("\n");
	aux = pesquisar_vertice_no(r);
	if (aux != NULL)
	{
		listar_adjacencias_vertice(aux);
	}
	else
	{
		printf("\nOrigem nao existe");
	}
	pausa();
}

struct vtc * inserir_vertice_no(char r)
{
	struct vtc *novo, *aux=nullptr;
	novo = (struct vtc *)malloc(sizeof(struct vtc));
	if (novo != NULL)
	{
		novo->r = r;
		novo->a = NULL;
		novo->p = NULL;
		if (g == NULL)
		{
			g = novo;
			aux = g;
		}

		else
		{
			aux = g;
			while (aux->p != NULL)
				aux = aux->p;
			aux->p = novo;
		}

	}
	return aux;
}

struct adj * inserir_adjacencia_no(struct vtc *o, struct vtc *d)
{
	struct adj *novo, *aux;
	novo = (struct adj *)malloc(sizeof(struct adj));
	if (novo != NULL)
	{
		novo->d = d;
		novo->p = NULL;

		if (o->a == NULL)
			o->a = novo;

		else
		{
			aux = o->a;
			while (aux->p != NULL)
				aux = aux->p;
			aux->p = novo;
		}

	}
	return novo;
}

struct adj * pesquisar_adjacencia_no(struct vtc *o, struct vtc *d)
{
	struct adj *aux;
	aux = o->a;
	while (aux->p != NULL && aux->d != d)
		aux = aux->p;
	return aux;
}

void listar_adjacencias_vertice(struct vtc *o)
{
	struct adj *aux;
	printf("\nOrigem: %p - %c", o, o->r);
	aux = o->a;
	while (aux != NULL)
	{
		printf("\nDestino: %p - %c", aux->d, aux->d->r);
		aux = aux->p;
	}

}

