
/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/


#include "stack.hpp"
#include "stacknode.hpp"
#include "iostream"
using namespace std;


stack::stack()
{
    tepe=nullptr;
}


bool stack:: isEmpty()
{
    return tepe == nullptr;
}

stack::~stack()
{
   while (!isEmpty())
   {	
   		stacktanCikar();
   }   
}

void stack :: tumStackNodelariYaz()
{
    stacknode*tmp=tepe;
    while (tmp!=nullptr)
    {
        cout<<tmp->veri<<endl;
        tmp=tmp->sonraki;
    }    
}

void stack::stackaEkle(int veri) //onden ekliyoruz
{
   stacknode* yeni=new stacknode(veri);
    
   if (tepe==nullptr)
   {
        tepe=yeni;   
    //cout<<yeni->veri<<" , "<<yeni<<"  "<<tepe<< " tepesonraki : "<<tepe->sonraki<<" yigita ilk veri eklendi"<<endl;
   }
   else
   {
        yeni->sonraki=tepe;
        tepe=yeni;
      // cout<<yeni->veri<<" , "<<yeni<<"  "<<tepe<< " tepesonraki : "<<tepe->sonraki<<" yigita yeni veri eklendi"<<endl;
   }  
}

void stack::stacktanCikar()
{  
    if (tepe!=0)
    {
      	stacknode*silinecek=tepe;
        //cout<<"stacktan "<< tepe->veri<< "  cikti  " <<endl;
       	tepe=tepe->sonraki;     
      	delete silinecek;      
    }
}

int stack::tepeGetir()
{
    if (tepe!=0)
    { 
        return tepe->veri;     
    }
    
    //throw  out_of_range("stacknode::tepeGetir(): yıgın bos");
}