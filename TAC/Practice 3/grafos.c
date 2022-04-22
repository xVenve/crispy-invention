#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODOS 2000

int *matriz[MAX_NODOS];
int clusters[MAX_NODOS];
FILE *fptr;

char *mi_malloc(int nbytes) {
  char *p;
  static long int nb = 0L;
  static int nv = 0;

  p = malloc(nbytes);
  if (p == NULL) {
    fprintf(stderr, "Error, no queda memoria disponible para %d bytes mas\n", nbytes);
    fprintf(stderr, "Se han reservado %ld bytes en %d llamadas\n", nb, nv);
    exit(0);
  }

  nb += (long)nbytes;
  nv++;

  return p;
}

/* crea matriz: vector de punteros a vectores en memoria dinámica */
void crear_matriz(int **matriz) {
  int i;

  for (i = 0; i < MAX_NODOS; i++) {
    matriz[i] = (int *)mi_malloc(sizeof(int) * MAX_NODOS);
  }
}

/* 0 indica que no hay arista entre los nodos i-j */
void inicializar_grafo(int **matriz, int nodos) {
  int i;
  int j;

  for (i = 0; i < nodos; i++) {
    for (j = 0; j < nodos; j++) {
      matriz[i][j] = 0;
    }
  }
}

/* crea grafo con n nodos y a arcos: no se controlan los limites */
/* 1 indica que hay arista entre los nodos i-j */
void crear_grafo(int **matriz, int nodos, int arcos) {
  int i;
  int p;
  int q;

  inicializar_grafo(matriz, nodos);

  for (i = 0; i < arcos; i++) {
    do {
      p = rand() % nodos;
      q = rand() % nodos;
    } while (p == q || matriz[p][q] != 0); // evitar diagonal y arcos existentes
    matriz[p][q] = 1;
    matriz[q][p] = 1; // arista simétrica
  }
}

int borrar_arco_aleatorio(int **matriz, int nodos, int arcos) {
  int p;
  int q;

  if (arcos == 0) {
    return 0;
  }

  do {
    p = rand() % nodos;
    q = rand() % nodos;
  } while (matriz[p][q] == 0 || p == q); // p==q es redundante

  matriz[p][q] = 0;
  matriz[q][p] = 0;

  return arcos - 1;
}

/* imprime nodos del grafo en diagonal y en las intersecciones si son adyacentes */
/* imprime antes el número de grafo incoexo (cluster) si está disponible */
void imprimir_grafo(int **matriz, int nodos) {
  int i;
  int j;

  for (i = 0; i < nodos; i++) {
    fprintf(fptr, "%4d, c:%3d: ", i, clusters[i]);
    for (j = 0; j < nodos; j++) {
      if (i == j) { // marca diagonal con punto
        // printf (".", i);
        fprintf(fptr, ".");
      } else if (matriz[i][j] == 1) { // si i-j son adyacentes
        fprintf(fptr, "+");           // marca interseccion i-j con +
      } else
        fprintf(fptr, " ");
    }
    fprintf(fptr, "\n");
  }
}

/* para propagar recursivamente una marca (número de cluster) a los nodos adyacentes del nodo n */
void propagar_marcaR(int **matriz, int nodos, int n, int n_cluster) { // T(n) = 1 + 2 + n(3 + 3 + 1 + T(n-1))
  int j;

  for (j = 0; j < nodos; j++) { // T(n) = 2 + n*(3+3+1+1+T(n-1)); T(n) = 2 + n*(8 + T(n-1))
    if (n != j && matriz[n][j] != 0 && clusters[j] == -1) {
      clusters[j] = n_cluster;
      propagar_marcaR(matriz, nodos, j, n_cluster);
    }
  }
}

