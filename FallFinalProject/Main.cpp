// Elizabeth Atkins
// C++ Software Development Final Project
// December 1, 2022
// This program allows a user to get a tarot reading and view card meanings


#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "Suit.h"

using namespace std;

const int MINORSIZE = 56;
const int MAJORSIZE = 22;

enum suits { WANDS, CUPS, SWORDS, PENTACLES };
enum ranks { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, PAGE, KNIGHT, QUEEN, KING };

struct MinorArcana
{
	suits suit;
	ranks rank;

};

template <class T>
class add {
public:
	T sum(T a, T b)
	{
		T result = a + b;
		return (result);
	}
};

template<>
class add <string> {
public:
	string combine(string a, string b)
	{
		string word = a.append(b);
		return (word);

	}
};

// Function Prototypes

void createDeckArray(MinorArcana[]);
void displayMinorArcana(MinorArcana[]);
void displayMajorArcana(string[]);
void getSuitInfo();
void birthFortune();
string cardMeanings(string);
string displaySuit(MinorArcana);
string displayRank(MinorArcana);
string cardName(MinorArcana);
int majorDeal(string[]);
MinorArcana minorDeal(MinorArcana[]);
int menu();


int main() {

	MinorArcana minorArcana[MINORSIZE];
	string majorArcana[MAJORSIZE] = { "The Fool", "The Magician", "The High Priestess", "The Emperor", "The Hierophant", "The Lovers", "The Chariot", "Strength", "The Hermit", "Wheel of Fortune", "Justice", "The Hanged Man", "Death", "Temperance", "The Devil", "The Tower", "The Star", "The Moon", "The Sun", "Judgement", "The World", };
	MinorArcana card1, card2, card3;
	string deal1, deal2, deal3;
	int choice = 0;
	string card;
	int offset;

	

	// Introduce program to the user

	cout << "\n * Welcome to the Fortune Reading Program *\n";
	cout << "+------------------+";			cout << "\t+------------------+\n";
	cout << "|		   |";					cout << "\t|		   |\n";
	cout << "|		   |";					cout << "\t|		   |\n";
	cout << "|   0. The Fool    |";			cout << "\t| 1. The Magician  |\n";
	cout << "|		   |";					cout << "\t|	           |\n";
	cout << "|		   |";				    cout << "\t|		   |\n";
	cout << "|		   |";					cout << "\t|		   |\n";
	cout << "|		   |";					cout << "\t|		   |\n";
	cout << "+------------------+";			cout << "\t+------------------+\n";
	cout << "\n Tarot reading is the practice of divining wisdom and guidance through a specific spread of Tarot cards.";
	cout << "\n However, contrary to popular belief, the cards do not simply tell your fortune, and ";
	cout << "\n one does not have to be a psychic to give Tarot readings.\n";

	cout << "\n This program will allow you to get a three card tarot reading with the Minor or Major Arcana. ";
	cout << "\n The Major Arcana can represent important life altering moments, while the Minor Arcana may represent smaller events.\n";

	cout << "\n Best practices:";
	cout << "\n It's typically best to have a question in mind before a reading.";
	cout << "\n You can consider the three cards as past, present, and future regarding your question.";
	cout << "\n After the reading, you can search a card to view the meaning behind it.\n";

	
	createDeckArray(minorArcana); // Call function to create minor arcana deck
	

	do { // Loop user menu until exit
		int choice = menu();
		
		switch (choice) {
		case 1: displayMajorArcana(majorArcana);
			break;
		case 2:
			displayMinorArcana(minorArcana);
			break;
		case 3: getSuitInfo();
			break;
		case 4: 
			cardMeanings(card);
			break;
		case 5: cout << " Press enter to receive a three-card Minor Arcana reading: ";
			system("pause");
			std::srand(std::time(nullptr));
			card1 = minorDeal(minorArcana);
			card2 = minorDeal(minorArcana);
			card3 = minorDeal(minorArcana);

			cout << " " << cardName(card1) << endl << " " << cardName(card2) << endl << " " << cardName(card3) << endl;
			break;
		case 6:
			cout << " Press enter to receive a three-card Major Arcana reading: ";
			system("pause");
			srand(time(0));
			for (int i = 0; i < 3; i++) {
				int seed = rand() % 22;
				cout << majorArcana[seed] << endl;
			}
			break;
		case 7: birthFortune();
			break;
		case 8: cout << "\nThanks for playing, goodbye!"; return 0;
			break;
		default: "Invalid choice";
			break;
		}
	} while (choice > 1 || choice < 8);




	cout << endl << endl;
	system("pause");
	return 0;
}

int menu() { // User menu
	int choice = 0;
	cout << "\nPlease enter a selection:";
	cout << "\n1. Display Major Arcana";
	cout << "\n2. Display Minor Arcana";
	cout << "\n3. View Suit Info";
	cout << "\n4. View Card Meanings";
	cout << "\n5. 3 Card Minor Arcana Reading";
	cout << "\n6. 3 Card Major Arcana Reading";
	cout << "\n7. Fortune Cookie Reading";
	cout << "\n8. Exit Program";
	cin >> choice;

	if (choice < 1 || choice > 8) {
		cout << "\nInvalid selection, try again: ";
		cin >> choice;
	}
	return choice;
}

string displaySuit(MinorArcana s) { // Display suit of card

	s.suit;

	switch (s.suit) {
	case WANDS: return "Wands";
		break;
	case CUPS: return "Cups";
		break;
	case SWORDS: return "Swords";
		break;
	case PENTACLES: return "Pentacles";
		break;
	}
}

