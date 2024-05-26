#include<gl/glut.h>
#include<iostream>
using namespace std;
int h=0,r=0;

void myInit() {
	gluOrtho2D(-250, 250, -250, 500);
}

void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < h; i++) {
		double angle = 0;
		for (int j = 0; j <= 360; j++) {
			angle = (3.14 / 180)* r* j;
			glVertex2i(r*cos(angle), r*sin(angle)+i);
		}
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Cylinder");
	myInit();
	cout << "Enter cylinder height and radius\n";
	cin >> h>>r;
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}