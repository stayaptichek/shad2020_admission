#include <iostream>
#include <string>


int main()
{
	std::string hello = "Hello, world! ";
	std::string result;

	std::cout<<hello<<'\n';

	int times_to_concat;
	std::cin>>times_to_concat;

	for(int i=0; i<times_to_concat; i++){
		result += hello;
		//тут уже все работает очень быстро, потому что string помнит длину строки 
	}
	//std::cout<<result<<std::endl;
	return 0;
}