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

/* Vector Functions */
void readRecords(string fileName, vector<Point2D*>& p2dv,
  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);

void constructObject(vector<string>& objectData, vector<Point2D*>& p2dv,
  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);

void sortThisUp(string& filterCriteria, string& sortingCriteria,
  string& sortingOrder, vector<Point2D*>& p2dv, vector<Point3D*>& p3dv,
  vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);

/* Utility Functions */
vector<string> splitByDelims(string line, string delims);

void cleanMemory(vector<Point2D*>& p2dv, vector<Point3D*>& p3dv,
  vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);

void cleanUpBrackets(string& s);

void writeToFile(string& filterCriteria, string& sortingCriteria, string& sortingOrder, vector<Point2D*>& p2dv,
  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);

/* Print Functions */
void printMenu(string fc, string sc, string so);

void printData(string& filterCriteria, string& sortingCriteria, string& sortingOrder, vector<Point2D*>& p2dv,
  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv);

/* Criteria Functions */
void specifyFilter(string& filterCriteria, string& sortingCriteria);
void specifyCriteria(string& filterCriteria, string& sortingCriteria);
void specifyOrder(string& sortingOrder);
void decideSortingCriteria(string& filterCriteria,
  string& sortingCriteria, char& criteria);
