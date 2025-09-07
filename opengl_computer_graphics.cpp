#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
using namespace std;
//shuvo
float me = 0.0f;
float v = 2.8f;
float e = 0.3f;
float ma = 1.2f;
float j = 3.2f;
float s = 1.5f;
float u = 0.6f;
float n = 3.0f;
float sx =0.0f;
float sy=0.0f;

float mes = 0.4f;
float vs = 0.9f;
float es = 0.9f;
float mas = 0.4f;
float js = 3.0f;
float ss = 2.4f;
float us = 1.25f;
float ns = 1.1f;

int st[650][2];
float zoom=0.01;
//milton
float _move1 = 0.0f;
float _move2 = 0.0f;
float _sunY = 13.0f;
float _m1 = 0.0f;
float _m2 = 0.0f;
float _m3 = 0.0f;
float _mo1 = 0.0f;
float _mo2 = 0.0f;
bool isBMoving = false;
bool isBVisible = true;
bool isSMoving = false;
bool isSVisible = true;
bool isCMoving = false;
bool isCVisible = true;
bool isCoMoving = false;
bool isCoVisible = true;
//jimmy
int ary[800][2];
float sunPositionY = 50.6f; // Initial position of the sun
float sunSpeed = 0.1f;       // Speed of the sun
float _angle1 = 0.0f;
//float carPosition = -100.0f;  // Initial position of the car
//float carSpeed = 1.0f;        // Speed of the car
bool isDay = true;  // Start with day mode
int nightCounter = 0; // Counter to track the duration of the night
const int nightDuration = 200; // Duration for the night
//siam
float scaleX = 100.0f;
float scaleY = 56.18f;
float siamMove = 0.0f;
float siamMove2 = 0.0f;
float siamMove3 = 0.0f;
float siamMove4 = 0.0;
float siamMove5 = 0.0f;
int currentScene = 0;
float move = 0.0f;
float moonAngle1 = 0.0f, moonAngle2 = 0.0f, moonAngle3 = 0.0f;
float radiusStartX = 51.1204101147212f;
float radiusStartY = 56.18f;
float radiusEndX = 51.2901657984f;
float radiusEndY = -56.18f;
float radiusMidX = 70.0f;
float radiusMidY = 0.0f;
const float INITIAL_VELOCITY = 20.0f;
float siamMove6 = 0.0f;
bool moveRover = false;
float _velocity = INITIAL_VELOCITY;
float _direction2 = 1.0f;
int _direction = 1;
float carPosition = -100.0f;
float carSpeed = 1.0f;
const int numSnowflakes = 100;
struct Snowflake {
    float x;
    float y;
    float speed;
};
//shuvo
void star()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(0.4);
    glBegin(GL_POINTS);
    for (int i = 0; i < 300; i++)
        {
        float x = st[i][0];
        float y = st[i][1];
        glVertex2f(x, y);
        }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1.8);
    glBegin(GL_POINTS);
    for (int i = 300; i < 450; i++)
        {
        float x = st[i][0];
        float y = st[i][1];
        glVertex2f(x, y);
        }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(3.1);
    glBegin(GL_POINTS);
    for (int i = 450; i < 590; i++)
        {
        float x = st[i][0];
        float y = st[i][1];
        glVertex2f(x, y);
        }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0);
    glPushMatrix();
    glTranslated(sx,sy,0);
    glBegin(GL_POINTS);
    for (int i = 590; i < 650; i++)
        {
        float x = st[i][0];
        float y = st[i][1];
        glVertex2f(x, y);
        }
    glEnd();
    glPopMatrix();
}
void drawText(float x, float y, const char* text, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);
    glRasterPos2f(0.0f, 0.0f);

    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    glPopMatrix();
}

void circle(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++) {
        glColor3f(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+xc,y+yc);
    }
    glEnd();
}

void circle1(float radius, float xc, float yc, float r, float g, float b,float rx,float ry,float s,const char* name) {
    float x = rx * cos(s);
    float y = ry * sin(s);
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++) {
        glColor3f(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float xx = r * cos(A);
        float yy = r * sin(A);
        glVertex2f(xx+xc,yy+yc);
    }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(1.5,1.2,name, 5.0f);
    glPopMatrix();
}

void ellipse(float radiusX, float radiusY, float xc, float yc, float r, float g, float b) {
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 200; i++) {
        glColor3f(r, g, b);
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 200;
        float x = radiusX * cos(angle);
        float y = radiusY * sin(angle);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}
void solarSystem()
{
    //star();
    circle(6.5,0.0,0.0,1,1,0); //sun
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(7.0,-1.0,"SUN", 5.0f);


    ellipse(22.36,10.0,0.0,0.0,1,1,1); // Mercury
    ellipse(28.6531,14.0,0.0,0.0,1,1,1); // Venus
    ellipse(35,18.0,0.0,0.0,1,1,1); // Earth
    ellipse(41.328,22.0,0.0,0.0,1,1,1); // Mars
    ellipse(47.707,27.0,0.0,0.0,1,1,1); // Jupiter
    ellipse(54.083,34.0,0.0,0.0,1,1,1); // Saturn
    ellipse(60.465,42.0,0.0,0.0,1,1,1); // Uranus
    ellipse(66.85,48.0,0.0,0.0,1,1,1); // Neptune
    circle1(mes,0.0,0.0,0.5,0.5,0.5,22.36,10.0,me,"Mercury");
    circle1(vs,0.0,0.0,0.586,0.41,0.0977,28.6531,14.0,v,"Venus");
    circle1(es,0.0,0.0,0.157,0.478,0.722,35,18,e,"Earth");
    circle1(mas,0.0,0.0,1,0,0,41.328,22,ma,"Mars");
    circle1(js,0.0,0,0.6,0.412,0.325,47.707,27,j,"Jupiter");
    circle1(ss,0.0,0,0.5255,0.4667,0.3725,54.083,34,s,"Saturn");
    circle1(us,0.0,0,0,1,1,60.465,42,u,"Uranus");
    circle1(ns,0.0,0,0,0,1,66.85,48,n,"Neptune");

    glColor3f(0,1,0);
    drawText(-95,50,"Press 'D' for Planets Distance from Sun", 100.0f);
    glColor3f(0,1,0);
    drawText(-95,45,"Press 'R' for Planets Radius", 100.0f);
    glColor3f(0,1,0);
    drawText(-95,-53,"Press 'H' for Home", 100.0f);
    drawText(-7,-53,"Solar System", 100.0f);
}
void solarSystem1()
{
    //star();
    circle(6.0,0.0,0.0,1,1,0); //sun
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(7.0,-1.0,"SUN", 5.0f);

    glPointSize(1);
    ellipse(22.36,10.0,0.0,0.0,1,1,1); // Mercury
    ellipse(28.6531,14.0,0.0,0.0,1,1,1); // Venus
    ellipse(35,18.0,0.0,0.0,1,1,1); // Earth
    ellipse(41.328,22.0,0.0,0.0,1,1,1); // Mars
    ellipse(47.707,27.0,0.0,0.0,1,1,1); // Jupiter
    ellipse(54.083,34.0,0.0,0.0,1,1,1); // Saturn
    ellipse(60.465,42.0,0.0,0.0,1,1,1); // Uranus
    ellipse(66.85,48.0,0.0,0.0,1,1,1); // Neptune
    circle1(mes,0.0,0.0,0.5,0.5,0.5,22.36,10.0,me,"Mercury");
    circle1(vs,0.0,0.0,0.586,0.41,0.0977,28.6531,14.0,v,"Venus");
    circle1(es,0.0,0.0,0.157,0.478,0.722,35,18,e,"Earth");
    circle1(mas,0.0,0.0,1,0,0,41.328,22,ma,"Mars");
    circle1(js,0.0,0,0.6,0.412,0.325,47.707,27,j,"Jupiter");
    circle1(ss,0.0,0,0.5255,0.4667,0.3725,54.083,34,s,"Saturn");
    circle1(us,0.0,0,0,1,1,60.465,42,u,"Uranus");
    circle1(ns,0.0,0,0,0,1,66.85,48,n,"Neptune");
}
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    glLoadIdentity();
    gluOrtho2D(-100,100,-56.18,56.18);
    glMatrixMode(GL_MODELVIEW);
    star();
    glColor3f(0,1,0);
    drawText(-32,50,"Welcome with joy to uncovering the unknown of our solar family", 100.0f);
    drawText(-15,10,"Press 'E' for Solar System", 100.0f);
    drawText(-6,-10,"Instructor", 100.0f);
    drawText(-13,-13,"Aneem Al Ahsan Rupai", 100.0f);
    drawText(-6,-30,"Designer", 100.0f);
    drawText(-16,-34,"Name                            ID", 100.0f);
    drawText(-26,-38,"Tanbhir Ahamed Shuvo          22-46765-1", 100.0f);
    drawText(-26,-42,"Shanjid Ahmed Jimmy            22-46730-1", 100.0f);
    drawText(-26,-46,"Milton Neogi                            22-46432-1", 100.0f);
    drawText(-26,-50,"M.A Habib Siam                      22-46353-1", 100.0f);
    glutSwapBuffers();
}
void drawScene1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,1,1);
    glLoadIdentity();
    gluOrtho2D(-100,100,-56.18,56.18);
    glMatrixMode(GL_MODELVIEW);
    star();
    glPushMatrix();
    glScaled(zoom,zoom,1);
    if(zoom<1)
    {
        solarSystem1();
    }
    else
    {
        solarSystem();
    }
    glPopMatrix();
    glutSwapBuffers();
}
void drawScene2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,1,1);
    glLoadIdentity();
    gluOrtho2D(-100,100,-56.18,56.18);
    glMatrixMode(GL_MODELVIEW);
    star();
    solarSystem();
    glColor3f(1,1,1);
    drawText(55,50,"Distance of the Planets from the Sun:", 100.0f);
    drawText(65,45,"1. Mercury: 57.9 million km", 100.0f);
    drawText(65,40,"2. Venus: 108.2 million km", 100.0f);
    drawText(65,35,"3. Earth: 149.6 million km", 100.0f);
    drawText(65,30,"4. Mars: 227.9 million km", 100.0f);
    drawText(65,25,"5. Jupiter: 778.6 million km", 100.0f);
    drawText(65,20,"6. Saturn: 1.4 billion km", 100.0f);
    drawText(65,15,"7. Uranus: 2.9 billion km", 100.0f);
    drawText(65,10,"8. Neptune: 4.5 billion km", 100.0f);
    glutSwapBuffers();
}
void drawScene3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,1,1);
    glLoadIdentity();
    gluOrtho2D(-100,100,-56.18,56.18);
    glMatrixMode(GL_MODELVIEW);
    star();
    solarSystem();
    glColor3f(1,1,1);
    drawText(55,50,"The Approximate Radius of the Planets:", 100.0f);
    drawText(65,45,"1. Mercury: 2440 km", 100.0f);
    drawText(65,40,"2. Venus: 6052 km", 100.0f);
    drawText(65,35,"3. Earth: 6371 km", 100.0f);
    drawText(65,30,"4. Mars: 3389 km", 100.0f);
    drawText(65,25,"5. Jupiter: 69911 km", 100.0f);
    drawText(65,20,"6. Saturn: 58232 km", 100.0f);
    drawText(65,15,"7. Uranus: 25362 km", 100.0f);
    drawText(65,10,"8. Neptune: 24622 km", 100.0f);

    glutSwapBuffers();
}
//milton
void retangular(float xf, float yf, float af, float bf, float r, float g, float b) {
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex2f(xf, yf);
    glVertex2f(af, yf);
    glVertex2f(af, bf);
    glVertex2f(xf, bf);
    glEnd();
}
void drawRaindrop(float x, float y)
{
    glPointSize(1);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // White color for raindrops
    glVertex2f(x, y);
    glVertex2f(x, y - 2.0f); // Adjust the length of the raindrops as needed
    glEnd();
}


