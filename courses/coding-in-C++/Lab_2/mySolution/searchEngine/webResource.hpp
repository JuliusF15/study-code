#include <string>
#include <iostream>

class WebResource{
    private:
        std::string address;
        std::string information;
        int rank;
        static int numberWebResources;
        int THRESHOLD_POPULAR = 50;

    public:
        WebResource(const std::string &address, const std::string &information); //Konstruktor

        WebResource();

        void editAddress(const std::string &address);

        void getAddress(std::string &get_address) const;

        std::string getAddress() const;

        void editInformation(const std::string &information);

        void getInformation(std::string &get_information) const;
        
        std::string getInformation() const;

        void editRank(int rankChange);

        int getRank() const;

        bool isPopular() const;

        int getNumWebResources() const;
};