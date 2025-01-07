#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"
/// Sub-classe de `FiguraGeométrica` para apagar uma esfera com as coordenadas especificadas.
class CutSphere : public FiguraGeometrica{
protected:
    int radius; ///< Raio da esfera.
public:
    /// Método para apagar uma esfera com as coordenadas especificados.
    /// @param xcenter Coordenada X do ponto central.
    /// @param ycenter Coordenada Y do ponto central.
    /// @param xcenter Coordenada Y do ponto central.
    /// @param radius Raio da esfera.
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /// Método para desenhar a figura geométrica.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H
