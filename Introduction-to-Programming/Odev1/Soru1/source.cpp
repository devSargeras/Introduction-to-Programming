/****************************************************************************
**							SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**						B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI     : 1
**				��RENC� ADI       : �mer Can �al���r
**				��RENC� NUMARASI  :
**				DERS GRUBU        : D
****************************************************************************/

#include<iostream>
#include<string>
#include<locale.h> 
using namespace std;


int main() {
	setlocale(LC_ALL, "Turkish");

	int boslukSiniri1 = 6, boslukSiniri2 = 7;
	// sat�r say�s� kadar d�nme i�lemi
	for (int i = 1; i <= 5; i++) {
		// s�tun say�s� kadar d�nme i�lemi
		for (int j = 1; j <= 12; j++) {
			// ko�ul sa�land��� durumda bo�luk bas�larak �eklin orta k�sm�n� olu�turma i�lemi
			if ((j >= boslukSiniri1 && j < 7) || (j >= 7 && j <= boslukSiniri2)) {
				cout << "  ";
			}
			// if ko�ulu sa�lanmad��� durumda y�ld�z basma i�lemi
			else {
				cout << "* ";
			}
		}
		boslukSiniri1 -= 1;
		boslukSiniri2 += 1;
		cout << endl;
	}

	cout << "\n";

	int boslukSiniri3 = 2, boslukSiniri4 = 11;
	// sat�r say�s� kadar d�nme i�lemi
	for (int i = 1; i <= 5; i++) {
		// s�tun say�s� kadar d�nme i�lemi
		for (int j = 1; j <= 12; j++) {
			// ko�ul sa�land��� durumda bo�luk bas�larak �eklin orta k�sm�n� olu�turma i�lemi
			if ((j >= boslukSiniri3 && j < 7) || (j >= 7 && j <= boslukSiniri4)) {
				cout << "  ";
			}
			// if ko�ulu sa�lanmad��� durumda y�ld�z basma i�lemi
			else {
				cout << "* ";
			}
		}
		boslukSiniri3 += 1;
		boslukSiniri4 -= 1;
		cout << endl;
	}


	system("pause");
	return 0;
}