#pragma once
#ifndef SUIT_H
#define SUIT_H
using namespace std;
class Suit {
private:
	string name;
	string element;
	string represents;
	string direction;
	string season;

public:
	Suit(string n, string e, string r, string d, string s) {
		name = n;
		element = e;
		represents = r;
		direction = d;
		season = s;
	}
	void printData() {
		cout << "\nName: " << name;
		cout << "\nElement: " << element;
		cout << "\nRepresents: " << represents;
		cout << "\nSeason: " << season;
		cout << "\nDirection: " << direction;
		cout << endl;
	}

};


#endif