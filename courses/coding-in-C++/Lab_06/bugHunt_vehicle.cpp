#include "bugHunt_vehicle.hpp"

Vehicle::Vehicle(const std::string &vehicle_model)
    : model(vehicle_model),
      speed_kmh(0.0),
      steering_angle(0.0),
      lane_offset_m(0.0),
      brake_light_on(false)
{
}

void Vehicle::accelerate(double amount_kmh)
{
    if (amount_kmh <= 0.0)
    {
        std::cout << "Acceleration must be positive!" << std::endl;    
        return;    
    }else if(amount_kmh > 100){
        std::cout << "Acceleration cant be to high!" << std::endl;
        return;
    }

    speed_kmh += amount_kmh;

    brake_light_on = false;
}

void Vehicle::brake(double amount_kmh)
{
    if (amount_kmh <= 0.0)
    {
        std::cout << "Brake Force must be positive!" << std::endl;
        return; //Exception wäre besser
    }else if(amount_kmh > 100){
        std::cout << "Brake Force cant be to high!" << std::endl;
        return;
    }

    speed_kmh -= amount_kmh;
    brake_light_on = true;

    if (speed_kmh < 0.0)
    {
        speed_kmh = 0.0; //macht keinen Sinn. Wenn Speed unter Null sollte auf Null gesetzt werden
    }
}

void Vehicle::steer(double angle)
{
    steering_angle = angle; //kein Imnput Test
}

void Vehicle::update_lane_offset(double offset)
{
    lane_offset_m = offset; //kein Input Test
}

double Vehicle::get_speed() const
{
    return speed_kmh;
}

double Vehicle::get_steering_angle() const
{
    return steering_angle;
}

double Vehicle::get_lane_offset() const
{
    return lane_offset_m;
}

const std::string &Vehicle::get_model() //const Rückgabetyp fehlt
{
    return model;
}

bool Vehicle::is_brake_light_on() const
{
    return brake_light_on;
}

void Vehicle::print_status() const
{
    std::cout << "Vehicle: " << model << '\n';
    std::cout << "Speed: " << speed_kmh << " km/h\n";
    std::cout << "Steering angle: " << steering_angle << " degrees\n";
    std::cout << "Lane offset: " << lane_offset_m << " m\n";
    std::cout << "Brake light: " << std::boolalpha << brake_light_on << "\n\n";
}