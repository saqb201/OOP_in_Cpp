22#include <iostream>
#include <iomanip> // Include for setprecision

using namespace std;

class Tollbooth {
private:
  int tCars;   
  double tCash;
public:
  // Constructor: Initialize total cars and cash to 0
  Tollbooth() {
    tCars = 0;
    tCash = 0.0;
  }

  // Function to handle paying cars
  void payingCars() {
    tCars++;
    tCash += 0.50;
  }

  // Function to display totals
  void display() {
    cout << "Total Cars: " << tCars << endl;
    cout << "Total Cash Collected: $" << fixed << setprecision(2) << tCash << endl;
  }

};

int main() {
  Tollbooth b1; // Create a tollbooth object

  // Simulate cars passing the toll
  int numCars;
  cout << "Enter the number of cars passing the toll to go through : ";
  cin >> numCars;

  for (int i = 0; i < numCars; i++) {
    b1.payingCars();
  }

  b1.display();

  return 0;
}