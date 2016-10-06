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

		glColor3f(1.0f, 1.0f, 1.0f);

		/*glPointSize(5);
		glBegin(GL_POINTS);
		for (int i = 0; i < pointsAndCoordinates.size(); i++) {
			letter = (char)('a' - arrpoints[i] + arrpoints.length - 1);
			string = "" + letter;
			glBegin(GL_POINTS);
			glVertex2f((float)(cordinates[arrpoints[i]][0]), (float)(cordinates[arrpoints[i]][1]));
			glEnd();
			drawLetters(gl, string, (float)((cordinates[arrpoints[i]][2])), (float)((cordinates[arrpoints[i]][3])));
			glColor3f(1.0f, 1.0f, 1.0f);
		}

		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glBegin(GL_LINES);

		int first = 0;
		for (int i = arrstatic.length - 1; i >= 0; i--) {
			if (arrstatic[i] == 0) {

			}
			else {
				int last = arrstatic.length - 1;
				int[] myString = new int[arrstatic[last]];
				myString = arrList.get(first);
				for (int k = 0; k < myString.length; k++) {
					glBegin(GL_LINES);
					glVertex2f((float)(cordinates[arrpoints[i]][0]), (float)(cordinates[arrpoints[i]][1]));
					glVertex2f((float)(cordinates[myString[k]][0]), (float)(cordinates[myString[k]][1]));
					glEnd();
				}
				last--;
				first++;

			}
		}
		glFlush();*/
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
	glutCreateWindow("GLUT bitmap & stroke font example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0, 0, 0);
	glLineWidth(3.0);
	glutDisplayFunc(display);
	//	glutReshapeFunc(reshape);
	glutMainLoop();
}