#include "Line3D.h"

Line3D::Line3D(Point3D pt1, Point3D pt2) : Line2D() {
  this->pt1 = pt1;
  this->pt2 = pt2;
}

void Line3D::setLength() {
  double x = pt1.getX() - pt2.getX();
  double y = pt1.getY() - pt2.getY();
  double z = pt1.getZ() - pt2.getZ();
  this->length = sqrt((pow(x, 2)) + (pow(y, 2)) + (pow(z, 2)));
}

Point3D Line3D::getPt1() {
  return this->pt1;
}

Point3D Line3D::getPt2() {
  return this->pt2;
}

void Line3D::setPt1(Point3D pt1) {
  this->pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2) {
  this->pt2 = pt2;
}

#ifdef LINE3D

int main() {
  return 0;
}

#endif
