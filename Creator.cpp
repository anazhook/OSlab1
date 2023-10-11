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
int main() {
    string BinName;
    int NumberOfLines;
    cout << "enter bin file name and number of employees \n";
    getline(cin, BinName);
    cin >> NumberOfLines;
    cout << "enter data (id, name and number of hours) \n";
    employee* E = new employee[NumberOfLines]; //employee array
    ofstream outfile(BinName, ios::out | ios::binary); // Creating a bin file from console
    if (!outfile) {
        cerr << "file not open!" << endl;
        return 1;
    }

    for (int i = 0; i < NumberOfLines; i++)
    {
        cin >> E[i].num >> E[i].name >> E[i].hours;
        outfile.write((char*)&E[i], sizeof(E[i]));
       /* outfile.write((char*)&E[i].num, sizeof(E[i].num));
        outfile.write(E[i].name, sizeof(E[i].name));
        outfile.write((char*)&E[i].hours, sizeof(E[i].hours));*/
    }

    outfile.close();
    return 0;
}