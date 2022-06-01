//%%writefile grafos3.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODOS 2000

#define initial 1
#define waiting 2
#define visited 3
int state[MAX_NODOS]; /*can be initial, waiting or visited*/
int queue[MAX_NODOS], front = -1, rear = -1;
unsigned long long int cont = 0;

int *matriz[MAX_NODOS];
int colores[MAX_NODOS];
int conexiones[MAX_NODOS];
int indices[MAX_NODOS];
unsigned long long sin_conflictos = 0L;

/**
 * It's a wrapper for malloc() that prints an error message and exits if malloc() returns NULL
 *
 * @param nbytes The number of bytes to allocate.
 *
 * @return A pointer to the first byte of the allocated memory.
 */
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

    nb += (long) nbytes;
    nv++;

    return p;
}

/**
 * It creates a matrix of MAX_NODOS x MAX_NODOS, and then assigns each row to a pointer in the array
 * matriz
 */
void crear_matriz() {
    int i;

    for (i = 0; i < MAX_NODOS; i++) {
        matriz[i] = (int *) mi_malloc(sizeof(int) * MAX_NODOS);
    }
}

/**
 * It initializes a matrix to all zeros
 *
 * @param nodos number of nodes
 */
void inicializar_grafo(int nodos) {
    int i;
    int j;

    for (i = 0; i < nodos; i++) {
        for (j = 0; j < nodos; j++) {
            matriz[i][j] = 0;
        }
    }
}

/**
 * It creates a random graph with a given number of nodes and edges
 *
 * @param nodos number of nodes
 * @param arcos number of edges
 */
void crear_grafo(int nodos, int arcos) {
    int i;
    int p;
    int q;

    inicializar_grafo(nodos);

    for (i = 0; i < arcos; i++) {
        do {
            p = rand() % nodos;
            q = rand() % nodos;
        } while (p == q || matriz[p][q] != 0); // evitar diagonal y arcos existentes
        matriz[p][q] = 1;
        matriz[q][p] = 1; // arista simétrica
    }
}

/**
 * It creates a graph with a given number of nodes and a given number of arcs per node
 *
 * @param nodos number of nodes
 * @param arcospornodo the number of arcs per node
 */
void construye_grafo(int nodos, double arcospornodo) {
    crear_grafo(nodos, nodos * arcospornodo); // crea grafo maximo
    // imprimir_grafo(nodos);
}

/**
 * It picks a random edge, and deletes it
 *
 * @param nodos number of nodes
 * @param arcos number of arcs
 *
 * @return The number of arcs in the graph.
 */
