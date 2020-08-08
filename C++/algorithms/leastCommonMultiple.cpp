#include <iostream>

int gcd(int a, int b)
{
	while(b != 0){
		int temp = b; 
		b = a % b; 
		a = temp; 
	}
	return a;
}

int lcm(int a, int b){
	return (a * b) / gcd(a, b);
}


int main()
{
	int num1 = 234;
	int num2 = 5205;
	int result = lcm(num1, num2); 
	std::cout << result << std::endl;
}
