#include <stdio.h>
#include <stdlib.h> //system() fonksiyonu için lazım

int main() {
    int secim;

    printf("C Sistem Yonetim Araci\n");
    printf("1.Sistem Bilgilerini Goster (OS, Kernel vb.)\n");
    printf("2.Aktif Calisan Surecleri Listele (Top 10)\n");
    printf("3.Ag Baglantilarini Kontrol Et (Ping)\n");
    printf("Seciminiz: ");
    scanf("%d", &secim);

    printf("\nIslem Sonucu\n");

    if (secim == 1) {
        
        #ifdef _WIN32
            system("systeminfo | findstr /B /C:\"OS Name\" /C:\"OS Version\""); //Windows için systeminfo
        #else
            system("uname -a");//Linux/macOS için uname -a
        #endif
    } 
    else if (secim == 2) {
        #ifdef _WIN32
            system("tasklist | help"); //Windows süreç listesi
        #else
            system("ps aux | head -n 10"); //Linux/macOS süreç listesi
        #endif
    } 
    else if (secim == 3) {
        //Google'a bir ping atıp bağlantıyı test eder
        #ifdef _WIN32
            system("ping www.google.com -n 4");
        #else
            system("ping -c 4 www.google.com");
        #endif
    } 
    else {
        printf("Gecersiz secim!\n");
    }

    printf("\n----------------------\n");
    return 0;
}