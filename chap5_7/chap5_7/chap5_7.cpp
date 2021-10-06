/*
* 책 코딩
//마우스 콜백
#include<gl/glut.h>
#include<gl/GL.h>
#include<gl/GLU.h>
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
void MyDisplay()
{
    glViewport(0, 0, 300, 300);
    //gl 함수를 통해 그림
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    //4개의 꼭짓점을 감싼다
    glVertex3f(TopLeftX/300.0,(300- TopLeftY)/300, 0.0);
    glVertex3f(TopLeftX / 300.0, (300 - BottomRightY) / 300, 0.0);
    glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300, 0.0);
    glVertex3f(BottomRightX / 300.0, (300 - TopLeftY) / 300, 0.0);

    glEnd();
    glFlush();
}

void MyMouseClick(GLint Buttom, GLint State, GLint X, GLint Y) {
    if (Buttom == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
    }
}

//키보드
void MyMouseMove(GLint X, GLint Y) {
    BottomRightX = X;
    BottomRightY = Y;
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
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);
    glutMainLoop();
    return 0;
}
*/

//인터넷에서 찾은 코드
#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include <stdlib.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;//1
GLint RotFlag = 0; // 회전 플래그
GLfloat WinHeight, WinWidth;

void JMDisplay() { //디스플레이 콜백 함수
    glClear(GL_COLOR_BUFFER_BIT);  // GL 상태변수 설정
    //glViewport(0, 0, 700,700);
    glColor3f(1.0, 0.0, 0.0); //물체의 색
    glBegin(GL_POLYGON);   // 기본 입력 요소 정의
    glVertex3f((float)TopLeftX / WinWidth, (float)(WinHeight - TopLeftY) / WinHeight, 0.0);//2
    glVertex3f((float)TopLeftX / WinWidth, (float)(WinHeight - BottomRightY) / WinHeight, 0.0);
    glVertex3f((float)BottomRightX / WinWidth, (float)(WinHeight - BottomRightY) / WinHeight, 0.0);
    glVertex3f((float)BottomRightX / WinWidth, (float)(WinHeight - TopLeftY) / WinHeight, 0.0);

    glEnd();

    glFlush();
}
void JMMouseClick(GLint Button, GLint State, GLint X, GLint Y) {//3
    glutPostRedisplay();
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        printf("%d,,,%d\n", X, Y);
        TopLeftX = X;
        TopLeftY = Y;

    }

}
void JMMouseMove(GLint X, GLint Y) {//4
    printf("move:%d,,,%d\n", X, Y);
    BottomRightX = X;
    BottomRightY = Y;

}

void JMKeyboard(unsigned char KeyPressed, int x, int y) {
    switch (KeyPressed) {

    case 'Q':
        exit(0); break; //exit()는 stdlib에 있음
    case 'q':
        exit(0); break;
    case '27':  //'esc'의 아스키 코드값
        exit(0); break;
    }

}
void JMIdle() {
    //glutPostRedisplay();//화면을 다시 그려주기 
}
void JMReshape(int NewWidth, int NewHeight) {
    WinHeight = NewHeight; //현재의 윈도우 크기를 반환 
    WinWidth = NewWidth;
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;//
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
    glMatrixMode(GL_PROJECTION);   //
    glLoadIdentity();
    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);//5
}
void main(int argc, char** argv) {
    glutInit(&argc, argv);     //GLUT 윈도우 함수
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(700, 700);   //윈도우 크기
    glutInitWindowPosition(120, 55);   //0,0위치에 윈도우 
    glutCreateWindow("OpenGL JM's Window"); //GLUT에게 새로운 위도우를 생성하라는 명령
    glClearColor(1.0, 1.0, 1.0, 1.0);  // GL 상태변수 설정 

    glutDisplayFunc(JMDisplay);// MyDisplay라는 함수를 디스플레이 이벤트에 대한 콜백함수로 등록
    glutReshapeFunc(JMReshape);
    glutKeyboardFunc(JMKeyboard);
    glutMouseFunc(JMMouseClick);//6
    glutMotionFunc(JMMouseMove);//7
    glutIdleFunc(JMIdle);//아이들 콜백 
    glutMainLoop(); // 메인함수의 마지막 
}