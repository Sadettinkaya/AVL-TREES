
/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/





#ifndef stacknode_hpp
#define stacknode_hpp
#include <iostream>
	
using namespace std;

class stacknode
{
public:
    int veri;
    stacknode*sonraki;
    
	stacknode(int veri);
    ~stacknode();

    friend std::ostream & operator <<(std:: ostream & os,stacknode& a)
    {
        os<<a.veri;
        return os;
    }
};
#endif