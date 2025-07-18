#include <stdio.h>
#include <stdlib.h>

/*
Ceydanur Gezer
*/



int gemi_sayi=3;

//STRUCTLARIM
typedef struct //Gemi_bilgilerini iceren struct
{
    char gemi_adi[30];
    int gemi_no;
    float gemi_kapasitesi;
    float gemi_yuku;//Gemi yükü
    float kesilen_ucret;
    float ucret_yuk;
    float ucret_kalma;
    float kalacagi_saat;
} GM;

typedef struct //Liman bilgilerini içeren struct
{
    int gemi_sayisi;
    GM* Gemiler;
} LM;


//FONSİYONLARIM
void menu(LM* liman);//Ana menü ilk çıkan menu
void menu_yuk(LM* liman);//Yuk bırakma ve Limandan yük alma ile ilgili menü
void menu_ucret(LM* liman);//Gemi yük ve kalma ücretleri
LM* liman_olustur(LM* liman);//limanda bulunan gemilerle liman oluşturduk
LM* gemi_ekleme(LM* liman);//Limana yeni gemi ekleme
void yuk_alma(LM* liman);//gemiye limandan yük ekleme
void yuk_birakma(LM* liman);//gemiden limana yük bırakma
void listele(LM* liman);//limanda bulunan ve sonradan eklenen gemileri yazdırma
void yuk_ucret(LM* liman);//gemide bulunan yuk miktarina göre ucret hesaplama
void kalma_ucreti(LM* liman);//gemide kalınan süreye göre ucret hesaplama fonksiyonu
void gemi_silme(LM* liman);//liimandan gemi silen fonksiyon
void gemi_bilgileri_guncelleme(LM* liman);//limandaki gemi bilgilerini güncelleme

int main()
{
    LM* liman;
    liman=liman_olustur(liman);
    menu(liman);

    free(liman->Gemiler);
    free(liman);

    return 0;
}

void menu(LM* liman)
{
    int secim;

    do
    {
        system("cls");
        printf("\t\t\t\t**********************************************\n");
        printf("\t\t\t\t --MERSIN ULUSLARARASI LIMANINA HOSGELDINIZ--\n");
        printf("\t\t\t\t**********************************************\n\n");
        printf("-----------------MENU----------------\n");
        printf("1.Gemi Girisi\n"); //Limana gemi gelince gemi bilgileri ekleme
        printf("2.Yuk Islemleri(Yuk Alma/Yuk Birakma)\n"); //Gemiden limana yuk bırakıp alma islemi
        printf("3.Liman Gemi Listesi\n");//Limandaki gemilerin listesi
        printf("4.Ucret Bilgisi Ogrenme(Yuk Ucreti/Limanda Kalma Ucreti/Toplam Ucret)\n");
        printf("5.Limandan Gemi Cikisi Gerceklestirme\n");//Limandan geminin ayrılması
        printf("6.Liman Gemi Bilgileri Guncelleme\n");
        printf("7.Cikis\n");
        printf("-------------------------------------\n");

        printf("Luften menuden bir secim yapiniz(1-7): \n");
        scanf("%d", &secim);
    }
    while(secim>7 || secim<1);

    switch(secim)
    {
    case 1:
        gemi_ekleme(liman);
        break;
    case 2:
        menu_yuk(liman);
        break;
    case 3:
        listele(liman);
        break;
    case 4:
        menu_ucret(liman);
        break;
    case 5:
        gemi_silme(liman);
        break;
    case 6:
        gemi_bilgileri_guncelleme(liman);
        break;
    case 7:
        printf("Sistemden cikisiniz yapiliyor...");
        break;
    }
}

