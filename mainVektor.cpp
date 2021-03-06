#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using std::sort;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct studentas {
	string vardas = "", pav = "";
	float paz[10], vid, med, egz, gal;
};


void spausdinimas(studentas stud) {
	
	//cout << "---------------------------------------------"<< "\n";
	cout << stud.vardas << "          " << stud.pav << "         ";
	cout << std::fixed;
	cout << std::setprecision(2);
	cout << stud.gal <<"\n";

}

int int_imimas() {
	int pazymys;
	cin >> pazymys;

	//Error check
	while ((cin.good() == false) or !(0 <= pazymys)) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> pazymys;
	}
	return pazymys;
};

int ndskaiciaus_imimas() {
	int nskaicius;
	cin >> nskaicius;

	//Error check
	while ((cin.good() == false) or !(nskaicius <= 10 && 0 <= nskaicius)) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> nskaicius;
	}
	return nskaicius;
};

int menu_pasirinkimas() {
	int pasirink;
	cin >> pasirink;

	//Error check
	while ((cin.good() == false) or !(pasirink == 1 or pasirink == 0)) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> pasirink;
	}
	return pasirink;
};

float pazymiu_imimas() {
	float pazymys;
	cin >> pazymys;

	//Error check
	while ((cin.good() == false) or !(pazymys<=10 && 1<=pazymys) ) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> pazymys;
	}
	return pazymys;
};

string vardo_imimas() {
	string vard;
	cin >> vard;

	//Error check
	while (cin.good() == false) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> vard;
	}
	return vard;
}

studentas sukurimas() {
	studentas zmogus;
	cout << "iveskite varda:   "; zmogus.vardas = vardo_imimas();
	cout << "iveskite pavarde: "; zmogus.pav = vardo_imimas();
	//paprasome pazymiu(demonstracine funkcijos vieta):
	int arrandom = 0;
	int nd = 1;
	zmogus.vid = 0;
	cout << "ar generuoti atsitiktinai?(0-ne, 1-taip)"; arrandom = menu_pasirinkimas();
	if (arrandom == 0) {
		cout << "kiek ND pazymiu?: "; nd = ndskaiciaus_imimas();

		vector < float > pazymiai(nd);
		zmogus.vid = 0;
		for (int i = 0; i < nd; i++)
		{
			cout << "Iveskite " << i + 1 << "-aji pazymi: "; pazymiai.push_back(pazymiu_imimas());

			zmogus.vid += pazymiai[i];

		};
		int pasirinkimas = 0;
		cout << "ar ivesite papildoma pazymi?(0-ne, 1- taip)"; pasirinkimas = menu_pasirinkimas();

		while (pasirinkimas == 1) {
			nd++;

			cout << "Iveskite " << nd << "-aji pazymi: "; pazymiai[nd-1] = pazymiu_imimas();

			cout << "ar ivesite papildoma pazymi?(0-ne, 1- taip)"; pasirinkimas = menu_pasirinkimas();
		}
		for (int i = 0; i < nd; i++) { zmogus.paz[i]=pazymiai[i]; };
		// demonstracijos pabaiga.
		cout << "Iveskite egzamino rezultata: "; zmogus.egz = pazymiu_imimas();
		cout << endl;
	}
	else
	{
		int nd = rand() % 10 + 1;
		for (int i = 0; i < nd; i++) {
			zmogus.paz[i] = rand() % 10 + 1;
			//cout << zmogus.paz[i];
			zmogus.vid += zmogus.paz[i];
		}
		zmogus.egz = rand() % 10 + 1;
	};
	//cout << zmogus.vid;
	zmogus.vid = zmogus.vid / nd;
	sort(zmogus.paz, zmogus.paz + nd);
	if (nd % 2 != 0) { zmogus.med = (float)zmogus.paz[nd / 2]; }
	else { zmogus.med = (float)((zmogus.paz[(nd - 1) / 2] + zmogus.paz[nd / 2])) / 2.0; };

	return zmogus;
};
/*
int main() {
	//studentas Grupe[10];
	int n = 0;
	cout << "Iveskite studentu skaiciu: ";
	cin >> n;

	studentas* grupe = new studentas[n];
	for (int i = 0; i < n; i++) { cout << "Iveskite " << i + 1 << "-aji vada: "; cin >> grupe[i].vardas; }
	for (int i = 0; i < n; i++) { cout << grupe[i].vardas << " : "; }
	cout << endl;

	studentas* temp = new studentas[n + 1];
	for (int i = 0; i < n; i++) temp[i] = grupe[i];
	for (int i = 0; i < n; i++) { cout << temp[i].vardas << " : "; }
	cout << endl;

	cout << "Iveskite " << n + 1 << "-aji vada: ";
	cin >> temp[n].vardas;
	for (int i = 0; i < n + 1; i++) { cout << temp[i].vardas << " : "; }
	cout << endl;

	delete[] grupe;
	n++;
	grupe = new studentas[n];
	for (int i = 0; i < n; i++) grupe[i] = temp[i];
	delete[] temp;
	cout << "grupe" << endl;
	for (int i = 0; i < n; i++) { cout << grupe[i].vardas << " : "; }
	cout << endl;
}
*/
int main() {
	int n = 0;
	cout << "kiek studentu bus?:  "; n = int_imimas();
	studentas* grupe = new studentas[n];
	for (int i = 0; i < n; i++) { grupe[i] = sukurimas(); };
	//spausdinimas
	int pasirinkimas = 0;
	cout << "Spausdinti galutini pagal vidurki(0) ar mediana(1)"; pasirinkimas = menu_pasirinkimas();
	if (pasirinkimas == 0) {
		for (int i = 0; i < n; i++){
			grupe[i].gal = 0.4 * grupe[i].vid + 0.6 * grupe[i].egz;
	}
		cout << "vardas         Pavarde         galutinis(vid)" << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			grupe[i].gal = 0.4 * grupe[i].med + 0.6 * grupe[i].egz;
		}
		cout << "vardas         Pavarde         galutinis(med)" << "\n";
	}
	cout << "---------------------------------------------" << "\n";
	for (int i = 0; i < n; i++) { spausdinimas(grupe[i]); };
	cout << endl;

	delete[] grupe;
}