/*
Copyright (c) 2015 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#include "library/compiler/util.h"
#include "library/compiler/lcnf.h"
#include "library/compiler/elim_dead_let.h"
#include "library/compiler/cse.h"
#include "library/compiler/specialize.h"
#include "library/compiler/llnf.h"
#include "library/compiler/closed_term_cache.h"
#include "library/compiler/compiler.h"
#include "library/compiler/emit_cpp.h"
#include "library/compiler/builtin.h"
#include "library/compiler/extname.h"

namespace lean {
void initialize_compiler_module() {
    initialize_compiler_util();
    initialize_lcnf();
    initialize_elim_dead_let();
    initialize_cse();
    initialize_specialize();
    initialize_closed_term_cache();
    initialize_llnf();
    initialize_compiler();
    initialize_builtin();
    initialize_emit_cpp();
    initialize_extname();
}

void finalize_compiler_module() {
    finalize_extname();
    finalize_emit_cpp();
    finalize_builtin();
    finalize_compiler();
    finalize_llnf();
    finalize_closed_term_cache();
    finalize_specialize();
    finalize_cse();
    finalize_elim_dead_let();
    finalize_lcnf();
    finalize_compiler_util();
}
}
