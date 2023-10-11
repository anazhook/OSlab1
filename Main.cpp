#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <cstring>
#include <fstream>

#pragma warning(disable: 4996)
using namespace std;
void Console_report(string name)
{
	ifstream in(name);
	string next_line;
	while (getline(in, next_line))
	{
		cout << next_line << endl;
	}
}

string CreatorInput(istream& is, string binfile_name, int& number)
{
	cout << "The name of the binary file: ";
	getline(cin, binfile_name);

	cout << "The number of employees: ";
	cin >> number;
	//int number_length =  (int)log10((double)number) + 1;

	string command_line; // = new char[binfile_name.length() + number_length + 2];
	command_line = binfile_name + " ";
	command_line += number;
	return command_line;
}

string ReporterInput(istream& is, string binfile_name, string reportfile_name, double& payment_by_hour)
{
	cout << "The name of report file: ";
	cin >> reportfile_name;

	cout << "The payment by hour: ";
	cin >> payment_by_hour;
	//int payment_length =  (int)log10(payment_by_hour) + 1;

	string command_line;// = new char[binfile_name.length() + reportfile_name.length() + payment_length + 3];
	command_line = binfile_name + " " + reportfile_name + " ";
	command_line += payment_by_hour;
	return command_line;
}



int main()
{
	string binfile_name;
	int number = 0;

	string creator_command_line = CreatorInput(cin, binfile_name, number);
	string arg1 = "Creator.exe " + creator_command_line;
	char args1[255];
	strcpy(args1, arg1.c_str());
	WCHAR* name_creator = new WCHAR[arg1.size()];
	mbstowcs(name_creator, args1, arg1.size());

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	if (!CreateProcess(NULL, name_creator, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		_cputs("Process not created\n");
		_getch();
		return 0;
	}
	_cputs("Creator process created.\n");
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	string reportFile;
	double payment_by_hour = 0;

	string reporter_command_line = ReporterInput(cin, binfile_name, reportFile, payment_by_hour);
	string arg2 = "Reporter.exe " + reporter_command_line;
	char args2[255];
	strcpy(args2, arg2.c_str());
	WCHAR* name_reporter = new WCHAR[arg2.size()];
	mbstowcs(name_reporter, args2, arg2.size());

	STARTUPINFO si2;
	PROCESS_INFORMATION pi2;
	ZeroMemory(&si2, sizeof(STARTUPINFO));
	si2.cb = sizeof(STARTUPINFO);
	if (!CreateProcess(NULL, name_reporter, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
	{
		_cputs("Process is not created.\n");
		_getch();
		return 0;
	}
	_cputs("The Reporter process is created.\n");
	WaitForSingleObject(pi2.hProcess, INFINITE);
	CloseHandle(pi2.hThread);
	CloseHandle(pi2.hProcess);
	Console_report(reportFile);
	return 0;
}