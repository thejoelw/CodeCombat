#include "robot.h"

void Robot::render()
{
    /*
    float x;
    float y;

    float v;

    float rot;
    float rot_sin;
    float rot_cos;

    unsigned int cell_ax;
    unsigned int cell_zx;
    unsigned int cell_ay;
    unsigned int cell_zy;
    */

    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2i(cell_ax * CELL_SIZE, cell_ay * CELL_SIZE);
    glVertex2i((cell_zx + 1) * CELL_SIZE, cell_ay * CELL_SIZE);
    glVertex2i((cell_zx + 1) * CELL_SIZE, (cell_zy + 1) * CELL_SIZE);
    glVertex2i(cell_ax * CELL_SIZE, (cell_zy + 1) * CELL_SIZE);
    glEnd();

    glTranslatef(x, y, 0.0);
    glRotatef(-rot * 180.0 / M_PI, 0.0, 0.0, 1.0);

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(-ROBOT_WIDTH / 2, -ROBOT_LENGTH / 2);
    glVertex2f( ROBOT_WIDTH / 2, -ROBOT_LENGTH / 2);
    glVertex2f( ROBOT_WIDTH / 2,  ROBOT_LENGTH / 2);
    glVertex2f(-ROBOT_WIDTH / 2,  ROBOT_LENGTH / 2);
    glEnd();

    glPopMatrix();

    /*
    glTranslatef(150.0, 250.0, 0.0);
    glRotatef(rot, 0.0, 0.0, 1.0);
    glTranslatef(-150.0, -250.0, 0.0);

    unsigned int size = 100;

    signed int cx = 100;
    signed int cy = 200;
    signed int mcx = cx + size;
    signed int mcy = cy + size;

    //glBindTexture(GL_TEXTURE_2D, tex);

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    //glColor3f(1.0, 0.0, 1.0);
    glTexCoord2f(0, 0); glVertex2i(cx , cy );
    glTexCoord2f(0, 1); glVertex2i(cx , mcy);
    glTexCoord2f(1, 1); glVertex2i(mcx, mcy);
    glTexCoord2f(1, 0); glVertex2i(mcx, cy );
    glEnd();
    */
}
