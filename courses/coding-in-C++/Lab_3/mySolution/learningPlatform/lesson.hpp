#ifndef LESSON_HPP
#define LESSON_HPP

#include <string>
#include <iostream>
#include "content.hpp"

class Lesson {
private:
    std::string lesson_name;
    Content lesson_content;

public:
    Lesson(std::string name, Content content): lesson_name(name), lesson_content(content) {};
    Lesson(std::string name): lesson_name(name) {};
    Lesson() {};

    ~Lesson();

    void addLessonContent(Content newContent){
        lesson_content = newContent;
    };
    Content getLessonContent(){
        return lesson_content;
    };
    std::string getLessonName(){
        return lesson_name;
    }

};

#endif // LESSON_HPP