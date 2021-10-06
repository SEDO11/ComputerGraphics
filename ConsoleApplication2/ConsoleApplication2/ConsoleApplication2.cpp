//키보드 콜백
#include<gl/glut.h>
#include<gl/GL.h>
#include<gl/GLU.h>

void MyDisplay()
{
    //gl 함수를 통해 그림
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    //4개의 꼭짓점을 감싼다
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);

    glEnd();
    glFlush();
}

//키보드
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case 27: //'esc' 아스키 코드 값
        exit(0); break;
    }
}

//실행 무조건 main이 가장 아래에 있어야 함
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}