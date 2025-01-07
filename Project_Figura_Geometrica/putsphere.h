#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

/// Sub-classe de `FiguraGeométrica` para colocar uma esfera com tamanho, cor e coordenadas especificados.
class PutSphere : public FiguraGeometrica{
protected:
    int radius; ///< Raio da esfera.
public:
    /// Método para colocar uma esfera com as coordenadas, cor e transparência especificados.
    /// @param xcenter Coordenada X do ponto central.
    /// @param ycenter Coordenada Y do ponto central.
    /// @param xcenter Coordenada Y do ponto central.
    /// @param radius Raio da esfera.
    /// @param r Componente vermelho (Red) da cor, de 0 a 255.
    /// @param g Componente verde (Green) da cor, de 0 a 255.
    /// @param b Componente azul (Blue) da cor, de 0 a 255.
    /// @param a Componente de transparência (Alpha), de 0 a 1.
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);

    /// Método para desenhar a figura geométrica.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
