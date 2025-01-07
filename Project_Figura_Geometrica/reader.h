#ifndef READER_H
#define READER_H
#include "figurageometrica.h"
#include <vector>

/// Classe que serve para ler um arquivo TXT com as instruções para gerar uma escultura 3D em um arquivo OFF.
class Reader{
    int dimX, ///< Tamanho máximo da matriz tridimensional no eixo X.
        dimY, ///< Tamanho máximo da matriz tridimensional no eixo Y.
        dimZ; ///< Tamanho máximo da matriz tridimensional no eixo Z.

    std::vector<FiguraGeometrica*> figs; ///< Vetor contendo métodos que geram figuras geométricas.

public:
    /// Construtor que abre o arquivo TXT de acordo com o nome do arquivo.
    /// @param *filename Nome do arquivo TXT que será lido.
    Reader(const char *filename);

    /// Destrutor da classe.
    ~Reader();

    /// Método para desenhar as figuras geométricas.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);

    ///Retorna o tamanho máximo da matriz em X.
    /// @return dimX
    int getDimX();

    ///Retorna o tamanho máximo da matriz em Y.
    /// @return dimY
    int getDimY();

    ///Retorna o tamanho máximo da matriz em Z.
    /// @return dimZ
    int getDimZ();
};

#endif // READER_H
