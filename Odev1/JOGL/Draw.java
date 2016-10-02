package Main;

import java.util.ArrayList;

import javax.swing.JFrame;

import com.jogamp.opengl.GL2;
import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.GLCapabilities;
import com.jogamp.opengl.GLEventListener;
import com.jogamp.opengl.GLProfile;
import com.jogamp.opengl.awt.GLCanvas;
import com.jogamp.opengl.util.gl2.GLUT;

public class Draw implements GLEventListener {
	private static int[] arrstatic;
	private static int[] arrpoints;
	private static float[][] cordinates;
	private static ArrayList<int[]> arrList;

	public void drawLetters(GL2 gl, String string, float x, float y) {

		gl.glColor3f(0.0f, 1.0f, 0f);
		gl.glRasterPos2f(x, y); // <-- position of text

		GLUT glut = new GLUT();

		glut.glutBitmapString(GLUT.BITMAP_HELVETICA_12, string);

	}

	@Override
	public void display(GLAutoDrawable drawable) {
		final GL2 gl = drawable.getGL().getGL2();

		// reset
		gl.glLoadIdentity();

		gl.glColor3f(1.0f, 1.0f, 1.0f);

		String string = "a";
		char letter = 'a';

		// set size to 1 for a group of points
		gl.glPointSize(5);
		gl.glBegin(GL2.GL_POINTS);
		for (int i = 0; i < arrpoints.length; i++) {
			letter = (char) ('a' - arrpoints[i] + arrpoints.length - 1);
			string = "" + letter;
			gl.glBegin(GL2.GL_POINTS);
			gl.glVertex2f((float) (cordinates[arrpoints[i]][0]), (float) (cordinates[arrpoints[i]][1]));
			gl.glEnd();
			drawLetters(gl, string, (float)((cordinates[arrpoints[i]][2])) , (float) ((cordinates[arrpoints[i]][3])));
			gl.glColor3f(1.0f, 1.0f, 1.0f);
		}
		// gl.glFlush();

		gl.glEnable(GL2.GL_LINE_SMOOTH);
		gl.glHint(GL2.GL_LINE_SMOOTH_HINT, GL2.GL_NICEST);
		gl.glBegin(GL2.GL_LINES);

		int first = 0;
		for (int i = arrstatic.length - 1; i >= 0; i--) {
			if (arrstatic[i] == 0) {

			} else {
				int last = arrstatic.length - 1;
				int[] myString = new int[arrstatic[last]];
				myString = arrList.get(first);
				for (int k = 0; k < myString.length; k++) {
					gl.glBegin(GL2.GL_LINES);
					gl.glVertex2f((float) (cordinates[arrpoints[i]][0]), (float) (cordinates[arrpoints[i]][1]));
					gl.glVertex2f((float) (cordinates[myString[k]][0]), (float) (cordinates[myString[k]][1]));
					gl.glEnd();
				}
				System.out.print("\n");
				last--;
				first++;

			}
		}
		gl.glFlush();
	}

	@Override
	public void dispose(GLAutoDrawable arg0) {
		// method body
	}

	@Override
	public void init(GLAutoDrawable arg0) {
		// method body
	}

	@Override
	public void reshape(GLAutoDrawable arg0, int arg1, int arg2, int arg3, int arg4) {
		// method body
	}

	public static void Graph(float[][] cordinates, int[] arrstatic, ArrayList<int[]> arrList, int[] arrpoints) {

		Draw.cordinates = cordinates;
		Draw.arrstatic = arrstatic;
		Draw.arrList = arrList;
		Draw.arrpoints = arrpoints;

		// getting the capabilities object of GL2 profile
		final GLProfile profile = GLProfile.get(GLProfile.GL2);
		GLCapabilities capabilities = new GLCapabilities(profile);

		// The canvas
		final GLCanvas glcanvas = new GLCanvas(capabilities);
		Draw l = new Draw();
		glcanvas.addGLEventListener((GLEventListener) l);
		glcanvas.setSize(1280, 720);

		// creating frame
		final JFrame frame = new JFrame("Graph");

		// adding canvas to frame
		frame.getContentPane().add(glcanvas);

		frame.setSize(frame.getContentPane().getPreferredSize());
		frame.setVisible(true);

	}
}
