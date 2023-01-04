// miejsce zapisu: F:\proj PK3\Projekt PK3
// wielkie funkcje --> camelFont        mniejsze funkcje --> nazwa_funkcji

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "auto.cpp"
#include "auta_funkcje.h"
#include "zamowienie.cpp"
#include "zamowienie_funkcje.h"
#include "towar.cpp"
#include "towar_funkcje.h"
#include "klient.cpp"
#include "klient_funkcje.h"
#include "menu.cpp"
#include "menu_funkcje.h"
#include <fstream>
#include <list>
#include <string>
#include <chrono>

using namespace std;

int main()
{

  /*  string file_start = "start.txt";
    string client_txt, pojazd_txt, towary_txt, zamowienia_txt;
    int last_number_txt;
    bool dane = false;
    string kontrola = file_start;

    do {
        if (dane) {
            break;
        }

        dane = memoryState(&file_start, &client_txt, &last_number_txt, &pojazd_txt, &towary_txt, &zamowienia_txt);

    } while (1);*/
    string klient_start = "klient.bin";

    Klient k1(3, "Bramex", "789951235"), k2(2, "Maxim", "645148123"), k3(1, "Protiks", "325657145");

    Auto a1(9, 9, 1), a2(8, 18, 0), a3(7, 2, 1);

    string auta_start = "auta.bin";
    ListaAut autoList;

    autoList.load_auto(auta_start);
    //autoList.print_list_aut();

    ListaKli klientList;
    
    klientList.load_klient(klient_start);
    
    /*klientList.dod_do_listy_klient(k1);
    klientList.dod_do_listy_klient(k2);
    klientList.dod_do_listy_klient(k3);*/

    //klientList.sort_zawartosci_klient();
    //klientList.print_list_klient();
    //klientList.save_klient(klient_start);
    
    //glowna(autoList, klientList);

    return 0;
}
