#ifndef ASSISTANCE_SYSTEM_HPP
#define ASSISTANCE_SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <string>

#include "bugHunt_vehicle.hpp"

//schlechte Dokumentation, keine Beschreibungen 

class AssistanceFeature{
    private:
        std::string systemName;
    
    public:
        AssistanceFeature(std::string systemName);
        virtual void evaluate(Vehicle &vehicle, const std::shared_ptr<DistanceSensor>);
        void print_name();
        virtual ~AssistanceFeature();
};

class DistanceSensor
{
private:
    std::string position;
    bool active;
    double measured_distance_m; //warum public?

public:

    DistanceSensor(const std::string &sensor_position,
                   double initial_distance_m);

    void set_distance(double distance_m);
    void activate();
    void deactivate();

    double get_distance() const;
    bool is_active() const;
    std::string get_position() const;

    bool operator>(const DistanceSensor &other) const;
    bool is_exactly_at_warning_distance(double warning_distance) const;

    void print_info() const;
};

class EmergencyBrakeSystem : public AssistanceFeature
{
private:
    double critical_distance_m; 
    static constexpr float emergency_brake_force = 30.0;

public:
    EmergencyBrakeSystem(double critical_distance); 

    void evaluate(Vehicle &vehicle, const std::shared_ptr<DistanceSensor> front_sensor) override;
};

class LaneKeepingAssist
{
private:
    double max_allowed_offset_m;
    double correction_angle;

public:
    LaneKeepingAssist(double max_offset, double correction);

    void evaluate(Vehicle &vehicle) const;
};

class AdaptiveCruiseControl : public AssistanceFeature
{
private:
    double target_speed_kmh;
    double minimum_distance_m;

    static constexpr float standart_brake_force = 5.0;
    static constexpr float standart_acceleration = 5.0;

public:
    AdaptiveCruiseControl(double target_speed,
                          double minimum_distance);

    void evaluate (Vehicle &vehicle,
                  const std::shared_ptr<DistanceSensor> front_sensor) override;
};

class ParkingAssistant : public AssistanceFeature
{
private:
    std::vector<std::shared_ptr<DistanceSensor>> sensors;
    double warning_distance_m;

public:
    ParkingAssistant(double warning_distance);

    void add_sensor(std::shared_ptr<DistanceSensor> sensor);
    void print_warnings() const;
};

#endif