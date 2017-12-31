#include "core/game.h"
#include "view/App/app.h"
#include "util/common.h"
#include <iostream>

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);

  try {
    App* app = new App(1024, 768, 60);
    app->Run();

    delete app;
  } catch (const char* msg) {
    LOG_FATAL("Caught Exception : %s", msg);
    return 1;
  }

	return 0;
}
