#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"
/// Classe base do programa, serve para colocar e retirar voxels, escolher a cor e escrever em um arquivo OFF.
class Sculptor{

public:
    /// Matriz de voxels tridimensional que guarda o local de cada bloco da escultura.
    Voxel ***v;
    int nx, ///< Coordenada X do ponto.
        ny, ///< Coordenada Y do ponto.
        nz; ///< Coordenada Z do ponto.
    float r, ///< Componente vermelho (Red) da cor, de 0 a 255
          g, ///< Componente verde (Green) da cor, de 0 a 255
          b, ///< Componente azul (Blue) da cor, de 0 a 255
          a; ///< Componente de transparência (Alpha), de 0 a 1

    /// Construtor do programa, possui 3 parâmetros representando uma coordenada do plano tridimensional.
    /// @param _nx Coordenada X do ponto.
    /// @param _ny Coordenada Y do ponto.
    /// @param _nx Coordenada Y do ponto.
    Sculptor(int _nx, int _ny, int _nz);

    /// Destrutor da classe.
    ~Sculptor();

    /// Método para selecionar uma cor RGB, e sua transparencia `a`.
    /// @param r Componente vermelho (Red) da cor, de 0 a 255
    /// @param g Componente verde (Green) da cor, de 0 a 255
    /// @param b Componente azul (Blue) da cor, de 0 a 255
    /// @param a Componente de transparência (Alpha), de 0 a 1
    void setColor(float r, float g, float b, float a);

    /// Método para colocar um Voxel em uma coordenada do plano tridimensional.
    /// @param x Coordenada X do ponto.
    /// @param y Coordenada Y do ponto.
    /// @param x Coordenada Y do ponto.
    void putVoxel(int x, int y, int z);

    /// Método para apagar um Voxel em uma coordenada do plano tridimensional.
    /// @param x Coordenada X do ponto.
    /// @param y Coordenada Y do ponto.
    /// @param x Coordenada Y do ponto.
    void cutVoxel(int x, int y, int z);

    /// Método para escrever a escultura em um arquivo OFF.
    /// @param *filename Nome do arquivo para escrita.
    void writeOFF(const char *filename);

    /// Retorna o eixo x da coordenada.
    /// @return nx
    int getX();

    /// Retorna o eixo y da coordenada.
    /// @return ny
    int getY();

    /// Retorna o eixo z da coordenada.
    /// @return nz
    int getZ();
};

#endif // SCULPTOR_H
