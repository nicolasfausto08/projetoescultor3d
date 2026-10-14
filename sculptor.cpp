#include <iostream>

using namespace std;

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
}


