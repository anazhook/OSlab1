#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct employee
{
    int num; // идентификационный номер сотрудника
    char name[10]; // имя сотрудника
    double hours; // количество отработанных часов
};

int main()
{

    /*
     std::ifstream binaryFile("input.bin", std::ios::binary);
    if (!binaryFile) {
        std::cerr << "Failed to open the binary file." << std::endl;
        return 1;
    }

    // Open the text file for writing
    std::ofstream textFile("output.txt");
    if (!textFile) {
        std::cerr << "Failed to open the text file." << std::endl;
        return 1;
    }

    // Read data from the binary file and transfer it to the text file
    char byte;
    while (binaryFile.read(&byte, sizeof(byte))) {
        // Convert the binary data into a text representation
        std::string text = std::to_string(byte);

        // Write the converted text data into the text file
        textFile << text << " ";
    }

    */

    double Salary;
    string BinFile, Report;
    cout << "Binary file name, report path and salary per hour: \n";
    getline(cin, BinFile);
    getline(cin, Report);
    cin >> Salary;

    ofstream repout(Report); //
    repout << "Отчёт по файлу " << BinFile << endl;

    ifstream readbin(BinFile, ios::binary);          // чтение бинарного
    if (!readbin) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    //int NumberOfEmployees = readbin.tellg() / sizeof(employee);

    //readbin.seekg(ios::beg);
    employee temp;
    while (readbin.read((char*)&temp, sizeof(employee)))
    {
        repout << temp.num << " " << temp.name << " " << temp.hours << " " << temp.hours * Salary << endl;
    }
    readbin.close();
    repout.close();
}