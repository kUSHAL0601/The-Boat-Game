#include "main.h"
#include "timer.h"
#include "ball.h"
#include "water.h"
#include "boat.h"
#include "time.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1;
//Ball ball2;
Water water;
Boat boat;
Ball stones[50][50];
int boat_move=0;
int move_flag=0;
int wind_count=0;
int global_count=0;

color_t COLOR_SKY={26,208,248};
color_t COLOR_STONE={128,128,128};

float screen_zoom = 0.25, screen_center_x = 0, screen_center_y = 0;

int perspective=0;
float perspective_angle=90.0;
float eyex,eyey,eyez,targetx,targety,targetz,upx,upy,upz;
int view_count=1;

Timer t60(1.0 / 60);

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
    else if(view_count==2)
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
    else if(view_count==4)
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
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            stones[i][j].draw(VP);
    boat.draw(VP);
    water.draw(VP);
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
    if (left) {
        boat_move=0;
        boat.rotation+=1.0;
        // Do something
    }
    else if(right)
    {
        boat_move=0;
        boat.rotation-=1.0;
    }
    if(up && move_flag==0)
    {
        boat_move=1;
        float speed=0.1;
        boat.position.x+=speed*sin(boat.rotation * M_PI / 180.0f);
        boat.position.z+=speed*cos(boat.rotation * M_PI / 180.0f);
    }
    else if(down && move_flag==0)
    {
        boat_move=1;

        float speed=-0.1;
        boat.position.x+=speed*sin(boat.rotation * M_PI / 180.0f);
        boat.position.z+=speed*cos(boat.rotation * M_PI / 180.0f);
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
    else if(view4)
    {
        view_count=4;
    }
}

void tick_elements() {
//    ball1.tick();
//    boat.tick(boat_move);
    move_flag=0;
    if(wind_count==500)
        wind_count=0;
    if(wind_count!=0)
    {
        boat.position.x+=0.05*cos(boat.rotation * M_PI / 180.0f)*(float)(500-wind_count)/500.0f;
        boat.position.z+=0.05*sin(boat.rotation * M_PI / 180.0f)*(float)(500-wind_count)/500.0f;
        wind_count++;
    }
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            if(detect_collision_bs(i,j))
            {
                move_flag=1;
            }
        }
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    srand((unsigned int)time(NULL));
    /* Objects should be created before any other gl function and shaders */
    // Create the models

//    ball1       = Ball(0, 0, COLOR_GREEN);
    boat=Boat(0,0,0);
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
            stones[i-1][j-1]=Ball(((float)20*i+(float)(rand()/(float)(RAND_MAX/20.0f))-10.0f)*factorx,((float)20*j+(float)(rand()/(float)(RAND_MAX/20.0f))-10.0f)*factory,COLOR_STONE);
        }
    }
    water       = Water(0, 0, 0);

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
bool detect_collision_bs(int i,int j)
{
    bounding_box_t b=stones[i][j].bounding_box;
    return (abs(boat.position.x - b.x) * 2 < (3.0*sin(boat.rotation * M_PI / 180.0f) + b.width)) &&
           (abs(boat.position.z - b.y) * 2 < (8.0*cos(boat.rotation * M_PI / 180.0f) + b.height));

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
