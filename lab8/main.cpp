#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return false;
		return true;
	}
};

int main() {
	string myString;
	ifstream myFile("input.txt");
	if (!myFile)
	{
		printf("error la deschiderea fisierului: input.txt");
		return 0;
	}
	//citim prima linie din fisier
	if (!getline(myFile, myString)) {
		printf("error la citirea din fisier: input.txt");
		return 0;
	}
	//convertim in lowercase
	for (int i = 0; i < myString.size(); i++) {
		if (myString[i] >= 'A' && myString[i] <= 'Z') {
			myString[i] = myString[i] + 'a' - 'A';
		}
	}
	map<string, int> myMap;
	printf("Sirul de caractere citit este: %s\n", myString.c_str());
	
	string aux;
	for (int i = 0; i < myString.size(); i++) {
		if (!(myString[i] >= 'a' && myString[i] <= 'z')) {
			if (myMap.count(aux) != 0) {
				myMap[aux] += 1;
			}
			else {
				myMap[aux] = 1;
			}
			aux.clear();
		}
		else {
			aux += myString[i];
		}
	}
	//afisam cuvintele
	for (const auto& pair : myMap) {
		cout << "cuvantul: " << pair.first << " apare de " << pair.second << " ori;" << '\n';
	}
	
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
	for (const auto& pair : myMap) {
		myQueue.push(make_pair(pair.first, pair.second));
	}
	printf("\nSortate\n");
	while (!myQueue.empty())
	{
		
		cout << myQueue.top().first << " => " << myMap[myQueue.top().first] << '\n';
		myQueue.pop();
	}
	
	
};