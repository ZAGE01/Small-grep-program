Mygrep –projekti oli mielenkiintoinen harjoitus, joka opetti minulle komentorivityöskentelyä ja kehitti stringien käsittelyä. Ohjelma käynnistetään komentoriviltä ja sille voidaan haluttaessa antaa 2 tai 3 lisäargumenttia. Käytin ohjelmointiin Microsoft Visual Studio 2022:ta ja kääntämiseen Windows 10 Komentokehotetta.

Kun ohjelma käynnistetään pelkällä ohjelman nimellä, käyttäjältä pyydetään stringi ja hakustringi, jolloin hakustringiä haetaan suuremmasta stringistä. Jos pienempi stringi löytyy suuremmasta stringistä, käyttäjälle tulostetaan mistä kohtaa pienempi stringi löytyy (alkaen paikasta 0).

Kun ohjelmalle annetaan käynnistyksen yhteydessä ohjelman nimen lisäksi hakustringi ja samassa kansiossa olevan tiedoston nimi, hakee ohjelma stringiä tiedostosta ja jokainen rivi, jossa hakustringi esiintyy, tulostetaan käyttäjälle. Haluttaessa käyttäjä voi myös syöttää ohjelman nimen jälkeen lisäoption, joka kertoo tulosten yhteydessä rivinumerot, löydettyjen tulosten määrän tai molemmat. Käytettävät lisäoptiot ovat: “-oo”, “-ol” ja “-olo”.

Ohjelma antaa käyttäjälle myös virheilmoitukset, jos käynnistyksessä ilmenee ongelmia. Tällaisia voivat olla esimerkiksi tilanteet, joissa annettua tiedostoa ei löytynyt kyseisestä kansiosta, argumentit ovat virheellisiä tai niitä on liian vähän tai paljon.
