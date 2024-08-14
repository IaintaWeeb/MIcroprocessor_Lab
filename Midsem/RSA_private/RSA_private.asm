ORG 0H
LJMP MAIN
ORG 70H
MAIN:
	MOV A, #19
	MOV B, #13
	MOV 71H, #173
	DEC A
	DEC B
	MUL AB
	MOV 70H, A
	CALL KEY_CALC
	CALL DISPLAY
	Here: SJMP Here
	
	KEY_CALC:
		MOV R2, #1
		Loop1:
			MOV A, 70H
			MOV B,R2
			MUL AB
			INC A
			CALL REM
			INC R2
			JNZ Loop1
			MOV 72H, R4
		RET
	
	REM:
		MOV R3, 71H
		MOV R4, #0
		Here2:
			CLR C
			PUSH ACC
			MOV A,B
			JZ  last
			POP ACC
			SUBB A , R3 
			INC R4
			JNC Here2
			JC dec_
			dec_:DEC B
			SJMP here2
			last:
				POP ACC
				last2:CLR C
				SUBB A , R3
				INC R4
				JNC last2
				ADD A,R3
				DEC R4
		RET	
	
	DISPLAY:
		loop2:
			MOV P1,#00H
			MOV A, 72H
			MOV C,ACC.4
			MOV P1.4,C
			MOV C,ACC.5
			MOV P1.5,C
			MOV C,ACC.6
			MOV P1.6,C
			MOV C,ACC.7
			MOV P1.7,C
			CALL Delay
			CALL Delay
			CALL Delay
			CALL Delay
			CALL Delay
			MOV P1,#0
			CALL DELAY
			MOV C,ACC.0
			MOV P1.4,C
			MOV C,ACC.1
			MOV P1.5,C
			MOV C,ACC.2
			MOV P1.6,C
			MOV C,ACC.3
			MOV P1.7,C
			CALL Delay
			CALL Delay
			CALL Delay
			CALL Delay
			CALL Delay
			LJMP loop2
		RET	
	
	Delay:
		MOV R2, #100
		MOV R5, #10
		PUSH 05H
		LOOP4:
			PUSH 02H 
			LOOP3:
				ACALL delay_1ms
				DJNZ R2 ,LOOP3
			POP 02H
			DJNZ R5,LOOP4
		POP 05H
		RET
	
	delay_1ms:
		push 00h
		mov r0, #4
		h2: acall delay_250us
		djnz r0, h2
		pop 00h
		ret
	delay_250us:
		push 00h
		mov r0, #244
		h1: djnz r0, h1
		pop 00h
		ret
	
END