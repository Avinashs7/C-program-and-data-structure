#include<gl/glut.h>
#include<iostream>
using namespace std;
int b = 0, w = 0,l=0;

void myInit() {
	gluOrtho2D(0, 500, 0, 500);
}


void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2);
	glColor3f(0, 0, 0);
	for (int i = 0; i < l; i++) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(b+i, w+i);
		glVertex2f(b + b+i, w+i);
		glVertex2f(b + b+i, w + w+i);
		glVertex2f(b+i, w + w+i);
		glEnd();
	}
	glFlush();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Parallel pipette");
	myInit();
	cout << "Enter breadth and width of rectangle\n";
	cin >> b>>w;
	cout << "Enter length of pipette\n";
	cin >> l;
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}