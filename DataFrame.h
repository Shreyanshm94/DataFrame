#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <vector>
#include <string>
#include <map>

using namespace std;

class DataFrame {
private:
    vector<string> columns;
    vector<map<string, string>> data;

public:
    void loadCSV(const string& filename);
    void show(int rows);
    double mean(const string& columnName);
    DataFrame filter(const string& column, const string& value);
    void addRow(const vector<string>& row);
    void saveCSV(const string& filename);
    const vector<string>& getColumns() const;
};

#endif
