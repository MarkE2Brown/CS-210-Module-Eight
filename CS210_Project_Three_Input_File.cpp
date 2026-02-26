#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequencies;

public:
    // Load data 
    void LoadData(string frequency.dat) {
        ifstream inputFile(frequency.dat);
        string itemName;

        if (inputFile.is_open()) {
            while (inputFile >> itemName) {
                itemFrequencies[itemName]++;
            }
            inputFile.close();
            BackupData("frequency.dat");
        } else {
            cout << "Error: Could not open input file." << endl;
        }
    }

    void BackupData(string filename) {
        ofstream outputFile(filename);
        for (auto const& [item, count] : itemFrequencies) {
            outputFile << item << " " << count << endl;
        }
        outputFile.close();
    }

    //Search for specific item
    void SearchItem() {
        string item;
        cout << "Enter item name: ";
        cin >> item;
        if (itemFrequencies.count(item)) {
            cout << item << " appears " << itemFrequencies[item] << " times." << endl;
        } else {
            cout << "Item not found." << endl;
        }
    }

    //Print list with numbers
    void PrintFrequencies() {
        for (auto const& [item, count] : itemFrequencies) {
            cout << item << " " << count << endl;
        }
    }

    //Print Histogram
    void PrintHistogram() {
        for (auto const& [item, count] : itemFrequencies) {
            cout << left << setw(12) << item << " ";
            for (int i = 0; i < count; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    ItemTracker tracker;
    tracker.LoadData("CS210_Project_Three_Input_File.txt");

    int choice = 0;
    while (choice != 4) {
        cout << "\n--- Corner Grocer Menu ---" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: tracker.SearchItem(); break;
            case 2: tracker.PrintFrequencies(); break;
            case 3: tracker.PrintHistogram(); break;
            case 4: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    }
    return 0;
}