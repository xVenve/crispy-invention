//%%writefile grafos2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODOS 2000

unsigned long long cont = 0;
int *matriz[MAX_NODOS];
int clusters[MAX_NODOS];

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
 * It creates a matrix of MAX_NODOS x MAX_NODOS, where each element is an integer
 */
void crear_matriz() {
    int i;

    for (i = 0; i < MAX_NODOS; i++) {
        matriz[i] = (int *) mi_malloc(sizeof(int) * MAX_NODOS);
    }
}

/**
 * It initializes a matrix to all zeros, not conected
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
 * It takes a node and a cluster number, and marks all the nodes connected to the first node with the
 * second number
 * 
 * @param nodos number of nodes
 * @param n number of nodes
 * @param n_cluster the cluster number
 */
void propagar_marcaR(int nodos, int n, int n_cluster) { // T(n) = 2 + n(3 + 3 + 2 + T(n-1)) = 2 + n*(8 + T(n-1))
    int j;
    cont += 2;
    for (j = 0; j < nodos; j++) {
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
int contar_clusters(int nodos) { // T(n)= 2 + n(4) + 3 + n(6 + LLAMADA + 2)
    int i;
    int n_cluster;
    cont += 2;
    for (i = 0; i < nodos; i++) {
        cont += 4;
        clusters[i] = -1; // todos los nodos sin marcar para empezar
    }
    n_cluster = 0;
    cont += 3;
    for (i = 0; i < nodos; i++) {
        cont += 4;
        if (clusters[i] == -1) { // nodo i no está marcado ==> es nodo de grafo inconexo
            cont += 4;
            clusters[i] = n_cluster; // nuevo cluster y propagar a sus adyacentes
            propagar_marcaR(nodos, i, n_cluster);
            n_cluster++;
        }
    }

    return n_cluster;
}

/**
 * It creates a complete graph, then removes edges at random until there are no edges left
 * 
 * @param nodos number of nodes
 */
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
            cluster0 = cluster1;
        } // elimina un arco al azar:
        arcos = borrar_arco_aleatorio(nodos, arcos);
    } while (arcos > 0);

    startT = clock();
    cluster1 = contar_clusters(nodos);
    endT = clock();
    if (cluster1 > cluster0) { // imprime solo si aparece nuevo cluster
        cpu_time_usedT = ((double) (endT - startT)) / CLOCKS_PER_SEC;
        printf("Nodos\t %4d\t Arcos\t %4d\t Clusters\t %3d\t Tiempo \t %3f\n", nodos, arcos, cluster1, cpu_time_usedT);
        cluster0 = cluster1;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo %3f \n", cpu_time_used);
}


int asignaciones[MAX_NODOS];

unsigned long long sin_conflictos = 0L;
unsigned long long con_conflictos = 0L;


/* imprime nodos del grafo en diagonal y en las intersecciones si son adyacentes */
/* imprime antes el número de grafo inconexo (cluster) si está disponible y el color asignado, si lo hay */

/**
 * It prints the adjacency matrix of the graph
 * 
 * @param nodos number of nodes
 */
void imprimir_grafo(int nodos) {
    int i;
    int j;

    for (i = 0; i < nodos; i++) {
        printf("%4d, clust:%3d:, col:%1d ", i, clusters[i], asignaciones[i]);
        for (j = 0; j < nodos; j++) {
            if (i == j) {            // marca diagonal con punto
                printf(".");
            } else if (matriz[i][j] == 1) {    // si i-j son adyacentes
                printf("+");        // marca intersección i-j con +
            } else printf(" ");
        }
        printf("\n");
    }
}

/* dada una asignacion de colores en asignaciones comprueba si dos nodos i, j
 estan conectados y en tal caso no coinciden en colores.                        */
