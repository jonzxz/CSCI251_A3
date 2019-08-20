#include "Line2D.h"

Line2D::Line2D(Point2D p1, Point2D p2) {
  this->pt1 = p1;
  this->pt2 = p2;
}

Line2D::Line2D() {
  this->pt1 = Point2D();
  this->pt2 = Point2D();
}

void Line2D::setLength() {
  double x = pt1.getX() - pt2.getX();
  double y = pt1.getY() - pt2.getY();
  this->length = sqrt(pow(x, 2) + pow(y, 2));
}

Point2D Line2D::getPt1() {
  return this->pt1;
}

Point2D Line2D::getPt2() {
  return this->pt2;
}

void Line2D::setPt1(Point2D pt1) {
  this->pt1 = pt1;
}

void Line2D::setPt2(Point2D pt2) {
  this->pt2 = pt2;
}

double Line2D::getScalarValue() {
  return this->length;
}

std::string Line2D::toString() {
  std::string s = this->pt1.toString() + ", " + this->pt2.toString();
  return s;
}

#ifdef LINE2D

int main() {
  return 0;
}

#endif
