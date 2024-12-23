MODULE ExampleMod;

TYPE MyArray = ARRAY [10] OF INTEGER;

VAR v: MyArray;

PROCEDURE Main;
BEGIN
  v[2] := 100;
END Main;

END ExampleMod.
