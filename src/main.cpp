#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

// Global state controller
bool showFlag = true;

void drawFlag() {
    glBegin(GL_QUADS);
        glColor3ub(0, 158, 73);
        glVertex2f(-0.9f, 0.9f); glVertex2f(0.9f, 0.9f);
        glVertex2f(0.9f, -0.9f); glVertex2f(-0.9f, -0.9f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.9f, 0.9f); glVertex2f(0.9f, 0.0f); glVertex2f(-0.9f, -0.9f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub(252, 209, 22);
        glVertex2f(-0.9f, 0.75f); glVertex2f(0.75f, 0.0f); glVertex2f(-0.9f, -0.75f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.9f, 0.9f); glVertex2f(-0.1f, 0.0f); glVertex2f(-0.9f, -0.9f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub(206, 17, 38);
        glVertex2f(-0.9f, 0.75f); glVertex2f(-0.25f, 0.0f); glVertex2f(-0.9f, -0.75f);
    glEnd();
}

void drawSingleCube() {
    float gap = 0.05f;

    glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(gap + 0.2f, gap + 0.2f); glVertex2f(gap + 0.7f, gap + 0.2f);
        glVertex2f(gap + 0.7f, gap + 0.7f); glVertex2f(gap + 0.2f, gap + 0.7f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(50, 50, 50);
        glVertex2f(gap + 0.2f, gap + 0.2f); glVertex2f(gap + 0.2f, gap + 0.7f);
        glVertex2f(gap, gap + 0.5f); glVertex2f(gap, gap);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(30, 30, 30);
        glVertex2f(gap + 0.2f, gap + 0.2f); glVertex2f(gap + 0.7f, gap + 0.2f);
        glVertex2f(gap + 0.5f, gap); glVertex2f(gap, gap);
    glEnd();

    glColor3ub(255, 255, 255);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(gap + 0.2f, gap + 0.2f); glVertex2f(gap + 0.7f, gap + 0.2f);
        glVertex2f(gap + 0.7f, gap + 0.7f); glVertex2f(gap + 0.2f, gap + 0.7f);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex2f(gap + 0.2f, gap + 0.7f); glVertex2f(gap, gap + 0.5f);
        glVertex2f(gap, gap); glVertex2f(gap + 0.5f, gap);
        glVertex2f(gap + 0.7f, gap + 0.2f);
    glEnd();
}

void drawLogo() {
    glPushMatrix(); drawSingleCube(); glPopMatrix(); 
    glPushMatrix(); glScalef(-1, 1, 1); drawSingleCube(); glPopMatrix(); 
    glPushMatrix(); glScalef(-1, -1, 1); drawSingleCube(); glPopMatrix(); 
    glPushMatrix(); glScalef(1, -1, 1); drawSingleCube(); glPopMatrix(); 
}

void display() {
    if (showFlag) glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    else glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if (showFlag) drawFlag();
    else drawLogo();

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'f' || key == 'F') showFlag = true;
    if (key == 'l' || key == 'L') showFlag = false;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600); 
    glutCreateWindow("Guyana Flag & Geometric Logo Renderer");
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}