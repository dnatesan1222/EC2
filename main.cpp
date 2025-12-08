// COMSC-210 | Extra Credit 2 | Diksha Tara Natesan
// IDE used: Vim/Terminal

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <list>
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
	/* Milestone 1
	for (auto it = ratings.begin(); it != ratings.end(); it++){
		cout << "Movie: " << it->first << "\n\tRatings:  ";
		for (const int &i : it->second)
			cout << i << "  ";
		cout << endl << endl;
	} */
	list<double> avg;
	double total = 0;
	double count = 0;
	for (auto it = ratings.begin(); it != ratings.end(); it++){
		for (const int &i : it->second){
			total += i;
			count += 1;
		}
		avg.push_back(total/count)
		count = 0;
		total = 0;
	}

}
