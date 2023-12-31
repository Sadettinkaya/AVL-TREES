/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/





#ifndef stackListeNode_hpp
#define stackListeNode_hpp
#include <iostream>
#include "stack.hpp"
#include "avl.hpp"
using namespace std;
class stackListeNode
{

public:
    
    stack* stacklarptr;
    stack* stacklaryedekptr;
    avl* avlAgaci;
    stackListeNode* sonrakiStack;
	int sira;
	int ascii;

    
    stack*getstack();
    stackListeNode( avl*avlAgaci,stack* stacklar ,stack* yedekstack, int sira , int ascii);
    ~stackListeNode();
  // void stackikopyala( stack* stacklarptr);
    friend ostream& operator<<(ostream& os , stackListeNode& stacklarpr)
    {
        os << stacklarpr.stacklarptr;
        return os;
    }


 
};

#endif