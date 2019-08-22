#include "Point2D.h"

Point2D::Point2D(int x, int y) {
  this->x = x;
  this->y = y;
  this->distFrOrigin = 0;
  this->setDistFrOrigin();
}

Point2D::Point2D() {
  this->x = 0;
  this->y = 0;
}

void Point2D::setDistFrOrigin() {
  this->distFrOrigin = sqrt(pow(this->x, 2) + (pow(this->y, 2)));
}

int Point2D::getX() {
  return this->x;
}

int Point2D::getY() {
  return this->y;
}

double Point2D::getScalarValue() {
  return this->distFrOrigin;
}
/*
std::string Point2D::toString() {
  std::string s = "[   " + std::to_string(this->x) + ",   "
  + std::to_string(this->y) + "]" + "   " + std::to_string(this->getScalarValue());
  return s;
}*/

void Point2D::toString() {
  cout << "[" + std::to_string(this->x) + ", " + std::to_string(this->y) + "]" + std::to_string(this->getScalarValue()) + "\n";
}

bool Point2D::compareX(Point2D* pOne, Point2D* pTwo) {
  return pOne->getX() < pTwo->getX();
}

bool Point2D::compareY(Point2D* pOne, Point2D* pTwo) {
  return pOne->getY() < pTwo->getY();
}

bool Point2D::compareDist(Point2D* pOne, Point2D* pTwo) {
  return pOne->getScalarValue() < pTwo->getScalarValue();
}
#ifdef POINT2D

int main() {
  return 0;
}

#endif
