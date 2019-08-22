#include "Assn3.h"

/*Fn Prototypes*/


int main() {
  bool isQuit = false;
  string filterCriteria= "None";
  string sortingCriteria = "None";
  string sortingOrder = "None";
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
        string fileName;
        cout << "Please enter filename: ";
        //cin >> fileName;
        cout << "\n";
        readRecords("data.txt", point2DVec, point3DVec, line2DVec, line3DVec);
        break;
      }
      case '2':
        specifyFilter(filterCriteria, sortingCriteria);
        break;
      case '3':
        specifyCriteria(filterCriteria, sortingCriteria);
        break;
      case '4':
        specifyOrder(sortingOrder);
        break;
      case '5':
        sortThisUp(filterCriteria, sortingCriteria, sortingOrder, point2DVec, point3DVec, line2DVec, line3DVec);
        printData(filterCriteria, sortingCriteria, sortingOrder, point2DVec, point3DVec, line2DVec, line3DVec);
        break;
      case '6':
        writeToFile(filterCriteria, sortingCriteria, sortingOrder, point2DVec, point3DVec, line2DVec, line3DVec);
        break;
      case '7':
        cout << "Clearing vectors.. No memory leaks!\n";
        cleanMemory(point2DVec, point3DVec, line2DVec, line3DVec);
        isQuit = true;
        break;
      default:
        cout << "Invalid!\n";
    }

  } while (!isQuit);

  return 0;
}



/* Vector Functions */