void house()
{
    glBegin(GL_POLYGON);
    glColor3f(0.710f, 0.106f, 0.459f);
    glVertex2f(-92, -1);
    glVertex2f(-92, 30);
    glVertex2f(-82, 35);
    glVertex2f(-82, -1);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);

    glColor3f(0.663f, 0.114f, 0.227f);
    glVertex2f(-82, -0.75);
    glVertex2f(-82, 30);
    glVertex2f(-62, 30);
    glVertex2f(-62, -0.75);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
    glColor3f(0.45f, 0.4f, 0.9);
    for (float y = 3; y <= 28; y += 2)
    {
        glVertex2f(-82, y);
        glVertex2f(-62, y);
    }
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glColor3f(0.710f, 0.106f, 0.459f);
    glVertex2f(-52, -1);
    glVertex2f(-52, 30);
    glVertex2f(-62, 35);
    glVertex2f(-62, -1);
    glEnd();
    glFlush();


}
void house2()
{
    glScalef(1, 1.15, 0.0);
    retangular(-55, -0.05, -35, 40, 1.0, 0.647, 0.0);
    retangular(-51, 3, -47, 38, 1.0f, 0.8f, 0.0f);
    retangular(-39, 3, -43, 38, 1.0f, 0.8f, 0.0f);

}
void house7()
{

    glPushMatrix();
    glTranslatef(23.0f, 0.0f, 0.0f);
    glScalef(0.85, 1.05, 0.0);
    retangular(-55, -0.5, -35, 41.5, 0.404f, 0.247f, 0.412f);
    retangular(-51, 3, -47, 39, 0.843f, 0.294f, 0.463f);
    retangular(-39, 3, -43, 39, 0.843f, 0.294f, 0.463f);
    glPopMatrix();
    glEnd();
    glFlush();
}
void house3()////lasst house
{
    glPushMatrix();
    glTranslatef(28.0f, 0.0f, 0.0f);
    glScalef(0.8, 1.1, 1.0);
    retangular(-36, 30, -16, -1, 0.608f, 0.224f, 0.133f);
    retangular(-34, 4, -18, 2, 0.949f, 0.380f, 0.247f);
    retangular(-34, 8, -18, 6, 1.0f, 0.125f, 0.306f);
    retangular(-34, 12, -18, 10, 0.949f, 0.380f, 0.247f);
    retangular(-34, 16, -18, 14, 1.0f, 0.125f, 0.306f);
    retangular(-34, 20, -18, 18, 0.949f, 0.380f, 0.247f);
    retangular(-34, 24, -18, 22, 1.0f, 0.125f, 0.306f);
    retangular(-34, 28, -18, 26, 0.949f, 0.380f, 0.247f);
    retangular(-34, 32, -18, 30, 1.0f, 0.125f, 0.306f);
    retangular(-32, 34, -20, 32, 1.0, 1.0, 0.878);
    retangular(-30, 36, -22, 34, 1.0, 1.0, 0.2);
    retangular(-28, 38, -24, 36, 1.0f, 0.125f, 0.306f);
    ///triangular(-32, 36, -26, 34, -14, 30, 0.7, 0.75, 0.71); not posible in graph
    glPopMatrix();
    glEnd();
    glFlush();

}
void house8()
{
    glPushMatrix();
    glTranslatef(-7.0f, 0.0f, 0.0f);
    glScalef(0.9, 1.05, 1.0);
    retangular(-36, 30, -16, -1, 1.0, 0.0, 0.0);
    retangular(-34, 4, -18, 2, 1.0, 0.4, 0.35);
    retangular(-34, 8, -18, 6, 1.0, 0.35, 0.25);
    retangular(-34, 12, -18, 10, 1.0, 0.4, 0.35);
    retangular(-34, 16, -18, 14, 1.0, 0.35, 0.25);
    retangular(-34, 20, -18, 18, 1.0, 0.4, 0.35);
    retangular(-34, 24, -18, 22, 1.0, 0.35, 0.25);
    retangular(-34, 28, -18, 26, 1.0, 0.4, 0.35);
    retangular(-34, 32, -18, 30, 1.0, 0.3, 0.2);
    retangular(-32, 34, -20, 32, 1.0, 0.35, 0.25);
    ///triangular(-32, 36, -26, 34, -14, 30, 0.7, 0.75, 0.71); not posible in graph
    glPopMatrix();
    glEnd();
    glFlush();

}
void house4()
{
    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 0.0f);

    retangular(-7, 25, 10, -1.75, 0.5, 0.75, 0.71);
    retangular(-5.5, 27, 5, 25, 0.5, 0.75, 0.71);
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.5f, 0.5f);
    glVertex2f(-7, 25);
    glVertex2f(5, 25);
    glVertex2f(10, -1);
    glVertex2f(5, -1);
    glEnd();
    glFlush();
    retangular(-7, 8, 10, 6, 0.5, 0.75, 0.71);
    retangular(-7, 18, 10, 16, 0.5, 0.75, 0.71);
    glPopMatrix();
    glEnd();
    glFlush();

}

void mou()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.3906f, 0.0f);
    glVertex2f(10, 0);
    glVertex2f(35, 15);
    glColor3f(0.1445f, 0.2539f, 0.08984f);
    glVertex2f(46.8634062475669, 18.108465202192);
    glVertex2f(60, 25);
    glColor3f(0.0f, 0.3906f, 0.0f);
    glVertex2f(90, 0);
    glColor3f(0.203f, 0.4843f, 0.171875f);

    glVertex2f(10, 0);
    glEnd();
    glFlush();

}

void mou2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.3906f, 0.0f);
    glVertex2f(-100, 5);
    glVertex2f(-100, 14);
    glColor3f(0.1445f, 0.2539f, 0.08984f);
    glVertex2f(-90, 17.66);
    glColor3f(0.0f, 0.3906f, 0.0f);
    glVertex2f(-80, 5);
    glEnd();
    glFlush();
}
void mou3()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.3906f, 0.0f);
    glVertex2f(0, 3);
    glVertex2f(19.3920750741426, 17.254805793445);
    glColor3f(0.1445f, 0.2539f, 0.08984f);
    glVertex2f(39.5013562585851, 24.5635998177995);
    glColor3f(0.0f, 0.3906f, 0.0f);
    glVertex2f(50, 26);
    glVertex2f(100, 3);
    glEnd();
    glFlush();
}

void mou1()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.3906f, 0.0f);
    glVertex2f(40, 0);
    glVertex2f(51.4238368447233, 10.1922461436673);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(64.1586241726318, 13.9782639542661);
    glVertex2f(75, 25);
    glColor3f(0.1445f, 0.2539f, 0.08984f);
    glVertex2f(86.0952012942043, 28.08640252794);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(95.2211797494897, 20.7758868414775);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(100, 10);
    glVertex2f(110, 0);
    glEnd();
    glFlush();

}
void car(float r, float g, float b, float r1, float g1, float b1)
{

    //glPushMatrix();
    //glTranslatef(_m1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    ///glColor3f(0.7f, 0.7f, 0.98f);
    glColor3f(r, g, b);
    glVertex2f(-90, -15.5);
    glVertex2f(-70, -15.5);
    glVertex2f(-70, -12);
    glVertex2f(-90, -12);
    glEnd();
    //glFlush();

    glBegin(GL_POLYGON);
    glColor3f(r1, g1, b1);
    glVertex2f(-85.55556, -12);
    glVertex2f(-82, -9);
    glVertex2f(-76, -9);
    glVertex2f(-72.5, -12);
    glEnd();
    //glFlush();
    circle(1.5f, -85.556f, -15.5f, 0.0f, 0.0f, 0.0f);
    circle(1.5f, -75.556f, -15.5f, 0.0f, 0.0f, 0.0f);
    //glPopMatrix();
}
void car2()
{
    glPushMatrix();
    glTranslatef(_m2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.98f);
    glVertex2f(-70, -5.5);
    glVertex2f(-50, -5.5);
    glVertex2f(-50, -2);
    glVertex2f(-70, -2);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.7f, 0.5f);
    glVertex2f(-66.5, -2);
    glVertex2f(-63, 1);
    glVertex2f(-57, 1);
    glVertex2f(-53.5556, -2);
    glEnd();
    glFlush();
    circle(1.5f, -65.556f, -5.5f, 0.0f, 0.0f, 0.0f);
    circle(1.5f, -55.556f, -5.5f, 0.0f, 0.0f, 0.0f);
    glPopMatrix();
}
void cloud() {
    glPushMatrix();
    glTranslatef(_mo1, 0.0f, 0.0f);
    circle(5.0f, -62.2492027617584, 44.7487010818593, 1.0f, 1.0f, 1.0f);
    circle(3.5f, -56, 45.3f, 1.0f, 1.0f, 1.0f);
    circle(3.f, -67.5480115285772, 46.9041487158195, 1.0f, 1.0f, 1.0f);
    glPopMatrix();

}
void cloud1() {
    glPushMatrix();
    glTranslatef(_mo2, 0.0f, 0.0f);
    circle(5.0f, 45, 45, 1.0f, 1.0f, 1.0f);
    circle(4.2f, 38.7058336639857, 46.7327482341064f, 1.0f, 1.0f, 1.0f);
    circle(3.8f, 50.838047209355, 45.95686, 1.0f, 1.0f, 1.0f);
    glPopMatrix();

}
void river() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.67f, 0.937f); // Ocean blue
    glVertex2f(-100, -56.16);
    glVertex2f(100, -56.16);
    glColor3f(0.332f, 0.804f, 1.0f); // Sky blue
    glVertex2f(100, -40);
    glVertex2f(-100, -40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.332f, 0.804f, 1.0f); // Sky blue
    glVertex2f(-100, -40);
    glVertex2f(100, -40);
    //glColor3f(0.449f, 0.84f, 1.0f); // Lighter sky blue
    glColor3f(0.644f, 0.894f, 1.0f);
    glVertex2f(100, -28);
    glVertex2f(-100, -28);
    glEnd();
}

void boat()
{
    glPushMatrix();
    glTranslatef(_move1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.173f, 0.306f, 0.502f);
    glVertex2f(-80, -48.5);
    glVertex2f(-90, -45);
    glVertex2f(-20, -45);
    glVertex2f(-30, -48.5);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.557f, 0.243f, 0.388f);
    glVertex2f(-83, -45);
    glVertex2f(-80, -36);
    glVertex2f(-40, -38);
    glVertex2f(-30, -45);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.824f, 0.392f, 0.604f);
    glVertex2f(-80, -40);
    glVertex2f(-40, -40);
    glVertex2f(-34, -43.5);
    glVertex2f(-80, -43.5);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.557f, 0.243f, 0.388f);
    glVertex2f(-78, -36.5);
    glVertex2f(-76, -28);
    glVertex2f(-50, -30);
    glVertex2f(-42, -38);
    glEnd();
    glFlush();
    glPopMatrix();
}
void feild() {
    retangular(-100, -20, 100, -28, 0.0, 0.5, 0.0);
}
void feild1() {
    retangular(-100, 5, 100, -3, 0.0, 0.5, 0.0);
}
void Rsky()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-100, 5);
    glVertex2f(100, 5);
    glVertex2f(100, 8);
    glVertex2f(-100, 8);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-100, 8);
    glVertex2f(100, 8);
    glColor3ub(86, 86, 86);
    glVertex2f(100, 15);
    glVertex2f(-100, 15);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3ub(86, 86, 86);
    glVertex2f(-100, 15);
    glVertex2f(100, 15);
    glColor3ub(130, 131, 133);
    glVertex2f(100, 30);
    glVertex2f(-100, 30);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3ub(130, 131, 133);
    glVertex2f(-100, 30);
    glVertex2f(100, 30);
    glColor3ub(188, 194, 190);
    glVertex2f(100, 56.16);
    glVertex2f(-100, 56.16);
    glEnd();
    glFlush();


}
void sky()
{
    glBegin(GL_POLYGON);
    glColor3ub(29, 41, 81);
    glVertex2f(-100, 5);
    glVertex2f(100, 5);
    glColor3ub(0, 0, 128);
    glVertex2f(100, 8);
    glVertex2f(-100, 8);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 128);
    glVertex2f(-100, 8);
    glVertex2f(100, 8);
    glColor3ub(16, 70, 163);
    glVertex2f(100, 15);
    glVertex2f(-100, 15);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3ub(16, 70, 163);
    glVertex2f(-100, 15);
    glVertex2f(100, 15);
    glColor3ub(0, 128, 255);
    glVertex2f(100, 30);
    glVertex2f(-100, 30);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 255);
    glVertex2f(-100, 30);
    glVertex2f(100, 30);
    glColor3ub(90, 150, 240);
    glVertex2f(100, 56.16);
    glVertex2f(-100, 56.16);
    glEnd();
    glFlush();

    ///retangular(-100, 17, 100, 34, 0.0, 0.5, 0.998);
   ///retangular(-100, 34, 100, 56.16, 0.0, 0.0, 0.498);
}

void drawDottedLine() {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    for (float x = -100.0f; x < 100.0f; x += 11.0f) {
        glVertex2f(x, -11.5f);
        glVertex2f(x + 5.0f, -11.5f);
    }
    glEnd();

    glDisable(GL_LINE_STIPPLE);
}

void road() {
    retangular(-100, -20, 100, -3, 0.3f, 0.3f, 0.3f);

    drawDottedLine();
}


void boat1() {
    glPushMatrix();
    glTranslatef(_move2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.5);
    glVertex2f(25, -40);
    glVertex2f(15, -35);
    glVertex2f(75, -35);
    glVertex2f(65, -40);
    glEnd();
    glFlush();
    retangular(25, -30, 65, -35, 0.604, 0.804, 0.196);
    retangular(30, -25, 60, -30, 0.510, 0.514, 0.522);
    retangular(35, -21, 55, -25, 0.604, 0.804, 0.196);
    glPopMatrix();
}

