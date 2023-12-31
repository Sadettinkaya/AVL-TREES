/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/





#include<iostream>
#include"stackListeNode.hpp"
#include"stackNode.hpp"
using namespace std;


stackListeNode ::stackListeNode( avl*avl,  stack*ptr, stack* yedekstack,int sira,int ascii)
{
    this->stacklarptr=ptr;
    this->avlAgaci=avl;
	this->sira = sira;
	this->ascii = ascii;
    this->sonrakiStack=0;
	this->stacklaryedekptr=yedekstack;

  
}

stackListeNode::~stackListeNode()
{

}

// stack* stackListeNode::getstack()
// {
//     return this->stacklarptr;
// }
// void stackListeNode::stackikopyala(stack* hedef) {
//     stack* geciciStack = new stack();  // Geçici stack oluştur

//     // Orijinal stack'ten elemanları geçici stack'e kopyala
//     while (!stacklarptr->isEmpty()) {
//         int eleman = stacklarptr->stacktanCikar();
//         geciciStack->stackaEkle(eleman);
//     }

//     // Geçici stack'ten elemanları hedef stack'e kopyala
//     while (!geciciStack->isEmpty()) {
//         int eleman = geciciStack->stacktanCikar();
//         hedef->stackaEkle(eleman);
//     }

//     // Geçici stack'i sil
//     delete geciciStack;
// }




