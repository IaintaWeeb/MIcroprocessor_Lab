ORG 0H
LJMP MAIN
ORG 100H
MAIN:
	CALL FILT
	HERE: SJMP HERE
	ORG 130H
	// *****************
	FILT:
	// ADD YOUR CODE HERE
		PUSH 57H
		PUSH 58H
		PUSH 59H
		MOV 57H,#0
		MOV 58H,#0
		MOV 59H,#0
		MOV R0,#60H
		MOV R1,#70H
		MOV R6,#8
		loopo:
			MOV R7,#4
			MOV A,#0
				loopi:
					MOV 02H,@R0
					ADD A, R2
					DEC R0
					DJNZ R7,loopi
			MOV B,#4
			DIV AB
			MOV @R1,A
			INC R0
			INC R0
			INC R0
			INC R0
			INC R0
			INC R1
			DJNZ R6,loopo
		POP 59H
		POP 58H
		POP 57H
	RET
END
