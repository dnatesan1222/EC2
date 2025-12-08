// COMSC-210 | Extra Credit 2 | Diksha Tara Natesan
// IDE used: Vim/Terminal

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
	map<string, vector<int>> ratings;
	
	ifstream fin("movies.txt");
	if (!fin) {
		cout << "Error: could not open bakerydata.txt" << endl;
		return 1;
	}
	string movie;
	string rating;
	while (fin >> movie >> rating){
		int r = stoi(rating);
		ratings[movie].push_back(r);
	}
	cout << "Movie   \t\tRatings" << endl;
	for (auto it = ratings.begin(); it != ratings.end(); it++){
		cout << "Movie: " << it->first << "\n\tRatings:  ";
		for (const int &i : it->second)
			cout << i << "  ";
		cout << endl << endl;
	}
}
