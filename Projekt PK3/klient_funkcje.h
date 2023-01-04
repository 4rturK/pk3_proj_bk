#ifndef klient_funkcje_h
#define klient_funkcje_h

#include <iostream>
#include <list>
#include <string>

using namespace std;

class Klient {
protected:
    int ID_klient;
    string nazwa;
    string NIP;
    Klient* next;
    Klient* prev;

public:

    //Konstruktor
    Klient(int id = -1, string nazw = "brak", string NIP = "brak") {
        this->ID_klient = id;
        this->nazwa = nazw;
        this->NIP = NIP;
        this->next = nullptr;
        this->prev = nullptr;
    }

    //Destruktor
    ~Klient() {};

    //kopiujacy
    Klient(const Klient& a) {
        this->ID_klient = a.ID_klient;
        this->nazwa = a.nazwa;
        this->NIP = a.NIP;
        this->next = a.next;
        this->prev = a.prev;
    }

    //Operator pozwalaj¹cy do porównywania obiektów w inny sposób ni¿ adresy w pamiêci
    friend bool operator==(const Klient& c1, const Klient& c2) {
        return c1.ID_klient == c2.ID_klient;
    };

    //wypisanie danych jednego klienta
    void print_klient();

    friend class ListaKli;

};

class ListaKli {
private:
    Klient* head;
    Klient* tail;

    list<Klient> zawartosc_klient;

public:
    ListaKli() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    //Zapis listy aut do pliku .bin
    void save_klient(const string& filename);

    //Odczyt listy aut z pliku .bin
    void load_klient(const string& file_name);

    //Dodaje na koniec listy element
    void dod_do_listy_klient(Klient pojazd);

    //Wyswietlanie listy aut
    void print_list_klient();

    //sortuje liste na podstawie id + utworzenie listy 'zawartosc'
    void sort_zawartosci_klient();
};

#endif