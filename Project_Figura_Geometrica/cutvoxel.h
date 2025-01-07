#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
/// Sub-classe de `FiguraGeométrica` para colocar um voxel em uma coordenada específicada.
class CutVoxel : public FiguraGeometrica{
public:
    /// Método para apagar o voxel com a coordenada especificada.
    /// @param x Coordenada X do ponto.
    /// @param y Coordenada Y do ponto.
    /// @param x Coordenada Y do ponto.
    CutVoxel(int x, int y, int z);

    /// Método para desenhar a figura geométrica.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H
