MODULE ScopeTest;

VAR x: INTEGER;

PROCEDURE TestScope;
VAR x: INTEGER;
BEGIN
    x := 20;
END TestScope;

BEGIN
    x := 10;
    TestScope;
END ScopeTest.
