//%%writefile grafosbfs.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODOS 20000

#define initial 1
#define waiting 2
#define visited 3
int state[MAX_NODOS]; /*can be initial, waiting or visited*/
int queue[MAX_NODOS], front = -1, rear = -1;
int cont = 0;

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

    nb += (long) nbytes;
    nv++;

    return p;
}

/* crea matriz: vector de punteros a vectores en memoria dinámica */
void crear_matriz() {
    int i;

    for (i = 0; i < MAX_NODOS; i++) {
        matriz[i] = (int *) mi_malloc(sizeof(int) * MAX_NODOS);
    }
}

/* 0 indica que no hay arista entre los nodos i-j */
void inicializar_grafo(int nodos) {
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

/* imprime nodos del grafo en diagonal y en las intersecciones si son adyacentes */
/* imprime antes el número de grafo inconexo (cluster) si está disponible */
void imprimir_grafo(int nodos) {
    int i;
    int j;

    for (i = 0; i < nodos; i++) {
        fprintf(fptr, "%4d, c:%3d: ", i, clusters[i]);
        for (j = 0; j < nodos; j++) {
            if (i == j) { // marca diagonal con punto
                // printf (".", i);
                fprintf(fptr, ".");
            } else if (matriz[i][j] == 1) { // si i-j son adyacentes
                fprintf(fptr, "+");           // marca intersección i-j con +
            } else
                fprintf(fptr, " ");
        }
        fprintf(fptr, "\n");
    }
}

/* para propagar recursivamente una marca (número de cluster) a los nodos adyacentes del nodo n */
void propagar_marcaR(int nodos, int n, int n_cluster) { // T(n) = 1 + 2 + n(3 + 3 + 1 + T(n-1))
    int j;
    cont += 2;
    for (j = 0; j < nodos; j++) { // T(n) = 2 + n*(3+3+1+1+T(n-1)); T(n) = 2 + n*(8 + T(n-1))
        cont += 3;
        cont += 3;
        if (n != j && matriz[n][j] != 0 && clusters[j] == -1) {
            cont += 2;
            clusters[j] = n_cluster;
            propagar_marcaR(nodos, j, n_cluster);
        }
    }
}

/* wrapper para propagar una marca (número de cluster) a los nodos adyacentes  */
int contar_clusters(int nodos) { // T(n)=3 + 2 + n(3+ 1) + 1 + 2 + n(3 + 1 + 2 + LLAMADA + 1) + 1
    int i;
    int n_cluster;
    cont += 2;
    for (i = 0; i < nodos; i++) { // T(n) = 2 + n*(1+2+1) ; T(n) = 4n + 2
        cont += 4;
        clusters[i] = -1; // todos los nodos sin marcar para empezar
    }
    n_cluster = 0;
    cont += 3;
    for (i = 0; i < nodos; i++) { // T(n) = 2 + n*(1+2+1+1+1+__+2) = 2 + n*(8+__)
        cont += 4;
        if (clusters[i] == -1) {   // nodo i no está marcado ==> es nodo de grafo inconexo
            cont += 4;
            clusters[i] = n_cluster; // nuevo cluster y propagar a sus adyacentes
            propagar_marcaR(nodos, i, n_cluster);
            n_cluster++;
        }
    }

    return n_cluster;
}

void analizar_grafo(int nodos) {
    int arcos;
    int cluster0;
    int cluster1;

    clock_t start, startT;
    clock_t end, endT;
    double cpu_time_used, cpu_time_usedT;

    arcos = nodos * (nodos - 1) / 2;

    crear_grafo(nodos, arcos); // crea grafo completo

    start = clock();
    cluster0 = 0;

    do {
        startT = clock();
        cluster1 = contar_clusters(nodos);
        endT = clock();
        cpu_time_usedT = ((double) (endT - startT)) / CLOCKS_PER_SEC;
        printf("Arcos\t %4d\t Tiempo\t %3f \n", arcos, cpu_time_usedT);
        if (cluster1 > cluster0) { // imprime solo si aparece nuevo cluster
            cpu_time_usedT = ((double) (endT - startT)) / CLOCKS_PER_SEC;
            printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, cluster1,
                   cpu_time_usedT);
            fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, cluster1,
                    cpu_time_usedT);
            cluster0 = cluster1;
            imprimir_grafo(nodos);
        } // elimina un arco al azar:
        arcos = borrar_arco_aleatorio(nodos, arcos);
    } while (arcos > 0);

    startT = clock();
    cluster1 = contar_clusters(nodos);
    endT = clock();
    if (cluster1 > cluster0) { // imprime solo si aparece nuevo cluster
        cpu_time_usedT = ((double) (endT - startT)) / CLOCKS_PER_SEC;
        printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, cluster1, cpu_time_usedT);
        fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, cluster1,
                cpu_time_usedT);
        cluster0 = cluster1;
        imprimir_grafo(nodos);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo %3f \n", cpu_time_used);
    fprintf(fptr, "Tiempo %3f \n", cpu_time_used);
}

