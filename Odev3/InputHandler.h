#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler
{
private:
	int m_vertexNumber;
public:
	InputHandler();
	~InputHandler();
	int getSetprimVertexNumber();
	int ** getprimInput();
	int getBeginingVertex();
};
#endif