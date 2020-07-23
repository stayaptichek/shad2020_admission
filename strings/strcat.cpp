#include <cstdio>
#include <cstring>
#include<cstdlib>

int main(){

	const char*s = "Hello,world! ";
	printf("%s\n", s);
	printf("strlen(s) = %d\n", (int)strlen(s));

	int times_to_concat;
	scanf("%d", &times_to_concat);
	size_t buffer_length  = strlen(s)*times_to_concat + 1;
	char* buffer = (char*)malloc(buffer_length*sizeof(char));


	for(int i=0; i<times_to_concat; i++){

		strcat(buffer, s);
		//программа с увеличением times_to_concat будет работать всё дольше, так как strcat 
		//каждый раз дожен добегать до конца buffer, чтобы добавить s

		//strcat - функция из C, плохо 
		//лучше писать на C++, чтобы знать гед заканчаивается строка и не бежать каждый раз до конца 

	}


	free(buffer);

	return 0;

}