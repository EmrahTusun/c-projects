#include <stdio.h>
#include <stdlib.h> //malloc, realloc ve free için kullanıyorum

typedef struct {
    int *veriler;     //Sayıların tutulacağı adres (Pointer)
    int adet;         //sayı miktarı
    int kapasite;     //Toplam ayrılan yer
} DinamikDizi;

void diziHazirla(DinamikDizi *d, int ilkKapasite) {
    d->veriler = (int *)malloc(ilkKapasite * sizeof(int));  //Hafızadan yer isteme (malloc)
    
    d->adet = 0; //Henüz içi boş
    d->kapasite = ilkKapasite; //Kapasiteyi belirle
}

void elemanEkle(DinamikDizi *d, int yeniSayi) {
    if (d->adet == d->kapasite) { //Yer kalmadıysa kapasiteyi artır
        d->kapasite *= 2; //Kapasiteyi 2 katına çıkar

        d->veriler = (int *)realloc(d->veriler, d->kapasite * sizeof(int)); //Mevcut yeri genişlet (realloc)
        printf("\nKapasite yetmedi, %d yapildi.\n", d->kapasite);
    }
    
    d->veriler[d->adet] = yeniSayi;
    d->adet++;
}

void diziyiSil(DinamikDizi *d) {
    free(d->veriler); //Bilgisayardan kiraladığımız yeri iade et
    d->veriler = NULL;
    d->adet = 0;
    d->kapasite = 0;
}

int main() {
    DinamikDizi listem;
    diziHazirla(&listem, 2); //1. Diziyi 2 kişilik yerle başlatalım
    
    for (int i = 1; i <= 5; i++) {  //2. Döngüyle 5 tane sayı ekleyelim
        elemanEkle(&listem, i * 10);
        printf("Sayi eklendi: %d | Mevcut Adet: %d | Toplam Kapasite: %d\n", 
                i * 10, listem.adet, listem.kapasite);
    }
    //3. Ekrana yazdıralım
    printf("\nSonuc: ");
    for (int i = 0; i < listem.adet; i++) {
        printf("%d ", listem.veriler[i]);
    }
    //4. İşi bitince belleği temizle
    diziyiSil(&listem);
    printf("\n\nBellek temizlendi. Proje tamam!");

    return 0;
}