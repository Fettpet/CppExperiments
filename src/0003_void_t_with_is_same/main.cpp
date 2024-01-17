/**
This is a simple void_t test. void_t is a easy way to provide SFIANE failures.
This test checks whether it is possible to use void_t with traits. The trait reduce to FalseType. Is
it enough to for void_t?
*/

#include <tuple>
#include <type_traits>

/*
This is the SFIANE test object. It has a value == 0
*/
template <typename T, typename SFIANE = void>
struct Test
{
   constexpr static int value = 0;
};

/*
This is the specialication. The valud of Test<int>::value shall be 1
*/
template <typename T>
struct Test<T, std::void_t<std::is_same<int, T>>>
{
   constexpr static int value = 1;
};

int main()
{
   // work as expected
   static_assert(Test<int>::value == 1, "Test<int> shall be 1, since it is the specialication");

   // fails, since there is no substitution error
   static_assert(Test<float>::value == 0, "Test<float> shall be 0, since it is the default");
   return 0;
}