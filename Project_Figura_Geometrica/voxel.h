#ifndef VOXEL_H
#define VOXEL_H

/// Struct que representa um Voxel, ou seja o menor bloco possível deste projeto, com dimensão 1x1x1
struct Voxel {
    float r, ///< Componente vermelho (Red) da cor, de 0 a 255
          g, ///< Componente verde (Green) da cor, de 0 a 255
          b, ///< Componente azul (Blue) da cor, de 0 a 255
          a; ///< Componente de transparência (Alpha), de 0 a 1
    bool show; ///< Componente que representa se o bloco está posicionado ou não
};

#endif // VOXEL_H
