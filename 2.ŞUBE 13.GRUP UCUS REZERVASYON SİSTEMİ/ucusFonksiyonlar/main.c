#include "C:\Users\90546\CLionProjects\ucusRezervassyonH\main.h"

void dosyadanOku(struct UcusBilgisi ucuslar[]) {
    FILE *dosya = fopen(DOSYA_ADI, "r");
    if (dosya != NULL) {
        for (int i = 0; i < MAX_UCUS; ++i) {
            fscanf(dosya, "%d %s %s %s %d %d %d %d", &ucuslar[i].ucusNo, ucuslar[i].kalkisSehir, ucuslar[i].varisSehir,
                   ucuslar[i].kalkisSaat, &ucuslar[i].sure, &ucuslar[i].biletFiyati, &ucuslar[i].rezervasyonDurumu, &ucuslar[i].kullaniciID);
        }
        fclose(dosya);
    }
}

void dosyayaYaz(struct UcusBilgisi ucuslar[]) {
    FILE *dosya = fopen(DOSYA_ADI, "w");
    if (dosya != NULL) {
        for (int i = 0; i < MAX_UCUS; ++i) {
            fprintf(dosya, "%d %s %s %s %d %d %d %d\n", ucuslar[i].ucusNo, ucuslar[i].kalkisSehir, ucuslar[i].varisSehir,
                    ucuslar[i].kalkisSaat, ucuslar[i].sure, ucuslar[i].biletFiyati, ucuslar[i].rezervasyonDurumu, ucuslar[i].kullaniciID);
        }
        fclose(dosya);
    }
}

void rezervasyonIptal(struct UcusBilgisi ucuslar[], int ucusNo, int kullaniciID) {
    if (ucusNo < 1 || ucusNo > MAX_UCUS) {
        printf("Gecersiz ucus numarasi.\n");
        return;
    }

    if (ucuslar[ucusNo - 1].rezervasyonDurumu == 1 && ucuslar[ucusNo - 1].kullaniciID == kullaniciID) {
        ucuslar[ucusNo - 1].rezervasyonDurumu = 0;
        ucuslar[ucusNo - 1].kullaniciID = -1;
        printf("Rezervasyon iptal edildi.\n");
    } else {
        printf("Bu ucus zaten bos veya bu kullaniciya ait degil.\n");
    }
}

void rezervasyonlariGoruntule(struct UcusBilgisi ucuslar[]) {
    printf("\nUcus Numarasi\tKalkis Sehri\tVaris Sehri\tKalkis Saati\tDakika\tBilet Fiyati\tDurumu\tKullanici ID\n");
    for (int i = 0; i < MAX_UCUS; ++i) {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t%d\t\t%s\t\t%d\n", ucuslar[i].ucusNo, ucuslar[i].kalkisSehir, ucuslar[i].varisSehir,
               ucuslar[i].kalkisSaat, ucuslar[i].sure, ucuslar[i].biletFiyati, (ucuslar[i].rezervasyonDurumu == 0) ? "Bos" : "Dolu", ucuslar[i].kullaniciID);
    }
}

void biletAl(struct UcusBilgisi ucuslar[], int kullaniciID) {
    printf("\nBilet Al\n");

    printf("\nUygun Ucuslar:\n");
    printf("Ucus Numarasi\tKalkis Sehri\tVaris Sehri\tKalkis Saati\tSure\tBilet Fiyati\n");
    for (int i = 0; i < MAX_UCUS; ++i) {
        if (ucuslar[i].rezervasyonDurumu == 0) {
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t%d\n", ucuslar[i].ucusNo, ucuslar[i].kalkisSehir, ucuslar[i].varisSehir,
                   ucuslar[i].kalkisSaat, ucuslar[i].sure, ucuslar[i].biletFiyati);
        }
    }

    int secilenUcus;
    printf("\nBilet almak istediginiz ucus numarasini girin: ");
    scanf("%d", &secilenUcus);

    if (secilenUcus < 1 || secilenUcus > MAX_UCUS || ucuslar[secilenUcus - 1].rezervasyonDurumu != 0) {
        printf("Gecersiz ucus numarasi veya secilen ucus dolu.\n");
        return;
    }

    char kartNumarasi[17];
    char sonKullanmaTarihi[6];
    int guvenlikKodu;

    printf("Kart Numarasi (16 haneli): ");
    scanf("%s", kartNumarasi);

    printf("Son Kullanma Tarihi (MM/YY): ");
    scanf("%s", sonKullanmaTarihi);

    printf("Guvenlik Kodu: ");
    scanf("%d", &guvenlikKodu);

    printf("Islem basariyla tamamlandi. Bilet satin alindi.\n");

    ucuslar[secilenUcus - 1].kullaniciID = kullaniciID;
    ucuslar[secilenUcus - 1].rezervasyonDurumu = 1;
}


