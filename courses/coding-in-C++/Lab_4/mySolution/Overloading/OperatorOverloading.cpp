#include "Vec2.hpp"

int main(){

    Vec2 Vector1(10, 13.2), Vector2(5,12);
    Vec2 Vector3 = Vector1 + Vector2;

    std::cout << "Vector1: " << Vector1.getX() << std::endl;
    std::cout << "Vector2: " << Vector2.getX() << std::endl;
    std::cout << "Vector3: " << Vector3.getX() << std::endl;
    Vector3 += Vector1;
    std::cout << "Vector3: " << Vector3.VecLength() << std::endl;
    std::cout << "Vector1: " << Vector3.getX() << std::endl;
    std::cout << "Vector1: " << Vector3.getY() << std::endl;


    Vector3 * 2;
    std::cout << "Vector3: " << Vector3.VecLength() << std::endl;
    std::cout << "Vector1: " << Vector3.getX() << std::endl;
    std::cout << "Vector1: " << Vector3.getY() << std::endl;
    
    std::cout << std::boolalpha;
    if(Vector1 == Vector1){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }


    

}