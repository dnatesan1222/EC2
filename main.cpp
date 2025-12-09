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
	//Milestone 1
	for (auto it = ratings.begin(); it != ratings.end(); it++){
		cout << "Movie: " << it->first << "\n\tRatings:  ";
		for (const int &i : it->second)
			cout << i << "  ";
		cout << endl << endl;
	}

	//Milestone 2
	list<double> avg;
	int mov_total = 0;
	double total = 0;
	double count = 0;
	for (auto it = ratings.begin(); it != ratings.end(); it++){
		cout << "Movie: " << it->first << "\n\tRatings:  ";
		for (const int &i : it->second){
			cout << i << "  ";
			total += i;
			count += 1;
		}
		avg.push_back(total/count);
		cout << "\n\tAverage Rating: " << avg.back() << endl << endl;
		count = 0;
		total = 0;
		mov_total += 1;
	}
	cout << "\nTotal number of movies: " << mov_total << endl << endl;

	//Milestone 3
	list<string> best_rated;
	double highest = 0;
	for (auto it = avg.begin(); it != avg.end(); ++it){
        if(*it > highest){
			highest = *it;
			best_rated.clear();
			int i = 0;
			for (auto it2 = ratings.begin(); it2 != ratings.end(); it2++){
				if (i == count){
					best_rated.push_back(it2->first);
					break;
				}
				i += 1;
			}
		} 
		else if (*it == highest){
			int i = 0;
			for (auto it2 = ratings.begin(); it2 != ratings.end(); it2++){
				if (i == count){
					best_rated.push_back(it2->first);
					break;
				}
				i += 1;
			}
		}
		count += 1;
	}
	cout << "Highest Average Rating: " << highest << endl;
	cout << "Movie(s) with Rating " << highest << ":" << endl;
	for (auto it = best_rated.begin(); it != best_rated.end(); it++)
		cout << '\t' << *it << endl;
	cout << endl;
}
