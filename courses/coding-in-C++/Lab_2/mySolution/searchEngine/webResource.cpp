#include <iostream>
#include <string>
#include "webResource.hpp"

int WebResource::numberWebResources = 0;

WebResource::WebResource(const std::string &address, const std::string &information): 
            address(address), information(information), rank(0) {
                numberWebResources++;
            };

WebResource::WebResource(): 
            address(""), information(""), rank(0) {
                numberWebResources++;
            };

void WebResource::editAddress(const std::string &address){
    this->address = address;
};

void WebResource::getAddress(std::string &get_address) const{
    get_address = address;
};

std::string WebResource::getAddress() const{
    return address;
}

void WebResource::editInformation(const std::string &information){
    this->information = information;  
};

void WebResource::getInformation(std::string &get_information) const{
    get_information = information;
};

std::string WebResource::getInformation() const{
    return information;
};

void WebResource::editRank(int rankChange){
    rank += rankChange;
};

int WebResource::getRank() const{
    return rank;
};

bool WebResource::isPopular() const{
    if(rank >= THRESHOLD_POPULAR){
        return true;
    }else{
        return false;
    }
};

int WebResource::getNumWebResources() const{
    return numberWebResources;
};