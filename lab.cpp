#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//start of the program
int main() {
    char mStatus;
    float salary, tRate, tAmount;

    // Input marital status
    cout << "Enter marital status (S-single/M-married): ";
    cin >> mStatus;

    // Input validation using cin.fail
    if ((mStatus != 'S' && mStatus != 's' && mStatus != 'M' && mStatus != 'm') || cin.fail()) {
        cout << "Error: Invalid marital status\nUse 'S' (Single) or 'M' (Married) only!" << endl;
        return 0; // Exit program
    }

    // Input monthly salary
    cout << "Enter monthly salary (non-negative): ";
    cin >> salary;

    // Validate salary input using cin.fail
    if (cin.fail() || salary < 0) {
        cout << "Error: The salary must be a non-negative value only!" << endl;
        return 0; // Exit program
    }

    // if elseif conditions
    if (mStatus == 'S' || mStatus == 's') {
        if (salary > 100000) {
            tRate = 0.30;
        } else if (salary >= 50000) {
            tRate = 0.20;
        } else {
            tRate = 0.10;
        }
    } else if (mStatus == 'M' || mStatus == 'm') {
        if (salary > 100000) {
            tRate = 0.25;
        } else if (salary >= 50000) {
            tRate = 0.15;
        } else {
            tRate = 0.05;
        }
    }

    // tax calculation
    tAmount = salary * tRate;

    // Output results
    cout << fixed << setprecision(2); // Set precision for currency formatting
    cout << "\nEmployee Monthly Salary: " << salary << endl;
    cout << "Marital Status: " << ((mStatus == 'S' || mStatus == 's') ? "Single" : "Married") << endl;
    cout << "Tax Rate: " << tRate * 100 << "%" << endl;
    cout << "Salary Tax: " << tAmount << endl;

    return 0;
}