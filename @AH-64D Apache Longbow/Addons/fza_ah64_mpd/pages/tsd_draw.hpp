#include "tsd\common.hpp"

class Root {
    condition = __EVAL(format [STRINGIFY(EQ(user%1, 0)), MFD_OFFSET + MFD_IND_TSD_SUBPAGE]);
    #include "tsd\root.hpp"
};

class Show {
    condition = __EVAL(format [STRINGIFY(EQ(user%1, 1)), MFD_OFFSET + MFD_IND_TSD_SUBPAGE]);
    #include "tsd\show.hpp"
};