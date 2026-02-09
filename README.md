## 🛠 Proje 1: Dinamik Bellek Yönetimli Dizi (Vector)

### Proje Hakkında
C dilinde diziler varsayılan olarak sabit boyutludur. Bu projede, Python'daki `list` veya C++'taki `std::vector` yapısına benzer, çalışma zamanında (runtime) kapasitesini otomatik olarak artıran bir dinamik dizi yapısı geliştirilmiştir.

### Temel Özellikler
* **Otomatik Genişleme:** Kapasite dolduğunda mevcut boyutu 2 katına çıkarır.
* **Güvenli Bellek Yönetimi:** `malloc` ve `realloc` ile dinamik yer ayırma.
* **Hafıza Temizliği:** Program sonunda `free` ile bellek sızıntılarının (memory leak) önlenmesi.

## Nasıl Çalıştırılır?

1.  **Depoyu Klonlayın:**
    ```bash
    git clone [https://github.com/EmrahTusun/c-projects.git]
    ```
2.  **Derleyin:**
    ```bash
    gcc dinamik_dizi.c -o dinamik_dizi
    ```
3.  **Çalıştırın:**
    ```bash
    ./dinamik_dizi
    ```
