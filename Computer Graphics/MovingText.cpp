#include<gl/glut.h>
#include<iostream>
using namespace std;
string str;
int x1=0, x2=250,j=0;

void myInit() {
	gluOrtho2D(0, 500, 0, 500);
}


void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glRasterPos2i(x1+j*5, x2);
	for (int i = 0; i < str.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	glFlush();
}

void update(int value) {
	j+=1;
	if (x1+j*5 < 500-str.length()*10) {
		glutPostRedisplay();
		glutTimerFunc(100, update, 0);
	}
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Moving Text");
	myInit();
	cout << "Enter a text\n";
	cin >> str;
	glutDisplayFunc(display);
	glutTimerFunc(100, update, 0);
	glutMainLoop();
	return 0;
}