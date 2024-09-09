#include <iostream>
#include "File.h"

#define FLAG_FILTER (1<<0)
#define FLAG_SPLIT (1<<1)


bool filter(File *file) {
    std::cout<<"Input keyword"<<std::endl;
    std::string keyword;
    std::cin >> keyword;
    if (!keyword.empty()){
        return file->startFilter(keyword);
    }
    return false;
}

int split(File *file) {

    std::cout << "Input split block size(MB) " << std::endl;

    size_t splitSize;
    std::cin >> splitSize;

    if (splitSize > file->size) {
        std::cout << "File don't need split." << std::endl;
        return -2;
    }

    splitSize = splitSize * 1024 * 1024;

    file->startSplit(splitSize);
    return 0;
}

int main(int argc, char *argv[]) {
    int flags = 0;

    for (int i = 1; i < argc; ++i) {
        std::string item = argv[i];
        if (item == "-F") {
            flags |= FLAG_FILTER;
        } else if (item == "-S") {
            flags |= FLAG_SPLIT;
        } else {
            std::cout << "Unknown argument: " << item << std::endl;
        }
    }

    std::cout << "Input file path" << std::endl;
    std::string inputPath;
    std::cin >> inputPath;
    File file = File(inputPath);
    if (file.size < 0) {
        std::cout << "File not exists!" << std::endl;
        return -1;
    } else {
        std::cout << "File size: " << file.size << std::endl;
    }

    if (flags & FLAG_SPLIT || flags == 0) {
        return split(&file);
    }

    if (flags & FLAG_FILTER) {
        return filter(&file);
    }

    return -1;

}

