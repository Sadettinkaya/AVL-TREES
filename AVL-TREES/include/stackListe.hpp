/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/





#ifndef stackListe_hpp
#define stackListe_hpp
#include "stackListeNode.hpp"
#include "stackListe.hpp"
#include "stack.hpp"

using namespace std;

class stackListe
{ 
public:
   stackListeNode* ilkstackListeNode;

   void print(stackListeNode* aktif);
   void print2(stackListeNode* aktif);
   stackListe();
   ~stackListe();
   void stackListeNodeEkle(avl* avlAgaci ,stack*stacklarptr, stack* yedekstack,int sira , int ascii);
   // void popMinMax();
   // void ListeGez(stackListeNode*bas);

   stackListeNode* minNode();
   stackListeNode* iterateNodes();

   stackListeNode* maxNode(); 
   	
   void kiyaslasil();
   void stackListeNodeYazdir();

   // friend ostream & operator<<(ostream& os, stackListe&liste);
   friend ostream& tumStackNodelariYaz(ostream& os) ;
};
#endif