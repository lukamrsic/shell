#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64

char**parse_input(char *input){
    char **args = malloc(MAX_ARGS * sizeof(char*)); 
    int i = 0;
    char *token = strtok(input, " \t\n"); 
    while(token != NULL && i < MAX_ARGS - 1){
        args[i] = token; 
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;     
    return args; 
}
void execute(char **args){
    if(args[0] == NULL){
        return;
    }
    if(strcmp(args[0], "cd")==0){
        if(args[1] == NULL){
            fprintf(stderr, "cd: nedostaje argument\n");
        }else{
            if(chdir(args[1])!= 0){
                perror("cd");
            }
        }
        return;
    }
    if (strcmp(args[0], "exit") == 0){
        exit(0);
    }
    pid_t pid = fork(); 
    if (pid == 0){
        execvp(args[0], args); 
        perror("greska");
        exit(1); 
    }else if (pid > 0){
        int status; 
        waitpid(pid, &status, 0); 
    }else{
        perror("fork nije uspio");
    }
}

int main(){
    char input[1024];

    while(1){
        printf("mojshell> ");
        if(fgets(input,sizeof(input),stdin)==NULL){
            break;
        }
        char **args = parse_input(input); 
        execute(args);
        free(args);
    }
    return 0; 
}