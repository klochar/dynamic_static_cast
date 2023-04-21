#ifndef CHIEN
#define CHIEN
#include <string>
#include <iostream>
#include "Animal.hpp"
using namespace std;
class Chien : public Animal{
public:
    Chien(int nbPatte, string nom , int nbYeux):Animal(nbPatte,nom,nbYeux){}
    void crier() const override{
        cout<<"woof"<<endl;
    }
    string saluer() const override{
        return "hello";
    }




private:


};

#endif