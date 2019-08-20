#ifndef POINT3D_H
#define POINT3D_H
#include "Point2D.h"


class Point3D : public Point2D {
protected:
  int z;
  void setDistFrOrigin() override;
public:
  Point3D(int x, int y, int z);
  Point3D();
  void setZ(int z);
  int getZ();
};

#endif
