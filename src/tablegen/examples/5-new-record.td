class Inst<string mnemonic, int opcode, bit commutable = 0> {
  string Mnemonic = mnemonic;
  int Opcode = opcode;
  bit Commutable = commutable;
}

multiclass InstWithImm<string mnemonic, int opcode> {
  def "": Inst<mnemonic, opcode>;
  def I: Inst<!strconcat(mnemonic,"i"), !add(opcode, 1)>;
  def "M": Inst<!strconcat(mnemonic,"m"), !add(opcode, 2)>;
}

defm ADD : InstWithImm<"add", 0xA0>;



