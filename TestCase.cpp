#include "TestCase.hpp"

    // template <typename T>
    // TestCase :: check_equal(T &a, T &b)
    // {

    // }

    // template <typename T>
    // TestCase :: check_different(T &a, T &b)
    // {

    // }

    // template <typename T>
    // TestCase :: check_output(T &a, string b)
    // {

    // }

    // template <typename T,typename S>
    // TestCase :: check_function(T &(*func)(S &),S &,T &b)
    // {

    // }
    TestCase :: TestCase(string name, ostream &stream)
    {
        failed = 0;
        passed = 0;
        counter = 0;
        this->name = name;
        os = &stream;
    }

    void TestCase :: print()
    {
        *os<<name<<": "<<failed<<" failed, "<<passed<<" passed, "<<failed+passed<<" total."<<endl;
        *os<<"---"<<endl;
    }

    /**
 * A main program for testing the "TestCase" tester.
 */

/**
 * Below we define some functions with deliberate bugs, 
 * to demonstrate that our tester can find them.
 */

// int sqr(int x) { 
// 	return x*x*x;   // a deliberate bug (it should be: x*x)
// }

// int roundd(double x) { 
// 	return int(x);  // a deliberate bug (it should be: int(x+0.5)).
// }



// /**
//  * Below we define a whole new struct with deliberate bugs, 
//  * to demonstrate that our tester can find bugs even in new classes.
//  */

// struct MyStruct {
// 	int num;
// 	MyStruct(int num): num(num) {}
// 	bool operator==(const MyStruct& other) {
// 		return false; // a deliberate bug
// 	}
// 	bool operator!=(const MyStruct& other) {
// 		return num!=other.num; // no bug 
// 	}
// 	int myNum() const { 
// 		return num+2;   // a deliberate bug
// 	}
// };

// int getNum(const MyStruct& s) {
// 	return s.num+1; // a deliberate bug
// }

// ostream& operator<< (ostream& out, const MyStruct& tc) {
// 	return (out << "MyStrct"<<"("<<tc.num<<")"); // a deliberate typo (forgot "u").
// }

// int main() {
// 	TestCase("Test int operators", cerr)
// 		.check_equal(5,5)                  // check operator ==. Here there is no bug.
// 		.check_different(5,6)              // check operator !=. Here there is no bug.
// 		.check_function(sqr, 1, 1)         // check a function int->int.     Here there is no bug.
// 		.check_function(sqr, 5, 25)        // check a function int->int.    Here there is a bug.
// 		.check_function(roundd, 5.3, 5)     // check a function double->int. Here there is no bug.
// 		.check_function(roundd, 5.8, 6)     // check a function double->int. Here there is a bug.
// 		.check_output(5, "5")     // check output operator <<
// 		.print();

// 	TestCase("Test MyStruct operators", cerr)
// 		.check_equal(MyStruct(5), MyStruct(5))      // Here there is a bug.
// 		.check_different(MyStruct(5), MyStruct(6))  // Here there is no bug.
// 		.check_output(MyStruct(5), "MyStruct(5)")   // Here there is a bug. 
// 		.check_function(getNum, MyStruct(5), 5)     // Here there is a bug.
// 		.check_function([](const MyStruct& s){return s.myNum();}, MyStruct(5), 5) // Here there is a bug.
// 		.print();
// }

/* Expected output:
	Test int operators: Failure in test #4: Function should return 25 but returned 125!
	Test int operators: Failure in test #6: Function should return 6 but returned 5!
	Test int operators: 2 failed, 5 passed, 7 total.
	---
	Test MyStruct operators: Failure in test #1: MyStrct(5) should equal MyStrct(5)!
	Test MyStruct operators: Failure in test #3: string value should be MyStruct(5) but is MyStrct(5)
	Test MyStruct operators: Failure in test #4: Function should return 5 but returned 6!
	Test MyStruct operators: Failure in test #5: Function should return 5 but returned 7!
	Test MyStruct operators: 4 failed, 1 passed, 5 total.
	---
*/
