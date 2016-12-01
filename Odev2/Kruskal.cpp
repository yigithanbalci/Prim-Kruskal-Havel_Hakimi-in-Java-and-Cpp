#include "InputHandler.h"
#include "Drawer.h"
#include <vector>
#include <algorithm>
#include <math.h>

#define PI 3.14159265

int ** Graph;
int ** Kruskal_Graph;
std::vector<std::pair<int, std::pair<int, int>>> kirisler;
std::vector<std::pair<int, std::pair<int, int>>> MST;
std::vector<std::vector<int>> kumeler;

typedef std::vector<int> kume;
std::vector<std::vector<int>> kruskalKume;

void KruskalAlgorithm(int vertexNumber);
void initializeMSTMatrix(int vertexNumber);
void initializeKirisler(int vertexNumber);
bool compare(const std::pair<int, std::pair<int, int>>&i, const std::pair<int, std::pair<int, int >>&j);
void initializeKume(int vertexNumber);
bool findSet(int u, int v, int vertexNumber);
std::vector<std::pair<char, std::pair<double, double>>> pointsAndCoordinatesVector3cff(int vertexNumber);
void kruskalUnion(int u, int v, int vertexNumber);

void main(int* argcp, char **argv){
	int vertexNumber = getKruskalVertexNumber();
	if (vertexNumber == 0) return;
	std::vector<std::pair<char, std::pair<double, double>>> points_and_coordinates = pointsAndCoordinatesVector3cff(vertexNumber);
	Graph = getKruskalInput(vertexNumber);
	initializeMSTMatrix(vertexNumber);

	KruskalAlgorithm(vertexNumber);

	setGraphType(cizge);
	setPointsAndCoordinates(points_and_coordinates);
	setGraph(Graph);
	setMST(MST);
	setVertexNumber(vertexNumber);

	drawGraph();

	int wait;
	std::cin >> wait;
}

void KruskalAlgorithm(int vertexNumber){
	initializeKirisler(vertexNumber);
	initializeKume(vertexNumber);

	for (unsigned int i = 0; i < kirisler.size(); i++)
	{
		std::cout << kirisler[i].first << " " << kirisler[i].second.first << " " << kirisler[i].second.second << std::endl;
	}
	
	std::stable_sort(kirisler.begin(), kirisler.end(), compare);

	std::cout << std::endl;

	for (unsigned int i = 0; i < kirisler.size(); i++)
	{
		if (findSet(kirisler[i].second.first, kirisler[i].second.second, vertexNumber) == true){
			MST.push_back(kirisler[i]);
		}
	}

	for (unsigned int i = 0; i < vertexNumber; i++){
		for (unsigned int k = 0; k < kruskalKume[i].size(); k++){
			std::cout << kruskalKume[i].at(k) << " ";
		}
		std::cout << std::endl;
	}

	for (unsigned int i = 0; i < MST.size(); i++)
	{
		std::cout << MST[i].first << " " << MST[i].second.first << " " << MST[i].second.second << std::endl;
	}
}

bool findSet(int u, int v, int vertexNumber){
	if (std::equal(kruskalKume[u].begin(), kruskalKume[u].end(), kruskalKume[v].begin())){
		return false;
	}
	else{
		kruskalUnion(u, v, vertexNumber);
		return true;
	}
}

void kruskalUnion(int u, int v, int vertexNumber){
	kruskalKume[u].insert(kruskalKume[u].end(), kruskalKume[v].begin(), kruskalKume[v].end());
	kruskalKume[v] = kruskalKume[u];

	std::sort(kruskalKume[u].begin(), kruskalKume[u].end());
	kruskalKume[u].erase(std::unique(kruskalKume[u].begin(), kruskalKume[u].end()), kruskalKume[u].end());
	std::sort(kruskalKume[v].begin(), kruskalKume[v].end());
	kruskalKume[v].erase(std::unique(kruskalKume[v].begin(), kruskalKume[v].end()), kruskalKume[v].end());

	for (unsigned int i = 0; i < kruskalKume[u].size(); i++){
		int k = kruskalKume[u].at(i);

		kruskalKume[k].insert(kruskalKume[k].end(), kruskalKume[u].begin(), kruskalKume[u].end());

		std::sort(kruskalKume[k].begin(), kruskalKume[k].end());
		kruskalKume[k].erase(std::unique(kruskalKume[k].begin(), kruskalKume[k].end()), kruskalKume[k].end());
	}
}

void initializeKirisler(int vertexNumber){
	for (int i = 0; i < vertexNumber; i++){
		for (int k = i; k < vertexNumber; k++){
			if (Graph[i][k] != 0){
				std::pair<int, std::pair<int, int>> aPair;
				aPair.first = Graph[i][k];
				aPair.second.first = i;
				aPair.second.second = k;

				kirisler.push_back(aPair);
			}
		}
	}
}

void initializeMSTMatrix(int vertexNumber){
	Kruskal_Graph = new int*[vertexNumber];
	for (int h = 0; h < vertexNumber; h++)
	{
		Kruskal_Graph[h] = new int[vertexNumber];

		for (int w = 0; w < vertexNumber; w++)
		{
			Kruskal_Graph[h][w] = 0;
			if (h == w){
				Kruskal_Graph[h][w] = 1;
			}
		}
	}
}

void initializeKume(int vertexNumber){
	for (int i = 0; i < vertexNumber; i++){
		kume k;
		k.push_back(i);
		kruskalKume.push_back(k);
	}
	
}

std::vector<std::pair<char, std::pair<double, double>>> pointsAndCoordinatesVector3cff(int vertexNumber)
{
	std::vector<std::pair<char, std::pair<double, double>>> points_and_coordinates;
	double x = 0;
	double y = 0;
	double angle = 360 / vertexNumber;
	char k = 'a';

	for (unsigned int i = 0; i < vertexNumber; i++){
		x = cos((angle*i)*PI / 180) * 0.5;
		y = sin((angle*i)*PI / 180) * 0.5;
		points_and_coordinates.push_back(std::make_pair(k, std::make_pair(x, y)));
		k++;
	}
	return points_and_coordinates;
}

bool compare(const std::pair<int, std::pair<int, int>>&i, const std::pair<int, std::pair<int, int >>&j){
	return i.first < j.first;
}
