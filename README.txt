Mygrep –projekti oli mielenkiintoinen harjoitus, joka opetti minulle komentorivityöskentelyä ja kehitti stringien käsittelyä. Ohjelma käynnistetään komentoriviltä ja sille voidaan haluttaessa antaa 2 tai 3 lisäargumenttia. Käytin ohjelmointiin Microsoft Visual Studio 2022:ta ja kääntämiseen Windows 10 Komentokehotetta.

Kun ohjelma käynnistetään pelkällä ohjelman nimellä, käyttäjältä pyydetään stringi ja hakustringi, jolloin hakustringiä haetaan suuremmasta stringistä. Jos pienempi stringi löytyy suuremmasta stringistä, käyttäjälle tulostetaan mistä kohtaa pienempi stringi löytyy (alkaen paikasta 0).

Kun ohjelmalle annetaan käynnistyksen yhteydessä ohjelman nimen lisäksi hakustringi ja samassa kansiossa olevan tiedoston nimi, hakee ohjelma stringiä tiedostosta ja jokainen rivi, jossa hakustringi esiintyy, tulostetaan käyttäjälle. Haluttaessa käyttäjä voi myös syöttää ohjelman nimen jälkeen lisäoption, joka kertoo tulosten yhteydessä rivinumerot, löydettyjen tulosten määrän tai molemmat. Käytettävät lisäoptiot ovat: “-oo”, “-ol” ja “-olo”.

Ohjelma antaa käyttäjälle myös virheilmoitukset, jos käynnistyksessä ilmenee ongelmia. Tällaisia voivat olla esimerkiksi tilanteet, joissa annettua tiedostoa ei löytynyt kyseisestä kansiosta, argumentit ovat virheellisiä tai niitä on liian vähän tai paljon.

--------------------------------------------------

The Mygrep project was an interesting exercise that taught me command-line operation and improved string manipulation. The program is launched from the command line and can optionally be given 2 or 3 additional arguments. I used Microsoft Visual Studio 2022 for programming and Windows 10 Command Prompt for compilation.

When the program is started with just the program name, the user is prompted for a string and a search string. The program then searches for the search string within the larger string. If the smaller string is found within the larger string, the program prints the position where the smaller string is located (starting from position 0) to the user.

When the program is given, during startup, the program name along with the search string and the name of a file in the same directory, the program searches for the string in the file. Each line containing the search string is then printed to the user. Optionally, the user can input additional options after the program name, which specify whether to display line numbers, the number of found results, or both. The available additional options are "-oo," "-ol," and "-olo."

The program also provides error messages to the user if any issues occur during startup. Examples of such issues include situations where the specified file is not found in the given directory, the arguments are incorrect, or there are too few or too many of them.
