# C++ DataFrame Library

A lightweight DataFrame-like library implemented in C++ for basic data analysis and CSV manipulation.

## 🚀 Features

- Load and parse `.csv` files
- Display `n` number of rows from the dataset
- Compute the mean of numerical columns
- Filter data based on column values (e.g., Department = "HR")
- Add new data entries through user input (with option to skip using -1)
- Real-time updates to the CSV file after data insertion

## 🛠️ Technologies Used

- C++
- STL (vector, map, string)
- File I/O
- Command-line interface

## 🧪 Sample Functionalities

```cpp
DataFrame df;
df.loadCSV("data.csv");
df.show(5);
double avg = df.mean("Salary");
DataFrame hr = df.filter("Department", "HR");
df.addRowInteractively(); // Prompts user input to add a row

📁 Files Structure

DataFrame.h – Header file for the class definition
DataFrame.cpp – Functionality implementations
main.cpp – Sample driver code for usage
data.csv – Sample dataset

📸 Sample Run

Enter number of rows to display: 5
== First 5 Rows ==
...

== Mean of 'Salary' ==
56200.00

== Filter where Department == Marketing ==
...

Add a new entry? Enter -1 to skip.
Name: Shreyansh
...

👨‍💻 Author

Shreyansh Mishra


