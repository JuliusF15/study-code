#include <iostream>
#include <memory>

#include "bugHunt_vehicle.hpp"
#include "bugHunt_assistance_system.hpp"

int main()
{
    Vehicle ego_vehicle("Vector X1");

    DistanceSensor front_sensor("front", 25.0);
    DistanceSensor rear_sensor("rear", 1.2);
    DistanceSensor left_sensor("left", 0.8);
    DistanceSensor right_sensor("right", 3.0);

    std::shared_ptr p_front_sensor = std::make_shared<DistanceSensor>(front_sensor);
    std::shared_ptr p_rear_sensor = std::make_shared<DistanceSensor>(rear_sensor);
    std::shared_ptr p_left_sensor = std::make_shared<DistanceSensor>(left_sensor);
    std::shared_ptr p_right_sensor = std::make_shared<DistanceSensor>(right_sensor);

    std::cout << p_rear_sensor.use_count() << std::endl;
    std::cout << p_front_sensor.use_count() << std::endl;

    std::vector<std::unique_ptr<AssistanceFeature>> assistanceSystemsVector;
    
    EmergencyBrakeSystem emergency_brake(10.0);
    LaneKeepingAssist lane_assist(0.4, 5.0);
    AdaptiveCruiseControl cruise_control(80.0, 15.0);
    ParkingAssistant parking_assistant(1.5);

    std::unique_ptr p_emergency_brake = std::make_unique<AssistanceFeature>(emergency_brake);
    std::unique_ptr p_parking_assistant = std::make_unique<AssistanceFeature>(parking_assistant);
    std::unique_ptr p_cruise_control = std::make_unique<AssistanceFeature>(cruise_control);

    assistanceSystemsVector.push_back(p_emergency_brake);
    assistanceSystemsVector.push_back(p_parking_assistant);
    assistanceSystemsVector.push_back(p_cruise_control);

    parking_assistant.add_sensor(p_rear_sensor);
    parking_assistant.add_sensor(p_left_sensor);
    parking_assistant.add_sensor(p_right_sensor);

    std::cout << p_rear_sensor.use_count() << std::endl;


    std::cout << "--- Initial vehicle status ---\n";
    ego_vehicle.print_status();

    std::cout << "--- Accelerating vehicle ---\n";
    ego_vehicle.accelerate(50.0);
    ego_vehicle.print_status();

    std::cout << "--- Adaptive cruise control test ---\n";
    front_sensor.set_distance(12.0);
    cruise_control.evaluate(ego_vehicle, p_front_sensor);
    ego_vehicle.print_status();

    std::cout << "--- Emergency brake system test ---\n";
    front_sensor.set_distance(25.0);
    emergency_brake.evaluate(ego_vehicle, p_front_sensor);
    ego_vehicle.print_status();
    std::cout << p_front_sensor.use_count() << std::endl;

    std::cout << "--- Lane keeping assist test ---\n";
    ego_vehicle.update_lane_offset(0.7);
    lane_assist.evaluate(ego_vehicle);
    ego_vehicle.print_status();

    std::cout << "--- Parking assistant test ---\n";
    parking_assistant.print_warnings();

    std::cout << "--- Manual braking test ---\n";
    ego_vehicle.brake(100.0);
    ego_vehicle.print_status();


    return 0;
}