int comprueba_conflictos(int nodos) { // T(n)=1+3+(n-1)(4+3+ p(3+1+1+2))
    int i;
    int j;
    long int cf = 0L;
    cont += 4;
    for (i = 0; i < nodos - 1; i++) {
        cont += 7;
        for (j = i + 1; j < nodos; j++) {
            cont += 4;
            if (matriz[i][j] == 1) {
                cont += 1;
                if (asignaciones[i] == asignaciones[j]) {
                    cont += 2;
                    cf++;
                }
            }
        }
    }
    return cf;
}

/* funcion recursiva para generar todas las asignaciones posibles.
Cuando llega al nodo hoja llama a comprueba_conflictos para
contabilizar si se trata de una soluci�n v�lida o fallida          */
/* Se ha realizado de forma recursiva como paso previo para usar backtracking */

/**
 * It assigns colors to a graph and counts the number of solutions with and without conflicts
 * 
 * @param ind index of the node to be colored
 * @param nodos number of nodes
 * @param k number of colors
 */
void asigna_colores(int ind, int nodos, int k) { // T(n)= 1+ max(1+LLAMADA_CONFLICTOS+1+2; 2+k(3+3+LLAMADA_ASIGNAR))
    int j;
    int cf;
    cont += 1;
    if (ind >= nodos) {
        cf = comprueba_conflictos(nodos);
        if (cf == 0) {
            sin_conflictos++;
        } else {
            con_conflictos++;
        }
        cont += 4;
    } else {
        cont += 2;
        for (j = 0; j < k; j++) {
            cont += 6;
            asignaciones[ind] = j;
            asigna_colores(ind + 1, nodos, k);

            // if (sin_conflictos >= 1) return ;	// Ñapa para obtener primera solucion
        }
    }
}

/**
 * It tries to color a graph with k colors, and it stops when it finds the first solution
 * 
 * @param ind the index of the node we're currently coloring
 * @param nodos number of nodes
 * @param k number of colors
 * 
 * @return The number of times the function is called.
 */
void asigna_colores_backtracking(int ind, int nodos, int k) {
    int j;
    int cf;
    cont += 1;
    if (ind >= nodos) {
        cf = comprueba_conflictos(nodos);
        if (cf == 0) {
            sin_conflictos++;
        } else {
            con_conflictos++;
        }
        cont += 4;
    } else {
        cont += 2;
        for (j = 0; j < k; j++) {
            cont += 7;
            asignaciones[ind] = j;
            asigna_colores_backtracking(ind + 1, nodos, k);
            if (sin_conflictos >= 1)
                return;    // Ha ocurrido la primera asignacion completa sin conflicto, acabará de volver de la condición base de la recursión.
        }
    }
}

/**
 * It creates a graph with a given number of nodes and a given number of arcs per node
 * 
 * @param nodos number of nodes
 * @param arcospornodo the number of arcs per node
 */
void construye_grafo(int nodos, double arcospornodo) {
    int arcos;

    arcos = nodos * arcospornodo;
    crear_grafo(nodos, arcos); // crea grafo maximo
    //imprimir_grafo(nodos);
}

/* funci�n que construye un grafo de 100 nodos con una cantidad de arcos
determinada por arcospornodo
Posteriormente comienza a analizar la colorabilidad de subgrafos
de tama�o 10, 11, .., hasta 100.
De esa forma la proporcion de arcos por nodo es aproximadamente la que se esperaba
aunque hay variabilidad.
Se cronometra la duracion de la generacion exhaustiva de todas las asignaciones de color poisbles
sean v�lidas o no  */

/**
 * It generates a graph with a given number of nodes and edges per node, and then tries to color the
 * graph with a given number of colors
 * 
 * @param k number of colors
 * @param arcospornodo the number of edges per node
 */
