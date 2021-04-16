// By Siddhartha Bobba
// C++
//A linked list to add students, get average, create new students. A database for students and their info.


#include <iostream>
#include <cstring>
#include <iomanip>

#include "Student.h"
#include "Node.h"

using namespace std;

void createStudent(Node* &head);
void addStudent(Student*, Node*, Node*&);
void print(Node*);

void average(Node* head, int Count, float TotalAvg);


int main() {

  Node* head = NULL;

  bool Running = true;
  char input[40];


  while (Running == true) {

    cout << "What would you like to do?" << endl;
    cout << endl;
    cout << "ADD" << endl << "PRINT" << endl << "AVERAGE" << endl << "DELETE" << endl << "QUIT" << endl; //gives user the options
    cout <<endl; //space
    cout << "Please select from the above commands and enter:" << endl; //asks to enter
    
    cin.get(input, 40);
    cin.ignore();




    if (input[0] == 'A' && input[1] == 'D' && input[2] == 'D') { //if the first input matches 'ADD', run add student function

      createStudent(head);
	    
    }

    if (input[0] == 'P' && input[1] == 'R' && input[2] == 'I' && input[3] == 'N' && input[4] == 'T') {

      print(head); 
    }


    if (input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T') {
      
      cout << "Terminating program..." << endl;
      Running = false; // Ends code, ends while loop

    }

    if (input[0] == 'A' && input[1] == 'V' && input[2] == 'E' && input[3] == 'R' && input[4] == 'A' && input[5] == 'G' && input[6] == 'E') {


      average(head, 0, 0);

    }//takes input for average and calls function in main
      
  }

  
  return 0;
}


void createStudent(Node* &head) {

  char* firstname = new char[50]; // first name
  char* lastname = new char[50]; //last name
  int studentid = 0; //student's id variable
  float gpa = 0; //students gpa variable
  
  cout << "Enter the student's first name" << endl;
  cin.get(firstname, 50);
  cin.get(); //terminating char
  
  cout << "Enter the student's last name" << endl;
  cin.get(lastname, 50);
  cin.get(); //terminating char

  cout << "Enter the student's ID number" << endl;
  cin >> studentid;
  cin.get(); //terminating char

  cout << "Enter the student's GPA" << endl;
  cin >> gpa;
  cin.get(); //terminating char

  //assigning the variables and setters to the student pointer
  Student* newstudent = new Student(firstname);
  newstudent->setLastname(lastname);
  newstudent->setStudentid(studentid);
  newstudent->setGPA(gpa);

  addStudent(newstudent, head, head);

}

void addStudent(Student* newstudent, Node* next, Node* &head) {

  if (head == NULL) {
    //create a new node and create a new student to put in that node

    head = new Node(newstudent); //set head to new node

    return;
  } 

  if (next->getNext() == NULL) {
    next->setNext(new Node(newstudent));
  }
  
  else if (next -> getNext() != NULL) {
    addStudent(newstudent, next->getNext(), head);
  }

}


void print(Node* next) {

  if (next != NULL) {

    cout << endl;
    
    cout << next->getStudent()->getFirstname() << endl;
    
    cout << next->getStudent()->getLastname() << endl;
    
    cout << next->getStudent()->getStudentid() << endl;

    cout << next->getStudent()->getGPA() << endl;

    cout << endl;
 
    print(next->getNext());

    
  }
  
}


void average(Node* head, int Count, float TotalAvg) {


  Node* CurrentNumb = head;
  //head = new Node(CurrentNumb);


  if (head == NULL) {
    
    cout << "There is nothing to average. The list is empty. Add students before using AVERAGE" << endl;
    
  }
  else {
    if(head->getNext()== NULL) {

      Count = Count+1;
      TotalAvg+= CurrentNumb->getStudent()->getGPA();
      cout << "The average of all students is:" << setprecision(2) << (TotalAvg/Count)<< endl;
    }
    else {
      average(head->getNext(), Count+1, TotalAvg+CurrentNumb->getStudent()->getGPA());
      
      
    }
    
  }
  
}
