#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () {
    int angka_rahasia, tebak;
    srand(time(NULL));
    angka_rahasia = (rand () % 100) + 1;
    printf("Welcome permainana tebak angka\n");
    printf("Pilih angka 1-100\n");

    do {
        printf("Maukin tebakan mu:\n"); 
        scanf("%d" , &tebak);

        if (tebak < angka_rahasia) {
        printf("Terlallu rendah band!!\n");
        } else if (tebak > angka_rahasia) {
            printf("Terlalu tinggi woy!\n");
        } else {
            printf("selamat anda benar menebak angka %d \n", angka_rahasia);
        } 
    } while (tebak != angka_rahasia);

    return 0;
}