#pragma once
#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

class TextBuddy{
private:
	string fileName;
public:
	TextBuddy(void);
	~TextBuddy(void);
	void add(string, vector<string>&);
	void display(vector<string>&);
	void deleteSentence(vector<string>&, int);
	void clear(vector<string>&);
	void setName(string);
	void run();
	void makeFile();
	void updateFile(vector<string>&);
	string getFileName();
	void showWelcomeMessage(string);
	void processInput(string, vector<string>&, string, string);
	void sortIt(vector<string>&);
	void searchIt(vector<string>&, string, vector<string>&);
};

#endif

