#ifndef menu_funkcje_h
#define menu_funkcje_h

#include <iostream>
#include <list>
#include <string>
#include <chrono>

using namespace std;

/** Funkcja sprawdza pobrana liczbe i sprawdza jej poprawnosc w stosunku do przedzialu <min, max>
@param min minimalna wartosc liczby typu int
@param max minimalna wartosc liczby typu int
@return wybrana liczba z zakresu */
int chooseOption(int min, int max);

/** Funkcja bedaca glownyn menu posiadajaca odniesienia do innych funkcjonalnosci
@return informacja do pliku startujacego zakonczeniu wykonywania sie programu*/
int glowna(ListaAut autoList, ListaKli klientList);

/** Funkcja bedaca podMenu posiadajaca opcje dodawania
@return informacja do glownego menu o zakonczeniu wykonywania podMenu*/;
int dodaj();

/** Funkcja bedaca podMenu posiadajaca opcje wyswietlania wykazow
@return informacja do lownego menu o zakonczeniu wykonywania podMenu*/
int wykazy(ListaAut autoList, ListaKli klientList);

/** Funkcja zmieniajaca czytelna date dla uzytkownika na liczbe w formacie daty unix
@param data podana przez uzytkownika
@return liczba w formacie unix podanej daty typu long */
long toUnixTime(string data);

/** Funkcja zmieniajaca liczbe w formacie daty unix na czytelna date dla uzytkownika
@param unix_date liczba w formacie unix typu long  */
void readableTime(long unix_date);
#endif