/* wrapper para propagar una marca (número de cluster) a los nodos adyacentes  */
int contar_clusters(int **matriz, int nodos) { // T(n)=3 + 2 + n(3+ 1) + 1 + 2 + n(3 + 1 + 2 + LLAMADA + 1) + 1
  int i;
  int j;
  int n_cluster;

  for (i = 0; i < nodos; i++) { // T(n) = 2 + n*(1+2+1) ; T(n) = 4n + 2
    clusters[i] = -1;           // todos los nodos sin marcar para empezar
  }
  n_cluster = 0;

  for (i = 0; i < nodos; i++) { // T(n) = 2 + n*(1+2+1+1+1+__+2) = 2 + n*(8+__)
    if (clusters[i] == -1) {    // nodo i no está marcado ==> es nodo de grafo inconexo
      clusters[i] = n_cluster;  // nuevo cluster y propagar a sus adyacentes
      propagar_marcaR(matriz, nodos, i, n_cluster);
      n_cluster++;
    }
  }

  return n_cluster;
}

void analizar_grafo(int **matriz, int nodos) {
  int arcos;
  int clust0;
  int clust1;

  clock_t start, startT;
  clock_t end, endT;
  double cpu_time_used, cpu_time_usedT;

  arcos = nodos * (nodos - 1) / 2;

  crear_grafo(matriz, nodos, arcos); // crea grafo completo

  start = clock();
  clust0 = 0;

  do {
    startT = clock();
    clust1 = contar_clusters(matriz, nodos);
    endT = clock();
    cpu_time_usedT = ((double)(endT - startT)) / CLOCKS_PER_SEC;
    printf("Arcos\t %4d\t Tiempo\t %3f \n", arcos, cpu_time_usedT);
    if (clust1 > clust0) { // imprime solo si aparece nuevo cluster
      cpu_time_usedT = ((double)(endT - startT)) / CLOCKS_PER_SEC;
      printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, clust1, cpu_time_usedT);
      fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, clust1,
              cpu_time_usedT);
      clust0 = clust1;
      imprimir_grafo(matriz, nodos);
    } // elimina un arco al azar:
    arcos = borrar_arco_aleatorio(matriz, nodos, arcos);
  } while (arcos > 0);

  startT = clock();
  clust1 = contar_clusters(matriz, nodos);
  endT = clock();
  if (clust1 > clust0) { // imprime solo si aparece nuevo cluster
    cpu_time_usedT = ((double)(endT - startT)) / CLOCKS_PER_SEC;
    printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, clust1, cpu_time_usedT);
    fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, clust1, cpu_time_usedT);
    clust0 = clust1;
    imprimir_grafo(matriz, nodos);
  }

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Tiempo %3f segs \n", cpu_time_used);
  fprintf(fptr, "Tiempo %3f segs \n", cpu_time_used);
}

int main(void) {
  srand(3);

  fptr = fopen("output_grafos.txt", "w");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  crear_matriz(matriz);
  /* int nodos = 4;
  int arcos = nodos * (nodos - 1) / 2;
  crear_grafo(matriz, nodos, arcos);
  for (int i = 0; i < nodos * (nodos - 1) / 2; i++) {
    arcos = borrar_arco_aleatorio(matriz, nodos, arcos);
  }

  clock_t startTT;
  clock_t endTT;
  double cpu_time_usedTT;
  startTT = clock();
  int cl = contar_clusters(matriz, nodos);
  endTT = clock();
  cpu_time_usedTT = ((double)(endTT - startTT)) / CLOCKS_PER_SEC;
  printf("Tiempo %3f \n", cpu_time_usedTT);
  printf("%d\n", cl); */

  // analizar_grafo(matriz, 16);
  // analizar_grafo(matriz, 32);
  // analizar_grafo(matriz, 64);
  // analizar_grafo(matriz, 128);
  // analizar_grafo(matriz, 256);
  analizar_grafo(matriz, 512);
  // analizar_grafo(matriz, 1024);

  fclose(fptr);
  mi_malloc(-1);
  system("PAUSE");
}