#include <iostream>
#include <memory>
#include "Animal.hpp"
#include "Chat.hpp"
#include "Chien.hpp"
#include <concepts>
#include <vector>

using namespace std;

template <derived_from<Animal> T>//beosin de include concepts
ostream& operator<<(ostream& os,const T& a){
    return os<<a.saluer();
}


//polymorph heritage
int main () {
    Chat c1 = Chat(4,"minou",2,"gentil");
    //cout<<c1<<endl;
    //c1.crier();
    Chien c2 = Chien(4,"faith",2);
    //cout<<c2<<endl;
    //c2.crier();

    //on veut faire un vector de type ptr vers animal Animal, 
    //selon le comportement de chaque type, ceci est base sur le type statique
    // vector <Animal*> v = {&c1,&c2};
    // for(auto i:v){
    //     cout<<i->saluer()<<endl;
    // }


    vector<Animal*> v = {&c1,&c2};
    //Chat* ptrChat = v[1]//jpeux pas faire ca marlgre que c un Chat, on doit faire conversion explicite




    //exemple de casting 
    /*
    Chat lettre = (int)... --> le plus dangereux 
        //    //  static_cast<int>//mieux que le premier, empeche la conversion de pointeur en int
        //    //  int{...}; --> verifie qu il n y a pas de perte de donne 
        //    //    dynamic_cast<Type>
    */

    //Chat* chatPtr1 = dynamic_cast<Chat*>(v[0]);//si ca echoue le ptr sera nullptr, et si on a fait une reference et que ca echoue donc ca throw une exception bad_cast
    for(auto&& i:v){
        if(auto chat = dynamic_cast<Chat*>(i)){
            cout<<"un chat"<<endl;
            chat->crier();
        } else if(auto chien = dynamic_cast<Chien*>(i)){    
            cout<<"un chien"<<endl;
            chien->crier();
        }
    }









    





    return 0;
}