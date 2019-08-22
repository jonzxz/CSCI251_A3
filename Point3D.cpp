#include "Point3D.h"


  Point3D::Point3D(int x, int y, int z) : Point2D(x, y) {
    this->z = z;
  }

  Point3D::Point3D() {

  }

  void Point3D:: setDistFrOrigin() {
    this->distFrOrigin = sqrt(pow(this->getX(), 2) + (pow(this->getY(), 2)) + (pow(this->getZ(), 2)));
  }

  void Point3D::setZ(int z) {
    this->z = z;
  }

  int Point3D::getZ() {
    return this->z;
  }

  std::string Point3D::toString() {
    std::string s = "(" + std::to_string(this->getX()) + ", " + std::to_string(this->getY())
              + ", " + std::to_string(this->getZ()) + ")" + "Distance: " + std::to_string(this->getScalarValue());

    return s;
  }

  void Point3D::printPoint() {
    std::cout << std::right
    << "[" << std::setw(4) << std::to_string(this->getX())
    << ", " << std::setw(4) << std::to_string(this->getY())
    << ", " << std::setw(4) << std::to_string(this->getZ())
    << "]" <<"\t" << std::to_string(this->getScalarValue()) + "\n";
  }

  bool Point3D::compareZ(Point3D* pOne, Point3D* pTwo) {
    return pOne->getZ() < pTwo->getZ();
  }


  #ifdef POINT3D

  int main() {
    return 0;
  }

  #endif
