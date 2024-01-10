#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


void oneArgument() {
	int position = 0; // Kertoo paikan, josta hakustringi lˆytyy.
	string str; // Stringi, josta pienemp‰‰ stringi‰ haetaan. 
	string search_string; // Hakustringi.

	// Pyydet‰‰n k‰ytt‰j‰lt‰ suurempaa stringi‰ ja pienemp‰‰ stringi‰, jota haetaan suuremmasta stringist‰.
	cout << "\nGive a string from which to search for: ";
	getline(cin, str);
	cout << "Give search string: ";
	getline(cin, search_string);

	// Positioniin sijoitetaan paikka, josta stringi lˆytyy.
	position = str.find(search_string);

	// Jos position lˆytyy ennen stringin loppua.
	if (position != string::npos) {
		cout << "'" << search_string << "' found in " << str << " in position " << position << endl;
	}

	// Jos hakustringi‰ ei lˆydy isommasta stringist‰.
	else {
		cout << "'" << search_string << "' NOT found in " << str << endl;
	}
}


void threeArguments(string file_name, string search_string) {
	int counter = 0; // Laskuri kasvaa aina, kun tiedostosta lˆydet‰‰n hakustringi.
	ifstream file; // Tiedoston lukua varten.
	string str; // Tiedoston sis‰ll‰ olevat rivit, joista haetaan.

	// Avataan annettu tiedosto.
	file.open(file_name);

	// Jos tiedosto saadaan auki.
	if (file.is_open())
	{
		// K‰yd‰‰n tiedosto l‰pi rivitt‰in.
		while (getline(file, str)) {

			// Jos hakustringi lˆytyy tiedoston rivilt‰ ennen rivin loppua.
			// T‰llˆin rivi tulostetaan ja laskuria kasvatetaan yhdell‰.
			if (str.find(search_string) != string::npos) {
				cout << endl << str << endl;
				counter++;
			}
		}

		// Jos laskuri on 0 tiedoston l‰pi k‰ymisen j‰lkeen eli hakustringill‰ ei lˆytynyt yht‰k‰‰n tulosta.
		if (counter == 0) {
			cout << "\nNothing found with search term '" << search_string << "'." << endl;
		}

		// Suljetaan tiedosto lopuksi.
		file.close();
	}

	// Jos tiedostoa ei saada auki tai sit‰ ei lˆydy.
	else
	{
		cout << "\nError! Invalid file name." << endl;
	}
}


void fourArguments(string file_name, string search_string, string extra_options) {

	ifstream file; // Tiedoston lukua varten.
	string str; // Tiedoston rivit.
	int counter = 0; // Laskuri, joka pit‰‰ kirjaa lˆydettyjen tulosten m‰‰r‰st‰.
	int position = 0; // Lˆydetyn tuloksen rivinumero.

	// Jos annettu lis‰optio oli stringin‰ "-oo".
	// Tehd‰‰n sama k‰sittely kuin kolmella argumentilla mutta lopuksi tulostetaan myˆs lˆydettyjen rivien m‰‰r‰.
	if (string(extra_options) == "-oo") {
		file.open(file_name);

		if (file.is_open())
		{
			while (getline(file, str)) {

				if (str.find(search_string) != string::npos) {
					cout << endl << str << endl;
					counter++;
				}
			}

			if (counter == 0) {
				cout << "\nNothing found with search term '" << search_string << "'." << endl;
			}

			// Jos laskuri ei ole 0 eli hakustringill‰ lˆydettiin tuloksia.
			else {
				cout << "\nOccurrences of lines containing '" << search_string << "': " << counter << endl;
			}

			file.close();
		}
		else
		{
			cout << "\nError! Invalid file name." << endl;
		}
	}

	// Jos annettu lis‰optio oli stringin‰ "-ol".
	// Tehd‰‰n sama k‰sittely kuin kolmella argumentilla mutta k‰ytt‰j‰lle kerrotaan myˆs rivien numerot.
	else if (string(extra_options) == "-ol") {

		file.open(file_name);

		if (file.is_open())
		{
			while (getline(file, str)) {
				position++; // Position kasvaa yhdell‰ jokaisesta tarkistetusta rivist‰.

				if (str.find(search_string) != string::npos) {

					// Tulostetaan rivin lis‰ksi myˆs position eli rivi, jolta haku lˆytyi.
					cout << endl << position << ": " << str << endl;
					counter++;
				}
			}

			if (counter == 0) {
				cout << "\nNothing found with search term '" << search_string << "'." << endl;
			}

			file.close();
		}
		else
		{
			cout << "\nError! Invalid file name." << endl;
		}
	}

	// Jos annettu lis‰optio oli stringin‰ "-olo".
	// Tehd‰‰n sama k‰sittely kuin kolmella argumentilla mutta lopuksi tulostetaan myˆs lˆydettyjen rivien m‰‰r‰ sek‰ rivien numerot.
	else if (string(extra_options) == "-olo") {
		file.open(file_name);

		if (file.is_open())
		{
			while (getline(file, str)) {
				position++; // Position kasvaa yhdell‰ jokaisesta tarkistetusta rivist‰.

				if (str.find(search_string) != string::npos) {

					// Tulostetaan rivin lis‰ksi myˆs position eli rivi, jolta haku lˆytyi.
					cout << endl << position << ": " << str << endl;
					counter++;
				}
			}

			if (counter == 0) {
				cout << "\nNothing found with search term '" << search_string << "'." << endl;
			}

			// Jos laskuri ei ole 0 eli hakustringill‰ lˆydettiin tuloksia.
			else {
				cout << "\nOccurrences of lines containing '" << search_string << "': " << counter << endl;
			}

			file.close();
		}
		else
		{
			cout << "\nError! Invalid file name." << endl;
		}
	}

	// Jos lis‰optio ei ollut stringin‰ "-oo", "-ol" tai "-olo".
	else {
		cout << endl << extra_options << " is not a valid argument." << endl;
		cout << "Available options are -oo, -ol and -olo." << endl;
	}
}



// Argc kertoo argumenttien m‰‰r‰n, johon on laskettu mukaan myˆs ohjelman nimi,
// ja argv taulukosta jokaista argumenttia voidaan k‰sitell‰ erikseen.
int main(int argc, char* argv[]) {

	// Jos k‰ynnistyksess‰ annetaan pelkk‰ ohjelman nimi (argc==1) siirtyy ohjelma yhden argumentin aliohjelmaan.
	if (argc == 1) {
		oneArgument();
	}

	// Jos k‰ynnistyksess‰ annetaan kolme argumenttia, k‰ytet‰‰n seuraavaa aliohjelmaa.
	// Aliohjelmaan vied‰‰n mukana tiedoston nimi sek‰ k‰ynnistyksen yhteydess‰ annettu hakustringi.
	else if (argc == 3) {
		threeArguments(argv[2], argv[1]);
	}

	// Jos argumentteja on nelj‰.
	// Aliohjelmaan vied‰‰n mukana tiedoston nimi, hakustringi sek‰ annettu lis‰optio.
	else if (argc == 4) {
		fourArguments(argv[3], argv[2], argv[1]);
	}

	// Jos argumentteja on esimerkiksi kaksi tai muu virheellinen m‰‰r‰, tulostetaan seuraava virhe.
	else {
		cout << "\nYou can type the program name to make a search from your own string." << endl << endl;
		cout << "You can also type the program name, a searching string and a file name separated by spaces to search the file for the string." << endl;
		cout << "Additionally you can input extra option after the program name to view the lines containing the search string." << endl;
		cout << "Available extra options are -oo, -ol and -olo." << endl;
	}

	return 0;
}