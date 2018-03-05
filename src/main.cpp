#include "main.h"
#include "timer.h"
#include "ball.h"
#include "water.h"
#include "boat.h"
#include "time.h"
#include "bullet.h"
#include "unistd.h"
#include "monster.h"
#include "monster_bullet.h"
#include "gift.h"
#include "health_gift.h"
#include "man.h"
//#include "target.h"
#include "island.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Water water;
Boat boat;
HGift gift;
Man man;
Island island;
//Target cross_hair;

vector <Ball> stones;
vector <Monster> monsters;
int boat_move=0;
int man_to_move=0;
int move_flag=0;
int wind_count=0;
int global_count=0;
vector <Bullet> bullet;
vector <MBullet> m_bullet;
color_t COLOR_SKY={26,208,248};
color_t COLOR_STONE={128,128,128};
int m_fire_count=0;
vector <Gift> stars;
vector <HGift> hstars;
float screen_zoom = 0.25, screen_center_x = 0, screen_center_y = 0;
float nitro=5.0;
int nitro_on=0;

int perspective=0;
float perspective_angle=90.0;
float eyex,eyey,eyez,targetx,targety,targetz,upx,upy,upz;
int view_count=1;
int max_bullets=50;
float health=100.0;
int score=0;
int count_star=0;
int count_hstar=0;
float rot_init;
float hght_init;
Timer t60(1.0 / 60);

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
   float A = area (x1, y1, x2, y2, x3, y3);

   float A1 = area (x, y, x2, y2, x3, y3);

   float A2 = area (x1, y1, x, y, x3, y3);

   float A3 = area (x1, y1, x2, y2, x, y);

   return (A == A1 + A2 + A3);
}

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    if(view_count==1)
    {
        if(man_to_move==0)
        {
            eyex=boat.position.x;
            eyey=15.0f;
            eyez=boat.position.z;
            targetx=boat.position.x;
            targety=boat.position.y;
            targetz=boat.position.z;
            upx=0;
            upy=0;
            upz=1;
            perspective=0;
            reset_screen();
        }
        else
        {
            eyex=man.position.x;
            eyey=30.0f;
            eyez=man.position.z;
            targetx=man.position.x;
            targety=man.position.y;
            targetz=man.position.z;
            upx=0;
            upy=0;
            upz=1;
            perspective=0;
            reset_screen();
        }
    }
    else if(view_count==2)
    {
        if(man_to_move==0)
        {
        eyex=boat.position.x+5.0*sin(boat.rotation * M_PI / 180.0f);
        eyey=boat.position.y+2.3;
        eyez=boat.position.z+(5.0f*cos(boat.rotation * M_PI / 180.0f));
        targetx=boat.position.x+8.0*sin(boat.rotation * M_PI / 180.0f);
        targety=boat.position.y;
        targetz=boat.position.z+(8.0f*cos(boat.rotation * M_PI / 180.0f));
        upx=0;
        upy=1;
        upz=0;
        perspective=1;
        perspective_angle=90.0f;
        reset_screen();
        }
        else
        {
            eyex=man.position.x+5.0*sin(man.rotation * M_PI / 180.0f);
            eyey=man.position.y+2.3;
            eyez=man.position.z+(5.0f*cos(man.rotation * M_PI / 180.0f));
            targetx=man.position.x+8.0*sin(man.rotation * M_PI / 180.0f);
            targety=man.position.y;
            targetz=man.position.z+(8.0f*cos(man.rotation * M_PI / 180.0f));
            upx=0;
            upy=1;
            upz=0;
            perspective=1;
            perspective_angle=90.0f;
            reset_screen();
        }
    }
    else if(view_count==4)
    {
        if(man_to_move==0)
        {
        eyex=boat.position.x-10.0*sin(boat.rotation * M_PI / 180.0f);
        eyey=boat.position.y+2.3;
        eyez=boat.position.z-(10.0f*cos(boat.rotation * M_PI / 180.0f));
        targetx=boat.position.x;
        targety=boat.position.y;
        targetz=boat.position.z;
        upx=0;
        upy=1;
        upz=0;
        perspective=1;
        perspective_angle=90.0f;
        reset_screen();
        }
        else
        {
            eyex=man.position.x-10.0*sin(man.rotation * M_PI / 180.0f);
            eyey=man.position.y+2.3;
            eyez=man.position.z-(10.0f*cos(man.rotation * M_PI / 180.0f));
            targetx=man.position.x;
            targety=man.position.y;
            targetz=man.position.z;
            upx=0;
            upy=1;
            upz=0;
            perspective=1;
            perspective_angle=90.0f;
            reset_screen();
        }
    }
    if(view_count==5)
    {
        if(man_to_move==0)
        {
        eyex=boat.position.x-10.0*sin(rot_init * M_PI / 180.0f);
        eyey=hght_init;
        eyez=boat.position.z-(10.0f*cos(rot_init * M_PI / 180.0f));
        targetx=boat.position.x;
        targety=boat.position.y;
        targetz=boat.position.z;
        upx=0;
        upy=1;
        upz=0;
        perspective=1;
        perspective_angle=90.0f;
        reset_screen();
        }
        else
        {
            eyex=man.position.x-10.0*sin(rot_init * M_PI / 180.0f);
            eyey=hght_init;
            eyez=man.position.z-(10.0f*cos(rot_init * M_PI / 180.0f));
            targetx=man.position.x;
            targety=man.position.y;
            targetz=man.position.z;
            upx=0;
            upy=1;
            upz=0;
            perspective=1;
            perspective_angle=90.0f;
            reset_screen();
        }
    }

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye (eyex,eyey,eyez);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (targetx,targety,targetz);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (upx,upy,upz);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
//    ball1.draw(VP);
//    ball2.draw(VP);
    for(int i=0;i<stones.size();i++)
          stones[i].draw(VP);
    for(int i=0;i<bullet.size();i++)
        bullet[i].draw(VP);
    for(int i=0;i<monsters.size();i++)
        monsters[i].draw(VP);
    for(int i=0;i<m_bullet.size();i++)
        m_bullet[i].draw(VP);
    for(int i=0;i<stars.size();i++)
        stars[i].draw(VP);
    for(int i=0;i<hstars.size();i++)
        hstars[i].draw(VP);
    boat.draw(VP,nitro_on);
    man.draw(VP);
    water.draw(VP);
    double mouse_x,mouse_y;
    glfwGetCursorPos(window,&mouse_x,&mouse_y);
    if(perspective==1)
    {
        double posx=boat.position.x - 4 + mouse_x/75.0f;
        posx*=-1.0f;
        double posy=boat.position.y - 4 + mouse_y/75.0f;
        posy*=-1.0f;
//        cross_hair.set_position(posx,posy,boat.position);
//        cross_hair.rotation=boat.rotation;
//        cross_hair.draw(VP,boat.position);
    }
    island.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window,GLFW_KEY_UP);
    int down = glfwGetKey(window,GLFW_KEY_DOWN);
    int view1 = glfwGetKey(window,GLFW_KEY_1);
    int view2 = glfwGetKey(window,GLFW_KEY_2);
    int view3 = glfwGetKey(window,GLFW_KEY_3);
    int view4 = glfwGetKey(window,GLFW_KEY_4);
    int view5 = glfwGetKey(window,GLFW_KEY_5);
    int fire = glfwGetKey(window,GLFW_KEY_F);
    int get_off = glfwGetKey(window,GLFW_KEY_J);
    int enter = glfwGetKey(window,GLFW_KEY_H);
    int ntro = glfwGetKey(window,GLFW_KEY_N);
    int ntroff = glfwGetKey(window,GLFW_KEY_B);
    int jump = glfwGetKey(window,GLFW_KEY_SPACE);
    if(get_off)
    {
        man_to_move=1;
        man.translate(man_to_move);
    }
    if(enter)
    {
        man_to_move=0;
        man.set_position(boat.position.x,boat.position.y,boat.position.z);
        man.rotation=boat.rotation;
        man.translate(man_to_move);
    }
    if(ntro)
    {
        nitro_on=1;
    }
    if(ntroff)
    {
        nitro_on=0;
    }
    if (left) {
        if(man_to_move==0)
        {
        boat_move=0;
        boat.rotation+=1.0;
        man.rotation+=1.0;
        }
        else
        {
            boat_move=0;
            man.rotation+=1.0;
        }
        // Do something
    }
    else if(right)
    {
        if(man_to_move==0)
        {
        boat_move=0;
        boat.rotation-=1.0;
        man.rotation-=1.0;
        }
        else
        {
            boat_move=0;
            man.rotation-=1.0;
        }
    }
    if(jump)
    {
        if(man_to_move==0)
        {
        boat.position.y+=0.35;
        boat.speedy=-0.05;
        }
        man.position.y+=0.35;
        man.speedy=-0.05;
    }
    if(up && move_flag==0)
    {
        if(man_to_move==0)
        {
        boat_move=1;
        float speed=0.1;
        if(nitro_on==1 && nitro>=0.05)
        {
            speed=1.0;
            nitro-=0.05;
        }
        else
            nitro_on=0;
        boat.position.x+=speed*sin(boat.rotation * M_PI / 180.0f);
        boat.position.z+=speed*cos(boat.rotation * M_PI / 180.0f);
        man.set_position(boat.position.x,boat.position.y,boat.position.z);
        }
        else
        {
            float speed=0.1;
            man.position.x+=speed*sin(man.rotation * M_PI / 180.0f);
            man.position.z+=speed*cos(man.rotation * M_PI / 180.0f);
            if(isInside(island.position.x-16.0f,island.position.z-16.0*tan(M_PI/6.0),island.position.x+16.0f,island.position.z-16.0*tan(M_PI/6.0),island.position.x+0.0f,island.position.z+32.0*cos(M_PI/6.0)-16.0*tan(M_PI/6.0),man.position.x,man.position.z));
                man.position.y+=0.5;
        }
    }
    else if(down && move_flag==0)
    {
        if(man_to_move==0)
        {
        boat_move=1;
        float speed=-0.1;
        if(nitro_on==1 && nitro>=0.05)
        {
            nitro-=0.05;
            speed=-0.03;
        }
        else
            nitro_on=0;
        boat.position.x+=speed*sin(boat.rotation * M_PI / 180.0f);
        boat.position.z+=speed*cos(boat.rotation * M_PI / 180.0f);
        man.set_position(boat.position.x,boat.position.y,boat.position.z);
        }
        else
        {
            float speed=-0.1;
            man.position.x+=speed*sin(man.rotation * M_PI / 180.0f);
            man.position.z+=speed*cos(man.rotation * M_PI / 180.0f);
            if(isInside(-16.0f,-16.0*tan(M_PI/6.0),16.0f,-16.0*tan(M_PI/6.0),0.0f,32.0*cos(M_PI/6.0)-16.0*tan(M_PI/6.0),man.position.x,man.position.z));
                man.position.y-=0.5;
        }
    }
    else
    {
        boat_move=0;
    }
    if(view1)
    {
        view_count=1;
    }
    else if(view2)
    {
        view_count=2;
    }
    else if(view3)
    {
        if(man_to_move==0)
        {
        view_count=3;
        eyex=boat.position.x;
        eyey=boat.position.y+15.0f;
        eyez=boat.position.z-5.0f;
        targetx=boat.position.x;
        targety=boat.position.y;
        targetz=boat.position.z;
        upx=0;
        upy=1;
        upz=1;
        perspective=45;
        reset_screen();
        draw();
        }
        else
        {
            view_count=3;
            eyex=man.position.x;
            eyey=man.position.y+15.0f;
            eyez=man.position.z-5.0f;
            targetx=man.position.x;
            targety=man.position.y;
            targetz=man.position.z;
            upx=0;
            upy=1;
            upz=1;
            perspective=45;
            reset_screen();
            draw();
        }
    }
    else if(view4)
    {
        view_count=4;
    }
    else if(view5)
    {
        if(man_to_move==0)
        {
        view_count=5;
        rot_init=boat.rotation;
        hght_init=boat.position.z+10;
        }
        else
        {
            view_count=5;
            rot_init=man.rotation;
            hght_init=man.position.z+15;
        }
    }
    if(fire && bullet.size()<max_bullets)
    {
        if(man_to_move==0)
            bullet.push_back(Bullet(boat.position.x,boat.position.z,COLOR_RED,boat.rotation));
        else
            bullet.push_back(Bullet(man.position.x,man.position.z,COLOR_RED,man.rotation));
    }
}

