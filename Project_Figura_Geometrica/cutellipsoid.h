#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

/// Sub-classe de `FiguraGeométrica` para apagar um elipsóide com as coordenadas especificadas.
class CutEllipsoid : public FiguraGeometrica{
protected:
    int rx, ///< Raio do elipsóide em X.
        ry, ///< Raio do elipsóide em Y.
        rz; ///< Raio do elipsóide em Z.
public:
    /// Método para apagar um elipsóide com as coordenadas especificados.
    /// @param xcenter Coordenada X do ponto central.
    /// @param ycenter Coordenada Y do ponto central.
    /// @param xcenter Coordenada Y do ponto central.
    /// @param rx Raio do elipsóide em X.
    /// @param ry Raio do elipsóide em Y.
    /// @param rz Raio do elipsóide em Z.
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /// Método para desenhar a figura geométrica.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H
