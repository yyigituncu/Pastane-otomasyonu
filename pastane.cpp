#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <locale.h>
using namespace std;



//Sami Yiðit Uncu
//2212721051
//PASTANE OTOMASYONU



struct pastane
{
	string tur;
	float stok;
	float fiyat;	
};

struct satisBilgileri
{
	pastane satilanUrun;
	float toplam;
	int adet;	
};

void urunEkle()
{
	ofstream bilgiler("pastane.txt", ios::app);
	char secim;
	int sayi=0;
	pastane urun;

	do
	{
		
	cout << "Ürünün ismi giriniz: " ;
	cin >> urun.tur ; 
	
	cout << "Lütfen " << urun.tur << " ürün stoðunu giriniz: " ;
	cin >> urun.stok ;
	
	cout << "Lütfen " << urun.tur << " ürün fiyatýný giriniz: " ;
	cin >> urun.fiyat ; 

	bilgiler << endl << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat ; 
	
	cout << "Baþka Ürünün girisi yapmak ister misiniz? (E/H): ";	
	secim=getche();	
	cout << endl;
	sayi++;
		
	}
	while(secim=='e' || secim=='E');
	cout << sayi << " Adet Ürünün girisi yapýldý." << endl;
	bilgiler.close();		
	
}

void urunListeleme()
{
	pastane urun;
	ifstream okuma("pastane.txt");
	cout << setw(10) << "ÜRÜN" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;
	while(!(okuma.eof()))
	{
		okuma >> urun.tur >> urun.stok >> urun.fiyat;
		cout << setw(10) << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat << endl;
	}
}

void urunArama()
{
	pastane urun;
	ifstream okuma("pastane.txt");
	cout << "Hangi ürünü görmek istiyorsunuz?: " ;
	string isim;
	cin >> isim;
	int sayac=0;
	cout << setw(10) << "ÜRÜN" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;	
	while(!(okuma.eof()))
	{
		okuma >> urun.tur >> urun.stok >> urun.fiyat;
		if(urun.tur==isim){
		cout << setw(10) << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat << endl;
		sayac++;
		}
	}
	if(sayac==0)
	{
		cout << "Ürun bulunamadý." << endl;
	}
}

void urunSilme()
{
	pastane urun;
	cout << "   ELÝMÝZDE OLAN ÜRUNLER   " << endl;
	ofstream yedek("yedek.txt", ios::app);
	ifstream okuma("pastane.txt");
	char secim;
	int sayac=0;
	
	while(!(okuma.eof()))
	{
		okuma >> urun.tur >> urun.stok >> urun.fiyat;
		cout << setw(10) << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat << endl;
	}
	ifstream okuma2("pastane.txt");
	cout << "Silinen Urunler " << endl;
	
	while(!(okuma2.eof()))
	{
		
		okuma2 >> urun.tur >> urun.stok >> urun.fiyat;
		if(urun.stok==0)
		{
			cout << setw(10) << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat << endl;
			sayac++;
		}
		else
		{
			yedek << endl << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat ; 		
		}
	}
	if(sayac>0)
	{
	
	cout << sayac << " Adet Ürün Silindi" << endl;
}
	else
	{
		cout << "Ürün silinmedi" << endl;
	}
	okuma2.close();
	okuma.close();
	yedek.close();
	
	
	remove("pastane.txt");
	rename("yedek.txt", "pastane.txt");
}


void urunGuncelleme()
{
	pastane urun;
	cout << "  ELÝMÝZDE OLAN ÜRÜNLER   " << endl;
	ofstream yedek("yedek.txt", ios::app);
	ifstream okuma("pastane.txt");
	char secim;
	do
	{
	while(!(okuma.eof()))
	{
		okuma >> urun.tur >> urun.stok >> urun.fiyat;
		cout << setw(10) << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat << endl;
	}
	ifstream okuma2("pastane.txt");
	cout << "Hangi Ürünü Güncellemek Ýstiyorsunuz?" << endl;
	string isim;
	cin >> isim;
		while(!(okuma2.eof()))
	{
		okuma2 >> urun.tur >> urun.stok >> urun.fiyat;
		if(isim==urun.tur)
		{
			cout << "Ürünün Ýsmi Giriniz: " ;
			cin >> urun.tur ; 
	 
			cout << "Lütfen " << urun.tur << " Ürünün Stoðunu Giriniz: " ;
			cin >> urun.stok ;
	
			cout << "Lütfen " << urun.tur << " Ürünün Fiyatýný Giriniz: " ;
			cin >> urun.fiyat ; 
		
			yedek << endl << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat ; 
		
		}
		else
		{
			yedek << endl << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat ; 		
		}
	}
	
	

	okuma2.close();
	okuma.close();
	yedek.close();
	
	cout << "Baþka Ürünü Güncellemek Ýster misiniz? (E/H)" << endl;	
	secim=getche();	 
	}
	while(secim=='e' || secim=='E');
		
	remove("pastane.txt");
	rename("yedek.txt", "pastane.txt");
}
    
