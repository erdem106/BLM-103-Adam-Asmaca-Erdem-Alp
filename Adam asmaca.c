#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <string.h>

#include <locale.h>

#define Karaktersayisi 64

void adamCiz(int durum) {

	switch (durum) {

	case 9:
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|      / \\     \n");
		printf("|__             \n");
		break;
	case 8:
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|      /        \n");
		printf("|__             \n");
		printf("\nBir tane yanlis yapma hakkin kaldi!\n");
		break;
	case 7:
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|               \n");
		printf("|__             \n");
		printf("\nSon 2 yanlis hakkiniz kaldi.\n");
		break;
	case 6:
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|       \n");
		printf("|       |       \n");
		printf("|               \n");
		printf("|__             \n");
		printf("\nSon 3 yanlis yapma hakkiniz kaldi.\n");
		break;
	case 5:
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|               \n");
		printf("|__             \n");

		break;
	case 4:
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");
		break;
	case 3:
		printf(" __________     \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");
		break;
	case 2:
		printf("                \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");
		printf("\nilk yanlisinizi yaptiniz.\n");
		break;
	case 1:
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf(" __             \n");
		break;

	default:

		printf("\nAdaminiz Henuz Asilmaya Baslamadi!\n\n");

		break;
	}
}

void Tire(char* dizi, int boyut)
{

	int i;

	for (i = 0; i <= boyut; i++)
	{

		dizi[i] = ' _';
	}

	dizi[i] = '\0';

}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Turkish");
	
	srand(time(NULL));

	char harf;

	char* harfler;

	int x, dogru = 0, bulunanharfler = 0, adam = 0, uzunluk, kelime;

	char torba[Karaktersayisi][10];

	int Okelime = 0;


	FILE* fp;

	int sonuc;

	if ((sonuc = fopen_s(&fp, "kelimeler.txt", "r")) != 0)
	{

		printf("Hata!\n");

		return 0;

	}

	char giren[64];


    while (fgets(giren, 63, fp)) 
	{
		int x = 0;

		for (x = 0; giren[x] != '\0'; x++) 
		{
          
			torba[Okelime][x] = giren[x];
		
		}
		
		torba[Okelime][x] = '\0';

		printf("\ngiren: %s \ntorba[%d]: %s \n ", giren, Okelime, torba[Okelime]);

		Okelime++;

	}

	printf("\nToplam Okunan Kelime Sayisi : %d\n", Okelime);

	fclose(fp);

    
	
	kelime = rand() % Okelime;

	uzunluk = strlen(torba[kelime] - 1);

	harfler = (char*)malloc((uzunluk * sizeof(char));

	if (harfler == NULL) { printf("Bellekte yer ayirma hatasi!"); return 0; }

	Tire(harfler, uzunluk);

	printf("%s", torba[kelime]);

    while (adam != 9 && bulunanharfler != uzunluk)
	{
		printf("\nHarf :  ");

		char c;

		scanf_s("%c", &harf);

		scanf_s("%c", &c);

		for (x = 0; x <= uzunluk; x++)
		{
			if (harf == torba[kelime][x])
			{
				harfler[x] = harf;

				bulunanharfler++;

				dogru = 1;

			}
		}


		if (dogru != 1)
		{

			adam++;

		}
		else
		{

			dogru = 0;

		}

		printf("\nAdamin Son Durumu:    \n");

        adamCiz(adam);


        printf("\nKelimenin Son Durum:   \n");

		puts(harfler);



        
		printf("\n--------------------------------------------\n");

	}


	printf("\n\n");

	if (adam != 9)
	{


		printf("Tebrikler! Kelimeyi Dogru Bildiniz.\n");

	}

	else
	{

		printf("Olmadi Bir Dahaki Sefere.\n");

		printf("Kelime: %s", torba[kelime]);


	}

    free(harfler);
    return 0;
}



