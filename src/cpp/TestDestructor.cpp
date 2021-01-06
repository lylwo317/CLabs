#include <iostream>
#include <cstring>

namespace KX {
	class Person
	{
	public:
		int age;
		Person() {
			memset(this, 0, sizeof(Person));
			using namespace std;
			cout << "Person::Person()" << endl;
		}

		~Person() {
			using namespace std;
			cout << "Person::~Person()" << endl;
		}
	};
}

namespace KX {
	int g_age;
}

namespace LX {
	int g_age;
}


/*
*/
int main(int argc, char const *argv[])
{
	using namespace KX;
	using namespace LX;
	LX::g_age;

	KX::Person person;
	//Person *person1 = new Person();

	::std::cout << "0" << std::endl;

	using std::cout;
	cout << "0" << std::endl;

	using namespace std;
	cout << "2" << endl;

	return 0;
}
