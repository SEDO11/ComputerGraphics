//리셰이프 콜백
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

//그래픽의 왜곡현상 방지
void MyReshape(int NewWidth, int NewHeight) {
    glViewport(0, 0, NewWidth, NewHeight);
    //화면의 길이가 달라져도 그래픽의 크기가 유지되게 해줌
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor,
        -1.0, 1.0);
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
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}