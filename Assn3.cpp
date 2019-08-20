#include "Assn3.h"

/*Fn Prototypes*/


int main() {
  bool isQuit = false;
  string filterCriteria= "filterCriteria";
  string sortingCriteria = "sortingCriteria";
  string sortingOrder = "sortingOrder";
  vector<Point2D*> point2DVec;
  vector<Point3D*> point3DVec;
  vector<Line2D*> line2DVec;
  vector<Line3D*> line3DVec;
  char choice;

  do {
    cout << "Student ID   : 6342218\n"
    << "Student Name : Jonathan Kerk\n"
    << "------------------------------\n"
    << "Welcome to Assn3 program!\n\n";
    printMenu(filterCriteria, sortingCriteria, sortingOrder);
    cout << "Please enter your choice: ";
    cin >> choice;

    switch (choice) {
      case '1': {
        cout << "C1\n";
        string fileName;
        cout << "Please enter filename: ";
        //cin >> fileName;
        readRecords("data.txt", point2DVec, point3DVec, line2DVec, line3DVec);
        break;
      }
      case '2':
        cout << "C2\n";
        for (Point2D* ptr : point2DVec) {
          cout << ptr->toString() << "\n";
        }

        for (Point3D* ptr : point3DVec) {
          cout << ptr->toString() << "\n";
        }

        for (Line2D* ptr : line2DVec) {
          cout << ptr->toString() << "\n";
        }

        for (Line3D* ptr : line3DVec) {
          cout << ptr->toString() << "\n";
        }
        break;
      case '3':
        cout << "C3\n";
        break;
      case '4':
        cout << "C4\n";
        break;
      case '5':
        cout << "C5\n";
        break;
      case '6':
        cout << "C6\n";
        break;
      case '7':
        cout << "C7\n";
        cleanMemory(point2DVec, point3DVec, line2DVec, line3DVec);
        isQuit = true;
        break;
      default:
        cout << "Invalid!\n";
    }

  } while (!isQuit);

  return 0;
}

void printMenu(string filterCriteria, string sortingCriteria,
  string sortingOrder) {
    cout << "1) Read in data\n"
    << "2) Specify filtering criteria (current: "<< filterCriteria << ")\n"
    << "3) Specify sorting criteria (current: " << sortingCriteria << ")\n"
    << "4) Specify sorting order(current: " << sortingOrder << ")\n"
    << "5) View data\n"
    << "6) Store data\n"
    << "7) Quit\n\n";
  }

/*
opens file
splits lines by , and returns vector
cleans up element in vector [ ]
passes vector in to construct pointer of object

*/
void readRecords(string fileName, vector<Point2D*>& p2dv,
                  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {
  ifstream fileReader;
  string line;


  fileReader.open(fileName);
  while (getline(fileReader, line) && !line.empty()) {
    vector<string> objectData;
    objectData = splitByDelims(line, ", ");

    for(string &s : objectData) {
      cleanUpBrackets(s);
    }

    constructObject(objectData, p2dv, p3dv, l2dv, l3dv);
  }
}

vector<string> splitByDelims(string line, string delims) {
  vector<string> splittedStrings;
  size_t pos = 0;
  string token;

  while ((pos = line.find(delims)) != string::npos) {
    token = line.substr(0, pos);
    splittedStrings.push_back(token);
    line.erase(0, pos + delims.length());
  }

  if (!line.empty()) {
    splittedStrings.push_back(line);
  }

  return splittedStrings;
}

void cleanUpBrackets(string& s) {
  s.erase(remove(s.begin(), s.end(), '['), s.end());
  s.erase(remove(s.begin(), s.end(), ']'), s.end());
}

void constructObject(vector<string>& objectData, vector<Point2D*>& p2dv,
                  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {
  string objectName = objectData.at(0);

  if (objectName == "Point2D") {
    int x = stoi(objectData.at(1));
    int y = stoi(objectData.at(2));
    Point2D* p2dptr = new Point2D(x, y);
    p2dv.push_back(p2dptr);

  } else if (objectName == "Point3D") {
    int x = stoi(objectData.at(1));
    int y = stoi(objectData.at(2));
    int z = stoi(objectData.at(3));
    Point3D* p3dptr = new Point3D(x, y, z);
    p3dv.push_back(p3dptr);

  } else if (objectName == "Line2D") {
    int x1 = stoi(objectData.at(1));
    int y1 = stoi(objectData.at(2));
    int x2 = stoi(objectData.at(3));
    int y2 = stoi(objectData.at(4));
    Line2D* l2dptr = new Line2D(Point2D(x1, y1), Point2D(x2, y2));
    l2dv.push_back(l2dptr);
  } else if (objectName == "Line3D") {
    int x1 = stoi(objectData.at(1));
    int y1 = stoi(objectData.at(2));
    int z1 = stoi(objectData.at(3));
    int x2 = stoi(objectData.at(4));
    int y2 = stoi(objectData.at(5));
    int z2 = stoi(objectData.at(6));
    Line3D* l3dptr = new Line3D(Point3D(x1, y1, z1), Point3D(x2, y2, z2));
    l3dv.push_back(l3dptr);
  }
}

  void cleanMemory(vector<Point2D*>& p2dv, vector<Point3D*>& p3dv,
                  vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {

    for (Point2D* p2dptr : p2dv) {
      delete p2dptr;
    }

    for (Point3D* p3dptr : p3dv) {
      delete p3dptr;
    }

    for (Line2D* l2dptr : l2dv) {
      delete l2dptr;
    }

    for (Line3D* l3dptr : l3dv) {
      delete l3dptr;
    }
  }
