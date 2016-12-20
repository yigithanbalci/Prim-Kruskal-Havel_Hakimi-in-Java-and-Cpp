#ifndef PRIMHANDLER_H
#define PRIMHANDLER_H
#include <vector>
class PrimHandler
{
private:
	int ** Graph;
	int ** prim_Graph;
	int vertexNumber;
	int baslangic;
	int u, v;
	std::vector<std::pair<int, std::pair<int, int>>> kirisler;
	std::vector<std::pair<int, std::pair<int, int>>> MST;
	std::vector<std::vector<int>> kumeler;
	std::vector<std::pair<int, std::pair<int, int>>>queue;

	typedef std::vector<int> kume;
	std::vector<std::vector<int>> primKume;
public:
	PrimHandler();
	void PrimAlgorithm();
	void initializeMSTMatrix();
	void initializeKirisler();
	void initializeQueue();
	void updateQueue(int v1, int v2);
	std::vector<std::pair<char, std::pair<double, double>>> pointsAndCoordinatesVector3cff();
	static bool compare(const std::pair<int, std::pair<int, int>>&i, const std::pair<int, std::pair<int, int >>&j);
	void startPrim();
	void setPrim(int m_vertexNumber, int ** m_graph, int baslangic);
};
#endif