#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <locale.h>
using namespace std;



//Sami Yi�it Uncu
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
		
	cout << "�r�n�n ismi giriniz: " ;
	cin >> urun.tur ; 
	
	cout << "L�tfen " << urun.tur << " �r�n sto�unu giriniz: " ;
	cin >> urun.stok ;
	
	cout << "L�tfen " << urun.tur << " �r�n fiyat�n� giriniz: " ;
	cin >> urun.fiyat ; 

	bilgiler << endl << urun.tur << setw(10) << urun.stok << setw(10) << urun.fiyat ; 
	
	cout << "Ba�ka �r�n�n girisi yapmak ister misiniz? (E/H): ";	
	secim=getche();	
	cout << endl;
	sayi++;
		
	}
	while(secim=='e' || secim=='E');
	cout << sayi << " Adet �r�n�n girisi yap�ld�." << endl;
	bilgiler.close();		
	
}

void urunListeleme()
{
	pastane urun;
	ifstream okuma("pastane.txt");
	cout << setw(10) << "�R�N" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;
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
	cout << "Hangi �r�n� g�rmek istiyorsunuz?: " ;
	string isim;
	cin >> isim;
	int sayac=0;
	cout << setw(10) << "�R�N" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;	
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
		cout << "�run bulunamad�." << endl;
	}
}

void urunSilme()
{
	pastane urun;
	cout << "   EL�M�ZDE OLAN �RUNLER   " << endl;
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
	
	cout << sayac << " Adet �r�n Silindi" << endl;
}
	else
	{
		cout << "�r�n silinmedi" << endl;
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
	cout << "  EL�M�ZDE OLAN �R�NLER   " << endl;
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
	cout << "Hangi �r�n� G�ncellemek �stiyorsunuz?" << endl;
	string isim;
	cin >> isim;
		while(!(okuma2.eof()))
	{
		okuma2 >> urun.tur >> urun.stok >> urun.fiyat;
		if(isim==urun.tur)
		{
			cout << "�r�n�n �smi Giriniz: " ;
			cin >> urun.tur ; 
	 
			cout << "L�tfen " << urun.tur << " �r�n�n Sto�unu Giriniz: " ;
			cin >> urun.stok ;
	
			cout << "L�tfen " << urun.tur << " �r�n�n Fiyat�n� Giriniz: " ;
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
	
	cout << "Ba�ka �r�n� G�ncellemek �ster misiniz? (E/H)" << endl;	
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
	cout << setw(10) << "�r�n�n" << setw(10) << "Fiyat" << setw(10) << "Adet" << setw(15) << "Toplam fiyat" << endl;	
	while(!(okuma.eof()))
	{
		okuma >> satislar.satilanUrun.tur >> satislar.satilanUrun.fiyat >> satislar.adet >> satislar.toplam;
		cout << setw(10) << satislar.satilanUrun.tur << setw(10) << satislar.satilanUrun.fiyat << setw(10) << satislar.adet << setw(15) << satislar.toplam << endl;
		toplam+=satislar.toplam;
	}
	cout << endl;
	cout << "G�nl�k Kazan�: " << toplam << endl;
}
void urunSatis()
{
	pastane urun;
	satisBilgileri satislar;
	cout << "   EL�M�ZDE OLAN �R�NLER   " << endl;
	cout << setw(10) << "�R�N" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;
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
	cout << "Hangi �r�n� satmak istiyorsunuz?" << endl;
	string isim;
	cin >> isim;
	int sayi;
	float odenecekUcret;
		while(!(okuma2.eof()))
	{
		okuma2 >> urun.tur >> urun.stok >> urun.fiyat;
		if(isim==urun.tur)
		{
			cout << "Ka� tane �r�n satmak istiyorsunuz?" << endl;
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
			cout << "�demeniz Gereken �cret: " << odenecekUcret << endl;
			satis << endl<<satislar.satilanUrun.tur << setw(10) << satislar.satilanUrun.fiyat << setw(10) << satislar.adet << setw(10) << satislar.toplam;
			}
			else
			{
				cout << "Elimizde " << urun.stok << " tane " << urun.tur << " �r�n bulunmaktad�r." << endl;
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
	
	cout << "Ba�ka �r�n�n sat��� yapmak ister misiniz? (E/H)" << endl;	
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
	cout << "---         Ana Men�            ---" << endl;
	cout << "---       1.�r�n Ekleme         ---" << endl;               
	cout << "---      2.�r�n G�ncelleme      ---" << endl;
	cout << "---      3.Stok G�r�nt�leme     ---" << endl;
	cout << "---        4.�r�n Sat���        ---" << endl;
	cout << "---        5.�r�n Arama         ---" << endl;
 	cout << "---       6.Sat�� Listeleme     ---" << endl;
 	cout << "---        7.�r�n Silme         ---" << endl;
 	cout << "---           8.��k��           ---" << endl;


	cout << "\nL�tfen yapmak istedi�iniz i�lemi girin: " ;
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
		cout << "Hatal� Se�im Yapt�n�z! 1-8" << endl;
	}
	if(secim!='8')
	{
	cout << "Ana menuye donmek ister misin?(E/H)" << endl;
	secim=getche();
	}
	
	} 
	while(secim=='e' || secim=='E');
	cout << "Programdan ��kt�n�z!" << endl;
	
	system("pause");
	return 0;
}
