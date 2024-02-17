#include <string>
using namespace std;
class Item{
    
    string type = "";
    int id = 0;
    string titel = "";
    string autor = "";
    int erscheinungsjahr = 0;
    int spieleranzahl = 0;
    int empfohlenesAlter = 0;
    bool ausleihstatus = false;
    
    public:
    
    //Buch
    Item(int id, string titel, string autor, int erscheinungsjahr){
        this->type = "Buch";
        this->id = id;
        this->titel = titel;
        this->autor = autor;
        this->erscheinungsjahr = erscheinungsjahr;
    }
    
    //Spiel
    Item(int id, string titel, int spieleranzahl, int empfohlenesAlter){
        this->type = "Spiel";
        this->id = id;
        this->titel = titel;
        this->spieleranzahl = spieleranzahl;
        this->empfohlenesAlter = empfohlenesAlter;
    }
    
    bool getAusleihstatus(){
        return this->ausleihstatus;
    }
    
    void setAusleihstatus(bool status){
        this->ausleihstatus = status;
    }
    
    int getId(){
        return this->id;
    }
    
    int getSpieleranzahl(){
        return this->spieleranzahl;
    }
    
    string getAutor(){
        return this->autor;
    }
    
    string getTitel(){
        return this->titel;
    }
    
    string toString(){
        string ausgabe = "";
        string status = "";
        
        if(ausleihstatus){
            status = "Ausgeliehen";
        }else{
            status = "Verfuegbar";
        }
        
        if(type == "Buch"){
            ausgabe = ausgabe + "Type: " + type + "- ID: " + to_string(this->id) + " - Titel: " + titel;
            ausgabe += " - Autor: " + this->autor + " - Erscheinungsjahr: " + to_string(this->erscheinungsjahr);
            ausgabe += " - Ausleihstatus: " + status;
            return ausgabe;
        }
        if(type == "Spiel"){
            ausgabe = ausgabe + "Type: " + type + " - ID: " + to_string(this->id) + " - Titel: " + titel + " - Spieleranzahl: " + to_string(spieleranzahl);
            ausgabe += " - Empfohlenes Alter: " + to_string(this->empfohlenesAlter) + " - Ausleihstatus: " + status;
            return ausgabe;
        }
        return "fehler";
        
    }
};