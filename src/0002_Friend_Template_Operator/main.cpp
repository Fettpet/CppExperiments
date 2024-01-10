/**
Experiment Idea: I want to have an operator* as a customization point. It should have access to the
private variables of a class.

Implementation: The operator* is defined as a friend. It is tested whether decltype(auto) works as
a result type and whether templates can be used. Additionally, a template specialization is tested.
 *
 * */
#include <iostream>

struct MyClass {

    MyClass(int value): value{value} {}

    /** 1. experiment
     *  Test that decltype(auto) can be used as friend of the operator*
     *  */
    friend decltype(auto) operator*(MyClass, int);

    /** 2. experiment
     *  Test that template can be a friend
     *  */
    template<typename T>
    friend decltype(auto) operator*(MyClass, T);

private:
    int value;
};
/**************************************************************************************************
/**
 *  this works as expected
 *  */
decltype(auto) operator*(MyClass m, int v){
   return "Multiple with decltype(auto)";
}

/**
 *  this Doesnt compile
 *
void operator*(MyClass m, int v){
   return m.value * v;
}
*/

/**************************************************************************************************/
template<typename T>
decltype(auto) operator*(MyClass myClass, T t){
   return "Multiple with template";
}

template<>
decltype(auto) operator*<char>(MyClass myClass, char t){
   return "Multiple with template specialization";
}

int main()
{

    std::cout << "Result of experiment 1: " << MyClass {7} * 7 << std::endl;
    std::cout << "Result of experiment 2: " << MyClass {7} * 5. << std::endl;
    std::cout << "Result of experiment 3: " << MyClass {7} * char{2} << std::endl;
    return 0;
}
