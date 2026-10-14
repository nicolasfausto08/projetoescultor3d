#include "sculptor.h"
#include <iostream>

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
	for(int x = 0; x < nx; x++){
		for(int y = 0; y < ny; y++){
			for(int z = 0; z < nz; z++){
				int dx = x - xcenter;
				int dy = y - ycenter;
				int dz = z - zcenter;
				if((dx*dx)+(dy*dy)+(dz*dz) <= (radius*radius)){
				putVoxel(x,y,z)
        }
			}
		}
	}
}