void sun() {
    glPushMatrix();
    glTranslatef(68.0f, _sunY, 0.0f);
    circle(5.50f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
    glPopMatrix();
}
////////////////////2nd scene ( rainy)
void drawScene4() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    glMatrixMode(GL_MODELVIEW);
    sky();
    if (isSVisible) {
        glLoadIdentity();
        gluOrtho2D(-100, 100, -56.18, 56.18);
        glMatrixMode(GL_MODELVIEW);

        sun();
    }
    feild1();
    road();
    feild();
    river();
    mou3();
    mou();
    mou1();
    mou2();
    if (isCoVisible)////cloud
    {
        glPushMatrix();
        glTranslatef(_mo1, 0.0f, 0.0f);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef((_mo1)+50, -4.0f, 0.0f);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef((_mo1)-180, -4.0f, 0.0f);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef((_mo1)-210, 1.0f, 0.0f);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef((_mo1)-70, 2.0f, 0.0f);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef((_mo1)-40, -8.0f, 0.0f);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef((_mo1)-110, -7.5f, 0.0f);
        cloud();
        glPopMatrix();
        glPushMatrix();
        glTranslatef((_mo1)+170, -2.0f, 0.0f);
        cloud();
        glPopMatrix();
        cloud1();
    }

    house7();
    house2();
    house();
    house3();
    house4();
    house8();

    if (isBVisible) {
        glLoadIdentity();
        gluOrtho2D(-100, 100, -56.18, 56.18);
        glMatrixMode(GL_MODELVIEW);

        boat1();
        boat();
    }
    if (isCVisible) {
        glLoadIdentity();   ///car
        gluOrtho2D(-100, 100, -56.18, 56.18);
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();
        glTranslatef(_m1, 0.0f, 0.0f);
        car(0.0f, 0.2f, 0.98f, 0.686, 0.863, 0.925f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef((2 * _m1) + 60, 3.f, 0.0f);
        car(0.608, 0.353, 0.706, 1.0, 0.667, 1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef((1.1 * _m3) + 40, 0.f, 0.0f);
        car(1.0, 0.0, 0.0, 1.0, 0.4, 0.4);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(50, 2.f, 0.0f);
        car2();
        glPopMatrix();
        glPushMatrix();

        car2();
    }

    glutSwapBuffers();
}
void drawSceneR() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    glMatrixMode(GL_MODELVIEW);
    Rsky();

    feild1();
    road();
    feild();
    river();
    mou3();
    mou();
    mou1();
    mou2();

    house7();
    house2();
    house();
    house3();
    house4();
    house8();

    if (isBVisible) {
        glLoadIdentity();
        gluOrtho2D(-100, 100, -56.18, 56.18);
        glMatrixMode(GL_MODELVIEW);

        boat1();
        boat();
    }
    if (isCVisible) {
        glLoadIdentity();
        gluOrtho2D(-100, 100, -56.18, 56.18);
        glMatrixMode(GL_MODELVIEW);

        glPushMatrix();
        glTranslatef(_m1, 0.0f, 0.0f);
        car(0.7f, 0.7f, 0.98f, 0.8f, 0.2f, 0.98f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef((2 * _m1) + 60, 3.f, 0.0f);
        car(0.f, 0.f, 0.98f, 0.9f, 0.1f, 0.98f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef((1.1 * _m3) + 40, 0.f, 0.0f);
        car(0.9f, 0.7f, 0.98f, 0.6f, 0.1f, 0.7f);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(50, 2.f, 0.0f);
        car2();
        glPopMatrix();
        glPushMatrix();

        car2();
    }

    for (int i = 0; i < 100; ++i) {
        float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 200.0f - 100.0f; // Random x position between -1 and 1
        float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 200.0f - 100.0f;; // Random y position above the ground
        drawRaindrop(x, y);
    }

    glutSwapBuffers();
}
//jimmy


void setDayColors() {
  glClearColor(1.0f, 0.8f, 0.6f, 1.0f); // Day sky color on Mars

}

void setNightColors() {
    glClearColor(0.078f, 0.094f, 0.322f, 1.0f); // Night sky color on Mars
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1.5);
    glBegin(GL_POINTS);
    for (int i = 0; i < 800; i++)
        {
        float x = ary[i][0];
        float y = ary[i][1];
        glVertex2f(x, y);
        }
    glEnd();
}


void drawWheel(float x, float y) {

    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);
    glTranslatef(-x, -y, 0.0f);

    glLineWidth(7.5);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 300; i++) {
        glColor3f(.63, .63, .63);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 300;
        float r = 2.009;  // Radius of the wheel
        float newX = x + r * cos(A);
        float newY = y + r * sin(A);
        glVertex2f(newX, newY);
    }
    glEnd();

    // Drawing lines inside the circle
    glBegin(GL_LINES);
    glColor3f(.0f, 0.0f, .0f); // Red
    glVertex2f(x - 2.009f, y);     // Left
    glVertex2f(x + 2.009f, y);     // Right
    glVertex2f(x, y - 2.009f);     // Bottom
    glVertex2f(x, y + 2.009f);     // Top
    glEnd();

    glPopMatrix();
}
void rock(){
glBegin(GL_POLYGON);
   glColor3f(0.757,0.412,0.208);
    glVertex2f(-76.34f, -7.11f);
     glVertex2f(-76.24f, -9.98f);
      glVertex2f(-75.0f, -15.0f);
       glVertex2f(-74.14f, -18.31f);
        glVertex2f(-70.69f, -21.18f);
         glVertex2f(-62.85f, -22.13f);
glVertex2f(-55.57f, -18.4f);
  glVertex2f(-53.47f, -13.81f);
   glVertex2f(-53.76f, -7.4f);
    glVertex2f(-56.82f, -2.04f);
     glVertex2f(-65.34f, -.7f);
      glVertex2f(-72.9f, -1.84f);
   glEnd();
    glBegin(GL_POLYGON);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
glVertex2f(-56.82f, -2.04f);
glVertex2f(-53.76f, -7.4f);
glVertex2f(-53.47f, -13.81f);
glVertex2f(-55.57f, -18.4f);
glVertex2f(-62.85f, -22.13f);
glVertex2f(-50.0f, -20.0f);
glVertex2f(-47.0f, -14.98f);
glVertex2f(-47.26f, -9.69f);
glVertex2f(-50.1f, -5.3f);

   glEnd();
}
void _drawRaindrop(float x, float y)
{
    glPointSize(0.5);
    glBegin(GL_LINES);

    glColor3f(.82f, .41f, .12f); // White color for raindrops
    glVertex2f(x, y);
    glVertex2f(x, y - .1f); // Adjust the length of the raindrops as needed
    glEnd();
}


void drawscene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,1,1);
    glLoadIdentity();
    gluOrtho2D(-100,100,-56.18,56.18);
    glMatrixMode(GL_MODELVIEW);   // Clear the color buffer with current clearing color
glLineWidth(1.5);
glBegin(GL_LINES);
glColor3f(.757,.412,.208);
glVertex2f(-100.0f, 20.0f);
glVertex2f(100.0f, 20.0f);
	glEnd();
if (isDay) {
        setDayColors();
    } else {
        setNightColors();
    }

glBegin(GL_POLYGON);         // ground

if (isDay) {
        glColor3f(.804f,.522,.25);
    glVertex2f(-100.0f, 20.0f);
   glVertex2f(100.0f, 20.0f);
    glVertex2f(100.3f, -56.18f);
    glVertex2f(-100.0f, -56.18f);
    glEnd();
    } else {
        glColor3f(.33f,.188,.098);

     glVertex2f(-100.0f, 20.0f);
   glVertex2f(100.0f, 20.0f);
    glVertex2f(100.3f, -56.18f);
    glVertex2f(-100.0f, -56.18f);
    glEnd();
    }
    // Draw the sun with
    rock();
    glPushMatrix();
    glTranslated(10,5,0);
    rock();
    glPopMatrix();
    glPushMatrix();
    glTranslated(120,5,0);
    rock();
    glPopMatrix();
    glPushMatrix();
    glTranslated(85,0,0);
    rock();
    glPopMatrix();
    glPushMatrix();
    glTranslated(75,0,0);
    rock();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, .9f, 0.0f); // Yellow for sun

    // Translate the sun to its position
    glTranslatef(-90.98f, sunPositionY, 0.0f);
    // Apply scaling

    // Draw the sun as a circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 300;
        float r = 5.0; // Radius of the sun
        float newX = r * cos(A);
        float newY = r * sin(A);
        glVertex2f(newX, newY);
    }
    glEnd();
    glPopMatrix();
     // Draw mountains with different colors for day and night
    glBegin(GL_POLYGON);         // 1st mountain(abde)
if (isDay) {
    glColor3f(0.757f, 0.412f, 0.208f); // Brown for day
    glVertex2f(-100.f, 48.72f);
    glVertex2f(-96.01f, 47.41f);
     glColor3f(0.55f, 0.271f, 0.075f); // Brown for day
    glVertex2f(-80.0f, 20.0f);
    glVertex2f(-100.0f, 20.0f);
    glEnd();
}
  else {
       glColor3f(0.722f, 0.53f, 0.043f); // Brown for day
    glVertex2f(-100.f, 48.72f);
    glVertex2f(-96.01f, 47.41f);
     glColor3f(0.55f, 0.271f, 0.075f); // Brown for day
    glVertex2f(-80.0f, 20.0f);
    glVertex2f(-100.0f, 20.0f);
    glEnd();
    }
     glBegin(GL_POLYGON);         // 2nd mountain(bedc)
     if(isDay){
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-96.01f, 47.41f);
    glVertex2f(-100.0f, 20.0f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-80.0f, 20.0f);
    glVertex2f(-90.98f, 42.6f);
    glEnd();
     }
     else {
           glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-96.01f, 47.41f);
    glVertex2f(-100.0f, 20.0f);
    glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-80.0f, 20.0f);
    glVertex2f(-90.98f, 42.6f);
    glEnd();
    }
    glBegin(GL_POLYGON);         // 3rd mountain(cfgjd)
    if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-90.98f, 42.6f);
   glVertex2f(-85.29f, 42.38f);
    glVertex2f(-80.0f, 40.0f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-64.08f, 20.29f);
    glVertex2f(-80.0f, 20.0f);
    glEnd();
    }
    else {
        glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-90.98f, 42.6f);
   glVertex2f(-85.29f, 42.38f);
    glVertex2f(-80.0f, 40.0f);
  glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-64.08f, 20.29f);
    glVertex2f(-80.0f, 20.0f);
    glEnd();
    }

    glBegin(GL_POLYGON);         // 4th mountain(gkll4j)
    if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-80.0f, 40.0f);
   glVertex2f(-74.58f, 42.81f);
    glVertex2f(-64.3f, 40.41f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-50.0f, 20.27f);
    glVertex2f(-64.09f, 20.29f);
    glEnd();
    }
    else {
           glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-80.0f, 40.0f);
   glVertex2f(-74.58f, 42.81f);
    glVertex2f(-64.3f, 40.41f);
     glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-50.0f, 20.27f);
    glVertex2f(-64.09f, 20.29f);
    glEnd();
    }

     glBegin(GL_POLYGON);         // 5th mountain(lmol4)
     if(isDay){
      glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-64.3f, 40.41f);
   glVertex2f(-55.56f, 38.66f);
   glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-43.53f, 43.91f);
     glVertex2f(-50.0f, 20.27f);
    glEnd();
     }
     else {
      glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-64.3f, 40.41f);
   glVertex2f(-55.56f, 38.66f);
   glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-43.53f, 43.91f);
     glVertex2f(-50.0f, 20.27f);
    glEnd();
     }
     glBegin(GL_POLYGON);         // 6th mountain(opqh1l4)
     if(isDay){
            glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-43.53f, 43.91f);
   glVertex2f(-31.95f, 41.5f);
    glVertex2f(-17.08f, 36.47f);
    glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(17.03f, 20.15f);
    glVertex2f(-50.0f, 20.27f);
    glEnd();
     }
     else {
    glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-43.53f, 43.91f);
   glVertex2f(-31.95f, 41.5f);
    glVertex2f(-17.08f, 36.47f);
    glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(17.03f, 20.15f);
    glVertex2f(-50.0f, 20.27f);
    glEnd();
     }
    glBegin(GL_POLYGON);         // 7th mountain(qsum4h1)
    if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-17.08f, 36.47f);
   glVertex2f(-1.56f, 45.44f);
    glVertex2f(25.99f, 35.82f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(35.95f, 20.11f);
    glVertex2f(17.03f, 20.15f);
    glEnd();
    }
    else {
   glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-17.08f, 36.47f);
   glVertex2f(-1.56f, 45.44f);
    glVertex2f(25.99f, 35.82f);
    glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(35.95f, 20.11f);
    glVertex2f(17.03f, 20.15f);
    glEnd();
    }

      glBegin(GL_POLYGON);    // 8th mountain(huvwt1)
      if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
      glVertex2f(17.03f, 20.15f);
     glVertex2f(25.99f, 35.82f);
   glVertex2f(37.58f, 42.6f);
    glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(45.01f, 37.79f);
    glVertex2f(51.65f, 20.0f);
    glEnd();
      }
