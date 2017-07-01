#pragma once

#include "utils.h"
#include "Enums.h"
#include <cstring>

class Kernel {
private:
    std::vector<std::string> getArgs(std::string& src){
        std::vector<std::string> Args;
        std::size_t openBrace = src.find("{");
        std::size_t openPar = src.find("(");
        char* dup = strdup(src.substr(openPar, openBrace - openPar).c_str());
        char* token = std::strtok(dup, ",");
        while(token != NULL){
            Args.push_back(std::string(token));
            token = strtok(NULL, ",");
        }
        free(dup);
        for(int i=0;i<Args.size();i++){
            std::cout<<Args[i]<<std::endl;
        }
        return Args;
    }
public:
    std::string kernelName;
    std::map<int, Qualifier> Qualifier;
    std::map<int, bool> isPtr;
    std::map<int, bool> isConst;
    std::map<int, bool> isDoublePtr;
    std::map<int, PreDataType> preDataType;
    std::map<int, DataType> dataType;
    std::map<int, Attribute> attribute;
    std::map<int, int> bufferId;
    Kernel(std::string& src){
        std::size_t kernelNameBegin = src.find("kernel void ") + strlen("kernel void ");
        std::size_t kernelNameEnd = src.find("(");
        if(kernelNameEnd != std::string::npos && kernelNameBegin != std::string::npos) {
            for(std::size_t i=0;i<kernelNameEnd-kernelNameBegin;i++){
                kernelName = src.substr(kernelNameBegin, kernelNameEnd - kernelNameBegin);
            }
        }
        std::cout<<kernelName<<std::endl;
        getArgs(src);
    }
};
