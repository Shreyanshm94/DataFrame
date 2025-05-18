#include "DataFrame.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

void DataFrame::loadCSV(const string& filename) {
    ifstream file(filename);
    string line;

    if (!getline(file, line)) return;

    stringstream ss(line);
    string col;
    while (getline(ss, col, ',')) {
        columns.push_back(col);
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        map<string, string> row;
        int i = 0;
        while (getline(ss, cell, ',')) {
            if (i < columns.size()) {
                row[columns[i]] = cell;
            }
            i++;
        }
        data.push_back(row);
    }
}

void DataFrame::show(int rows) {
    for (const auto& col : columns) {
        cout << setw(12) << col;
    }
    cout << "\n";

    for (int i = 0; i < min(rows, (int)data.size()); ++i) {
        for (const auto& col : columns) {
            cout << setw(12) << data[i][col];
        }
        cout << "\n";
    }
}

double DataFrame::mean(const string& columnName) {
    double sum = 0;
    int count = 0;
    for (const auto& row : data) {
        if (row.count(columnName)) {
            try {
                sum += stod(row.at(columnName));
                count++;
            } catch (...) {}
        }
    }
    return count ? sum / count : 0.0;
}

DataFrame DataFrame::filter(const string& column, const string& value) {
    DataFrame result;
    result.columns = columns;
    for (const auto& row : data) {
        if (row.at(column) == value) {
            result.data.push_back(row);
        }
    }
    return result;
}

void DataFrame::addRow(const vector<string>& row) {
    if (row.size() != columns.size()) return;
    map<string, string> newRow;
    for (size_t i = 0; i < columns.size(); ++i) {
        newRow[columns[i]] = row[i];
    }
    data.push_back(newRow);
}

void DataFrame::saveCSV(const string& filename) {
    ofstream file(filename);
    for (size_t i = 0; i < columns.size(); ++i) {
        file << columns[i];
        if (i != columns.size() - 1) file << ",";
    }
    file << "\n";

    for (const auto& row : data) {
        for (size_t i = 0; i < columns.size(); ++i) {
            file << row.at(columns[i]);
            if (i != columns.size() - 1) file << ",";
        }
        file << "\n";
    }
}

const vector<string>& DataFrame::getColumns() const {
    return columns;
}
