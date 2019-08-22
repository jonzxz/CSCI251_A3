#include "Line2D.h"

Line2D::Line2D(Point2D p1, Point2D p2) {
  this->pt1 = p1;
  this->pt2 = p2;
  this->length = 0;
  this->setLength();
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
  std::string s = this->getPt1().toString() + ", " + this->getPt2().toString()
  + "Distance: " + std::to_string(this->getScalarValue());
  return s;
}

void Line2D::printPoint() {
  std::cout << std::right
  << "[" << std::setw(4) << std::to_string(this->getPt1().getX())
  << ", " << std::setw(4) << std::to_string(this->getPt1().getY()) << "]"
  << "\t[" << std::setw(4) << std::to_string(this->getPt2().getX())
  << ", " << std::setw(4) << std::to_string(this->getPt2().getY()) << "]"
  << "\t" << std::to_string(this->getScalarValue()) + "\n";
}

bool Line2D::comparePtOne(Line2D* lOne, Line2D* lTwo) {
  if (lOne->getPt1().getX() != lTwo->getPt1().getX()) {
    return lOne->getPt1().getX() < lTwo->getPt1().getX();
  }
  return lOne->getPt1().getY() < lTwo->getPt1().getY();
}

bool Line2D::comparePtTwo(Line2D* lOne, Line2D* lTwo) {
  if (lOne->getPt2().getX() != lTwo->getPt2().getX()) {
    return lOne->getPt2().getX() < lTwo->getPt2().getX();
  }
  return lOne->getPt2().getY() < lTwo->getPt2().getY();
}

bool Line2D::compareLength(Line2D* lOne, Line2D* lTwo) {
  return lOne->getScalarValue() < lTwo->getScalarValue();
}


#ifdef LINE2D

int main() {
  return 0;
}

#endif
