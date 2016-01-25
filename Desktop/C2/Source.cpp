
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>

char harf[][26]={{'a','A'},{'b','B'},{'c','C'},{'d','D'},{'e','E'},{'f','F'},{'g','G'},{'h','H'},{'i','I'},{'j','J'},{'k','K'},{'l','L'},{'m','M'},{'n','N'},{'o','O'},{'p','P'},{'q','Q'},{'r','R'},{'s','S'},{'t','T'},{'u','U'},{'v','V'},{'w','W'},{'x','X'},{'y','Y'},{'z','Z'}};
////alfabe iki boyutlu bir diziye atand�....

int AsilacakIndis(char kelime[]); ///kullan�lan fonksiyonlar�n prototipi
int KelimeAgirligi(char kelime[]);///kullan�lan fonksiyonlar�n prototipi
int KelimeAgirligi(char kelime);///kullan�lan fonksiyonlar�n prototipi

FILE *dd,*cc;
int main() ///main fonksiyonu....
{
	char GdosyaAdi[15]="words.txt",CdosyaAd�[20]="balance.txt"; //dosya isimleri diziye atand�....
	char kelime[30];
	char GdosyaAdiHarf[20],CdosyaAd�Harf[20];
	int DengeliKelimeSayisi = 0;
	printf("Giris Dosyasi:"); //kullan�c�dan giri� dosyas� al�n�yor....
	scanf("%s",&GdosyaAdiHarf);
	printf("Cikis Dosyasi:"); //kullan�c�dan ��k�� dosyas� al�n�yor....
	scanf("%s",&CdosyaAd�Harf);

	while(strcmp(GdosyaAdiHarf,GdosyaAdi)!=0 && strcmp(CdosyaAd�Harf,CdosyaAd�)!=0) //girilen dosya isimleri kontrol� yap�l�yor....
	{
	printf("Lutfen Dosya Isimlerini Dogru Giriniz!!!!\n");
	printf("Giris Dosyasi:");
	scanf("%s",&GdosyaAdiHarf);
	printf("Cikis Dosyasi:");
	scanf("%s",&CdosyaAd�Harf);
	
	}


	cc=fopen("F:\\balance.txt","a"); // Dengeli kelimeleri eklenecek dosya a��ld�
	//dosyay� okuma ///
	dd=fopen(GdosyaAdi,"r");
	
	if(dd==NULL)
	{ 
		printf("Sistem Dosyay� bulam�yor!!!!:");
	}
	else
	{
		while ((fscanf(dd, "%s", &kelime) != EOF)) //dosya sonuna kadar kelimeler okunuyor....
		{
			
			if (AsilacakIndis(kelime) != -1)///asilacakindis fonksiyonu  �ag�rl�yor.. -1 den farkl� ise 
			{
				DengeliKelimeSayisi++;///dengeli kelime say�s� 1 art�r�r.
				fprintf(cc,"%2s:   %c(%d) %3d\n",kelime,kelime[AsilacakIndis(kelime)],(AsilacakIndis(kelime)),KelimeAgirligi(kelime)); ///��k�s dosyas�na dengeli kelimeler ekleniyor

			}
			
		}
		printf("%s Dosyasinda %d Adet Dengeli Kelime var.Dengeli Kelimeler  %s  Dosyasina kayit edildi",GdosyaAdi,DengeliKelimeSayisi,CdosyaAd�Harf);
	
		
	}
	
	
	fclose(dd); //a��lan dosya kapand�..
	fclose(cc); //a��lan dosya kapand�..
	getch();
	
}

///AGIRLIK  BULAN FONKS�YON.....

int KelimeAgirligi(char kelime[]) ///ag�rl�k buluyor.....kelimeyi dizi olarak al�yor
{
	int agirlik=0;
	int b=strlen(kelime);
	for (int i = 0; i <b; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (kelime[i]==harf[j][0] || kelime[i]==harf[j][1])
			{
				agirlik=agirlik+(j+1); /// j+1 dedik ��nk� A 1 den ba�l�yor...
			}
		}
	}
	
	return agirlik;

}
int KelimeAgirligi(char kelime) ///ag�rl�k buluyor.....(harf harf buluyor..)
{
	int agirlik=0;
	for (int j = 0; j < 26; j++)
		{
			if (kelime==harf[j][0] || kelime==harf[j][1])
			{
				agirlik=agirlik+(j+1); /// j+1 dedik ��nk� A 1 den ba�l�yor...
			}
		}
	return agirlik;

}	
	
int AsilacakIndis(char kelime[]) {
	int indis = 0,sayac=0;
	int SolSayac = 0;
	int SagSayac = 0; 
	int SolToplam = 0; 
	int SagToplam = 0;
	if (strlen(kelime) < 3) ///kelimenin boyutu 3 den k���k olmamal� denge i�in...
	{
		return -1;
	}
	else
	{
		int SolBoyut = (int)strlen(kelime) / 2; ///kelimenin boyutunun yar�s� al�n�yor(kelimenin sol k�sm�n�n boyutu)
		int SagBoyut = (int)strlen(kelime) - SolBoyut;///kelimenin di�er yar�s�n�n boyutu hesaplan�yor(kelimenin sag k�sm�n�n boyutu)
		while (sayac < strlen(kelime))
		{
			sayac++;
			SolSayac = SolBoyut; ///sol sayaca, solun boyutu at�l�yor..
			for (int i = strlen(kelime) - 1; i >= strlen(kelime) / 2; i--)
			{
				SolToplam = SolToplam + (KelimeAgirligi(kelime[i])) * (SolSayac--); ///sol k�sm�n�n toplam ag�rl�g�n� buluyor...
			}
			SagSayac = SagBoyut; ///sag sayaca,sag boyut at�l�yor...
			for (int j = 0; j < strlen(kelime) / 2; j++)
			{
				SagToplam = SagToplam + (KelimeAgirligi(kelime[j])*(--SagSayac)); ///sag k�sm�n toplam ag�rl�g� bulunuyor...
				indis = SagBoyut - 1; 
			}
			if (SolToplam == SagToplam) ///eger e�it ise ��k�yor
			{
				break;
			}
			else if (SolToplam < SagToplam) ///solun toplam� sagdan k���kse denge saga dogru kayar..
			{
				SolBoyut =SolBoyut + 1;/// sol boyutu 1 art�r�p 
				SagBoyut =SagBoyut - 1;///sag boyut 1 azal�r...
				SagToplam = 0;
				SolToplam = 0;
				if (SolBoyut == 0 || SagBoyut == 0) 
				{
					indis = -1;
					break;
				}
			}
			else //if (SolToplam > SagToplam)
			{

				SolBoyut =SolBoyut- 1;
				SagBoyut =SagBoyut + 1;
				SagToplam = 0;
				SolToplam = 0;
				if (SolBoyut == 0 || SagBoyut == 0) ///e�it ise d�ng�den ��k...
				{
					indis = -1;
					break;
				}
			}
		}
		if (SolToplam == 0 || SagToplam == 0) ///e�it ise d�ng�den ��k..
		{
			indis = -1;
		}
	}
	return indis; //indisi donderir
}