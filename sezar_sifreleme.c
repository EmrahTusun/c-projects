#include <stdio.h>

int main() {
    FILE *kaynak, *hedef;
    char dosyaAdi[100], ch;
    int secim, anahtar = 3; //Harfleri 3 birim kaydıracak

    printf("Dosya Guvenlik Araci\n");
    printf("1.Dosya Sifrele\n");
    printf("2.Sifre Coz\n");
    printf("Seciminiz: ");
    scanf("%d", &secim);

    printf("islem yapilacak dosya adini girin (ornek: mesaj.txt): ");
    scanf("%s", dosyaAdi);

    kaynak = fopen(dosyaAdi, "r");
    if (secim == 1) {
        hedef = fopen("sifreli_sonuc.txt", "w");
    } else {
        hedef = fopen("cozulmus_sonuc.txt", "w");
        anahtar = -anahtar; //sifre çözerken 3 geri gideceğiz tam tersi
    }

    if (kaynak == NULL || hedef == NULL) {
        printf("Hata:Dosya acilamadi\n");
        return 1;
    }

    while ((ch = fgetc(kaynak)) != EOF) {     //Dosyayı karakter karakter okuma     
        fputc(ch + anahtar, hedef); //ASCII değerini kaydırarak işlemi yap
    }

    printf("islem basariyla tamamlandi.\n");

    fclose(kaynak);
    fclose(hedef);

    return 0;
}