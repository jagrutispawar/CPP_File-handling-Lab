#include <iostream>

#include <fstream>

#include <string>
using namespace std;
int main()
{
string userInput;
// Asking user for input
cout << "Enter some text: ";
getline(cin, userInput);
// Writing user input to a file
ofstream outFile("myfile.txt");
if (outFile.is_open())
{
outFile << userInput;
outFile.close();
cout << "Data saved to file." << endl;
}
else
{
cout << "Error opening file for writing." << endl;
}
// Reading content from the file
string fileContent;
ifstream inFile("myfile.txt");
if (inFile.is_open())
{
getline(inFile, fileContent);
inFile.close();
cout << "Data read from file: " << fileContent << endl;
}
else

{

cout << "Error opening file for reading." << endl;
}
return 0;
}