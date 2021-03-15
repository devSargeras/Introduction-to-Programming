/****************************************************************************
**							SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**					    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI     : 2. �DEV
**				��RENC� ADI       : �MER CAN �ALI�IR
**				��RENC� NUMARASI  :
**				DERS GRUBU        : D
****************************************************************************/

#include<iostream>
#include<string>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;

// random gelen de�erin tekrar edip etmedi�ini bulma.Tekrar ediyor mu ?   Evet(1) / Hay�r(0)
int tekrarEdiyorMu(int rastgeleSayi, char harf[5][10]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			// harf matrisinin i�erisinde, random olu�an say�n�n olup olmad���n� kontrol etme i�lemi.
			if (harf[i][j] == char(rastgeleSayi)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "Turkish");
	
	// rastgele ve tekrars�z matris olu�turma i�lemi.
	srand(time(NULL));
	char harf[5][10];
	int a, b;
	// 2 boyutlu 5 e 10 luk bir matrisi olu�turmak i�in i� i�e 2 for kullan�m�.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10;) {
			// random de�er �retme i�lemi.
			int rastgeleSayi1 = (rand() % 26) + 65;
			// �retilen random de�erin tekrar edip etmedi�ini sorgulama i�lemi.
			a = tekrarEdiyorMu(rastgeleSayi1, harf);

			int rastgeleSayi2 = (rand() % 26) + 97;
			b = tekrarEdiyorMu(rastgeleSayi2, harf);
			// tekrar yoksa ve �ift sut�nlardan birindeyse , eleman� alma i�lemi. 
			if (a == 0 && (j % 2 == 0)) {
				harf[i][j] = char(rastgeleSayi1);
				j++;
			}
			// tekrar yoksa ve tek sut�nlardan birindeyse , eleman� alma i�lemi. 
			else if (b == 0 && (j % 2 == 1)) {
				harf[i][j] = char(rastgeleSayi2);
				j++;
			}
		}
	}
	cout << "Tekrarsiz ve  Rastgele Dizi" << endl;

	// rastgele matrisi bast�rma i�lemi.	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << harf[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "S�ralanm�� Dizi" << endl;

	
	int tutucu;
	// s�ralanm�� matrisi olu�turma i�lemi.
	for (int m = 0; m < 5; m++) {
		for (int n = 0; n < 10; n++) {
			int s = n;
			// harf[m][n] eleman� ve bu elemandan sonraki elemanlarda d�nme i�lemi.
			for (int i = m; i < 5; i++) {
				for (int j = s; j < 10; j++) {
					// k���k olan eleman� tespit edip , d�ng�n�n ba��ndaki elemanla yer de�i�tirme i�lemi.
					if (harf[m][n] > harf[i][j]) {
						tutucu = harf[m][n];
						harf[m][n] = harf[i][j];
						harf[i][j] = tutucu;
					}
				}
				s = 0;
			}
		}
	}

	// s�ralanm�� matrisi bast�rma i�lemi.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << harf[i][j] << "\t";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}
