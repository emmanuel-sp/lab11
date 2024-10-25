#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

void f(int);
double sum;

int main(int argc, char * argv[]) {
	pid_t PID = getpid();
	printf("Program started with pid = %d\n", PID);
	printf("Enter a list of doubles to sum,\n");
	printf("and to end the program,\n");
	printf("run one of the following Unix commands:\n");
	printf("\tkill -8 %d\n", PID);
	printf("\tkill -10 %d\n", PID);
	printf("\tkill -12 %d\n", PID);
	double input;
	sum = 0;
	signal(8, f);
	signal(10, f);
	signal(12, f);
	while (1==1) {
		int ret = scanf("%lf", &input);
		if (ret == 0) {
			char s;
			scanf("%s", &s);
			printf("Error:\tplease input a numeric value.\n");
		} else if (ret < 0) {
			//printf("End of file\n");
			sleep(60);
			printf("Program ended after sleeping for 60 seconds.\n");
			exit(0);
		} else {
			//printf("%lf\n", input);
			sum += input;
		}
	}
	return 0;
}
void f(int signum) {
	printf("The sum is %lf.\n", sum);
	printf("Program ended by handling the signal from kill -%d %d.\n", signum, getpid());
	exit(0);
}
