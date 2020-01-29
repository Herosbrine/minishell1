/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>

typedef struct s_data t_data;
struct s_data {
    int y;
    int pwd;
    char **envp;
};

//  EVAL_EXPR.C
int eval_expr(char const *str);

//  CALCUL.C
char infin_basic_ope(char const *str, char *result, int i, int a);
char infin_ope(char const *str, char *result, int i, int a);

//  PARENTHESES.C
int manage_parentheses(char *str, char *stk, int i);

//  MANAGES_ERRORS.C
int manage_ope(char const *str, int i);
int manage_errors(char const *str);

// DO_OP.C
int do_op(char *nb1, char *nb2, char *signe);
int value_k(char *expr);
char *find_nb1(char * expr, int k);
char *find_nb2(char * expr, int k);
char *find_signe(char * expr, int k);

// INFIN_ADD.C
char *infin_add(char *nb1, char *nb2);

// OTHER FUNCTIONS
int my_strlen(char const *str);
int my_put_nbr(int nbr);
void my_putchar(char c);
int my_getnbr(char *str);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_put_nbr2(unsigned int nbr);

//octal
int my_put_octal(unsigned nbr);
int my_put_hexa(unsigned nbr);
int my_put_space(int i, char const *format);
int my_flag(int i, va_list paramsinfos, char const * format, ...);
int my_printf(char const * format, ...);
int my_printf2(int *i, va_list paramsinfos, char const * format, ...);
int my_put_hexa_min(unsigned nbr);
int my_put_binary(unsigned int nbr);
void info_file(char *filepath);

//Programs
char *one_space(char *buffer);
char *delete_first_space(char *save);
int my_strcmp(char *s1, char *s2, int size);
int shell_loop(char **envp, t_data *cordonnee);
char **read_user_input(char **envp, t_data *cordonnee);
char **count_word(char *buffer);
char **position_a(int *a, char *buffer);
int find_path(char **src);
char **my_str_envp_array(int *a, char *buffer);
int my_exit(char **argv);
int parsing_path(char **all_argv, char *argv, char **envp);
int count_word_envp(char *buffer);
char **my_str_envp_array(int *a, char *buffer);
char *my_strcat(char *dest, char *src);
char *my_strdup(char *str);
int my_cd(char **argv, char **envp, char *envi);
int my_unsetenv(char **argv, t_data *cordonnee);
int find_home_path(char **src);
int my_setenv(char **argv, t_data *cordonnee);
char *my_strcat2(char *dest, char *src);
int check_command(char **argv, char **envp, t_data *cordonnee);
int my_env(char **argv, t_data *cordonnee);
int find_pwd_path(char **src);

#endif