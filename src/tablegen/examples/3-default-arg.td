class Inst<string mnemonic, int opcode, bit commutable = 0> {
 string Mnemonic = mnemonic;
 int Opcode = opcode;
 bit Commutable = commutable;
}

def ADD : Inst<"add", 0xA0, 1>;
def SUB : Inst<"sub", 0xB0>;


