ORG 0H
LJMP MAIN
ORG 100H
MAIN:
	CALL QUANT
	HERE: SJMP HERE
	ORG 130H
// *****************
	QUANT:
		MOV R0, #60H
		MOV R1, #70H
		MOV R2, #10
		MOV R3, #20
		MOV R4, #30
		MOV R7, #8
		loop:
		MOV A,@R0
		CLR C
		SUBB A,R2
		JZ eq10
		JNC check20
		MOV @R1,#5
		LJMP return
		check20:
			MOV A,@R0
			CLR C
			SUBB A,R3
			JZ eq20
			JNC check30
			MOV @R1,#15
			LJMP return
			check30:
				MOV A,@R0
				CLR C
				SUBB A,R4
				JNC else_
				MOV @R1,#25
				LJMP return
				else_:
					MOV @R1,#35
					LJMP return
				eq10:
					MOV @R1,#15
					LJMP return
				eq20:
					MOV @R1,#25
					LJMP return
		return:INC R0
		INC R1
		DJNZ R7,loop
// 
	RET
END