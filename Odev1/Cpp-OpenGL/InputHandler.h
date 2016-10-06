#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<std::pair<int, char>> inputLineTo2Map()
{
	std::vector<std::pair<int, char>> points_and_degrees;
	std::string input;
	std::vector<int> points;

	std::getline(std::cin, input);
	
	int i = 0;
	int k = 1;
	bool x = true;
	int basamak = 1;
	int sayi = 0;
	for (char& c : input){
		if (c < '9' && c > '0'){
			sayi = (int)(c - '0') + (sayi * basamak);
			i++;
			basamak *= 10;
			x = true;
		}
		if(c == ' ' && k != input.size()){
			if (x){
				points.push_back(sayi);
				basamak = 1;
				sayi = 0;
				x = false;
			}
		}
		else if (k == input.size()){
			points.push_back(sayi);
			basamak = 1;
			sayi = 0;
		}
		k++;
	}

	std::stable_sort(points.begin(), points.end(), std::greater<int>());

	k = 0;
	for (int& i : points){
		points_and_degrees.push_back(std::make_pair(i, (char)('a' + k)));
		k++;
	}
	return points_and_degrees;
}

