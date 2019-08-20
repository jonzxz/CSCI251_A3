#include "Point3D.h"


  Point3D::Point3D(int x, int y, int z) : Point2D(x, y) {
    this->z = z;
  }

  Point3D::Point3D() {

  }

  void Point3D:: setDistFrOrigin() {
    //this->distFrOrigin = d;
  }

  void Point3D::setZ(int z) {
    this->z = z;
  }

  int Point3D::getZ() {
    return this->z;
  }

  #ifdef POINT3D

  int main() {
    return 0;
  }

  #endif
