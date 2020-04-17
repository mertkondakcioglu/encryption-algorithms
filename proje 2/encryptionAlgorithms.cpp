// text deneme.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void sifrele_f(string sifre)
{
	for (int i = 0; i < sifre.length(); i++)
	{
		cout<<sifre[i];
		Sleep(75);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL,"Turkish");
	int dizi_ascii[200];
	int dizi_ceaser_fark[200],dizi_ceaser_tut[200];
	int dizi_karisik[200];
	string kullanici,sifre;
	char secim_basagit;
	int secimyaz,rastyaz,secim;
	basla1:
	cout<<"--------------------- ANASAYFA ---------------------"<<endl;
	cout<<"Kullanýcý eklemek için 1'e veya kullanýcýya göre þifre çözmek için 2'ye basýnýz ..."<<endl;
	cout<<"Seçim = ";
	cin>>secim;
	switch (secim)
	{
	case 1:
		{
	rastyaz=rand()%33;
	cout<<"--------------------- KULLANICI EKLEME SAYFASI ---------------------"<<endl;
	cout<<"Kullanýcý = ";
	cin>>kullanici;
	cout<<"Ascii kodlarýna göre þifrelemek için 1'e, Ceaser þifreleme için 2'ye, karýþýk þifreleme için 3'e basýnýz ..."<<endl;
	basla2:
	cout<<"Seçim = ";
	cin>>secimyaz;
		switch (secimyaz)
	{
		case 1:
		{
			cout<<"                         1-ASCÝÝ ÞÝFRELEME SAYFASI"<<endl;
			cout<<"------------------------------------------------------------------------------"<<endl;
			cout<<"Þifre Giriniz ---------------> ";
			cin.ignore();
			getline(cin,sifre);
			string sifre_kod;
			int *sifre_ascii;
			sifre_ascii = new int[sifre.size()];

			for (int i = 0; i < sifre.length(); i++) //þifreleme yapýyoruz.---------------------------------------------------------------------------------------------
			{
				sifre_ascii[i]=(int(sifre[i]) + rastyaz)+17; //int(sifre[i]) sayesinde harfleri ascii koduna çevirdik.
				dizi_ascii[i] = sifre_ascii[i];
				sifre_kod = sifre_kod + to_string(sifre_ascii[i]); // burada to_string(sifre_ascii[i]) sayesinde sifre_ascii[i] deðiþkenini string kabul ettik ve 2 string deðiþkeni topladýk. mesela i=0 i=i+1; gibi.
			}

			sifre=char(65+rand()%26) + sifre_kod + char(97+rand()%26); // burada baþa ve sona 2 harf ekledik ve yine string toplamasý yaptýk.
			cout<<"Þifrenin Þifrelenmiþ Hali ---> ";
			sifrele_f(sifre);
			cout<<endl;
			delete[] sifre_ascii;
			break;
		}
		case 2:
		{
			cout<<"                      2-CEASER ÞÝFRELEME SAYFASI"<<endl;
			cout<<"------------------------------------------------------------------------------"<<endl;
			cout<<"Þifre Giriniz ---------------> ";
			cin.ignore();
			getline(cin,sifre);
			string ceaser_sifre_kod;
			int *ceaser_rast,*ceaser_ascii,*ceaser_tut,*ceaser_fark;
			int ceaser_sayac=0;

			ceaser_rast = new int[sifre.size()];
			ceaser_ascii = new int[sifre.size()];
			ceaser_tut = new int[sifre.size()];
			ceaser_fark = new int[sifre.size()];

			for (int i = 0; i < sifre.length(); i++) //þifreleme yapýyoruz.---------------------------------------------------------------------------------------------
			{
				ceaser_rast[i] = rastyaz;
				if(int(sifre[i]) < 97)
				{
					ceaser_tut[i] = int(sifre[i]);
					dizi_ceaser_tut[i] = ceaser_tut[i];
					ceaser_ascii[i] = int(sifre[i]) + ceaser_rast[i] + (97 - int(sifre[i]));
				}
				else if(int(sifre[i]) > 122)
				{
					ceaser_tut[i] =  int(sifre[i]);
					dizi_ceaser_tut[i] = ceaser_tut[i];
					ceaser_ascii[i] = int(sifre[i]) + ceaser_rast[i] - (int(sifre[i]) - 97);
				}
				else
				{
					ceaser_tut[i] =  int(sifre[i]);
					dizi_ceaser_tut[i] = ceaser_tut[i];
					ceaser_ascii[i] = int(sifre[i]) + ceaser_rast[i];
					if(ceaser_ascii[i] > 122)
					{
						ceaser_fark[ceaser_sayac] = ceaser_ascii[i];
						dizi_ceaser_fark[i] = ceaser_fark[ceaser_sayac];
						ceaser_ascii[i] = 97 + (ceaser_ascii[i] - 122);
						ceaser_sayac=ceaser_sayac+1;
					}
				}
				ceaser_sifre_kod = ceaser_sifre_kod + char(ceaser_ascii[i]);
			}

			sifre = char(65+rand()%26) + ceaser_sifre_kod + char(48+rand()%10);
			cout<<"Þifrenin Þifrelenmiþ Hali ---> ";
			sifrele_f(sifre);
			cout<<endl;

			delete[] ceaser_tut;
			delete[] ceaser_ascii;
			delete[] ceaser_fark;
			delete[] ceaser_rast;
			break;
		}
		case 3:
		{
			cout<<"                       3-KARIÞIK ÞÝFRELEME SAYFASI"<<endl;
			cout<<"------------------------------------------------------------------------------"<<endl;
			cout<<"Þifre Giriniz ---------------> ";
			cin.ignore();
			getline(cin,sifre);
			string karisik_sifre_kod, karisik_harfler;
			int *karisik_rast, *karisik_ascii, *karisik_carpan, karisik_sayac=0;

			karisik_rast = new int[sifre.length()];
			karisik_carpan = new int[sifre.length()];
			karisik_ascii = new int[sifre.length()];
			karisik_harfler=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			for (int i = 0; i < sifre.length(); i++) //þifreleme yapýyoruz.---------------------------------------------------------------------------------------------
			{
				karisik_rast[i] = rastyaz;
				if (int(sifre[i])%2 == 1)
				{
					karisik_ascii[i] = int(sifre[i]) + karisik_rast[i];
					while(true)
					{
						if (karisik_ascii[i] > 26)
						{
							karisik_ascii[i] = karisik_ascii[i] - 26;
							karisik_sayac = karisik_sayac + 1 ;
						}
						else
							break;
					}
					karisik_carpan[i] = karisik_sayac;
					dizi_karisik[i] = karisik_carpan[i];
					karisik_sifre_kod = karisik_sifre_kod + karisik_harfler[karisik_ascii[i]];
					karisik_sayac = 0;
				}
				else
				{
					karisik_ascii[i] = int(sifre[i]) + karisik_rast[i] + 13;
					while(true)
					{
						if (karisik_ascii[i] > 9)
						{
							karisik_ascii[i] = karisik_ascii[i] - 9;
							karisik_sayac = karisik_sayac + 1 ;
						}
						else
							break;
					}
					karisik_carpan[i] = karisik_sayac;
					dizi_karisik[i] = karisik_carpan[i];
					karisik_sifre_kod = karisik_sifre_kod + to_string(karisik_ascii[i]);
					karisik_sayac = 0;
				}
			}

			sifre = karisik_sifre_kod + char(97+rand()%26);

			cout<<"Þifrenin Þifrelenmiþ Hali ---> ";
			sifrele_f(sifre);
			cout<<endl;

			delete[] karisik_ascii;
			delete[] karisik_rast;
			delete[] karisik_carpan;
			break;
		}
		default:
			cout<<"HATA# Lütfen 1 ile 3 arasýnda bir sayi giriniz..."<<endl;
			goto basla2;
	}
	//------------------------------------------------------------------//yazma
	ofstream dosyayaz;
	dosyayaz.open ("veritabani.txt", ios::app);
	dosyayaz <<kullanici<<endl;
    dosyayaz <<secimyaz<<endl;
    dosyayaz <<rastyaz<<endl;
    dosyayaz.close();
	//------------------------------------------------------------------
			cout<<"Anasayfaya dönmek isterseniz E veya e ye basýnýz ..."<<endl;
			cout<<"Seçim = ";
			cin>>secim_basagit;
			if(secim_basagit == 'e' || secim_basagit == 'E')
			{
				goto basla1;
			}
	break;
		}
	//------------------------------------------------------------------//okuma
	case 2:
		{
	cout<<"--------------------- ÞÝFRE ÇÖZME SAYFASI ---------------------"<<endl;
    string satir, kullanici_id;
	basla3:
	cout<<"Þifreyi hangi kullanýcýya göre çözmek istersiniz = ";
	cin>>kullanici_id;
	int say1=0,say2=0,x=0,rastoku,secimoku;
    ifstream dosyaoku ("veritabani.txt");
	while(getline(dosyaoku,satir))
	{	
		say1++;
		if(x == 1)
		{
		rastoku=stoi(satir);
		x--;
		}
		if(x == 2)
		{
		secimoku=stoi(satir);
		x--;
		}
		if(satir == kullanici_id)
		x=2;
		else
		say2++;
	}
	if(say1 == say2)
	{
		cout<<"HATA# Böyle bir kullanýcý adý yok, lütfen tekrar giriniz ..."<<endl;
		goto basla3;
	}
    dosyaoku.close();
	switch (secimoku)
	{
	case 1:
		{
			cout<<"Çözmek Ýstediðiniz Þifreyi Giriniz --------> ";
			cin.ignore();
			getline(cin,sifre);
			string sifre_kod;
			int *sifre_ascii;
			sifre_ascii = new int[sifre.size()];
			cout<<"Þifrenin Çözülmüþ Hali --------> ";
			int sayac=0;
			string ascii_bul,sifre_gecici;

			sifre=sifre.substr(1,sifre.length()-2); // burada baþdaki ve sondaki 2 harfi çýkardýk. amaç kafa karýþtýrmak.

			for (int i = 0; i < sifre.length(); i++) //þifrelemeyi çözüyoruz.-------------------------------------------------------------------------------------------
			{
				sifre_ascii[sayac] = dizi_ascii[sayac];
				for (int j = 1; j <= 3; j++) //burasýný 3 yaptýk çünkü hesaplamalarýma göre burada ascii kodlarý en fazla 3 basamaklý oluyor.
				{
					ascii_bul=sifre.substr(i,j); //dizi elemanlarýný sayac ile belirlemimizin asýl sebebi.
					if(sifre_ascii[sayac]==stol(ascii_bul))
					{
						sifre_ascii[sayac]=(sifre_ascii[sayac] - rastoku) - 17;
						sifre_gecici=sifre_gecici + char(sifre_ascii[sayac]);
						sayac=sayac+1; //sayac ile dizinin elemanlarýný belirledik çünkü i ile yapsaydýk þifrenin ascii kodlarýna çevrilmiþ halinin uzunluðu gelecekti,bu yüzden arada gereksiz boþluklar ve elemanlar olacaktý ve þifre çözülmeyecekti.
					}
				}
			}
			sifre=sifre_gecici;
			sifrele_f(sifre);
			cout<<endl;
			delete[] sifre_ascii;
		break;
		}
	case 2:
		{
			cout<<"Çözmek Ýstediðiniz Þifreyi Giriniz --------> ";
			cin.ignore();
			getline(cin,sifre);
			string ceaser_sifre_kod;
			int *ceaser_rast,*ceaser_ascii,*ceaser_tut,*ceaser_fark;
			int ceaser_sayac=0;

			ceaser_rast = new int[sifre.size()];
			ceaser_ascii = new int[sifre.size()];
			ceaser_tut = new int[sifre.size()];
			ceaser_fark = new int[sifre.size()];
			sifre = sifre.substr(1,sifre.size()-2);
	
			string ceaser_sifre_gecici;
			ceaser_sayac=0;

			for (int i = 0; i < sifre.length(); i++)//þifrelemeyi çözüyoruz.-------------------------------------------------------------------------------------------
			{
				ceaser_tut[i] = dizi_ceaser_tut[i];
				if(ceaser_tut[i] < 97)
				{
					ceaser_ascii[i] = int(sifre[i]) - rastoku - (97 - ceaser_tut[i]);
				}
				else if(ceaser_tut[i] > 122)
				{
					ceaser_ascii[i] = int(sifre[i]) - rastoku + (ceaser_tut[i] - 97);
				}
				else
				{
					ceaser_ascii[i] = int(sifre[i]) - rastoku;
					if(ceaser_ascii[i] < 97) 
					{
						ceaser_fark[ceaser_sayac] = dizi_ceaser_fark[ceaser_sayac];
						ceaser_ascii[i] = ceaser_fark[ceaser_sayac] - rastoku;
						ceaser_sayac=ceaser_sayac+1;
					}
					if(ceaser_tut[i] == 122)
					{
						ceaser_ascii[i] = 122;
						ceaser_sayac=ceaser_sayac+1;
					}
				}
				ceaser_sifre_gecici = ceaser_sifre_gecici + char(ceaser_ascii[i]);
			}
			sifre = ceaser_sifre_gecici;
			cout<<"Þifrenin Çözülmüþ Hali --------> ";
			sifrele_f(sifre);
			cout<<endl;
			delete[] ceaser_tut;
			delete[] ceaser_ascii;
			delete[] ceaser_fark;
			delete[] ceaser_rast;
		break;
		}
	case 3:
		{
			string karisik_harfler;
			int *karisik_ascii, *karisik_carpan;

			karisik_carpan = new int[sifre.length()];
			karisik_ascii = new int[sifre.length()];
			karisik_harfler=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			cout<<"Çözmek Ýstediðiniz Þifreyi Giriniz --------> ";
			cin.ignore();
			getline(cin,sifre);
			sifre = sifre.substr(0,sifre.size()-1);

			string karisik_sifre_gecici,karisik_sayilar;
			karisik_sayilar = "123456789";
			for (int i = 0; i < sifre.length(); i++) //þifrelemeyi çözüyoruz.-------------------------------------------------------------------------------------------
			{
				if(65 <= int(sifre[i]) <= 90)
				{
					karisik_carpan[i] = dizi_karisik[i];
					for (int j = 1; j < karisik_harfler.length(); j++)
					{
						if (sifre[i] == karisik_harfler[j])
							karisik_ascii[i] = j + (26*karisik_carpan[i]) - rastoku;
					}
				}
				if (49 <= int(sifre[i]) <= 57)
				{
					for (int j = 0; j < karisik_sayilar.length(); j++)
					{
						if (sifre[i] == karisik_sayilar[j])
							karisik_ascii[i] = (j + 1) + (9*karisik_carpan[i]) - 13 - rastoku;
					}
				}
				karisik_sifre_gecici = karisik_sifre_gecici + char(karisik_ascii[i]);
			}
			sifre = karisik_sifre_gecici;
			cout<<"Þifrenin Çözülmüþ Hali --------> ";
			sifrele_f(sifre);
			cout<<endl;
			delete[] karisik_ascii;
			delete[] karisik_carpan;
		break;
		}
	default:
		{
		break;
		}
	}
			cout<<"Anasayfaya dönmek isterseniz E veya e ye basýnýz ..."<<endl;
			cout<<"Seçim = ";
			cin>>secim_basagit;
			if(secim_basagit == 'e' || secim_basagit == 'E')
			{
				goto basla1;
			}
	break;
		}
	//------------------------------------------------------------------
	default:
		cout<<"HATA# Lütfen 1 veya 2 sayýsýný giriniz..."<<endl;
		goto basla1;
	}
	system("pause");
	return 0;
}

