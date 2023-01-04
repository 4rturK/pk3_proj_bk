#include <iostream>
#include "auta_funkcje.h"
#include <fstream>
#include <list>
#include <string>

using namespace std;


void Auto::print_auto() {


    cout << "\nNumer pojazdu:\t\t\t" << this->ID_auto;
    cout << "\nPojemnosc pojazdu:\t\t" << this->pojemnosc_auto;
    cout << "\nCzy pojazd jest w treasie:\t";
    if (this->trasa) {
        cout << "tak\n";
    }
    else {
        cout << "nie\n";
    }
};

void ListaAut::save_auto(const string& file_name) {

    Auto pojazd = *this->head;

    ofstream file(file_name, ios::binary);

    while (1) {

        Auto dane;
        dane.ID_auto = pojazd.ID_auto;
        dane.pojemnosc_auto = pojazd.pojemnosc_auto;
        dane.trasa = pojazd.trasa;
        file.write(reinterpret_cast<const char*>(&dane), sizeof(dane));
        if (pojazd.next == nullptr) {
            break;
        }
        else {
            pojazd = *pojazd.next;
        }
    }

    file.close();
};

void ListaAut::load_auto(const string& file_name) {

    Auto pojazd;

    ifstream file(file_name, ios::binary);

    Auto poprz_poj;

    while (1) {
        file.read(reinterpret_cast<char*>(&pojazd), sizeof(pojazd));

        if (poprz_poj == pojazd) { break; }

        this->dod_do_listy_aut(pojazd);
        poprz_poj = pojazd;
    }

    file.close();

    this->sort_zawartosci_auto();

}

void ListaAut::print_trasa() {
    for (Auto& pojazd : zawartosc_auto) {
        if (pojazd.trasa == 1) { pojazd.print_auto(); }
    }
};

void ListaAut::print_wolne() {
    for (Auto& pojazd : zawartosc_auto) {
        if (pojazd.trasa == 0) { pojazd.print_auto(); }
    }
};

void ListaAut::sort_zawartosci_auto() {

    Auto* auto1 = this->head, * auto2 = this->tail;
    int a = -1;
    bool flaga = 1;
    while (1) {

        if (auto1->next == nullptr) {
            auto1 = this->head;
        }

        auto2 = auto1;
        auto1 = auto1->next;


        if (auto1->ID_auto < auto2->ID_auto) {
            auto auto2prev = auto2->prev;
            auto auto1next = auto1->next;

            //warunek dla pierwszego elementu listy
            if (auto2prev == nullptr) {
                this->head = auto1;
                auto1next->prev = auto2;
                auto2->next = auto1next;
                auto2->prev = auto1;
                auto1->next = auto2;
                auto1->prev = nullptr;
            }

            //warunek dla ostatniego elementu listy
            else if (auto1next == nullptr) {
                auto2prev->next = auto1;
                auto2->next = nullptr;
                auto2->prev = auto1;
                auto1->next = auto2;
                auto1->prev = auto2prev;
            }

            //warunek dla dowolnego elementu listy
            else {
                auto2prev->next = auto1;
                auto1next->prev = auto2;
                auto2->next = auto1next;
                auto2->prev = auto1;
                auto1->next = auto2;
                auto1->prev = auto2prev;
            }

            flaga = 1;
        }


        if (auto1->next == nullptr) {
            if (flaga) {
                a++;
                auto1 = this->head;
                flaga = 0;
            }
            else { break; }
        }

    }

    cout << "Auta:\t\t";
    if (a == 0) {
        cout << "Tablica byla posortowana\n";
    }
    else {
        cout << "Liczba przemieszczonych elementow: " << a + 1 << endl;
    }

    //Tworzenie listy z zawartoscia
    Auto* pojazd = this->head;

    zawartosc_auto.clear();
    while (1) {
        zawartosc_auto.push_back(*pojazd);
        if (pojazd->next == nullptr) {
            break;
        }
        else {
            pojazd = pojazd->next;
        }
    }
}

void ListaAut::print_poj_trasa() {
    string zmienna;
    int poj;
    bool trasa = 1;
    cout << "Minimalna pojemnosc: ";
    cin >> poj;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Podaj liczbe: ";
        cin >> poj;
    }
    cin.clear();


    while (trasa) {
        cout << "\nWyswietlic pojazdy w trasie (trasa), czy wolne (wolne)?\n";
        cin >> zmienna;
        if (zmienna == "trasa" || zmienna == "Trasa") { break; }
        else if (zmienna == "wolne" || zmienna == "Wolne") { trasa = 0; break; }
        else { cout << "\nNie podano poprawnej komendy.\n"; }

    }

    list<Auto> listaPomoc, listaWyjsie;
    for (Auto& pojazd : zawartosc_auto) {
        if (pojazd.trasa == trasa) { listaPomoc.push_back(pojazd); }
    }
    for (Auto& pojazd : listaPomoc) {
        if (pojazd.pojemnosc_auto >= poj) { listaWyjsie.push_back(pojazd); }
    }

    for (Auto& pojazd : listaWyjsie) {
        pojazd.print_auto();
    }

};

void ListaAut::dod_do_listy_aut(Auto pojazd) {

    Auto* newAuto = new Auto(pojazd);

    if (this->head == nullptr) {
        this->head = newAuto;
        this->tail = newAuto;
        return;
    }
    this->tail->next = newAuto;
    newAuto->prev = this->tail;
    this->tail = newAuto;

}

void ListaAut::print_list_aut() {

    Auto* pojazd = this->head;

    while (1) {

        cout << "\nNumer pojazdu:\t\t\t" << pojazd->ID_auto;
        cout << "\nPojemnosc pojazdu:\t\t" << pojazd->pojemnosc_auto;
        cout << "\nCzy pojazd jest w treasie:\t";
        if (pojazd->trasa) {
            cout << "tak\n";
        }
        else {
            cout << "nie\n";
        }

        //Jak bedzie to w warunku while, to nie wyœwietli ostatniego rekordu
        if (pojazd->next == nullptr) {
            break;
        }
        else {
            pojazd = pojazd->next;
        }

    }
};