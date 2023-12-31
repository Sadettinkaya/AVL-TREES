/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/




#include "stacknode.hpp"

stacknode::stacknode(int veri)
{
 	this->veri=veri;
	this->sonraki=0;
}
stacknode::~stacknode()
{
  //  cout<<" stacknode"<<"silindi";
}