void tick_elements() {
    if(detect_collision(island.bounding_box,man.bounding_box)&&man.position.y>=10.0)
    {
        score+=100;
        island.position.x*=-1;
        island.position.z*=-1;
//        sleep(2);
//        quit(window);
    }
    gift.tick();
    island.tick();
    boat.tick(boat_move);
    man.tick(boat_move);
    move_flag=0;
    for(int i=0;i<stars.size();i++)
    {
        stars[i].tick();
    }
    for(int i=0;i<hstars.size();i++)
    {
        hstars[i].tick();
    }
    if(wind_count==500)
        wind_count=0;
    if(wind_count!=0)
    {
        boat.position.x+=0.05*cos(boat.rotation * M_PI / 180.0f)*(float)(500-wind_count)/500.0f;
        boat.position.z+=0.05*sin(boat.rotation * M_PI / 180.0f)*(float)(500-wind_count)/500.0f;
        if(man_to_move==0)
            man.set_position(boat.position.x,boat.position.y,boat.position.z);
        wind_count++;
    }
    for(int i=0;i<stars.size();i++)
    {
        if(detect_collision_powerup(stars[i].bounding_box))
        {
            if(count_star==700)
            {
                nitro+=5.0;
                stars.erase(stars.begin()+i);
                i--;
                count_star=0;
            }
            else
                count_star++;
        }
    }
    for(int i=0;i<hstars.size();i++)
    {
        if(detect_collision_powerup(hstars[i].bounding_box))
        {
            if(count_hstar==700)
            {
                hstars.erase(hstars.begin()+i);
                i--;
                if(health<=99.5)
                    health+=0.5f;
                else
                    health=100.0f;
                count_hstar=0;
            }
            else
            {
                count_hstar++;
            }
        }
    }
    for(int i=0;i<stones.size();i++)
    {
            if(detect_collision(boat.bounding_box,stones[i].bounding_box))
            {
//                printf("Collided\n");
                health-=0.05;
//                printf("%f\n",health);
            }
            for(int j=0;j<bullet.size();j++)
            {
                if(detect_collision(stones[i].bounding_box,bullet[j].bounding_box))
                {
                    stones.erase(stones.begin()+i);
                    score+=1;
                    i--;
                }
            }
    }
    for(int i=0;i<bullet.size();i++)
    {
        bullet[i].position.x+=0.3*sin(bullet[i].rotation * M_PI / 180.0f);
        bullet[i].position.z+=0.3*cos(bullet[i].rotation * M_PI / 180.0f);
        if(bullet[i].position.x<=boat.position.x-100 || bullet[i].position.z<=boat.position.z-100 || bullet[i].position.z>=boat.position.z+100 || bullet[i].position.x>=boat.position.x+100)
        {
            bullet.erase(bullet.begin()+ i);
            i--;
        }
    }
    for(int i=0;i<monsters.size();i++)
    {
        float mx=monsters[i].position.x;
        float mz=monsters[i].position.z;
        float bx=boat.position.x;
        float bz=boat.position.z;
        if((mx-bx)*(mx-bx)+(mz-bz)*(mz-bz)<=10000)
        {
            if(mz>bz)
                monsters[i].rotation=-1.0*(atan((bx-mx)/(mz-bz))*180.0f/M_PI);
            else
                monsters[i].rotation=180+(-1.0*(atan((bx-mx)/(mz-bz))*180.0f/M_PI));
            if(m_fire_count==0)
            {
                m_bullet.push_back(MBullet(monsters[i].position.x,monsters[i].position.z,COLOR_GREEN,monsters[i].rotation));
            }
            m_fire_count++;
            if(m_fire_count>=40)
                m_fire_count=0;
//            printf("%f\n",monsters[i].rotation);
        }
        for(int j=0;j<bullet.size();j++)
        {
            if(detect_collision(monsters[i].bounding_box,bullet[j].bounding_box))
            {
                monsters.erase(monsters.begin()+i);
                score+=5;
                i--;
            }
        }
    }
    for(int i=0;i<m_bullet.size();i++)
    {
        m_bullet[i].position.x+=m_bullet[i].factor*0.3*sin(m_bullet[i].rotation * M_PI / 180.0f);
        m_bullet[i].position.z+=m_bullet[i].factor*0.3*cos(m_bullet[i].rotation * M_PI / 180.0f);
        if(m_bullet[i].position.x<=m_bullet[i].initx-100 || m_bullet[i].position.z<=m_bullet[i].initz-100 || m_bullet[i].position.z>=m_bullet[i].initz+100 || m_bullet[i].position.x>=m_bullet[i].initx+100)
        {
            m_bullet.erase(m_bullet.begin()+ i);
            i--;
        }
        if(detect_collision(m_bullet[i].bounding_box,boat.bounding_box))
        {
            health-=0.01;
            m_bullet.erase(m_bullet.begin()+ i);
            i--;
        }
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    srand((unsigned int)time(NULL));
    island=Island(500,500,COLOR_GREEN);
    /* Objects should be created before any other gl function and shaders */
    // Create the models

//    ball1       = Ball(0, 0, COLOR_GREEN);
    double mouse_x,mouse_y;
    glfwGetCursorPos(window,&mouse_x,&mouse_y);
    double posx=boat.position.x - 4 + mouse_x/75.0f;
    double posy=boat.position.x - 4 + mouse_y/75.0f;
//    cross_hair=Target(posx,posy,COLOR_RED);

    boat=Boat(0,0,0);
    man=Man(boat.position.x,boat.position.y,boat.position.z);
    boat.speed=0;
//    ball2       = Ball(-5, -5, COLOR_RED);
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
        {
            float factorx,factory;
            if(i%2==0)
                factorx=-1.0f;
            else
                factorx=1.0f;
            if(j%2==0)
                factory=-1.0f;
            else
                factory=1.0f;
            stones.push_back(Ball(((float)20*i+(float)(rand()/(float)(RAND_MAX/20.0f))-10.0f)*factorx,((float)20*j+(float)(rand()/(float)(RAND_MAX/20.0f))-10.0f)*factory,COLOR_STONE));
        }
    }
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            float factorx,factory;
            if(i%2==0)
                factorx=-1.0f;
            else
                factorx=1.0f;
            if(j%2==0)
                factory=-1.0f;
            else
                factory=1.0f;
            monsters.push_back(Monster(((float)100*i+(float)(rand()/(float)(RAND_MAX/100.0f))-50.0f)*factorx,((float)100*j+(float)(rand()/(float)(RAND_MAX/100.0f))-50.0f)*factory,COLOR_BLACK));
            stars.push_back(Gift(((float)100*i+(float)(rand()/(float)(RAND_MAX/100.0f))-50.0f)*factorx+10.0,((float)100*j+(float)(rand()/(float)(RAND_MAX/100.0f))-50.0f)*factory+15.0));
            hstars.push_back(HGift(((float)100*i+(float)(rand()/(float)(RAND_MAX/100.0f))-50.0f)*factorx+20.0,((float)100*j+(float)(rand()/(float)(RAND_MAX/100.0f))-50.0f)*factory+30.0));
        }
    }
    water = Water(0, 0, 0);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_SKY.r / 256.0, COLOR_SKY.g / 256.0, COLOR_SKY.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            if(health<=0)
            {
                sleep(1);
                quit(window);
            }
            // 60 fps
            // OpenGL Draw commands
            global_count++;
            if(global_count%1000==0)
            {
                    wind_count++;
                    global_count=0;
            }
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            char hlt[501]={};
            sprintf(hlt,"Health %f        Score %d       Nitro %f",health,score,nitro);
            glfwSetWindowTitle(window,hlt);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}
bool detect_collision_powerup(bounding_box_t a) {
    return (abs(a.x - boat.position.x) * 2 < (a.width + 3.0)) &&
           (abs(a.y - boat.position.y) * 2 < (a.height + 2.0));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    if(perspective==0)
        Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
    else
        Matrices.projection = glm::perspective (perspective_angle, (GLfloat) top / (GLfloat) right, 0.1f, 500.0f);
}
void height_change(float ht)
{
    if(view_count==5)
        hght_init+=ht;
    if(hght_init<1.0 && ht<0)
        hght_init-=ht;
}
void rotation_change(float rot)
{
    if(view_count==5)
        rot_init+=rot;
}
