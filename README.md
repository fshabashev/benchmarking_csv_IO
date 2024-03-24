# File Processing Benchmark: Python vs C++

This repository contains benchmark results for processing a large CSV file using Python and C++. The task involves reading a file named `output32gb.csv`, processing its contents, and writing the results to multiple output files based on the last column's value in each row.

## Benchmark Setup
- **File Details:** The input file `output32gb.csv` contains 800,000,000 rows, the size of the file is 35GB, it was generated with the `generate_file.py` script
- **Python version:** Python3.11 was used for the tests
- **Technical specifications:** CPU: `AMD Ryzen 7 5800X 8-Core Processor`, Memory: `32GB`, Hard Drive: `Samsung SSD 970 EVO Plus 1TB`
- **Python script:** `iterate_over_file.py`
- **C++ code:** `ConsoleApplication2.cpp`
## Benchmark Results
### Python
Total processing time: **1115.348 seconds**

### C++

The C++ program processed the file as follows:

Total processing time: **853.298 seconds**

## Conclusion
The benchmark results show that the C++ implementation is approximately 30% faster than the Python script