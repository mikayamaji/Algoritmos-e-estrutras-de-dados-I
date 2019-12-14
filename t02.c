//Daniela Mika 769686, Engenharia de computação

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    int posicao;
    struct pessoa *prox;
} Pessoa;

Pessoa *inicio;

void insereLista (int x) {
    Pessoa *nova;
    Pessoa *fim;
    nova = malloc(sizeof(Pessoa));
    //cria duas células novas e aloca dinamicamente a nova
    nova->posicao = x; //atribui o conteúdo x a célula nova
    if (inicio == NULL){ //se não tiver uma lista criada, cria-se uma do zero
        nova->prox= nova;
        inicio = nova;
        fim = nova;
    }
    fim->prox = nova; //com a lista já criada, insere-se novas células
    nova->prox = inicio;
    fim = nova;
}

void removeLista (Pessoa *p) {
    Pessoa *morta;
    Pessoa *aux = inicio;
    while (aux != p) //busca o elemento que quer remover
    {
        aux = aux->prox;
    }
    morta = p->prox;
    aux->prox = morta->prox;
    free(morta);
}

void imprimeLista(){
    Pessoa *aux = inicio;
    do {
        printf("Soldado %d ", aux->posicao);
        aux = aux->prox;
    }
    while (aux != inicio); //imprime a lista, enquanto ela nao tiver chegado ao fim
}

int resolveJosephus(int n, int m)
{
    inicio = NULL;
    for(int i=1; i<=n; i++) //insere cada soldado na lista
        insereLista(i);
    Pessoa* aux = inicio;
    while (inicio->prox != inicio){ //looping enquanto tiverem + de 2 soldados na lista
        inicio = aux;
        for(int i=0; i<(m-1); i++)
            aux = aux->prox; //auxiliar muda de posição conforme o número de passos pra matar o soldado
        if(aux->prox == inicio)
            aux = aux->prox;
        removeLista(aux); //remove o soldado que se quer matar
        aux = aux->prox;
    }
    return aux->posicao;
}

int main () {
    int nroexecs ;

    scanf ("%d", &nroexecs ) ;
    int *n = malloc (nroexecs*sizeof(int) ) ;
    int *p = malloc (nroexecs*sizeof(int) ) ;

    for (int i = 0; i < nroexecs ; i ++) {
        scanf ("%d", &n[i]) ;
        scanf ("%d", &p[i]) ;
    }

    for (int i = 0; i < nroexecs ; i ++) {
        printf ("Usando n=%d, m=%d, resultado=%d\n", n[i] , p[i] , resolveJosephus (n[i] ,p[i]) ) ;
    }

    return 0;
}
