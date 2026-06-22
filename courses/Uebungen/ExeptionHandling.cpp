#include <iostream>
#include <string>
#include <stdexcept>

class ConfigError: public;
class ConfigLoader{
    public:
        void load(const std::string& filename){
            if(filename == "missing.cfg"){
                throw std::runtime_error("Cant open File!");
            }
            if(filename == "invalid.cfg"){
                throw std::invalid_argument("Wrong Configuration!");
            }
            if(filename.empty()){
                throw std::invalid_argument("Empty Filename!");

            }if(filename.find(".cfg") == -1){ //NICHT DIE IDEALE LÖSUNG
                throw std::invalid_argument("Can only use .cfg Files!");
            }
        }
};

int main(){
    ConfigLoader loader;

    try{
        loader.load("missing.cfg");
    }
    catch
}