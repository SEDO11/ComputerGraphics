//메뉴 콜백
#include<gl/glut.h>
#include<gl/GL.h>
#include <gl/GLU.h>

GLboolean IsSphere = true;
void MyDisplay()
{
    //gl 함수를 통해 그림
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    if (IsSphere)
        glutWireSphere(0.2, 15, 15);
    else glutWireTorus(0.1, 0.3, 40, 20);
    glEnd();
    glFlush();
}

//메뉴
void MyMainMenu(int entryID) {
    if (entryID == 1)
        IsSphere = true;
    else if (entryID == 2)
        IsSphere = false;
    else if (entryID == 3)
        exit(0);
    glutPostRedisplay();
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddMenuEntry("Draw Sphere", 1);
    glutAddMenuEntry("Draw Torus", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON); //마우스 오른쪽 버튼 인식
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}