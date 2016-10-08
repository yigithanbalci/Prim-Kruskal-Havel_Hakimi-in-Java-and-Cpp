#include <glut.h>
#include <vector>

std::vector<std::pair<char, std::pair<double, double>>> pointsAndCoordinates;
std::vector<std::pair<char, std::vector<char>>>  pointsAndNeighbors;

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

void setPointsAndNeighbors(std::vector<std::pair<char, std::vector<char>>>  points_and_neighbors)
{
	pointsAndNeighbors = points_and_neighbors;
}

void drawLetters (){

	/*glColor3f(0.0f, 1.0f, 0f);
	glRasterPos2f(x, y); // <-- position of text
	*/
	//GLUT glut;

	//glut.glutBitmapString(GLUT.BITMAP_HELVETICA_12, string);

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
			glRasterPos2f((pointsAndCoordinates[i].second.first) * 1.12 , (pointsAndCoordinates[i].second.second) * 1.12); // <-- position of text
			
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pointsAndCoordinates[i].first);
			glColor3f(1.0f, 1.0f, 1.0f);
		}

		glLineWidth(1);
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glBegin(GL_LINES);
		
		//coulda use std::find but this is more easier and basic.
		int first = 0;
		for (int i = 0; i < pointsAndNeighbors.size(); i++) {
			for (int k = 0; k < pointsAndNeighbors[i].second.size(); k++){
				glBegin(GL_LINES);
				glVertex2d(pointsAndCoordinates[pointsAndNeighbors[i].first - 'a'].second.first, pointsAndCoordinates[pointsAndNeighbors[i].first - 'a'].second.second);
				glVertex2d(pointsAndCoordinates[pointsAndNeighbors[i].second[k] - 'a'].second.first, pointsAndCoordinates[pointsAndNeighbors[i].second[k] - 'a'].second.second);
				glEnd();
			}
		}
		glFlush();
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
	//	glutReshapeFunc(reshape);
	glutMainLoop();
}