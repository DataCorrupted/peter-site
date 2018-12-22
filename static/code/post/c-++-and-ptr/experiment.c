#include <stdio.h>

void printResult(const char* op, int* head, int retVal, int* p){
	printf("op: %s.\t head[0]==%d, head[1]==%d, retVal==%d, *p==%d\n", 
		op, head[0], head[1], retVal, *p);
}

int main() {
	int head[2];
	int *p;
	int retVal;

	head[0] = 10; head[1] = 20;
	p = head; retVal = *++p;
	printResult("*++p"  , head, retVal, p);

	head[0] = 10; head[1] = 20;
	p = head; retVal = ++*p;
	printResult("++*p"  , head, retVal, p);

	head[0] = 10; head[1] = 20;
	p = head; retVal = *p++;
	printResult("*p++"  , head, retVal, p);

	head[0] = 10; head[1] = 20;
	p = head; retVal = *(p++);
	printResult("*(p++)", head, retVal, p);

	head[0] = 10; head[1] = 20;
	p = head; retVal = (*p)++;
	printResult("(*p)++", head, retVal, p);

	return 0;
}
