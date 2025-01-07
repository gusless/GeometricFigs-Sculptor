#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

namespace fs = std::filesystem;

/**
 * @brief Procura um arquivo em um diretório e retorna seu caminho absoluto.
 *
 * Esta função busca recursivamente em um diretório especificado para localizar
 * um arquivo com o nome fornecido. Se o arquivo for encontrado, o caminho
 * absoluto é retornado. Caso contrário, uma string vazia é retornada.
 *
 * @param directory O diretório raiz onde a busca será realizada. Deve ser um caminho válido.
 * @param filename O nome do arquivo a ser localizado. Deve incluir apenas o nome e a extensão.
 * @return std::string O caminho absoluto do arquivo encontrado ou uma string vazia caso o arquivo não seja localizado.
 *
 * @throws std::filesystem::filesystem_error Caso ocorra algum erro ao acessar o sistema de arquivos.
 *
 * @note Esta função utiliza a biblioteca `std::filesystem` para realizar operações no sistema de arquivos.
 */
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

/**
 * @brief Abre um arquivo especificado pelo caminho fornecido e realiza verificações.
 *
 * Esta função tenta localizar o arquivo especificado e verifica se ele existe.
 * Caso o arquivo não seja encontrado, uma mensagem de erro será exibida.
 *
 * @param filename O caminho relativo ou absoluto do arquivo a ser aberto.
 * Deve ser uma string terminada em caractere nulo (`const char*`).
 */
void win_open_file(const char *filename){
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
