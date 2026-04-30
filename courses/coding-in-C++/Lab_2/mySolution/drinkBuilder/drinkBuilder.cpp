#include <iostream>

constexpr int MAX_SUGAR = 100;
constexpr int DEFAULT_SUGAR = 0;
constexpr int DEFAULT_TEMPERATURE = 0;
constexpr bool DEFAULT_MILKSTATE = false;

/*
- constexpr initialisiert Variablen ganz am Anfang beim Compilen. Sind Konstant.
- DrinkBuilder() ist der Konstruktor, mit :name() sugar()... werden die Anfangsvariablen initialisiert
- method chaining: die Funktionen müssen return *this, dafür Funktionstyp: Klassenname& 
- const Funktionen dürfen keine Private Variablen ändern 
- const std::string& name //übergibt nur eine referenz(performance) und const sorgt dafür, dass man name nicht ausversehen ändern kann(Sicherheit)
- std::boolalpha printed bools als "true", "false"
*/

class DrinkBuilder{
    private: 
        std::string name;
        int sugar;
        int temperature;
        bool withMilk;

    public:
        DrinkBuilder(): //Konstruktor
        name("NoName"), sugar(DEFAULT_SUGAR), temperature(DEFAULT_TEMPERATURE), withMilk(DEFAULT_MILKSTATE) //Initialisierungsliste ist besser, da es effizienter als normale Konstruktoren ist 
        {
        }

        DrinkBuilder& setName(const std::string& name){ //übergibt nur eine referenz(performance) und const sorgt dafür, dass man name nicht ausversehen ändern kann(Sicherheit)
            this->name = name;
            return *this;
        };
        DrinkBuilder& setSugar(int sugar){
            if(sugar >= 0 && sugar < MAX_SUGAR){
                this->sugar = sugar;
            }else{
                std::cout << "Error: Sugar cant be negative!!" << std::endl;
            }
            return *this;
        };
        DrinkBuilder& setTemperature(int temperature){
            if(temperature > 0){
                this->temperature = temperature;
            }else{
                std::cout << "Error: Temperature has to be greater than 0!!" << std::endl;
            }
            return *this;
        };
        DrinkBuilder& setWithMilk(bool withMilk){
            this->withMilk = withMilk;
            return *this;

        };
        void print() const;
        

};

void DrinkBuilder::print() const{
    std::cout << "Drink: " << name << std::endl;
    std::cout << "Sugar: " << sugar << std::endl;
    std::cout << "Temperature: " << temperature << std::endl;
    std::cout << std::boolalpha;
    std::cout << "With Milk: " << withMilk << std::endl;
};
 
int main(){
    DrinkBuilder builder;
    builder.setName("Tea")
            .setSugar(10)
            .setTemperature(65)
            .setWithMilk(true)
            .print();    
    
    builder.setName("Wasser")
            .setSugar(0)
            .setTemperature(20)
            .setWithMilk(false)
            .print();    

    DrinkBuilder drink;
    drink.setName("KAFEE").setSugar(5).setTemperature(67).setWithMilk(true).print();
}