void menu_yuk(LM* liman)
{
    int secim1;

    do
    {
        system("cls");
        printf("\t\t\t\t**********************************************\n");
        printf("\t\t\t\t ---------MERSIN ULUSLARARASI LIMANI---------\n");
        printf("\t\t\t\t**********************************************\n\n");
        printf("--------------YUK ISLEMLERI---------------\n");
        printf("1.Limandan yuk alma\n");
        printf("2.Limana Yuk Birakma\n");
        printf("3.Ana menuye geri don\n");
        printf("------------------------------------------\n");

        printf("Luften bir islem seciniz: \n");
        scanf("%d", &secim1);
    }
    while(secim1>3 || secim1<1);

    switch(secim1)
    {
    case 1:
        yuk_alma(liman);
        break;
    case 2:
        yuk_birakma(liman);
        break;
    case 3:
        menu(liman);
        break;
    }

}

void menu_ucret(LM* liman)
{
    int secim1;

    do
    {
        system("cls");
        printf("\t\t\t\t**********************************************\n");
        printf("\t\t\t\t ---------MERSIN ULUSLARARASI LIMANI---------\n");
        printf("\t\t\t\t**********************************************\n\n");
        printf("---------------UCRET BILGISI--------------\n");
        printf("1.Yuk Ucreti Ogrenme\n");
        printf("2.Limanda Kalma Ucreti Ogrenme\n");
        printf("3.Ana menuye geri don\n");
        printf("------------------------------------------\n");

        printf("Luften bir islem seciniz: \n");
        scanf("%d", &secim1);
    }
    while(secim1>4 || secim1<1);

    switch(secim1)
    {
    case 1:
        yuk_ucret(liman);
        break;
    case 2:
        kalma_ucreti(liman);
        break;
    case 3:
        menu(liman);
        break;
    }
}

LM* liman_olustur(LM* liman)
{
    liman = malloc(sizeof(LM));

    if (liman == NULL)
    {
        printf("Yetersiz bellek!!");
        exit(1);
    }

    liman->gemi_sayisi = gemi_sayi;

    liman->Gemiler = malloc(liman->gemi_sayisi * sizeof(GM));
    if (liman->Gemiler == NULL)
    {
        printf("Yetersiz bellek!!");
        exit(1);
    }

    liman->Gemiler[0] = (GM)
    {"TITANIK", 140, 15.0, 7.0, 0.0,0.0,0.0,3.5
    };
    liman->Gemiler[1] = (GM)
    {"BANDIRMA", 145, 12.0, 8.5, 0.0,0.0,0.0,2.0
    };
    liman->Gemiler[2] = (GM)
    {"CNG", 148, 10.0, 5.75, 0.0,0.0,0.0,4.0
    };

    for(int i=0; i<liman->gemi_sayisi; i++)
    {
        liman->Gemiler[i];
    }

    return liman;
}

LM* gemi_ekleme(LM* liman)
{
    system("cls");
    int yeni_gemi,secim,i,j;
    int eskigemi_sayisi;

    printf("---------GEMI GIRISI(GEMI EKLEME)---------\n\n");
    printf("Kac tane gemi girisi yapacaginizi giriniz:\n");
    scanf("%d", &yeni_gemi);

    eskigemi_sayisi=liman->gemi_sayisi;
    liman->gemi_sayisi += yeni_gemi;

    liman->Gemiler = realloc(liman->Gemiler, liman->gemi_sayisi * sizeof(GM));

    if (liman->Gemiler == NULL)
    {
        printf("Yetersiz bellek!!");
        exit(1);
    }

    for (i = eskigemi_sayisi; i < liman->gemi_sayisi; i++)
    {
        printf("Geminin adini giriniz:\n");
        scanf("%s", (liman->Gemiler + i)->gemi_adi);
        printf("Geminin nosunu giriniz:\n");
        scanf("%d", &(liman->Gemiler + i)->gemi_no);
        for(j=0; j<i; j++)
        {
            if((liman->Gemiler+j)->gemi_no==(liman->Gemiler + i)->gemi_no)
            {
                printf("Eslesen gemi numarasi lutfen bilgileri tekrardan giriniz\n");
                printf("------------------------------------------\n\n");
                break;
            }

        }
        if(j!=i)
        {
            i--;
            continue;
        }
        printf("Geminin kapasitesini giriniz:\n");
        scanf("%f", &(liman->Gemiler + i)->gemi_kapasitesi);
        printf("Geminin yukunu giriniz:\n");
        scanf("%f", &(liman->Gemiler + i)->gemi_yuku);
        if((liman->Gemiler + i)->gemi_kapasitesi<(liman->Gemiler + i)->gemi_yuku)
        {
            printf("Kapasiteyi asan yuk miktari girdiniz\n");
            printf("Lutfen bilgileri tekrardan giriniz\n");
            printf("------------------------------------------\n\n");
            i--;
            continue;
        }
        (liman->Gemiler + i)->ucret_yuk =0.0 ;
        (liman->Gemiler + i)->ucret_kalma = 0.0;
        (liman->Gemiler + i)->kesilen_ucret = 0.0;
        printf("Geminin kalicagi saati giriniz:\n");
        scanf("%f", &(liman->Gemiler + i)->kalacagi_saat);
        liman_olustur(liman);


        printf("------------------------------------------\n");
        printf("GEMI BASARILI BI SEKILDE EKLENMISTIR\n");
        printf("------------------------------------------\n");



    }

    printf("Ana menuye donmek icin 0 giriniz: \n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 0:
        menu(liman);
        break;
    default:
        printf("Yanlis sacim yaptiniz.");
        break;
    }

    return liman;
}

