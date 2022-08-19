#include <stdio.h>
#include <stdlib.h>

// Kisi Ad ve Soyad bilgilerini almak icin kullanilacak Struct yapisi
struct Kisi
{
    char metin[1000];
    char soyad [1000];
};


//sifreleme yapilan fonksiyon
void sezarSifrele ( char *ptr, int key  )
{
	while( *ptr!='\0' )
	{
		*ptr = *ptr +key  ;
		ptr++;
	}

}


// Sifrenin cozuldugu fonksiyon
void sezarSifreCoz ( char *ptr, int key  )
{
	while( *ptr!='\0' )
	{
		*ptr = *ptr - key  ;
		ptr++;
	}

}


// Girilen ogrenci numarasinin en buyuk asal carpaninin bulundugu fonksiyon
int AsalCarpanBulma(int ogrenciNo) {
   int i, sifre = -1;
   while(ogrenciNo % 2 == 0) {
      sifre = 2;
      ogrenciNo = ogrenciNo/2;
   }
   for(i = 3; i <= sqrt(ogrenciNo); i=i+2){

      while(ogrenciNo % i == 0) {
         sifre = i;
         ogrenciNo = ogrenciNo/i;
      }
   }
   if(ogrenciNo > 2) {
      sifre = ogrenciNo;
   }
   return sifre;
}


int main()
{
		int key  ;
	int sayi;
	struct Kisi kisi_bilgi;


    printf(" Ad Giriniz: ");
    gets(kisi_bilgi.metin);
    printf(" Soyad Giriniz: ");
    gets(kisi_bilgi.soyad);

    // Girilen ad soyad birlstirilip tek kelime haline getirilir
    strcat(kisi_bilgi.metin,kisi_bilgi.soyad);
        sleep (1);
    printf(" Birlestirilmis Metin: %s\n\n\n",kisi_bilgi.metin);


    // sifrelemede ogrenci numarasinin son rakamina ihtiyac oldugu icin
    // Girilen ogrenci numarasinin mod 10'u alinarak son rakami elde edilir
    sleep (1);
    printf(" Sifreleme icin ogrenci numaranizi giriniz:");
    scanf("%d",&sayi);
    key = sayi % 10;


    // birlestirilmis metin ve ogrenci numarasinin son rakami
    // sifreleme fonksiyonuna parametre olarak gonderilir
	sezarSifrele(kisi_bilgi.metin, key);

	//Dosya acilir ve sifrelenmis metin bu dosyaya yazdirilir..
	FILE *dosya;
	int i, no;
	if ((dosya=fopen("SifrelenmisMetin.txt","w"))== NULL){
        printf("dosya acilamadi");
        exit(1);
	}
	fprintf(dosya,"%s\n", kisi_bilgi.metin);
	fclose(dosya);


	printf("\n\n Ad ve Soyadiniz birlestirilip, ogrenci numaranizin son hanesine gore sifrelenmistir.\n");
	printf(" Sifrelenmis metin 'SifrelenmisMetin.txt' dosyasina yazdirilmistir.\n\n");


   int ogrenciNo, Cevap, sifre, sifre2;

   //Ogrenci numarasi alinir ve Asal carpani bulacak fonksiyona parametre olarak yollanir
   printf(" Sifrelenmis metni gorebilmek icin ogrenci numaranizi giriniz:");
   scanf("%d", &ogrenciNo);
   sifre2 = AsalCarpanBulma(ogrenciNo);


   sifresor:
   printf(" \n Sifre olarak ogrenci numaranizin en buyuk asal carpanini giriniz: ");
   scanf("%d", &Cevap);


  // Uygulamanin buldugu sonuc ile kullanicinin girdigi sonuc karsilastirilir
  if (Cevap == sifre2)


            {
                if ( (dosya = fopen("SifrelenmisMetin.txt","r"))==NULL) {
                printf(" Dosya açýlamadý");
                exit(1);
            }

            fscanf(dosya, "%s\t",kisi_bilgi.metin);
            printf("\n\n Sifreli Metin : %s\n\n",kisi_bilgi.metin);

            fclose(dosya);

            sezarSifreCoz (kisi_bilgi.metin, key);

            printf("\n Sifrelenmis metin cozuluyor..." ) ;
            sleep(2);

            printf("\n\n Cozulmus Metin : %s \n", kisi_bilgi.metin ) ;
            printf("\n Ogrenci Numarasi: %d \n", ogrenciNo ) ;

            }

    else
            {
                    printf("\n\n Hatali parola girdiniz!");
                    goto sifresor;

            }






	return 0;
}


