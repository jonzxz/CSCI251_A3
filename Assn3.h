#define ASSN3_H
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void printMenu(string fc, string sc, string so);
void readRecords(string fileName, vector<Point2D*>& p2dv,
                  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);
vector<string> splitByDelims(string line, string delims);
void cleanUpBrackets(string& s);
void constructObject(vector<string>& objectData, vector<Point2D*>& p2dv,
                  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);
void cleanMemory(vector<Point2D*>& p2dv, vector<Point3D*>& p3dv,
                vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);
