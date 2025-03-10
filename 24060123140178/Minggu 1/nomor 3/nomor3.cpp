#include <GL/glut.h>

void GambarKubus() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    float colors[5][3] = {
        {1.0f, 0.0f, 0.0f}, // Merah
        {0.0f, 1.0f, 0.0f}, // Hijau
        {0.0f, 0.0f, 1.0f}, // Biru
        {1.0f, 1.0f, 0.0f}, // Kuning
        {1.0f, 0.0f, 1.0f}  // Ungu
    };
    
    float cubes[5][4][2] = {
        {{-0.6, -0.6}, {-0.4, -0.6}, {-0.4, -0.4}, {-0.6, -0.4}}, // Bawah kiri
        {{-0.2, -0.6}, {0.0, -0.6}, {0.0, -0.4}, {-0.2, -0.4}},   // Bawah tengah kiri
        {{0.2, -0.6}, {0.4, -0.6}, {0.4, -0.4}, {0.2, -0.4}},     // Bawah tengah kanan
        {{-0.4, -0.4}, {-0.2, -0.4}, {-0.2, -0.2}, {-0.4, -0.2}}, // Atas kiri
        {{0.0, -0.4}, {0.2, -0.4}, {0.2, -0.2}, {0.0, -0.2}},     // Atas kanan
    };
    
    glPushMatrix();
    glRotatef(15, 0.0f, 0.0f, 1.0f); // Rotasi kubus agar terlihat lebih menarik
    
    for (int i = 0; i < 5; i++) {
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        glBegin(GL_QUADS);
        for (int j = 0; j < 4; j++) {
            glVertex2f(cubes[i][j][0], cubes[i][j][1]);
        }
        glEnd();
    }
    
    glPopMatrix();
    glFlush();
}

void Init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Perspektif lebih luas
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Gambar Kubus Bertingkat Kreatif");
    glutDisplayFunc(GambarKubus);
    Init();
    glutMainLoop();
    return 0;
}

