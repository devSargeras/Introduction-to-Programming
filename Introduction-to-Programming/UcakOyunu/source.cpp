/****************************************************************************
**							SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**					    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI     : PROJE ÖDEVİ
**				ÖĞRENCİ ADI       : ÖMER CAN ÇALIŞIR
**				ÖĞRENCİ NUMARASI  :
**				DERS GRUBU        : D
****************************************************************************/
#include<pch.h>
#include<iostream>
#include<Windows.h>
#include<time.h>
#include<cstdlib>
#include<ctime>
using namespace std;

int donguSayaci = 0;
int mermiNumarasi = 0;
int dusmanNumarasi = 0;
int xKoordinatlari[5] = { 1,2,3,2,1 };
int yKoordinatlari[5] = { 7,8,9,10,11 };
int carpisanDusmanlarinNumaralari[1000];
int dusmanHizi = 1;
int dusmanOlusturmaHizi = 25;

enum YON
{
	YON_SABİT = 0,
	YON_SAG = 1,
	YON_SOL = 2,
	YON_YUKARI = 3,
	YON_ASAGI = 4
};

struct mermiHucre
{
	int x[100];
	int y[100];
	YON yon;
	char karakter;
};
struct ucakHucre
{
	int     x[5];

	int		y[5];

	YON		yon;
	char	karakter;
};
struct dusmanHucre
{
	int x[9];

	int y[9];

	YON yon;

	char karakter;

};


const int	genislik = 80;

const int	yukseklik = 20;

const char ucakKarakteri = 219;

const char mermiKarakteri = 219;

const char dusmanKarakteri = 219;

char		sahne[genislik][yukseklik];

char		tuslar[256];

ucakHucre		ucak[10];
mermiHucre		mermi[1000];
dusmanHucre		dusman[100];


void klavyeOku(char tuslar[])
{
	for (int x = 0; x < 256; x++)
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void kursoruGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void sahneyiCiz()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			cout << sahne[x][y];
		}

		cout << endl;
	}
}
void sahneyiTemizle()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			sahne[x][y] = ' ';
		}

	}
}
void sinirlariOlustur()
{
	for (int x = 0; x < genislik; x++)
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}

	for (int y = 0; y < yukseklik; y++)
	{
		sahne[0][y] = 219;
		sahne[genislik - 1][y] = 219;
	}

}