string displayRank(MinorArcana r) { // Display rank of card

	r.rank;

	switch (r.rank) {
	case ACE: return "Ace";
		break;
	case TWO: return "Two";
		break;
	case THREE: return "Three";
		break;
	case FOUR: return "Four";
		break;
	case FIVE: return "Five";
		break;
	case SIX: return "Six";
		break;
	case SEVEN: return "Seven";
		break;
	case EIGHT: return "Eight";
		break;
	case NINE: return "Nine";
		break;
	case TEN: return "Ten";
		break;
	case PAGE: return "Page";
		break;
	case KNIGHT: return "Knight";
		break;
	case QUEEN: return "Queen";
		break;
	case KING: return "King";
	}
}

string cardName(MinorArcana i) { // Return card name
	string r, s;
	string cardList;
	r = displayRank(i);
	s = displaySuit(i);
	cardList = r + " of " + s;
	return cardList;
}

void createDeckArray(MinorArcana minorArcana[]) { // Create minor arcana deck
	int i = 0;
	for (suits s = WANDS; s <= PENTACLES; s = static_cast<suits>(s + 1)) {
		for (ranks r = ACE; r <= KING; r = static_cast<ranks>(r + 1)) {

			minorArcana[i].suit = s;
			minorArcana[i].rank = r;
			i++;

		}
	}
}
void displayMinorArcana(MinorArcana minorArcana[]) { // Display minor arcana deck
	cout << "\nMinor Arcana: " << endl;
	for (int i = 0; i < MINORSIZE; i++) {
		cout << " " << cardName(minorArcana[i]) << endl;

	}
}

void displayMajorArcana(string majorArcana[]) { // Display major arcana deck
	cout << "\nMajor Arcana: " << endl;
	for (int i = 0; i < MAJORSIZE; i++) {
		cout << " " << majorArcana[i] << endl;
	}
}

MinorArcana minorDeal(MinorArcana minorArcana[]) { // Deal minor arcana cards
	int random = (rand() % 56) + 1;
	return minorArcana[random];

}


void getSuitInfo() { 
	Suit wands("Wands", "Fire", "Creativity", "South", "Summer");
	wands.printData();
	Suit swords("Swords", "Air", "Intellect", "West", "Spring");
	swords.printData();
	Suit cups("Cups", "Water", "Emotion", "East", "Autumn");
	cups.printData();
	Suit pentacles("Pentacles", "Earth", "Material Possessions", "North", "Winter");
	pentacles.printData();
}


string cardMeanings(string card) { // Function to display card meanings
	ifstream file;
	file.open("meanings.txt");
	string line;
	int offset;
	cout << "Enter the name of Tarot Card: \n";
	cout << "(case sensitive) \n";
	cin.ignore();
	getline(cin, card);

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			size_t pos = line.find(card); // Find card name in file
			if (pos != string::npos) {
				cout << line << endl;
			}
		}
	
		file.close();
	}
	else {
	cout << "Error opening file";
	}
	return card;
}


void birthFortune() { // Function to display fortune cookie reading
	int birthMonth;
	int color;

	add <string> words;
	string p(""), c("");
	add <int> numbers;
	
	cout << "\nEnter the number of your birth month: ";

	cout << "\n1. January ";
	cout << "\n2. Feburary";
	cout << "\n3. March";
	cout << "\n4. April";
	cout << "\n5. May";
	cout << "\n6. June";
	cout << "\n7. July";
	cout << "\n8. August";
	cout << "\n9. September";
	cout << "\n10. October";
	cout << "\n11. November";
	cout << "\n12. December";

	cin >> birthMonth;

	switch (birthMonth) {
	case 1: p = "An important person is";
		break;
	case 2: p = "Courtsey is";
		break;
	case 3: p = "Look for" ;
		break;
	case 4: p = "How you look depends on";
		break;
	case 5: p = "You need";
		break;
	case 6: p = "New ideas could be";
		break;
	case 7: p = "No one can walk backwards into";
		break;
	case 8: p = "Practice makes";
		break;
	case 9: p = "Self- knowledge could be";
		break;
	case 10: p = "Soon life will become";
		break;
	case 11: p = "Success is";
		break;
	case 12: p = "The harder you work, the sooner you will find";
		break;
	}
	
	cout << "\nEnter the number of your shirt color: ";
	cout << "\n1. Red ";
	cout << "\n2. Blue";
	cout << "\n3. Green";
	cout << "\n4. Yellow";
	cout << "\n5. Purple";
	cout << "\n6. Orange";
	cout << "\n7. Gray";
	cout << "\n8. Black";
	cout << "\n9. White";
	cout << "\n10. Pink";
	cout << "\n11. Beige";
	cout << "\n12. Other";
	cin >> color;

	
	switch (color) {
	case 1: c = " a new friendship ";
		break;
	case 2: c = " a new job";
		break;
	case 3: c = " wise advice";
		break;
	case 4: c = " the key ";
		break;
	case 5: c = " a new love ";
		break;
	case 6: c = " nothing ";
		break;
	case 7: c = " everything";
		break;
	case 8: c = " a new beginning ";
		break;
	case 9: c = " a dog ";
		break;
	case 10: c = " a problematic time ";
		break;
	case 11: c = " a new home ";
		break;
	case 12: c = " a new car ";
		break;
	}

	string word = words.combine(p, c);
	int sum = numbers.sum(birthMonth, color);
	cout << endl;
	cout << "The fortune cookie says:\n";
	cout << word << endl;
	cout << "Lucky number is " << sum << endl;


}