void explora_k_colorabilidad(int k, double arcospornodo) {
    int nodos;
    double proporcion;

    clock_t start;
    clock_t end;
    double cpu_time_used;

    construye_grafo(100, arcospornodo);

    for (nodos = 1; nodos < 23; nodos++) {
        sin_conflictos = 0L;
        con_conflictos = 0L;
        cont = 0;

        start = clock();
        asigna_colores(0, nodos, k);
        end = clock();

        // imprimir_grafo (nodos) ;	// si se genera primera solucion

        proporcion = (double) sin_conflictos;
        proporcion /= (double) con_conflictos;
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Nodos %3d, Soluciones %llu, Fallidas %llu, Total %llu, Proporcion %lf, Tiempo %3f, Testigos %llu \n",
               nodos, sin_conflictos, con_conflictos, sin_conflictos + con_conflictos, proporcion, cpu_time_used, cont);
    }
}

/**
 * It creates a graph with 15 nodes and a number of arcs that varies from 15*14/2 to 0. Then it assigns
 * colors to the nodes and prints the number of solutions, the number of failed attempts, the total
 * number of attempts, the proportion of solutions to failed attempts, the time it took to run the
 * function, and the number of witnesses
 * 
 * @param k number of colors
 */
void prueba_densidad(int k) {
    int arcos;
    double proporcion;

    clock_t start;
    clock_t end;
    double cpu_time_used;

    crear_grafo(15, 15 * 14 / 2);
    for (arcos = 15 * 14 / 2; arcos >= 0; arcos--) {
        sin_conflictos = 0L;
        con_conflictos = 0L;
        cont = 0;

        start = clock();
        asigna_colores(0, 15, k);
        end = clock();

        // imprimir_grafo (nodos) ;	// si se genera primera solucion

        proporcion = (double) sin_conflictos;
        proporcion /= (double) con_conflictos;
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf(
                "Nodos 15, Arcos %3d, Soluciones %llu, Fallidas %llu, Total %llu, Proporcion %lf, Tiempo %3f, Testigos %llu \n",
                arcos, sin_conflictos, con_conflictos, sin_conflictos + con_conflictos, proporcion, cpu_time_used,
                cont);
        borrar_arco_aleatorio(15, arcos);
    }
}


/**
 * It generates a graph with 100 nodes and a given number of arcs per node, then it tries to color the
 * graph with k colors using backtracking to get the first solution
 * 
 * @param k number of colors
 * @param arcospornodo The number of edges per node.
 */
void explora_k_colorabilidad_bt(int k, double arcospornodo) {
    int nodos;
    double proporcion;

    clock_t start;
    clock_t end;
    double cpu_time_used;

    construye_grafo(100, arcospornodo);

    for (nodos = 1; nodos < 100; nodos++) {
        sin_conflictos = 0L;
        con_conflictos = 0L;
        cont = 0;

        start = clock();
        asigna_colores_backtracking(0, nodos, k);
        end = clock();

        // imprimir_grafo (nodos) ;	// si se genera primera solucion

        proporcion = (double) sin_conflictos;
        proporcion /= (double) con_conflictos;
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Nodos %3d, Soluciones %llu, Fallidas %llu, Total %llu, Proporcion %lf, Tiempo %3f, Testigos %llu \n",
               nodos,
               sin_conflictos, con_conflictos, sin_conflictos + con_conflictos, proporcion, cpu_time_used, cont);
    }
}

int main(void) {
    srand(3);

    crear_matriz();
    /*
    for (int i = 1; i < 11; i++) {
      for (int j = 1; j <= i; j++) {
        clusters[i] = -1;
      }
      cont = 0;
      // comprueba_conflictos(i);
      asigna_colores(0, i, 3);
      printf("%d\n", cont);
    }
    */
    //explora_k_colorabilidad(3, 0); // exploramos con k=3 y 0 arcos por nodo
    // prueba_densidad(3);
    explora_k_colorabilidad_bt(3, 0); // exploramos con k=3 y 0 arcos por nodo
    //explora_k_colorabilidad_bt(3, 100*99/2/100); // exploramos con k=3 y completo

    for (int i = 0; i < MAX_NODOS; i++) {
        free(matriz[i]);
    }

    exit(0);
}