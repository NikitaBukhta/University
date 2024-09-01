#include "Core/Starter.hpp"

int main(int argc, char *argv[]) {
    auto app = Core::Starter::create(argc, argv);

    return app->main();
}