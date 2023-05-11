#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int pid0, pid1, pid2;

int main() {

pid0 = fork();

if(pid0 != 0) {
	pid1 = fork();
	if(pid1 != 0) {
	pid2 = fork();
    }
}


printf("hello world\n");

}
