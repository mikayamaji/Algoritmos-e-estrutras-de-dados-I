//Daniela Mika 769686

#include <stdio.h>
#include <stdlib.h>

#define WATER 0
#define LAND 1

#define MAX_COLS 1024

void *malloc_safe(unsigned nbytes)
{
    void *p;
    p = malloc(nbytes);
    if (p == NULL)
    {
	printf("Nao foi possível alocar!\n");
	exit(EXIT_FAILURE);
    }
    return p;
}


int** create_matrix(int n_rows, int n_cols){
    int** m = NULL;
    m = malloc_safe(n_rows*(sizeof(int*)));
    for (int i = 0; i < n_rows; ++i)
	m[i] = malloc_safe(n_cols*sizeof(int));
    return m;
}



void destroy_matrix(int **m, int n_rows){
    for (int i = 0; i < n_rows; ++i) {
	free(m[i]);
    }
    free(m);
}


void read_input(int* m[], int *n_rows, int *n_cols){
    char line[MAX_COLS];
    for (int i = 0; i < *n_rows; ++i) {
	fgets(line, MAX_COLS, stdin);
	for (int j = 0; j < *n_cols; ++j) {
	    if(line[j] == '0')
		m[i][j] = WATER;
	    else if(line[j] == '1')
		m[i][j] = LAND;
	    else{
		printf("Wrong char in buffer\n");
		printf("%s\n", line);
		exit(EXIT_FAILURE);
	    }
	}
    }
}


void print_matrix(int m[][MAX_COLS], int n_rows, int n_cols){
    printf("Print %d x %d matrix\n", n_rows, n_cols);
    for (int i = 0; i < n_rows; ++i) {
	for (int j = 0; j < n_cols; ++j) {
	    printf("%d", m[i][j]);
	}
	printf("\n");
    }
    printf("\n");
}


int rec(int **m, int n_rows, int n_cols, int row, int col){ //função recursiva
    m[row][col] = -1;
    int total = 1;
    if (col != 0 && m[row][col - 1] == 1) //verifica se a coluna não á e última a esquerda e se o nº é 1
        total += rec(m, n_rows, n_cols, row, col - 1); //adiciona a total o valor da recursiva a esquerda
    if (col != (n_cols - 1) && m[row][col + 1] == 1) //verifica se a col não é a ultima a direita
        total += rec(m, n_rows, n_cols, row, col + 1); //add a total o valor da rec a direita
    if (row != (n_rows - 1) && m[row + 1][col] == 1) //baixo
        total += rec(m, n_rows, n_cols, row + 1, col);
    if (row != 0 && m[row - 1][col] == 1) //cima
        total += rec(m, n_rows, n_cols, row - 1, col);
    return total;

}

int search_max_area(int **m, int n_rows, int n_cols){
    int max = 0, aux;
    for (int l = 0; l < n_rows; l++)
        for (int c = 0; c < n_cols; c++)
            if (m[l][c] == 1){ //percorre todo vetor até achar o primeiro 1
                aux = rec(m, n_rows, n_cols, l, c);
                if (aux > max) //compara o valor da função rec com o max (total da função rec anterior)
                    max = aux;
            }
    return max;
}

int main(void){
    int n_rows = 0, n_cols = 0;
    scanf("%d %d\n", &n_rows, &n_cols);
    int **m = create_matrix(n_rows, n_cols);
    read_input(m, &n_rows, &n_cols);
    int area = search_max_area(m, n_rows, n_cols);
    printf("%d", area);
    /*Função para desalocar a matriz.*/
    destroy_matrix(m, n_rows);
    return 0;
}
