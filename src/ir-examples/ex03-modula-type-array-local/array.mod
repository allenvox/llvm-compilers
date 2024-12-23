MODULE ExampleMod;

TYPE MyArray = ARRAY [10] OF INTEGER;

PROCEDURE Main;
VAR
  v: MyArray;
  x: INTEGER;
BEGIN
  v[0] := 3;
  x := v[1];
END Main;

END ExampleMod.
