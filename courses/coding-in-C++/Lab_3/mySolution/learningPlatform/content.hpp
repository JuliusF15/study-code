#ifndef CONTENT_HPP
#define CONTENT_HPP

#include <string>
#include <iostream>

class Content {
private:
    std::string content;

public:
    Content(): content("") {};
    Content(std::string content): content(content) {};
    ~Content();
    void addContent(const std::string& newContent){
        content += newContent;
    };
    std::string getContent(){
        return content;
    };
};

#endif // CONTENT_HPP