#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to create the shift table and print it
vector<int> createShiftTable(const string& pattern) {
    int m = pattern.length();
    vector<int> shiftTable(256, m); // Initialize with default value m

    for (int i = 0; i < m - 1; ++i) {
        shiftTable[static_cast<int>(pattern[i])] = m - 1 - i;
    }

    // Print the shift table for the pattern string
    cout << "Shift Table:\n";
    for (char c : pattern) {
        cout << c << ": " << shiftTable[static_cast<int>(c)] << "\n";
    }
    cout << "\n";

    return shiftTable;
}

// Function to perform string matching using Horspool algorithm
vector<int> horspool(const string& text, const string& pattern) {
    vector<int> occurrences;
    int n = text.length();
    int m = pattern.length();
    vector<int> shiftTable = createShiftTable(pattern);

    int i = m - 1; // Index for pattern
    int mismatchCount = 0;
    bool matchFound = false;

    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            cout << "Comparing pattern[" << m - 1 - k << "] = " << pattern[m - 1 - k]
                 << " with text[" << i - k << "] = " << text[i - k] << "\n";
            ++k;
        }
        if (k == m) {
            // Match found
            occurrences.push_back(i - m + 1);
            cout << "Pattern found at position: " << i - m + 1 << "\n";
            matchFound = true;
            break;
        } else {
            // Mismatch occurred
            cout << "Mismatch occurred at position: " << i - k + 1 << "\n";
            ++mismatchCount;
        }
        i += shiftTable[static_cast<int>(text[i])];
    }

    if (!matchFound) {
        cout << "Pattern not found in the text.\n";
    }

    cout << "Total mismatches: " << mismatchCount << "\n";

    return occurrences;
}

int main() {
    string text = "Hello, how are you doing today?";
    string pattern = "how";

    vector<int> occurrences = horspool(text, pattern);

    if (!occurrences.empty()) {
        cout << "Pattern found at positions:";
        for (int pos : occurrences) {
            cout << " " << pos;
        }
        cout << "\n";
    }

    return 0;
}
