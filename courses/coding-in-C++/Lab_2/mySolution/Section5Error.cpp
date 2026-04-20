#include <iostream>
#include <string>
#include <iomanip>
//header fehlt
using namespace std;  //kein using benutzen

class Article {
public:
    string name; //alle attribute sollten in private
    double price;
    int stock;
    string* category; //string pointer fehlt
    int id;

    Article(string name, double price, int stock, string category, int id) {
        name = name; //this fehlt
        price = price; //this fehlt
        stock = stock; //this fehlt
        this->id = id; //id wird nicht überprüft
        this->category = new string;
        *this->category = category;
    }

    void setPrice(double price) {
        price = price;//this
    }

    void sell(int amount) {
        stock = stock - amount;//this
    }

    void restock(int amount) {
        this->stock += amount;
    }

    double applyDiscount(double percent) {
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() { //konstante Funktion da nichts verändert wird
        return price;
    }

    bool isAvailable() { //konstante Funktion da nichts verändert wird
        if (stock > 0)
            return true; //{}fehlt
        else
            return false;
    }

    void printInfo() { //sollte seperat definiert werden
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};      //destruktor fehlt

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5);
    a.price = -100; //da public wird direkt auf price zugegriffen. schlecht
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl;  //schlechter syntax

    a.printInfo();
}