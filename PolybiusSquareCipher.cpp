/*
Polybius Square Cipher program descrtiption:  a program where each letter is replaced with two numbers according to a key entered by the user.

authorized by: Ahmed Mohamed Ali
version: 1.0
*/

#include<iostream>
#include<string>
#include <algorithm>
#include <cctype>
using namespace std;

string convertLower (string s);
string enc(string txt, char letters[5][5], string key[5]);
string dec(string enctxt, char letters[5][5], string key[5]);
string checkchoice(string choice);

string key[5];
char letters[5][5] = {{'a', 'b', 'c', 'd', 'e'}, 
					  {'f', 'g', 'h', 'i', 'k'},
					  {'l', 'm', 'n', 'o', 'p'},
					  {'q', 'r', 's', 't', 'u'},
					  {'v', 'w', 'x', 'y', 'z'}};

int main(){
	string txt, choice;
	string input;
	
	cout << "Ahlan ya user ya habibi.\nWhat do you like to do today?\n1- Cipher a message\n2- Decipher a message\n3- End\n";
	cin >> choice;
	
	choice = checkchoice(choice);

	while (choice != "3"){
		string key[5];
		for(int i = 0; i < 5; i++){
			cout << "\nplease enter the key every letter alone in the domain (0,1,2,3,4,5,6,7,8,9) and unrepeated value: ";
			cin >> input;
        
			auto exists = find(begin(key), end(key), input) != end(key);

			while ((input.find_first_not_of("0123456789") != string::npos || input.size() != 1 || exists)){
				cout << "\ninvalid input: please enter (a 1-digit number) don't contain any characters and unrepeated value ...\nexample (9): ";
				cin >> input;
				exists = find(begin(key), end(key), input) != end(key);
			}

			key[i] = input;
		}

		if (choice == "1"){
			cout << "\n\nplease enter the message you want to cipher: ";
			getline(cin>>ws, txt);
			cout << "Cipher Text: "<< enc(txt, letters, key) << "\n\n";
		}
		else if (choice == "2"){
			cout << "\n\nplease enter the message you want to decipher: ";
			getline(cin>>ws, txt);
			cout << "Decipher Text: "<< dec(txt, letters, key) << "\n\n";
		}
		cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message\n3- End\n";
		cin >> choice;
	
		checkchoice(choice);
	}
	return 0;
}

string enc(string txt, char letters[5][5], string key[5]){
	string encStr;

	txt = convertLower(txt);
	
	for (int i = 0; i < txt.size(); i++){
		if (txt[i] == ' '){
			encStr += ' ';
		}
		else {
			for (int row = 0; row < 5; row++) {
				for (int col = 0; col < 5; col++) {
					if (txt[i] == 'j'){
						txt[i] = 'i';
					}
					if (txt[i] == letters[row][col]){
						encStr += to_string(((stoi(key[row])) * 10) + (stoi(key[col])));
					}
				} 
			}		
		}
	}
	return encStr;
}

string dec(string enctxt, char letters[5][5], string key[5]){
	string decStr;
	for (int i = 0; i < enctxt.size(); i++){
		if (enctxt[i] == ' '){
			decStr += ' ';
		}
		else {
			if (((enctxt[i]-'0')-1) == 1 && ((enctxt[i + 1]-'0')-1) == 3){
				decStr += "(i/j)";
				i++;
			}
			else{
				decStr += letters[(enctxt[i]-'0')-1][(enctxt[i + 1]-'0')-1];
				i++;
			}
		}
	}
	return decStr;
}

string convertLower (string s){
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}

string checkchoice(string choice){
	while ((choice.find_first_not_of("123") != string::npos || choice.size() != 1)){
			cout << "\ninvalid choice: please enter (a 1-digit number) domain (1,2,3): ";
			cin >> choice;
	}
	return choice;
}