void yuk_alma(LM* liman)
{
    system("cls");
    int gemi_no,gemi_bul=-1,secim;
    float yeni_yuk;

    printf("---------------YUK ALMA ISLEMI-----------------\n");
    printf("Yuk eklemek istediginiz geminin nosunu giriniz:\n");
    scanf("%d",&gemi_no);

    for(int i=0; i<liman->gemi_sayisi; i++)
    {
        if((liman->Gemiler + i)->gemi_no==gemi_no)
        {
            gemi_bul=i;
            break;
        }
    }

    if(gemi_bul!=-1)
    {
        printf("Gemi adi: %s\n",(liman->Gemiler+gemi_bul)->gemi_adi);
        printf("Eklemek istediginiz yuk miktarini giriniz: \n");
        scanf("%f",&yeni_yuk);
        (liman->Gemiler +gemi_bul)->gemi_yuku+=yeni_yuk;

        if((liman->Gemiler +gemi_bul)->gemi_yuku<=(liman->Gemiler+gemi_bul)->gemi_kapasitesi)
        {
            printf("Yuk gemiye basarili bir sekilde yerlestirilmistir\n");
        }
        else
        {
            printf("Gemi kapasitesini astiginiz icin yuk yerlestirilemedi!!\n");
        }
    }

    printf("----------------------------------------------\n");
    printf("Ana menuye donmek icin 0 giriniz: \n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 0:
        menu(liman);
        break;
    default:
        printf("Yanlis sacim yaptiniz.\n");
        break;
    }

}

