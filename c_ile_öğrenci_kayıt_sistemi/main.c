#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Turkish");

  // Deðiþken tanýmlamalarý
  int sayac;
  int kul_ad;
  int sifre;
  int son_sec;
  char linse[256];
	char ogrn_bilgi[50];
  FILE *fp;
  char secim;

  printf("OKUL SÝSTEMÝNE HOÞ GELDÝNÝZ \nLÜTFEN SÝZE UYGUN OLAN SEÇENEÐÝ AÞAÐIDAN SEÇÝNÝZ \n");
  printf("1-YÖNETÝCÝ GÝRÝÞ\n2- ÖÐRENCÝ SÝSTEMÝ GÝRÝÞ\n");
  scanf("%d", &secim);

  switch (secim) {
  case 1:
    printf("YÖNETÝCÝ GÝRÝÞ EKRANINA HOÞ GELDÝNÝZ\n LÜTFEN AÞAÐIDAKÝ BÝLGÝLERÝ GÝRÝNÝZ\n");

    printf("KULLANICI ADINIZ:  ");
    scanf("%d", &kul_ad);
    printf("ÞÝFRENÝZ : ");
    scanf("%d", &sifre);

    if (kul_ad == 1234 && sifre == 1234) {
      printf("GÝRÝÞ BAÞARILI YÖNLENDÝRÝLÝYORSUNUZn");
      printf("----YAPMAK ÝSTEDÝÐÝNÝZ ÝÞLEMÝ AÞAÐIDAKÝ MENÜDEN SEÇÝNÝZ----\n");
      printf("1- YENÝ ÖÐRENCÝ KAYDI \n 2- ÖÐRENCÝ KAYDI SÝL\n 3-TÜM ÖÐRENCÝLERÝ LÝSTELE\n 4- ÖÐRENCÝ BUL\n");
      scanf("%d", &son_sec);

      switch (son_sec) {
      case 3:
        fp = fopen("ogrenciler.txt", "r");

        if (fp == NULL) {
          printf("Dosya açýlamadý!\n");
          return 1;
        }

        while (fgets(linse, sizeof(linse), fp) != NULL) {
          // Her seferinde sýfýrlayýn
          linse[0] = '\0';

          // Satýrý okuyun ve ekleyin
          fgets(linse, sizeof(linse), fp);
          strcat(linse, "\n");

          // Satýrý ekrana yazdýrýn
          printf("%s", linse);
        }

        fclose(fp);

        break;
        case 4 : 
       
         printf("ÖÐRENCÝ BÝLGÝ ARAMA SÝSTEMÝNE HOÞ GELDÝNÝZ\n");
        printf("ÖÐRENCÝ HAKKINDA BÝLGÝ GÝRÝNÝZ (ÖRN: OGRENCÝ NO / ÖÐRENCÝ ADI VB)\n");
        scanf("%s", &ogrn_bilgi);

        fp = fopen("ogrenciler.txt", "r");

        if (fp == NULL) {
          printf("Dosya açýlamadý!\n");
          return 1;
        }

        while (fgets(linse, sizeof(linse), fp) != NULL) {
          if (strstr(linse, ogrn_bilgi)) {
            printf("%s", linse);
          }
        }

        fclose(fp);

        break;

      default:
        printf("YANLIÞ SEÇÝM YAPTINIZ");
        return (19);

        break;
      }
    } else {
      printf("YANLIÞ KULLANICI ADI VEYA ÞÝFRE");
    }

    break;
  case 2:
  	printf("ÖÐRENCÝ BÝLGÝ EKRANINA HOÞ GELDÝNÝZ\n");
        printf("ÖÐRENCÝ NUMARANIZI GÝRÝNÝZ\n");
        scanf("%s", &ogrn_bilgi);

        fp = fopen("ogrenciler.txt", "r");

        if (fp == NULL) {
          printf("Dosya açýlamadý!\n");
          return 1;
        }

        while (fgets(linse, sizeof(linse), fp) != NULL) {
          if (strstr(linse, ogrn_bilgi)) {
            printf("%s", linse);
          }
        }

        fclose(fp);

        break;
    break;
  }

  return 0;
}

