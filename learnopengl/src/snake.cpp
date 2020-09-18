#include "snake.h"

void Snake::Init()
{
    // shader
    shader = new Shader("shaders/v_shader.glsl", "shaders/f_shader.glsl");

    // set up vertex data (and buffer(s)) and configure vertex 
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

}

void Snake::Move()
{
    body.erase(body.end());

    if (direction == S_FORWARD)
        z += 1;
    if (direction == S_BACKWARD)
        z -= 1;
    if (direction == S_LEFT)
        x -= 1;
    if (direction == S_RIGHT)
        x += 1;

    body.push_front(glm::vec3(x, y, z));
}

void Snake::Draw()
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    shader->use();

    for (auto i = body.begin(); i != body.end(); ++i)
    {
        glm::mat4 model(1.0f);
        glm::translate(model, *i);

        shader->setMat4("model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}

void Snake::ChangeDirection(Snake_Direction newDirection)
{
    if ((direction == S_RIGHT) && (newDirection == S_RIGHT))
        nextDirection = newDirection;
    if ((direction == S_LEFT) && (newDirection == S_RIGHT))
        nextDirection = newDirection;
    if ((direction == S_FORWARD) && (newDirection == S_BACKWARD))
        nextDirection = newDirection;
    if ((direction == S_BACKWARD) && (newDirection == S_FORWARD))
        nextDirection = newDirection;
}

void Snake::updateViewMatrix(glm::mat4 viewMatrix)
{
    shader->setMat4("view", viewMatrix);
}

Snake::~Snake()
{
    delete shader;

    //de - allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}