else {
    glColor3f(0.555f, 0.271f, 0.075f); // for night 1
      glVertex2f(17.03f, 20.15f);
     glVertex2f(25.99f, 35.82f);
   glVertex2f(37.58f, 42.6f);
    glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(45.01f, 37.79f);
    glVertex2f(51.65f, 20.0f);
    glEnd();
}
      glBegin(GL_POLYGON);    // 9th mountain(wzA1t1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
      glVertex2f(35.95f, 20.11f);
     glVertex2f(60.1f, 47.84f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
   glVertex2f(72.78f, 34.94f);
    glVertex2f(51.65f, 20.00f);
    glEnd();
}
else {
   glColor3f(0.555f, 0.271f, 0.075f); // for night 1
      glVertex2f(35.95f, 20.11f);
     glVertex2f(60.1f, 47.84f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
   glVertex2f(72.78f, 34.94f);
    glVertex2f(51.65f, 20.00f);
    glEnd();
}
glBegin(GL_POLYGON);    // 10th mountain(t1a1b1c1f1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
       glVertex2f(51.65f, 20.09f);
     glVertex2f(72.78f, 34.94f);
   glVertex2f(79.34f, 42.81f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(86.34f, 35.6f);
    glVertex2f(100.0f, 20.0f);
    glEnd();
}
else {
   glColor3f(0.555f, 0.271f, 0.075f); // for night 1
       glVertex2f(51.65f, 20.09f);
     glVertex2f(72.78f, 34.94f);
   glVertex2f(79.34f, 42.81f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(86.34f, 35.6f);
    glVertex2f(100.0f, 20.0f);
    glEnd();
}
glBegin(GL_POLYGON);    //11th mountain(f1c1d1e1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(100.0f, 20.0f);
    glVertex2f(86.34f, 35.6f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
   glVertex2f(89.83f, 43.69f);
    glVertex2f(100.00f, 48.72f);
    glEnd();
}
else {
        glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(100.0f, 20.0f);
    glVertex2f(86.34f, 35.6f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
   glVertex2f(89.83f, 43.69f);
    glVertex2f(100.00f, 48.72f);
    glEnd();
}
    glBegin(GL_POLYGON);    //1st small mountain1(A2z1w1g2f2)
    if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-25.82f, 31.23f);
    glVertex2f(-26.7f, 16.8f);
   glVertex2f(-32.82f, 12.2f);
   glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-6.15f, 12.64f);
    glVertex2f(-14.02f, 17.67f);
    glEnd();
    }
    else {
        glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-25.82f, 31.23f);
    glVertex2f(-26.7f, 16.8f);
   glVertex2f(-32.82f, 12.2f);
  glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-6.15f, 12.64f);
    glVertex2f(-14.02f, 17.67f);
    glEnd();
    }

     glBegin(GL_POLYGON);    //1st small mountain2(A2b2c2d2f2)
     if(isDay){
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-25.82f, 31.23f);
    glVertex2f(-23.64f, 43.91f);
   glVertex2f(-18.39f, 46.09f);
    glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-12.71f, 44.34f);
    glVertex2f(-14.02f, 17.67f);
    glEnd();
     }
     else {
  glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-25.82f, 31.23f);
    glVertex2f(-23.64f, 43.91f);
   glVertex2f(-18.39f, 46.09f);
  glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-12.71f, 44.34f);
    glVertex2f(-14.02f, 17.67f);
    glEnd();
     }
glBegin(GL_POLYGON);//2nd small mountain1(j1h1g1p1o1)
if(isDay){
       glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(23.15f, 30.35f);
    glVertex2f(17.03f, 20.15f);
   glVertex2f(22.28f, 11.99f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(36.05f, 11.55f);
    glVertex2f(35.83f, 30.35f);
    glEnd();
}
else{
    glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(23.15f, 30.35f);
    glVertex2f(17.03f, 20.15f);
   glVertex2f(22.28f, 11.99f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(36.05f, 11.55f);
    glVertex2f(35.83f, 30.35f);
    glEnd();
}

glBegin(GL_POLYGON);//2nd small mountain2(j1k1n1o1)
     glVertex2f(23.15f, 30.35f);
    glVertex2f(23.37f, 39.32f);
   glVertex2f(36.49f, 38.66f);
  glVertex2f(35.83f, 30.35f);
    glEnd();

    glBegin(GL_POLYGON);//2nd small mountain3(k1l1m1n1)
    glVertex2f(23.37f, 39.32f);
    glVertex2f(25.56f, 45.22f);
   glVertex2f(33.43f, 45.87f);
  glVertex2f(36.49f, 38.66f);
    glEnd();

     glBegin(GL_POLYGON);//3rd small mountain(q1p1s1r1)
    glVertex2f(35.99f, 17.01f);
    glVertex2f(36.05f, 11.55f);
   glVertex2f(59.88f, 12.2f);
  glVertex2f(44.58f, 26.85f);
    glEnd();


      glBegin(GL_POLYGON);//4th small mountain(q1p1s1r1)
    glVertex2f(51.65f, 20.00f);
    glVertex2f(59.88f, 12.2f);
   glVertex2f(69.28f, 12.2f);
  glVertex2f(68.85f, 27.73f);
    glEnd();

   // glutSwapBuffers();
glBegin(GL_POLYGON);    // 10th mountain(t1a1b1c1f1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
       glVertex2f(51.65f, -36.18f);
     glVertex2f(72.78f, -21.24f);
   glVertex2f(79.34f, -13.37f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(86.34f, -20.58f);
    glVertex2f(100.0f, -36.18f);
    glEnd();
}
else {
   glColor3f(0.555f, 0.271f, 0.075f); // for night 1
       glVertex2f(51.65f, -36.09f);
     glVertex2f(72.78f, -21.24f);
   glVertex2f(79.34f, -13.37f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(86.34f, -20.52f);
    glVertex2f(100.0f, -36.18f);
    glEnd();
}
glBegin(GL_POLYGON);    //11th mountain(f1c1d1e1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(100.0f, -36.18f);
    glVertex2f(86.34f, -20.52f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
   glVertex2f(89.83f, -12.49f);
    glVertex2f(100.00f, -7.46f);
    glEnd();
}
else {
        glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(100.0f, -36.18f);
    glVertex2f(86.34f,-20.52f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
   glVertex2f(89.83f, -12.49f);
    glVertex2f(100.00f, -7.46f);
    glEnd();
}
    glPushMatrix();
    glTranslatef(carPosition, 0.0f, 0.0f);

    if (isDay) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red car for day
    } else {
        glColor3f(0.0f, 1.0f, 0.0f); // Dark red car for night
    }

       glBegin(GL_LINES);

	glVertex2f(-24.09f, -35.05f);
	glVertex2f(11.91f, -34.98f);
	glVertex2f(11.91f, -34.98f);
	glVertex2f(14.96f, -36.93f);
	glVertex2f(-24.09f, -35.05f);
	glVertex2f(-24.09f, -37.84f);
glVertex2f(-20.8f, -35.05f);
glVertex2f(-20.8f, -36.98f);
glVertex2f(-2.15f, -34.96f);
glVertex2f(-2.15f, -39.85f);
glVertex2f(1.31f, -39.27f);
glVertex2f(1.31f, -34.95f);
	glEnd();


    //car1(p2q2r2b3)
    glBegin(GL_POLYGON);
glColor3f(0.753f, .753f, 0.753f); // silver
    glVertex2f(-25.0f, -20.0f);
    glVertex2f(11.96f, -19.98);
    glColor3f(0.502f, 0.502f, 0.502f); //
    glVertex2f(11.96f, -23.01f);
    glVertex2f(-25.05f, -22.96f);
    glEnd();
    // car2(a3s2t2w2z2)
    glBegin(GL_POLYGON);
  glColor3f(0.502f, 0.502f, 0.502f); //
    glVertex2f(-18.98f, -22.9f);
    glVertex2f(7.95f, -23.01f);
    glVertex2f(7.95f, -27.43f);
    glVertex2f(-14.97f, -25.99f);
    glVertex2f(-18.98f, -25.94f);
    glEnd();
    // car3(w2t2u2v2)
    glBegin(GL_POLYGON);
  glColor3f(0.502f, 0.502f, 0.502f); //
    glVertex2f(-14.97f, -25.99f);
   glVertex2f(7.95f, -27.43f);
    glVertex2f(7.89f, -34.93f);
    glVertex2f(-15.0f, -35.00f);
    glEnd();
     // car4(v2n3q3r3)
    glBegin(GL_POLYGON);
glColor3f(0.8f, 0.0f, 0.4f); //
    glVertex2f(-15.0f, -35.0f);
    glVertex2f(-2.0f, -30.0f);
    glVertex2f(-2.01f, -31.04f);
    glVertex2f(-12.55f, -34.99f);
    glEnd();

    // car5(p3o3n3q3)
    glBegin(GL_POLYGON);
glColor3f(0.8f, 0.0f, 0.4f); //
    glVertex2f(4.32f, -34.94f);
    glVertex2f(6.18f, -34.94f);
   glVertex2f(-2.0f, -30.0f);
    glVertex2f(-2.01f, -31.04f);
    glEnd();

    // car6(l2m2n2o2j2)
    glBegin(GL_POLYGON);
if(isDay){
    glColor3f(0.8f, 0.0f, 0.4f); //
    glVertex2f(-.98f, -2.61f);
    glVertex2f(-.99f, -20.04f);
   glVertex2f(2.1f, -19.98f);
    glVertex2f(2.24f, -2.69f);
    glVertex2f(.97f, -4.03f);
    glEnd();
}
else{
     glColor3f(0.6f, 0.0f, 0.298f); //
    glVertex2f(-.98f, -2.61f);
    glVertex2f(-.99f, -20.04f);
   glVertex2f(2.1f, -19.98f);
    glVertex2f(2.24f, -2.69f);
    glVertex2f(.97f, -4.03f);
    glEnd();
}

    // car7(h2k2j2i2)
    glBegin(GL_POLYGON);
    if(isDay){
    glColor3f(.63f,.63,.63);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-1.9f, -1.94f);
   glVertex2f(0.97f, -4.03f);
    glVertex2f(2.85f, -2.05f);
    glEnd();
    }
    else {
    glColor3f(1.0f, 1.0f, 1.0f); //
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-1.9f, -1.94f);
   glVertex2f(0.97f, -4.03f);
    glVertex2f(2.85f, -2.05f);
    glEnd();
    }

      // car8(g3h3c3d3)
    glBegin(GL_POLYGON);
    if(isDay){
glColor3f(0.8f, 0.0f, 0.4f); //
    glVertex2f(-6.26f, -9.98f);
     glVertex2f(-6.26f, -19.99f);
    glVertex2f(-5.0f, -19.99f);
   glVertex2f(-5.0f, -10.0f);
    glEnd();
    }
    else {
            glColor3f(0.6f, 0.0f, 0.298f); //
    glVertex2f(-6.26f, -9.98f);
     glVertex2f(-6.26f, -19.99f);
    glVertex2f(-5.0f, -19.99f);
   glVertex2f(-5.0f, -10.0f);
    glEnd();
    }
    // car9(f3e3d3g3)
    glBegin(GL_POLYGON);

    glVertex2f(-6.87f, -7.14f);
     glVertex2f(-5.64f, -6.22f);
    glVertex2f(-5.0f, -10.0f);
   glVertex2f(-6.26f, -9.98f);
    glEnd();

      // car10(k3l3m3i3j3)
    glBegin(GL_POLYGON);

    glVertex2f(-8.01f, -17.53f);
     glVertex2f(-8.89f, -17.95f);
    glVertex2f(-8.89f, -19.94f);
   glVertex2f(-6.77f, -19.99f);
   glVertex2f(-6.77f, -17.95f);
    glEnd();

    // Draw the wheels
    drawWheel(-24.17f, -39.92f);
    drawWheel(-21.09f, -38.99f);
    drawWheel(-2.12f, -39.85f);
    drawWheel(1.31f, -39.27f);
    drawWheel(15.03f, -39.00f);

    glPopMatrix();
     if (isDay) {
        glColor3f(0.6f, 0.4f, 0.2f); // Brown for day
    } else {
        glColor3f(0.2f, 0.2f, 0.2f); // Dark gray for night
    }

    glBegin(GL_POLYGON);         // 1st mountain(abde)
if(isDay){
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-100.f, -27.46f);
    glVertex2f(-96.01f, -28.77f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-80.0f, -56.18f);
    glVertex2f(-100.0f, -56.18f);
    glEnd();
}
else {
  glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-100.f, -27.46f);
    glVertex2f(-96.01f, -28.77f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-80.0f, -56.18f);
    glVertex2f(-100.0f, -56.18f);
    glEnd();
}
     glBegin(GL_POLYGON);         // 2nd mountain(bedc)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-96.01f, -28.77f);
    glVertex2f(-100.0f, -56.18f);
  glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-80.0f, -56.1f);
    glVertex2f(-90.98f, -33.58f);
    glEnd();
}
else {
glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-96.01f, -28.77f);
    glVertex2f(-100.0f, -56.18f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-80.0f, -56.1f);
    glVertex2f(-90.98f, -33.58f);
    glEnd();
}
glBegin(GL_POLYGON);
glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-68.96f, -45.97f);
     glVertex2f(-80.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-56.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-68.96f, -45.97f);
     glVertex2f(-56.64f, -56.18f);
    glVertex2f(-44.14f, -56.18f);
    glEnd();

