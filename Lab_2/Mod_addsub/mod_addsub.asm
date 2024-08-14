ORG 0H
LJMP MAIN
ORG 100H
MAIN:
	MOV R1, #61H
	CALL MODADD
	CALL MODSUB
	HERE: SJMP HERE
		ORG 130H
		// *****************
		MODADD:
			MOV A, 70H
			MOV B, R1
			DIV AB
			MOV R3, B
			MOV A, 71H
			MOV B, R1
			DIV AB
			MOV A, B
			ADD A, R3
			MOV B, R1
			DIV AB
			MOV 72H, B
			RET
		MODSUB:
			MOV A, 70H
			MOV R2, 71H
			MOV B, R1
			CLR C
			SUBB A, R2
			jc  ifcarry
			jnc ifncarry
			ifcarry:
				CPL A
				INC A
				DIV AB
				MOV R3, B  
				MOV A, R1
				CLR C
				SUBB A, R3
				MOV 73H, A
				ljmp return
			ifncarry:
				DIV AB
				MOV 73H, B
				ljmp return
			return: RET
	RET
END