#ifndef PROBEKLAUSUR_HPP
#define PROBEKLAUSUR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Car;

class Driver{
    protected:
        friend Car;
        static int ID_counter;
        int ID;
        std::string driverName;
        std::vector<std::string> licensesVector;
        std::weak_ptr<Car> carAssigned;

    public:
        Driver(std::string name);

        int getID() const;
        std::string getName() const;
        std::vector<std::string> getLicenses() const;
        std::weak_ptr<Car> getCar() const;

        void changeName(const std::string& name);

        void addLicenses(const std::string& license);
        void removeLicense(const std::string& license);
        bool hasLicense(const std::string& license);


};


class Car{
    protected:
        static int ID_counter;
        int ID;
        std::string brand;
        std::string license_req;
        std::shared_ptr<Driver> driver;

    public:
        Car(std::string brand, std::string license);
        ~Car() = default;
        int getID() const;
        std::string getBrand() const;
        std::string getLicenseReq() const;
        std::shared_ptr<Driver> getDriver() const;

        void changeBrand(const std::string& brand);
        void changeLicense(const std::string& license);

        void assignDriver(Driver& driver);
        void removeDriver();
        virtual void printInfo() const; 

};

class PKW : public Car{
    protected:
        float fuelConsumption;
    public:
        PKW(std::string brand, std::string license, float fuelConsumption);
        void printInfo() const override;

};

class E_Car : public Car{
    protected:
        float batteryCapacity;
    public:
        E_Car(std::string brand, std::string license, float capacity);
        void printInfo() const override;
};
#endif