/** 
* Dosya adı : G221210006ODEV2_VY
* Acıklama: Veri Yapilari 2. Proje
* Dersi aldığınız eğitim türü ve grup : 2.öğretim B grubu
* Ödev No : 2
* Tarih : 24/12/2023
* ödev sahibi adı soyadı: SADETTİN KAYA 
*/





#include"stackListe.hpp"
#include"stackListeNode.hpp"
#include"stack.hpp"
#include"avl.hpp"
#include"dugum.hpp"
#include<iostream>

using namespace std;
#include<iomanip>


void stackListe::print(stackListeNode* aktif)
{	
	while (aktif != 0) {
		//aktif->ascii=aktif->ascii%26+65;
		cout<<"-------------------------"<<endl;
		cout <<" AVL NO : "<< aktif->sira << endl;
		cout <<" SON KARAKTER : "<<(char)aktif->ascii <<endl;
		cout<<"-------------------------";
		aktif = aktif->sonrakiStack;
	}
}


void stackListe::print2(stackListeNode* aktif)
{	
	while (aktif != 0) {
		aktif->ascii=aktif->ascii%26+65;
		//cout << aktif->sira << "\t";
		cout <<(char)aktif->ascii;
		
		aktif = aktif->sonrakiStack;
	}
}


stackListe::stackListe()
{
    ilkstackListeNode=0;
}

stackListe::~stackListe()
{
    stackListeNode* dgmGec=ilkstackListeNode;
    while (dgmGec)
    {
        stackListeNode*dgmSil=dgmGec;
        dgmGec=dgmGec->sonrakiStack;
        delete dgmSil;
        cout<< " siradaki dugumun adresi: "<<dgmGec<<endl;
    }
    
}

// void stackListe::ListeGez(stackListeNode *bas)
// {

//     stackListeNode* onceki = nullptr;
//     stackListeNode* simdiki = bas;
//     stackListeNode* sonraki = nullptr;

//     while (simdiki != nullptr) {
//         sonraki = simdiki->sonrakiStack;

//         // Burada istediğiniz işlemleri yapabilirsiniz.
//         std::cout << "Veri: " << simdiki->stacklarptr << std::endl;

//         onceki = simdiki;
//         simdiki = sonraki;
//         }



// }

void stackListe ::stackListeNodeEkle(avl*avlAgaci, stack*stacklarptr,stack* yedekstack, int sira , int ascii)
{
	stackListeNode* dgmyeni=new stackListeNode(avlAgaci,stacklarptr, yedekstack, sira , ascii);
    if (ilkstackListeNode==0)
    {
        ilkstackListeNode=dgmyeni;
        return;
    }

    stackListeNode*dgmgec=ilkstackListeNode;

    while (dgmgec->sonrakiStack !=0)
    {
        dgmgec=dgmgec->sonrakiStack;
    }
    dgmgec->sonrakiStack =dgmyeni;
}
   
  
   
   
   
   
   
   // tumStackNodelariYaz() fonksiyonunun tanımı
// ostream& tumStackNodelariYaz(ostream& os) 
// {
//     stackListeNode*dgmgec=ilkstackListeNode;
//     // Burada çıktıyı oluşturun, örneğin:
//     while (dgmgec )
//     {
//         os<<setw(16)<<dgmgec<<setw(16);
//         dgmgec->stacklarptr->tumStackNodelariYaz();
//         os<<dgmgec->sonrakiStack<<endl;
//         dgmgec=dgmgec->sonrakiStack;
//     }
//     os<<endl; // Bu kısmı gerçek çıktıya uygun şekilde güncelleyin
//     return os;
// }


