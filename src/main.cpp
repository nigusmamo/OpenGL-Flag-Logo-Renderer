
#ifdef __APPLE__
    // macOS setup: Silencing deprecation warnings and using the GLUT framework path
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
#else
    // Windows/Linux setup: Using the standard GL path
    #include <GL/glut.h>
#endif

// --- Global Variables for State and Interaction ---
bool showFlag = true;          // Toggle between Flag (true) and Logo (false)
float rotX = 0.0f, rotY = 0.0f; // Rotation angles for 3D interaction
int lastX, lastY;              // Last mouse positions
bool isDragging = false;       // Mouse click state

// Helper function to draw flag layers with 3D depth
void drawFlagLayer(unsigned char r, unsigned char g, unsigned char b, float z_offset, float (*topFunc)(float), float (*bottomFunc)(float)) {
    float step = 0.05f; 
    glColor3ub(r, g, b);
    glBegin(GL_QUAD_STRIP);
    for (float x = -0.9f; x <= 0.901f; x += step) {
        glVertex3f(x, topFunc(x), z_offset);
        glVertex3f(x, bottomFunc(x), z_offset);
    }
    glEnd();
}

// Flag Boundary Math
float greenTop(float x) { return 0.9f; }
float greenBottom(float x) { return -0.9f; }
float whiteBound(float x) { return 0.9f * (1.0f - (x + 0.9f) / 1.8f); }
float whiteNegBound(float x) { return -0.9f * (1.0f - (x + 0.9f) / 1.8f); }
float yellowBound(float x) { float v = 0.75f * (1.0f - (x + 0.9f) / 1.65f); return (v > 0) ? v : 0; }
float blackBound(float x) { float v = 0.9f * (1.0f - (x + 0.9f) / 0.8f); return (v > 0) ? v : 0; }
float redBound(float x) { float v = 0.75f * (1.0f - (x + 0.9f) / 0.65f); return (v > 0) ? v : 0; }

// --- Function to draw the Guyana National Flag (3D Perspective Version) ---
void drawFlag() {
    // 1. Base Green Layer (Representing agriculture and forests)
    drawFlagLayer(0, 158, 73,    0.001f, greenTop, greenBottom);
    
    // 2. White Fimbriation (Large Triangle - Representing rivers and water)
    drawFlagLayer(255, 255, 255, 0.002f, whiteBound, whiteNegBound);
    
    // 3. Golden Arrowhead (Yellow Triangle - Representing mineral wealth)
    drawFlagLayer(252, 209, 22,  0.003f, yellowBound, [](float x){return -yellowBound(x);});
    
    // 4. Black Fimbriation (Small Triangle - Representing endurance)
    drawFlagLayer(0, 0, 0,       0.004f, blackBound, [](float x){return -blackBound(x);});
    
    // 5. Red Triangle (Representing zeal and dynamism)
    drawFlagLayer(206, 17, 38,   0.005f, redBound, [](float x){return -redBound(x);});
    
    // Backside rendering for full 3D rotation
    drawFlagLayer(255, 255, 255, -0.001f, whiteBound, whiteNegBound);
    drawFlagLayer(252, 209, 22,  -0.002f, yellowBound, [](float x){return -yellowBound(x);});
    drawFlagLayer(0, 0, 0,       -0.003f, blackBound, [](float x){return -blackBound(x);});
    drawFlagLayer(206, 17, 38,   -0.004f, redBound, [](float x){return -redBound(x);});
}

