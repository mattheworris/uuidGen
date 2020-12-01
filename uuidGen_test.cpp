// Include the header file with the definitions of the functions you create.
#include "uuidGen.h"

// Include the test framework.
#include "test/catch.hpp"

// Declares a single test.
TEST_CASE("test_uuid")
{
    // Check if your function returns "12345678-1234-1234-1234-012345678901".
    REQUIRE(uuid_gen::uuidGen("12345678", "1234", "123", "1234", "012345678901") 
            == "12345678-1234-4123-1234-012345678901");

    REQUIRE(uuid_gen::uuidGen("0", "0", "0", "0", "0") 
            == "00000000-0000-4000-0000-000000000000");

    REQUIRE(uuid_gen::uuidGen("1", "2", "3", "4", "5") 
            == "00000001-0002-4003-0004-000000000005");

    REQUIRE(uuid_gen::uuidGen("FFFFFFFF", "FFFF", "FFFF", "FFFF", "FFFFFFFFFFFF") 
            == "FFFFFFFF-FFFF-4FFF-FFFF-FFFFFFFFFFFF");
}