int borrar_arco_aleatorio(int nodos, int arcos) {
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

/**
 * It prints the adjacency matrix of the graph
 *
 * @param nodos number of nodes
 */
void imprimir_grafo(int nodos) {
    int i;
    int j;

    for (i = 0; i < nodos; i++) {
        printf("%4d, c:%3d: ", i, colores[i]);
        for (j = 0; j < nodos; j++) {
            if (i == j) { // marca diagonal con punto
                // printf (".", i);
                printf(".");
            } else if (matriz[i][j] == 1) { // si i-j son adyacentes
                printf("+");           // marca intersección i-j con +
            } else
                printf(" ");
        }
        printf("\n");
    }
}

/**
 * It merges two sorted subarrays into a single sorted subarray.
 *
 * @param p starting index of the sub-array
 * @param q the middle of the array
 * @param r the last index of the array
 */
void merge(int p, int q, int r) {
    cont += 5;
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];
    int L2[n1], M2[n2];

    cont += 2;
    for (int i = 0; i < n1; i++) {
        cont += 7;
        L[i] = conexiones[p + i];
        L2[i] = indices[p + i];
    }
    cont += 2;
    for (int j = 0; j < n2; j++) {
        cont += 9;
        M[j] = conexiones[q + 1 + j];
        M2[j] = indices[q + 1 + j];
    }

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    cont += 5;
    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        cont += 9;
        if (L[i] >= M[j]) {
            conexiones[k] = L[i];
            indices[k] = L2[i];
            i++;
        } else {
            conexiones[k] = M[j];
            indices[k] = M2[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    cont += 1;
    while (i < n1) {
        cont += 7;
        conexiones[k] = L[i];
        indices[k] = L2[i];
        i++;
        k++;
    }
    cont += 1;
    while (j < n2) {
        cont += 7;
        conexiones[k] = M[j];
        indices[k] = M2[j];
        j++;
        k++;
    }
}

/**
 * If the array is not empty, divide it into two subarrays, sort them and merge them
 *
 * @param l left index of the subarray of arr to be sorted
 * @param r the rightmost index of the array
 */
void mergeSort(int l, int r) {
    cont += 1;
    if (l < r) {
        cont += 8;
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        // Merge the sorted subarrays
        merge(l, m, r);
    }
}

/**
 * It counts the number of connections each node has
 *
 * @param nodos number of nodes
 */
void contar_conexiones(int nodos) {
    cont += 2;
    for (int i = 0; i < nodos; i++) {
        cont += 4;
        conexiones[i] = 0;
    }
    cont += 5;
    for (int i = 0; i < nodos - 1; i++) {
        cont += 8;
        indices[i] = i;
        for (int j = i + 1; j < nodos; j++) {
            cont += 5;
            if (matriz[i][j] == 1 && i != j) {
                cont += 4;
                conexiones[i]++;
                conexiones[j]++;
            }
        }
    }
    indices[nodos - 1] = nodos - 1;
}

/**
 * If the queue is not full, add the vertex to the end of the queue
 *
 * @param vertex The vertex to be inserted into the queue.
 */
void insert_queue(int vertex) { // T(n)=7
    if (rear == MAX_NODOS - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1) /*If queue is initially empty */
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

/**
 * If the front of the queue is -1 or greater than the rear of the queue, then the queue is empty
 *
 * @return 1 or 0
 */
int isEmpty_queue() { // T(n)=2
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

/**
 * If the queue is empty, exit the program. Otherwise, delete the first item in the queue and return it
 *
 * @return The first item in the queue.
 */
int delete_queue() { // T(n)=5
    int del_item;
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow\n");
        exit(1);
    }

    del_item = queue[front];
    front = front + 1;
    return del_item;
}

/**
 * BFS(v, component_Num, nodos) is a function that takes a vertex v, a component number component_Num,
 * and the number of vertices in the graph nodos, and performs a breadth-first search on the graph,
 * marking all vertices in the same connected component as v with the component number component_Num
 *
 * @param v the vertex to start the BFS from
 * @param component_Num The number of the component that is being visited.
 * @param nodos number of nodes
 */
int BFS(int v, int nodos) {
    int i;

    cont += 10;
    insert_queue(v);
    state[v] = waiting;
    colores[v] = 0;

    cont += 3;
    while (!isEmpty_queue()) {
        cont += 12;
        v = delete_queue();
        state[v] = visited;

        for (i = 0; i < nodos; i++) {
            cont += 5;
            /* Check for adjacent unvisited vertices */
            if (matriz[v][i] == 1 && colores[v] == colores[i])
                return 0;

            cont += 2;
            if (matriz[v][i] == 1 && state[i] == initial) {
                cont += 10;
                insert_queue(i);
                colores[i] = 1 - colores[v];
                state[i] = waiting;
            }
        }
    }
    return 1;
}

void two_coloring(int nodos) {
    int v;
    front = -1;
    rear = -1;

    cont += 4;
    for (v = 0; v < nodos; v++) {
        cont += 5;
        state[v] = initial;
        queue[v] = 0;
    }
    cont += 1;
    int o = BFS(0, nodos);

    cont += 2;
    for (v = 0; v < nodos; v++) {
        cont += 5;
        if (state[v] == initial && o == 1) {
            cont += 1;
            o = BFS(v, nodos);
        }
    }
    cont += 1;
    sin_conflictos = o;
}

void prueba_densidad() {
    clock_t start;
    clock_t end;
    double cpu_time_used;

    int nodos = 100;
    int arcos = nodos * (nodos - 1) / 2;

    crear_grafo(nodos, arcos);
    for (; arcos >= 0; arcos -= 1) {
        sin_conflictos = 0L;
        cont = 0;

        contar_conexiones(nodos);
        mergeSort(0, nodos - 1); // De 0 a NODOS-1
        cont = 0;                // No contar en el analisis

        for (int i = 0; i < nodos; i++) { // Control de retroceso en asignaciónes, -1, no asignado aun
            colores[i] = -1;
        }

        start = clock();
        two_coloring(nodos);
        end = clock();

        // imprimir_grafo (nodos) ;	// si se genera primera solucion

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Nodos %d\t Arcos %3d\t Soluciones %llu\t Tiempo %3f\t Testigos %llu \n",
               nodos, arcos, sin_conflictos, cpu_time_used, cont);
        borrar_arco_aleatorio(nodos, arcos);
    }
}

void explora_2_colorabilidad(double arcospornodo, int mnodos, int step) {
    int nodos;

    clock_t start;
    clock_t end;
    double cpu_time_used;

    construye_grafo(mnodos, arcospornodo);

    for (nodos = 0; nodos <= mnodos; nodos += step) {
        sin_conflictos = 0L;
        for (int j = 0; j < nodos; j++) {
            colores[j] = -1;
        }

        //contar_conexiones(nodos);
        //mergeSort(0, nodos - 1); // De 0 a NODOS-1
        cont = 0;                // No contar en el analisis

        start = clock();
        two_coloring(nodos);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Nodos %3d\t Solucion %llu\t Tiempo %3f\t Testigos %llu \n",
               nodos, sin_conflictos, cpu_time_used, cont);
    }
}

int main(void) {
    srand(3);

    crear_matriz();

    int n = 2000;
    explora_2_colorabilidad((0 * n * (n - 1) / 2) / n, n, 10);
    // prueba_densidad();

    for (int i = 0; i < MAX_NODOS; i++) {
        free(matriz[i]);
    }

    exit(0);
}