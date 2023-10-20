#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*Read or writing buffer*/
#define RAED_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*Command chaining*/
#define CMD_NORM          0
#define CMD_OR            1
#define CMD_AND           2
#define CMD_CHAIN         3

/*System getline()*/
#define USE_GETLINE       0
#define USE_STRTOK        0

#define HIST_FILE         ".simple_shell_history"
#define HIST_MAX          4096

extern char **environ;

/*Convert number*/
#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/**
 * struct liststr - singly linked list
 * @num: Number field
 * @str: String
 * @next: Points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Contains pseuodo arguments to pass to the function
 * so that uniform prototype for function pointer struct
 * @path: String patch for command
 * @environ: Environ from LL env
 * @arg: String from getline containing argument
 * @argv: Array of string generated arg
 * @argc: Argument count
 * @fname: Program filename
 * @alias: Alias node
 * @status: Return status of last exec'd command
 * @readfd: fd from which to read line input
 * @histcount: History line number count
 * @err_num: Error code for exit ()s
 * @line_count: Error count
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @cmd_buf: Address of pointer
 * @history: History node
 * @env_changed: Environ was changed
 * @env: Linked list
 * @linecount_flag: Count this line of input
 */
typedef struct passinfo
{
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	char *arg;
	char *path;
	char **argv;
	int argc;
	int env_changed;
	int status;
	char *fname;
	unsigned int line_count;
	int linecount_flag;
	char **cmd_buf;
	int cmd_buf_type;
	int histcount;
	int readfd;
} info_t;

#define INFO_INIT 
\ {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL,
	0, 0, NULL, \ 0, 0, 0}

/**
 * struct builtin - Contains a builtin string and related function
 * @type: Builtin command flag
 * @func: Function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _eputchar(char);

/* toem_shloop.c */
void fork_cmd(info_t *);
int find_builtin(info_t *);
void find_cmd(info_t *);
int hsh(info_t *, char **);

/* toem_string.c */
char *starts_with(const char *, const char *);
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcat(char *, char *);

/* toem_parser.c */
char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
void _puts(char *);
int _putchar(char);
char *_strdup(const char *);

/* toem_exits.c */
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow2(char *, char);
char **strtow(char *, char *);

/* toem_memory.c*/
int bfree(void **);

/* toem_errors1.c */
int print_d(int, int);
int _erratoi(char *);
char *convert_number(long int, int, int);
void remove_comments(char *);
void print_error(info_t *, char *);

/* toem_realloc.c */
void ffree(char **);
char *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);

/* toem_atoi.c */
int _isalpha(int);
int _atoi(char *);
int interactive(info_t *);
int is_delim(char, char *);

/* toem_getinfo.c */
void set_info(info_t *, char **);
void free_info(info_t *, int);
void clear_info(info_t *);

/* toem_builtin.c */
int _mycd(info_t *);
int _myhelp(info_t *);
int _myexit(info_t *);

/* toem_builtin1.c */
int _myalias(info_t *);
int _myhistory(info_t *);

/* toem_getline.c */
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
ssize_t get_input(info_t *);

/* toem_history */
int write_history(info_t *info);
int *get_history_file(info_t *info);
int build_history_list(info_t  *info, char *buf, int linecount);
char read_history_file(info_t *info);
int renumber_history(info_t *info);

/* toem_environ */
int _myenv(info_t *);
int _myunsetenv(info_t *);
char *_getenv(info_t *, const char *);
int _mysetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
char **get_environ(info_t *);


/* toem_lists1.c */
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
size_t list_len(const list_t *);
ssize_t get_node_index(list_t *, list_t *);
list_t *node_starts_with(list_t *, char *, char);

/* toem_vars.c */
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_vars(info_t *);
int replace_alias(info_t *);
int is_chain(info_t *, char *, size_t *);
int replace_string(char **, char *);

/* toem_lists.c */
list_t *add_node_end(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node(list_t **, const char *, int);
size_t print_list_str(const list_t *);
void free_list(list_t **);

#endif