void stackListe::stackListeNodeYazdir()
{ 
    cout<<setw(16)<<"adres:"<<setw(16)<<"veri:"<<setw(16)<<"sonraki:"<<endl;
    stackListeNode*dgmgec=ilkstackListeNode;

    while (dgmgec )
    {
        cout<<setw(16)<<dgmgec<<setw(16);
        dgmgec->stacklarptr->tumStackNodelariYaz();
        cout<<endl;
        cout<<dgmgec->sonrakiStack<<endl;
        dgmgec=dgmgec->sonrakiStack;
    }
    cout<<endl;
}

// Iteratör işlevi gören işaretçi
    stackListeNode* stackListe:: iterateNodes()
    {
        return ilkstackListeNode;
    }


stackListeNode* stackListe:: maxNode() {
	stackListeNode* iter = ilkstackListeNode;
	stackListeNode* maxNode = ilkstackListeNode;
	int maxVal = ilkstackListeNode->stacklarptr->tepeGetir();

    while (iter != nullptr) {
        stack* currentStack = iter->stacklarptr;

        if (!currentStack->isEmpty()) {
            int topValue = currentStack->tepeGetir();
             
            if (topValue > maxVal) {
                maxVal = topValue;
                maxNode = iter;
            }
        }

        iter = iter->sonrakiStack;
    }

    return maxNode;
}

 // En küçük veriye sahip düğümü gösteren işaretçi
stackListeNode* stackListe:: minNode() 
{
    stackListeNode* iter = ilkstackListeNode;

	stackListeNode* minNode = ilkstackListeNode;

	int minVal = ilkstackListeNode->stacklarptr->tepeGetir();
  
	while (iter != 0) {
        stack* currentStack = iter->stacklarptr;
        if (!currentStack->isEmpty()) {
            int topValue = currentStack->tepeGetir();
               
            if (topValue < minVal) {
                minVal = topValue;
                minNode = iter;
            }
        }
        iter = iter->sonrakiStack;
    }

    return minNode;
}




void stackListe::kiyaslasil()
{ 

	bool x=true;
	int  sayac=1;
 
    while (x)
    {  
       	if (sayac%2==1)
		{  
			stackListeNode* minNodePtr = minNode(); //minnodeptr tutuyor en küçük düğümün adresini
      
            stack* minstack   =	minNodePtr->stacklarptr; //minstack da en küçük stackın adresini tutuyor
			stack* yedekstack = minNodePtr->stacklaryedekptr; //yedek stackta aynı şekilde
            
			if (!minstack->isEmpty())
            {
				yedekstack->stackaEkle( minstack->tepeGetir()); //çıkarılacak olanı yedeğe ekliyoruz

				minstack->stacktanCikar(); //çıkarıyoruz
              
				if (minstack->isEmpty())
				{
					stackListeNode* itrtemp = 0;
					stackListeNode* itr = ilkstackListeNode;
					
					while (itr->sira != minNodePtr->sira)
					{
						itrtemp = itr;
						itr = itr->sonrakiStack;
					}
					
					if (minNodePtr == ilkstackListeNode)
					{
						ilkstackListeNode = minNodePtr->sonrakiStack;
						delete minNodePtr;
					}
					else {
						itrtemp->sonrakiStack = minNodePtr->sonrakiStack;
						delete minNodePtr;
					}

					x=false;    
				}  
            }                   
        }

         else
         {      
			stackListeNode* maxNodePtr = maxNode();
			
			stack* maxstack=maxNodePtr->stacklarptr;

			stack* yedekstack = maxNodePtr->stacklaryedekptr;

			if (!maxstack->isEmpty())
			{
				yedekstack->stackaEkle(maxstack->tepeGetir());

				maxstack->stacktanCikar();

				if (maxstack->isEmpty())
				{
					stackListeNode* itr = ilkstackListeNode;
					stackListeNode* itrtemp = 0;

					while (itr->sira != maxNodePtr->sira)
					{
						itrtemp = itr;
						itr = itr->sonrakiStack;
					}

					if (maxNodePtr == ilkstackListeNode)
					{
						ilkstackListeNode = maxNodePtr->sonrakiStack;
						delete maxNodePtr;
					}
					
					else {
						itrtemp->sonrakiStack = maxNodePtr->sonrakiStack;
						delete maxNodePtr;
					}

					x=false;                 
				}
			}
        }
		 
        sayac++ ;
    }  
    
	//cout << "---------------------" << endl;
	
	stackListeNode* itr = ilkstackListeNode;
	while (itr != 0)
	{
		while (!itr->stacklaryedekptr->isEmpty())
		{
			itr->stacklarptr->stackaEkle(itr->stacklaryedekptr->tepeGetir());
			itr->stacklaryedekptr->stacktanCikar();
			
		}
		
		itr = itr->sonrakiStack;
	
	}
	//cout << "---------------------" << endl;


	
	
}




















