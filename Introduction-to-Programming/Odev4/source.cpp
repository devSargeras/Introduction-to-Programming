/****************************************************************************
**							SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**					    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI     : 4. �DEV
**				��RENC� ADI       : �MER CAN �ALI�IR
**				��RENC� NUMARASI  :
**				DERS GRUBU        : D
****************************************************************************/

#include<iostream>
#include<string>
using namespace std;


class Sifre
{
	private:


		int tutucuSifre[100];
		int tutucuSifrelenecekMetin[100];
		int desifreMetin[100];
		int tasimaci[100];

		char alfabe[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		char sifre[100];
		char sifrelenecekMetin[100];
		char sifrelenmisMetin[100];


		int uzunlukAlfabe			   = 26;
		int uzunlukSifre		       = 0;
		int uzunlukSifrelenecekMetin   = 0;


	public:

		void yazdirSifrelenmisMetin();
		void yazdirDesifreMetin();
	
		void tutucuSifreMatrisiOlustur();

		void tutucuSifrelenecekMetinMatrisiOlustur();
	
		void girilenAlfebeyiOku();

		void girilenSifreyiOku();

		void girilenSifrelenecekMetniOku();

		void sifrelenmisMetniOlustur();

		void sifreCoz();

	

};





// sifrelenmis metini bast�r�r.
void Sifre::yazdirSifrelenmisMetin()
{
	cout << "SIFRELENMIS METIN\t:";
	for (int i = 0; i < uzunlukSifrelenecekMetin; i++)
	{
		cout << sifrelenmisMetin[i];
	}
}


// desifre metini bast�r�r.
void Sifre::yazdirDesifreMetin()
{
	cout << "DESIFRE METIN\t\t:";
	for (int i = 0; i < uzunlukSifrelenecekMetin; i++)
	{
		cout << char(desifreMetin[i]);
	}
}


// sifre elemanlar�n�n alfabedeki s�ras�n� tutan bir matris olu�turuyor.
void Sifre::tutucuSifreMatrisiOlustur()
{
	int tutucuDegiskeni = 0;
	// alfabe ve sifre i�erisindeki ayn�  harflerin tespiti i�in  sifre uzunlugu ve alfabe uzunlugu kadar donen forlar.
	for (int i = 1; i <= uzunlukSifre; i++)
	{
		for (int j = 1; j <= uzunlukAlfabe; j++)
		{
			//alfabe ve sifre i�erisindeki ayn�  harflerin  alfabedeki s�ras�n�n tespiti i�in if yap�s�.
			if (alfabe[j - 1] == sifre[i - 1])
			{
				tutucuSifre[tutucuDegiskeni] = j;
				tutucuDegiskeni++;
			}
		}
	}
}


// sifrelenecekMetin elemanlar�n�n alfabedeki s�ras�n� tutan bir matris olu�turuyor.
void Sifre::tutucuSifrelenecekMetinMatrisiOlustur()
{
	int tutucuDegiskeni = 0;
	// alfabe ve sifrelenecekMetin i�erisindeki ayn�  harflerin tespiti i�in  sifrelenecekMetin uzunlugu ve alfabe uzunlugu kadar donen forlar.
	for (int i = 1; i <= uzunlukSifrelenecekMetin; i++)
	{
		for (int j = 1; j <= uzunlukAlfabe; j++)
		{
			//alfabe ve sifrelenecekMetin i�erisindeki ayn�  harflerin  alfabedeki s�ras�n�n tespiti i�in if yap�s�.
			if (alfabe[j - 1] == sifrelenecekMetin[i - 1])
			{
				tutucuSifrelenecekMetin[tutucuDegiskeni] = j;
				tutucuDegiskeni++;
			}
		}
	}
}


// kullan�c�n�n girece�i alfabeyi okumaya yar�yor.
void Sifre::girilenAlfebeyiOku()
{
	char okunanKarakter = 'z';
	int i = 0;
	cout << "ALFABE\t\t\t:";
	// enter tu�una bas�lana kadar d�nen while yap�s�.
	while (okunanKarakter != '\r')
	{
		okunanKarakter = _getwche();
		if (okunanKarakter == '\r')
		{
			break;
		}
		alfabe[i] = okunanKarakter;
		i++;
	}
	if (i != 0)
	{
		uzunlukAlfabe = i;
	}
}


// kullan�c�n�n girece�i sifreyi okumaya yar�yor.
void Sifre::girilenSifreyiOku()
{
	char okunanKarakter = 'z';
	int i = 0;
	cout << "SIFRE\t\t\t:";
	// enter tu�una bas�lana kadar d�nen while yap�s�.
	while (okunanKarakter != '\r')
	{
		okunanKarakter = _getwche();
		sifre[i] = okunanKarakter;
		i++;
	}
	uzunlukSifre = i - 1;
}


// kullan�c�n�n girece�i sifrelenecekMetini okumaya yar�yor.
void Sifre::girilenSifrelenecekMetniOku()
{
	char okunanKarakter = 'z';
	int i = 0;
	cout << "SIFRELENECEK METIN\t:";
	// enter tu�una bas�lana kadar d�nen while yap�s�.
	while (okunanKarakter != '\r')
	{
		okunanKarakter = _getwche();
		sifrelenecekMetin[i] = okunanKarakter;
		i++;
	}
	uzunlukSifrelenecekMetin = i - 1;
}


// girilen sifrelenecekMetin ve sifreyi kullanarak sifrelenmisMetin olu�turuyor.
void Sifre::sifrelenmisMetniOlustur()
{
	int a = 0;


	for (int i = 0; i < uzunlukSifrelenecekMetin; i++)
	{
		sifrelenmisMetin[i] = tutucuSifre[a] + tutucuSifrelenecekMetin[i];

		tasimaci[i] = tutucuSifre[a] + tutucuSifrelenecekMetin[i];

		a++;
		// sifrenin , sifreleme metodu gere�i s�rekli tekrarlanarak sifrelenecek metnin alt�na yazd�r�lmas� i�in if yap�s�
		if (a == uzunlukSifre)
		{
			a = 0;
		}

		// sifre ve sifrelenecek metnin toplam� sonucu olu�an de�erin alfabe uzunlugundan b�y�k olup olmad��� kontrol ediliyor.B�y�kse alfabe uzunlugu ��kar�l�yor.
		if (sifrelenmisMetin[i] > uzunlukAlfabe)
		{
			int islem = sifrelenmisMetin[i] - uzunlukAlfabe;
			sifrelenmisMetin[i] = alfabe[islem - 1];
		}
		// 
		else
		{
			sifrelenmisMetin[i] = alfabe[sifrelenmisMetin[i] - 1];
		}
	}
}


// sifrelenmis metinden, sifreyi kullanarak yeniden sifrelenmesi i�in girilen metini olu�turuyor.
void Sifre::sifreCoz()
{

	int a = 0;


	for (int i = 0; i < uzunlukSifrelenecekMetin; i++)
	{
		desifreMetin[i] = tasimaci[i] - tutucuSifre[a];
		a++;
		if (a == uzunlukSifre)
		{
			a = 0;
		}
		if (desifreMetin[i] < 1)
		{
			int islem = desifreMetin[i] + uzunlukAlfabe;
			desifreMetin[i] = alfabe[islem - 1];
		}
		else
		{
			desifreMetin[i] = alfabe[desifreMetin[i] - 1];
		}

	}
}




int main() {


	Sifre sifre;


	cout << "Eger herhangibir alfabe girilmezse varsayilan olarak ingiliz alfabesi kullanilacaktir." << endl << endl;
	

	sifre.girilenAlfebeyiOku(); cout << endl;
	

	sifre.girilenSifreyiOku(); cout << endl;
	

	sifre.girilenSifrelenecekMetniOku(); cout << endl;
	

	sifre.tutucuSifreMatrisiOlustur();


	sifre.tutucuSifrelenecekMetinMatrisiOlustur();


	sifre.sifrelenmisMetniOlustur();


	sifre.yazdirSifrelenmisMetin(); cout << endl;
	


	sifre.sifreCoz();


	sifre.yazdirDesifreMetin(); cout << endl << endl;
	

	system("pause");
	return 0;
}