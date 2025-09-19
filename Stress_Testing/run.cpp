#include<bits/stdc++.h>
using namespace std;

const int ITER = 100; // increased iterations for better chance

// Function to trim trailing whitespace (spaces, tabs, newlines, carriage returns)
string trim_trailing(const string& s) {
    size_t end = s.find_last_not_of(" \n\r\t");
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return "";
    }
    string content((istreambuf_iterator<char>(file)), 
                   istreambuf_iterator<char>());
    file.close();
    return content;
}

int32_t main() {
    // Compile programs with error checking
    cout << "Compiling programs..." << endl;
    
    if (system("g++ -o correct correct.cpp") != 0) {
        cerr << "Error compiling correct.cpp" << endl;
        return 1;
    }
    if (system("g++ -o wrong wrong.cpp") != 0) {
        cerr << "Error compiling wrong.cpp" << endl;
        return 1;
    }
    if (system("g++ -o generator generator.cpp") != 0) {
        cerr << "Error compiling generator.cpp" << endl;
        return 1;
    }

    cout << "All programs compiled successfully!" << endl;
    cout << "Starting stress testing with " << ITER << " iterations..." << endl;

    auto st = clock();
    for (int t = 1; t <= ITER; t++) {
        // Generate test case
        system("./generator > input.txt");

        // Run solutions
        system("./correct < input.txt > correct_solution.txt");
        system("./wrong < input.txt > wrong_solution.txt");

        // Read and trim outputs (remove trailing whitespace)
        string correct_output = trim_trailing(readFile("correct_solution.txt"));
        string wrong_output = trim_trailing(readFile("wrong_solution.txt"));

        if (correct_output != wrong_output) {
            cout << "\n🎯 MISMATCH FOUND in test case " << t << "\n";
            cout << "======================================" << endl;
            cout << "Input: " << readFile("input.txt");
            cout << "Correct output: '" << correct_output << "'" << endl;
            cout << "Wrong output: '" << wrong_output << "'" << endl;
            cout << "======================================" << endl;
            cerr << "Time taken = " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s\n";
            
            // Keep the evidence files
            cout << "Evidence saved in: input.txt, correct_solution.txt, wrong_solution.txt" << endl;
            return 0;
        } else {
            // Optional: Uncomment the next line to see progress on passed test cases
            cout << "Test case " << t << " passed." << endl;
        }
    }
    
    cout << "\n✅ No mismatches found in " << ITER << " test cases!" << endl;
    cerr << "Time taken = " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s\n";
    
    // Clean up temporary files if no mismatch found
    remove("input.txt");
    remove("correct_solution.txt");
    remove("wrong_solution.txt");
    remove("correct");
    remove("wrong");
    remove("generator");
    remove("a.out");
    
    return 0;
}