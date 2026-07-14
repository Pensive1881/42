#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stddef.h>

# define WIDTH 1000
# define HEIGHT 700
# define EPSILON 0.000001
# define SHADOW_BIAS 0.0001

typedef struct s_vec { double x; double y; double z; } t_vec;
typedef struct s_color { double r; double g; double b; } t_color;
typedef struct s_ray { t_vec origin; t_vec dir; } t_ray;

typedef enum e_type { SPHERE, PLANE, CYLINDER } t_type;

typedef struct s_object
{
	t_type type;
	t_vec pos;
	t_vec dir;
	double radius;
	double height;
	t_color color;
	struct s_object *next;
} t_object;

typedef struct s_camera { t_vec pos; t_vec dir; double fov; } t_camera;
typedef struct s_light { t_vec pos; double ratio; t_color color; } t_light;
typedef struct s_hit { double t; t_vec point; t_vec normal; t_object *object; } t_hit;

typedef struct s_scene
{
	t_color ambient_color;
	double ambient_ratio;
	t_camera camera;
	t_light light;
	t_object *objects;
	int has_ambient;
	int has_camera;
	int has_light;
} t_scene;

typedef struct s_app
{
	void *mlx;
	void *win;
	void *img;
	char *pixels;
	int bits;
	int line_len;
	int endian;
	t_scene scene;
} t_app;

/* vector */
t_vec vec(double x, double y, double z);
t_vec vadd(t_vec a, t_vec b);
t_vec vsub(t_vec a, t_vec b);
t_vec vscale(t_vec v, double n);
double vdot(t_vec a, t_vec b);
t_vec vcross(t_vec a, t_vec b);
double vlen(t_vec v);
t_vec vnorm(t_vec v);

/* parsing */
int parse_scene(const char *path, t_scene *scene);
int split_fields(char *line, char **fields, int max);
int parse_double(const char *s, double *out);
int parse_vec(const char *s, t_vec *out);
int parse_color(const char *s, t_color *out);
int in_range(double value, double min, double max);

/* rendering */
int closest_hit(t_scene *scene, t_ray ray, double max_t, t_hit *hit);
void render(t_app *app);
int open_window(t_app *app);
int close_app(t_app *app);
void free_scene(t_scene *scene);
void fatal(t_app *app, const char *message);

#endif
