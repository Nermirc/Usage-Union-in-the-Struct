#include <stdio.h>
#include <stdlib.h>

struct degerTip {
    int tip; // tip degeri
    union {
        char kar;   // karakter
        float sayi; // sayi
    } bir;           // birlesim
};

int main() {
    struct degerTip degerler[20];
    char satir;
    int i = -1;
    float ortalama = 0.0;
    int j;
    int n = 0;

    while (1) {
        i++;
        printf("Lutfen bir tamsayi giriniz (0 veya 1). Cikmak icin farkli bir karakter giriniz.\n");
        if (scanf("%d", &degerler[i].tip) != 1) {
            // Break the loop if the input is not a valid integer
            break;
        }
        scanf("%c", &satir);

        if (degerler[i].tip == 1) {
            printf("Karakter giriniz.\n");
            scanf(" %c", &degerler[i].bir.kar); // Add a space before %c
        } else if (degerler[i].tip == 0) {
            printf("Reel sayi giriniz.\n");
            scanf("%f", &degerler[i].bir.sayi);
            ortalama += degerler[i].bir.sayi;
            n++;
        }
    }

    if (n > 0) {
        ortalama = ortalama / n;
        printf("Reel sayilarin ortalamasi : %f", ortalama);
    } else {
        printf("Girilen degerler arasinda reel sayi bulunamadi.\n");
    }

    return 0;
}

