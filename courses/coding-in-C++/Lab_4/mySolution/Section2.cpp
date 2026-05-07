class Shape{
    public:
        virtual ~Shape(){};
        virtual double ComputeArea() const{
            return 0.0;
        }
};

//has to have virtual function and destructor because it will definetly be used with Polymorphism

class Circle: public Shape{
    protected:
        double radius;
        static constexpr double PI = 3.141;
    public:
        Circle(double radius): radius(radius){};
        double ComputeArea() const override{
            return PI*radius*radius;
        }
};

class Rectangle: public Shape{
    protected:
        float x;
        float y;

    public:
        Rectangle(double x, double y): x(x), y(y){};
        double ComputeArea() const override{
            return x*y;
        }
};

int main(){
    Circle circle(5.1);
    Rectangle rectangle(3.2, 12.3);
}