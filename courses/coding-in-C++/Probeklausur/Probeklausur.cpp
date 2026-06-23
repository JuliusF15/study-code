#include "Probeklausur.hpp"


Driver::Driver(std::string name): driverName(name) {
    this->ID = this->ID_counter;
    this->ID_counter++;
}; 

int Driver::getID() const{
    return ID;
}

std::string Driver::getName() const{
    return driverName;
}

std::vector<std::string> Driver::getLicenses() const{
    return licensesVector;
}

void Driver::changeName(const std::string& name){
    if(!name.empty()){
        this->driverName = name;
        return;
    }else{
        std::cout << "Name cant be empty!\n";
        return; 
    }
}

void Driver::addLicenses(const std::string& license){ //add License Check
    if(!license.empty()){
        licensesVector.push_back(license);
        return;
    }else{
        std::cout << "License cant be empty!\n";
        return; 
    }
}

void Driver::removeLicense(const std::string& license){
    for (auto it = licensesVector.begin(); it!= licensesVector.end();){
        if(*it == license){
            it = licensesVector.erase(it);
            return;
        }else{
            ++it;
        }
    }
    std::cout << "Driver didnt have that License!\n";
}

bool Driver::hasLicense(const std::string& license){
    if(!license.empty()){
        for(auto i : licensesVector){
            if(i == license){
                return true;
            }
        }
        return false;
    }else{
        std::cout << "License cant be empty!\n";
        return false;
    }
}

std::weak_ptr<Car> Driver::getCar() const{
    return carAssigned;
}


Car::Car(std::string brand, std::string license): brand(brand), license_req(license) {
    this->ID = this->ID_counter;
    this->ID_counter++;
};

int Car::getID() const {
    return ID;
}

std::string Car::getBrand() const{
    return brand;
}

std::string Car::getLicenseReq() const{
    return license_req;
}

std::shared_ptr<Driver> Car::getDriver() const{
    return driver;
}

void Car::changeBrand(const std::string& brand){
    if(!brand.empty()){
        this->brand = brand;
    }else{
        std::cout << "Brand cant be empty!\n";
    }
}

void Car::changeLicense(const std::string& license){
        if(!license.empty()){
        this->license_req = license;
    }else{
        std::cout << "License cant be empty!\n";
    }
}

void Car::assignDriver(Driver& driver){
    if(driver.getCar().expired()){
        if(this->getDriver() == nullptr){
            if(driver.hasLicense(this->getLicenseReq())){
                this->driver = std::make_shared<Driver>(driver);
                driver.carAssigned = std::make_shared<Car>(*this);
                return;
            }
        }
    }
    std::cout << "Cant assign Driver\n";
    return;
}

void Car::removeDriver(){
    driver->carAssigned.reset();
    driver.reset();
}

PKW::PKW(std::string brand, std::string license, float consumption): Car(brand, license), fuelConsumption(consumption) {};

void PKW::printInfo() const{
    std::cout<< "Esential Information\n";
}

E_Car::E_Car(std::string brand, std::string license, float capacity): Car(brand, license), batteryCapacity(capacity) {};

void E_Car::printInfo() const{
    std::cout<< "Esential Information\n";
}