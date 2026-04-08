
#ifdef __APPLE__
    // macOS setup: Silencing deprecation warnings and using the GLUT framework path
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
#else
    // Windows/Linux setup: Using the standard GL path
    #include <GL/glut.h>
#endif

// State variable to toggle between Flag (true) and Logo (false)
bool showFlag = true;

// --- Function to draw the Guyana National Flag ---
void drawFlag() {
    // 1. Base Green Layer (Representing agriculture and forests)
    glBegin(GL_QUADS);
        glColor3ub(0, 158, 73);
        glVertex2f(-0.9f, 0.9f); glVertex2f(0.9f, 0.9f);
        glVertex2f(0.9f, -0.9f); glVertex2f(-0.9f, -0.9f);
    glEnd();

    // 2. White Fimbriation (Large Triangle - Representing rivers and water)
    glBegin(GL_TRIANGLES);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.9f, 0.9f); glVertex2f(0.9f, 0.0f); glVertex2f(-0.9f, -0.9f);
    glEnd();

    // 3. Golden Arrowhead (Yellow Triangle - Representing mineral wealth)
    glBegin(GL_TRIANGLES);
        glColor3ub(252, 209, 22);
        glVertex2f(-0.9f, 0.75f); glVertex2f(0.75f, 0.0f); glVertex2f(-0.9f, -0.75f);
    glEnd();

    // 4. Black Fimbriation (Small Triangle - Representing endurance)
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.9f, 0.9f); glVertex2f(-0.1f, 0.0f); glVertex2f(-0.9f, -0.9f);
    glEnd();

    // 5. Red Triangle (Representing zeal and dynamism)
    glBegin(GL_TRIANGLES);
        glColor3ub(206, 17, 38);
        glVertex2f(-0.9f, 0.75f); glVertex2f(-0.25f, 0.0f); glVertex2f(-0.9f, -0.75f);
    glEnd();
}

// --- Function to draw one 3D-styled quadrant of the logo ---
void drawSingleCube() {
    float gap = 0.05f; // Small center gap for symmetry

    // Front Face (Main Square) - Pure Black
    glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(gap + 0.2f, gap + 0.2f); glVertex2f(gap + 0.7f, gap + 0.2f);
        glVertex2f(gap + 0.7f, gap + 0.7f); glVertex2f(gap + 0.2f, gap + 0.7f);
    glEnd();

    // Left Side Slope (Medium Grey for 3D effect)
    glBegin(GL_QUADS);
        glColor3ub(50, 50, 50);
        glVertex2f(gap + 0.2f, gap + 0.2f); glVertex2f(gap + 0.2f, gap + 0.7f);
        glVertex2f(gap, gap + 0.5f); glVertex2f(gap, gap);
    glEnd();

    // Bottom Slope (Dark Grey for 3D effect)
    glBegin(GL_QUADS);
        glColor3ub(30, 30, 30);
        glVertex2f(gap + 0.2f, gap + 0.2f); glVertex2f(gap + 0.7f, gap + 0.2f);
        glVertex2f(gap + 0.5f, gap); glVertex2f(gap, gap);
    glEnd();

    // White separation lines to highlight the 3D edges
    glColor3ub(255, 255, 255);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP); // Outline for the front square
        glVertex2f(gap + 0.2f, gap + 0.2f); glVertex2f(gap + 0.7f, gap + 0.2f);
        glVertex2f(gap + 0.7f, gap + 0.7f); glVertex2f(gap + 0.2f, gap + 0.7f);
    glEnd();
    glBegin(GL_LINE_STRIP); // Outline for the slopes
        glVertex2f(gap + 0.2f, gap + 0.7f); glVertex2f(gap, gap + 0.5f);
        glVertex2f(gap, gap); glVertex2f(gap + 0.5f, gap);
        glVertex2f(gap + 0.7f, gap + 0.2f);
    glEnd();
}

// --- Function to build the full logo using Mirroring Transformations ---
void drawLogo() {
    glPushMatrix(); drawSingleCube(); glPopMatrix();                           // Top-Right
    glPushMatrix(); glScalef(-1, 1, 1); drawSingleCube(); glPopMatrix();        // Top-Left (Mirror X)
    glPushMatrix(); glScalef(-1, -1, 1); drawSingleCube(); glPopMatrix();       // Bottom-Left (Mirror X & Y)
    glPushMatrix(); glScalef(1, -1, 1); drawSingleCube(); glPopMatrix();        // Bottom-Right (Mirror Y)
}

// --- Display Callback ---
void display() {
    // Dark background for flag, White for logo to ensure contrast
    if (showFlag) glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    else glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    glClear(GL_COLOR_BUFFER_BIT);

    if (showFlag) drawFlag();
    else drawLogo();

    glFlush();
}

// --- Keyboard Interaction Logic ---
void keyboard(unsigned char key, int x, int y) {
    // Press 'F' to show Flag, 'L' to show Logo
    if (key == 'f' || key == 'F') showFlag = true;
    if (key == 'l' || key == 'L') showFlag = false;
    glutPostRedisplay(); // Refresh the screen
}

// --- Main Entry Point ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    // Set window size to match flag's 3:5 aspect ratio
    glutInitWindowSize(1000, 600); 
    
    // Instructions added to the window title for better UX
    glutCreateWindow("OpenGL Flag & Geometric Logo: Press [F] for Flag, [L] for Logo");
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}

/*
 * Refactored by: [Ermiyas Lakew ]
 * Description: Cleaned up code with detailed comments and cross-platform support.
 */