// --- Function to draw one tapered 3D-styled quadrant of the logo ---
void drawSingleCube() {
    // Wide Front Face (Starting at -0.4 to face camera)
    float f_in = 0.22f; float f_out = 0.85f; float fZ = -0.4f; 
    // Narrow Back Face (Receding to 0.3)
    float b_in = 0.01f; float b_out = 0.45f; float bZ = 0.3f;

    // 1. FRONT FACE (Main Square - Pure Black)
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex3f(f_in, f_in, fZ); glVertex3f(f_out, f_in, fZ);
        glVertex3f(f_out, f_out, fZ); glVertex3f(f_in, f_out, fZ);
    glEnd();

    // 2. BACK FACE (Narrower Rear - Dark Grey)
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
        glVertex3f(b_in, b_in, bZ); glVertex3f(b_out, b_in, bZ);
        glVertex3f(b_out, b_out, bZ); glVertex3f(b_in, b_out, bZ);
    glEnd();

    // 3. INNER SLANT (Medium Grey for 3D effect)
    glColor3ub(50, 50, 50);
    glBegin(GL_QUADS);
        glVertex3f(f_in, f_in, fZ); glVertex3f(f_in, f_out, fZ);
        glVertex3f(b_in, b_out, bZ); glVertex3f(b_in, b_in, bZ);
    glEnd();

    // 4. BOTTOM SLANT (Dark Grey for 3D effect)
    glColor3ub(30, 30, 30);
    glBegin(GL_QUADS);
        glVertex3f(f_in, f_in, fZ); glVertex3f(f_out, f_in, fZ);
        glVertex3f(b_out, b_in, bZ); glVertex3f(b_in, b_in, bZ);
    glEnd();

    // 5. TOP & RIGHT SIDES
    glColor3ub(40, 40, 40);
    glBegin(GL_QUADS);
        glVertex3f(f_in, f_out, fZ); glVertex3f(f_out, f_out, fZ);
        glVertex3f(b_out, b_out, bZ); glVertex3f(b_in, b_out, bZ);
    glEnd();
    glColor3ub(20, 20, 20);
    glBegin(GL_QUADS);
        glVertex3f(f_out, f_in, fZ); glVertex3f(f_out, f_out, fZ);
        glVertex3f(b_out, b_out, bZ); glVertex3f(b_out, b_in, bZ);
    glEnd();

    // --- WHITE OUTLINES (Highlighting 3D edges) ---
    glColor3ub(255, 255, 255); glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP); // Outline for front face
        glVertex3f(f_in, f_in, fZ); glVertex3f(f_out, f_in, fZ);
        glVertex3f(f_out, f_out, fZ); glVertex3f(f_in, f_out, fZ);
    glEnd();
    glBegin(GL_LINES); // Perspective connectors
        glVertex3f(f_in, f_in, fZ); glVertex3f(b_in, b_in, bZ);
        glVertex3f(f_out, f_in, fZ); glVertex3f(b_out, b_in, bZ);
        glVertex3f(f_out, f_out, fZ); glVertex3f(b_out, b_out, bZ);
        glVertex3f(f_in, f_out, fZ); glVertex3f(b_in, b_out, bZ);
    glEnd();
}

// --- Function to build the full logo using Mirroring Transformations ---
void drawLogo() {
    glPushMatrix(); drawSingleCube(); glPopMatrix();
    glPushMatrix(); glScalef(-1, 1, 1); drawSingleCube(); glPopMatrix();
    glPushMatrix(); glScalef(-1, -1, 1); drawSingleCube(); glPopMatrix();
    glPushMatrix(); glScalef(1, -1, 1); drawSingleCube(); glPopMatrix();
}

// --- Interaction Callbacks ---
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isDragging = true; lastX = x; lastY = y;
    } else isDragging = false;
}

void motion(int x, int y) {
    if (isDragging) {
        rotY += (x - lastX) * 0.5f; rotX += (y - lastY) * 0.5f;
        lastX = x; lastY = y; glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    // Press 'F' to show Flag, 'L' to show Logo
    if (key == 'f' || key == 'F') { showFlag = true; rotX = 0; rotY = 0; }
    if (key == 'l' || key == 'L') { showFlag = false; rotX = 0; rotY = 0; }
    glutPostRedisplay();
}

// --- Display Callback ---
void display() {
    // Dark background for flag, White for logo to ensure contrast
    if (showFlag) glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    else glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);

    if (showFlag) drawFlag();
    else drawLogo();

    glutSwapBuffers();
}

// --- Main Entry Point ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 600); 
    glutCreateWindow("OpenGL Flag & Logo: Press [F] for Flag, [L] for Logo (Mouse to Rotate)");
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse); glutMotionFunc(motion);
    
    glutMainLoop();
    return 0;
}

/*
 * Refactored by: [Ermiyas Lakew]
 * Description: Cleaned up code with detailed comments and cross-platform support.
 * Bonus Implementation: Add 3D viewing capabilities.
 */
