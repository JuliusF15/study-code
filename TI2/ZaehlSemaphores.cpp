#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>

constexpr int MAX_PARALLEL = 3;
std::counting_semaphore<MAX_PARALLEL> slots(MAX_PARALLEL);

void download(int id){
    slots.acquire();
    std::cout << "start dl " << id << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "end   dl " << id << '\n';
    slots.release();
}

int main(){
    std::vector<std::thread> v;
    for (int i = 0; i < 5; ++i){
        v.emplace_back(download, i);
    }
    for(auto& t : v){
        t.join();
    }
}