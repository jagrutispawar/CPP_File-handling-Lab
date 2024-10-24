#include <iostream>
#include <fstream>

using namespace std;

struct Employee {
    char name[50];
    int id;
    float salary;
};

void writeToFile(const Employee & employee){
    ofstream outFile("employee.dat",ios::binary);
    
    if(!outFile){
      cerr<<"Error:Could not open the file for writing!"<<endl;   
      return;
    }
    
    outFile.write(reinterpret_cast<const char*>(&employee),sizeof(employee));
    outFile.close();
    
    cout <<"Employee data written to binary file successfully!"<<endl;
}

void readFromFile(){
    Employee employee;
    
    ifstream inFile("employee.dat",ios::binary);
    if(!inFile){
       cerr<<"Error:Could not open the file for reading!"<<endl;
       return;
    }

    inFile.read(reinterpret_cast<char*>(& employee),sizeof(employee));
    
    if(inFile){
       cout<<"\nEmployee data read from binaryfile:"<<endl;
       cout<<"salary:"<<employee.name<<endl;
       cout<<"ID:"<<employee.id<<endl;
       cout<<"Salary:"<<employee.salary<<endl;
    }else{
       cerr<<"Error:Could not read data from the binary file!"<<endl;
    }
    
    inFile.close();
}

int main (){
    Employee employee;
    
    cout<<"Enter employee details:\n";
    cout<<"Name:";
    cin.ignore();
    cin.getline(employee.name,50);
    cout<<"ID:";
    cin>>employee.id;
    cout<<"Salary:";
    cin>> employee.salary;
    
    writeToFile(employee);
    
    readFromFile();
    
    return 0;
}
