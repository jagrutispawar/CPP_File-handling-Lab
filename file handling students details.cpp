#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addStudent(){
    ofstream outfile("student.txt",ios::app);
    string name;
    int rollNumber;
    float grade;
    
    cout <<"Enter student name:";
    cin >>name;
    cout <<"Enter roll number:";
    cin >>rollNumber;
    cout <<"Enter grade:";
    cin >>grade;
    
    outfile << name << "" << rollNumber << "" << grade << endl;
    
    outfile.close();
    cout <<"student record added!"<<endl;
}
void displayStudent(){
    ifstream infile("student.txt");
    string name;
    int rollNumber;
    float grade;
    
    cout <<"Student Records:"<<endl;
    
    while(infile>>name>>rollNumber>>grade){
        cout <<"Name:"<<name<<",RollNumber:"<<rollNumber<<",Grade:"<<grade<<endl;
    }
    infile.close();
}
void SearchStudent(){
    ifstream infile("student.txt");
    string name, SearchName;
    int rollNumber;
    float grade;
    bool found =false;
    
    cout <<"Enter the student nameto search:";
    cin >> SearchName ;
    
    while (infile >>name >>rollNumber>>grade){
        if(name == SearchName){
            cout <<"Student found!Name:"<<name<<",Roll Number:"<<rollNumber<<",Grade:"<<grade<<endl;
            found =true;
            break;
        }
    }
    if (!found){
        cout<<"student not found."<<endl;
    }
    infile.close();
}

int main(){
    int choice;
    do{
        cout <<"1.Add Student"<<endl;
        cout <<"2.Display All Students"<<endl;
        cout <<"3.Search for Student"<<endl;
        cout<<"4.Exit"<<endl;
        cout <<"Enter your choice:";
        cin >> choice;
        
        if (choice == 1){
            addStudent();
        }else if (choice == 2){
            displayStudent();
        }else if (choice == 3){
            SearchStudent();
        }
    }while (choice!=4);
    
    cout <<"Program exited."<< endl;
    return 0;
}