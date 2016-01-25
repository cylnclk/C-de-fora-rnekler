
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>

char harf[][26]={{'a','A'},{'b','B'},{'c','C'},{'d','D'},{'e','E'},{'f','F'},{'g','G'},{'h','H'},{'i','I'},{'j','J'},{'k','K'},{'l','L'},{'m','M'},{'n','N'},{'o','O'},{'p','P'},{'q','Q'},{'r','R'},{'s','S'},{'t','T'},{'u','U'},{'v','V'},{'w','W'},{'x','X'},{'y','Y'},{'z','Z'}};
////alfabe iki boyutlu bir diziye atandý....

int AsilacakIndis(char kelime[]); ///kullanýlan fonksiyonlarýn prototipi
int KelimeAgirligi(char kelime[]);///kullanýlan fonksiyonlarýn prototipi
int KelimeAgirligi(char kelime);///kullanýlan fonksiyonlarýn prototipi

FILE *dd,*cc;
int main() ///main fonksiyonu....
{
	char GdosyaAdi[15]="words.txt",CdosyaAdý[20]="balance.txt"; //dosya isimleri diziye atandý....
	char kelime[30];
	char GdosyaAdiHarf[20],CdosyaAdýHarf[20];
	int DengeliKelimeSayisi = 0;
	printf("Giris Dosyasi:"); //kullanýcýdan giriþ dosyasý alýnýyor....
	scanf("%s",&GdosyaAdiHarf);
	printf("Cikis Dosyasi:"); //kullanýcýdan çýkýþ dosyasý alýnýyor....
	scanf("%s",&CdosyaAdýHarf);

	while(strcmp(GdosyaAdiHarf,GdosyaAdi)!=0 && strcmp(CdosyaAdýHarf,CdosyaAdý)!=0) //girilen dosya isimleri kontrolü yapýlýyor....
	{
	printf("Lutfen Dosya Isimlerini Dogru Giriniz!!!!\n");
	printf("Giris Dosyasi:");
	scanf("%s",&GdosyaAdiHarf);
	printf("Cikis Dosyasi:");
	scanf("%s",&CdosyaAdýHarf);
	
	}


	cc=fopen("F:\\balance.txt","a"); // Dengeli kelimeleri eklenecek dosya açýldý
	//dosyayý okuma ///
	dd=fopen(GdosyaAdi,"r");
	
	if(dd==NULL)
	{ 
		printf("Sistem Dosyayý bulamýyor!!!!:");
	}
	else
	{
		while ((fscanf(dd, "%s", &kelime) != EOF)) //dosya sonuna kadar kelimeler okunuyor....
		{
			
			if (AsilacakIndis(kelime) != -1)///asilacakindis fonksiyonu  çagýrlýyor.. -1 den farklý ise 
			{
				DengeliKelimeSayisi++;///dengeli kelime sayýsý 1 artýrýr.
				fprintf(cc,"%2s:   %c(%d) %3d\n",kelime,kelime[AsilacakIndis(kelime)],(AsilacakIndis(kelime)),KelimeAgirligi(kelime)); ///çýkýs dosyasýna dengeli kelimeler ekleniyor

			}
			
		}
		printf("%s Dosyasinda %d Adet Dengeli Kelime var.Dengeli Kelimeler  %s  Dosyasina kayit edildi",GdosyaAdi,DengeliKelimeSayisi,CdosyaAdýHarf);
	
		
	}
	
	
	fclose(dd); //açýlan dosya kapandý..
	fclose(cc); //açýlan dosya kapandý..
	getch();
	
}

///AGIRLIK  BULAN FONKSÝYON.....

int KelimeAgirligi(char kelime[]) ///agýrlýk buluyor.....kelimeyi dizi olarak alýyor
{
	int agirlik=0;
	int b=strlen(kelime);
	for (int i = 0; i <b; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (kelime[i]==harf[j][0] || kelime[i]==harf[j][1])
			{
				agirlik=agirlik+(j+1); /// j+1 dedik çünkü A 1 den baþlýyor...
			}
		}
	}
	
	return agirlik;

}
int KelimeAgirligi(char kelime) ///agýrlýk buluyor.....(harf harf buluyor..)
{
	int agirlik=0;
	for (int j = 0; j < 26; j++)
		{
			if (kelime==harf[j][0] || kelime==harf[j][1])
			{
				agirlik=agirlik+(j+1); /// j+1 dedik çünkü A 1 den baþlýyor...
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
	if (strlen(kelime) < 3) ///kelimenin boyutu 3 den küçük olmamalý denge için...
	{
		return -1;
	}
	else
	{
		int SolBoyut = (int)strlen(kelime) / 2; ///kelimenin boyutunun yarýsý alýnýyor(kelimenin sol kýsmýnýn boyutu)
		int SagBoyut = (int)strlen(kelime) - SolBoyut;///kelimenin diðer yarýsýnýn boyutu hesaplanýyor(kelimenin sag kýsmýnýn boyutu)
		while (sayac < strlen(kelime))
		{
			sayac++;
			SolSayac = SolBoyut; ///sol sayaca, solun boyutu atýlýyor..
			for (int i = strlen(kelime) - 1; i >= strlen(kelime) / 2; i--)
			{
				SolToplam = SolToplam + (KelimeAgirligi(kelime[i])) * (SolSayac--); ///sol kýsmýnýn toplam agýrlýgýný buluyor...
			}
			SagSayac = SagBoyut; ///sag sayaca,sag boyut atýlýyor...
			for (int j = 0; j < strlen(kelime) / 2; j++)
			{
				SagToplam = SagToplam + (KelimeAgirligi(kelime[j])*(--SagSayac)); ///sag kýsmýn toplam agýrlýgý bulunuyor...
				indis = SagBoyut - 1; 
			}
			if (SolToplam == SagToplam) ///eger eþit ise çýkýyor
			{
				break;
			}
			else if (SolToplam < SagToplam) ///solun toplamý sagdan küçükse denge saga dogru kayar..
			{
				SolBoyut =SolBoyut + 1;/// sol boyutu 1 artýrýp 
				SagBoyut =SagBoyut - 1;///sag boyut 1 azalýr...
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
				if (SolBoyut == 0 || SagBoyut == 0) ///eþit ise döngüden çýk...
				{
					indis = -1;
					break;
				}
			}
		}
		if (SolToplam == 0 || SagToplam == 0) ///eþit ise döngüden çýk..
		{
			indis = -1;
		}
	}
	return indis; //indisi donderir
}