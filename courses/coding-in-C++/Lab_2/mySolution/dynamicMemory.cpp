#include <iostream>
#include <string>

using namespace std;

class Note{
    private:
        string* text;
    public:
        Note(string text_inp){
            text = new string;
            *text = text_inp;

        };
        Note(Note& t){ //Konstructor
            text = new string;
            *text = *t.text;
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