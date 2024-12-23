MODULE Point;

TYPE Point = RECORD
  x, y: INTEGER
END;

VAR p: Point;

PROCEDURE Assign(x: INTEGER);
BEGIN
  p.x := x;
  p.y := 100;
END Assign;

END Point.
