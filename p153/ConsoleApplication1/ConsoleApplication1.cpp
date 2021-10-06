#include "gl/glut.h"
/*
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin

    (GL_POLYGON);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.2f, 0.2f);

    glEnd();
    glFinish();
}

int main(int argc, char** argv)

{
    glutInit(&argc, argv);
    glutCreateWindow
    ("OpenGL");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
*/

//흰색 사각형 그리기 코드
//사각형 그리기
void MyDisplay()
{
    //gl 함수를 통해 그림
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    //4개의 꼭짓점을 감싼다
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);

    glEnd();
    glFlush();
}

//실행
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Drawing Example");
    glutDisplayFunc(MyDisplay);
    glutMainLoop();

    return 0;
}