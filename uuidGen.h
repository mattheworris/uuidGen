#if !defined(UUID_GEN_H)
#define UUID_GEN_H

#include <iostream>
#include <sstream>
#include <string>

namespace uuid_gen {

// uuidGen(): takes 5 arguments for each of the 5 octet groups in the UUID.
// Input is assumed to be valid Hexidecimal in the range 0 < input <= 0xFFFF, 
// 0 < input <= 0xFFFFFFFF, or 0 < input <= 0xFFFFFFFFFFFF, depending if the
// octet group contains 4, 8, or 12 characters.
// return: string with hexidecimal UUID
std::string uuidGen(std::string firstGroup,
                    std::string secondGroup,
                    std::string thirdGroup,
                    std::string fourthGroup,
                    std::string fifthGroup);

}  // namespace uuid_gen

#endif
