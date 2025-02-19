#include "AppLayer.h"

using namespace GLCore;
using namespace GLCore::Utils;

AppLayer::AppLayer()
    : m_VAO(0), m_VBO(0)
{
}

AppLayer::~AppLayer()
{
}

void AppLayer::OnEvent(Event& event)
{
    // Event handling
}

void AppLayer::OnAttach()
{
    EnableGLDebugging();

    // Define triangle vertices (x, y, z)
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,  // Bottom-left
         0.5f, -0.5f, 0.0f,  // Bottom-right
         0.0f,  0.5f, 0.0f   // Top
    };

    // Create VAO
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    // Create VBO
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Define vertex attribute (position)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

    // Unbind VAO
    glBindVertexArray(0);
}

void AppLayer::OnDetach()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
}

void AppLayer::OnUpdate(Timestep ts)
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Bind VAO and draw triangle
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

void AppLayer::OnImGuiRender()
{
    // UI Controls
}
