/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI    : 2
**				��RENC� ADI      : �mer Can �al���r
**				��RENC� NUMARASI :
**				DERS GRUBU       : D
****************************************************************************/



#include<iostream>
#include<string>
#include<locale.h>
#include<conio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");


	char ch = 'a';
	int sayac_A = 0, sayac_E = 0, sayac_I = 0, sayac_� = 0, sayac_U = 0, sayac_� = 0, sayac_O = 0, sayac_� = 0;
	// enter tu�una bas�lana kadar �al��an  while d�ng�s�
	while (ch != '\r') {

		ch = _getche();
		// k���k ve b�y�k a harfini klavyeden girilmesi halinde ko�ul kullanarak sayma i�lemi.
		if (ch == 'a' || ch == 'A') {
			sayac_A++;
		}
		// k���k ve b�y�k e harfini klavyeden girilmesi halinde ko�ul kullanrak sayma i�lemi.
		else if (ch == 'e' || ch == 'E') {
			sayac_E++;
		}
		//i harfinin say�lmas� i�lemi. B�y�k i ' yi ASCII kodlar�ndan yararlanarak ald�k.
		else if (ch == 'i' || int(ch) == -104) {
			sayac_�++;
		}
		// k���k ve b�y�k o harfini klavyeden girilmesi halinde ko�ul  kullan�larak sayma i�lemi.
		else if (ch == 'o' || ch == 'O') {  
			sayac_O++;
		}
		//  k���k ve b�y�k  u harfini klavyeden girilmesi halinde ko�ul  kullan�larak sayma i�lemi.
		else if (ch == 'u' || ch == 'U') {   
			sayac_U++;
		}
		// k���k ve b�y�k  � harfini ASCII kodlar�ndan yararlanarak tespit etme ve ko�ul kullanarak sayma i�lemi.
		else if (int(ch) == -108 || int(ch) == -103) { 
			sayac_�++;
		}
		// k���k ve b�y�k  � harfini ASCII kodlar�ndan yararlanarak tespit etme ve ko�ul kullanarak sayma i�lemi.
		else if (int(ch) == -127 || int(ch) == -102) { 
			sayac_�++;
		}
		// k���k � harfini ASCII kodlar�ndan yararlanarak tespit etme ve ko�ul kullanarak sayma i�lemi.
		else if (int(ch) == -115 || ch == 'I') {  
			sayac_I++;
		}
	}

	cout << endl;
	cout << endl << "a n�n girilme sayisi :" << sayac_A << endl;
	cout << endl << "e n�n girilme sayisi :" << sayac_E << endl;
	cout << endl << "� n�n girilme sayisi :" << sayac_I << endl;
	cout << endl << "i n�n girilme sayisi :" << sayac_� << endl;
	cout << endl << "u n�n girilme sayisi :" << sayac_U << endl;
	cout << endl << "� n�n girilme sayisi :" << sayac_� << endl;
	cout << endl << "o n�n girilme sayisi :" << sayac_O << endl;
	cout << endl << "� n�n girilme sayisi :" << sayac_� << endl;


	cout << "\n\n";


	cout << "------------   Grafik   ------------";
	cout << "\n\n";

	char harfler[8] = { 'a','e','�','i','u','�','o','�' };
	int arraySayaclar[8] = { sayac_A,sayac_E,sayac_I,sayac_�,sayac_U,sayac_�,sayac_O,sayac_� };

	int yukseklik = arraySayaclar[0];
	// grafi�imizin y�ksekli�ini bulma i�lemi
	// arraySayaclar i�inde d�nmek i�in for kullan�m�
	for (int kontrol = 0; kontrol <= 7; kontrol++) {
		// her for d�ng�s�nde , arraySayaclar de�erleri i�erisinden daha b�y���n� tespit etme i�lemi
		if (arraySayaclar[kontrol] > yukseklik) {
			yukseklik = arraySayaclar[kontrol];
		}
	}
	// grafi�i olu�turma i�lemi
	// for d�ng�s� kullarak ve y�kseklikten yararlanarak , sat�r say�s� kadar d�nme i�lemi
	for (int satirSayisi = yukseklik; satirSayisi >= 1; satirSayisi--) {
		// for d�ng�s� kullanarak s�tunlarda d�nme i�lemi
		for (int sutun = 0; sutun <= 7; sutun++) {
			// grafikteki X harflerini basma i�lemi
			if (arraySayaclar[sutun] >= satirSayisi) { // >= olacak
				cout << "X  ";
			}
			// grafikteki bo�luklar� basma i�lemi
			else {
				cout << "   ";
			}
		}
		cout << endl;
	}
	// for d�ng�s� kullanarak grafik ile harfler aras�na s�n�r �izgisi olu�turma
	for (int sutun = 0; sutun <= 10; sutun++) {
		cout << "--";
	}
	cout << endl;
	// for d�ng�s� kullanarak grafi�in alt k�sm�na harfleri yerle�tirme i�lemi
	for (int sutun = 0; sutun <= 7; sutun++) {
		cout << harfler[sutun] << "  ";
	}
	cout << "\n\n";

	cout << "------------   Grafik   ------------";
	cout << "\n\n\n\n";

	system("pause");
	return 0;
}