void satisListeleme()
{
	float toplam=0;
	satisBilgileri satislar;
	ifstream okuma("satis.txt");
	cout << setw(10) << "Ürünün" << setw(10) << "Fiyat" << setw(10) << "Adet" << setw(15) << "Toplam fiyat" << endl;	
	while(!(okuma.eof()))
	{
		okuma >> satislar.satilanUrun.tur >> satislar.satilanUrun.fiyat >> satislar.adet >> satislar.toplam;
		cout << setw(10) << satislar.satilanUrun.tur << setw(10) << satislar.satilanUrun.fiyat << setw(10) << satislar.adet << setw(15) << satislar.toplam << endl;
		toplam+=satislar.toplam;
	}
	cout << endl;
	cout << "Günlük Kazanç: " << toplam << endl;
}
void urunSatis()
{
	pastane urun;
	satisBilgileri satislar;
	cout << "   ELÝMÝZDE OLAN ÜRÜNLER   " << endl;
	cout << setw(10) << "ÜRÜN" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;
	ofstream yedek("yedek.txt", ios::app);
	ifstream okuma("pastane.txt");
	ofstream satis("satis.txt",ios::app);
	char secim;
	do
	{
	while(!(okuma.eof()))
	{
		okuma >> urun.tur >> urun.stok >> urun.fiyat;
		cout << setw(10) << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat << endl;
	}
	ifstream okuma2("pastane.txt");
	cout << "Hangi ürünü satmak istiyorsunuz?" << endl;
	string isim;
	cin >> isim;
	int sayi;
	float odenecekUcret;
		while(!(okuma2.eof()))
	{
		okuma2 >> urun.tur >> urun.stok >> urun.fiyat;
		if(isim==urun.tur)
		{
			cout << "Kaç tane ürün satmak istiyorsunuz?" << endl;
			cin >> sayi;
			if(sayi<=urun.stok)
			{
			urun.stok-=sayi;
			
			yedek << endl << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat ; 
			odenecekUcret=sayi*urun.fiyat;
			satislar.satilanUrun.tur=urun.tur;
			satislar.satilanUrun.fiyat=urun.fiyat;
			satislar.adet=sayi;
			satislar.toplam=satislar.adet*satislar.satilanUrun.fiyat;
			cout << "Ödemeniz Gereken Ücret: " << odenecekUcret << endl;
			satis << endl<<satislar.satilanUrun.tur << setw(10) << satislar.satilanUrun.fiyat << setw(10) << satislar.adet << setw(10) << satislar.toplam;
			}
			else
			{
				cout << "Elimizde " << urun.stok << " tane " << urun.tur << " ürün bulunmaktadýr." << endl;
			}
		}
		else
		{
			yedek << endl << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat ; 		
		}
	}

	okuma2.close();
	okuma.close();
	yedek.close();
	
	cout << "Baþka Ürünün satýþý yapmak ister misiniz? (E/H)" << endl;	
	cin >> secim;
	}
	while(secim=='e' || secim=='E');
	
	
	remove("pastane.txt");
	rename("yedek.txt", "pastane.txt");
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	char secim=' ';
	
	do{
	
	system("cls");       
	
	cout << "---     *PASTANE OTOMASYONU*    ---" << endl;
	cout << "---         Ana Menü            ---" << endl;
	cout << "---       1.Ürün Ekleme         ---" << endl;               
	cout << "---      2.Ürün Güncelleme      ---" << endl;
	cout << "---      3.Stok Görüntüleme     ---" << endl;
	cout << "---        4.Ürün Satýþý        ---" << endl;
	cout << "---        5.Ürün Arama         ---" << endl;
 	cout << "---       6.Satýþ Listeleme     ---" << endl;
 	cout << "---        7.Ürün Silme         ---" << endl;
 	cout << "---           8.Çýkýþ           ---" << endl;


	cout << "\nLütfen yapmak istediðiniz iþlemi girin: " ;
	secim=getche();
	cout<<endl;
	switch(secim)
	{
		case '1':
		{
			urunEkle();	
			break;
		}	
		
		case '2':
		{
			urunGuncelleme();
			break;
		}
		
		case '3':
		{
			urunListeleme();
			break;
		}
		
		case '4':
		{
			urunSatis();
			break;
		}
		
		case '5':
		{
			urunListeleme();
			urunArama();
			break;
		}
		
		case '6':
		{
		 	satisListeleme();
			break;
		}
		
		case '7':
		{
			urunSilme();
			break;
		}
		
		case '8':
		{
			break;
		}
		
		default:
		cout << "Hatalý Seçim Yaptýnýz! 1-8" << endl;
	}
	if(secim!='8')
	{
	cout << "Ana menuye donmek ister misin?(E/H)" << endl;
	secim=getche();
	}
	
	} 
	while(secim=='e' || secim=='E');
	cout << "Programdan Çýktýnýz!" << endl;
	
	system("pause");
	return 0;
}
