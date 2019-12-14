// Daniela Mika, RA: 769686, Engenharia de computação

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromoR(int i, int f, char *s)
{
    if (f<=i)/*caso-base: quando a última posição não tiver antes da primeira (número par de posições) ou quando a última
        for a mesma que a primeira (número impar de posições)*/
        return 1;
    else if (s[i]!=s[f]) // quando os elementos comparados não forem iguais, já se tem a certeza que não é palindromo
        return 0;
    return palindromoR(i+1, f-1, s); //chama a função de novo para verificar os dois prox pares de elementos
}

void palindromo(char *s)
{
    int saida = palindromoR(0, strlen(s) - 1, s);

    printf("\"");
    printf("%s", s);
    printf("\" ");

    if (saida)
    {
        printf("eh palindromo\n");
    }
    else
    {
        printf("nao eh palindromo\n");
    }
}

void inversaR(char *str)
{
    if (*str){ //se o elemento for diferente de '\0' (indica final de string)
        inversaR(str+1); //adiciona +1 na posição de memoria e proxicmo char vira o parametro
        putchar(*str); // chama a função de novo e retorna os caracteres de forma recursiva
    }
}

void inversa(char *s)
{
    printf("inversa de \"");
    printf("%s", s);
    printf("\" = ");

    inversaR(s);

    printf("\n");
}

unsigned long stirlingR(unsigned long n, unsigned long k)
{
    if (n==0 && k==0) //case-base fornecido pelo enunciado
        return 1;
    else if (k == 0 || n == 0) //segundo caso-base já fornecido
        return 0;
    else //chama a função dentro da própria função para calcular o número até chegar no caso-base
        return (n-1)*stirlingR(n-1,k)+stirlingR(n-1, k-1);
    }

void stirling(unsigned long n, unsigned long k)
{
    printf("Numero de Stirling [%lu, %lu]:", n, k);
    printf("%lu\n", stirlingR(n, k));
}

void padraoR(unsigned int x)
{
     if (x==0) //caso-base: quando chegou no meio da string
        printf("00");
    else if (x>0){
        printf("%d", x); //imprime o elemento
        padraoR(x-1); //chama a função de novo para o elemento anterior ao impresso
        printf("%d", x); //deois de chegar ao caso-base, a função termina seu comando e imprime os elementos depois do '00'
    }
}

void padrao(unsigned int x)
{
    printf("Testando o padrao para n = %d.\n", x);
    padraoR(x);
    printf("\n");
}


int main(int argc, char *argv[])
{
    int t;

    scanf("%d", &t);

    // if (argc != 2 || (t = atoi(argv[1])) < 1 || t > 4)
    if (t < 1 || t > 4)
    {
        printf("Parametros incorretos.\n");
        printf("Ex:\n");
        printf("tp01_recursao 1 [para testar palindromo]\n");
        printf("tp01_recursao 2 [para testar inversa]\n");
        printf("tp01_recursao 3 [para testar fibonacci]\n");
        printf("tp01_recursao 4 [para testar pisoLog]\n");
    }

    if (t == 1)
    {
        printf("\nTestando palindromo()\n\n");
        palindromo("");
        palindromo("1");
        palindromo("77");
        palindromo("505");
        palindromo("1111");
        palindromo("2112");
        palindromo("369963");
        palindromo("10101");
        palindromo("1001001");
        palindromo("12");
        palindromo("12451");
        palindromo("100011");
    }
    else if (t == 2)
    {
        printf("\nTestando inversa()\n\n");
        inversaR("");
        inversa("ab");
        inversa("gato");
        inversa("minerva");
    }
    else if (t == 3)
    {
        printf("\nTestando stirling()\n\n");
	stirling(0, 0);
	stirling(0, 3);
	stirling(5, 0);
	stirling(2, 2);
	stirling(5, 1);
	stirling(5, 2);
	stirling(7, 6);
	stirling(9, 3);
	stirling(10, 3);
	stirling(10, 5);
    }
    else if (t == 4)
    {
        printf("\nTestando padrao()\n\n");
	padrao(0);
	padrao(1);
	padrao(5);
	padrao(10);
	padrao(100);
    }

    return 0;
}
