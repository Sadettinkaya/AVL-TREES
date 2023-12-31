/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/





#ifndef stack_hpp
#define stack_hpp
#include <iostream>
#include "stacknode.hpp"
#include "stack.hpp"

using namespace std;

class stack
{
public:
    stacknode* tepe;

    stack();
    ~stack();
    bool isEmpty();
    void stackaEkle(int veri);
    void stacktanCikar();
    int tepeGetir();
    void tumStackNodelariYaz();
    
    friend std::ostream & operator <<(std:: ostream & os,stack& a)
    {
        os<<a.tepe;
        return os;
    }
};

#endif