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
        #ifdef __APPLE__
            if (path.front() == '\''){
                path = path.erase(0,1);
            }

            if (path.back() == '\''){
                path = path.erase(path.length() - 1);
            }
        #endif

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
