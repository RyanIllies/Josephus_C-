// Author: Ryan Illies
// Class: CSIS 352
// Assignment: 7
// EXE: prog7

#include <iostream>
#include <fstream>
#include "person.h"
#include "circularqueue.h"
#include <string>
#include <algorithm>
using namespace std;

int main() {
	CircularQueue<Person> people;
	cout << "Which file should we read the names from?" << endl;
	string filename;
	cin >> filename;
	int count = 0;
	// write code here to do the following:
	//   read from the file, THE NAMES WORK 
	ifstream file(filename);	
	if(file.is_open()){//f1
		string name;
		while(getline(file,name)){//w1
		//   create the people,
		//   add them to the queue,in the order of the file
		Person tmp;
		tmp.name = name;
		tmp.alive = true;
		people.add_before(tmp);
		count = count+1;
		}//w1
	}//f1
	file.close();
	cout << "How many are we skipping each time?" << endl;
	int skip_amount;
	cin >> skip_amount;
	//code below is he jeserits algorithm.
	
	for(int i = 0;i<count-1;i++){//f1
	Person you = people.curr();
	cout<<you.name<<endl;
	int skips = 0;
		while(skips < skip_amount){//skps
			Person pp;
			pp = people.curr();
			if(pp.alive){
				skips = skips+1;	
			}
			people.next();
		}//skps					this counts the skips to make sure we get to someone to kill
	    

		while(!(people.curr()).alive || (people.curr()).name == you.name){
			people.next();
		}
		(people.curr()).alive = false;
		cout<<"Killed: "<<(people.curr()).name<<endl;
	//now make it so the next current is found.down here
	
		while(!(people.curr()).alive){//w1
			people.next();
		}//w1
	}//f1
	string name;
	name = (people.curr()).name;
	cout<<"The survivor is: "<<name<<endl;
	//end of josehpus
	people.prev();
	string list[count];
	string tmp;
	for(int a = 0;a<count;a++){
		list[a] = (people.curr()).name;
		people.next();
	}
	sort(list,list+count);
    	for(int i = 0; i < count; i++){
       		cout << list[i]<< endl;
    	}
	
	return 0;
};



