// void stackListe::kiyaslasil()
// {  bool x=true;
  
//     while (x)
//     {
//        stackListeNode*aktif=ilkstackListeNode;

//        if (sayac%2==1)
//        { stackListeNode * kucuk=ilkstackListeNode;
          
//             while (aktif!=0)
//             {
                 
//                  if (kucuk->gecicistack->tepeGetir()> aktif->gecicistack->tepeGetir() )
//                 {
//                      kucuk=aktif;
//                 }
//                 aktif=aktif->sonrakiStack;
//             }
//                 kucuk->gecicistack->stacktanCikar();
//                 if (kucuk->gecicistack->isEmpty())
//                 {  
//                     if (gec)
//                     {
//                         kucuk->gec->sonrakiStack=kucuk->sonrakiStack;
//                     }

//                     else
//                     {
//                         ilkstackListeNode=kucuk->sonrakiStack;
//                     }

//                     if (kucuk->sonrakiStack)
//                     {
//                        kucuk->sonrakiStack->oncekiStack=kucuk->oncekiStack;
//                     }

//                     delete kucuk;
//                     x=false;
                    
                    
//                 }
                
           
            
//        }
       
//     }
    
    
    
    
    
    
    
    
    
    
    
//     sayac++;

// }
















// void stackListe::kiyaslasil()
// {   if (ilkstackListeNode == nullptr)
//     {
//         cout << "stackListe bos. Isleme devam edilemiyor." << endl;
//         return;
//     }

//     stackListeNode* minNodePtr = minNode();
//     stackListeNode* maxNodePtr = maxNode();

//     if (sayac % 2 == 1)
//     {
//         while (minNodePtr != nullptr)
//         {
//             stack* minStack = minNodePtr->stacklarptr;

//             if (!minStack->isEmpty())
//             {
//                 minStack->stacktanCikar();
//             }

//             minNodePtr = minNode();
//         }
//     }
//     else
//     {
//         while (maxNodePtr != nullptr)
//         {
//             stack* maxStack = maxNodePtr->stacklarptr;

//             if (!maxStack->isEmpty())
//             {
//                 maxStack->stacktanCikar();
//             }

//             maxNodePtr = maxNode();
//         }
//     }

//     sayac++;

// }
    



// void stackListe::popMinMax() {
//      if (ilkstackListeNode == nullptr) {
//             cout << "stackListe bos. Isleme devam edilemiyor." << endl;
//             return;
//         }

//         stackListeNode* minNodePtr = minNode();
//         stackListeNode* maxNodePtr = maxNode();

//     if (sayac%2==1)
//     {
//          // En küçük değeri içeren düğümün verisini silme işlemi
//         if (minNodePtr != nullptr)
//          {
//             stack* minStack = minNodePtr->stacklarptr;

//             if (!minStack->isEmpty()) {
//                 minStack->stacktanCikar();
//             }
//         }
//     }

//     else
//     {
//         if (maxNodePtr != nullptr)
//          {
//             stack* maxStack = maxNodePtr->stacklarptr;

//             if (!maxStack->isEmpty())
//             {
//                 maxStack->stacktanCikar();
//             }

//          }
    
//     }

// }


