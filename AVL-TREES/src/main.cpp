/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/




#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include "avl.hpp"
#include "stack.hpp"
#include "stacknode.hpp"
#include "dugum.hpp"
#include "stackListe.hpp"
#include "stackListeNode.hpp"
#include"Windows.h"

using namespace std;

int main()
{  
	int toplam =0;
	int sira = 0;
	int ascii = 0;
    ifstream dosya("veri.txt");
    
	stackListe* ekleDugum=new stackListe(); //listeyi gösteren ptr tanımladim
  
	if(dosya.is_open())
    {
        string satir;
       
		while(getline(dosya,satir))
        {
			sira++;
			int siradakisayi;

			stringstream satiroku(satir);

			avl* avlAgaci=new avl();
			stack* yaprakstack =new stack();  //orijinal stack
			stack* yedekstack = new stack(); //yedekstack oluşturdum

			while( satiroku>>siradakisayi)
			{
				avlAgaci->ekleGet(siradakisayi);
			} 

			avlAgaci->yaprakmi(avlAgaci->kok,yaprakstack);
			ascii = avlAgaci->yaprakDisindakileriTopla(avlAgaci->kok);
			
			// yaprakstack->tumStackNodelariYaz();
			// cout<<endl;
		   //cout<<"tepe: "<<yaprakstack->tepeGetir()<<endl;

		//	avlAgaci->yaprakGet(yaprakstack);
			ekleDugum->stackListeNodeEkle(avlAgaci,yaprakstack,yedekstack, sira , ascii);

        }       
    }
	

	while (ekleDugum->ilkstackListeNode->sonrakiStack != 0)
	{
		//ekleDugum->print(ekleDugum->ilkstackListeNode);

		//cout << ekleDugum->minNode()->stacklarptr->tepeGetir();
		//cout << ekleDugum->maxNode()->stacklarptr->tepeGetir();
		ekleDugum->print2(ekleDugum->ilkstackListeNode);
		// ekleDugum->ilkstackListeNode->ascii=ekleDugum->ilkstackListeNode->ascii%26+65;
		// cout<<(char)ekleDugum->ilkstackListeNode->ascii;
	
		
		ekleDugum->kiyaslasil();
		Sleep(5);
		system("cls");
	}
	ekleDugum->print(ekleDugum->ilkstackListeNode);

	return 0;
	
	
}