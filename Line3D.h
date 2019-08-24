#ifndef LINE3D_H
#define LINE3D_H
#include "Point3D.h"
#include "Line2D.h"

class Line3D : public Line2D {
private:
  Point3D pt1;
  Point3D pt2;

protected:
  void setLength() override;

public:
  Line3D(const Point3D pt1, const Point3D pt2);
  Line3D();
  Point3D getPt1() const;
  Point3D getPt2() const;
  void setPt1(Point3D pt1);
  void setPt2(Point3D pt2);
  std::string toString() override;
  void printPoint() override;
  static bool comparePtOne(Line3D* lOne, Line3D* lTwo);
  static bool comparePtTwo(Line3D* lOne, Line3D* lTwo);
  bool operator==(const Line3D &line) const;
};


#endif