void yuk_birakma(LM* liman)
{
    system("cls");
    int gemi_no,gemi_bul=-1,secim;
    float yuk_eksiltme;

    printf("---------------YUK BIRAKMA ISLEMI-----------------\n");
    printf("Limana yuk birakmak istediginiz geminin nosunu giriniz:\n");
    scanf("%d",&gemi_no);

    for(int i=0; i<liman->gemi_sayisi; i++)
    {
        if((liman->Gemiler + i)->gemi_no==gemi_no)
        {
            gemi_bul=i;
            break;
        }
    }
    if(gemi_bul!=-1)
    {
        printf("Gemi adi: %s\n",(liman->Gemiler+gemi_bul)->gemi_adi);
        printf("Cikarmak istediginiz yuk miktarini giriniz: \n");
        scanf("%f",&yuk_eksiltme);
        if((liman->Gemiler +gemi_bul)->gemi_yuku>=yuk_eksiltme)
        {
            (liman->Gemiler +gemi_bul)->gemi_yuku-=yuk_eksiltme;
            printf("Yuk Limana basarili bir sekilde birakilmistir.\n");
        }
        else
        {
            printf("Gemide bulunan yuk miktarindan fazla girdiniz!!\n");
        }

    }

    printf("--------------------------------------------------\n");
    printf("Ana menuye donmek icin 0 giriniz: \n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 0:
        menu(liman);
        break;
    default:
        printf("Yanlis sacim yaptiniz.\n");
        break;
    }

}
void listele(LM* liman)
{
    int secim;
    system("cls");
    printf("------------------------------------------------LIMAN GEMI LISTESI---------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-11s | %-10s | %-16s | %-10s | %-12s | %-10s | %-10s | %-13s|\n", "GEMI ADI", "GEMI NO", "GEMI KAPASITESI", "GEMI YUKU", "YUK UCRETI", "KALMA UCRETI", "TOPLAM UCRET", "KALINAN SAAT");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < liman->gemi_sayisi; i++)
    {
        printf("| %-11s | %-10d | %-16.2f | %-10.2f | %-12.2f | %-10.2f | %-11.2f | %-13.2f|\n",
               (liman->Gemiler + i)->gemi_adi,
               (liman->Gemiler + i)->gemi_no,
               (liman->Gemiler + i)->gemi_kapasitesi,
               (liman->Gemiler + i)->gemi_yuku,
               (liman->Gemiler + i)->ucret_yuk,
               (liman->Gemiler + i)->ucret_kalma,
               (liman->Gemiler + i)->kesilen_ucret=(liman->Gemiler + i)->ucret_kalma+(liman->Gemiler + i)->ucret_yuk,
               (liman->Gemiler + i)->kalacagi_saat);
        printf("----------------------------------------------------------------------------------------------------------------------\n");
    }
    printf("Ana menuye donmek icin 0 giriniz: \n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 0:
        menu(liman);
        break;
    default:
        printf("Yanlis sacim yaptiniz.");
        break;
    }
}

void yuk_ucret(LM* liman)
{
    system("cls");
    int gemi_no,gemi_bul=-1,secim;
    float ucret=0;

    printf("-----------------YUK UCRETI HESAPLAMA----------------\n");
    printf("Yuk ucretini ogrenmek istediginiz geminin nosunu giriniz:\n");
    scanf("%d",&gemi_no);

    for(int i=0; i<liman->gemi_sayisi; i++)
    {
        if((liman->Gemiler+i)->gemi_no==gemi_no)
        {
            gemi_bul=i;
            break;
        }
    }
    if(gemi_bul!=-1)
    {
        printf("Gemi adi: %s\n",(liman->Gemiler+gemi_bul)->gemi_adi);

        if((liman->Gemiler +gemi_bul)->gemi_yuku<=5)
        {
            ucret=100;
        }
        else if((liman->Gemiler +gemi_bul)->gemi_yuku<=10)
        {
            ucret=150;
        }
        else
        {
            ucret=200;
        }

        (liman->Gemiler+gemi_bul)->ucret_yuk=(liman->Gemiler +gemi_bul)->gemi_yuku*ucret;
        printf("Gemi ucreti hesaplanmistir\n");
        printf("%s adli Geminin Yuk Ucreti: %.2f \n",(liman->Gemiler+gemi_bul)->gemi_adi,(liman->Gemiler+gemi_bul)->ucret_yuk);

    }
    printf("-----------------------------------------------------\n");
    printf("Ana menuye donmek icin 0 giriniz: \n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 0:
        menu(liman);
        break;
    default:
        printf("Yanlis sacim yaptiniz.\n");
        break;
    }


}

