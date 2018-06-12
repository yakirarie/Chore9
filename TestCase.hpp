
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class TestCase
{
private:
    string name;
    int failed;
    int passed;
    int counter;
    ostream *os;

public:
    TestCase(string name, ostream &stream);

    template <typename T>
    TestCase& check_equal(T a, T b)
    {
        counter++;
        if(a==b)
            passed++;
        else//Test MyStruct operators: Failure in test #1: MyStrct(5) should equal MyStrct(5)!
        {
            failed++;
            *os<<name<<": Failure in test #"<<counter<<": "<<a<<" should equal "<<b<<"!"<<endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_different(T a, T b)
    {
        counter++;
        if(a!=b)
            passed++;
        else
        {
            failed++;
            *os<<name<<": Failure in test #"<<counter<<": "<<a<<" should not equal "<<b<<"!"<<endl;
        }
        return *this;
    }

    template <typename T>
    TestCase& check_output(T a, string b)
    {
        counter++;
        ostringstream stream;
        stream<<a;
        string output = stream.str();
        if(output.compare(b)==0)
            passed++;
        else//Test MyStruct operators: Failure in test #3: string value should be MyStruct(5) but is MyStrct(5)
        {
            failed++;
            *os<<name<<": Failure in test #"<<counter<<": string value should be "<<b<<" but is "<<output<<endl;//check
        }
        return *this;
    }

    // template <typename T,typename S>
    // TestCase& check_function(T(*func)(S),S s,T t)
    // {
    //     counter++;
    //     T ret = func(s);
    //     if(ret==t)
    //         passed++;
    //     else//Test MyStruct operators: Failure in test #4: Function should return 5 but returned 6!
    //     {
    //         failed++;
    //         *os<<name<<": Failure in test #"<<counter<<": Function should return "<<t<<" but returned "<<ret<<endl;//check
    //     }  
    //     return *this;
    // }

    // template <typename T,typename S>
    // TestCase& check_function(T(*func)(const S&),S s,T t)
    // {
    //     counter++;
    //     T ret = func(s);
    //     if(ret==t)
    //         passed++;
    //     else//Test MyStruct operators: Failure in test #4: Function should return 5 but returned 6!
    //     {
    //         failed++;
    //         *os<<name<<": Failure in test #"<<counter<<": Function should return "<<t<<" but returned "<<ret<<endl;//check
    //     }  
    //     return *this;
    // }
//
    template <typename T,typename S,typename func>
    TestCase& check_function(func f,S s,T t)
    {
        counter++;
        T ret = f(s);
        if(ret==t)
            passed++;
        else//Test MyStruct operators: Failure in test #4: Function should return 5 but returned 6!
        {
            failed++;
            *os<<name<<": Failure in test #"<<counter<<": Function should return "<<t<<" but returned "<<ret<<"!"<<endl;//check
        }  
        return *this;
    }

    void print();
};
