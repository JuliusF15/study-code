#include <iostream>
#include <string>

using namespace std;

class BankAccount{
    private:
        string owner;
        double balance;
    public:
        BankAccount() : balance(0){        }

        void setOwner(string owner){
            this->owner = owner;
        }

        string getOwner(){
            return owner;
        }

        int deposit(double num_deposit){
            if(num_deposit > 0){
                balance += num_deposit;
                return 0;
            }else{
                return -1;
            }
        }
        int withdraw(double num_withdraw){
            if(balance >= num_withdraw){
                balance -= num_withdraw;
                cout << "new balance: " << balance << endl;
                return 0;

            }else{
                return -1;
            }
        }
        double getBalance();
        void getAccountInfo();
};

double BankAccount::getBalance(){
    return(balance);
}

void BankAccount::getAccountInfo(){
     cout << "Owner: " << owner << endl;
     cout << "Balance: " << balance << endl;
}

int main(){
    BankAccount Account1;

    Account1.setOwner("Julius");
    Account1.deposit(1000.0);
    Account1.getAccountInfo();
    if(Account1.withdraw(1523.4) == -1){
        cout << "Balance to low!" << endl;
        cout << "Balance: " << Account1.getBalance() << endl;
    };

}