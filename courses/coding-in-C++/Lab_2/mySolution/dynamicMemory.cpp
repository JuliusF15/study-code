#include <iostream>
#include <string>

using namespace std;

class Note{
    private:
        string* text;
    public:
        Note(string text_inp){//Konstruktor
            text = new string; //an der Stelle ist new eigentlich unnötig, wenn man es aber benutzt, ist das der richtige Weg
            *text = text_inp; //ohne Copy Konstructor wird ein standart Copy Konstuctor gebaut, wenn man eine Node mit einer Node erzeugt. Dort zeigen dann beide Pointer von "new" auf die selbe Adresse. Beim Löschen wird trotzdem zweimal aufgerufen, was zu undefined behavior führt

        };
        Note(Note& t){ //Copy-Konstructor
            text = new string;
            *text = *(t.text);
        }
        ~Note(){  //Dekonstructor wird immer am Ende des Programms aufgerufen
            delete text;
        };
        void display(){
            cout << *text << endl;
        };
};

int main(){
    Note Text("Hlalal"); 
    Note Text2(Text);
    Text.display();
    Text2.display();
}