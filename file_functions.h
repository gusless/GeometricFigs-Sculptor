#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

namespace fs = std::filesystem;

std::string find_path(const std::string &directory, const std::string &filename){
    try{
        for(const auto &entry : fs::recursive_directory_iterator(directory)){
            //std::cout << entry.path().string() << std::endl;
            if(entry.is_regular_file() && entry.path().filename() == filename){
                return fs::absolute(entry.path()).string();
            }
        }
    } catch(const std::filesystem::filesystem_error &e){
    std::cerr << "Erro ao acessar a pasta" << e.what() << std::endl;
    }
    return "";
}

//funcao para abrir o arquivo no windows
void win_open_file(const char* filename){
    std::string file(filename);
    std::string file_local = find_path("../../",file);

    char file_path[200];
    file_local.copy(file_path,file_local.size());
    file_path[file_local.size()] = '\0';

    //std::cout << filename << std::endl;
    //std::cout << file_path << std::endl;

    if(!std::ifstream(file_path)){
        std::cerr << "Arquivo nao encontrado" << std::endl;
        return;
    }
#ifdef _WIN32
    ShellExecute(0, "open", file_path, NULL, NULL, SW_SHOWNORMAL);
#endif
}
#endif // FILE_FUNCTIONS_H
