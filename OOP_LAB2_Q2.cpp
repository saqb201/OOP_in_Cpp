
#include <iostream>
#include <limits> // for error handling

using namespace std;

class Bank {
public:
  Bank(double init_balance = 0.0) {
    balance = init_balance;
    num_transac = 0;
  }

  void deposit(double amount) {
    if (amount < 0) {
      cout << "Deposit amount cannot be negative." << endl;
      return;
    }
    balance += amount;
    num_transac++;
  }

  void withdraw(double amount) {
    if (amount < 0) {
      cout << "Withdrawal amount cannot be negative." << endl;
      return;
    }
    if (amount > balance) {
      cout << "Insufficient funds." << endl;
      return;
    }
    balance -= amount;
    num_transac++;
  }

  double get_balance() const {
    return balance;
  }

  int get_num_transactions() const {
    return num_transac;
  }

  void displayMenu() {
    cout << "\n**** Bank Account Menu ****" << endl;
    cout << "1. Display Balance" << endl;
    cout << "2. Display Number of Transactions" << endl;
    // Interest is not calculated in this basic class
    // cout << "3. Display Interest Earned (not implemented)" << endl;
    cout << "3. Make a Deposit" << endl;
    cout << "4. Make a Withdrawal" << endl;
    cout << "5. Exit" << endl;
  }

  void handleUserChoice() {
    int choice;
    double amount;

    do {
      displayMenu();
      cout << "Enter your choice: ";

      // Input validation to handle non-numeric characters
      if (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number." << endl;
        // Clear the error state from cin
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }

      switch (choice) {
        case 1:
          cout << "Account Balance: $" << get_balance() << endl;
          break;
        case 2:
          cout << "Number of Transactions: " << get_num_transactions() << endl;
          break;
        case 3:
          cout << "Enter amount to deposit: ";
          if (!(cin >> amount)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
          }
          deposit(amount);
          break;
        case 4:
          cout << "Enter amount to withdraw: ";
          if (!(cin >> amount)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
          }
          withdraw(amount);
          break;
        case 5:
          cout << "Exiting program." << endl;
          break;
        default:
          cout << "Invalid choice." << endl;
      }
    } while (choice != 5);
  }

private:
  double balance;
  int num_transac;
};

int main() {
  Bank account;
  account.handleUserChoice();
  return 0;
}


// #include <iostream>
// using namespace std;
//     class bank {
//         double balance;
//         double amount;
//         double transact_amount;
//         int num_of_trans;
//         char order;

//         public:
//             void amount(){
//                 cout <<""
//             }
//             void input_amount(){
//                 cout<<"Enter the amount you want to dseposite/withdraw from your account - "<<endl;
//                 cin>>amount;
//             }
//             void deposite_amount(){
//                 balance  = balance + amount;
//                 cout<<"Successfully Deposite"<<endl;
//                 cout<<"Amount  you deposite is - "<<amount<<endl;

//             }
//             void afterwithdraw_amount(){
//                 balance  = balance - amount;
//                 num_of_trans++;
//                 cout<<"Successfully Withdraw "<<endl;
//                 cout<<"Amount you withdraw is - "<<amount<<endl;
//             }
//             void aftersave_account(){
//                 cout<<"Your amount has now become "<<balance<<endl;
//             }
//             void report_currentaccount (){
//                 cout<<"YOUR ACCOUNT HAS BEEN REPOTEED "<<endl;
//             }
//             void transactions(){
//                 cout<<"Number of Transactions - "<<num_of_trans<<endl;
//             }
//             void report_NumOfTransactions(){
//                 cout<<"Number Of Transactions Has Been Reported "<<endl;

//             }
//             void report_account (){
//                     cout<<"If you want to report the account press[R]or[r] either press [A]or[a] "<<endl;
//                     cin>>order;
//                 }


// };
// int main(){
//     bank b1;
//     char key;
//     cout<<"you want to deposit/withdraw the amount from your account "<<endl<<"1. [D]or[d] for deposite 2. [W]or[w] for withdraw "<<endl;
//     cin>>key;
//     if(key=='D'||key=='d'){
//         b1.input_amount();
//         b1.deposite_amount();
//         b1.aftersave_account();
//         b1.report_currentaccount();
//     }

// }


// #include <iostream>

// class BankAccount {
// //   cout <<"This class represents a bank account with basic functionalities."<<endl;
// public:
//   BankAccount(double initial_balance = 0.0) {
//     balance = initial_balance;
//     num_transactions = 0;
//   }

//   void deposit(double amount) {
//     if (amount < 0) {
//       std::cout << "Deposit amount cannot be negative." << std::endl;
//       return;
//     }
//     balance += amount;
//     num_transactions++;
//   }

//   void withdraw(double amount) {
//     if (amount < 0) {
//       std::cout << "Withdrawal amount cannot be negative." << std::endl;
//       return;
//     }
//     if (amount > balance) {
//       std::cout << "Insufficient funds." << std::endl;
//       return;
//     }
//     balance -= amount;
//     num_transactions++;
//   }

//   double get_balance() const {
//     return balance;
//   }

//   int get_num_transactions() const {
//     return num_transactions;
//   }

// private:
//   double balance;
//   int num_transactions;
// };

// int main() {
//   BankAccount account;

//   int choice;
//   double amount;

//   while (choice != 5); {
//     std::cout << "\n**** Bank Account Menu ****" << std::endl;
//     std::cout << "1. Display Balance" << std::endl;
//     std::cout << "2. Display Number of Transactions" << std::endl;
//     // Interest is not calculated in this basic class
//     // std::cout << "3. Display Interest Earned (not implemented)" << std::endl;
//     std::cout << "3. Make a Deposit" << std::endl;
//     std::cout << "4. Make a Withdrawal" << std::endl;
//     std::cout << "5. Exit" << std::endl;
//     std::cout << "Enter your choice: ";
//     std::cin >> choice;

//     switch (choice) {
//       case 1:
//         std::cout << "Account Balance: $" << account.get_balance() << std::endl;
//         break;
//       case 2:
//         std::cout << "Number of Transactions: " << account.get_num_transactions() << std::endl;
//         break;
//       case 3:
//         std::cout << "Enter amount to deposit: ";
//         std::cin >> amount;
//         account.deposit(amount);
//         break;
//       case 4:
//         std::cout << "Enter amount to withdraw: ";
//         std::cin >> amount;
//         account.withdraw(amount);
//         break;
//       case 5:
//         std::cout << "Exiting program." << std::endl;
//         break;
//       default:
//         std::cout << "Invalid choice." << std::endl;
//     }
//   } 

//   return 0;
// }