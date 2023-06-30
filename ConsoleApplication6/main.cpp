#include "pch.h"

import m;

int main() {
    S s;
    s.do_stuff();         // OK.
    s.get();              // OK: pointer to incomplete type.
    //auto impl = *s.get(); // ill-formed: use of undefined type 'Impl'.
}