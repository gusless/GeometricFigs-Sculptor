#include "sculptor.h"
#include <iostream>
#include <fstream>
#include "voxel.h"

Sculptor::Sculptor(int nx, int ny, int nz) {
    this->nx = nx;
    this->ny = ny;
    this->nz = nz;


    v = new Voxel **[nx];
    v[0] = new Voxel *[nx*ny];
    v[0][0] = new Voxel [nx*ny*nz];

    for(int i = 1; i < nx; i++){
        v[i] = v[i - 1] + ny;
    }
    for(int i = 1; i < nx * ny; i++){
        v[0][i] = v[0][i - 1] + nz;
    }
    for(int i = 0; i < nx * ny * nz; i++){
        v[0][0][i].show = false;
    }
}

Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

int Sculptor::getX(){
    return nx;
}

int Sculptor::getY(){
    return ny;
}

int Sculptor::getZ(){
    return nz;
}

void Sculptor::setColor(float r, float g, float b, float a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z){
    if((x<nx && x>=0) && (y<ny && y>=0) && (z<nz && z>=0)){
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
        v[x][y][z].show = true;
    }else{
        std::cout<< "O voxel nao foi posicionado no comando putVoxel("
                  << x << ", " << y << ", " << z
                  << "), digite coordenadas que estejam dentro da matriz ("
                  << nx << ", " << ny << ", " << nz << ")" << std::endl;
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    if((x<nx && x>=0) && (y<ny && y>=0) && (z<nz && z>=0)){
        v[x][y][z].r = 0;
        v[x][y][z].g = 0;
        v[x][y][z].b = 0;
        v[x][y][z].a = a;
        v[x][y][z].show = false;
    }else{
        std::cout<< "O voxel nao foi apagado no comando cutVoxel("
                  << x << ", " << y << ", " << z
                  << "), digite coordenadas que estejam dentro da matriz ("
                  << nx << ", " << ny << ", " << nz << ")" << std::endl;
    }
}

void Sculptor::writeOFF(const char* filename){
    std::ofstream file;
    std::string path = "../../" + std::string(filename);

    file.open(path);

    if(!file.is_open()){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        std::cin.get();
        exit(1);
    }

    file << "OFF" << std::endl;

    int voxels = 0, val = 0;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show == true){
                    voxels++;
                }
            }
        }
    }

    file << voxels*8 << " " << voxels*6 << " " << 0 << std::endl;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show == true){
                    file << -0.5 + i << " " <<  0.5 + j << " " << -0.5 + k << std::endl;
                    file << -0.5 + i << " " << -0.5 + j << " " << -0.5 + k << std::endl;
                    file <<  0.5 + i << " " << -0.5 + j << " " << -0.5 + k << std::endl;
                    file <<  0.5 + i << " " <<  0.5 + j << " " << -0.5 + k << std::endl;
                    file << -0.5 + i << " " <<  0.5 + j << " " <<  0.5 + k << std::endl;
                    file << -0.5 + i << " " << -0.5 + j << " " <<  0.5 + k << std::endl;
                    file <<  0.5 + i << " " << -0.5 + j << " " <<  0.5 + k << std::endl;
                    file <<  0.5 + i << " " <<  0.5 + j << " " <<  0.5 + k << std::endl;
                }
            }
        }
    }

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show == true){
                    file << 4 << " " << 0 + val << " " << 3 + val  << " " << 2 + val <<  " " << 1 + val << " " <<
                        v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    file << 4 << " " << 4 + val << " " << 5 + val  << " " << 6 + val <<  " " << 7 + val << " " <<
                        v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    file << 4 << " " << 0 + val << " " << 1 + val  << " " << 5 + val <<  " " << 4 + val << " " <<
                        v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    file << 4 << " " << 0 + val << " " << 4 + val  << " " << 7 + val <<  " " << 3 + val << " " <<
                        v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    file << 4 << " " << 3 + val << " " << 7 + val  << " " << 6 + val <<  " " << 2 + val << " " <<
                        v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    file << 4 << " " << 1 + val << " " << 2 + val  << " " << 6 + val <<  " " << 5 + val << " " <<
                        v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a <<std::endl;
                    val+=8;
                }
            }
        }
    }

    file.close();
}
