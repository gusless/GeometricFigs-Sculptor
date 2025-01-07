#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

/// Sub-classe de `FiguraGeométrica` para colocar um elipsóide com tamanho, cor e coordenadas especificados.
class PutEllipsoid : public FiguraGeometrica{
protected:
    int rx, ///< Raio do elipsóide em X.
        ry, ///< Raio do elipsóide em Y.
        rz; ///< Raio do elipsóide em Z.
public:
    /// Método para colocar um elipsóide com as coordenadas, cor e transparência especificados.
    /// @param xcenter Coordenada X do ponto central.
    /// @param ycenter Coordenada Y do ponto central.
    /// @param xcenter Coordenada Y do ponto central.
    /// @param rx Raio do elipsóide em X.
    /// @param ry Raio do elipsóide em Y.
    /// @param rz Raio do elipsóide em Z.
    /// @param r Componente vermelho (Red) da cor, de 0 a 255.
    /// @param g Componente verde (Green) da cor, de 0 a 255.
    /// @param b Componente azul (Blue) da cor, de 0 a 255.
    /// @param a Componente de transparência (Alpha), de 0 a 1.
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);

    /// Método para desenhar a figura geométrica.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H
