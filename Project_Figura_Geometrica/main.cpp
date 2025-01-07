#include "reader.h"
#include "file_functions.h"

/**
 * @brief Função principal do programa para gerar e manipular um arquivo OFF baseado em um arquivo TXT.
 *
 * Esta função executa o fluxo principal do programa, realizando as seguintes operações:
 * 1. Localiza um arquivo TXT contendo instruções predefinidas para construção de objetos.
 * 2. Lê o conteúdo do arquivo TXT e inicializa um objeto `Sculptor` com base nas dimensões especificadas.
 * 3. Executa os comandos do arquivo TXT para desenhar o objeto no espaço 3D.
 * 4. Salva o resultado no formato OFF.
 * 5. Abre o arquivo OFF gerado para visualização ou processamento adicional.
 *
 * @return int Retorna 0 se a execução foi bem-sucedida.
 */
int main(){
    char filename[] = "offFile.off"; ///< Nome do arquivo de saída no formato OFF.
    char txtfile[] = "txtFile.txt"; ///< Nome do arquivo TXT contendo instruções.

    // Localiza o arquivo TXT no sistema.
    std::string filetxt(txtfile);
    std::string txt_local = find_path("../../", txtfile); // Procura o arquivo txt.
    const char* txt_local_ = txt_local.c_str();

    // Inicializa o leitor para interpretar o arquivo TXT.
    Reader r(txt_local_);

    // Cria o objeto Sculptor com base nas dimensões lidas.
    Sculptor s(r.getDimX(), r.getDimY(), r.getDimZ());

    // Executa as instruções do arquivo TXT para desenhar o objeto.
    r.draw(s);

    // Escreve o objeto desenhado em um arquivo OFF.
    s.writeOFF(filename);

    // Abre o arquivo OFF gerado.
    win_open_file(filename);

    return 0;
}

