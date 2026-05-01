#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>
#include "content.hpp"
#include "lesson.hpp"
#include "user.hpp"

class Course {
private:
    constexpr static int MAX_LESSONS = 10;
    constexpr static int MAX_USERS = 100;

    std::string course_name;
    std::string course_description;
    Lesson lessons[MAX_LESSONS];
    User users[MAX_USERS];

public:
    Course(): course_name(""), course_description("") {};
    Course(std::string name, std::string description): course_name(name), course_description(description) {};
    ~Course();

    void setCourseName(const std::string& name){
        course_name = name;
    };
    void setCourseDescription(const std::string& description){
        course_description = description;
    };
    void addLesson(Lesson add_lesson){
        int i = 0;
        while(lessons[i].getLessonContent().getContent() != "" && i < MAX_LESSONS){
            i++;
        }
        if(lessons[i].getLessonContent().getContent() == ""){
            lessons[i] = add_lesson;
        }
        
    }
    void getLesson(int index, Lesson &returnLesson){
        if(lessons[index].getLessonContent().getContent() != ""){
            returnLesson = lessons[index];
        }else{
            std::cout << "No Lesson at Index " << index << std::endl;
        }
    }

    void printCourseInfo(){
        std::cout << "Course Name: " << course_name << std::endl;
        std::cout << "Course Description: " << course_description << std::endl;
        for(int i = 0; i < MAX_LESSONS; i++){
            if(lessons[i].getLessonContent().getContent() != ""){
                std::cout << "Lesson " << lessons[i].getLessonName() << ": " << lessons[i].getLessonContent().getContent() << std::endl;
            }else{
                std::cout << "No Content on Index: " << i << std::endl;
            }
        }
    }

};

#endif // COURSE_HPP