void kalma_ucreti(LM* liman)
{
    system("cls");
    int gemi_no,gemi_bul=-1,secim;
    float ucret=0;

    printf("-----------------KALMA UCRETI HESAPLAMA----------------\n");
    printf("Yuk ucretini ogrenmek istediginiz geminin nosunu giriniz:\n");
    scanf("%d",&gemi_no);

    for(int i=0; i<liman->gemi_sayisi; i++)
    {
        if((liman->Gemiler+i)->gemi_no==gemi_no)
        {
            gemi_bul=i;
            break;
        }
    }
    if(gemi_bul!=-1)
    {
        printf("Gemi adi: %s\n",(liman->Gemiler+gemi_bul)->gemi_adi);

        if((liman->Gemiler +gemi_bul)->kalacagi_saat<=1)
        {
            ucret=50;
        }
        else if((liman->Gemiler +gemi_bul)->kalacagi_saat<=6)
        {
            ucret=75;
        }
        else if((liman->Gemiler +gemi_bul)->kalacagi_saat<=12)
        {
            ucret=125;
        }
        else if((liman->Gemiler +gemi_bul)->kalacagi_saat<=24)
        {
            ucret=175;
        }
        else
        {
            ucret=300;

        }

        (liman->Gemiler+gemi_bul)->ucret_kalma=(liman->Gemiler +gemi_bul)->kalacagi_saat*ucret;

        printf("Geminin Limanda kalma ucreti hesaplanmistir\n");
        printf("%s adli Geminin Limanda kalma ucreti: %.2f \n",(liman->Gemiler+gemi_bul)->gemi_adi,(liman->Gemiler+gemi_bul)->ucret_kalma);
    }
    printf("-------------------------------------------------------\n");
    printf("Ana menuye donmek icin 0 giriniz: \n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 0:
        menu(liman);
        break;
    default:
        printf("Yanlis sacim yaptiniz.\n");
        break;
    }

}



void gemi_silme(LM* liman)
{
    system("cls");
    int gemi_no,gemi_bul=-1,secim;

    printf("Limandan cikisini yapmak istediginiz geminin nosunu giriniz:\n");
    scanf("%d",&gemi_no);

    for(int i=0; i<liman->gemi_sayisi; i++)
    {
        if((liman->Gemiler+i)->gemi_no==gemi_no)
        {
            gemi_bul=i;
            break;
        }
    }

    if(gemi_bul!=-1)
    {
        for(int j=gemi_bul; j<liman->gemi_sayisi-1; j++)
        {
            liman->Gemiler[j]=liman->Gemiler[j+1];
        }

        liman->gemi_sayisi--;
        liman->Gemiler=realloc(liman->Gemiler,liman->gemi_sayisi*sizeof(GM));
        if (liman->Gemiler == NULL)
        {
            printf("Yetersiz bellek!!");
            exit(1);
        }

        printf("Gemi basarili bir sekilde limandan cikis yapmistir\n");
    }
    else
    {
        printf("Girdiginiz bilgide bir gemi bulunamadi!!\n");
    }

    printf("------------------------------------------\n");
    printf("Ana menuye donmek icin 0 giriniz: \n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 0:
        menu(liman);
        break;
    default:
        printf("Yanlis sacim yaptiniz.\n");
        break;
    }

}

void gemi_bilgileri_guncelleme(LM* liman)
{
    system("cls");
    int gemi_no,gemi_bul=-1,secim;

    printf("Bilgilerini guncellemek istediginiz geminin nosunu giriniz:\n");
    scanf("%d",&gemi_no);

    for(int i=0; i<liman->gemi_sayisi; i++)
    {
        if((liman->Gemiler+i)->gemi_no==gemi_no)
        {
            gemi_bul=i;
            break;
        }
    }
    if(gemi_bul!=-1)
    {
        printf("Yeni gemi adini giriniz:\n");
        scanf("%s",(liman->Gemiler+gemi_bul)->gemi_adi);
        printf("Yeni gemi kapasitesi giriniz: \n");
        scanf("%f",&(liman->Gemiler+gemi_bul)->gemi_kapasitesi);
        printf("Geminin Limanda kalma saatinin guncel halini giriniz: \n");
        scanf("%f",&(liman->Gemiler+gemi_bul)->kalacagi_saat);

        printf("--------------------------------------------\n");
        printf("Gemi bilgileri basarili bir sekilde guncellenmistir.\n");
    }
    else
    {
        printf("Girdiginiz bilgiler de bir gemi bulunamadi!!\n");
    }

    printf("------------------------------------------\n");
    printf("Ana menuye donmek icin 0 giriniz: \n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 0:
        menu(liman);
        break;
    default:
        printf("Yanlis sacim yaptiniz.\n");
        break;
    }

}
