#include "Probeklausur.hpp"

int main(){

    E_Car EAuto("VW", "B", 1000);
    PKW Verbrenner("BMW", "A2", 15);
    
    Driver Paul("Paul");
    Driver Max("Max");

    Paul.addLicenses("B");
    Max.addLicenses("A2");

    std::vector<Car> carVector = {EAuto, Verbrenner};
    std::vector<Driver> driverVector = {Paul, Max};

    EAuto.assignDriver(Paul);
    Verbrenner.assignDriver(Paul);
    Verbrenner.assignDriver(Max);

    EAuto.printInfo();
    Verbrenner.printInfo();
}