// düşmanın hareket etmesini sağlayan fonksiyon
void dusmaniHareketEttir()
{
	// düşman sayısı kadar dönen for yapısı
	for (int i = 0; i < dusmanNumarasi; i++)
	{
		// mermi ile çarpışan düşman olup olmadığını kontrol eden, eğer varsa bu düşman üzerinde işlem yapılmasını engelleyen if yapısı
		if (carpisanDusmanlarinNumaralari[i] != i)
		{
			// x koordinatlarında dönmeyi sağlayan for yapısı
			for (int j = 0; j < 9; j++)
			{
				int kontrol = dusman[i].x[j];
				// vurulmayan düşmanların çerçeve içerisinden çıkıp çıkmadığını kontrol eden if yapısı
				if (kontrol != 1)
				{
					dusman[i].x[j] -= dusmanHizi;
				}
			}
		}
	}
}
// merminin hareket etmesini sağlayan fonksiyon
void mermiyiHareketEttir()
{
	// mermi sayısı kadar dönen for yapısı
	for (int i = 0; i < mermiNumarasi; i++)
	{
		// mermi çerçevenin dışına çıktıktan sonra artık üzerinde işlem yapılmamasını sağlayan if else yapısı
		if (mermi[i].x[i] == genislik + 5)
		{

		}
		else
		{
			mermi[i].x[i]++;
		}
	}
}
// uçağın çerçevenin içerisinde hareket etmesini sağlayan fonksiyon
void ucagiHareketEttir()
{
	int l1 = 0;
	for (int i = 5; i < 10; i++)
	{
		// uçağın çerçeveden çıkmaması için sınırları kontrol eden if else if yapısı ve uçağın hareketini sağlayan else yapısı
		if (ucak[5].y[0] == 0)
		{
			int l2 = 0;
			for (int k = 5; k < 10; k++)
			{
				ucak[k].y[l2]++;
			}
			break;
		}
		else if (ucak[5].y[0] == 15)
		{
			int l3 = 0;
			for (int k = 5; k < 10; k++)
			{
				ucak[k].y[l3]--;
			}
			break;
		}
		else
		{
			// basılan tuşa göre uçağın hareketini sağlayan switch case yapısı
			switch (ucak[i].yon)
			{
			case YON_ASAGI:
				ucak[i].y[l1]++;
				l1++;
				break;
			case YON_YUKARI:
				ucak[i].y[l1]--;
				l1++;
				break;
			}
		}
	}
}
// düşman oluşmasını sağlayan fonksiyon
void dusmanOlustur()
{
	// düşman oluşturma hızına göre fonksiyonun çalışmasını sağlayan if yapısı
	if (donguSayaci % dusmanOlusturmaHizi == 0)
	{
		int a = 76;
		int b = (rand() % 16) + 2;
		dusman[dusmanNumarasi].x[0] = a - 1;
		dusman[dusmanNumarasi].x[1] = a;
		dusman[dusmanNumarasi].x[2] = a + 1;
		dusman[dusmanNumarasi].x[3] = a - 1;
		dusman[dusmanNumarasi].x[4] = a;
		dusman[dusmanNumarasi].x[5] = a + 1;
		dusman[dusmanNumarasi].x[6] = a - 1;
		dusman[dusmanNumarasi].x[7] = a;
		dusman[dusmanNumarasi].x[8] = a + 1;

		dusman[dusmanNumarasi].y[0] = b - 1;
		dusman[dusmanNumarasi].y[1] = b - 1;
		dusman[dusmanNumarasi].y[2] = b - 1;
		dusman[dusmanNumarasi].y[3] = b;
		dusman[dusmanNumarasi].y[4] = b;
		dusman[dusmanNumarasi].y[5] = b;
		dusman[dusmanNumarasi].y[6] = b + 1;
		dusman[dusmanNumarasi].y[7] = b + 1;
		dusman[dusmanNumarasi].y[8] = b + 1;

		dusmanNumarasi++;
	}


}
// mermi oluşturmaya yarayan fonksiyon
void mermiOlustur(int ucakX, int ucakY)
{
	mermi[mermiNumarasi].x[mermiNumarasi] = ucakX;
	mermi[mermiNumarasi].y[mermiNumarasi] = ucakY;
	mermi[mermiNumarasi].karakter = mermiKarakteri;

}
// uçak oluşturmaya yarayan fonksiyon
void ucakOlustur()
{
	// uçağın x ve y koordinatlarında dönmeye yarayan for yapıları
	for (int i = 0; i < 5; i++)
	{
		ucak[i].x[i] = xKoordinatlari[i];
	}
	int sayac = 0;
	for (int i = 5; i < 10; i++)
	{
		ucak[i].y[sayac] = yKoordinatlari[sayac];
		sayac++;
	}
	ucak[10].karakter = ucakKarakteri;
}
// mermi ile çarpışan düşmanların numaralarını tespit etmeye yarayan fonksiyon
void carpismaVarMı()
{
	// mermi numarası kadar dönen for yapısı
	for (int i = 0; i < mermiNumarasi; i++)
	{
		// dusman numarası kadar dönen for yapısı
		for (int k = 0; k < dusmanNumarasi; k++)
		{
			// mermi ve düşmanın x ve ye koordinatlarında dönmek için for yapısı
			for (int l = 0; l < 9; l++)
			{
				// düşman ve merminin x,y koordinatlarının eşitliğinden yararlanarak çarpışıldığının tespiti için if yapısı
				if (mermi[i].x[i] == dusman[k].x[l] && mermi[i].y[i] == dusman[k].y[l])
				{
					carpisanDusmanlarinNumaralari[k] = k;
				}
			}
		}
	}
}
// düşmanı sahneye yerleştirmeye yarayan fonksiyon
void dusmaniSahneyeYerlestir()
{
	// düşman numarası kadar dönen for yapısı
	for (int j = 0; j < dusmanNumarasi; j++)
	{
		// mermi ile çarpışan düşmanların üzerinde işlem yapılmaması için , çarpışanları kontrol eden if yapısı
		if (carpisanDusmanlarinNumaralari[j] != j)
		{
			// x ve y koordinatlarında dönmek için for yapısı
			for (int i = 0; i < 9; i++)
			{
				if (i != 4)
				{
					int x = dusman[j].x[i];
					int y = dusman[j].y[i];
					// düşmanın sahneden çıktıysa karakter atanmaması için if yapısı
					if (x != 1)
					{
						sahne[x][y] = dusmanKarakteri;
					}
				}
			}
		}
	}
}
// mermiyi sahneye yerleştirmeye yarayan fonksiyon
void mermiyiSahneyeYerlestir()
{
	// mermi numarası kadar dönen for yapısı
	for (int i = 0; i < mermiNumarasi; i++)
	{
		int x = mermi[i].x[i];
		int y = mermi[i].y[i];
		sahne[x][y] = mermiKarakteri;
	}
}
// uçağı sahneye yerleştirmeye yarayan fonksiyon
void ucagiSahneyeYerlestir()
{
	int z = 1;
	int k = 0;
	// uçağın parçalarında dönmeye yarayan for yapıları
	for (int i = 5; i < 8; i++)
	{
		int y = ucak[i].y[k];
		sahne[z][y] = ucakKarakteri;
		z++;
		k++;
	}
	int s = 2;
	int l = 3;
	for (int i = 8; i < 10; i++)
	{
		int y = ucak[i].y[l];
		sahne[s][y] = ucakKarakteri;
		s--;
		l++;
	}

}
// uçağın herhangibir tuşa basılmadığında hareketsiz kalması için yönleri sabitlemeye yarayan fonksiyon
void yonleriSabitle()
{
	for (int i = 5; i < 10; i++)
	{
		ucak[i].yon = YON_SABİT;
	}
}
// klavyeden okunan değerleri kontrol etmeye yarayan fonksiyon
void klavyeKontrol()
{
	klavyeOku(tuslar);
	// boşluğa basıldığında mermi oluşmasını sağlayan if yapısı
	if (tuslar[' '] != 0)
	{
		int ucakX = ucak[2].x[2];
		int ucakY = ucak[7].y[2];
		mermiOlustur(ucakX, ucakY);
		mermiNumarasi++;
	}
	// W tuşuna basıldığında uçağın yukarı hareket etmesini sağlayan if yapısı
	if (tuslar['W'] != 0)
	{
		for (int i = 5; i < 10; i++)
		{
			ucak[i].yon = YON_YUKARI;
		}
	}
	// S tuşuna basıldığında uçağın aşağı hareket etmesini sağlayan if yapısı
	if (tuslar['S'] != 0)
	{
		for (int i = 5; i < 10; i++)
		{
			ucak[i].yon = YON_ASAGI;
		}
	}
}
int main()
{
	srand(time(NULL));

	ucakOlustur();
	carpisanDusmanlarinNumaralari[0] = -1; // ilk düşmanın oyun başlar başlamaz gelmesi için
	while (true)
	{
		kursoruGizle();

		sahneyiTemizle();
		sinirlariOlustur();


		dusmanOlustur();


		klavyeKontrol();

		mermiyiSahneyeYerlestir();
		mermiyiHareketEttir();


		dusmaniSahneyeYerlestir();
		dusmaniHareketEttir();

		carpismaVarMı();


		ucagiHareketEttir();
		ucagiSahneyeYerlestir();


		yonleriSabitle();
		gotoxy(0, 0);
		sahneyiCiz();


		Sleep(30);
		donguSayaci++;
	}
}