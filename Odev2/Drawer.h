#include <glut.h>
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
#include <windows.h>

std::vector<std::pair<char, std::pair<double, double>>> pointsAndCoordinates;
int ** GraphOpenGL;
std::vector<std::pair<int, std::pair<int, int>>> MSTOpenGL;
int vertexNumberOpenGL;

enum GraphType {
	cizge,
	katliCizge,
	sozdeCizge,
	yonluCizge,
	yonluKatliCizge,

};

GraphType graphType;

void setGraphType(GraphType graph_type)
{
	graphType = graph_type;
}

void setPointsAndCoordinates(std::vector<std::pair<char, std::pair<double, double>>> points_and_coordinates)
{
	pointsAndCoordinates = points_and_coordinates;
}

void setGraph(int **Graph){
	GraphOpenGL = Graph;
}

void setVertexNumber(int vertexNumber){
	vertexNumberOpenGL = vertexNumber;
}

void setMST(std::vector<std::pair<int, std::pair<int, int>>> MST){
	MSTOpenGL = MST;
}

void
display(void)
{
	if (graphType == cizge){
		glLoadIdentity();

		glPointSize(5);
		glBegin(GL_POINTS);
		for (int i = 0; i < pointsAndCoordinates.size(); i++) {
			glBegin(GL_POINTS);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex2d(pointsAndCoordinates[i].second.first, pointsAndCoordinates[i].second.second);
			glEnd();

			glColor3f(0.0f, 1.0f, 0.0f);
			glRasterPos2f((pointsAndCoordinates[i].second.first) * 1.12, (pointsAndCoordinates[i].second.second) * 1.12); // <-- position of text

			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pointsAndCoordinates[i].first);

			glColor3f(1.0f, 1.0f, 1.0f);
		}

		glLineWidth(1);
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glBegin(GL_LINES);

		//coulda use std::find but this is more easier and basic.
		int first = 0;
		for (int i = 0; i < vertexNumberOpenGL; i++) {
			for (int k = i; k < vertexNumberOpenGL; k++){
				if (GraphOpenGL[i][k] != 0){
					glBegin(GL_LINES);
					glVertex2d(pointsAndCoordinates[i].second.first, pointsAndCoordinates[i].second.second);
					glVertex2d(pointsAndCoordinates[k].second.first, pointsAndCoordinates[k].second.second);

					glEnd();

					int weight = GraphOpenGL[i][k];
					std::cout << weight;
					std::string weightString = std::to_string(weight);
					std::cout << weightString;
							
					glPushMatrix();

					glTranslatef((((pointsAndCoordinates[i].second.first + pointsAndCoordinates[k].second.first) / 2.0) ) * 1.12,
						(((pointsAndCoordinates[i].second.second + pointsAndCoordinates[k].second.second) / 2.0) ) * 1.12, 0);
					glScalef(1.0 / 2500, 1.0 / 2500, 1.0 / 2500);


					double counter = 0.0;
					for (char& weightChar : weightString)
					{
						std::cout << weightChar;

						/*glRasterPos2d((((pointsAndCoordinates[i].second.first + pointsAndCoordinates[k].second.first) / 2.0) + counter) * 1.12,
							(((pointsAndCoordinates[i].second.second + pointsAndCoordinates[k].second.second) / 2.0) + counter) * 1.12); // <-- position of text
							*/
						glutStrokeCharacter(GLUT_STROKE_ROMAN, weightChar);
						counter++;
					}
					glPopMatrix();

				}
			}
		}
		glFlush();

		for (unsigned int i = 0; i < MSTOpenGL.size(); i++){
			glLineWidth(1);
			glEnable(GL_LINE_SMOOTH);
			glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
			glBegin(GL_LINES);
			glColor3f(0.0f, 1.0f, 0.0f);

			Sleep(1500);
			glBegin(GL_LINES);
			glVertex2d(pointsAndCoordinates[MSTOpenGL[i].second.first].second.first, pointsAndCoordinates[MSTOpenGL[i].second.first].second.second);
			glVertex2d(pointsAndCoordinates[MSTOpenGL[i].second.second].second.first, pointsAndCoordinates[MSTOpenGL[i].second.second].second.second);

			glEnd();
			glFlush();
		}
	}
}

void
reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glScalef(1, -1, 1);
	glTranslatef(0, -h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void
drawGraph()
{
	int argc = 1;
	char *argv[1] = { (char*)"Something" };
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Graph Draw");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0, 0, 0);
	glLineWidth(3.0);
	glutDisplayFunc(display);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	//	glutReshapeFunc(reshape);
	glutMainLoop();
}