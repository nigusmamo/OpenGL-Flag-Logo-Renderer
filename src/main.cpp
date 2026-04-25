
#ifdef __APPLE__
    // macOS setup: Silencing deprecation warnings and using the GLUT framework path
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
#else
    // Windows/Linux setup: Using the standard GL path
    #include <GL/glut.h>
#endif
#include <math.h> // Required for sine-wave calculations

// --- Global Variables for State and Interaction ---
bool showFlag = true;          // Toggle between Flag (true) and Logo (false)
float rotX = 0.0f, rotY = 0.0f; // Rotation angles for 3D interaction
int lastX, lastY;              // Last mouse positions
bool isDragging = false;       // Mouse click state
float waveTime = 0.0f;         // Time variable for dynamic wave animation

// --- Physics Helper: Anchored Sine-Wave Logic ---
// This ensures the wave is 0 at the pole (x=-0.9) and increases towards the right edge
float getAnchoredWave(float x) {
    float amplitude = 0.07f; // Height of the wave
    float frequency = 4.5f;  // Speed/Number of ripples
    float anchorWeight = (x + 0.9f) / 1.8f; // Physics constraint at the pole
    return sin(x * frequency + waveTime) * amplitude * anchorWeight;
}

// Helper function to draw flag layers with 3D depth and anchored wave animation
void drawFlagLayer(unsigned char r, unsigned char g, unsigned char b, float z_offset, float (*topFunc)(float), float (*bottomFunc)(float)) {
    float step = 0.02f; 
    glColor3ub(r, g, b);
    glBegin(GL_QUAD_STRIP);
    for (float x = -0.9f; x <= 0.901f; x += step) {
        float wave = getAnchoredWave(x);
        glVertex3f(x, topFunc(x) + wave, z_offset + wave);
        glVertex3f(x, bottomFunc(x) + wave, z_offset + wave);
    }
    glEnd();
}

// --- Function to draw the 6-faced Solid Pedestal layers ---
void drawSolidBaseLayer(float size, float height, float yPos) {
    float s = size / 2.0f;
    float h = height / 2.0f;

    // Top Face (Light Silver)
    glColor3ub(220, 220, 220);
    glBegin(GL_QUADS);
        glVertex3f(-s, yPos + h, s); glVertex3f(s, yPos + h, s);
        glVertex3f(s, yPos + h, -s); glVertex3f(-s, yPos + h, -s);
    glEnd();

    // Front & Side Faces (Shaded Silver for 3D volume)
    glColor3ub(180, 180, 180);
    glBegin(GL_QUADS);
        glVertex3f(-s, yPos + h, s); glVertex3f(s, yPos + h, s);
        glVertex3f(s, yPos - h, s); glVertex3f(-s, yPos - h, s);
    glEnd();
    
    glColor3ub(130, 130, 130); // Sides
    glBegin(GL_QUADS);
        glVertex3f(s, yPos + h, s); glVertex3f(s, yPos + h, -s);
        glVertex3f(s, yPos - h, -s); glVertex3f(s, yPos - h, s);
        glVertex3f(-s, yPos + h, s); glVertex3f(-s, yPos + h, -s);
        glVertex3f(-s, yPos - h, -s); glVertex3f(-s, yPos - h, s);
    glEnd();
}

// --- Function to build the 3D Flagpole System ---
void drawFlagpoleSystem() {
    float poleX = -0.72f;

    // 1. Solid Tiered Pedestal (The basement structure)
    glPushMatrix();
    glTranslatef(poleX, -0.92f, 0.0f);
    drawSolidBaseLayer(0.40f, 0.08f, -0.10f);
    drawSolidBaseLayer(0.25f, 0.08f, -0.02f);
    drawSolidBaseLayer(0.12f, 0.08f, 0.06f);
    glPopMatrix();

    // 2. Extra Long Cylindrical Staff (Metallic Silver)
    glPushMatrix();
    glTranslatef(poleX, -0.85f, 0.0f);
    glRotatef(-90, 1, 0, 0); 
    glColor3ub(192, 192, 192);
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, 0.022, 0.022, 1.80, 20, 20);
    glPopMatrix();

    // 3. Silver Sphere Top (Ornament)
    glPushMatrix();
    glTranslatef(poleX, 0.95f, 0.0f);
    glColor3ub(192, 192, 192);
    glutSolidSphere(0.045, 20, 20);
    glPopMatrix();
}

// Flag Boundary Math logic preserved for accuracy
float greenTop(float x) { return 0.9f; }
float greenBottom(float x) { return -0.9f; }
float whiteBound(float x) { return 0.9f * (1.0f - (x + 0.9f) / 1.8f); }
float whiteNegBound(float x) { return -0.9f * (1.0f - (x + 0.9f) / 1.8f); }
float yellowBound(float x) { float v = 0.75f * (1.0f - (x + 0.9f) / 1.65f); return (v > 0) ? v : 0; }
float blackBound(float x) { float v = 0.9f * (1.0f - (x + 0.9f) / 0.8f); return (v > 0) ? v : 0; }
float redBound(float x) { float v = 0.75f * (1.0f - (x + 0.9f) / 0.65f); return (v > 0) ? v : 0; }

