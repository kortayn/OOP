#define CATCH_CONFIG_MAIN
#include "./catch/catch_amalgamated.hpp"
#include "factorial.h"
#include <vector>

/*
Туториал: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md

Основные макросы:
REQUIRE( expression ) - завершает текущий тест, если выражение ложно
CHECK( expression ) - генерирует предупреждение, если выражение ложно,
                    но тест продолжает работу
REQUIRE_FALSE( expression ) - завершает текущий тест, если выражение истинно
CHECK_FALSE( expression ) - генерирует предупреждение, если выражение истинно,
                    но тест продолжает работу

REQUIRE_NOTHROW( expression ) - завершает текущий тест, если выражение не бросает исключение и выражение истинно
CHECK_NOTHROW( expression ) - генерирует предупреждение, если выражение не бросает исключение и выражение истинно

REQUIRE_THROWS( expression ) - завершает текущий тест, если выражение бросает исключение и выражение истинно
CHECK_THROWS( expression ) - генерирует предупреждение, если выражение бросает исключение и выражение истинно

REQUIRE_THROWS_AS( expression, exception type ) - завершает текущий тест, если выражение бросает исключение типа type и выражение истинно
CHECK_THROWS_AS( expression, exception type ) - генерирует предупреждение, если выражение бросает исключение типа type и выражение истинно

REQUIRE_THROWS_WITH( expression, string or string matcher ) - завершает текущий тест, если выражение бросает исключение-строку или string matcher
CHECK_THROWS_WITH( expression, string or string matcher ) - генерирует предупреждение, если выражение бросает исключение-строку или string matcher

Сравнение значений с плавающей точкой:
Approx target = Approx(100).epsilon(0.01);
100.0 == target; // Истина
200.0 == target; // Ложь
100.5 == target; // Истина, потому что 0.5 - допустимая погрешность

margin - погрешность в процентах
Approx target = Approx(100).margin(5);
100.0 == target; // истина
200.0 == target; // ложь
104.0 == target; // истина

Погрешность равна (Approx::scale + Approx::value) * epsilon
Approx target = Approx(100).scale(100).epsilon(0.01);
100.0 == target; //  истина
101.5 == target; //  истина
200.0 == target; // ложь
100.5 == target; // истина

Approx target1 = Approx(100).scale(100).margin(5);
100.0 == target1; // истина
200.0 == target1; // ложь
104.0 == target1; // истина
*/

/*TEST_CASE()
{
    REQUIRE(factorial(2) == 2);
}

//По имени и тегу можно обратиться к конкретному тесту и выполнить его
TEST_CASE("Test with n less or equal than 1", "[tag1]")
{
    REQUIRE(factorial(1) == 1);
}

TEST_CASE( "vectors can be sized and resized", "[vector]" ) 
{
	// share some code
    std::vector<int> v( 5 );

    REQUIRE( v.size() == 5 );
    REQUIRE( v.capacity() >= 5 );

         // Execute these sections
    SECTION( "resizing bigger changes size and capacity" ) 
    {
        v.resize( 10 );

        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "resizing smaller changes size but not capacity" ) 
    {
        v.resize( 0 );

        REQUIRE( v.size() == 0 );
        REQUIRE( v.capacity() >= 5 );
    }
    SECTION( "reserving bigger changes capacity but not size" ) 
    {
        v.reserve( 10 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "reserving smaller does not change size or capacity" ) 
    {
        v.reserve( 0 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );
    }
}*/

//BDD style
SCENARIO( "vectors can be sized and resized", "[vector]" ) 
{
         // given conditions
    GIVEN( "A vector with some items" ) 
    {
        std::vector<int> v( 5 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );

                 // When meeting the situation
        WHEN( "the size is increased" ) 
        {
            v.resize( 10 );

                         // get the result
            THEN( "the size and capacity change" ) 
            {
                REQUIRE( v.size() == 10 );
                REQUIRE( v.capacity() >= 10 );
            }
        }
        WHEN( "the size is reduced" ) 
        {
            v.resize( 0 );

            THEN( "the size changes but not capacity" ) 
            {
                REQUIRE( v.size() == 0 );
                REQUIRE( v.capacity() >= 5 );
            }
        }
        WHEN( "more capacity is reserved" ) 
        {
            v.reserve( 10 );

            THEN( "the capacity changes but not the size" ) 
            {
                REQUIRE( v.size() == 5 );
                REQUIRE( v.capacity() >= 10 );
            }
        }
        WHEN( "less capacity is reserved" ) 
        {
            v.reserve( 0 );

            THEN( "neither size nor capacity are changed" ) 
            {
                REQUIRE( v.size() == 5 );
                REQUIRE( v.capacity() >= 5 );
            }
        }
    }
}