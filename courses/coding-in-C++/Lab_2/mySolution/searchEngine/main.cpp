#include <iostream>
#include <string>
#include "webResource.hpp"

int main(){
    WebResource Website1("https://bla.bla.com", "Hallo Blalalala");
    
    std::string address; 
    Website1.getAddress(address);
    
    std::string information;
    Website1.getInformation(information);
    
    std::cout << "Adresse: " << address << " Information: " << information << " " << Website1.getNumWebResources() << std::endl;
    WebResource Website2("https://aua.baua.de", "caua daua");
    std::cout << std::endl;
    
    std::cout << "Adresse: " << Website2.getAddress() << " Information: " << Website2.getInformation() << " " << Website2.getNumWebResources() << std::endl;
    WebResource Website3("https://Tralalero-Tralala.com", "Sechs Sieba");
    std::cout << std::endl;
    
    
    Website3.getAddress(address);
    Website3.getInformation(information);
    std::cout << "Adresse: " << address << " Information: " << information << " " << Website3.getNumWebResources() << std::endl;
    std::cout << std::endl;


    return 0;
}