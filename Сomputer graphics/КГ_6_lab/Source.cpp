#include <windows.h>
#include <GL/glut.h> 


int spin = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0f, -7.0f);
    glRotatef(spin, -1.0f, 0.5f, 0.5f);

    float x[] = { 0.866f, 0.0f, -0.866f, -0.866f,  0.0f,  0.866f };
    float y[] = { 0.5f,   1.0f,  0.5f,   -0.5f,   -1.0f, -0.5f };


    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.6f);
    for (int i = 0; i < 6; ++i)
        glVertex3f(x[i], 1.0f, y[i]);
    glEnd();

    for (int i = 0; i < 6; i += 2)
    {
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.5f);
        glVertex3f(x[i], 1.0f, y[i]);
        glVertex3f(x[i + 1], 1.0f, y[i + 1]);
        glVertex3f((x[i] + x[i + 1]) / 2, -1.0f, (y[i] + y[i + 1]) / 2);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.4f);
    glVertex3f((x[0] + x[1]) / 2, -1.0f, (y[0] + y[1]) / 2);
    glVertex3f(x[1], 1.0f, y[1]);
    glVertex3f(x[2], 1.0f, y[2]);
    glVertex3f((x[2] + x[3]) / 2, -1.0f, (y[2] + y[3]) / 2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.4f);
    glVertex3f((x[2] + x[3]) / 2, -1.0f, (y[2] + y[3]) / 2);
    glVertex3f(x[3], 1.0f, y[3]);
    glVertex3f(x[4], 1.0f, y[4]);
    glVertex3f((x[4] + x[5]) / 2, -1.0f, (y[4] + y[5]) / 2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.4f);
    glVertex3f((x[4] + x[5]) / 2, -1.0f, (y[4] + y[5]) / 2);
    glVertex3f(x[5], 1.0f, y[5]);
    glVertex3f(x[0], 1.0f, y[0]);
    glVertex3f((x[0] + x[1]) / 2, -1.0f, (y[0] + y[1]) / 2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.6f);
    for (int i = 0; i < 6; i += 2)
        glVertex3f((x[i] + x[i + 1]) / 2, -1.0f, (y[i] + y[i + 1]) / 2);
    glEnd();

    Sleep(10);
    glLoadIdentity();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    if (height == 0) height = 1;
    GLfloat aspect = width / height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(-45.0f, aspect, 0.1f, 100.0f);
}

void init() {
    glClearColor(0.3f, 0.3f, 0.4f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void spinDisplay(void)
{
    spin += 1;
    spin %= 360;
    glutPostRedisplay();
}

void mouseClickEvent(int buttom, int state, int x, int y)
{
    switch (buttom)
    {
    case GLUT_LEFT_BUTTON:
    {
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
        break;
    }

    case GLUT_RIGHT_BUTTON:
    {
        if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
        break;
    }
    default:break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Rotation of the Pyramid");
    init();
    glutMouseFunc(mouseClickEvent);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}