#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

/// Sub-classe de `FiguraGeométrica` para apagar um paralelepípedo com as coordenadas especificadas.
class CutBox : public FiguraGeometrica{
protected:
    int xf, ///< Coordenada final em X do paralelepípedo.
        yf, ///< Coordenada final em Y do paralelepípedo.
        zf; ///< Coordenada final em Z do paralelepípedo.
public:
    /// Método para apagar um paralelepípedo com as coordenadas especificadas.
    /// @param x0 Coordenada inicial em X do paralelepípedo.
    /// @param y0 Coordenada inicial em Y do paralelepípedo.
    /// @param x0 Coordenada inicial em Y do paralelepípedo.
    /// @param x1 Coordenada final em X do paralelepípedo.
    /// @param y1 Coordenada final em Y do paralelepípedo.
    /// @param x1 Coordenada final em Y do paralelepípedo.
    CutBox(int x0, int y0, int z0, int x1, int y1, int z1);

    /// Método para desenhar a figura geométrica.
    /// @param &s Sculptor com a figura geométrica específica.
    void draw(Sculptor &s);
};

#endif // CUTBOX_H
