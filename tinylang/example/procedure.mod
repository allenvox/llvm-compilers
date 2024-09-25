MODULE ProcedureWithReturnError;

PROCEDURE MyProcedure;
BEGIN
    RETURN 10;
END MyProcedure;

BEGIN
    MyProcedure;
END ProcedureWithReturnError.
