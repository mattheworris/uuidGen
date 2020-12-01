#include "uuidGen.h"

using namespace std;

namespace uuid_gen {

// uuidGen(): takes 5 arguments for each of the 5 octet groups in the UUID.
// Input is assumed to be valid Hexidecimal in the range 0 < input <= 0xFFFF, 
// 0 < input <= 0xFFFFFFFF, or 0 < input <= 0xFFFFFFFFFFFF, depending if the
// octet group contains 4, 8, or 12 characters.
// return: string with hexidecimal UUID

// Let's assume a version 4, variant 1 UUID and users supplies the octet groups.
// 128 bit Format uuid as Hexadecimal:
// xxxxxxxx-xxxx-4xxx-xxxx-xxxxxxxxxxxx

string uuidGen(string firstGroup,
               string secondGroup,
               string thirdGroup,
               string fourthGroup,
               string fifthGroup) 
{
    // Return the UUID.
    // Long Inputs will be truncated to correct length
    stringstream uuid;
    uuid << hex;
    // Set the fill character for short inputs
    uuid.fill('0');
    //First Group: 8 Hex digits
    uuid.width(8);
    uuid << firstGroup.substr(0,8);
    uuid << "-";
    // Second Group: 4 Hex digits
    uuid.width(4);
    uuid <<  secondGroup.substr(0,4);
    uuid << "-4";
    // Third Group: Version 4 bits set and remaining Hex digits
    uuid.width(3);
    uuid <<  thirdGroup.substr(0,3);
    uuid << "-";
    // Fourth Group: 4 Hex digits
    uuid.width(4);
    uuid <<  fourthGroup.substr(0,4);
    uuid << "-";
    // Fifth Group: 12 Hex digits
    uuid.width(12);
    uuid <<  fifthGroup.substr(0,12);

    return uuid.str();
}

}  // namespace uuid_gen