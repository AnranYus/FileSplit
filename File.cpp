//
// Created by Anran on 2024/9/5.
//

#include "File.h"
#include <filesystem>
#include <fstream>
#include <vector>
#include <iostream>

bool File::isExists() {
    return std::filesystem::exists(path);
}

unsigned File::checkSize() {
    return std::filesystem::file_size(path);
}

bool File::startSplit(size_t maxChunkSize) {
    size_t fileSize = size;

    std::ifstream file(path,std::ios::binary);
    if (!file.is_open()){
        std::cerr <<"File open fail: " << path <<std::endl;
        return false;
    }

    size_t chunks = fileSize/maxChunkSize + (fileSize % maxChunkSize != 0);
    size_t readSize;
    char* buffer = new char[maxChunkSize];
    for (int i = 0; i < chunks; ++i) {
        std::string fileBlock = path+"."+std::to_string(i);
        std::ofstream output(fileBlock,std::ios::binary);

        if (!output.is_open()){
            std::cout<< "Failed to write file block";
            delete[] buffer;
            file.close();
            return false;
        }
        readSize = std::min(maxChunkSize,fileSize);

        file.read(buffer,readSize);
        output.write(buffer,file.gcount());

        fileSize -= readSize;

        output.close();
        std::cout << "Out put file:" << fileBlock << std::endl;
    }
    delete[] buffer;
    file.close();


    return true;
}

bool File::startFilter(const std::string& keyword) {
    std::ifstream file(this->path);
    std::string line;
    std::ofstream output(this->path + "_"+keyword,std::ios::binary);

    while (std::getline(file,line)){
        if (line.find(keyword) != std::string::npos){
            output << line<<std::endl;
        }
    }
    std::cout << "Out put file:" << this->path + "_"+keyword << std::endl;
    file.close();
    output.close();
    return true;
}
