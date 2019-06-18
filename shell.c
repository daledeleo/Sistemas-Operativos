
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

//quitando el salto de linea
void reemplazar(char *linea)
{
	while (*linea != 0)
	{
		if (*linea == '\n')
		{
			*linea = 0;
		}
		linea++;
	}
}

int main()
{
	int fds[2];

	char buf[100] = {0};
	char *args[10] = {0};
	pid_t cpid;
	
	printf("pid del padre %d\n", getpid());
	while (1)
	{

		printf("$ ");
		fgets(buf, 100, stdin);
		reemplazar(buf);
		/*
		int i = 0;
		char *valor;
		args[i] = strdup(strtok(buf, " "));
		i++;		
		while( (valor = strtok(NULL, " ")) != NULL ){
			args[i] = strdup(valor);
			i++;
		}
		*/
		if (strcmp(buf, "exit") != 0)
		{
			strcat("/bin/", buf)
			printf("%s\n", buf);
			fflush(stdout);
			if (pipe(fd) == -1) {	// creando un pipe
				fprintf(stderr,"Pipe fallado");
				return 1;
			} 
			pid_t pid = fork();
			if (pid > 0)	//proceso del padre
			{
				close(fds[0]); //close stdin
				dup(fds[0]);   // redirect standard input to the pipe table
				write(fds[1], buf, strlen(buf) + 1);
				close(fds[1]);

				int stat = -1;
				waitpid(cpid, &stat, 0);
				
			}
			else
			{
				close(fds[1]); //close stdin
				dup(fds[1]);   // redirect standard output to the pipe table
				char read_msg[strlen(buf) + 1];
				read(fds[1], read_msg, strlen(buf) + 1);
				close(fds[0]);
				int res = execvp(read_msg, args);
				printf("Error de execl %d", res);
			}
		}else{
			exit(0);
		}
	}
	return 1;
}
