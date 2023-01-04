//#ifndef klasy_h
//#define klasy_h
//
//#include <iostream>
//
//using namespace std;
//
//struct NodeAuto {
//    
//    Auto zawartosc;
//    NodeAuto* next;
//    NodeAuto* prev;
//};
//
//class Auto {
//protected:
//    int ID_auto;
//    int pojemnosc_auto;
//    bool trasa;
//
//public:
//
//    //Konstruktor
//    Auto(int id = -1, int p = -1, bool t = 0) : ID_auto(id), pojemnosc_auto(p), trasa(t) {};
//
//    //Destruktor
//    ~Auto() {};
//
//
//
//    //Operator pozwalaj¹cy do porównywania obiektów w inny sposób ni¿ adresy w pamiêci
//    friend bool operator==(const Auto& c1, const Auto& c2) {
//        return c1.ID_auto == c2.ID_auto;
//    };
//
//    void print();
//
//};
//
//#endif