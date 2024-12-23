class Inst<string mnemonic, int opcode, bit commutable = 0> {
  string Mnemonic = mnemonic;
  int Opcode = opcode;
  bit Commutable = commutable;
}

class InstDesc<string name, string suffix, int delta> {
    string Name = name;
    string Suffix = suffix;
    int Delta = delta;
}

def RegOp : InstDesc<"", "", 0>;
def ImmOp : InstDesc<"I", "i", 1>;
def MemOp : InstDesc<"M", "m", 2>;

class getDesc<int n> {
    InstDesc ret = !cond(!eq(n, 0) : RegOp,
                         !eq(n, 1) : ImmOp,
                         !eq(n, 2) : MemOp);
}

multiclass InstWithOps<string mnemonic, int opcode> {
    foreach I = 0-2 in {
        defvar Name = getDesc<I>.ret.Name;
        defvar Suffix = getDesc<I>.ret.Suffix;
        defvar Delta = getDesc<I>.ret.Delta;
        def Name: Inst<mnemonic # Suffix, !add(opcode, Delta)>;
    }
}

defm ADD : InstWithOps<"add", 0xA0>;

