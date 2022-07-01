;-------------------------------
;  Arquitectura de computadors 
;  PRA2 processament segmentat
;-------------------------------
;       Elena Barrachina
;          Laura Haro
;-------------------------------

		.data
n:		.word 1
iter:	.word 6

num:	.double 2
den:	.double 3
Res:	.double 0.0
Div: 	.double 1.0


		.text
		l.d F0, Res(R0)		;F0 = 0.0
		lw R1, n(R0)		;R1 = 1
		lw R3, iter(R0)		;R3 = 6
		l.d F2, num(R0)		;F2 = 2
		l.d F3, den(R0)		;F3 = 3
		l.d F4, den(R0)		;F4 = 3
		l.d F5, Div(R0)		;F5 = 1
		
		Sumatori:
				mul.d F5, F5, F2	
				mul.d F4, F4, F3
				
				div.d F1, F5, F4		;div = num/den
				daddi R1, R1, 1			;n = n + 1
				bne R1, R3, Sumatori	
				add.d F0, F0, F1		;Res = res + div
		s.d F0, Res(R0)
		halt