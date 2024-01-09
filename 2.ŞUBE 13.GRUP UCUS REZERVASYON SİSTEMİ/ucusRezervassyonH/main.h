#ifndef UCUSREZERVE
#define UCUSREZERVE

#include <stdio.h>
#include <stdlib.h>

#define MAX_UCUS 4
#define DOSYA_ADI "rezervasyon7.txt"

struct UcusBilgisi {
    int ucusNo;
    char kalkisSehir[20];
    char varisSehir[20];
    char kalkisSaat[10];   // Uçuş saati için yeni eklendi
    int sure;               // Uçuş süresi (dakika cinsinden) için yeni eklendi
    int biletFiyati;
    int rezervasyonDurumu;
    int kullaniciID;
};

// Fonksiyon prototipleri
void dosyadanOku(struct UcusBilgisi ucuslar[]);
void dosyayaYaz(struct UcusBilgisi ucuslar[]);
void rezervasyonIptal(struct UcusBilgisi ucuslar[], int ucusNo, int kullaniciID);
void rezervasyonlariGoruntule(struct UcusBilgisi ucuslar[]);
void biletAl(struct UcusBilgisi ucuslar[], int kullaniciID);

#endif