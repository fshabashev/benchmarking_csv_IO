# File Processing Benchmark: Python vs C++

This repository contains benchmark results for processing a large CSV file using Python and C++. The task involves reading a file named `output32gb.csv`, processing its contents, and writing the results to multiple output files based on the last column's value in each row.

## Benchmark Setup
- **File Details:** The input file `output32gb.csv` contains 800,000,000 rows, the size of the file is 35GB, it was generated with the `generate_file.py` script
- **Python version:** Python3.11 was used for the tests
- **C++ compiler parameters**: ```/permissive- /ifcOutput "x64\Release\" /GS /GL /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /sdl /Fd"x64\Release\vc143.pdb" /Zc:inline /fp:precise /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oi /MD /FC /Fa"x64\Release\" /EHsc /nologo /Fo"x64\Release\" /Fp"x64\Release\ConsoleApplication2.pch" /diagnostics:column ```
- **C++ compiler**: `Microsoft (R) C/C++ Optimizing Compiler Version 19.39.33523 for x86`
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

In this benchmark C++ performs 30% faster, but do you really want to use it for one-off tasks like processing a large CSV file? 

1. **SSD Throughput vs. CPU Processing Speed**: The distinction between the computational speed of the CPU and the read/write capabilities of storage devices (like SSDs) is a crucial one. CPUs are often capable of processing data much faster than it can be read from or written to storage devices. This discrepancy means that for many data-intensive tasks, the limiting factor isn't the speed at which the CPU can process data, but rather how quickly data can be transferred to and from storage.

2. **Python's Applicability for Data Processing**: Given the I/O bottleneck, the efficiency of Python for large data processing tasks is less affected by its slower execution speed compared to more performant languages like C++. The simplicity and developer productivity offered by Python often outweigh the performance penalties, especially for tasks that are run infrequently (one-off tasks) or where development time is a more critical factor than execution time.

3. **I/O Bottlenecks and Solutions**: While certain systems and architectures (e.g., distributed systems or setups with multiple SSDs) can alleviate I/O bottlenecks, they introduce complexity and may not be justified for simpler, one-off tasks. Systems like Apache Spark, ClickHouse, or Vertica are designed to scale out and leverage multiple nodes and storage devices to increase throughput. However, the overhead of setting up and maintaining such systems can be significant, making them less suitable for tasks where the complexity doesn't match the benefit.

4. **Practical Considerations for One-off Tasks**: The decision to use a more straightforward, albeit slower, processing method (like a Python script) for one-off data processing tasks is practical. In these cases, the time saved in development and the ease of implementation can be more valuable than the raw execution speed gained from using a more complex, lower-level language like C++ or a distributed data processing system.

