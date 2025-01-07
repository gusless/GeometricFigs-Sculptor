# Figura Geométrica

![Status](https://img.shields.io/badge/status-active-brightgreen)
![C++](https://img.shields.io/badge/language-C%2B%2B-blue)
![License](https://img.shields.io/badge/license-MIT-green)

## Descrição

O **Figura Geométrica** é um projeto desenvolvido em **C++**, utilizando programação orientada a objetos, que converte arquivos TXT contendo uma série de instruções predefinidas em arquivos **OFF**. Esses arquivos são utilizados para representar modelos tridimensionais. 

O projeto oferece uma estrutura modular para manipulação e geração de figuras geométricas tridimensionais.

---

## Funcionalidades

- **Leitura de Arquivos TXT:** Interpreta instruções para criar figuras geométricas.
- **Renderização de Modelos 3D:** Gera arquivos **OFF** para visualização em ferramentas 3D.
- **Programação Modular:** Classes específicas para diferentes tipos de figuras.
- **Interface Extensível:** Adicione novas formas geométricas com facilidade.

---

## Uso

### Estrutura de um Arquivo TXT de Entrada

Um arquivo TXT de entrada deve começar com a definição das dimensões do projeto, utilizando o comando `DIM`:

```txt
DIM X Y Z
```

Este comando define o tamanho da matriz tridimensional gerada, ou seja, o tamanho da "escultura" que será manipulada.

#### Exemplo:
```txt
DIM 150 150 150
```

Após a definição das dimensões, o arquivo TXT deve conter uma sequência de instruções no seguinte formato:

```txt
PUTVOXEL X Y Z R G B A
CUTVOXEL X Y Z
PUTBOX X0 Y0 Z0 X1 Y1 Z1 R G B A
CUTBOX X0 Y0 Z0 X1 Y1 Z1
PUTSPHERE XC YC ZC RADIUS R G B A
CUTSPHERE XC YC ZC RADIUS
PUTELLIPSOID XC YC ZC RX RY RZ R G B A
CUTELLIPSOID XC YC ZC RX RY RZ
```

#### Explicação dos Comandos:

- **DIM x y z**: Define as dimensões do espaço 3D.
- **PUTVOXEL x y z r g b a**: Adiciona um voxel (ponto no espaço 3D) na posição `(x, y, z)` com a cor RGB `(r, g, b)` e transparência `a`.
- **CUTVOXEL x y z**: Remove o voxel na posição `(x, y, z)`.
- **PUTBOX x0 y0 z0 x1 y1 z1 r g b a**: Cria uma caixa entre os pontos `(x0, y0, z0)` e `(x1, y1, z1)` com a cor RGB `(r, g, b)` e transparência `a`.
- **CUTBOX x0 y0 z0 x1 y1 z1**: Remove uma caixa de voxels entre os pontos `(x0, y0, z0)` e `(x1, y1, z1)`.
- **PUTSPHERE xc yc zc radius r g b a**: Adiciona uma esfera centrada em `(xc, yc, zc)` com o raio `radius` e a cor RGB `(r, g, b)` e transparência `a`.
- **CUTSPHERE xc yc zc radius**: Remove uma esfera com o centro em `(xc, yc, zc)` e o raio `radius`.
- **PUTELLIPSOID xc yc zc rx ry rz r g b a**: Adiciona um elipsoide com o centro em `(xc, yc, zc)` e raios `rx`, `ry`, `rz`, com a cor RGB `(r, g, b)` e transparência `a`.
- **CUTELLIPSOID xc yc zc rx ry rz**: Remove um elipsoide com o centro em `(xc, yc, zc)` e raios `rx`, `ry`, `rz`.

### Exemplo de Entrada:

```txt
PUTVOXEL 1 1 1 255 0 0 1
PUTVOXEL 2 2 2 0 100 50 1
PUTBOX 3 3 3 5 5 5 100 20 0 1
```

### Saída:

Após processar as instruções fornecidas no arquivo TXT, um arquivo **OFF** será gerado, representando o modelo 3D criado com os voxels, caixas, esferas e elipsoides conforme as especificações.

Essa estrutura melhorada organiza a informação de maneira mais clara, detalha cada comando e exemplo de entrada/saída, facilitando a compreensão e o uso do arquivo TXT para gerar o modelo 3D.


---

### Tabela de Comandos do Arquivo TXT

| **Comando**          | **Descrição**                                                                 | **Sintaxe**                                                          | **Parâmetros**                                                                                                                                                      | **Exemplo**                                                |
|-----------------------|------------------------------------------------------------------------------|----------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------|
| **DIM**              | Define as dimensões da matriz 3D.                                            | `DIM X Y Z`                                                          | `X`, `Y`, `Z`: Dimensões do espaço tridimensional.                                                                           | `DIM 30 30 30`                                             |
| **PUTVOXEL**         | Adiciona um voxel em uma posição específica.                                 | `PUTVOXEL X Y Z R G B A`                                             | `X`, `Y`, `Z`: Coordenadas; `R`, `G`, `B`: Cor (0 a 1); `A`: Transparência (0 a 1).                                          | `PUTVOXEL 5 5 5 1.0 0.0 0.0 1.0`                          |
| **CUTVOXEL**         | Remove um voxel em uma posição específica.                                   | `CUTVOXEL X Y Z`                                                     | `X`, `Y`, `Z`: Coordenadas.                                                                                                | `CUTVOXEL 5 5 5`                                           |
| **PUTBOX**           | Adiciona uma caixa sólida entre coordenadas iniciais e finais.               | `PUTBOX X0 Y0 Z0 X1 Y1 Z1 R G B A`                                   | `X0`, `Y0`, `Z0`: Coordenadas iniciais; `X1`, `Y1`, `Z1`: Coordenadas finais; `R`, `G`, `B`: Cor; `A`: Transparência.       | `PUTBOX 1 1 1 4 4 4 0.0 1.0 0.0 0.5`                      |
| **CUTBOX**           | Remove uma caixa de voxels entre coordenadas iniciais e finais.              | `CUTBOX X0 Y0 Z0 X1 Y1 Z1`                                           | `X0`, `Y0`, `Z0`: Coordenadas iniciais; `X1`, `Y1`, `Z1`: Coordenadas finais.                                               | `CUTBOX 1 1 1 4 4 4`                                       |
| **PUTSPHERE**        | Adiciona uma esfera com centro e raio definidos.                             | `PUTSPHERE XCENTER YCENTER ZCENTER RADIUS R G B A`                   | `XCENTER`, `YCENTER`, `ZCENTER`: Coordenadas do centro; `RADIUS`: Raio; `R`, `G`, `B`: Cor; `A`: Transparência.             | `PUTSPHERE 10 10 10 5 0.0 0.0 1.0 1.0`                    |
| **CUTSPHERE**        | Remove uma esfera de voxels com centro e raio definidos.                     | `CUTSPHERE XCENTER YCENTER ZCENTER RADIUS`                           | `XCENTER`, `YCENTER`, `ZCENTER`: Coordenadas do centro; `RADIUS`: Raio.                                                     | `CUTSPHERE 10 10 10 5`                                     |
| **PUTELLIPSOID**     | Adiciona um elipsoide com eixos e centro definidos.                          | `PUTELLIPSOID XCENTER YCENTER ZCENTER RX RY RZ R G B A`              | `XCENTER`, `YCENTER`, `ZCENTER`: Coordenadas do centro; `RX`, `RY`, `RZ`: Raios; `R`, `G`, `B`: Cor; `A`: Transparência.    | `PUTELLIPSOID 15 15 15 3 5 2 1.0 0.5 0.0 0.8`             |
| **CUTELLIPSOID**     | Remove um elipsoide de voxels com eixos e centro definidos.                  | `CUTELLIPSOID XCENTER YCENTER ZCENTER RX RY RZ`                      | `XCENTER`, `YCENTER`, `ZCENTER`: Coordenadas do centro; `RX`, `RY`, `RZ`: Raios.                                            | `CUTELLIPSOID 15 15 15 3 5 2`                              |
| **FOR_PUTVOXEL**     | Adiciona voxels iterativamente ao longo de um eixo.                         | `FOR_PUTVOXEL IT FOR_I X Y Z R G B A`                                | `IT`, `FOR_I`: Intervalo do loop; `X`, `Y`, `Z`: Coordenadas (`-1` indica eixo iterado); `R`, `G`, `B`: Cor; `A`: Transparência. | `FOR_PUTVOXEL 1 5 -1 10 10 1.0 0.0 0.0 1.0`               |
| **FOR_CUTVOXEL**     | Remove voxels iterativamente ao longo de um eixo.                           | `FOR_CUTVOXEL IT FOR_I X Y Z`                                        | `IT`, `FOR_I`: Intervalo do loop; `X`, `Y`, `Z`: Coordenadas (`-1` indica eixo iterado).                                     | `FOR_CUTVOXEL 1 5 -1 10 10`                               |
| **FOR_PUTELLIPSOID** | Adiciona elipsoides iterativamente ao longo de um eixo.                     | `FOR_PUTELLIPSOID IT FOR_I XCENTER YCENTER ZCENTER RX RY RZ R G B A` | `IT`, `FOR_I`: Intervalo do loop; `XCENTER`, `YCENTER`, `ZCENTER`: Coordenadas (`-1` indica eixo iterado); `RX`, `RY`, `RZ`: Raios; `R`, `G`, `B`: Cor; `A`: Transparência. | `FOR_PUTELLIPSOID 1 5 -1 15 15 3 5 2 1.0 0.0 1.0 0.8`     |
| **FOR_CUTELLIPSOID** | Remove elipsoides iterativamente ao longo de um eixo.                       | `FOR_CUTELLIPSOID IT FOR_I XCENTER YCENTER ZCENTER RX RY RZ`          | `IT`, `FOR_I`: Intervalo do loop; `XCENTER`, `YCENTER`, `ZCENTER`: Coordenadas (`-1` indica eixo iterado); `RX`, `RY`, `RZ`: Raios. | `FOR_CUTELLIPSOID 1 5 -1 15 15 3 5 2`                     |

## Requisitos

Certifique-se de que você tenha os seguintes itens instalados no seu ambiente:

- **Compilador C++** compatível com C++17 (ou superior).
- **CMake** (para configurar e construir o projeto).
- **Qt Creator** (opcional, para edição e execução).
- **Bibliotecas padrão do sistema de arquivos (`<filesystem>`).**

---

### Licença

Este projeto está licenciado sob a Licença MIT - consulte o arquivo [LICENSE](./LICENSE.txt) para obter mais informações.

---

### Créditos

- **Desenvolvedor**: Augusto César
  
Agradecemos a todos que contribuíram para este projeto e ajudaram a melhorar sua qualidade!