// --- Function to draw the Guyana National Flag (3D Animated Version) ---
void drawFlag() {
    drawFlagpoleSystem(); // Render the staff and base first

    glPushMatrix();
    // Attached to the top of the extended pole with realistic scaling
    glTranslatef(-0.355f, 0.58f, 0.0f); 
    glScalef(0.38f, 0.38f, 1.0f);     

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

    // Backside rendering (Physics-synced wave)
    drawFlagLayer(255, 255, 255, -0.001f, whiteBound, whiteNegBound);
    drawFlagLayer(252, 209, 22,  -0.002f, yellowBound, [](float x){return -yellowBound(x);});
    drawFlagLayer(0, 0, 0,       -0.003f, blackBound, [](float x){return -blackBound(x);});
    drawFlagLayer(206, 17, 38,   -0.004f, redBound, [](float x){return -redBound(x);});
    
    glPopMatrix();
}

// --- Function to draw one tapered 3D-styled quadrant of the logo ---
void drawSingleCube() {
    // Wide Front Face and Narrow Back Face logic for Aggressive Perspective
    float f_in = 0.22f; float f_out = 0.85f; float fZ = -0.4f; 
    float b_in = 0.01f; float b_out = 0.45f; float bZ = 0.3f;

    // Front Face (Main Square) - Pure Black
    glColor3ub(0, 0, 0); glBegin(GL_QUADS);
    glVertex3f(f_in, f_in, fZ); glVertex3f(f_out, f_in, fZ);
    glVertex3f(f_out, f_out, fZ); glVertex3f(f_in, f_out, fZ); glEnd();

    // Side and Inner Slant Faces (Shaded Grey for 3D depth)
    glColor3ub(80, 80, 80); glBegin(GL_QUADS); // Back
    glVertex3f(b_in, b_in, bZ); glVertex3f(b_out, b_in, bZ);
    glVertex3f(b_out, b_out, bZ); glVertex3f(b_in, b_out, bZ); glEnd();

    glColor3ub(50, 50, 50); glBegin(GL_QUADS); // Left
    glVertex3f(f_in, f_in, fZ); glVertex3f(f_in, f_out, fZ);
    glVertex3f(b_in, b_out, bZ); glVertex3f(b_in, b_in, bZ); glEnd();

    glColor3ub(30, 30, 30); glBegin(GL_QUADS); // Bottom
    glVertex3f(f_in, f_in, fZ); glVertex3f(f_out, f_in, fZ);
    glVertex3f(b_out, b_in, bZ); glVertex3f(b_in, b_in, bZ); glEnd();

    // White separation lines to highlight the 3D edges
    glColor3ub(255, 255, 255); glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(f_in, f_in, fZ); glVertex3f(f_out, f_in, fZ);
    glVertex3f(f_out, f_out, fZ); glVertex3f(f_in, f_out, fZ); glEnd();
    glBegin(GL_LINES);
    glVertex3f(f_in, f_in, fZ); glVertex3f(b_in, b_in, bZ);
    glVertex3f(f_out, f_in, fZ); glVertex3f(b_out, b_in, bZ);
    glVertex3f(f_out, f_out, fZ); glVertex3f(b_out, b_out, bZ);
    glVertex3f(f_in, f_out, fZ); glVertex3f(b_in, b_out, bZ); glEnd();
}

// --- Function to build the full logo using Mirroring Transformations ---
void drawLogo() {
    glPushMatrix();
    glPushMatrix(); drawSingleCube(); glPopMatrix();
    glPushMatrix(); glScalef(-1, 1, 1); drawSingleCube(); glPopMatrix();
    glPushMatrix(); glScalef(-1, -1, 1); drawSingleCube(); glPopMatrix();
    glPushMatrix(); glScalef(1, -1, 1); drawSingleCube(); glPopMatrix();
    glPopMatrix();
}

// --- Interaction Callbacks ---
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { isDragging = true; lastX = x; lastY = y; }
    else isDragging = false;
}
void motion(int x, int y) {
    if (isDragging) { rotY += (x - lastX) * 0.5f; rotX += (y - lastY) * 0.5f; lastX = x; lastY = y; glutPostRedisplay(); }
}
void timer(int value) { waveTime += 0.1f; glutPostRedisplay(); glutTimerFunc(16, timer, 0); }

// --- Keyboard Interaction Logic ---
void keyboard(unsigned char key, int x, int y) {
    // Press 'F' to show Flag, 'L' to show Logo
    if (key == 'f' || key == 'F') { showFlag = true; rotX = 0; rotY = 0; }
    if (key == 'l' || key == 'L') { showFlag = false; rotX = 0; rotY = 0; }
    glutPostRedisplay();
}

// --- Display Callback ---
void display() {
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
    
    // Instructions added to the window title for better UX
    glutCreateWindow("OpenGL Flag & Geometric Logo: Press [F] for Flag, [L] for Logo (Drag to Rotate)");
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse); glutMotionFunc(motion);
    glutTimerFunc(16, timer, 0); 
    
    glutMainLoop();
    return 0;
}

/*
 * Refactored by: [Ermiyas Lakew]
 * Description: Cleaned up code with detailed comments and cross-platform support.
 * Bonus Implementation: Ultra-Realistic 3D Staff, Solid Pedestal, and Anchored Physics.
 */