ORG 0H
LJMP MAIN
ORG 100H
MAIN:
	MOV 90H, #0FH
	MOV P0, #00H
	MOV TMOD, #01H
	CLR TF0
	loop:
		CPL P0.7
		CALL DELAY
		CALL DELAY
		LJMP loop
		
	DELAY:
		JB P1.3, Ma
		JB P1.2, Ga
		JB P1.1, Re
		JB P1.0, Sa
		MOV TL0, #00H
		MOV TH0, #00H
		LJMP Here
		
		Sa:
			MOV TL0, #57H
			MOV TH0, #0F8H
			LJMP Here
			
		Re:
			MOV TL0, #44H
			MOV TH0, #0F9H
			LJMP Here
		Ga:
			MOV TL0, #0FEH
			MOV TH0, #0F9H
			LJMP Here
		
		Ma:
			MOV TL0, #57H
			MOV TH0, #0FAH
			LJMP Here
		
		Here:
			SETB TR0
			loop2: JNB TF0, loop2
			CLR TR0
			CLR TF0
			RET
	RET
END