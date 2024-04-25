#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Employee {
private:
  char* firstName;
  string lastName;
  int monthlySalary;

public:
  // Constructor with setter functionality
  Employee(const char* fName, const string& lName, int salary) {
    firstName = new char[strlen(fName) + 1];
    strcpy(firstName, fName);
    lastName = lName;
    monthlySalary = salary > 0 ? salary : 0; // Ensure positive salary
  }

  // Destructor to free dynamically allocated memory
  ~Employee() {
    delete[] firstName;
  }

  // Getter functions
  char* getFirstName() { return firstName; }
  string& getLastName() { return lastName; }
  int getMonthlySalary() { return monthlySalary; }

  // Function to calculate and return yearly salary
  int getYearlySalary() {
    return monthlySalary * 12;
  }

  // Function to apply a raise (percentage)
  void applyRaise(double raisePercent) {
    monthlySalary += (monthlySalary * raisePercent) / 100;
  }
};

int main() {
  Employee emp1("Ammar", "Khan", 8000);
  Employee emp2("Shoaib", "Akram", 6500);

  // Display initial yearly salaries
  cout << emp1.getFirstName() << " " << emp1.getLastName() << " - Yearly Salary: Rs. "
            << emp1.getYearlySalary() << endl;
  cout << emp2.getFirstName() << " " << emp2.getLastName() << " - Yearly Salary: Rs. "
            << emp2.getYearlySalary() << endl;

  // Apply 10% raise
  emp1.applyRaise(10.0);
  emp2.applyRaise(10.0);

  // Display salaries after raise
  cout << "\nAfter 10% Raise:" << endl;
  cout << emp1.getFirstName() << " " << emp1.getLastName() << " - Yearly Salary: Rs. "
            << emp1.getYearlySalary() << endl;
  cout << emp2.getFirstName() << " " << emp2.getLastName() << " - Yearly Salary: Rs. "
            << emp2.getYearlySalary() << endl;

  return 0;
}
