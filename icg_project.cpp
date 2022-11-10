/*
Group Members -
VENKATA ANUHYA TUMMALA - CED19I031
N. SREE DHYUTI         - CED19I027*/
//Use d or D for day
//Use n or N for night

// g++ icg_project.cpp -o pro -lGL -lGLU -lglut -lGLEW
#include <GL/gl.h>
#include <iostream>
#include <GL/glut.h>

int posx = 0, posy = 0;
int cx=-10;
float spin = 0.0;
int part_of_the_day = 1; // 1 for day ,0 for night
void Pixel(float x, float y)
{
    glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}


void Plot_all_Octants( float x, float y)
{
    Pixel( y, x); //O1
    Pixel( x, y); //O2
    Pixel(- x, y); //O3
    Pixel(- y, x); //O4

    Pixel(- y, - x); //O5
    Pixel(- x, - y); //O6
    Pixel( x, - y); //O7
    Pixel( y, - x); //O8
}
void mcd(GLdouble rad)
{
    int x =0;
    int y=rad;
    int p0=1-rad;//decision parameter
    
    while(y>x)
    {
    	Plot_all_Octants( x, y);
     if(p0<0)
     {
     	x++;
     	p0+=2*x+1;
     }
     else
     {
     	y--;
     	x++;
     	p0+=2*(x-y)+1;
     }
    }
    
}
void circle(GLdouble rad)
{
    mcd(rad);
    float temp = rad;
    while (temp--)
    {
        mcd(temp);
        mcd(temp);
    }

}

// tree
void tree(int x, int y)
{
    glColor3f(0.6156863, 0, 0);

    glBegin(GL_POLYGON);

    glVertex3i(50 +x, 350 +y, 0);
    glVertex3i(70+x, 350+y, 0);

    glVertex3i(70+x, 500+y, 0);
    glVertex3i(50+x, 500+y, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(10+x, 500+y, 0);
    glVertex3i(110+x, 500+y, 0);

    glVertex3i(60+x, 600+y, 0);

    glEnd();
    glBegin(GL_POLYGON);

    glVertex3i(15+x, 550+y, 0);
    glVertex3i(105+x, 550+y, 0);

    glVertex3i(60+x, 650+y, 0);

    glEnd();
}

/// river
void river()
{
    glColor3f(0.0352941176470588, 0.5098039215686275, 0.9568627450980392);
    glBegin(GL_POLYGON);

    glVertex3i(0, 0, 0);
    glVertex3i(1200, 0, 0);
    glVertex3i(1200, 300, 0);
    glVertex3i(0, 300, 0);

    glEnd();
}
// land
void land()
{
    glColor3f(0.533, 1.293, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(0, 300, 0);
    glVertex3i(1200, 300, 0);
    glVertex3i(1200, 600, 0);
    glVertex3i(0, 600, 0);

    glEnd();
}
/// hill
void hill()
{
    
    glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(600, 600, 0);
    glVertex3i(800, 900, 0);
    glVertex3i(900, 650, 0);
    // glVertex3i(600, 600, 0);

    glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);

    // glVertex3i(600, 600, 0);
    glVertex3i(900, 650, 0);
    glVertex3i(1000, 800, 0);
    glVertex3i(1100, 620, 0);

    glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(1050, 620, 0);
    glVertex3i(1200, 800, 0);
    glVertex3i(1200, 600, 0);
    // glVertex3i(1100, 620, 0);

    glEnd();
}

// house
void house(int x, int y)
{
    //body
    glColor3f(.555, 0.924, 0.930);

    glBegin(GL_POLYGON);

    glVertex3i(210 + x , 350 + y , 0);
    glVertex3i(390 + x , 350 + y , 0);
    glVertex3i(390 + x , 450 + y , 0);
    glVertex3i(210 + x , 450 + y , 0);

    glEnd();
    //roof
    glColor3f(.990, 0.0, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(200 + x , 450 + y , 0);
    glVertex3i(400 + x , 450 + y , 0);
    glVertex3i(400 + x , 490 + y , 0);
    glVertex3i(200 + x , 530 + y , 0);

    glEnd();
    //door
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);

    glVertex3i(280 + x , 350 + y , 0);
    glVertex3i(320 + x , 350 + y , 0);
    glVertex3i(320 + x , 450 + y , 0);
    glVertex3i(280 + x , 450 + y , 0);

    glEnd();
    //window1
    glBegin(GL_POLYGON);

    glVertex3i(240 + x , 380 + y , 0);
    glVertex3i(260 + x , 380 + y , 0);
    glVertex3i(260 + x , 420 + y , 0);
    glVertex3i(240 + x , 420 + y , 0);

    glEnd();
    //window2
    glBegin(GL_POLYGON);

    glVertex3i(340 + x , 380 + y , 0);
    glVertex3i(360 + x , 380 + y , 0);
    glVertex3i(360 + x , 420 + y , 0);
    glVertex3i(340 + x , 420 + y , 0);

    glEnd();
}
//sun
void sun()
{
    glPushMatrix();
        glColor3f(0.9764705882352941, 0.4705882352941176, 0.0196078431372549);
        glTranslatef(1000, 1000, 0);
        circle(50);
    glPopMatrix();
}

// boat
void boat(int x, int y)
{
   
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);

    glVertex3i(10+x, 150+y, 0);
    glVertex3i(200+x, 150+y, 0);
    glVertex3i(170+x, 100+y, 0);
    glVertex3i(30+x, 100+y, 0);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);

    glVertex3i(50+x, 150+y, 0);
    glVertex3i(150+x, 150+y, 0);
    glVertex3i(150+x, 420+y, 0);
    glEnd();
    
}
// night
void night_effect()
{
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);

    glVertex3i(0, 300, 0);
    glVertex3i(1200, 300, 0);
    glVertex3i(1200, 1200, 0);
    glVertex3i(0, 1200, 0);

    glEnd();
}
// stars

