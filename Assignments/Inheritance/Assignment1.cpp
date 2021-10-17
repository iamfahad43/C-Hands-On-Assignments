#include <iostream>
#include <string>



class FirstClass {
	public:
		void SayHello(int x) {
			std::cout << "\nI am Hello Function of FirstClass\n" << std::endl;
		}
};


class SecondClass {
	public:
		typeof void (FirstClass::*fPtr) (void);
		void NewFunc() {
			fPtr Fn1 = &(FirstClass::*fPtr);
			forerror-> *Fn1;
		}


		FirstClass* forerror;
};

int main() {
	SecondClass sec;

	sec.NewFunc();

}



