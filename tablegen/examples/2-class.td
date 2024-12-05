class Inst<string mnemonic, int opcode> {
  string Mnemonic = mnemonic;
  int Opcode = opcode;
}

def ADD : Inst<"add", 0xA0>;
def SUB : Inst<"sub", 0xB0>;
