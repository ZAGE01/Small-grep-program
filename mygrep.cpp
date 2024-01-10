#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


void oneArgument() {
	int position = 0; // Kertoo paikan, josta hakustringi löytyy.
	string str; // Stringi, josta pienempää stringiä haetaan. 
	string search_string; // Hakustringi.

	// Pyydetään käyttäjältä suurempaa stringiä ja pienempää stringiä, jota haetaan suuremmasta stringistä.
	cout << "\nGive a string from which to search for: ";
	getline(cin, str);
	cout << "Give search string: ";
	getline(cin, search_string);

	// Positioniin sijoitetaan paikka, josta stringi löytyy.
	position = str.find(search_string);

	// Jos position löytyy ennen stringin loppua.
	if (position != string::npos) {
		cout << "'" << search_string << "' found in " << str << " in position " << position << endl;
	}
	
	// Jos hakustringiä ei löydy isommasta stringistä.
	else {
		cout << "'" << search_string << "' NOT found in " << str << endl;
	}
}


void threeArguments(string file_name, string search_string) {
	int counter = 0; // Laskuri kasvaa aina, kun tiedostosta löydetään hakustringi.
	ifstream file; // Tiedoston lukua varten.
	string str; // Tiedoston sisällä olevat rivit, joista haetaan.

	// Avataan annettu tiedosto.
	file.open(file_name);

	// Jos tiedosto saadaan auki.
	if (file.is_open())
	{
		// Käydään tiedosto läpi rivittäin.
		while (getline(file, str)) {
			
			// Jos hakustringi löytyy tiedoston riviltä ennen rivin loppua.
			// Tällöin rivi tulostetaan ja laskuria kasvatetaan yhdellä.
			if (str.find(search_string) != string::npos) {
				cout << endl << str << endl;
				counter++;
			}
		}

		// Jos laskuri on 0 tiedoston läpi käymisen jälkeen eli hakustringillä ei löytynyt yhtäkään tulosta.
		if (counter == 0) {
			cout << "\nNothing found with search term '" << search_string << "'." << endl;
		}

		// Suljetaan tiedosto lopuksi.
		file.close();
	}

	// Jos tiedostoa ei saada auki tai sitä ei löydy.
	else
	{
		cout << "\nError! Invalid file name." << endl;
	}
}


void fourArguments(string file_name, string search_string, string extra_options) {

	ifstream file; // Tiedoston lukua varten.
	string str; // Tiedoston rivit.
	int counter = 0; // Laskuri, joka pitää kirjaa löydettyjen tulosten määrästä.
	int position = 0; // Löydetyn tuloksen rivinumero.

	// Jos annettu lisäoptio oli stringinä "-oo".
	// Tehdään sama käsittely kuin kolmella argumentilla mutta lopuksi tulostetaan myös löydettyjen rivien määrä.
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

			// Jos laskuri ei ole 0 eli hakustringillä löydettiin tuloksia.
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

	// Jos annettu lisäoptio oli stringinä "-ol".
	// Tehdän sama käsittely kuin kolmella argumentilla mutta käyttäjälle kerrotaan myös rivien numerot.
	else if (string(extra_options) == "-ol") {

		file.open(file_name);

		if (file.is_open())
		{
			while (getline(file, str)) {
				position++; // Position kasvaa yhdellä jokaisesta tarkistetusta rivistä.

				if (str.find(search_string) != string::npos) {

					// Tulostetaan rivin lisäksi myös position eli rivi, jolta haku löytyi.
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

	// Jos annettu lisäoptio oli stringinä "-olo".
	// Tehdään sama käsittely kuin kolmella argumentilla mutta lopuksi tulostetaan myös löydettyjen rivien määrä sekä rivien numerot.
	else if (string(extra_options) == "-olo") {
		file.open(file_name);

		if (file.is_open())
		{
			while (getline(file, str)) {
				position++; // Position kasvaa yhdellä jokaisesta tarkistetusta rivistä.

				if (str.find(search_string) != string::npos) {

					// Tulostetaan rivin lisäksi myös position eli rivi, jolta haku löytyi.
					cout << endl << position << ": " << str << endl;
					counter++;
				}
			}

			if (counter == 0) {
				cout << "\nNothing found with search term '" << search_string << "'." << endl;
			}

			// Jos laskuri ei ole 0 eli hakustringillä löydettiin tuloksia.
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

	// Jos lisäoptio ei ollut stringinä "-oo", "-ol" tai "-olo".
	else {
		cout << endl << extra_options << " is not a valid argument." << endl;
		cout << "Available options are -oo, -ol and -olo." << endl;
	}
}



// Argc kertoo argumenttien määrän, johon on laskettu mukaan myös ohjelman nimi,
// ja argv taulukosta jokaista argumenttia voidaan käsitellä erikseen.
int main(int argc, char *argv[]) {

	// Jos käynnistyksessä annetaan pelkkä ohjelman nimi (argc==1) siirtyy ohjelma yhden argumentin aliohjelmaan.
	if (argc == 1) {
		oneArgument();
	}

	// Jos käynnistyksessä annetaan kolme argumenttia, käytetään seuraavaa aliohjelmaa.
	// Aliohjelmaan viedään mukana tiedoston nimi sekä käynnistyksen yhteydessä annettu hakustringi.
	else if (argc == 3) {
		threeArguments(argv[2], argv[1]);
	}

	// Jos argumentteja on neljä.
	// Aliohjelmaan viedään mukana tiedoston nimi, hakustringi sekä annettu lisäoptio.
	else if (argc == 4) {
		fourArguments(argv[3], argv[2], argv[1]);
	}

	// Jos argumentteja on esimerkiksi kaksi tai muu virheellinen määrä, tulostetaan seuraava virhe.
	else {
		cout << "\nYou can type the program name to make a search from your own string." << endl << endl;
		cout << "You can also type the program name, a searching string and a file name separated by spaces to search the file for the string." << endl;
		cout << "Additionally you can input extra option after the program name to view the lines containing the search string." << endl;
		cout << "Available extra options are -oo, -ol and -olo." << endl;
	}

	return 0;
}