/*
opens file
splits lines by , and returns vector
cleans up element in vector [ ]
passes vector in to construct pointer of object
*/
void readRecords(string fileName, vector<Point2D*>& p2dv, vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {
  ifstream fileReader;
  string line;
  int count = 0;

  fileReader.open(fileName);
  while (getline(fileReader, line) && !line.empty()) {
    vector<string> objectData;
    objectData = splitByDelims(line, ", ");

    for(string &s : objectData) {
      cleanUpBrackets(s);
    }

    constructObject(objectData, p2dv, p3dv, l2dv, l3dv);
    count++;
  }

  cout << to_string(count) << " records read in successfully!\n\n"
       << "Going back to main menu...\n\n";
}

void constructObject(vector<string>& objectData, vector<Point2D*>& p2dv, vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {
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

void sortThisUp(string& filterCriteria, string& sortingCriteria, string& sortingOrder, vector<Point2D*>& p2dv, vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {
  //P2D BEGINS HERE
  //P2D X
  if (filterCriteria == "Point2D" && sortingCriteria == "x-ordinate" && sortingOrder == "ASC") {
    sort(p2dv.begin(), p2dv.end(), Point2D::compareX);
  } else if (filterCriteria == "Point2D" && sortingCriteria == "x-ordinate" && sortingOrder == "DSC") {
    sort(p2dv.rbegin(), p2dv.rend(), Point2D::compareX);
  //P2D Y
  } else if (filterCriteria == "Point2D" && sortingCriteria == "y-ordinate" && sortingOrder == "ASC") {
    sort(p2dv.begin(), p2dv.end(), Point2D::compareY);
  } else if (filterCriteria == "Point2D" && sortingCriteria == "y-ordinate" && sortingOrder == "DSC") {
    sort(p2dv.rbegin(), p2dv.rend(), Point2D::compareY);
  // P2D DIST
  } else if (filterCriteria == "Point2D" && sortingCriteria == "Distance" && sortingOrder == "ASC") {
    sort(p2dv.begin(), p2dv.end(), Point2D::compareDist);
  } else if (filterCriteria == "Point2D" && sortingCriteria == "Distance" && sortingOrder == "DSC") {
    sort(p2dv.rbegin(), p2dv.rend(), Point2D::compareDist);
    // P3D BEGINS HERE
    // P3D X
  } else if (filterCriteria == "Point3D" && sortingCriteria == "x-ordinate" && sortingOrder == "ASC") {
    sort(p3dv.begin(), p3dv.end(), Point2D::compareX);
  } else if (filterCriteria == "Point3D" && sortingCriteria == "x-ordinate" && sortingOrder == "DSC") {
    sort(p3dv.rbegin(), p3dv.rend(), Point2D::compareX);
    // P3D Y
  } else if (filterCriteria == "Point3D" && sortingCriteria == "y-ordinate" && sortingOrder == "ASC") {
    sort(p3dv.begin(), p3dv.end(), Point2D::compareY);
  } else if (filterCriteria == "Point3D" && sortingCriteria == "y-ordinate" && sortingOrder == "ASC") {
    sort(p3dv.rbegin(), p3dv.rend(), Point2D::compareY);
    // P3D DIST
  } else if (filterCriteria == "Point3D" && sortingCriteria == "Distance" && sortingOrder == "ASC") {
    sort(p3dv.begin(), p3dv.end(), Point2D::compareDist);
  } else if (filterCriteria == "Point3D" && sortingCriteria == "Distance" && sortingOrder == "DSC") {
    sort(p3dv.rbegin(), p3dv.rend(), Point2D::compareDist);
    // P3D Z
  } else if (filterCriteria == "Point3D" && sortingCriteria == "z-ordinate" && sortingOrder == "ASC") {
    sort(p3dv.begin(), p3dv.end(), Point3D::compareZ);
  } else if (filterCriteria == "Point3D" && sortingCriteria == "z-ordinate" && sortingOrder == "DSC") {
    sort(p3dv.rbegin(), p3dv.rend(), Point3D::compareZ);
    // L2D BEGINS HERE
    // PT. 1
  } else if (filterCriteria == "Line2D" && sortingCriteria == "Pt. 1" && sortingOrder == "ASC") {
    sort(l2dv.begin(), l2dv.end(), Line2D::comparePtOne);
  } else if (filterCriteria == "Line2D" && sortingCriteria == "Pt. 1" && sortingOrder == "DSC") {
    sort(l2dv.rbegin(), l2dv.rend(), Line2D::comparePtOne);
    // PT. 2
  } else if (filterCriteria == "Line2D" && sortingCriteria == "Pt. 2" && sortingOrder == "ASC") {
    sort(l2dv.begin(), l2dv.end(), Line2D::comparePtTwo);
  } else if (filterCriteria == "Line2D" && sortingCriteria == "Pt. 2" && sortingOrder == "DSC") {
    sort(l2dv.rbegin(), l2dv.rend(), Line2D::comparePtTwo);
    // LENGTH
  } else if (filterCriteria == "Line2D" && sortingCriteria == "Length" && sortingOrder == "ASC") {
    sort(l2dv.begin(), l2dv.end(), Line2D::compareLength);
  } else if (filterCriteria == "Line2D" && sortingCriteria == "Length" && sortingOrder == "DSC") {
    sort(l2dv.rbegin(), l2dv.rend(), Line2D::compareLength);
    // L3D BEGINS HERE
    // PT. 1
  } else if (filterCriteria == "Line3D" && sortingCriteria == "Pt. 1" && sortingOrder == "ASC") {
    sort(l3dv.begin(), l3dv.end(), Line3D::comparePtOne);
  } else if (filterCriteria == "Line3D" && sortingCriteria == "Pt. 1" && sortingOrder == "DSC") {
    sort(l3dv.rbegin(), l3dv.rend(), Line3D::comparePtOne);
    // PT. 2
  } else if (filterCriteria == "Line3D" && sortingCriteria == "Pt. 2" && sortingOrder == "ASC") {
    sort(l3dv.begin(), l3dv.end(), Line3D::comparePtTwo);
  } else if (filterCriteria == "Line3D" && sortingCriteria == "Pt. 2" && sortingOrder == "DSC") {
    sort(l3dv.rbegin(), l3dv.rend(), Line3D::comparePtTwo);
    // LENGTH
  } else if (filterCriteria == "Line3D" && sortingCriteria == "Length" && sortingOrder == "ASC") {
    sort(l3dv.begin(), l3dv.end(), Line2D::compareLength);
  } else if (filterCriteria == "Line3D" && sortingCriteria == "Length" && sortingOrder == "DSC") {
    sort(l3dv.rbegin(), l3dv.rend(), Line2D::compareLength);
  }
}

/*----------------------------------------------------------------------------*/

/* Utility Functions */
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

void cleanMemory(vector<Point2D*>& p2dv, vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {
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

void writeToFile(string& filterCriteria, string& sortingCriteria, string& sortingOrder, vector<Point2D*>& p2dv,
  vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {

  string fileName;
  cout << "Please enter filename: ";
  cin >> fileName;

  ofstream fileWriter(fileName);
  ofstream::trunc;

  // saves output buffer of cout and redirect it into file
  streambuf* strm_buffer = cout.rdbuf();
  cout.rdbuf(fileWriter.rdbuf());
  printData(filterCriteria, sortingCriteria, sortingOrder, p2dv, p3dv, l2dv, l3dv);
  cout.rdbuf(strm_buffer);
}
/*----------------------------------------------------------------------------*/

/* Print Functions */
void printData(string& filterCriteria, string& sortingCriteria, string& sortingOrder, vector<Point2D*>& p2dv, vector<Point3D*>& p3dv, vector<Line2D*>& l2dv, vector<Line3D*>& l3dv) {
  int count = 0;
  cout << "[View data ...]\n"
  << "filtering criteria: " << filterCriteria
  << "\nsorting criteria: " << sortingCriteria
  << "\nsorting order: " << sortingOrder
  << "\n\n";

  if (filterCriteria == "None" || sortingCriteria == "None" || sortingOrder == "None") {
    cout << "Please select all criterias, going back to main menu...";
  } else {
    if (filterCriteria == "Point2D") {
      cout
      << setw(5) << right << "X"
      << setw(6)  << "Y"
      << setw(5)  << "\tDist. Fr Origin\n"
      << "------------------------------------------------\n";
      for (Point2D* ptr : p2dv) {
        ptr->printPoint();
        count++;
      }

    } else if (filterCriteria == "Point3D") {
      cout
      << setw(5) << right << "X"
      << setw(6)  << "Y"
      << setw(6) << "Z"
      << setw(5)  << "\tDist. Fr Origin\n"
      << "------------------------------------------------\n";
      for (Point3D* ptr : p3dv) {
        ptr->printPoint();
        count++;
      }

    } else if (filterCriteria == "Line2D") {
      cout << setw(5) << right << "P1-X"
      << setw(6) << "P1-Y"
      << setw(10) << "P2-X"
      << setw(6) << "P2-Y"
      << setw(6) << "\tLength\n"
      << "----------------------------------------------\n";
      for (Line2D* ptr : l2dv) {
        ptr -> printPoint();
        count++;
      }

    } else {
      cout << setw(5) << right << "P1-X"
      << setw(6) << "P1-Y"
      << setw(6) << "P1-Z"
      << setw(12) << "P2-X"
      << setw(6) << "P2-Y"
      << setw(6) << "P2-Z"
      << setw(6) << "\tLength\n"
      << "--------------------------------------------------------------------\n";
      for (Line3D* ptr : l3dv) {
        ptr -> printPoint();
        count++;
      }
    }
    cout << "\n" << to_string(count) << " records printed!";
  }
  cout << "\n\n";
}

void printMenu(string filterCriteria, string sortingCriteria, string sortingOrder) {
    cout << "1) Read in data\n"
    << "2) Specify filtering criteria (current: "<< filterCriteria << ")\n"
    << "3) Specify sorting criteria (current: " << sortingCriteria << ")\n"
    << "4) Specify sorting order(current: " << sortingOrder << ")\n"
    << "5) View data\n"
    << "6) Store data\n"
    << "7) Quit\n\n";
  }

/*----------------------------------------------------------------------------*/

/* Criteria Functions */

void specifyFilter(string& filterCriteria, string& sortingCriteria) {
  char criteria;
  bool isValid = false;
  cout << "[Specifying filtering criteria (current: " << filterCriteria << ")]\n\n"
       << "a) Point2D records\n"
       << "b) Point3D records\n"
       << "c) Line2D records\n"
       << "d) Line3D records\n\n";
  cout << "Please enter your criteria (a-d): ";
  cin >> criteria;
  cout << endl;

  if (criteria == 'a') {
    filterCriteria = "Point2D";
    sortingCriteria = "x-ordinate";
    isValid = true;
  } else if (criteria == 'b') {
    filterCriteria = "Point3D";
    sortingCriteria = "x-ordinate";
    isValid = true;
  } else if (criteria == 'c') {
    filterCriteria = "Line2D";
    sortingCriteria = "Pt. 1";
    isValid = true;
  } else if (criteria == 'd') {
    filterCriteria = "Line3D";
    sortingCriteria = "Pt. 1";
    isValid = true;
  }
  if (isValid) {
  cout << "Filter criteria successfully set to '" << filterCriteria << "'!\n"
       << "Also setting default sorting criteria to '" << sortingCriteria << "'!\n\n";

  } else {
  cout << "Invalid choice!\n\n"
       << "Going back to main menu...\n\n";

  }
}

void specifyCriteria(string& filterCriteria, string& sortingCriteria) {
  cout << "[Specifying sorting criteria (current: " << sortingCriteria << ")]\n\n";
  char criteria;
  bool isValid = false;
  if (filterCriteria == "Point2D") {
    cout << "a) X-ordinate value\n"
         << "b) Y-ordinate value\n"
         << "c) Dist. Fr Origin value\n";
  } else if (filterCriteria == "Point3D") {
    cout << "a) X-ordinate value\n"
         << "b) Y-ordinate value\n"
         << "c) Z-ordinate value\n"
         << "d) Dist. Fr Origin value\n";
  } else if (filterCriteria == "None") {
    cout << "No filter selected, please select a filter!\n\n";
  } else {
    cout << "a) X and Y coordinates values of Pt. 1\n"
         << "b) X and Y coordinates values of Pt. 2\n"
         << "c) Length value\n";
  }

  if (filterCriteria != "None") {
    if (filterCriteria != "Point3D") {
      cout << "Please enter your criteria (a-c): ";
    } else {
      cout << "Please enter your criteria (a-d): ";
    }
    cin >> criteria;
  }


  if (criteria == 'a' || criteria == 'b' || criteria == 'c' || criteria == 'd') {
    if (!(filterCriteria == "Point3D") && criteria == 'd') {
      cout << "\nInvalid, only select a-c!\n\n";
      cout << "Going back to main menu..\n\n";
    }
    decideSortingCriteria(filterCriteria, sortingCriteria, criteria);
  } else {
    cout << "\nInvalid!\n"
         << "Going back to main menu...\n\n";
  }

}

void specifyOrder(string& sortingOrder) {
  char choice;
  cout << "[Specifying sorting order (current: " << sortingOrder << ")]\n\n"
       << "a) ASC (Ascending order)\n"
       << "b) DSC (Descending order)\n\n"
       << "Please enter your criteria (a - b): ";
  cin >> choice;
  cout << endl;
  if (choice == 'a') {
    sortingOrder = "ASC";
    cout << "Sorting order successfully set to '" << sortingOrder << "'!\n\n";
  } else if (choice == 'b') {
    sortingOrder = "DSC";
    cout << "Sorting order successfully set to '" << sortingOrder << "'!\n\n";
  } else {
    cout << "Invalid!\n\n";
  }
}

void decideSortingCriteria(string& filterCriteria, string& sortingCriteria, char& criteria) {
  if (criteria == 'a') {
      if (filterCriteria == "Point2D" || filterCriteria == "Point3D") {
        sortingCriteria = "x-ordinate";
      } else {
        sortingCriteria = "Pt. 1";
      }
  } else if (criteria == 'b') {
    if (filterCriteria == "Point2D" || filterCriteria == "Point3D") {
      sortingCriteria = "y-ordinate";
    } else {
      sortingCriteria = "Pt. 2";
    }
  } else if (criteria == 'c') {
    if (filterCriteria == "Point2D") {
      sortingCriteria = "Distance";
    } else if (filterCriteria == "Point3D") {
      sortingCriteria = "z-ordinate";
    } else {
      sortingCriteria = "Length";
    }
  } else {
    sortingCriteria = "Distance";
  }

  cout << "\nSorting criteria successfully set to '" << sortingCriteria << "'!\n\n";
}

/*----------------------------------------------------------------------------*/
