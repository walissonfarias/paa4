#include<iostream>
#include<vector>

typedef int elem;
// Tipo exportado
typedef struct arv* Arv;

typedef struct Arv
{
	int info;
	struct node* left;
	struct node* right;
	struct node* father;
} NODE;
typedef NODE* ARV_BIN_ENC;

Arv arv_criavazia(void)
{
	return NULL;
}

int arv_vazia(Arv a)
{
	return a == NULL;
}

Arv arv_cria(elem c, Arv sae, Arv sad)
{
	Arv p = (Arv)malloc(sizeof(struct arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

Arv arv_libera(Arv* a) {
	if (!arv_vazia(a)) {
		arv_libera(a->esq); /* libera sae */
		arv_libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
	}
	return NULL;
}

void arv_imprime(Arv* a)
{
	if (!arv_vazia(a)) {
		printf("%c ", a->info); /* mostra raiz */
		arv_imprime(a->esq); /* mostra sae */
		arv_imprime(a->dir); /* mostra sad */
	}
}

int main() {
	Arv* a = arv_cria('a',
		arv_cria('b',
			arv_criavazia(),
			arv_cria('d', arv_criavazia(), arv_criavazia())
		),
		arv_cria('c',
			arv_cria('e', arv_criavazia(), arv_criavazia()),
			arv_cria('f', arv_criavazia(), arv_criavazia())
		)
	);
	arv_imprime(a);
}