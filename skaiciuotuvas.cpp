// skaiciuotuvas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
const int masyvo_dydis = 100;
void duomenu_skaitymas(string& linija);
void skaiciavimas(double& skaicius1, double& skaicius2, char& simbolis, string linija, double& atsakymas);
int main()
{
	double skaicius1 = 0, skaicius2 = 0;
	double atsakymas = 0;
	char simbolis;
	string linija;
		duomenu_skaitymas(linija);
		skaiciavimas(skaicius1, skaicius2, simbolis, linija, atsakymas);
		return 0;
}
void duomenu_skaitymas(string& linija)
{
	cout << "IVESKITE SALYGA(2 SKAICIUS)" << endl;
	cout << "SALYGA: ";  cin >> linija;
	//cout << linija;
}
void skaiciavimas(double& skaicius1, double& skaicius2, char& simbolis, string linija, double & atsakymas)
{
	char laikinas_kintamasis[masyvo_dydis];
	string ivestis;
	bool salyga = true;
	string skaicius1_string;
	string skaicius2_string;
	int ciklo_dydis = 0;
	while (salyga)
	{
		salyga = false;
		if (atsakymas > 0)
		{
			cout << "IVESKITE SALYGA(2 SKAICIUS)" << endl;
			cout << "SALYGA: " << atsakymas << " ";  cin >> linija;
		}
		//cout << linija;

		for (int i = 0; i < linija.length(); i++)
		{
			laikinas_kintamasis[i] = linija.at(i);
		}
		for (int i = 0; i < linija.length(); i++)
		{
			if (laikinas_kintamasis[i] == '+' || laikinas_kintamasis[i] == '-' || laikinas_kintamasis[i] == '*' || laikinas_kintamasis[i] == '/')
			{
				ciklo_dydis = i;
				simbolis = laikinas_kintamasis[i];
				//cout << simbolis << endl;
				if(atsakymas <= 0)
				{
					for (int j = 0; j < ciklo_dydis; j++)
					{
						if (laikinas_kintamasis[j] != ' ')
							skaicius1_string += laikinas_kintamasis[j];
					}
				}

				for (int k = ciklo_dydis + 1; k < linija.length(); k++)
				{
					if (laikinas_kintamasis[k] != ' ')
						skaicius2_string += laikinas_kintamasis[k];
				}
				break;
			}
		}
		

		if (atsakymas <= 0)
		{
			stringstream string1(skaicius1_string);
			string1 >> skaicius1;
		}
		else
		{
			skaicius1 = atsakymas;
			atsakymas = 0;
			//cout << skaicius1 << " " << atsakymas << endl;
		}
			
		
		stringstream string2(skaicius2_string);
		string2 >> skaicius2;
		skaicius2_string.clear();
		//cout << skaicius2 << endl;
		switch (simbolis)
		{
		case '+':
			atsakymas = skaicius1 + skaicius2;
			break;
		case '-':
			atsakymas = skaicius1 - skaicius2;
			break;
		case '*':
			atsakymas = skaicius1 * skaicius2;
			break;
		case '/':
			atsakymas = skaicius1 / skaicius2;
			break;
		}
		skaicius1 = 0;
		skaicius2 = 0;
		cout << "ATSAKYMAS: " << atsakymas << endl;
		cout << "JEI NORITE TESTI SKAICIAVIMA SU GAUTU ATSAKYMU RASYKITE: TESTI" << endl;
		cout << "JEI NORITE BAIGTI SKAICIAVIMUS ISJUNGITE PROGRAMA ARBA RASYKITE: ISEITI" << endl;
		cin >> ivestis;
		transform(ivestis.begin(), ivestis.end(), ivestis.begin(), ::toupper);
		cout << endl;
		if (ivestis == "TESTI")
		{
			salyga = true;
		}
		else
		{
			cout << "ACIU, KAD NAUDOJOTES MUSU SKAICIAVIMO PROGRAMA, SPAUSKITE BET KOKI KLAVIATUROS MYGTUKA" << endl;
			break;
		}
			
			
		
	}
	
	
	
}
