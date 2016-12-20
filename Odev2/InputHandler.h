#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int getKruskalVertexNumber(){
	int vertexNumber = 0;
	std::cout << "Kac koseli cizgeyi inceleyecekseniz girin." << std::endl;
	std::cin >> vertexNumber;
	return vertexNumber;
}

int ** getKruskalInput(int vertexNumber){
	int** Graph;
	Graph = new int*[vertexNumber];
	for (int h = 0; h < vertexNumber; h++)
	{
		Graph[h] = new int[vertexNumber];

		for (int w = 0; w < vertexNumber; w++)
		{
			Graph[h][w] = 0;
		}
	}

	std::cout << "Lutfen her satirda bir kirisi 'kose1 kose2 agirlik'\n ex : 'a b 5' seklinde girin '- 1 for finishin'" << std::endl;

	bool getInput = true;
	while (getInput)
	{
		char a, b;
		int c;
		std::cin >> a;
		std::cin >> b;
		if ((a == '-' && b == '1')){
			getInput = false;
			break;
		}
		std::cin >> c;

		if ((a <= 'z' && a >= 'a') && (b <= 'z' && b >= 'a')){
			int v1 = (int)(a - 'a');
			int v2 = (int)(b - 'a');
			Graph[v1][v2] = c;
			Graph[v2][v1] = c;
		}
		else if ((a <= 'Z' && a >= 'Z') && (b <= 'Z' && b >= 'A')){
			int v1 = (int)(a - 'A');
			int v2 = (int)(b - 'A');
			Graph[v1][v2] = c;
			Graph[v2][v1] = c;
		}
	}

	return Graph;
}