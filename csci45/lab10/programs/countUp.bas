10 LET X = 1
20 REM Stop printing if X >= 100
30 LET Y = 100
40 IF X > Y THEN GOTO 100
50 REM Otherwise, print X and add 1 to it
60 PRINT X
70 LET Z = 1
80 LET X = X + Z
90 GOTO 40
100 END
