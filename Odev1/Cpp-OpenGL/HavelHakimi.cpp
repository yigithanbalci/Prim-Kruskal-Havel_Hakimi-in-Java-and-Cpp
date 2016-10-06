#include <iostream>
#include "InputHandler.h"
#include "DrawGraph.h"
#include <vector>
#include <algorithm>
#include <math.h>

#define PI 3.14159265


std::vector<std::pair<int, char>> sortVector2IntChar(std::vector<std::pair<int, char>> points_and_degrees);
void havelHakimiAlgorithm(std::vector<std::pair<int, char>> points_and_degrees);
std::vector<std::pair<char, std::pair<double, double>>> pointsAndCoordinatesVector3cff(std::vector<std::pair<int, char>> points_and_degrees);
int check(std::vector<std::pair<int, char>> points_and_degrees, int size);
std::vector<std::pair<int, char>> process(std::vector<std::pair<int, char>> points_and_degrees, int size);
std::pair<char, std::vector<char>> neighbor(std::vector<std::pair<int, char>> points_and_degrees, int size);
bool compare(const std::pair<int, char>&i, const std::pair<int, char>&j);

void main(int* argcp, char **argv){
	std::vector<std::pair<int, char>> points_and_degrees;
	int wait;

	points_and_degrees = inputLineTo2Map();

	for (int i = 0; i < points_and_degrees.size(); i++){
		if (points_and_degrees[i].first + i >= points_and_degrees.size()){
			std::cout << "error";
			//std::cin >> wait;
			return;
		}
	}

	std::vector<std::pair<char, std::pair<double, double>>> points_and_coordinates = pointsAndCoordinatesVector3cff(points_and_degrees);
	
	setGraphType(cizge);
	setPointsAndCoordinates(points_and_coordinates);

	havelHakimiAlgorithm(points_and_degrees);
	

	std::cin >> wait;
}

void havelHakimiAlgorithm(std::vector<std::pair<int, char>> points_and_degrees)
{
	std::vector<std::pair<char, std::vector<char>>> points_and_neighbors;

	std::pair<char, std::vector<char>> aPair;

	for (unsigned int i = 0; i < points_and_degrees.size(); i++){
		int a = check(points_and_degrees, i);
		if (points_and_degrees.size() == 1 && points_and_degrees[0].first != 0) a=-1;
		if (a == -1) {
			std::cout << "Bu dizi bir cizgeye ait olamaz.";
			break;
		}
		else if (a == 0) {
			std::cout << "Bu dizi bir cizgeye ait olabilir.";
			drawGraph();
			break;
		}
		else if (a == 1) {
			aPair = neighbor(points_and_degrees, i);
			points_and_neighbors.push_back(aPair);

			/*for (int s = 0; s < points_and_degrees.size(); s++)
			{
				std::cout << points_and_degrees[s].second << " ";
			}
			std::cout << std::endl;*/
			
			points_and_degrees = process(points_and_degrees, i);
			points_and_degrees = sortVector2IntChar(points_and_degrees);
		}
	}

	/*for (unsigned int a = 0; a < points_and_neighbors.size(); a++)
	{
		std::cout << points_and_neighbors[a].first << ": ";
		for (unsigned int b = 0; b < points_and_neighbors[a].second.size(); b++){
			std::cout << points_and_neighbors[a].second[b] << " ";
		}
	}*/

	setPointsAndNeighbors(points_and_neighbors);
	//drawGraph();
}

std::vector<std::pair<int, char>> sortVector2IntChar(std::vector<std::pair<int, char>> points_and_degrees)
{
	std::stable_sort(points_and_degrees.begin(), points_and_degrees.end(), compare);
	/*for (int s = 0; s < points_and_degrees.size(); s++)
	{
		std::cout << points_and_degrees[s].second << " ";
	}
	std::cout << std::endl;

	for (int s = 0; s < points_and_degrees.size(); s++)
	{
		std::cout << points_and_degrees[s].first << " ";
	}
	std::cout << std::endl;*/
	return points_and_degrees;
}

std::vector<std::pair<char, std::pair<double, double>>> pointsAndCoordinatesVector3cff(std::vector<std::pair<int, char>> points_and_degrees)
{
	std::vector<std::pair<char, std::pair<double, double>>> points_and_coordinates;
	double x = 0;
	double y = 0;
	double angle = 360 / points_and_degrees.size();

	for (unsigned int i = 0; i < points_and_degrees.size(); i++){
		x = cos((angle*i)*PI / 180) * 0.5;
		y = sin((angle*i)*PI / 180) * 0.5;
		points_and_coordinates.push_back(std::make_pair(points_and_degrees[i].second, std::make_pair(x, y)));
	}
	return points_and_coordinates;
}

int check(std::vector<std::pair<int, char>> points_and_degrees, int size)
{
	int a = 1;
	int counter = 0;
	for (unsigned int i = size; i < points_and_degrees.size(); i++) {
		if (points_and_degrees[i].first == 0) {
			counter++;
		}
		else if (points_and_degrees[i].first == -1) {
			return -1;
		}
	}
	if (counter == points_and_degrees.size() - size)
		a = 0;

	return a;
}

std::vector<std::pair<int, char>> process(std::vector<std::pair<int, char>> points_and_degrees, int size)
{
	for (int i = size + 1; i <= points_and_degrees[size].first + size; i++){
		/*if (i >= points_and_degrees.size()){
			std::cout << "error";
			return points_and_degrees;
		}*/
		points_and_degrees[i].first -= 1;
	}

	return points_and_degrees;
}

std::pair<char, std::vector<char>> neighbor(std::vector<std::pair<int, char>> points_and_degrees, int size)
{
	std::pair<char, std::vector<char>> neighborarr;
	neighborarr.first = points_and_degrees[size].second;
	
	for (int i = size + 1; i <= points_and_degrees[size].first + size; i++){
		/*if (i >= points_and_degrees.size()){
			std::cout << "error";
			return neighborarr;
		}*/
		neighborarr.second.push_back(points_and_degrees[i].second);
	}
	
	return neighborarr;
}

bool compare(const std::pair<int, char>&i, const std::pair<int, char>&j)
{
	return i.first > j.first;
}
