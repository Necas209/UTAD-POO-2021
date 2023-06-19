#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // Allow special characters
    setlocale(LC_ALL, "");
    // Open input and output files
    FILE *f1 = fopen("../dados_ent.txt", "r");
    FILE *f2 = fopen("../dados_saida.txt", "w");
    if (f1 == NULL) {
        printf("Error: cannot open file dados_ent.txt\n");
        exit(1);
    }
    if (f2 == NULL) {
        printf("Error: cannot open file dados_saida.txt\n");
        exit(1);
    }
    // Read and write
    int a, b;
    fscanf(f1, "%d %d", &a, &b);
    printf("%d %d\n", a, b);
    fprintf(f2, "This file was changed in class no. 2.\n");
    fprintf(f2, "%d\n", a * a);
    fprintf(f2, "%d\n", b * b);
    // Close files
    fclose(f1);
    fclose(f2);
    system("pause");
    return 0;
}
