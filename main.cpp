#include <iostream>
#include "File.h"

int main() {
    std::cout<<"Input file path"<<std::endl;
    std::string inputPath;
    std::cin>>inputPath;
    File file = File(inputPath);
    if (file.size < 0){
        std::cout << "File not exists!" << std::endl;
        return -1;
    } else{
        std::cout << "File size: "<<file.size<<std::endl;
    }

    std::cout << "Input split block size(MB) "<<std::endl;

    size_t splitSize;
    std::cin >> splitSize;

    if (splitSize > file.size){
        std::cout << "File don't need split." << std::endl;
        return -2;
    }
    
    splitSize = splitSize * 1024*1024;

    file.startSplit(splitSize);

    return 0;
}
