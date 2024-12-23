MODULE FunctionWithDuplicateParams;

PROCEDURE Add(x: INTEGER; x: INTEGER): INTEGER;
BEGIN
    RETURN x + x;
END Add;

VAR result: INTEGER;

BEGIN
    result := Add(5, 10);
END FunctionWithDuplicateParams.
