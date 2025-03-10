#include <GL/glut.h>

void GambarKubus() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    
    float cubes[5][4][2] = {
        {{-0.6, -0.6}, {-0.4, -0.6}, {-0.4, -0.4}, {-0.6, -0.4}}, 
        {{-0.2, -0.6}, {0.0, -0.6}, {0.0, -0.4}, {-0.2, -0.4}},   
        {{0.2, -0.6}, {0.4, -0.6}, {0.4, -0.4}, {0.2, -0.4}},    
        {{-0.4, -0.4}, {-0.2, -0.4}, {-0.2, -0.2}, {-0.4, -0.2}}, 
        {{0.0, -0.4}, {0.2, -0.4}, {0.2, -0.2}, {0.0, -0.2}},     
    };
    
    for (int i = 0; i < 5; i++) {
        glBegin(GL_QUADS);
        for (int j = 0; j < 4; j++) {
            glVertex2f(cubes[i][j][0], cubes[i][j][1]);
        }
        glEnd();
    }
    
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Gambar Kubus Bertingkat");
    glutDisplayFunc(GambarKubus);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}

