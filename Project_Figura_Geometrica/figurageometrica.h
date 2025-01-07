#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

/**
 * @brief Classe base abstrata para representar figuras geométricas.
 *
 * Esta classe define uma interface genérica para figuras geométricas que podem ser desenhadas
 * em um objeto do tipo `Sculptor`. As figuras geométricas herdam desta classe para implementar
 * comportamentos específicos no método `draw`.
 */
class FiguraGeometrica{
protected:
    int x, ///< Coordenada X da figura.
        y, ///< Coordenada Y da figura.
        z; ///< Coordenada Z da figura.
    float r, ///< Intensidade da cor vermelha, de 0 a 255.
          g, ///< Intensidade da cor verde, de 0 a 255.
          b, ///< Intensidade da cor azul, de 0 a 255.
          a; ///< Transparência (alpha), onde 0.0 é totalmente transparente e 1.0 é totalmente opaco.

public:
    ///Construtor padrão da classe `FiguraGeometrica`.
    FiguraGeometrica();

    /// Destrutor virtual da classe `FiguraGeometrica`.
    virtual ~FiguraGeometrica();

    /**
     * @brief Método virtual puro para desenhar a figura.
     *
     * Este método deve ser implementado pelas classes derivadas, que definem como a figura
     * será desenhada em um objeto do tipo `Sculptor`.
     *
     * @param s Referência ao objeto `Sculptor` onde a figura será desenhada.
     */
    virtual void draw(Sculptor &s) = 0;
};

#endif // FIGURAGEOMETRICA_H
