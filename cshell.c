#<stdio.h>
#<stdlib.h>

/* Initialize 
shell reads and executes it's configuration files 
which impacts the shells behavior
*/

/*Interpret
shell interprets and executes commands from stdin (interactive or a file)

*/
/* Terminate
After execution of commands has finished, the shell lastly
executes the shutdown commands, frees up memory, and terminates


/*
read the command from std input
parse and separate the command string into a program and args
execute the parsed 
*/

char *lsh_read_line(void)
{
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // read a character
        c = getchar();

        // If EOF, replace with null char and return
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++

        // If we have exceeded buffer, reallocate.

        if (position >= bufsize) {
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprint(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void lsh_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);

    } while (status);

}


int main(int argc, char **argv)
{

    return EXIT_SUCCESS;
}
