DataFrame C++ Library
A lightweight C++ DataFrame library for handling tabular data from CSV files.
Inspired by Python’s pandas, this project provides essential data manipulation and analysis capabilities directly in C++.

Features

Load CSV data with headers into an in-memory DataFrame.
Display a user-defined number of rows.
Calculate basic statistics such as mean for numeric columns.
Filter rows based on column values.
Add new rows dynamically to the DataFrame.
Save updated data back to CSV files.
Motivation

This project aims to provide a simple, yet functional DataFrame implementation in C++ for educational purposes and small data processing tasks, bridging the gap between fast C++ execution and convenient tabular data handling.

Usage

Load your CSV file into the DataFrame.
View and analyze your data using functions like show(), mean(), and filter().
Add new rows with addRow() and save updates back to disk with saveCSV().
Example

DataFrame df;
df.loadCSV("data.csv");

df.show(10);
cout << "Mean Salary: " << df.mean("Salary") << endl;

auto engineering = df.filter("Department", "Engineering");
engineering.show();

vector<string> newRow = {"Ananya", "29", "HR", "58000"};
df.addRow(newRow);
df.saveCSV("data.csv");


Requirements

C++11 or higher
Standard C++ library only (no external dependencies)
Future Improvements

Support for more statistical operations.
Column type detection (numeric, categorical).
More flexible filtering options.
Support for writing and reading other file formats.
