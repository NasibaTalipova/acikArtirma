#include <stdio.h>
#include <stdlib.h>

//struct tanýmlar
typedef struct {
	
    int teklifveren_no;
    double teklif;
    
}Teklif;
//pointer tanýmlama
Teklif* teklifler;

double odemeyi_hesapla(Teklif* teklifler , int teklifveren_sayisi) {
    
	int i = 0;
    double odeme = 0.0;

	//teklifveren_sayisi degiskeninin 0 olduðunda programý sonlandýrýr
	if (teklifveren_sayisi == 0) {
       
        return 0;
    }
    
    //En büyük teklifi bularak odeme deðiþkenine eþitler
	for (i ; i < teklifveren_sayisi; ++i) {
        if (teklifler[i].teklif > odeme) {
            odeme = teklifler[i].teklif;
        }
    }

    return odeme;
}

void acikarttirma(Teklif* teklifler, int teklifveren_sayisi) {
    

   //teklifveren_sayisi'nýn 0 olduðunda programý durdurur    
    	if (teklifveren_sayisi == 0) {
        printf("Teklif veren kimse yok");
        return;
    }
    
    //odeme degiskeni olusturarak fonksiyonu uygular ve eþitler
    double odeme = odemeyi_hesapla(teklifler, teklifveren_sayisi);
    int kazanan_no = 0;
    int i = 0;

   //Kazanan teklifi verenin numarasýný bulur ve yazdýrýr
    for (i ; i < teklifveren_sayisi; ++i) {
        if (teklifler[i].teklif == odeme) {

            kazanan_no += teklifler[i].teklifveren_no;

            printf("%d. Teklifi veren kisi kazandi\n" , kazanan_no);

        }
    }

    printf("\n");
    printf("Teklif ettigi miktar ise: %.2lf TL'idi", odeme);
}

int main() {

    int i = 0;
    int teklifveren_sayisi;
    printf("Teklif veren kac kisi var ? : ");
    scanf("%d", &teklifveren_sayisi);

    //kullanýcýnýn girdiði teklifveren_sayisi kadar hafýzada yer ayrýrýr
    Teklif* teklifler = (Teklif*)malloc(teklifveren_sayisi * sizeof(Teklif));
   
    if (teklifveren_sayisi == NULL) {
    	
        printf(stderr, "Hafiza ayrilamadi.");
        return 1;
    }
       //teklifveren_sayisi deðiþkeninin pozitif bir tamsayý olduðunu kontrol eder
    if (teklifveren_sayisi <= 0) {
        printf("Gecersiz deger girdiniz.");
        return 1;
    }
    
     //Teklif veren kiþilerin tekliflerini alýr
     for (i ; i < teklifveren_sayisi; ++i) {
        teklifler[i].teklifveren_no = i + 1;

        printf("%d. Kisinin teklif ettigi miktari giriniz : ", teklifler[i].teklifveren_no);
        scanf("%lf", &teklifler[i].teklif);
    }
     acikarttirma(teklifler, teklifveren_sayisi);

    // hafýzayý boþaltýr
    free(teklifler);
    return 0;
}
