#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::ofstream> fileObjects;
    for (int i = 0; i < 10; ++i) {
        fileObjects.emplace_back("./data_output/output32gb_" + std::to_string(i) + ".csv", std::ios::out);
    }

    std::ifstream inputFile("./data/output32gb.csv");
    std::string line;
    long long count = 0;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            if (count == 0) {
                // Assuming you just want to print out the columns as in the Python script
                std::cout << "Columns: " << line << std::endl;
            }
            else {
                std::vector<std::string> data;
                std::string token;
                std::stringstream lineStream(line);

                while (getline(lineStream, token, ',')) {
                    data.push_back(token);
                }

                int intColumn = std::stoi(data.back());
                int outputFileIndex = intColumn % 10;
                fileObjects[outputFileIndex] << line << "\n";

                if (count % 10000000 == 0) {
                    auto now = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = now - start;
                    std::cout << "Row " << count << ": " << line << ", time taken since start: " << elapsed.count() << " seconds" << std::endl;
                }
            }
            ++count;
        }
        inputFile.close();
    }

    for (auto& fileObject : fileObjects) {
        if (fileObject.is_open()) {
            fileObject.close();
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Number of rows: " << count - 1 << std::endl; // Subtracting 1 to match the Python script's output.
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