void star()
{
    glPointSize(4);
    glColor3f(1, 1, 1);
    for(int x=0;x<1200;x=x+100)
    {
        glBegin(GL_POINTS);
        glVertex3i(30+x, 1150, 0);
        glVertex3i(30+x, 1050, 0);
        glVertex3i(50+x, 900, 0);
        glVertex3i(1200-x, 1100, 0);
        glVertex3i(90+x, 1000, 0);
        glEnd();
    }
    
   
}
// moon
void moon()
{
   glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(1000, 1000, 0);
        circle(50);
    glPopMatrix();
}
//windmill

// Windmill_Stand_Model 
void Windmill_Stand_Model(){

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}
void Windmill_Blade(){

    ///Blade_final
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}

// Windmill_Final_Model 
void Windmill(){



    ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();




}
void Windmill_final(int x , int y){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(x,y,0);
    Windmill();
    glPopMatrix();

}
// clouds


void cloud_model_1(){
    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right

    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();
}

void cloud(int x,int y){
    glPushMatrix();
    glTranslatef(cx+x,y,0);
    cloud_model_1();
    glPopMatrix();

}
void objects()
{
    if (part_of_the_day == 1)
    {
        land();
        hill();
        Windmill_final(20,500);
        Windmill_final(590,500);
        Windmill_final(300,500);
        tree(0,0);
        tree(100,0);
        tree(50,100);
        tree(150,100);
        tree(1000,0);
        tree(1100,0);
        tree(950,100);
        tree(1050,100);
        river();
        house(50,0);
        house(400,0);
        house(230,180);
        house(500,180);
        
        sun();
        cloud(0,600);
        cloud(50,700);
        cloud(100,900);
        cloud(-800,900);
        cloud(-900,700);
        cloud(-650,600);
        cloud(-500,800);
        cloud(-100,900);
        glPushMatrix();
        glTranslatef(1200-posx, 0, 0);
        boat(150,150);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(posx, 0, 0);
        boat(0,0);
        glPopMatrix();
    }
    else
    {

        night_effect();
        land();
        star();
        hill();
        Windmill_final(20,500);
        Windmill_final(590,500);
        tree(0,0);
        tree(100,0);
        tree(50,100);
        tree(150,100);
        tree(1000,0);
        tree(1100,0);
        tree(950,100);
        tree(1050,100);
        river();
        house(50,0);
        house(400,0);
        house(230,180);
        house(500,180);
        moon();
        cloud(0,600);
        cloud(50,700);
        cloud(60,650);
        cloud(100,900);
        cloud(-800,900);
        cloud(-900,700);
        cloud(-650,600);
        cloud(-500,800);
        cloud(-100,900);
        glPushMatrix();
        glTranslatef(posx, 0, 0);
        boat(0,0);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(1200-posx, 0, 0);
        boat(150,150);
        glPopMatrix();
    }
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    objects();

    glFlush();
}
void keyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'n':
        part_of_the_day = 0;
        display();
        break;
    case 'd':
        part_of_the_day = 1;
        display();
        break;
    case 'N':
        part_of_the_day = 0;
        display();
        break;
    case 'D':
        part_of_the_day = 1;
        display();
        break;
    }
}
void update(int value)
{
    spin = spin +.5;
    if (posx >= 1200)
    {
        posx = 0;
    }
    else
    {
        posx++;
    }
    if (cx >= 1200)
    {
        cx = 0;
    }
    else
    {
        cx++;
    }
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}
void init(void)
{

    glClearColor(0.6196078431372549, 0.9333333333333333, 0.996078431372549, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0, 1200.0);
}

int main(int argc, char **argv)
{
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Smart Village");
    glutDisplayFunc(display);
    // glutDestroyWindow(Smart Village);
    glutKeyboardFunc(keyboardFunc);

    init();
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
