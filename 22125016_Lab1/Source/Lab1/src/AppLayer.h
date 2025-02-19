#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

class AppLayer : public GLCore::Layer
{
public:
	AppLayer();
	virtual ~AppLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(GLCore::Event& event) override;
	virtual void OnUpdate(GLCore::Timestep ts) override;
	virtual void OnImGuiRender() override;
private:
	GLuint m_VAO, m_VBO;
};