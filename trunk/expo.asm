%include "asm_io.inc"
segment  .data
	exp dd 2
	A dd 0,0,1,1
	
segment .bss

segment .text

	global asm_main
	extern scanf, printf

asm_main:
	
	enter 0,0		;setup routine
	mov eax,A
	push dword [exp]
	push dword eax
	call cal_decimal
	add esp, 8
	mov eax,0		;return back to C
	leave
	ret

cal_decimal:
	push ebp
	mov ebp,esp
	;mov ecx, [ebp+12]	;exponente
	mov ebx, [ebp+8]	;direccion del primer elemento
	mov edx,0			;resultado final
	mov edi,3			;variable de control

while_loop:
	cmp edi,0			;condicion de salida
	jl end_loop
	mov ecx,0
	mov ecx,[ebp]
	cmp edx,0
	jz avanzar			
	mov esi,0			;valor!=0	esi=0	esi=posicion-1
	mov eax,1			;resultadopotencia = 1	neutro de la multiplicacion

while_potencia:
	cmp esi,edi				
	jz end_potencia
	imul eax,[ebp+12]
	inc esi
	jmp while_potencia

end_potencia:
	imul eax,ecx		;resultado = valor*resultado => resultado es el expoente elevado a la posicion-1
	add edx,eax			;resultado final = resultado final+resultado

avanzar:
	add ebp,8
	dec edi
	jmp while_loop

end_loop:
	mov eax,edx			;eax = resultado final
	push eax
	mov esp,ebp
	pop ebp
	ret