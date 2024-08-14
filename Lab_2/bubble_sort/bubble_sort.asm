ORG 0H
LJMP MAIN
ORG 100H
MAIN:
MOV 70H,60H
MOV 71H,61H
MOV 72H,62H
MOV 73H,63H
MOV 74H,64H
MOV 75H,65H
MOV 76H,66H
MOV 77H,67H
CALL SORT
HERE: SJMP HERE
ORG 130H
// *****************
//sort function
SORT:
	MOV R7, #7
	MOV R0, #70H
	MOV R1, #71H
	CLR P1.1
	loop:
		MOV A, @R0
		SUBB A, @R1
		CLR P1.2
		JNC SWP
		back:INC R0
		INC R1
		CALL swap_c
		DJNZ R7, loop
		JB P1.1,SORT
RET
//swap function
SWP:
	MOV 02H, @R1
	MOV 03H, @R0
	MOV @R1, 03H
	MOV @R0, 02H
	SETB P1.2
	lJMP back
//swap checker function
swap_c:
	MOV C, P1.2
	ORL C, P1.1
	MOV P1.1, C
	RET

END