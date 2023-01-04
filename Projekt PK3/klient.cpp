#include <iostream>
#include "klient_funkcje.h"
#include <fstream>
#include <list>
#include <string>

using namespace std;


void Klient::print_klient() {

    cout << "\nNumer klienta:\t\t" << this->ID_klient;
    cout << "\nNazwa klietna:\t\t" << this->nazwa;
    cout << "\nNumer NIP klienta:\t"<<this->NIP;
};

void ListaKli::save_klient(const string& file_name) {

    Klient customer = *this->head;

    ofstream file(file_name, ios::binary);

    while (1) {

        Klient dane;
        dane.ID_klient = customer.ID_klient;
        dane.nazwa = customer.nazwa;
        dane.NIP = customer.NIP;
        file.write(reinterpret_cast<const char*>(&dane), sizeof(dane));
        if (customer.next == nullptr) {
            break;
        }
        else {
            customer = *customer.next;
        }
    }

    file.close();
};

//problem przy return
void ListaKli::load_klient(const string& file_name) {

    Klient customer;

    Klient poprz_customer;

    ifstream file(file_name, ios::binary);


    while (1) {
        file.read(reinterpret_cast<char*>(&customer), sizeof(customer));

        if (poprz_customer == customer) { break; }

        this->dod_do_listy_klient(customer);
        poprz_customer = customer;
    }

    file.close();

    //this->sort_zawartosci_klient();

    //this->print_list_klient();
    
}

void ListaKli::sort_zawartosci_klient() {

    Klient* klient1 = this->head, * klient2 = this->tail;
    int a = -1;
    bool flaga = 1;
    while (1) {

        if (klient1->next == nullptr) {
            klient1 = this->head;
        }

        klient2 = klient1;
        klient1 = klient1->next;


        if (klient1->ID_klient < klient2->ID_klient) {
            auto klient2prev = klient2->prev;
            auto klient1next = klient1->next;

            //warunek dla pierwszego elementu listy
            if (klient2prev == nullptr) {
                this->head = klient1;
                klient1next->prev = klient2;
                klient2->next = klient1next;
                klient2->prev = klient1;
                klient1->next = klient2;
                klient1->prev = nullptr;
            }

            //warunek dla ostatniego elementu listy
            else if (klient1next == nullptr) {
                klient2prev->next = klient1;
                klient2->next = nullptr;
                klient2->prev = klient1;
                klient1->next = klient2;
                klient1->prev = klient2prev;
            }

            //warunek dla dowolnego elementu listy
            else {
                klient2prev->next = klient1;
                klient1next->prev = klient2;
                klient2->next = klient1next;
                klient2->prev = klient1;
                klient1->next = klient2;
                klient1->prev = klient2prev;
            }

            flaga = 1;
        }


        if (klient1->next == nullptr) {
            if (flaga) {
                a++;
                klient1 = this->head;
                flaga = 0;
            }
            else { break; }
        }

    }

    cout << "Klienci:\t";
    if (a == 0) {
        cout << "Tablica byla posortowana\n";
    }
    else {
        cout << "Liczba przemieszczonych elementow: " << a + 1 << endl;
    }

    //Tworzenie listy z zawartoscia
    Klient* customer = this->head;

    zawartosc_klient.clear();
    while (1) {
        zawartosc_klient.push_back(*customer);
        if (customer->next == nullptr) {
            break;
        }
        else {
            customer = customer->next;
        }
    }
}

void ListaKli::dod_do_listy_klient(Klient pojazd) {

    Klient* newKlient= new Klient(pojazd);

    if (this->head == nullptr) {
        this->head = newKlient;
        this->tail = newKlient;
        return;
    }
    this->tail->next = newKlient;
    newKlient->prev = this->tail;
    this->tail = newKlient;

}

void ListaKli::print_list_klient() {

    Klient* customer = this->head;

    while (1) {

        cout << "\nNumer klienta:\t\t" << customer->ID_klient;
        cout << "\nNazwa klietna:\t\t" << customer->nazwa;
        cout << "\nNumer NIP klienta:\t" << customer->NIP << endl;

        //Jak bedzie to w warunku while, to nie wyœwietli ostatniego rekordu
        if (customer->next == nullptr) {
            break;
        }
        else {
            customer = customer->next;
        }

    }
};