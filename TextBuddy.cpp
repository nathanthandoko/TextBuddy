#include "TextBuddy.h"
#include<algorithm>

#define NULL "";
#define START_NUMBER 1;

TextBuddy::TextBuddy(void){}

TextBuddy::~TextBuddy(void){}


void TextBuddy::display(vector<string>&text){
	if (text.empty()){
		cout << fileName << " is empty" << endl;
	}
	int number = START_NUMBER;
	vector<string>::iterator iter;
	for(iter = text.begin(); iter!= text.end(); ++iter){
		cout << number << ". " << *iter << endl;
		number++;
	}
}

void TextBuddy::clear(vector<string>&text){
	cout << "all content deleted from " << fileName << endl;
	text.clear();
}

void TextBuddy::deleteSentence(vector<string>&text, int number){
	cout << "deleted from " << fileName << ": " << text[number - 1] << endl;
	text.erase(text.begin() + number - 1);
}

void TextBuddy::add(string added, vector<string>&text){
	cout << "added to " << fileName << ": " << "\"" << added << "\"" << endl;
	text.push_back(added);
}

void TextBuddy::setName(string newName){
	fileName = newName;
	makeFile();
}

//makeFile creates a .txt file with the user-specified name
void TextBuddy::makeFile(){
	ofstream write(fileName);
}

//updateFile writes what is in the vector text onto the created file
void TextBuddy::updateFile(vector<string>&text){
	ofstream write;
	write.open(fileName);
	int number = START_NUMBER;
	vector<string>::iterator iter;
	for(iter = text.begin(); iter!= text.end(); ++iter){
		write << number << ". " << *iter << endl;
		number++;
	}
	write.close();
}

string TextBuddy::getFileName(){
	return fileName;
}

void TextBuddy::showWelcomeMessage(string fileName){
	cout <<"Welcome to TextBuddy. " << fileName << " is ready for use" << endl;
}

void getInput(string &input){
	getline (cin, input);
}

void parseInput(string &input, string &command, string &sentence){
	for (int i=0; i<input.length(); i++){
				if (input[i] == ' '){
					command = input.substr(0,i);
					sentence = input.substr(i+1);
					break;
				}
	}
}

void askForCommand(){
	cout <<"command: ";
}

void TextBuddy::processInput(string input, vector<string>&text, string command, string sentence){
	vector<string> temp; //temporary storage for search function
	int number;
	while (input != "exit"){
			askForCommand();
			getInput(input);
			if (input == "exit"){
				break;
			}	else if (input == "display"){
				display(text);
			}	else if (input == "clear"){
				clear(text);
			}	else if (input == "sort"){
				sortIt(text);		
			}	else { //exctract command and sentence from input
				parseInput(input, command, sentence);
				}
				if (command == "add"){
					add(sentence, text);
				}	else if (command == "delete"){
					istringstream(sentence) >> number; 
					deleteSentence(text, number);
				}	else if (command == "search"){
					searchIt(text, sentence, temp);
					temp.clear(); //as it is temporary, it must be cleared after use
				}	
			command = NULL;
		}
}

void TextBuddy::sortIt(vector<string>&text){
	sort(text.begin(), text.end());
}

bool isFound(vector<string>::iterator iter, string findThis){
	if((iter->find(findThis))!=std::string::npos){
		return true;
	} else return false;
}

//searchIt would search from all lines whether they contain the wanted word and stored the wanted lines in
//a sorted manner
void TextBuddy::searchIt(vector<string>&text, string findThis, vector<string>&temp){
	vector<string>::iterator iter;
	for (iter = text.begin(); iter!= text.end(); ++iter){
		if (isFound(iter, findThis)){
			temp.push_back(*iter);
		}
	}
	sortIt(temp);
	display(temp);
}

void TextBuddy::run(){
	string input;
	string command = NULL;
	string sentence;
	vector<string> text;
	
	showWelcomeMessage(fileName);
	processInput(input, text, command, sentence);
	updateFile(text);
}


int main(int argc, char*argv[]){
	TextBuddy newText;
	newText.setName(argv[1]);
	newText.run();
	return 0;
}