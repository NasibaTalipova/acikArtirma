#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double teklif;
} Oyuncu;

typedef struct {
    int teklifveren_sayisi;
    Oyuncu *teklifverenler;
} Artirma;

void acikarttirma(Artirma a) {
    double enyuksek_teklif = -1.0;
    int kazanan_no = -1;
    for (int i = 0; i < a.teklifveren_sayisi; i++) {
        if (a.teklifverenler[i].teklif > enyuksek_teklif) {
            enyuksek_teklif = a.teklifverenler[i].teklif;
            kazanan_no = i;
        }
    }
    printf("Kazanan Teklif Sahibi: %d\n", kazanan_no);
    printf("Odeme: %f\n", enyuksek_teklif);
}

int main()  {
    Artirma a;
    a.teklifveren_sayisi = 5;
    a.teklifverenler = (Oyuncu *) malloc(a.teklifveren_sayisi * sizeof(Oyuncu));
    a.teklifverenler[0].teklif = 200.0;
    a.teklifverenler[1].teklif = 250.0;
    a.teklifverenler[2].teklif = 300.0;
    a.teklifverenler[3].teklif = 350.0;
    a.teklifverenler[4].teklif = 400.0;

    acikarttirma(a);

    free(a.teklifverenler);
    
    return 0;
}
