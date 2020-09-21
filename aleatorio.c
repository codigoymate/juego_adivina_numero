#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
	int numero;

	srand(time(NULL));

	numero = rand(); // 0 ----> RAND_MAX (2147483647)
	printf("%d\n", numero);
	numero = rand();
	printf("%d\n", numero);
	numero = rand();
	printf("%d\n", numero);
	numero = rand();
	printf("%d\n", numero);

	return 0;
}