#include "minirt.h"
#include <string.h>

int main(int argc, char **argv)
{
	t_app app;

	memset(&app, 0, sizeof(app));
	if (argc != 2)
		fatal(&app, "usage: ./miniRT scene.rt");
	if (!parse_scene(argv[1], &app.scene))
		fatal(&app, "invalid scene file");
	if (!open_window(&app))
		fatal(&app, "could not initialize MiniLibX");
	return (0);
}
