//Daniela Mika 769686, EnC
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nro = 0;

//função para verificar se pode ou não colocar a rainha
bool verifica (int **t, int n, int lin, int col){
    int i, j;
    for (j = 0; j < n; j++)
        if (t[lin][j] == 1) //verifica linha
            return false;
    for (i = 0; i < n; i++) //verifica coluna
        if (t[i][col] == 1)
            return false;
    for (i = lin, j = col; i >= 0 && j >= 0; i--, j--) //verifica diag principal acima
        if (t[i][j] == 1)
            return false;
    for (i = lin, j = col; i < n && j >= 0; i++, j--) //verifica diag sec acima
        if (t[i][j] == 1)
            return false;
    return true;
}

// função recursiva para resolver
// true se da pra colocar, false se não
void recursiva (int **t, int n, int col){
    if (col == n){
        nro++;
        return;
    }
    for (int i = 0; i < n; i++)
        if(verifica(t, n, i, col)){ //ve se pode por a rainha
            t[i][col] = 1; //coloca a rainha
            recursiva(t, n, col+1);
            t[i][col] = 0; //backtracking pra retirar a rainha
        }
}

int main(){
    int n;
    scanf ("%d", &n);
    int **t = (int**)malloc(n*sizeof(int*));
    for (int j = 0; j < n; j++)
        t[j] = (int*)malloc(n*sizeof(int));
    recursiva(t, n, 0);
    printf("%d", nro);
    return 0;
}




