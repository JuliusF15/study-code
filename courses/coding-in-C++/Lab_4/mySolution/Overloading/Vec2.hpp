#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>
#include <cmath>

class Vec2{
    private:
        double x;
        double y;
    public:
        Vec2(): x(0.0), y(0.0){};
        Vec2(double x, double y): x(x), y(y) {};

        double getX() const{
            return x;
        }
        double getY() const{
            return y;
        }
        void printCords() const{
            std::cout << "X: " << this->getX() << " Y: " << this->getY() << std::endl;
        }

        //Function Overloading
        double VecLength() const{
            return sqrt(pow(this->getX(), 2) + pow(this->getY(), 2));
        }
        double VecLength(int decimal) const{
            double length = this->VecLength();
            double factor = std::pow(10.0, decimal);
            return std::round(length * factor) / factor;
        }
        void print(const Vec2& vec) const{
            std::cout << "Vector X: " << vec.getX() << "Vector Y: " << vec.getY() << std::endl;
        }

        //Operator Overloading
        //Member Function da nur ein Eingabewert
        void operator+=(const Vec2& vec){ //Overloading mit verändern des Originalobjekts
            this->x += vec.getX();
            this->y += vec.getY();  
        }
        void operator*(int Skalar){
            this->x *= Skalar;
            this->y *= Skalar;
        }
    };
    
//Free Functions, da zwei Eingabewerte
Vec2 operator+(const Vec2& v_left, const Vec2& v_right){
    return Vec2(v_left.getX() + v_right.getX(),
                v_left.getY() + v_right.getY());
}
bool operator==(const Vec2& v_left, const Vec2& v_right){
    return v_left.getX() == v_right.getX() && v_left.getY() == v_right.getY();

}
bool operator!=(const Vec2& v_left, const Vec2& v_right){
    return v_left.getX() != v_right.getX() && v_left.getY() != v_right.getY();
}
    

#endif