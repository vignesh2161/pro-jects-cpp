#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to create a new file
void createFile(string fileName)
{
    ofstream outfile;
    outfile.open(fileName.c_str());
    outfile.close();
    cout << "File created successfully!" << endl;
}

// Function to read a file
void readFile(string fileNam
{
    ifstream infile;
    infile.open(fileName.c_str());
    string line;
    while (getline(infile, line))
    {
        cout << line << endl;
    }
    infile.close();
}

// Function to update an existing file
void updateFile(string fileName)
{
    ofstream outfile;
    outfile.open(fileName.c_str(), ios::app);
    string line;
    cout << "Enter text to be added: ";
    getline(cin, line);
    outfile << line << endl;
    outfile.close();
    cout << "File updated successfully!" << endl;
}

// Function to delete a file
void deleteFile(string fileName)
{
    if (remove(fileName.c_str()) == 0)
    {
        cout << "File deleted successfully!" << endl;
    }
    else
    {
        cout << "Error deleting file" << endl;
    }
}

int main()
{
    string fileName;
    int choice;
    cout << "Enter file name: ";
    getline(cin, fileName);

    do
    {
        cout << "Choose operation:" << endl;
        cout << "1. Create file" << endl;
        cout << "2. Read file" << endl;
        cout << "3. Update file" << endl;
        cout << "4. Delete file" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            createFile(fileName);
            break;
        case 2:
            readFile(fileName);
            break;
        case 3:
            updateFile(fileName);
            break;
        case 4:
            deleteFile(fileName);
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
