//%%writefile grafosbfs.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODOS 2000

#define initial 1
#define waiting 2
#define visited 3
int state[MAX_NODOS]; /*can be initial, waiting or visited*/
int queue[MAX_NODOS], front = -1, rear = -1;

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
  printf("Tiempo %3f \n", cpu_time_used);
  fprintf(fptr, "Tiempo %3f \n", cpu_time_used);
}

void prueba_empirico(int **matriz, int nodos) {
  int arcos;
  int clust1;

  clock_t start;
  clock_t end;
  double cpu_time_used;

  for (int i = nodos; i < MAX_NODOS; i++) {
    arcos = i * (i - 1) / 2;
    crear_grafo(matriz, i, arcos);

    // Limpieza del grafo para tener el peor caso
    do {
      arcos = borrar_arco_aleatorio(matriz, i, arcos);
    } while (arcos != i * (i - 1) / 4);

    // Medir tiempo de contar clusteres
    start = clock();
    clust1 = contar_clusters(matriz, i);
    end = clock();

    // Guardar info
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, clust1, cpu_time_used);
    fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, clust1, cpu_time_used);
    imprimir_grafo(matriz, i);
  }
}

int maximo(int a, int b) {
  if (a > b)
    return (a);
  else
    return (b);
}

int warshall(int **matriz, int nodos) {
  int i, j, k;
  for (k = 0; k <= nodos; k++)
    for (i = 0; i <= nodos; i++)
      for (j = 0; j <= nodos; j++)
        matriz[i][j] = maximo(matriz[i][j], matriz[i][k] && matriz[k][j]);

  int n_cluster = 0;
  clusters[0] = n_cluster;
  for (i = 1; i <= nodos; i++)
    for (j = 0; j <= i; j++)
      if (matriz[i][j] == 1) {
        clusters[j] = clusters[i];
        break;
      } else if (i == j) {
        n_cluster++;
        clusters[j] = n_cluster;
      }
  return n_cluster;
}

void prueba_empirico_w(int **matriz, int nodos) {
  int arcos;
  int clust1;

  clock_t start;
  clock_t end;
  double cpu_time_used;

  for (int i = nodos; i < MAX_NODOS; i++) {
    arcos = i * (i - 1) / 2;
    crear_grafo(matriz, i, arcos);

    // Limpieza del grafo para tener el peor caso
    do {
      arcos = borrar_arco_aleatorio(matriz, i, arcos);
    } while (arcos != i * (i - 1) / 4);
    fprintf(fptr, "\n");
    imprimir_grafo(matriz, i);

    // Medir tiempo de contar clusteres
    start = clock();
    clust1 = warshall(matriz, i);
    end = clock();

    // Guardar info
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, clust1, cpu_time_used);
    fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, clust1, cpu_time_used);
    imprimir_grafo(matriz, i);
  }
}

void insert_queue(int vertex) {
  if (rear == MAX_NODOS - 1)
    printf("Queue Overflow\n");
  else {
    if (front == -1) /*If queue is initially empty */
      front = 0;
    rear = rear + 1;
    queue[rear] = vertex;
  }
} /*End of insert_queue()*/

int isEmpty_queue() {
  if (front == -1 || front > rear)
    return 1;
  else
    return 0;
} /*End of isEmpty_queue()*/

int delete_queue() {
  int del_item;
  if (front == -1 || front > rear) {
    printf("\nQueue Underflow\n");
    exit(1);
  }

  del_item = queue[front];
  front = front + 1;
  return del_item;

} /*End of delete_queue() */

void BFS(int v, int component_Num, int nodos) {
  int i;

  insert_queue(v);
  state[v] = waiting;

  while (!isEmpty_queue()) {
    v = delete_queue();
    state[v] = visited;
    clusters[v] = component_Num;

    for (i = 0; i < nodos; i++) {
      /* Check for adjacent unvisited vertices */
      if (matriz[v][i] == 1 && state[i] == initial) {
        insert_queue(i);
        state[i] = waiting;
      }
    }
  }
} /*End of BFS()*/

int BF_Traversal(int nodos) {
  int v, components = 0;
  front = -1;
  rear = -1;

  for (v = 0; v < nodos; v++) {
    state[v] = initial;
    queue[v] = 0;
  }

  components++;
  BFS(0, components, nodos); /*start BFS from vertex 0*/

  for (v = 0; v < nodos; v++) {
    if (state[v] == initial) {
      components++;
      BFS(v, components, nodos);
    }
  }
  return components;
} /*End of BF_Traversal()*/

void prueba_empirico_bfs(int **matriz, int nodos) {
  int arcos;
  int clust1;

  clock_t start;
  clock_t end;
  double cpu_time_used;

  for (int i = nodos; i < MAX_NODOS; i++) {
    arcos = i * (i - 1) / 2;
    crear_grafo(matriz, i, arcos);

    // Limpieza del grafo para tener el peor caso
    do {
      arcos = borrar_arco_aleatorio(matriz, i, arcos);
    } while (arcos != i * (i - 1) / 4);

    // Medir tiempo de contar clusteres
    start = clock();
    clust1 = BF_Traversal(i);
    end = clock();

    // Guardar info
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, clust1, cpu_time_used);
    fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, clust1, cpu_time_used);
    imprimir_grafo(matriz, i);
  }
}

int main(void) {
  srand(3);

  fptr = fopen("output_grafos.txt", "w");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  crear_matriz(matriz);
  // analizar_grafo(matriz, 512);
  // prueba_empirico(matriz, 1);
  // prueba_empirico_w(matriz, 1);
  prueba_empirico_bfs(matriz, 1);

  fclose(fptr);
  mi_malloc(-1);
  system("PAUSE");
}