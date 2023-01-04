#ifndef auta_funkcje_h
#define auta_funkcje_h

#include <iostream>
#include <list>
#include <string>

using namespace std;

class Auto {
protected:
    int ID_auto;
    int pojemnosc_auto;
    bool trasa;
    Auto* next;
    Auto* prev;

public:

    //Konstruktor
    Auto(int id = -1, int poj = -1, bool trasa = 0) {
        this->ID_auto = id;
        this->pojemnosc_auto = poj;
        this->trasa = trasa;
        this->next = nullptr;
        this->prev = nullptr;
    }

    //Destruktor
    ~Auto() {};

    //Operator pozwalaj¹cy do porównywania obiektów w inny sposób ni¿ adresy w pamiêci
    friend bool operator==(const Auto& c1, const Auto& c2) {
        return c1.ID_auto == c2.ID_auto;
    };

    //wypisanie danych jednego pojazdu
    void print_auto();

    friend class ListaAut;

};

class ListaAut {
private:
    Auto* head;
    Auto* tail;
    
    list<Auto> zawartosc_auto;

public:
    ListaAut() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    //Zapis listy aut do pliku .bin
    void save_auto(const string& filename);

    //Odczyt listy aut z pliku .bin
    void load_auto(const string& file_name);

    //Dodaje na koniec listy element
    void dod_do_listy_aut(Auto pojazd);

    //Wyswietlanie listy aut
    void print_list_aut();

    //Wypisanie pojazdow w trasie
    void print_trasa();

    //Wypisanie wolnych pojazdow
    void print_wolne();

    //sortuje liste na podstawie id + utworzenie listy 'zawartosc'
    void sort_zawartosci_auto();

    //Wyswietlanie pojazdow o podanej pojemnosci 
    void print_poj_trasa();

};

#endif