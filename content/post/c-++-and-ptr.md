
+++

title = "All you wanted to know about the combination of '++' and '*' combinations in C"

date = 2018-12-21T18:45:00
lastmod = 2018-12-22T11:21:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = ["C", "C++", "Programming"]
summary = "Skip this post if you are not confused by *++p, ++*p, *p++, *(p++), and (*p)++."

+++

There are times I would call Halloween when programming C. 
It is when you would expect ghosts dancing in your yard and you can do nothing about it.
The combination of "++" and "\*" is one of the worst.
I have been arguing against this way of coding for a long time because I believe every piece of code should be readable by HUMAN. (yes, not COMPILERS!)

However, this coding style appears regardless of my willingness.
Therefore, I have to write about all the possible (ugly) usage of the combinations here.

## Rules

DO NOTICE THAT WHEN IT COMES TO PREFIX INC/DEC, POSTFIX INC/DEC, AND DEREFERENCE, C AND C++ SHARE THE SAME RULE.

| Precedence 	| Operator 	| Description                            	| Associativity 	|
|------------	|----------	|----------------------------------------	|---------------	|
| 1          	| ++/- -   	| Suffix/postfix increment and decrement 	| Left to Right 	|
| 2          	| ++/- -  	| Prefix increment and decrement         	| Right to Left 	|
| 2          	| *        	| Indirection (dereference)              	| Right to Left 	|

## The Easy Part

The postfix and prefix are complicated enough.
Fine, it's not easy at all.
So I decided to write them first.

Suppose we have:
```c
int i = 10;
```

### ++i

```c
i += 1;
return i;
```
### i++

```c
int tmp = i; 
i += 1;
return tmp;
```
## Hallowing

We suppose we have:
```c
int* p = head;
```

we will expand the operation as a simple function. 
But do notice that this DOES NOT mean that the compilers will compile these operators this way. 
This is just a show of concept how these operators work.

### \*++p

Prefix increment get executed first, and the result value is returned for dereference.

```c
p = p + 1;
assert(p == head + 1);
return *p;
```

### ++\*p

Dereference get executed first, then we would increment the object itself and return the result.

```c
assert(p == head);
*p = *p + 1;
return *p; // *p has been incremented.
```

### \*p++

Postfix increment has higher precedence. Yet the result is not returned. So the dereferenced object is the one pointed by original p.

```c
int* tmp = p;
p = p + 1;
assert(p == head + 1);
return *tmp;
```

### \*(p++)

Postfix increment has higher precedence, it doesn't change with the presence of parentheses.
Same as \*p++.

### (\*p)++

ALMOST the same with ++\*p.
But the increment is changed to postfix one, so the return value changed.
The parentheses have higher precedence, thus dereference is carried first, then postfix increment.

```c
assert(p == head);
int tmp = *p
*p = (*p) + 1;
return tmp;
```

## Experiment

You may download [this code](../../code/post/c-++-and-ptr/experiment.c) and [Makefile](../../code/post/c-++-and-ptr/Makefile) form the link provided.
```c
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
```

and we can get the following result:
```
op: *++p.	 head[0]==10, head[1]==20, retVal==20, *p==20
op: ++*p.	 head[0]==11, head[1]==20, retVal==11, *p==11
op: *p++.	 head[0]==10, head[1]==20, retVal==10, *p==20
op: *(p++).	 head[0]==10, head[1]==20, retVal==10, *p==20
op: (*p)++.	 head[0]==11, head[1]==20, retVal==10, *p==11
```

Also, I am happy to find that the result from C and Cpp compiler are the same.
(Off course.)

## Reference 
[C Operator Precedence](https://en.cppreference.com/w/c/language/operator_precedence)  
[C++ Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)  
[Difference between ++\*p, \*p++ and \*++p](https://www.geeksforgeeks.org/difference-between-p-p-and-p/)  