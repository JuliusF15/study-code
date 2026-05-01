#include "content.hpp"
#include "user.hpp"
#include "course.hpp"
#include "lesson.hpp"

int main(){
    Course Mathe("Mathematik", "Ein Kurs ueber Mathematik");
    Lesson Analysis("Mathe");
    Content Aufgaben;

    Aufgaben.addContent("Aufgabe 1: assaslsls, Aufgabe2: akskdadn");

    Analysis.addLessonContent(Aufgaben);

    Mathe.addLesson(Analysis);

    Mathe.printCourseInfo();
}