#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int factorial(int);
int sumnation(int);

int main(int numInputs, char* commandLine[])
{
	pthread_t factThread, sumThread;

	int inputParameters[1];
	inputParameters[0] = atoi(commandLine[0]);

	if(pthread_create(&factThread, NULL, factorial, inputParameters) == 0) //WHY IS 0 ERROR
	{
		printf("Thread 1 Failed");
		return -1;
	}

	if(pthread_create(&sumThread, NULL, sumnation, inputParameters) == 0) //WHY IS 0 ERROR
	{
		printf("Thread 2 Failed");
		return -1;
	}

	int* sumResult;
	int* factResult;
	void* sumBuffer;
	void* factBuffer;

	pthread_join(sumThread, sumBuffer);	
	pthread_join(factThread, factBuffer);	

	sumResult = (int *)sumBuffer;
	factResult = (int *)factBuffer;

	printf("Final Sum Result %d", *sumResult);
	printf("Final Factorial Result %d", *factResult);

}


int factorial(int inputtedNum)
{
	int sum = 1;
	for(int i = 1; i <= inputtedNum; i++)
	{
		sum *= i;
	}
	return sum;
}

int sumnation(int num) //PARK WILL LOVE THIS
{return (num + 1) * ((int) (num / 2)) + (num % 2) * ((num + 1) / 2);}
