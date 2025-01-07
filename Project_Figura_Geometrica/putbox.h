#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"

/// Sub-classe de `FiguraGeométrica` para colocar um paralelepípedo com tamanho, cor e coordenadas especificados.
class PutBox : public FiguraGeometrica{
protected:
    int xf, ///< Coordenada final em X do paralelepípedo.
        yf, ///< Coordenada final em Y do paralelepípedo.
        zf; ///< Coordenada final em Z do paralelepípedo.
public:
    /// Método para colocar um paralelepípedo com as coordenadas, cor e transparência especificados.
    /// @param x0 Coordenada inicial em X do paralelepípedo.
    /// @param y0 Coordenada inicial em Y do paralelepípedo.
    /// @param x0 Coordenada inicial em Y do paralelepípedo.
    /// @param x1 Coordenada final em X do paralelepípedo.
    /// @param y1 Coordenada final em Y do paralelepípedo.
    /// @param x1 Coordenada final em Y do paralelepípedo.
    /// @param r Componente vermelho (Red) da cor, de 0 a 255.
    /// @param g Componente verde (Green) da cor, de 0 a 255.
    /// @param b Componente azul (Blue) da cor, de 0 a 255.
    /// @param a Componente de transparência (Alpha), de 0 a 1.
    PutBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a);

    /// Método para desenhar a figura geométrica.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);
};

#endif // PUTBOX_H