glBegin(GL_POLYGON);
glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-50.96f, -45.97f);
     glVertex2f(-60.08f, -56.18f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-36.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-50.96f, -45.97f);
     glVertex2f(-36.64f, -56.18f);
    glVertex2f(-24.14f, -56.18f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-26.96f, -45.97f);
     glVertex2f(-36.08f, -56.18f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(00.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-26.96f, -45.97f);
     glVertex2f(-12.64f, -56.18f);
    glVertex2f(-00.14f, -56.18f);
    glEnd();

glBegin(GL_POLYGON);
glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-2.96f, -45.97f);
     glVertex2f(-12.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(24.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-2.96f, -45.97f);
     glVertex2f(12.64f, -56.18f);
    glVertex2f(24.14f, -56.18f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(22.96f, -45.97f);
     glVertex2f(12.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(48.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(22.96f, -45.97f);
     glVertex2f(36.64f, -56.18f);
    glVertex2f(48.14f, -56.18f);
    glEnd();
     glBegin(GL_POLYGON);
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(46.96f, -45.97f);
     glVertex2f(36.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(72.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(46.96f, -45.97f);
     glVertex2f(60.64f, -56.18f);
    glVertex2f(72.14f, -56.18f);
    glEnd();
     glBegin(GL_POLYGON);
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(70.96f, -45.97f);
     glVertex2f(60.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(96.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(70.96f, -45.97f);
     glVertex2f(84.64f, -56.18f);
    glVertex2f(96.14f, -56.18f);
    glEnd();
    ////////////////////////////////////////////////////
     glBegin(GL_POLYGON);         // 1st mountain(abde)
if(isDay){
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-50.f, -27.46f);
    glVertex2f(-46.01f, -28.77f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-30.0f, -56.18f);
    glVertex2f(-50.0f, -56.18f);
    glEnd();
}
else {
  glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-50.f, -27.46f);
    glVertex2f(-46.01f, -28.77f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-30.0f, -56.18f);
    glVertex2f(-50.0f, -56.18f);
    glEnd();
}
glBegin(GL_POLYGON);         // 2nd mountain(bedc)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-46.01f, -28.77f);
    glVertex2f(-50.0f, -56.18f);
  glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-30.0f, -56.1f);
    glVertex2f(-40.98f, -33.58f);
    glEnd();
}
else {
glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-46.01f, -28.77f);
    glVertex2f(-50.0f, -56.18f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-30.0f, -56.1f);
    glVertex2f(-40.98f, -33.58f);
    glEnd();
}
////////////////////////////////////////////////////

glPushMatrix();
    glTranslated(50,-45,0);
    rock();
    glPopMatrix();
     glPushMatrix();
    glTranslated(80,-44,0);
    rock();
    glPopMatrix();
     glPushMatrix();
    glTranslated(120,-45,0);
    rock();
    glPopMatrix();

    for (int i = 0; i < 10000; ++i) {
        float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 200.0f - 100.0f; // Random x position between -1 and 1
        float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 200.0f - 100.0f;; // Random y position above the ground
        _drawRaindrop(x, y);
    }
    glColor3f(0.0f,1.0f,0.0f);
       drawText(-90.0,50.18,"Press g to stop sandstorm.",10);
    glutSwapBuffers();


}
void drawscene2() {
glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,1,1);
    glLoadIdentity();
    gluOrtho2D(-100,100,-56.18,56.18);
    glMatrixMode(GL_MODELVIEW);  // Clear the color buffer with current clearing color
glLineWidth(1.5);
glBegin(GL_LINES);
glColor3f(.757,.412,.208);
glVertex2f(-100.0f, 20.0f);
glVertex2f(100.0f, 20.0f);
	glEnd();
if (isDay) {
        setDayColors();
    } else {
        setNightColors();
    }

glBegin(GL_POLYGON);         // ground

if (isDay) {
        glColor3f(.804f,.522,.25);
    glVertex2f(-100.0f, 20.0f);
   glVertex2f(100.0f, 20.0f);
    glVertex2f(100.3f, -56.18f);
    glVertex2f(-100.0f, -56.18f);
    glEnd();
    } else {
        glColor3f(.33f,.188,.098);

     glVertex2f(-100.0f, 20.0f);
   glVertex2f(100.0f, 20.0f);
    glVertex2f(100.3f, -56.18f);
    glVertex2f(-100.0f, -56.18f);
    glEnd();
    }
    // Draw the sun with
    rock();
    glPushMatrix();
    glTranslated(10,5,0);
    rock();
    glPopMatrix();
    glPushMatrix();
    glTranslated(120,5,0);
    rock();
    glPopMatrix();
    glPushMatrix();
    glTranslated(85,0,0);
    rock();
    glPopMatrix();
    glPushMatrix();
    glTranslated(75,0,0);
    rock();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, .9f, 0.0f); // Yellow for sun

    // Translate the sun to its position
    glTranslatef(-90.98f, sunPositionY, 0.0f);
    // Apply scaling

    // Draw the sun as a circle
    glBegin(GL_POLYGON);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 300;
        float r = 5.0; // Radius of the sun
        float newX = r * cos(A);
        float newY = r * sin(A);
        glVertex2f(newX, newY);
    }
    glEnd();
    glPopMatrix();
     // Draw mountains with different colors for day and night
    glBegin(GL_POLYGON);         // 1st mountain(abde)
if (isDay) {
    glColor3f(0.757f, 0.412f, 0.208f); // Brown for day
    glVertex2f(-100.f, 48.72f);
    glVertex2f(-96.01f, 47.41f);
     glColor3f(0.55f, 0.271f, 0.075f); // Brown for day
    glVertex2f(-80.0f, 20.0f);
    glVertex2f(-100.0f, 20.0f);
    glEnd();
}
  else {
       glColor3f(0.722f, 0.53f, 0.043f); // Brown for day
    glVertex2f(-100.f, 48.72f);
    glVertex2f(-96.01f, 47.41f);
     glColor3f(0.55f, 0.271f, 0.075f); // Brown for day
    glVertex2f(-80.0f, 20.0f);
    glVertex2f(-100.0f, 20.0f);
    glEnd();
    }
     glBegin(GL_POLYGON);         // 2nd mountain(bedc)
     if(isDay){
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-96.01f, 47.41f);
    glVertex2f(-100.0f, 20.0f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-80.0f, 20.0f);
    glVertex2f(-90.98f, 42.6f);
    glEnd();
     }
     else {
           glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-96.01f, 47.41f);
    glVertex2f(-100.0f, 20.0f);
    glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-80.0f, 20.0f);
    glVertex2f(-90.98f, 42.6f);
    glEnd();
    }
    glBegin(GL_POLYGON);         // 3rd mountain(cfgjd)
    if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-90.98f, 42.6f);
   glVertex2f(-85.29f, 42.38f);
    glVertex2f(-80.0f, 40.0f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-64.08f, 20.29f);
    glVertex2f(-80.0f, 20.0f);
    glEnd();
    }
    else {
        glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-90.98f, 42.6f);
   glVertex2f(-85.29f, 42.38f);
    glVertex2f(-80.0f, 40.0f);
  glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-64.08f, 20.29f);
    glVertex2f(-80.0f, 20.0f);
    glEnd();
    }

    glBegin(GL_POLYGON);         // 4th mountain(gkll4j)
    if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-80.0f, 40.0f);
   glVertex2f(-74.58f, 42.81f);
    glVertex2f(-64.3f, 40.41f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-50.0f, 20.27f);
    glVertex2f(-64.09f, 20.29f);
    glEnd();
    }
    else {
           glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-80.0f, 40.0f);
   glVertex2f(-74.58f, 42.81f);
    glVertex2f(-64.3f, 40.41f);
     glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-50.0f, 20.27f);
    glVertex2f(-64.09f, 20.29f);
    glEnd();
    }

     glBegin(GL_POLYGON);         // 5th mountain(lmol4)
     if(isDay){
      glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-64.3f, 40.41f);
   glVertex2f(-55.56f, 38.66f);
   glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-43.53f, 43.91f);
     glVertex2f(-50.0f, 20.27f);
    glEnd();
     }
     else {
      glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-64.3f, 40.41f);
   glVertex2f(-55.56f, 38.66f);
   glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-43.53f, 43.91f);
     glVertex2f(-50.0f, 20.27f);
    glEnd();
     }
     glBegin(GL_POLYGON);         // 6th mountain(opqh1l4)
     if(isDay){
            glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-43.53f, 43.91f);
   glVertex2f(-31.95f, 41.5f);
    glVertex2f(-17.08f, 36.47f);
    glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(17.03f, 20.15f);
    glVertex2f(-50.0f, 20.27f);
    glEnd();
     }
     else {
    glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-43.53f, 43.91f);
   glVertex2f(-31.95f, 41.5f);
    glVertex2f(-17.08f, 36.47f);
    glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(17.03f, 20.15f);
    glVertex2f(-50.0f, 20.27f);
    glEnd();
     }
    glBegin(GL_POLYGON);         // 7th mountain(qsum4h1)
    if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-17.08f, 36.47f);
   glVertex2f(-1.56f, 45.44f);
    glVertex2f(25.99f, 35.82f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(35.95f, 20.11f);
    glVertex2f(17.03f, 20.15f);
    glEnd();
    }
    else {
   glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-17.08f, 36.47f);
   glVertex2f(-1.56f, 45.44f);
    glVertex2f(25.99f, 35.82f);
    glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(35.95f, 20.11f);
    glVertex2f(17.03f, 20.15f);
    glEnd();
    }

      glBegin(GL_POLYGON);    // 8th mountain(huvwt1)
      if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
      glVertex2f(17.03f, 20.15f);
     glVertex2f(25.99f, 35.82f);
   glVertex2f(37.58f, 42.6f);
    glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(45.01f, 37.79f);
    glVertex2f(51.65f, 20.0f);
    glEnd();
      }
else {
    glColor3f(0.555f, 0.271f, 0.075f); // for night 1
      glVertex2f(17.03f, 20.15f);
     glVertex2f(25.99f, 35.82f);
   glVertex2f(37.58f, 42.6f);
    glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(45.01f, 37.79f);
    glVertex2f(51.65f, 20.0f);
    glEnd();
}
      glBegin(GL_POLYGON);    // 9th mountain(wzA1t1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
      glVertex2f(35.95f, 20.11f);
     glVertex2f(60.1f, 47.84f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
   glVertex2f(72.78f, 34.94f);
    glVertex2f(51.65f, 20.00f);
    glEnd();
}
else {
   glColor3f(0.555f, 0.271f, 0.075f); // for night 1
      glVertex2f(35.95f, 20.11f);
     glVertex2f(60.1f, 47.84f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
   glVertex2f(72.78f, 34.94f);
    glVertex2f(51.65f, 20.00f);
    glEnd();
}
glBegin(GL_POLYGON);    // 10th mountain(t1a1b1c1f1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
       glVertex2f(51.65f, 20.09f);
     glVertex2f(72.78f, 34.94f);
   glVertex2f(79.34f, 42.81f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(86.34f, 35.6f);
    glVertex2f(100.0f, 20.0f);
    glEnd();
}
else {
   glColor3f(0.555f, 0.271f, 0.075f); // for night 1
       glVertex2f(51.65f, 20.09f);
     glVertex2f(72.78f, 34.94f);
   glVertex2f(79.34f, 42.81f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(86.34f, 35.6f);
    glVertex2f(100.0f, 20.0f);
    glEnd();
}
glBegin(GL_POLYGON);    //11th mountain(f1c1d1e1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(100.0f, 20.0f);
    glVertex2f(86.34f, 35.6f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
   glVertex2f(89.83f, 43.69f);
    glVertex2f(100.00f, 48.72f);
    glEnd();
}
else {
        glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(100.0f, 20.0f);
    glVertex2f(86.34f, 35.6f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
   glVertex2f(89.83f, 43.69f);
    glVertex2f(100.00f, 48.72f);
    glEnd();
}
    glBegin(GL_POLYGON);    //1st small mountain1(A2z1w1g2f2)
    if(isDay){
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-25.82f, 31.23f);
    glVertex2f(-26.7f, 16.8f);
   glVertex2f(-32.82f, 12.2f);
   glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-6.15f, 12.64f);
    glVertex2f(-14.02f, 17.67f);
    glEnd();
    }
    else {
        glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-25.82f, 31.23f);
    glVertex2f(-26.7f, 16.8f);
   glVertex2f(-32.82f, 12.2f);
  glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-6.15f, 12.64f);
    glVertex2f(-14.02f, 17.67f);
    glEnd();
    }

     glBegin(GL_POLYGON);    //1st small mountain2(A2b2c2d2f2)
     if(isDay){
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(-25.82f, 31.23f);
    glVertex2f(-23.64f, 43.91f);
   glVertex2f(-18.39f, 46.09f);
    glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-12.71f, 44.34f);
    glVertex2f(-14.02f, 17.67f);
    glEnd();
     }
     else {
  glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(-25.82f, 31.23f);
    glVertex2f(-23.64f, 43.91f);
   glVertex2f(-18.39f, 46.09f);
  glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-12.71f, 44.34f);
    glVertex2f(-14.02f, 17.67f);
    glEnd();
     }
