#include <iostream>
#include <vector>

using namespace std;
class Student {
    public:
        vector<int> oceny;
        string imie;
        string nazwisko;
        int nr;
        double srednia;
        void wyswietlDane() {
          cout << "Imie: " << imie << ", Nazwisko: " << nazwisko << ", Numer w dzienniku: " << nr << " , Średnia ocen: " << srednia << endl; 
          cout << "Oceny: ";
          for(int i : oceny){
            cout << i << "";
          };
          cout << endl;
        }
};
class Dziennik {
    private:
        vector<Student> listaUczniow;
    public:
        void dodajUcznia() {
            Student nowy;
            cout << "Wpisz imie: ";
            cin >> nowy.imie;
            cout << "Wpisz nazwisko: ";
            cin >> nowy.nazwisko;
            nowy.nr = listaUczniow.size() + 1;
            listaUczniow.push_back(nowy);
            cout << "Dodano ucznia!\n";
        }
        void wyswietlUczni() {
            if (listaUczniow.empty()) {
                cout << "Lista jest pusta!\n";
                return;
            } else {
                for (int i = 0; i < listaUczniow.size(); i++) {
                    listaUczniow[i].wyswietlDane();
                }
            }
        }
        void dodajOcene(){
            int choiceOcena, nowaOcena;
            for (int i = 0; i < listaUczniow.size(); i++) {
                    listaUczniow[i].wyswietlDane();
                }
                cout << "Któremu uczniowi chcesz dodać ocenę: ";
                cin >> choiceOcena;
                cout <<"Jaką ocenę chcesz dodać?: ";
                cin >> nowaOcena;
                listaUczniow[choiceOcena - 1].oceny.push_back(nowaOcena);
               // for ( int j = 0; j < listaUczniow.oceny.size(); j++) {
                    
               // }
        }
        void sredniaOcen() {
            if (listaUczniow.empty()) {
                cout << "Brak uczniów, brak ocen.\n";
                return;
            }
            double sumaOcenUcznia, sredniaUcznia;
            int liczbaOcen;
            for (int i = 0; i < listaUczniow.size(); i++) { // Wchodzi w ucznia
                if (listaUczniow[i].oceny.size() == 0){
                    cout << "Brak ocen";
                    continue;
                }
                sumaOcenUcznia = 0;
                liczbaOcen = 0;
                for (int j = 0; j < listaUczniow[i].oceny.size(); j++ ) { // Wchodzi w jego oceny
                    liczbaOcen++;
                    sumaOcenUcznia+=listaUczniow[i].oceny[j]; // Dodaje oceny tego ucznia
                }
                sredniaUcznia = sumaOcenUcznia / liczbaOcen;
                cout << "Średnia ocen ucznia " << listaUczniow[i].imie << " wynosi: " << sredniaUcznia << endl;
                listaUczniow[i].srednia = sredniaUcznia;
            }

        }
};
int main() {
    Dziennik mojDziennik;
    int choice;
    do {
    cout << "Witaj, co chcesz zrobić?\n1.Dodaj ucznia\n2.Dodaj ocene\n3.Wyświetl dane i oceny ucznia\n4.Wyświetl średnią ocen wszytskich uczni\nWybór: ";
    cin >> choice;
    if (choice == 1) {
            mojDziennik.dodajUcznia();
    } else if (choice == 2) {
            mojDziennik.dodajOcene();
    } else if (choice == 3) {
            mojDziennik.wyswietlUczni();
    } else {
            mojDziennik.sredniaOcen();
    }
    } while (choice != 0);
    return 0;
}

/* 
Struktura kodu:
1. Klasa Student
    - imie
    - nazwisko
    - ocena
2. Klasa dziennik
    - lista uczni
    - w niej moge dodać ucznia
    - oblicze średnia
*/