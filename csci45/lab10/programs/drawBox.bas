1 LET X = 10
2 LET Y = 5
3 LET Z = 1
4 REM I keeps track of the line we're on
5 LET I = 1
6 IF I > Y THEN GOTO 16
7 REM J keeps track of where we are on the line
8 LET J = 1
9 IF J > X THEN GOTO 13
10 PRINT "*"
11 LET J = J + Z
12 GOTO 9
13 PRINT "\012"
14 LET I = I + Z
15 GOTO 6
16 END
