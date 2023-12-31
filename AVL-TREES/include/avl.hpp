
/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/



#ifndef avl_hpp
#define avl_hpp
#include "dugum.hpp"
#include "stack.hpp"
#include "stacknode.hpp"

#include <iostream>

using namespace std;

class avl
{
public:
   dugum* kok;

    avl();
    ~avl();
    bool avlBosMu();
    dugum* cocuklariSagaDondur(dugum* buyukAna);
    dugum* cocuklariSolaDondur(dugum* buyukAna);
    dugum*ekle(int veri,dugum* aktifDugum);
    int yukseklik(dugum*aktifdugum);
    void ekleGet(int veri);
	void yaprakmi(dugum*kok,stack*ygn);

	int yaprakDisindakileriTopla(dugum*kok);

    void yaprakdisitopla(int veri);
  	//  int stacktaOlmayanlariTopla(dugum*kok,stack*ygn);
	void yaprakGet(stack* ygn);
   	// dugum* yaprakDisindakileriTopla(dugum*kok);
    void yaprakDisindakileriToplaGet(stack*ygn);
   	// bool yaprak(dugum* kok);

friend std::ostream & operator <<(std:: ostream & os,avl& a)
    {
        os<<a.kok->veri;
        return os;
    }
};


#endif