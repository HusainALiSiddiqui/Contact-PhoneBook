	// Project 2........Contact Book.......Husain Ali Siddiqui 32115229  
	#include <iostream>
	#include <vector>
	#include <fstream>
    #include <string>  // need it for get line function
	#include"Person.h"
    using namespace std;
	
	ofstream information("informtaion.txt");





	void displayOption() {                                        //Displays the menu fot the switch statemtns
		cout << "Please choose one of the following options: " << endl;
		cout << "\t 1- Add contact" << endl;
		cout << "\t 2- Delete contact" << endl;
		cout << "\t 3- Search contact" << endl;
		cout << "\t 4- List of all contacts" << endl;
		cout << "\t 5- Exit" << endl;
	}



	vector<Person> contents;         // global vector since we will be using vectors alot in the following functions and we need the info stored in em 
	

	void readFile() {
		fstream information;
		information.open("information.txt", ios::in);
		if (information.is_open()) {
			string line;
			while (getline(information,line)) {         //reads line of text and stores it in in line
				cout << line << endl;

			}
			information.close();
		
		}
	
	}


	void saveContact() {
		ofstream information("information.txt");
		if (information.is_open()) { //checks if file is open or not 

			for (Person p : contents) {     //The for loop iterates over each Person object in the vector      
				information << "\tName: " << p.name << endl;
				information << "\tSurname: " << p.surname << endl;    // for each person obect writes out the following
				information << "\tAge: " << p.age << endl;
				information << "\tAddress: " << p.adress << endl;
				information << "\tPhoneNo: " << p.phoneNo << endl;
				information << endl;
			}
			information.close();
		}
		else {
			cout << "Error: Could not open the file" << endl;
		}
	}
	
	
	
	void Option1() {                                                                 // option 1 for cases in switch 
		
		Person p1;
		cout << endl << "Please fill in the following infromation" << endl;          // asks user to input the information to store the contacts information in txt file
		cout << "Name: ";
		cin >> p1.name;
		cout << endl << "Surname: ";
		cin >> p1.surname;
		cout << endl << "Age: ";
		cin >> p1.age;
		cout << endl << "Adress: ";
		cin >> p1.adress;
		cout << endl << "Phone Number: ";
		cin >> p1.phoneNo;
	
		contents.push_back(p1);                                                      //the information is stored in the global vector contents 
	
		saveContact();                                                               //the information is saved using the save contact information
	}


	void C1() {       //the function here helps save the informtaion from the.txt file so its after evry run its stored and the information can be used for next compile
      		
		ifstream information("information.txt");
	    Person p1;
		if (information.is_open()) {
			
			while ( information >> p1.name >> p1.surname >> p1.age >> p1.adress >> p1.phoneNo) {          // reads data from the file and stores it in the object "p1"
				contents.push_back(p1);   //adds it inside the vector 
			}
			information.close();
		}

	}


void DltContact() {
		int PhoneN;
		bool found1 = false;
	    cout << "Please enter the phone number you want the contact deleted for:";
		cin >> PhoneN;
		for (int i = 0; i < contents.size(); i++) {                    //loops i till the the size of the vector
			
			
			if (contents[i].phoneNo == PhoneN) {                 //loops through the vector to find the same phone number
			
               contents.erase(contents.begin() + i);            //removes the ith element of the vector if the phone number is found
				found1 = true;
				break;
			}
		}
		saveContact();                                         //saves the update contact list to the file
		
		if (found1) {
			cout << "\n The contact is Deleted" << endl;
		}
		else if (!found1) {
			cout << "\n No contact with that Phone number exists in ur contacts" << endl;
		}
		

}

	


void SContact() {
	int phoneNumber;
	bool found = false;

	cout << "Please enter the phone number you want to search for: ";
	cin >> phoneNumber;

	for (int i = 0; i < contents.size(); i++) {           // loops using i  inside the vector
		if (contents[i].phoneNo == phoneNumber) {             //checks phone number in vector and if equal displays the rest of the things
			cout << "Name: " << contents[i].name << endl;
			cout << "Surname: " << contents[i].surname << endl;
			cout << "Age: " << contents[i].age << endl;
			cout << "Address: " << contents[i].adress << endl;
			cout << "Phone number: " << contents[i].phoneNo << endl<<endl;
			found = true;
		}
	}

	if (!found) {                                       //if not found display the following
		cout << "No contact with that phone number exists." << endl;
	}
}







int main(void) {
		C1();         //tries saving the text from file into vector so it can save the contents of the file for next fresh run of program after exiting 
		int option;
	
    do {
		displayOption();
		cin >> option;

		switch (option) {
			case 1:
				Option1(); //Calls option 1 stored in function
				break;
			case 2:
				DltContact();   //delete contacts on phone number
				break;
			 case 3:
				SContact();     //searches for phone number
				break;
			case 4:
				readFile();    // calls function to display information
				break;
			case 5:
				cout << "Exited succesfully\n\n"; // Exits Program clearly
				break;
			default:
				cout << "============================" << endl;
				cout << "PLEASE CHOOSE A VALID OPTION" << endl;  //if anything othrn then option number are put in 
				cout << "============================" << endl;
				break;
			}
		
	} while (option != 5);  //keep repeatig switch statement until choice isnt 5 as 5 is an exit status

}
