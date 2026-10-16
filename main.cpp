#include <iostream>

int main() {
  Sculptor s(10, 10, 10); //tamanho do voxel
  s.writeOFF("coqueiro.off");
  return 0;
}
