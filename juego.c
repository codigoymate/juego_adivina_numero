#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaraciones
void intro (void);
double rand_double(void);
int elegir_numero(void);
void informar(int intentos);
int obtener_entero(void);

void victoria(int numero);
void derrota(int numero);

int dialogo_salir(void);

int main (int argc, char *argv[]) {

	int salir = 0, maquina, humano, intentos, jugando;

	srand(time(NULL));

	intro();

	while (!salir) {
		maquina = elegir_numero();
		intentos = 10; jugando = 1;

		while (jugando) {
			informar(intentos);
			humano = obtener_entero();

			// Evaluo la entrada
			if (humano == 0) {
				jugando = 0;
			} else if (humano < maquina) {
				printf("\nEs mayor... Se resta un intento.\n"); intentos --;
			} else if (humano > maquina) {
				printf("\nEs menor... Se resta un intento.\n"); intentos --;
			} else /*(humano == maquina)*/ {
				victoria(maquina); jugando = 0;
			}

			if (intentos == 0) {
				derrota(maquina); jugando = 0;
			}
		}

		salir = dialogo_salir();
	}

	return 0;
}

void intro (void) {
	printf("\n\n\nAdivina El Numero 1.0\n");
	printf("2020 - Javier Candales. (Código y Mate)\n\n");
}

double rand_double(void) {
	// rand()   0   -----   RAND_MAX

	// 1.0   ----->  RM
	//  X   ------->  rand();
	return (double)rand() / (double)RAND_MAX;
}

int elegir_numero(void) {
	return rand_double() * 1000 + 1;
}

void informar(int intentos) {
	printf("\nIngresa un número comprendido entre 1 y 1000 (0 para salir):\n");
	printf("Te quedan %d intentos >>> ", intentos);
}

int obtener_entero(void) {

	int numero;

	do {

		scanf("%d", &numero);

		if (numero < 0 || numero > 1000) {
			printf("\nDebe ser entre 1 y 1000 (y 0 para salir) >>> ");
		}

	} while (numero < 0 || numero > 1000);

	return numero;
}

void victoria(int numero) {
	printf("\nGanaste !!! El numero era %d !!\n\n", numero);
}

void derrota(int numero) {
	printf("\nPerdiste. El numero era %d :(\n\n", numero);
}

int dialogo_salir(void) {
	//char opcion[2];
	char opcion[] = " ";

	while (1) {
		printf("Continuar jugando (s/n)? > ");

		scanf("%1s", opcion);

		if (opcion[0] == 's' || opcion[0] == 'S') {
			return 0;
		}

		if (opcion[0] == 'n' || opcion[0] == 'N') {
			return 1;
		}

		printf("Por favor elegir (s) o (n).\n");
	}

	// nunca pasa por aca.
	return 0;
}