glBegin(GL_POLYGON);//2nd small mountain1(j1h1g1p1o1)
if(isDay){
       glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(23.15f, 30.35f);
    glVertex2f(17.03f, 20.15f);
   glVertex2f(22.28f, 11.99f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(36.05f, 11.55f);
    glVertex2f(35.83f, 30.35f);
    glEnd();
}
else{
    glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(23.15f, 30.35f);
    glVertex2f(17.03f, 20.15f);
   glVertex2f(22.28f, 11.99f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(36.05f, 11.55f);
    glVertex2f(35.83f, 30.35f);
    glEnd();
}

glBegin(GL_POLYGON);//2nd small mountain2(j1k1n1o1)
     glVertex2f(23.15f, 30.35f);
    glVertex2f(23.37f, 39.32f);
   glVertex2f(36.49f, 38.66f);
  glVertex2f(35.83f, 30.35f);
    glEnd();

    glBegin(GL_POLYGON);//2nd small mountain3(k1l1m1n1)
    glVertex2f(23.37f, 39.32f);
    glVertex2f(25.56f, 45.22f);
   glVertex2f(33.43f, 45.87f);
  glVertex2f(36.49f, 38.66f);
    glEnd();

     glBegin(GL_POLYGON);//3rd small mountain(q1p1s1r1)
    glVertex2f(35.99f, 17.01f);
    glVertex2f(36.05f, 11.55f);
   glVertex2f(59.88f, 12.2f);
  glVertex2f(44.58f, 26.85f);
    glEnd();


      glBegin(GL_POLYGON);//4th small mountain(q1p1s1r1)
    glVertex2f(51.65f, 20.00f);
    glVertex2f(59.88f, 12.2f);
   glVertex2f(69.28f, 12.2f);
  glVertex2f(68.85f, 27.73f);
    glEnd();

   // glutSwapBuffers();
glBegin(GL_POLYGON);    // 10th mountain(t1a1b1c1f1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
       glVertex2f(51.65f, -36.18f);
     glVertex2f(72.78f, -21.24f);
   glVertex2f(79.34f, -13.37f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(86.34f, -20.58f);
    glVertex2f(100.0f, -36.18f);
    glEnd();
}
else {
   glColor3f(0.555f, 0.271f, 0.075f); // for night 1
       glVertex2f(51.65f, -36.09f);
     glVertex2f(72.78f, -21.24f);
   glVertex2f(79.34f, -13.37f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(86.34f, -20.52f);
    glVertex2f(100.0f, -36.18f);
    glEnd();
}
glBegin(GL_POLYGON);    //11th mountain(f1c1d1e1)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
     glVertex2f(100.0f, -36.18f);
    glVertex2f(86.34f, -20.52f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
   glVertex2f(89.83f, -12.49f);
    glVertex2f(100.00f, -7.46f);
    glEnd();
}
else {
        glColor3f(0.555f, 0.271f, 0.075f); // for night 1
     glVertex2f(100.0f, -36.18f);
    glVertex2f(86.34f,-20.52f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
   glVertex2f(89.83f, -12.49f);
    glVertex2f(100.00f, -7.46f);
    glEnd();
}
    glPushMatrix();
    glTranslatef(carPosition, 0.0f, 0.0f);

    if (isDay) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red car for day
    } else {
        glColor3f(0.0f, 1.0f, 0.0f); // Dark red car for night
    }

       glBegin(GL_LINES);

	glVertex2f(-24.09f, -35.05f);
	glVertex2f(11.91f, -34.98f);
	glVertex2f(11.91f, -34.98f);
	glVertex2f(14.96f, -36.93f);
	glVertex2f(-24.09f, -35.05f);
	glVertex2f(-24.09f, -37.84f);
glVertex2f(-20.8f, -35.05f);
glVertex2f(-20.8f, -36.98f);
glVertex2f(-2.15f, -34.96f);
glVertex2f(-2.15f, -39.85f);
glVertex2f(1.31f, -39.27f);
glVertex2f(1.31f, -34.95f);
	glEnd();


    //car1(p2q2r2b3)
    glBegin(GL_POLYGON);
glColor3f(0.753f, .753f, 0.753f); // silver
    glVertex2f(-25.0f, -20.0f);
    glVertex2f(11.96f, -19.98);
    glColor3f(0.502f, 0.502f, 0.502f); //
    glVertex2f(11.96f, -23.01f);
    glVertex2f(-25.05f, -22.96f);
    glEnd();
    // car2(a3s2t2w2z2)
    glBegin(GL_POLYGON);
  glColor3f(0.502f, 0.502f, 0.502f); //
    glVertex2f(-18.98f, -22.9f);
    glVertex2f(7.95f, -23.01f);
    glVertex2f(7.95f, -27.43f);
    glVertex2f(-14.97f, -25.99f);
    glVertex2f(-18.98f, -25.94f);
    glEnd();
    // car3(w2t2u2v2)
    glBegin(GL_POLYGON);
  glColor3f(0.502f, 0.502f, 0.502f); //
    glVertex2f(-14.97f, -25.99f);
   glVertex2f(7.95f, -27.43f);
    glVertex2f(7.89f, -34.93f);
    glVertex2f(-15.0f, -35.00f);
    glEnd();
     // car4(v2n3q3r3)
    glBegin(GL_POLYGON);
glColor3f(0.8f, 0.0f, 0.4f); //
    glVertex2f(-15.0f, -35.0f);
    glVertex2f(-2.0f, -30.0f);
    glVertex2f(-2.01f, -31.04f);
    glVertex2f(-12.55f, -34.99f);
    glEnd();

    // car5(p3o3n3q3)
    glBegin(GL_POLYGON);
glColor3f(0.8f, 0.0f, 0.4f); //
    glVertex2f(4.32f, -34.94f);
    glVertex2f(6.18f, -34.94f);
   glVertex2f(-2.0f, -30.0f);
    glVertex2f(-2.01f, -31.04f);
    glEnd();

    // car6(l2m2n2o2j2)
    glBegin(GL_POLYGON);
if(isDay){
    glColor3f(0.8f, 0.0f, 0.4f); //
    glVertex2f(-.98f, -2.61f);
    glVertex2f(-.99f, -20.04f);
   glVertex2f(2.1f, -19.98f);
    glVertex2f(2.24f, -2.69f);
    glVertex2f(.97f, -4.03f);
    glEnd();
}
else{
     glColor3f(0.6f, 0.0f, 0.298f); //
    glVertex2f(-.98f, -2.61f);
    glVertex2f(-.99f, -20.04f);
   glVertex2f(2.1f, -19.98f);
    glVertex2f(2.24f, -2.69f);
    glVertex2f(.97f, -4.03f);
    glEnd();
}

    // car7(h2k2j2i2)
    glBegin(GL_POLYGON);
    if(isDay){
    glColor3f(.63f,.63,.63);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-1.9f, -1.94f);
   glVertex2f(0.97f, -4.03f);
    glVertex2f(2.85f, -2.05f);
    glEnd();
    }
    else {
    glColor3f(1.0f, 1.0f, 1.0f); //
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-1.9f, -1.94f);
   glVertex2f(0.97f, -4.03f);
    glVertex2f(2.85f, -2.05f);
    glEnd();
    }

      // car8(g3h3c3d3)
    glBegin(GL_POLYGON);
    if(isDay){
glColor3f(0.8f, 0.0f, 0.4f); //
    glVertex2f(-6.26f, -9.98f);
     glVertex2f(-6.26f, -19.99f);
    glVertex2f(-5.0f, -19.99f);
   glVertex2f(-5.0f, -10.0f);
    glEnd();
    }
    else {
            glColor3f(0.6f, 0.0f, 0.298f); //
    glVertex2f(-6.26f, -9.98f);
     glVertex2f(-6.26f, -19.99f);
    glVertex2f(-5.0f, -19.99f);
   glVertex2f(-5.0f, -10.0f);
    glEnd();
    }
    // car9(f3e3d3g3)
    glBegin(GL_POLYGON);

    glVertex2f(-6.87f, -7.14f);
     glVertex2f(-5.64f, -6.22f);
    glVertex2f(-5.0f, -10.0f);
   glVertex2f(-6.26f, -9.98f);
    glEnd();

      // car10(k3l3m3i3j3)
    glBegin(GL_POLYGON);

    glVertex2f(-8.01f, -17.53f);
     glVertex2f(-8.89f, -17.95f);
    glVertex2f(-8.89f, -19.94f);
   glVertex2f(-6.77f, -19.99f);
   glVertex2f(-6.77f, -17.95f);
    glEnd();

    // Draw the wheels
    drawWheel(-24.17f, -39.92f);
    drawWheel(-21.09f, -38.99f);
    drawWheel(-2.12f, -39.85f);
    drawWheel(1.31f, -39.27f);
    drawWheel(15.03f, -39.00f);

    glPopMatrix();
     if (isDay) {
        glColor3f(0.6f, 0.4f, 0.2f); // Brown for day
    } else {
        glColor3f(0.2f, 0.2f, 0.2f); // Dark gray for night
    }

    glBegin(GL_POLYGON);         // 1st mountain(abde)
if(isDay){
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-100.f, -27.46f);
    glVertex2f(-96.01f, -28.77f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-80.0f, -56.18f);
    glVertex2f(-100.0f, -56.18f);
    glEnd();
}
else {
  glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-100.f, -27.46f);
    glVertex2f(-96.01f, -28.77f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-80.0f, -56.18f);
    glVertex2f(-100.0f, -56.18f);
    glEnd();
}
     glBegin(GL_POLYGON);         // 2nd mountain(bedc)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-96.01f, -28.77f);
    glVertex2f(-100.0f, -56.18f);
  glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-80.0f, -56.1f);
    glVertex2f(-90.98f, -33.58f);
    glEnd();
}
else {
glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-96.01f, -28.77f);
    glVertex2f(-100.0f, -56.18f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-80.0f, -56.1f);
    glVertex2f(-90.98f, -33.58f);
    glEnd();
}
glBegin(GL_POLYGON);
glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-68.96f, -45.97f);
     glVertex2f(-80.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-56.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-68.96f, -45.97f);
     glVertex2f(-56.64f, -56.18f);
    glVertex2f(-44.14f, -56.18f);
    glEnd();

glBegin(GL_POLYGON);
glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-50.96f, -45.97f);
     glVertex2f(-60.08f, -56.18f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-36.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-50.96f, -45.97f);
     glVertex2f(-36.64f, -56.18f);
    glVertex2f(-24.14f, -56.18f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-26.96f, -45.97f);
     glVertex2f(-36.08f, -56.18f);
     glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(00.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-26.96f, -45.97f);
     glVertex2f(-12.64f, -56.18f);
    glVertex2f(-00.14f, -56.18f);
    glEnd();

