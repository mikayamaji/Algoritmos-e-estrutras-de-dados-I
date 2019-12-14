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