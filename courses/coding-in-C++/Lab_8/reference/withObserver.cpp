#include <iostream>
#include <vector>

// ======================================================
// Observer Interface
// ======================================================

class Observer
{
public:
    virtual void update(float value) = 0;

    virtual ~Observer() = default;
};

// ======================================================
// Subject
// ======================================================

class TemperatureSensor
{
private:
    float temperature = 0.0f;

    std::vector<Observer *> observers;

    void notify_observers()
    {
        for (Observer *observer : observers)
        {
            observer->update(temperature);
        }
    }

public:
    void add_observer(Observer *observer)
    {
        observers.push_back(observer);
    }

    void set_temperature(float value)
    {
        temperature = value;

        notify_observers();
    }
};

// ======================================================
// Concrete Observer: Display
// ======================================================

class Display : public Observer
{
public:
    void update(float value) override
    {
        std::cout << "Display: " << value << " C\n";
    }
};

// ======================================================
// Concrete Observer: Logger
// ======================================================

class Logger : public Observer
{
public:
    void update(float value) override
    {
        std::cout << "Logger: " << value << " C\n";
    }
};

class Alarm : public Observer{
    public:
        void update(float value) override{
            if(value > 30){
                std::cout << "ALARM" << std::endl;
            }
        }
};

class CloudPublisher : public Observer{
    private:
        float old_value = -1;

    public:
        void update(float value) override{
            if(old_value == -1){
                old_value = value;
            }
            if(value != old_value ){
                std::cout << "Publishing " << value << std::endl;
            }else{
                old_value = value;
            }
        }
};
// ======================================================
// Main
// ======================================================

int main()
{
    TemperatureSensor sensor;

    Display display;
    Logger logger;
    Alarm alarm;
    CloudPublisher publisher;

    sensor.add_observer(&display);
    sensor.add_observer(&logger);
    sensor.add_observer(&alarm);
    sensor.add_observer(&publisher);

    sensor.set_temperature(33.5f);
    sensor.set_temperature(34.5f);

    return 0;
}