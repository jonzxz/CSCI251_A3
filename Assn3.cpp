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
void readRecords(string fileName, vector<Point2D*>& point2DVec,
                vector<Point3D*>& point3DVec, vector<Line2D*>& line2DVec,
                vector<Line3D*>& line3DVec) {
  ifstream fileReader;
  string line;


  fileReader.open(fileName);
  while (getline(fileReader, line) && !line.empty()) {
    vector<string> objectData;
    objectData = splitByDelims(line, ", ");

    for(string s : objectData) {
      cleanUpBrackets(s);
    }
    constructObject(objectData, point2DVec, point3DVec, line2DVec, line3DVec);
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

void constructObject(vector<string> objectData) {

}
