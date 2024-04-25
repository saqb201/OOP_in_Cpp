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