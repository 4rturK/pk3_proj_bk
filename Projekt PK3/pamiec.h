#ifndef pamiec_h
#define pamiec_h

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <crtdbg.h>
#include <chrono>
#include <fstream>

using namespace std;

bool memoryState(string* file, string* cli, int* nr_zam, string* poj, string* towar, string* zam) {

    string line, plik;
    int i = 1;
    ifstream basic_Memory(*file);

    if (basic_Memory.is_open()) {
        while (getline(basic_Memory, line)) {

            switch (i % 5) {
            case 1:
                *cli = line;
                i++;
                break;

            case 2:
                *poj = line;
                i++;
                break;

            case 3:
                *towar = line;
                i++;
                break;

            case 4:
                *zam = line;
                i++;
                break;

            case 0:
                *nr_zam = stoi(line);
                i++;
                break;
            }


        }

        string co_to = "klientow";
        file_state(&*cli, co_to);
        co_to = "pojazdow";
        file_state(&*poj, co_to);
        co_to = "towarow";
        file_state(&*towar, co_to);
        co_to = "zamowien";
        file_state(&*zam, co_to);

        plik += *cli;
        plik += "\n";
        plik += *poj;
        plik += "\n";
        plik += *towar;
        plik += "\n";
        plik += *zam;
        plik += "\n";
        string powrot = to_string(*nr_zam);
        plik += powrot;

        ofstream popr(*file);
        popr << plik;
        popr.close();

        return true;
    }

    else {
        cout << "Nie znaleziono pliku inicjujacego!" << endl << endl << "Podaj nazwe pliku z rozszerzeniem (napisanie 'stop' zakonczy prace programu):" << endl << endl;
        cin >> *file;
        cout << endl;
        if (*file == "stop" || *file == "STOP") {
            exit(1);
        }

        return false;
    }

}

void file_state(string* nazwa_txt, string co_to) {

    do {
        ifstream check(*nazwa_txt);
        if (!check.is_open()) {
            cout << endl << endl << "Nie znaleziono pliku (" << co_to << ") " << *nazwa_txt << endl << endl;
            cout << "Podaj nazwe pliku z rozszerzeniem (napisanie 'stop' zakonczy prace programu):" << endl << endl;
            cin >> *nazwa_txt;
            if (*nazwa_txt == "stop" || *nazwa_txt == "STOP") {
                exit(1);
            }
        }
        else {
            break;
        }

    } while (1);

}


#endif
