#include "Point3D.h"


  Point3D::Point3D(int x, int y, int z) : Point2D(x, y) {
    this->z = z;
  }

  Point3D::Point3D() {

  }

  void Point3D:: setDistFrOrigin() {
    this->distFrOrigin = sqrt(pow(this->x, 2) + (pow(this->y, 2)) + (pow(this->z, 2)));
  }

  void Point3D::setZ(int z) {
    this->z = z;
  }

  int Point3D::getZ() {
    return this->z;
  }

  std::string Point3D::toString() {
    std::string s = "(" + std::to_string(this->x) + ", " + std::to_string(this->y)
              + ", " + std::to_string(this->z) + ")" + "Distance: " + std::to_string(this->getScalarValue());

    return s;
  }

  bool Point3D::compareZ(Point3D* pOne, Point3D* pTwo) {
    return pOne->getZ() < pTwo->getZ();
  }


  #ifdef POINT3D

  int main() {
    return 0;
  }

  #endif
