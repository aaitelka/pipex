#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
int main()
{
	char **args;
	int fd= open("infile.x", O_RDONLY);
	args = malloc (3 * sizeof(char *));
	args[0] = strdup("/usr/bin/grep");
	args[1] = strdup("a1");
	args[2] = NULL;
	dup2(fd, 0);
	execve (args[0], args, NULL);
}