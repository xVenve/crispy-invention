//%%writefile grafos2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODOS 2000

int cont = 0;
int *matriz[MAX_NODOS];
int clusters[MAX_NODOS];

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

/* para propagar recursivamente una marca (número de cluster) a los nodos adyacentes del nodo n */
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


void construye_grafo(int nodos, double arcospornodo) {
    int arcos;

    arcos = nodos * arcospornodo;
    crear_grafo(nodos, arcos); // crea grafo maximo
    imprimir_grafo(nodos);
}

/* funci�n que construye un grafo de 100 nodos con una cantidad de arcos
determinada por arcospornodo
Posteriormente comienza a analizar la colorabilidad de subgrafos
de tama�o 10, 11, .., hasta 100.
De esa forma la proporcion de arcos por nodo es aproximadamente la que se esperaba
aunque hay variabilidad.
Se cronometra la duracion de la generacion exhaustiva de todas las asignaciones de color poisbles
sean v�lidas o no  */
void explora_k_colorabilidad(int k, double arcospornodo) {
    int nodos;
    double proporcion;

    clock_t start;
    clock_t end;
    double cpu_time_used;

    construye_grafo(100, arcospornodo);

    for (nodos = 10; nodos < 100; nodos++) {
        sin_conflictos = 0L;
        con_conflictos = 0L;

        start = clock();

        asigna_colores(0, nodos, k);

        end = clock();

        // imprimir_grafo (nodos) ;	// si se genera primera solucion

        proporcion = (double) sin_conflictos;
        proporcion /= (double) con_conflictos;

        printf("Nodos %3d, Soluciones %llu, Fallidas %llu, total %llu, proporcion %lf\n", nodos, sin_conflictos,
               con_conflictos, sin_conflictos + con_conflictos, proporcion);

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tiempo %3f \n", cpu_time_used);
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
    explora_k_colorabilidad(3, 4.0); // exploramos con k=3 y 4 arcos por nodo

    for (int i = 0; i < MAX_NODOS; i++) {
        free(matriz[i]);
    }

    exit(0);
}