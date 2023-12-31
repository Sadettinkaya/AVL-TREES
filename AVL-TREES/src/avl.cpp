
/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/




#include "avl.hpp"
#include "dugum.hpp"
#include "stack.hpp"
#include "stacknode.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

avl::avl()
{
    kok=nullptr;
}

int toplam;

bool avl:: avlBosMu()
{
    return kok ==nullptr;
}

int avl::yukseklik(dugum* aktifdugum)
{
    if(aktifdugum)
    {
        return 1+max(yukseklik(aktifdugum->sol),yukseklik(aktifdugum->sag));
    }
    return -1;
}
dugum*avl::cocuklariSagaDondur(dugum*buyukAna)
{
    dugum*solcocuk=buyukAna->sol;
    buyukAna->sol=solcocuk->sag;
    solcocuk->sag=buyukAna;
    return solcocuk;
}
dugum*avl::cocuklariSolaDondur(dugum*buyukAna)
{
    dugum*sagcocuk=buyukAna->sag;
    buyukAna->sag=sagcocuk->sol;
    sagcocuk->sol=buyukAna;
    return sagcocuk;
}

void avl::yaprakdisitopla(int veri)
{
   //  cout<<"kalanlarin toplami: "<<toplam<<endl;
    toplam=toplam+veri;
   

}
void avl::yaprakmi(dugum*kok,stack* ygn)
{
    if(kok)
    { 
     	if (kok->sag==0 && kok->sol==0)
        {  
            ygn->stackaEkle(kok->veri);
        }  
		yaprakmi(kok->sol, ygn);
		yaprakmi(kok->sag, ygn);
    }  
}

//  bool avl:: yaprak(dugum* kok)
//  {
//      if(kok)
//      { 
//          yaprak(kok->sol);
//          yaprak(kok->sag);
//          if (kok->sag==0 && kok->sol==0)
//          {   
//              return true;

//          }
        
//      }
//  }
   

int avl::yaprakDisindakileriTopla(dugum*kok)
{
	if (kok) {
		if (kok->sag == 0 && kok->sol == 0) {
			return 0;
		}
		return kok->veri + yaprakDisindakileriTopla(kok->sag) + yaprakDisindakileriTopla(kok->sol);
	}
	else return 0;
}


// 	void avl::yaprakGet(stack* ygn)
// 	{
// 	toplam=0;
// //	kok = yaprakmi(kok,ygn);
// 	cout<<"toplam:"<<toplam<<endl; 
// 	int ascii = toplam%(90-65 + 1) + 65;
// 	cout<<"asci: "<<(char)ascii<<endl;
// 	}


// void avl::yaprakDisindakileriToplaGet(stack * ygn)
// {
//     toplam=0;
//     kok = yaprakmi(kok,ygn);
//     cout<<"toplam:::::"<<toplam<<endl; //??
// }

void avl::ekleGet(int veri)
{
    kok=ekle(veri,kok);
 	// cout<<veri<<" dugumun verisi avlye eklendi"<<endl;
    
}


dugum* avl::ekle(int veri,dugum*aktifDugum)
{  
   
    
    if(aktifDugum==0)
    {
        return new dugum(veri);
    
    }

    if(aktifDugum->veri>veri)
    {
        aktifDugum->sol=ekle(veri,aktifDugum->sol);
      	//cout<<"veri "<<veri<<" icin "<<"aktifdugum->sol cagrildi"<<endl;

        if (yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {
            if (veri<aktifDugum->sol->veri)
            {
               aktifDugum=cocuklariSagaDondur(aktifDugum);
               //cout<<" saga dondu"<<endl;
            }
            else
            {
                aktifDugum->sol=cocuklariSolaDondur(aktifDugum->sol);
                aktifDugum=cocuklariSagaDondur(aktifDugum);
                //cout<<" sola ve saga dondu"<<endl;
            }
        }
        
    }

    else if(aktifDugum->veri<veri)
    {
        aktifDugum->sag=ekle(veri,aktifDugum->sag);
        //cout<<"veri "<<veri<<" icin "<<"aktifdugum->sag cagrildi"<<endl;
        if (yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {
            if(veri>aktifDugum->sag->veri)
             { aktifDugum=cocuklariSolaDondur(aktifDugum);
                  //cout<<" saga dondu"<<endl;
             }
            else
            {
                aktifDugum->sag=cocuklariSagaDondur(aktifDugum->sag);
                aktifDugum=cocuklariSolaDondur(aktifDugum);
                 //cout<<" saga ve sola dondu"<<endl;
            }
            
        }
        
    }
    return aktifDugum;
}