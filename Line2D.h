#ifndef LINE2D_H
#define LINE2D_H
#include "Point2D.h"

class Line2D {
private:
  Point2D pt1;
  Point2D pt2;
protected:
  double length;
  virtual void setLength();
public:
  Line2D(const Point2D p1, const Point2D p2);
  Line2D();
  Point2D getPt1() const;
  Point2D getPt2() const;
  void setPt1(Point2D pt1);
  void setPt2(Point2D pt2);
  double getScalarValue();
  virtual std::string toString();
  virtual void printPoint();
  static bool comparePtOne(Line2D* lOne, Line2D* lTwo);
  static bool comparePtTwo(Line2D* lOne, Line2D* lTwo);
  static bool compareLength(Line2D* lOne, Line2D* lTwo);
  bool operator==(const Line2D &line) const;

};

#endif
