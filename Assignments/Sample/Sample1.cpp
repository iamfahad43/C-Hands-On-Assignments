#include <iostream>
#include <string>
#include <functional>


class MyClass {
	public:
	      int SayHello() {
		      std::cout <<  "\n Hello from function of class \n " << std::endl;
		      return 0;
	      }
};

int main() {
	std::function<int(MyClass&)> myclsde = &MyClass::SayHello;
	MyClass mycls;

	std::cout << myclsde(mycls) << std::endl;
}
