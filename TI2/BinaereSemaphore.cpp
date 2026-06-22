#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>

std::vector<int> ProductVec;

std::binary_semaphore door(1);

void produce(){
    static int productCounter = 0;
    std::cout << "Produkt erstellt: " << productCounter << std::endl;
    ProductVec.push_back(productCounter);
    productCounter++;
}

void consume(){
    std::cout << "Product consumed" << ProductVec.back() << std::endl;
    ProductVec.pop_back();
}


void workerProduce(char name){
    for(int i=0; i<1000000; i++){
        door.acquire();
        std::cout << name << " inside\n";
        produce();
        std::cout << name << " leaves\n";
        door.release();
    }
}
void workerConsume(char name){
    for(int i=0; i<1000000; i++){
        door.acquire();
        std::cout << name << " inside\n";
        consume();
        std::cout << name << " leaves\n";
        door.release();
    }
}

/*void workerC(char name){
        door.acquire();
        std::cout << name << " inside\n";
        for (int i = 0; i<500000; i++){
            counterDown(counter);
        }
        std::cout << counter << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << name << " leaves\n";
        door.release();
    }

    */



int main(){
    std::thread a{workerProduce, 'A'};
    std::thread b{workerConsume, 'B'};
    std::thread c{workerConsume, 'C'};
    a.join();
    b.join();
    c.join();
}