#ifndef POINT2D_H
#define POINT2D_H
#include <cmath>
#include <string>

class Point2D {

protected:
  int x;
  int y;
  double distFrOrigin;
  virtual void setDistFrOrigin();

public:
Point2D(int x, int y);
Point2D();
int getX();
int getY();
void setX(int x);
void setY(int y);
double getScalarValue();
virtual std::string toString();

};


#endif
