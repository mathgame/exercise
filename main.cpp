#include "app/Application.h"
#include "tools/FileSystem.h"
int main(int argc, char *argv[])
{
    fs::path exe_path = fs::canonical(fs::executable_path(argv[0]).remove_filename());
    fs::path app_path = fs::canonical(fs::path("../exercise/"), exe_path);
    fs::add_path_protocol("app:", app_path.string());


    Application app;
    if( app.Init() )
    {
        app.Run();
        app.Deinit();
    }

    return 0;
}
