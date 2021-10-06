#include<gl/glut.h>

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