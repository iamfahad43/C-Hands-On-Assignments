#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	vector <int> myvec;
	// insertion
	myvec.insert(myvec.begin(), 10);
	myvec.push_back( 20 );
	myvec.push_back( 30 );
	myvec.push_back( 40 );

	for (auto i=myvec.begin(); i!=myvec.end(); ++i)
		cout <<* i << endl;
}
