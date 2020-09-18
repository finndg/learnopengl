#ifndef SNAKE_H
#define SNAKE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"

#include <deque>

enum Snake_Direction
{
    S_FORWARD,
    S_BACKWARD,
    S_LEFT,
    S_RIGHT
};

class Snake
{
public:
    void Init();
    void Move();
    void Draw();
    void ChangeDirection(Snake_Direction newDirection);
    void updateViewMatrix(glm::mat4 viewMatrix);
    ~Snake();
    
private:
    float x = 0, y = 0, z = 0;
    std::deque<glm::vec3> body = { glm::vec3(x, y, z), glm::vec3(x, y, z) , glm::vec3(x, y, z) };
    GLuint VAO = 0, VBO = 0;
    Snake_Direction direction = S_RIGHT, nextDirection = S_RIGHT;
    Shader *shader;

    float vertices[216] =
    {
        -0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,
         0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,
         0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,

        -0.5f, -0.5f,  0.5f,     0.0f, 0.3f, 0.0f,
         0.5f, -0.5f,  0.5f,     0.0f, 0.3f, 0.0f,
         0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,     0.0f, 0.3f, 0.0f,

        -0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,
        -0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,
        -0.5f, -0.5f,  0.5f,     0.0f, 0.3f, 0.0f,
        -0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,
         0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,
         0.5f, -0.5f,  0.5f,     0.0f, 0.3f, 0.0f,
         0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,
         0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,
         0.5f, -0.5f,  0.5f,     0.0f, 0.3f, 0.0f,
         0.5f, -0.5f,  0.5f,     0.0f, 0.3f, 0.0f,
        -0.5f, -0.5f,  0.5f,     0.0f, 0.3f, 0.0f,
        -0.5f, -0.5f, -0.5f,     0.0f, 0.3f, 0.0f,

        -0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f
    };
};

#endif