#ifndef ENGLIBS_H
#define ENGLIBS_H


int _atoi(char *s);
char *_getchar();
char *_tostring(int n);
int _strlen(char *s);
int *read_window(void);
char **screen(int *dim);
char **get_pixels(int *dim, int lenght);
int draw(char **screen, char **pixels, int *dim);
void *set_listener();
void *set_timer();
char ***_obj(int n);
int obj_trans(char **ob, int code);
char *mov_coord(char *x, char *y);
int delay(float del);
void print_time();
extern char **pixels;
extern char **scn;

#endif /* ENGLIBS_H */
