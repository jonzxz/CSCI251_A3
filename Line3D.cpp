#include "Line3D.h"

Line3D::Line3D(const Point3D pt1, const Point3D pt2) : Line2D() {
  this->pt1 = pt1;
  this->pt2 = pt2;
  this->length = 0;
  this->setLength();
}

Line3D::Line3D() {
  this->pt1 = Point3D();
  this->pt2 = Point3D();
}

void Line3D::setLength() {
  double x = pt1.getX() - pt2.getX();
  double y = pt1.getY() - pt2.getY();
  double z = pt1.getZ() - pt2.getZ();
  this->length = sqrt((pow(x, 2)) + (pow(y, 2)) + (pow(z, 2)));
}

Point3D Line3D::getPt1() const {
  return this->pt1;
}

Point3D Line3D::getPt2() const {
  return this->pt2;
}

void Line3D::setPt1(Point3D pt1) {
  this->pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2) {
  this->pt2 = pt2;
}

std::string Line3D::toString() {
  std::string s = this->getPt1().toString() + ", " + this->getPt2().toString()
  + "Distance: " + std::to_string(this->getScalarValue());
  return s;
}

void Line3D::printPoint() {
  std::cout << std::right
  <<"[" << std::setw(4) << std::to_string(this->getPt1().getX())
  << ", " << std::setw(4) << std::to_string(this->getPt1().getY())
  << ", " << std::setw(4) << std::to_string(this->getPt1().getZ())<< "]"
  << "\t[" << std::setw(4) << std::to_string(this->getPt2().getX())
  << ", " << std::setw(4) << std::to_string(this->getPt2().getY())
  << ", " << std::setw(4) << std::to_string(this->getPt2().getZ()) << "]"
  << "\t" << std::to_string(this->getScalarValue()) + "\n";
}

bool Line3D::comparePtOne(Line3D* lOne, Line3D* lTwo) {
  if (lOne->getPt1().getX() != lTwo->getPt1().getX()) {
    return lOne->getPt1().getX() < lTwo->getPt1().getX();
  }
  return lOne->getPt1().getY() < lTwo->getPt1().getY();
}

bool Line3D::comparePtTwo(Line3D* lOne, Line3D* lTwo) {
  if (lOne->getPt2().getX() != lTwo->getPt2().getX()) {
    return lOne->getPt2().getX() < lTwo->getPt2().getX();
  }
  return lOne->getPt2().getY() < lTwo->getPt2().getY();
}

bool Line3D::operator==(const Line3D &line) const {
  return this->getPt1() == line.getPt1() && this->getPt2() == line.getPt2();
}

#ifdef LINE3D

int main() {
  return 0;
}

#endif
