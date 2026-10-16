#include <iostream>
#include "sculptor.h"
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

//Construtor
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny; 
    nz = _nz;
    r = g = b = a = 1.0 //cor padrão branca

    v = new Voxel**[nx];
    for(int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
        for(int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
            for(int k = 0; k < nz; k++){
                v[i][j][k].show = false;
                v[i][j][k].r = 0.0;
                v[i][j][k].g = 0.0;
                v[i][j][k].b = 0.0;
            }   
        }
    }    
}

//Destrutor
Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }    
    delete[] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Sculptor::putVoxel(int x, int y, int z){
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
        v[x][y][z] = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
        v[x][y][z] = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int x = x0; x <= x1; x++){
        for(int y = y0; y <= y1; y++){
            for(int z = z0; z <= z1; z++){
                putVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int x = x0; x <= x1; x++){
        for(int y = y0; y <= y1; y++){
            for(int z = z0; z <= z1; z++){
                cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int r2 = radius * radius;
    for(int x = xcenter - radius; x <= xcenter + radius; x++){
        for(int y = ycenter - radius; y <= ycenter + radius; y++){
            for(int z = zcenter - radius; z <= zcenter + radius; z++){
                int dist2 = (x-xcenter)*(x-xcenter) +
                            (y-ycenter)*(y-ycenter) +
                            (z-zcenter)*(z-zcenter)
                if(dist2 < r2){
                    putVoxel(x, y, z);
                }
             }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int r2 = radius * radius;
    for(int x = xcenter - radius; x <= xcenter + radius; x++){
        for(int y = ycenter - radius; y <= ycenter + radius; y++){
            for(int z = zcenter - radius; z <= zcenter + radius; z++){
                int dist2 = (x-xcenter)*(x-xcenter) +
                            (y-ycenter)*(y-ycenter) +
                            (z-zcenter)*(z-zcenter);
                if(dist2 < r2){
                    cutVoxel(x, y, z);
                }
             }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int x = xcenter - rx; x <= xcenter + rx; x++){
        for(int y = ycenter - ry; y <= ycenter + ry; y++){
            for(int z = zcenter - rz; z <= zcenter + rz; z++){
                double termoX = (double) ((x-xcenter)*(x-xcenter))/(rx*rx);
                double termoY = (double) ((y-ycenter)*(y-ycenter))/(ry*ry);
                double termoZ = (double) ((z-zcenter)*(z-zcenter))/(rz*rz);

                if(termoX + termoY + termoZ <= 1.0){
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int x = xcenter - rx; x <= xcenter + rx; x++){
        for(int y = ycenter - ry; y <= ycenter + ry; y++){
            for(int z = zcenter - rz; z <= zcenter + rz; z++){
                double termoX = (double) ((x-xcenter)*(x-xcenter))/(rx*rx);
                double termoY = (double) ((y-ycenter)*(y-ycenter))/(ry*ry);
                double termoZ = (double) ((z-zcenter)*(z-zcenter))/(rz*rz);

                if(termoX + termoY + termoZ <= 1.0){
                    cutVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename){
    std::ofstream fout(filename);

    int totalVoxels = 0;
    for(int x = 0; x < nx; x++){
        for(int y = 0; y < ny; y++){
            for(int z = 0; z < nz; z++){
                if(v[x][y][z].show){
                    totalVoxels++;
                }
            }
        }
    }
    int totalVertices = totalVoxels * 8;
    int totalFaces = totalVoxels * 6;

    fout << "OFF\n";
    fout << totalVertices << " " << totalFaces << " 0\n";

    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    fout << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << "\n";
                    fout << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << "\n";
                    fout << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << "\n";
                    fout << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << "\n";
                    fout << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << "\n";
                    fout << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << "\n";
                    fout << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << "\n";
                    fout << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << "\n";
                }
            }
        }
    }
    int voxelIndex = 0;
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    int k = voxelIndex * 8;
                    fout << "4 " << k + 0 << " " << k + 3 << " " << k + 2 << " " << k + 1 << " "
                         << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    fout << "4 " << k + 4 << " " << k + 5 << " " << k + 6 << " " << k + 7 << " "
                         << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    fout << "4 " << k + 0 << " " << k + 1 << " " << k + 5 << " " << k + 4 << " "
                         << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    fout << "4 " << k + 0 << " " << k + 4 << " " << k + 7 << " " << k + 3 << " "
                         << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    fout << "4 " << k + 3 << " " << k + 7 << " " << k + 6 << " " << k + 2 << " "
                         << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    fout << "4 " << k + 1 << " " << k + 2 << " " << k + 6 << " " << k + 5 << " "
                         << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
                    voxelIndex++;
                }
            }
        }
    }
    fout.close();
}


