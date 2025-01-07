#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"

/// Sub-classe de `FiguraGeométrica` para colocar um voxel em uma coordenada específicada.
class PutVoxel : public FiguraGeometrica{
public:
    /// Método para colocar o voxel com as coordenadas, cor e transparência especificados.
    /// @param x Coordenada X do ponto.
    /// @param y Coordenada Y do ponto.
    /// @param x Coordenada Y do ponto.
    /// @param r Componente vermelho (Red) da cor, de 0 a 255.
    /// @param g Componente verde (Green) da cor, de 0 a 255.
    /// @param b Componente azul (Blue) da cor, de 0 a 255.
    /// @param a Componente de transparência (Alpha), de 0 a 1.
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);

    /// Método para desenhar a figura geométrica.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