void prueba_empirico(int nodos) {
    int arcos;
    int cluster1;

    clock_t start;
    clock_t end;
    double cpu_time_used;

    arcos = MAX_NODOS * (MAX_NODOS - 1) / 4;
    crear_grafo(MAX_NODOS, arcos);

    for (int i = nodos; i < MAX_NODOS; i += 10) {
        // Medir tiempo de contar clusteres
        start = clock();
        cluster1 = contar_clusters(i);
        end = clock();

        // Guardar info
        arcos = i * (i - 1) / 4;
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, cluster1, cpu_time_used);
        fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, cluster1,
                cpu_time_used);
    }
}

int maximo(int a, int b) {
    if (a > b)
        return (a);
    else
        return (b);
}

int warshall(int nodos) {
    int i, j, k;
    for (k = 0; k <= nodos; k++)
        for (i = 0; i <= nodos; i++)
            for (j = 0; j <= nodos; j++)
                matriz[i][j] = maximo(matriz[i][j], matriz[i][k] && matriz[k][j]);

    int n_cluster = 1;
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

void prueba_empirico_w(int nodos) {
    int arcos;
    int cluster1;

    clock_t start;
    clock_t end;
    double cpu_time_used;

    for (int i = nodos; i < MAX_NODOS; i++) {
        arcos = i * (i - 1) / 4;
        crear_grafo(i, arcos);

        // Medir tiempo de contar clusteres
        start = clock();
        cluster1 = warshall(i);
        end = clock();

        // Guardar info
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, cluster1, cpu_time_used);
        fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, cluster1,
                cpu_time_used);
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

void prueba_empirico_bfs(int nodos) {
    int arcos;
    int cluster1;

    clock_t start;
    clock_t end;
    double cpu_time_used;

    arcos = MAX_NODOS * (MAX_NODOS - 1) / 4;
    crear_grafo(MAX_NODOS, arcos);

    for (int i = nodos; i < MAX_NODOS; i += 10) {
        // Medir tiempo de contar clusteres
        start = clock();
        cluster1 = BF_Traversal(i);
        end = clock();

        // Guardar info
        arcos = i * (i - 1) / 4;
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, cluster1, cpu_time_used);
        fprintf(fptr, "Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", i, arcos, cluster1,
                cpu_time_used);
    }
}

int main(void) {
    srand(3);

    fptr = fopen("output_grafos.txt", "w");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    crear_matriz();
    /* Datos para diferencias finitas
    crear_grafo(MAX_NODOS, MAX_NODOS * (MAX_NODOS - 1) / 2);
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j <= i; j++) {
            clusters[i] = -1;
        }
        cont = 0;
        //propagar_marcaR(i, 0, 1);
        contar_clusters(i);
        printf("%d\n", cont);
    }
    */
    // analizar_grafo(512);
    // prueba_empirico(0);
    prueba_empirico_bfs(0);
    // prueba_empirico_w(0);

    fclose(fptr);
    for (int i = 0; i < MAX_NODOS; i++) {
        free(matriz[i]);
    }

    exit(0);
}