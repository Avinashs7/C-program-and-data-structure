

#include<gl/glut.h>
#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> points;

void myInit() {
	gluOrtho2D(0, 500, 0, 500);
}
int roundOf(float val) {
	return (int)(val + 0.5);
}

void DDA(pair<int, int> start, pair<int, int> end) {

	int dx = end.first - start.first, dy = end.second - start.second;
	int steps = 0;
	if (abs(dx) > abs(dy))
		steps = dx;
	else
		steps = dy;
	float xin = (float)dx / (float)steps, yin = (float)dy / (float)steps;
	for (int i = 0; i <= steps; i++) {
		points.push_back({ roundOf(start.first + i * xin),roundOf(start.second + i * yin) });
	}
}

void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2);
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	for(int i=0; i<points.size(); i++)
	glVertex2i(points[i].first, points[i].second);
	glEnd();
	glFlush();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("DDA Algorithm");
	myInit();
	pair<int, int> start, end;
	cout << "Enter starting and ending points of line\n";
	cin >> start.first >> start.second;
	cin >> end.first >> end.second;
	DDA(start, end);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
