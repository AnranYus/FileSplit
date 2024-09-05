//
// Created by Anran on 2024/9/5.
//

#ifndef UNTITLED_FILE_H
#define UNTITLED_FILE_H


#include <string>

class File {
private:
    std::string path;
public:
    explicit File(std::string path){
        this->path = std::move(path);
        if (isExists()){
            size = checkSize();
        }
    }
    size_t size;
    bool isExists();
    unsigned checkSize();
    bool startSplit(size_t maxChunkSize);

};


#endif //UNTITLED_FILE_H
