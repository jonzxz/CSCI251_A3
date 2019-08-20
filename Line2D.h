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
  Line2D(Point2D p1, Point2D p2);
  Line2D();
  Point2D getPt1();
  Point2D getPt2();
  void setPt1(Point2D pt1);
  void setPt2(Point2D pt2);
  double getScalarValue();
  virtual std::string toString();
};

#endif
