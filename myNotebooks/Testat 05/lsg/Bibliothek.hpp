#include <string>
#include <list>
#include <iostream>
#include "Item.hpp"
using namespace std;

class Bibliothek{
    
    int idCounter = 1;
    list<Item*> inventar;
    
    public:
    
    void addBuch(string titel, string autor, int eJahr){
        inventar.push_back(new Item(idCounter, titel, autor, eJahr));
        idCounter++;
    }
    
    void addSpiel(string titel, int szahl, int alter){
        inventar.push_back(new Item(idCounter, titel, szahl, alter));
        idCounter++;
    }
                           
    bool entferneItem(int id){
        for(Item *tmp : inventar){
            if(tmp->getId() == id){
                inventar.remove(tmp);
                return true;
            }
        }
        return false;
    }
                           
    bool verleiheItem(int id){
        for(Item *tmp : inventar){
            if(tmp->getId() == id){
                tmp->setAusleihstatus(true);
                return true;
            }
        }
        return false;
    }
        
    bool gebeItemZurueck(int id){
        for(Item *tmp : inventar){
            if(tmp->getId() == id){
                tmp->setAusleihstatus(false);
                return true;
            }
        }
        return false;
    }
                           
    bool pruefeVerleihstatus(int id){
        for(Item *tmp : inventar){
            if(tmp->getId() == id){
                return tmp->getAusleihstatus();
            }
        }
        return false;
    }
            
    void druckeInventar(){
        cout << "\n";
        for(Item *tmp : inventar){
            cout << tmp->toString() << "\n";
        }
    }
    
    void sucheTitel(string titel){
        cout << "\n Items mit folgenden Titel: " + titel << "\n";
        for(Item *tmp : inventar){
            if(tmp->getTitel() == titel){
                cout << "\n" << tmp->toString() << "\n";
            }
        }
    }
    
    void sucheAutor(string autor){
        cout << "\n Buecher mit folgenden Autor: " + autor << "\n";
        for(Item *tmp : inventar){
            if(tmp->getAutor() == autor){
                cout << "\n" << tmp->toString() << "\n";
            }
        }
    }
    
    void sucheSpielerzahl(int sZahl){
        cout << "\n Spiele mit der Spieleranzahl: " + to_string(sZahl) << "\n";
        for(Item *tmp : inventar){
            if(tmp->getSpieleranzahl() == sZahl){
                cout << "\n" << tmp->toString() << "\n";
            }
        }
    }
    
    void sucheID(int id){
        cout << "Item mit der ID: " << to_string(id) << "\n";
        for(Item *tmp : inventar){
            if(tmp->getId() == id){
                cout << "\n" << tmp->toString() << "\n";
            }
        }
    }
};