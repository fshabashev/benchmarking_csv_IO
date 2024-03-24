#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // Specify the file name
    std::string fileName = "./data/output32gb.csv";

    // Open the file
    std::ifstream file(fileName);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 1;
    }

    long int count = 0;
    std::string line;
    // Read the file line by line
    while (std::getline(file, line)) {
        // Process the line (here, simply print it)
        count++;
        // print the progress
        if (count % 10000000 == 0) {
            std::cout << "Number of lines read: " << count << std::endl;
            auto intermediate = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = intermediate - start;
            std::cout << "Number of lines read: " << count
                << " - Elapsed time: " << elapsed.count() << " s" << std::endl;

        }
    }
    // Close the file
    file.close();
    // Print the number of lines
    std::cout << "Number of lines in the file: " << count << std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // Print the elapsed time in milliseconds
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}
