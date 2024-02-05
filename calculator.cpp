#include <iostream>
using namespace std;

int main() {
    float num1, num2, result;
    int operation;
    char choice = '\0';
    bool error = false;

    do {
        error = false;

        cout << "Choose an operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Quit" << endl;
        cin >> operation;

        if (operation < 1 || operation > 5) {
            cout << "Error: Invalid operation." << endl;
            error = true;
        } else {
            if (operation != 5) {
                cout << "Enter the first number: ";
                cin >> num1;
                cout << "Enter the second number: ";
                cin >> num2;

                switch (operation) {
                    case 1:
                        result = num1 + num2;
                        break;
                    case 2:
                        result = num1 - num2;
                        break;
                    case 3:
                        result = num1 * num2;
                        break;
                    case 4:
                        if (num2 != 0) {
                            result = num1 / num2;
                        } else {
                            cout << "Error: Cannot divide by zero." << endl;
                            error = true;
                        }
                        break;
                }

                if (!error) {
                    cout << num1 << " " << (operation == 1 ? '+' : operation == 2 ? '-' : operation == 3 ? '*' : '/') << " " << num2 << " = " << result << endl;
                }
            }
        }

        if (operation == 5) {
            cout << "Goodbye!" << endl;
        } else if (!error) {
            cout << "Do you want to perform another calculation? (y/n): ";
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}