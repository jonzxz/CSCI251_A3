#ifndef POINT2D_H
#define POINT2D_H
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

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
virtual void printPoint();
static bool compareX(Point2D* pOne, Point2D* pTwo);
static bool compareY(Point2D* pOne, Point2D* pTwo);
static bool compareDist(Point2D* pOne, Point2D* pTwo);
};


#endif
