
/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/



#ifndef dugum_hpp
#define dugum_hpp
#include <iostream>

using namespace std;

class dugum
{
public:
    int veri;
	dugum* sol;
    dugum* sag;
	int yukseklik;

	dugum(int veri);
    ~dugum();
    
    friend std::ostream & operator <<(std:: ostream & os,dugum& a)
    {
        os<<a.veri;
        return os;
    }
};


#endif
