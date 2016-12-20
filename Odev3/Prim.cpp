#include "InputHandler.h"
#include "PrimHandler.h"

int main(int* argc, char **argv)
{
	InputHandler iohandler;
	int vertexNumber = iohandler.getSetprimVertexNumber();
	int** Graph = iohandler.getprimInput();
	int baslangic = iohandler.getBeginingVertex();
	PrimHandler p;
	p.setPrim(vertexNumber, Graph, baslangic);
	p.startPrim();
	return 0;
}

