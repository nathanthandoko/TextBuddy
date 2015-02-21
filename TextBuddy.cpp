#include "TextBuddy.h"


TextBuddy::TextBuddy(void)
{
}

TextBuddy::~TextBuddy(void)
{
}

void TextBuddy::display(vector<string>&text){
	if (text.empty()){
		cout << fileName << " is empty" << endl;
	}
	int number = 1;
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

void TextBuddy::makeFile(){
	ofstream write(fileName);
}

//updateFile writes what is in the vector text onto the created file
void TextBuddy::updateFile(vector<string>&text){
	ofstream write;
	write.open(fileName);
	int number = 1;
	vector<string>::iterator iter;
	for(iter = text.begin(); iter!= text.end(); ++iter){
		write << number << ". " << *iter << endl;
		number++;
	}
	write.close();
}

void TextBuddy::run(){
	string input;
	string command ="";
	string addedSentence;
	vector<string> text;
	int number;
	cout <<"Welcome to TextBuddy. " << fileName << " is ready for use" << endl;
	
	while (input != "exit"){
		cout <<"command: ";
		getline (cin, input);

		if (input == "exit"){
			break;
		}  else if (input == "display"){
			display(text);
		}  else if (input == "clear"){
			clear(text);
		} else { //exctract method from input
			for (int i=0; i<input.length(); i++){
				if (input[i] == ' '){
					command = input.substr(0,i);
					addedSentence = input.substr(i+1);
					break;
				}
			}
			if (command == "add"){
				add(addedSentence, text);
			}
			else if (command == "delete"){
				istringstream(addedSentence) >> number; 
				deleteSentence(text, number);
			}
		}
		command = "";
	}
	updateFile(text);
}


int main(int argc, char*argv[]){
	TextBuddy newText;
	newText.setName(argv[1]);
	newText.run();
	return 0;
}