glBegin(GL_POLYGON);
glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-2.96f, -45.97f);
     glVertex2f(-12.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(24.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-2.96f, -45.97f);
     glVertex2f(12.64f, -56.18f);
    glVertex2f(24.14f, -56.18f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(22.96f, -45.97f);
     glVertex2f(12.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(48.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(22.96f, -45.97f);
     glVertex2f(36.64f, -56.18f);
    glVertex2f(48.14f, -56.18f);
    glEnd();
     glBegin(GL_POLYGON);
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(46.96f, -45.97f);
     glVertex2f(36.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(72.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(46.96f, -45.97f);
     glVertex2f(60.64f, -56.18f);
    glVertex2f(72.14f, -56.18f);
    glEnd();
     glBegin(GL_POLYGON);
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(70.96f, -45.97f);
     glVertex2f(60.08f, -56.18f);
      glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(96.64f, -56.18f);
    glEnd();
glBegin(GL_POLYGON);
    glVertex2f(70.96f, -45.97f);
     glVertex2f(84.64f, -56.18f);
    glVertex2f(96.14f, -56.18f);
    glEnd();
    ////////////////////////////////////////////////////
     glBegin(GL_POLYGON);         // 1st mountain(abde)
if(isDay){
     glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-50.f, -27.46f);
    glVertex2f(-46.01f, -28.77f);
glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-30.0f, -56.18f);
    glVertex2f(-50.0f, -56.18f);
    glEnd();
}
else {
  glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-50.f, -27.46f);
    glVertex2f(-46.01f, -28.77f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-30.0f, -56.18f);
    glVertex2f(-50.0f, -56.18f);
    glEnd();
}
glBegin(GL_POLYGON);         // 2nd mountain(bedc)
if(isDay){
        glColor3f(0.757f, 0.412f, 0.208f); // for day1
    glVertex2f(-46.01f, -28.77f);
    glVertex2f(-50.0f, -56.18f);
  glColor3f(0.55f, 0.271f, 0.075f); //for day 2
    glVertex2f(-30.0f, -56.1f);
    glVertex2f(-40.98f, -33.58f);
    glEnd();
}
else {
glColor3f(0.555f, 0.271f, 0.075f); // for night 1
    glVertex2f(-46.01f, -28.77f);
    glVertex2f(-50.0f, -56.18f);
glColor3f(0.722f, 0.53f, 0.043f); // for night 2
    glVertex2f(-30.0f, -56.1f);
    glVertex2f(-40.98f, -33.58f);
    glEnd();
}
////////////////////////////////////////////////////

glPushMatrix();
    glTranslated(50,-45,0);
    rock();
    glPopMatrix();
     glPushMatrix();
    glTranslated(80,-44,0);
    rock();
    glPopMatrix();
     glPushMatrix();
    glTranslated(120,-45,0);
    rock();
    glPopMatrix();
     glColor3f(0.0f,1.0f,0.0f);
    drawText(-90.0,50.18,"Press f to start sandstorm.",10);
    glutSwapBuffers();


}
//siam
void SiamDrawText(float x, float y, const char* text, float scale, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);
    glColor3f(r, g, b);
    glRasterPos2f(0.0f, 0.0f);
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
    glPopMatrix();
}
Snowflake snowflakes[numSnowflakes];
void initSnow() {
    for (int i = 0; i < numSnowflakes; ++i) {
        snowflakes[i].x = (rand() % 20000 - 10000) / 100.0f;
        snowflakes[i].y = (rand() % 11236 - 5618) / 100.0f;
        snowflakes[i].speed = (rand() % 100 + 50) / 10000.0f;
    }
}
void drawSnowflakes() {
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < numSnowflakes; ++i) {
        glVertex2f(snowflakes[i].x, snowflakes[i].y);
    }
    glEnd();
}
void siamUpdateSnow() {
    for (int i = 0; i < numSnowflakes; ++i) {
        snowflakes[i].y -= snowflakes[i].speed;
        if (snowflakes[i].y < -56.18f) {
            snowflakes[i].y = 56.18f;
            snowflakes[i].x = (rand() % 20000 - 10000) / 100.0f;
        }
    }
}
void SiamCircle(float xOffset, float yOffset, float r, float red, float green, float blue) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;
        glColor3f(red, green, blue);
        glVertex2f(x, y);
    }
    glEnd();
}
void ground() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.8 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(1.0 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f);
    glVertex2f(-1 * scaleX, -0.6 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.8f);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.7f);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(0.6 * scaleX, -0.5 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.0f, 0.6f);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(0.6 * scaleX, -0.5 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.8f);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.9f);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 1.0f);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glVertex2f(1 * scaleX, -0.4 * scaleY);
    glVertex2f(0.7 * scaleX, -0.3 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(-1 * scaleX, -0.8 * scaleY);
    glVertex2f(-1 * scaleX, -1 * scaleY);
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.4f);
    glVertex2f(-0.1 * scaleX, -1 * scaleY);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.6f);
    glVertex2f(0.0 * scaleX, -0.8 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glVertex2f(1 * scaleX, -0.4 * scaleY);
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(-1 * scaleX, -1 * scaleY);
    glVertex2f(-1 * scaleX, -1.2 * scaleY);
    glVertex2f(1 * scaleX, -1.2 * scaleY);
    glVertex2f(1 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(-1 * scaleX, -1.2 * scaleY);
    glVertex2f(-1 * scaleX, -1.4 * scaleY);
    glVertex2f(1 * scaleX, -1.4 * scaleY);
    glVertex2f(1 * scaleX, -1.2 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f);
    glVertex2f(1 * scaleX, -0.8 * scaleY);
    glVertex2f(1 * scaleX, -1 * scaleY);
    glVertex2f(0.8 * scaleX, -1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.6f);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.805 * scaleX, -0.539 * scaleY);
    glVertex2f(-1 * scaleX, -0.6 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.1f, 0.6f);
    glVertex2f(-0.5 * scaleX, -0.5 * scaleY);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(-100, -0.5 * 56.18);
    glVertex2f(-50, -28);
    glVertex2f(-100, -0.6 * 56.18);
    glEnd();
}
void siamSky() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(-1.2 * scaleX, 1 * scaleY);
    glColor3f(0.1f, 0.0f, 0.3f);
    glVertex2f(1 * scaleX, 1 * scaleY);
    glColor3f(0.2f, 0.0f, 0.5f);
    glVertex2f(1.05 * scaleX, -0.05 * scaleY);
    glColor3f(0.1f, 0.0f, 0.2f);
    glVertex2f(-1.2 * scaleX, 0.2 * scaleY);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glPointSize(1.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 5; ++i) {
        float x = -100.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (200.0f)));
        float y = -56.18f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (112.36f)));
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void mountain() {
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.6f);
    glVertex2f(-1 * scaleX, 0.2 * scaleY);
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(-0.8052359506136 * scaleX, 0.6499629374436 * scaleY);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.6f);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(-0.2473459943025 * scaleX, 0.7530800383732 * scaleY);
    glVertex2f(0.4009809471278 * scaleX, 0.1316905541238 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 0.6f);
    glVertex2f(0.024983344593 * scaleX, 0.1497009106251 * scaleY);
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(0.4850498251202 * scaleX, 0.7821643488918 * scaleY);
    glVertex2f(1.0002558146587 * scaleX, 0.1110764591988 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.35f, 0.55f);
    glVertex2f(-1 * scaleX, 0.2 * scaleY);
    glVertex2f(-0.8528284587349 * scaleX, 0.266578844244 * scaleY);
    glVertex2f(-0.8977769386273 * scaleX, 0.340611634655 * scaleY);
    glColor3f(0.1f, 0.3f, 0.5f);
    glVertex2f(-0.8 * scaleX, 0.4 * scaleY);
    glVertex2f(-0.8343202611322 * scaleX, 0.4886772154769 * scaleY);
    glVertex2f(-0.8052359506136 * scaleX, 0.6499629374436 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.35f, 0.55f);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glVertex2f(-0.2605661354473 * scaleX, 0.3882041427763 * scaleY);
    glVertex2f(-0.3345989258582 * scaleX, 0.5098294413086 * scaleY);
    glColor3f(0.1f, 0.3f, 0.5f);
    glVertex2f(-0.2499900225314 * scaleX, 0.6393868245278 * scaleY);
    glVertex2f(-0.2473459943025 * scaleX, 0.7530800383732 * scaleY);
    glVertex2f(-0.5999484996762 * scaleX, 0.1801226514847 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.35f, 0.55f);
    glVertex2f(0.024983344593 * scaleX, 0.1497009106251 * scaleY);
    glVertex2f(0.426881204083 * scaleX, 0.3247474652812 * scaleY);
    glVertex2f(0.3660685548169 * scaleX, 0.5124734695376 * scaleY);
    glColor3f(0.1f, 0.3f, 0.5f);
    glVertex2f(0.5247102485546 * scaleX, 0.6367427962988 * scaleY);
    glVertex2f(0.4850498251202 * scaleX, 0.7821643488918 * scaleY);
    glEnd();
    glFlush();
}
void spaces()
{
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.35f, 0.55f);
    glVertex2f(-1 * scaleX, 0.2 * scaleY);
    glVertex2f(-1 * scaleX, -0.5 * scaleY);
    glVertex2f(-0.2 * scaleX, -0.6 * scaleY);
    glVertex2f(0.4 * scaleX, -0.4 * scaleY);
    glVertex2f(0.8 * scaleX, -0.6 * scaleY);
    glVertex2f(1 * scaleX, -0.4 * scaleY);
    glVertex2f(1.0002558146587 * scaleX, 0.1110764591988 * scaleY);
    glEnd();
    glFlush();
}
void arc(float xOffset, float yOffset, float r, float red, float green, float blue) {
    glBegin(GL_LINE);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;
        glColor3f(red, green, blue);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void spaceship() {
    glTranslatef(50, 100.0f, 0.0f);
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(siamMove, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-20, -12);
    glVertex2f(8, -12);
    glVertex2f(14, -15);
    glVertex2f(8, -18);
    glVertex2f(-20, -18);
    glVertex2f(-22, -17);
    glVertex2f(-22, -15);
    glVertex2f(-22, -13);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-20, -12);
    glVertex2f(-20, -5);
    glVertex2f(-18, -4);
    glVertex2f(-10, -12);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-20, -18);
    glVertex2f(-20, -24);
    glVertex2f(-18, -26);
    glVertex2f(-10, -18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-12, -10);
    glVertex2f(4, -10);
    glVertex2f(4, -12);
    glVertex2f(-10, -12);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(4, -18);
    glVertex2f(4, -20);
    glVertex2f(-12, -20);
    glVertex2f(-10, -18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-14, -14);
    glVertex2f(-14, -16);
    glVertex2f(8, -16);
    glVertex2f(8, -14);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(8, -12);
    glVertex2f(8, -18);
    glVertex2f(14, -15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-22.5, -17);
    glVertex2f(-24.017, -16.9);
    glVertex2f(-23.5, -16);
    glVertex2f(-24, -15.5);
    glVertex2f(-22.5, -15);
    glVertex2f(-24, -14.5);
    glVertex2f(-23.5, -14);
    glVertex2f(-24, -13);
    glVertex2f(-22.5, -13);
    glVertex2f(-22, -12);
    glVertex2f(-22, -18);
    glVertex2f(-22.5, -18);
    glEnd();
    glPopMatrix();
    glFlush();
}
void spacerover() {
    glPushMatrix();
    glTranslatef(0.0, siamMove3, 0);
    glTranslatef(siamMove4, 0.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.75f, 0.75f, 0.75f);
    glVertex2f(-0.8 * scaleX, 0.0f);
    glVertex2f(-0.5f * scaleX, 0);
    glVertex2f(-0.4 * scaleX, -0.1 * scaleY);
    glVertex2f(-0.9 * scaleX, -0.1 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-0.85 * scaleX, -0.15f * scaleY);
    glVertex2f(-0.75 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.8 * scaleX, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-0.55 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.45 * scaleX, -0.15 * scaleY);
    glVertex2f(-0.5 * scaleX, 0.0);
    glEnd();
    glColor3f(0.0f, 0.8f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(-0.6 * scaleX, -0.05 * scaleY);
    glVertex2f(-0.7 * scaleX, -0.05 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 1.0f);
    glVertex2f(-0.65 * scaleX, 0.1 * scaleY);
    glVertex2f(-0.75 * scaleX, 0);
    glVertex2f(-0.55 * scaleX, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 1.0f);
    glVertex2f(-0.55 * scaleX, 0.1 * scaleY);
    glVertex2f(-0.54 * scaleX, 0.1 * scaleY);
    glVertex2f(-0.54 * scaleX, 0 * scaleY);
    glVertex2f(-0.55 * scaleX, 0 * scaleY);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-0.54 * scaleX, 0.1 * scaleY);
    glVertex2f(-0.5 * scaleX, 0.08 * scaleY);
    glVertex2f(-0.54 * scaleX, 0.06 * scaleY);
    glEnd();
    glPopMatrix();
    glFlush();
}
void arc(float xOffset, float yOffset, float r) {
    glLineWidth(7);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 300; i++) {
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float x = r * cos(a) + xOffset;
        float y = r * sin(a) + yOffset;
        float red = 1.0 - (float)i / 300;
        float green = 0.5;
        float blue = (float)i / 300;
        glColor3f(red, green, blue);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void ball_naptune_gravity()
{
    glPushMatrix();
    glTranslatef(0.0, siamMove5, 0);
    SiamCircle(-0.2 * scaleX, -0.1 * scaleY, 3, 0, 0, 1);
    SiamDrawText(-0.25 * scaleX, -0.2 * scaleY, "Naptune", 2, 0, 0, 1);
    glPopMatrix();
}
void ball_naptune_earth()
{
    glPushMatrix();
    glTranslatef(0.0, siamMove6, 0);
    SiamCircle(0.0577543454977 * scaleX, -0.10277862500768 * scaleY, 3, 0, 1, 0);
    SiamDrawText(0.02 * scaleX, -0.2 * scaleY, "Earth", 2, 0, 1, 0);
    glPopMatrix();
}
void siamSun() {
    SiamCircle(-60.0f, 0.0f, 33.3132820428746, 1.0f, 0.8f, 0.0f);
}
void neptune() {
    SiamCircle(60.0f, 0.0f, 22.3526632316143, 0.0f, 0.5f, 1.0f);
}
void moon(float xOffset, float yOffset, float radius, float angle, float moonRadius, float red, float green, float blue) {
    float x = xOffset + radius * cos(angle);
    float y = yOffset + radius * sin(angle);
    SiamCircle(x, y, moonRadius, red, green, blue);
}
void radius(float xStart, float yStart, float xEnd, float yEnd, float xMid, float yMid) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 150 * move; i++) {
        float t = i / 150.0f;
        float one_minus_t = 1.0f - t;
        float x = one_minus_t * one_minus_t * xStart + 2 * one_minus_t * t * xMid + t * t * xEnd;
        float y = one_minus_t * one_minus_t * yStart + 2 * one_minus_t * t * yMid + t * t * yEnd;
        glColor3f(1, 1, 1);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawStars() {
    glPointSize(1.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 5; ++i) {
        float x = -100.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (200.0f)));
        float y = -56.18f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (112.36f)));
        glVertex2f(x, y);
    }
    glEnd();
}
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    initSnow();
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    if (currentScene == 0) {
        SiamDrawText(-19, 00, "Some facts about Neptune", 200, 0, 0, 1);
    }
    else if (currentScene == 1) {
        move += 0.01f;
        siamSun();
    }
    else if (currentScene == 2) {
        // Initialize move to 0 when entering scene 2
        if (move < 1.0f) {
            move += 0.01f;
        }
        SiamDrawText(-27, 4, "Sun to Neptune is approximately 4.4721 billion km", 1, 1, 1, 1);
        siamSun();
        radius(radiusStartX, radiusStartY, radiusEndX, radiusEndY, radiusMidX, radiusMidY);
        neptune();
    }
    else if (currentScene == 3) {
        siamSun();
        radius(radiusStartX, radiusStartY, radiusEndX, radiusEndY, radiusMidX, radiusMidY);
        SiamDrawText(-19, 4, "Neptune Has 14 moons", 2, 1, 1, 1);
        neptune();
    }
    else if (currentScene == 4) {
        siamSun();
        radius(radiusStartX, radiusStartY, radiusEndX, radiusEndY, radiusMidX, radiusMidY);
        SiamDrawText(-19, 4, "Neptune Has 14 moons", 2, 1, 1, 1);
        neptune();
        moon(60.0f, 0.0f, 30.0f, moonAngle1, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 40.0f, moonAngle2, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 50.0f, moonAngle3, 3.0f, 0.5f, 0.5f, 0.5f);
    }
    else if (currentScene == 5) {
        // Scene where siamSky and Neptune with moons are displayed
        siamSky();
        ball_naptune_gravity();
        ball_naptune_earth();
        siamSun();
        neptune();
        moon(60.0f, 0.0f, 30.0f, moonAngle1, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 40.0f, moonAngle2, 3.0f, 0.5f, 0.5f, 0.5f);
        moon(60.0f, 0.0f, 50.0f, moonAngle3, 3.0f, 0.5f, 0.5f, 0.5f);
    }
    else if (currentScene == 6)
    {
        ground();
        drawStars();
        arc(0, -110, 160.08225989589045);
        mountain();
        spaces();
        drawSnowflakes();
        spacerover();
    }
    glFlush();
    glutSwapBuffers();
}
void display_scene()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    initSnow();
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    spacerover();
    //spaceship();
    glFlush();
    glutSwapBuffers();
}
void display2()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    initSnow();
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    spacerover();
    spaceship();
    glFlush();
    glutSwapBuffers();
}
void display3()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    initSnow();
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    SiamDrawText(-0.3 * scaleX, 0.8 * scaleY, "The gravity of comparison between earth and naptune", 2, 0, 1, 1);
    siamMove3 = 0.0f;
    siamMove4 = 0.0f;
    spacerover();
    spaceship();
    glFlush();
    glutSwapBuffers();
}
void display4()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    initSnow();
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    SiamDrawText(-0.3 * scaleX, 0.8 * scaleY, "The gravity of comparison between earth and naptune", 2, 0, 1, 1);
    spacerover();
    spaceship();
    glFlush();
    glutSwapBuffers();
}
void display5()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(2.0f);
    initSnow();
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -56.18, 56.18);
    ground();
    siamSky();
    arc(0, -110, 160.08225989589045);
    mountain();
    spaces();
    drawSnowflakes();
    SiamDrawText(-0.3 * scaleX, 0.8 * scaleY, "The gravity of comparison between earth and naptune", 2, 0, 1, 1);
    ball_naptune_gravity();
    ball_naptune_earth();
    spacerover();
    spaceship();
    glFlush();
    glutSwapBuffers();
}

