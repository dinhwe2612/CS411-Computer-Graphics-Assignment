#include "GLCore.h"
#include "AppLayer.h"

using namespace GLCore;

class App : public Application
{
public:
	App()
	{
		PushLayer(new AppLayer());
	}
};

int main()
{
	std::unique_ptr<App> app = std::make_unique<App>();
	app->Run();
}