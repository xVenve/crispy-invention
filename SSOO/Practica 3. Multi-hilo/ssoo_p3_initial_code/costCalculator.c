
#include "queue.h"
#include <fcntl.h>
#include <math.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_CONSUMERS 1

/**
 * Entry point
 * @param argc
 * @param argv
 * @return
 */

pthread_mutex_t ring;
pthread_mutex_t des;
pthread_cond_t lleno;
pthread_cond_t vacio;
struct queue *cola;
const char *fichero;
FILE *descriptorP;
int total = 0;

struct param {
  int id_ini;
  int op;
};

// Cada hilo tiene acceso a su propio dominio de id`s, donde el nº de operaciones que tendrá asociado será
// floor(num.lineas/num.productores), leerá e insertará de uno en uno
void *producir(void *arg) {
  // Sacar parametros
  struct param *p = arg;

  // Hallamos el desciptor que corresponde al primer indice, para que no se mezclen bloquemas y desbloqueamos
  pthread_mutex_lock(&des);

  descriptorP = fopen(fichero, "r");
  int counter = 0;
  char chr;
  while (counter <= p->id_ini) {
    chr = fgetc(descriptorP);
    if (chr == '\n') {
      counter++;
    }
  }                            // fin while
  FILE *current = descriptorP; // Almacenamos la posicion por la que va, de esta manera la podemos recuperar.

  pthread_mutex_unlock(&des);

  int i, i1, i2 = 0;
  for (int j = p->op; j > 0; j--) {
    // Sacamos los valores a introducir en el buffer del puntero, y salvamos la nueva posicion del mismo.
    pthread_mutex_lock(&des);

    descriptorP = current;
    fscanf(descriptorP, "%d %d %d", &i, &i1, &i2);
    current = descriptorP;

    // Prueba impresion
    // printf("Escribe el que comienza en %d, el id %d (Ajustado para coincidir)\n", p->id_ini, i-1);

    pthread_mutex_unlock(&des);

    struct element temporal = {i1, i2};

    pthread_mutex_lock(&ring);
    while (queue_full(cola))
      pthread_cond_wait(&lleno, &ring);

    queue_put(cola, &temporal);

    pthread_cond_signal(&vacio);
    pthread_mutex_unlock(&ring);
  }
}

void *consumir() {
  struct element data;
  //Bucle de todo mientras no se hallar leido todas las ops esperadas, meter parametro.
  pthread_mutex_lock(&ring);

  while (queue_empty(cola))
    pthread_cond_wait(&vacio, &ring);

  //Sacar parametros, queue_get

  pthread_cond_signal(&lleno);
  pthread_mutex_unlock(&ring);

  //Al ser solo 1 la variable total no se modifica. Carlos <3
  //total+=...
}

int calculo_lineas(const char filename[]) {
  FILE *file = fopen(filename, "r");
  char chr;
  int lines = 0;
  while (!feof(file)) {
    chr = fgetc(file);
    if (chr == '\n') {
      lines++;
    }
  }
  fclose(file);
  return lines;
}

int main(int argc, const char *argv[]) {

  printf("%s\n", argv[1]);
  FILE *descriptor = fopen(argv[1], "r");

  int numVal;
  fscanf(descriptor, "%d", &numVal);
  int numLin = calculo_lineas(argv[1]);
  printf("Lineas: %d\n", numLin);
  if (numVal > (numLin - 1)) {
    perror("Error: Se esperaban mas operaciones.");
    return -1;
  }

  int productores = atoi(argv[2]);
  if (productores <= 0) {
    perror("Error: Numero invalido de productores.");
  }
  int size = atoi(argv[3]);
  if (size <= 0) {
    perror("Error: Tamaño invalido.");
  }

  cola = queue_init(size);
  pthread_mutex_init(&ring, NULL);
  pthread_mutex_init(&des, NULL);
  pthread_cond_init(&lleno, NULL);
  pthread_cond_init(&vacio, NULL);

  int operaciones = floor((numVal / productores));
  int id_inicio = 1;
  pthread_t hilosP[productores];
  pthread_t hiloC;
  pthread_create(&hiloC, NULL, (void *)consumir, NULL);
  int i;
  fichero = malloc(sizeof(char[strlen(argv[1])]));
  fichero = argv[1];
  struct param args[productores];
  for (i = 0; i < (productores - 1); i++) {
    // printf("ID: %d\n", id_inicio);
    args[i].op = operaciones;
    args[i].id_ini = id_inicio;
    pthread_create(&hilosP[i], NULL, (void *)producir, &args[i]);
    id_inicio += operaciones;
  }
  int op_ultimo = numVal - (i * operaciones);
  args[productores - 1].op = op_ultimo;
  args[productores - 1].id_ini = id_inicio;
  pthread_create(&hilosP[productores - 1], NULL, (void *)producir, &args[productores - 1]);

  for (int i = 0; i < productores; i++) {
    pthread_join(hilosP[i], NULL);
  }
  pthread_join(hiloC, NULL);

  /*
  printf("El numero total de productores es %d\n",numVal);
  int i,i1,i2;
  fscanf(descriptor, "%d %d %d", &i, &i1, &i2 );
  printf("La primera fila es %d, %d y %d\n",i, i1, i2);

  fscanf(descriptor, "%d %d %d", &i, &i1, &i2 );
  printf("La segunda fila es %d, %d y %d\n", i, i1, i2);
 */

  /*
    //PRUEBA BUFFER
    printf("Inicio\n");
    struct queue *cola = queue_init(3);

    printf("He inicializado\n");
    struct element elem = {1, 2};

    queue_put(cola, &elem);

    printf("Vacia %d\n", queue_empty(cola));
    printf("Llena %d\n", queue_full(cola));

    struct element *elem2 = queue_get(cola);
    struct element elem3 = {10, 20};

    printf("Vacia %d\n", queue_empty(cola));

    printf("Type %d, time %d\n", elem2->type, elem2->time);
    printf("Type %d, time %d\n", elem3.type, elem3.time);
    queue_destroy(cola);
    //
  */

  printf("Total: %i €.\n", total);
  return 0;
}
