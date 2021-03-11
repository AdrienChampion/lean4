/-
Copyright (c) 2020 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura, Sebastian Ullrich
-/
import Lean.Parser.Term

namespace Lean
namespace Parser
namespace Tactic

builtin_initialize
  registerParserAlias! "tacticSeq"    tacticSeq

@[builtinTacticParser] def «unknown»    := parser! withPosition (ident >> errorAtSavedPos "unknown tactic" true)
@[builtinTacticParser] def nestedTactic := tacticSeqBracketed

/- Auxiliary parser for expanding `match` tactic -/
@[builtinTacticParser] def eraseAuxDiscrs := parser!:maxPrec (symbol "eraseAuxDiscrs!" <|> "erase_aux_discrs")

def matchRhs  := Term.hole <|> Term.syntheticHole <|> tacticSeq
def matchAlts := Term.matchAlts (rhsParser := matchRhs)
@[builtinTacticParser] def «match» := parser!:leadPrec "match " >> sepBy1 Term.matchDiscr ", " >> Term.optType >> " with " >> matchAlts
@[builtinTacticParser] def introMatch := parser! nonReservedSymbol "intro " >> matchAlts

end Tactic
end Parser
end Lean
