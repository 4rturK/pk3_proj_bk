#include <iostream>
#include "menu_funkcje.h"
#include <list>
#include <string>
#include <chrono>

using namespace std;

int chooseOption(int min, int max) {
    int liczba;
    cin >> liczba;

    while (cin.fail() || liczba<min || liczba>max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "podaj poprawna liczbe: ";
        cin >> liczba;
    }
    return liczba;
}

int glowna(ListaAut autoList, ListaKli klientList) {
    while (1) {
        cout << "\n1.  rezerwacja kursu\n2.  anulowanie kursu\n3.  wprowadzenie do bazy\n4.  wyswietlenie wykazow\n5.  zamkniecie programu" << endl << endl;
        int opcja = chooseOption(1, 5);
        switch (opcja) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            dodaj();
            break;
        case 4:
            wykazy(autoList, klientList);
            break;
        case 5:
            return 0;
        }
    }

}

int dodaj() {
    while (1) {
        cout << "\n1.  wprowadz klienta\n2.  wprowadz pojazd\n3.  powrot" << endl << endl;
        int opcja = chooseOption(1, 3);
        switch (opcja) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            return 0;
        }
    }

}

int wykazy(ListaAut autoList, ListaKli klientList) {
    while (1) {
        ListaAut prk;
        cout << "\n1.  lista wszystkich zamowien\n2.  lista klientow \n3.  lista wszystkich pojazdow\n4.  lista zamowien w toku\n5.  lista zakonczonych zamowien\n6.  lista anulowanych zamowien\n7.  lista dostepncyh pojazdow\n8.  lista pojazdow w trasie\n9.  powrot" << endl << endl;
        int whatToDo = chooseOption(1, 9);
        switch (whatToDo) {
        case 1:
            break;
        case 2:
            cout << "\n---------- Lista klientow ----------\n";
            klientList.print_list_klient();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            cout << "\n---------- Lista dostpnych pojazdow ----------\n";
            autoList.print_wolne();
            break;
        case 8:
            cout << "\n---------- Lista pojazdow w trasie ----------\n";
            autoList.print_trasa();
            break;
        case 9:
            return 0;
        }
    }

}

long toUnixTime(string data) {
    int i = 1;
    string word = "", year, month, day;
    for (auto x : data)
    {
        if (x == '/' || x == '-' || x == '.' || x == ',')
        {

            switch (i % 2) {
            case 1:
                day = word;
                i++;
                word = "";
                break;

            case 0:
                month = word;
                i++;
                word = "";
                break;
            }

        }
        else {
            word = word + x;
        }
    }
    year = word;

    struct tm t;
    time_t t_of_day;

    t.tm_year = stoi(year) - 1900;  // Year - 1900
    t.tm_mon = stoi(month) - 1;     // Month, where 0 = jan
    t.tm_mday = stoi(day);          // Day of the month
    t.tm_hour = 00;
    t.tm_min = 00;
    t.tm_sec = 00;
    t_of_day = mktime(&t);

    uint64_t t_day = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();

    if ((long)t_of_day < t_day) {
        return 0;
    }

    return (long)t_of_day;


}

void readableTime(long unix_date) {

    time_t rawtime = unix_date;
    struct tm  ts;
    char       buf[80];

    ts = *localtime(&rawtime);
    strftime(buf, sizeof(buf), "%d.%m.%Y", &ts);
    printf(buf);
}