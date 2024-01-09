#include "C:\Users\90546\CLionProjects\ucusRezervassyonH\main.h"
#include "C:\Users\90546\CLionProjects\ucusFonksiyonlar\main.c"

int main() {
    struct UcusBilgisi ucuslar[MAX_UCUS] = {
            {1, "Ankara", " Izmir", "08:00", 60, 100, 0, -1},
            {2, "Antalya", "Ankara", "10:30", 120, 200, 0, -1},
            {3, "Trabzon", "Antalya", "14:15", 90, 300, 0, -1},
            {4, "Ankara", "Denizli", "16:45", 75, 400, 0, -1},
    };

    dosyadanOku(ucuslar);

    int secim, ucusNo, kullaniciID;
    do {
        printf("\n1. Rezervasyon Iptal Et\n2. Rezervasyonlari Goruntule\n3. Bilet Al\n0. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Iptal etmek istediginiz ucus numarasini girin: ");
                scanf("%d", &ucusNo);
                printf("Kullanici ID'sini girin: ");
                scanf("%d", &kullaniciID);
                rezervasyonIptal(ucuslar, ucusNo, kullaniciID);
                break;
            case 2:
                rezervasyonlariGoruntule(ucuslar);
                break;
            case 3:
                printf("Kullanici ID'sini girin: ");
                scanf("%d", &kullaniciID);
                biletAl(ucuslar, kullaniciID);
                break;
            case 0:
                dosyayaYaz(ucuslar);
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } while (secim != 0);

    return 0;
}