//shuvo
void update2(int value)
{
    zoom+=0.02f;
    if(zoom>1) {
        zoom=1.01;
    }
    glutPostRedisplay();
    glutTimerFunc(20, update2, 0);
}
void update1(int value)
{
    sx = static_cast<float>((rand() % 200) - 100);
    sy = static_cast<float>((rand() % 11236) - 5618) / 100.0;
    glutPostRedisplay();
    glutTimerFunc(1000, update1, 0);
}
void update(int value) {
    me+=0.02f;
    if(me>2*3.1416) {
        me-=2*3.1416;
    }
    v+=0.015f;
    if(v>2*3.1416) {
        v-=2*3.1416;
    }
    e += 0.01f;
    if(e>2*3.1416) {
        e-=2*3.1416;
    }
    ma+=0.007f;
    if(ma>2*3.1416) {
        ma-=2*3.1416;
    }
    j+=0.005f;
    if(j>2*3.1416) {
        j-=2*3.1416;
    }
    s+=0.003f;
    if(s>2*3.1416) {
        s-=2*3.1416;
    }
    u+=0.0015f;
    if(u>2*3.1416) {
        u-=2*3.1416;
    }
    n+=0.0005f;
    if (n>2*3.1416) {
        n-=2*3.1416;
    }
    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}
//milton

void update3(int value) {
    if (isBMoving) {
        _move1 += 1.0f;
        if (_move1 > 180) {
            _move1 = -100.0f;
        }

        _move2 -= 0.05f;
        if (_move2 < -180) {
            _move2 = 100.0f;
        }
    }
    if (isSMoving) {
        _sunY += 0.05f;
        if (_sunY > 100) {
            _sunY = 0.0f;
        }

    }
    if (isCMoving) {
        _m2 += 1.25f;
        if (_m2 > 180) {
            _m2 = -100.0f;
        }

        _m1 -= 2.0f;
        if (_m1 < -180) {
            _m1 = 179.0f;
        }
        _m3 -= 4.25f;
        if (_m3 < -180) {
            _m3 = 179.0f;
        }
    }

    if (isCoMoving) { ///cloud
        _mo1 += 0.3f;
        if (_mo1 > 180) {
            _mo1 = -100.0f;
        }
        _mo2 += 0.1f;
        if (_mo2 > 180) {
            _mo2 = -179.0f;
        }

    }

    glutPostRedisplay();
    glutTimerFunc(20, update3, 0);
}
//jimmy
void update4(int value) {
    _angle1 -= 2.0f;
    if (_angle1 < 360.0) {
        _angle1 += 360;
    }

    carPosition += carSpeed;
    if (carPosition > 100.0f) {
        carPosition = -100.0f;
    }

    if (isDay) {
        sunPositionY -= sunSpeed;
        if (sunPositionY < 37.6f) {
            isDay = false; // Switch to night mode
              sunPositionY = 37.6f;
            nightCounter = 0; // Reset night counter

        }
    } else {
        if (nightCounter < nightDuration) {
            nightCounter++; // Increment night duration counter
        } else {
            sunPositionY += sunSpeed;
            if (sunPositionY >37.6f) {
                    sunPositionY = 50.6f;
                isDay = true; // Switch to day mode


            }
        }
    }

    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(20, update4, 0); // Notify GLUT to call update again in 25 milliseconds
}

//siam
void siamUpdate(int value) {
    siamMove -= 5.0;
    if (siamMove <= -90.0) {
        siamMove = -90.1;
    }
    glutPostRedisplay();
    glutTimerFunc(100, siamUpdate, 0);
}
void siamUpdate2(int value)
{
    if (moveRover) {
        siamMove3 += 1.0f;
        if (siamMove3 >= 30) {
            siamMove3 = 30.1;
            siamMove4 += 1.0;
            if (siamMove4 >= 190)
            {
                siamMove4 = -60;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(100, siamUpdate2, 0);
}
void siamUpdate3(int value)
{
    siamMove5 += 1.0f * _direction;
    if (siamMove5 >= 30.0f)
    {
        siamMove5 = 30.0f;
        _direction = -1;
    }
    else if (siamMove5 <= -20.0f)
    {
        siamMove5 = -20.0f;
        _direction = 1;
    }
    glutPostRedisplay();
    glutTimerFunc(100, siamUpdate3, 0);
}
void siamUpdate4(int value)
{
    _velocity += -9.8f * 0.1f;
    siamMove6 += _velocity * 0.1f;
    if (siamMove6 <= -20.0f)
    {
        siamMove6 = -20.0f;
        _velocity = -_velocity;
    }
    if (siamMove6 >= 30.0f)
    {
        siamMove6 = 30.0f;
        _velocity = -_velocity;
    }
    glutPostRedisplay();
    glutTimerFunc(100, siamUpdate4, 0);
}
void siamUpdate5(int value) {
    if (move >= 1.0f) {
        move = 1.0f;
    }
    moonAngle1 += 0.05f;
    moonAngle2 += 0.03f;
    moonAngle3 += 0.02f;
    if (moonAngle1 > 2 * M_PI) moonAngle1 -= 2 * M_PI;
    if (moonAngle2 > 2 * M_PI) moonAngle2 -= 2 * M_PI;
    if (moonAngle3 > 2 * M_PI) moonAngle3 -= 2 * M_PI;
    glutPostRedisplay();
    glutTimerFunc(16, siamUpdate5, 0);
}
void timer(int) {
    siamMove2 += 1.01f;
    if (siamMove2 > -60.0f) siamMove2 = -60.1f;
    for (int i = 0; i < numSnowflakes; ++i) {
        snowflakes[i].speed = 1.0f + 0.01f * (56.18f - snowflakes[i].y);
    }
    siamUpdateSnow();
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}
void timer2(int value) {
    if (currentScene < 4) { // Change condition to allow transition to scene 4
        currentScene++;
        if (currentScene == 2) {
            move = 0.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(3000, timer2, 0);
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'E':
case 'e':
    mes = 0.4f;
    vs = 0.9f;
    es = 0.9f;
    mas = 0.4f;
    js = 3.0f;
    ss = 2.4f;
    us = 1.25f;
    ns = 1.1f;
    zoom=0.01;
    glutDisplayFunc(drawScene1);
    break;
case 'D':
case 'd':
    mes = 0.4f;
    vs = 0.9f;
    es = 0.9f;
    mas = 0.4f;
    js = 3.0f;
    ss = 2.4f;
    us = 1.25f;
    ns = 1.1f;
    glutDisplayFunc(drawScene2);
    break;
case 'R':
case 'r':
    mes = 0.4f;
    vs = 0.9f;
    es = 0.9f;
    mas = 0.4f;
    js = 3.0f;
    ss = 2.4f;
    us = 1.25f;
    ns = 1.1f;
    glutDisplayFunc(drawScene3);
    break;
case 'H':
case 'h':
    mes = 0.4f;
    vs = 0.9f;
    es = 0.9f;
    mas = 0.4f;
    js = 3.0f;
    ss = 2.4f;
    us = 1.25f;
    ns = 1.1f;
    glutDisplayFunc(drawScene);
    break;
//milton
case '1':
    glutDisplayFunc(drawScene4);
// boat start
case 'a':
    isBMoving = true;
    break;
    // boat stop
case 'b':
    isBMoving = false;
    break;
        // sun run
case 's':
    isSMoving = true;
    break;
        // cannot see boat
case 'c':
    isBVisible = false;
    break;
        // see boat
case 'p':
    isBVisible = true;
    break;////
        // car start
case 'm':
    isCMoving = true;
    break;
        // car stop
case 'n':
    isCMoving = false;
    break;
        // cannot see car
case 'l':
    isCVisible = false;
    break;
        // see car
case 'k':
    isCVisible = true;
    break;
    // car start
case 'o':
    isCoMoving = true;
    break;


    // cannot see car
case 'i':
    isCoVisible = false;
    break;

case 'y':
    isCoVisible = true;
    break;
case 'q':
    glutDisplayFunc(drawSceneR);
    break;
case 'w':
    glutDisplayFunc(drawScene4);
    break;
//jimmy
case '2':
    glutDisplayFunc(drawscene);
case 'f':
    glutDisplayFunc(drawscene);
    break;
case 'g':
    glutDisplayFunc(drawscene2);
    break;
//siam
case '3':
   scaleX = 100.0f;
  scaleY = 56.18f;
 siamMove = 0.0f;
  siamMove2 = 0.0f;
  siamMove3 = 0.0f;
 siamMove4 = 0.0;
 siamMove5 = 0.0f;
 currentScene = 0;
 move = 0.0f;
 moonAngle1 = 0.0f, moonAngle2 = 0.0f, moonAngle3 = 0.0f;
 radiusStartX = 51.1204101147212f;
 radiusStartY = 56.18f;
 radiusEndX = 51.2901657984f;
 radiusEndY = -56.18f;
 radiusMidX = 70.0f;
 radiusMidY = 0.0f;
 //INITIAL_VELOCITY = 20.0f;
 siamMove6 = 0.0f;
moveRover = false;
 _velocity = INITIAL_VELOCITY;
 _direction2 = 1.0f;
 _direction = 1;

//numSnowflakes = 100;

    glutDisplayFunc(display);
case 'Z':
    siamMove = 0.0f;
    glutDisplayFunc(display_scene);
    break;
case 'X':
    siamMove = 0.0f;
    glutDisplayFunc(display2);
    break;
case 'C':
    moveRover = true;
    break;
case 'V':
    glutDisplayFunc(display4);
    glutPostRedisplay();
    break;
case 'B':
    glutDisplayFunc(display5);
    glutPostRedisplay();
    break;
case 'N':
    currentScene=0;
    glutDisplayFunc(display);
    break;
glutPostRedisplay();
	}}


int main(int argc, char** argv) {
    for(int i = 0; i < 650; i++)
    {
        float x5 = static_cast<float>(rand() % 200) - 100;
        float y5 = static_cast<float>(rand() % 200) - 100;
        st[i][0] = x5;
        st[i][1] = y5;
    }
    for(int i = 0; i < 800; i++)

    {

        float x5 = static_cast<float>(rand() % 200) - 100;

        float y5 = static_cast<float>(rand() % 200) - 100;

        ary[i][0] = x5;

        ary[i][1] = y5;

    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Solar System");
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(20, update, 0);
    glutTimerFunc(1000, update1, 0);
    glutTimerFunc(20, update2, 0);
    glutTimerFunc(20, update3, 0);
    glutTimerFunc(20, update4, 0);
    glutTimerFunc(100, siamUpdate, 0);
    glutTimerFunc(100, siamUpdate2, 0);
    glutTimerFunc(100, siamUpdate3, 0);
    glutTimerFunc(100, siamUpdate4, 0);
    glutTimerFunc(16, siamUpdate5, 0);
    glutTimerFunc(50, timer, 0);
    glutTimerFunc(3000, timer2, 0);

    glutMainLoop();
    return 0;
}
