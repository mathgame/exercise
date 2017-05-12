#include "app/Application.h"

int main(int argc, char *argv[])
{
    Application app;
    if( app.Init() )
    {
        app.Run();
        app.Deinit();
    }

    return 0;
}
