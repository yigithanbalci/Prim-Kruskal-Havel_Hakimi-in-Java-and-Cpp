#include "PrimHandler.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include "Drawer.h"

#define PI 3.14159265
#define NIL -1
#define INFINITE 2147483647

PrimHandler::PrimHandler()
{

}
void PrimHandler::setPrim(int m_vertexNumber, int** m_graph, int m_baslangic)
{
	vertexNumber = m_vertexNumber;
	Graph = m_graph;
	baslangic = m_baslangic;
}
void PrimHandler::startPrim()
{
	if (vertexNumber == 0) return;
	std::vector<std::pair<char, std::pair<double, double>>> points_and_coordinates = pointsAndCoordinatesVector3cff();
	
	initializeMSTMatrix();

	PrimAlgorithm();

	setGraphType(cizge);
	setPointsAndCoordinates(points_and_coordinates);
	setGraph(Graph);
	setMST(MST);
	setVertexNumber(vertexNumber);

	drawGraph();

	int wait;
	std::cin >> wait;
}

void PrimHandler::PrimAlgorithm(){

	/*for (int i = 0; i < vertexNumber; i++)
	{
		for (int k = 0; k < vertexNumber; k++)
		{
			std::cout << Graph[i][k];
		}
		std::cout << std::endl;
	}*/
	
	initializeQueue();

	while (!queue.empty())
	{
		std::sort(queue.begin(), queue.end(), PrimHandler::compare);
		if (queue.back().second.first != NIL){
			MST.push_back(queue.back());
		}
		int parent = queue.back().first;
		queue.pop_back();

		for (int i = 0; i < vertexNumber; i++)
		{
			if (Graph[parent][i] != 0 && i != parent){
				updateQueue(parent, i);
			}
		}
	}

	std::cout << std::endl;

}

void PrimHandler::updateQueue(int v1, int v2)
{
	for (int i = 0; i < queue.size(); i++)
	{
		if (queue[i].first == v2 && queue[i].second.second > Graph[v1][v2]){
			queue[i].second.first = v1;
			queue[i].second.second = Graph[v1][v2];
			break;
		}
	}
}

void PrimHandler::initializeKirisler(){
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

void PrimHandler::initializeQueue()
{
	for (int i = 0; i < vertexNumber; i++)
	{
		std::pair<int, std::pair<int, int>> aPair;
		if (i != baslangic)
		{
			aPair.first = i;
			aPair.second.first = NIL;
			aPair.second.second = INFINITE;
		}
		else if (i == baslangic)
		{
			aPair.first = i;
			aPair.second.first = NIL;
			aPair.second.second = 0;
		}
		queue.push_back(aPair);
	}
}

void PrimHandler::initializeMSTMatrix(){
	prim_Graph = new int*[vertexNumber];
	for (int h = 0; h < vertexNumber; h++)
	{
		prim_Graph[h] = new int[vertexNumber];

		for (int w = 0; w < vertexNumber; w++)
		{
			prim_Graph[h][w] = 0;
		}
	}
}

std::vector<std::pair<char, std::pair<double, double>>> PrimHandler::pointsAndCoordinatesVector3cff()
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

bool PrimHandler::compare(const std::pair<int, std::pair<int, int>>&i, const std::pair<int, std::pair<int, int >>&j){
	return i.second.second > j.second.second;
}