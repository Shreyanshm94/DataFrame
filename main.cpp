#include "DataFrame.h"
#include <iostream>

using namespace std;

int main() {
    DataFrame df;
    df.loadCSV("data.csv");

    int n;
    cout << "Enter number of rows to display: ";
    cin >> n;

    cout << "\n== First " << n << " Rows ==\n";
    df.show(n);

    cout << "\n== Mean of 'Salary' ==\n";
    cout << df.mean("Salary") << "\n";

    cout << "\n== Filter where Department == Marketing ==\n";
    DataFrame marketing = df.filter("Department", "Marketing");
    marketing.show(n);

    cout << "\n== Filter where Name == Shreyansh ==\n";
    DataFrame name = df.filter("Name", "Shreyansh");
    name.show(n);

    cout << "\n== Add a New Row (Enter -1 to skip) ==\n";
    vector<string> newRow;
    const vector<string>& cols = df.getColumns();

    for (const string& col : cols) {
        string value;
        cout << col << ": ";
        cin >> value;
        if (value == "-1") {
            cout << "Skipping row addition.\n";
            return 0;
        }
        newRow.push_back(value);
    }

    df.addRow(newRow);
    df.saveCSV("data.csv");
    cout << "New row added and saved.\n";

    return 0;
}


//  g++ main.cpp DataFrame.cpp -o main && ./main

