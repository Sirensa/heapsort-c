#include <stdio.h>
#include <stdlib.h>

// Fonction pour échanger deux éléments
void echanger(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Fonction pour maintenir la propriété du tas
void tas(int t[], int n, int max) {
    int i = max;
    int g = 2 * i + 1;
    int d = 2 * i + 2;

    if (g < n && t[g] > t[max]) {
        max = g;
    }
    if (d < n && t[d] > t[max]) {
        max = d;
    }
    if (max != i) {
        echanger(&t[i], &t[max]);
        tas(t, n, max);
    }
}

// Fonction de tri par tas
void tritas(int t[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        tas(t, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        echanger(&t[0], &t[i]);
        tas(t, i, 0);
    }
}

// Fonction pour remplir le tableau
void affichage(int t[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Entrer l'élément %d: ", i + 1);
        scanf("%d", &t[i]);
    }
}

// Fonction principale
int main() {
    int n;
    printf("Entrer la taille du tableau : ");
    scanf("%d", &n);

    int *t = (int *)malloc(n * sizeof(int));
    if (t == NULL) {
        printf("La mémoire n'a pas été allouée.\n");
        exit(0);
    }

    printf("Entrer les éléments du tableau :\n");
    affichage(t, n);

    tritas(t, n);

    printf("Tableau après le tri :\n");
    for (int i = 0; i < n; i++) {
        printf("Élément %d : %d\n", i + 1, t[i]);
    }

    free(t);
    return 0;
}
