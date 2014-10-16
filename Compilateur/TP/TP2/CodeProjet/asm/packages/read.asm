
%include "asm/include/macros.mac"
%include "asm/include/debugger.mac"

; =====================================
global readString
global readString.args_size

global readInt
global readInt.args_size

global readFloat
global readFloat.args_size

global readChar
global readChar.args_size

global readBoolean
global readBoolean.args_size

global readLn
global readLn.args_size
; =====================================

extern _getchar
extern _scanf

;	@ char buffer
;	max size
;
;	ecx <- @ of string buffer
;	esi <- string length
%macro readtileol 2
		mov			esi, 0
.do:
		cmp 		esi, %2
		jz 			.donenonl
	    push    	dword 1
	    push    	dword %1
	    push    	dword 0
	    mov     	eax, 3
	    sub     	esp, 4
	    int     	0x80
	    add     	esp, 16
	    mov 		al, byte [%1]
		cmp			al, 0xa
		jz			.done
		mov			byte [ecx+esi], al
		inc 		esi
		jmp			.do
.donenonl:
	    push    	dword 1
	    push    	dword %1
	    push    	dword 0
	    mov     	eax, 3
	    sub     	esp, 4
	    int     	0x80
	    add     	esp, 16
	    mov 		al, byte [%1]
		cmp			al, 0xa
		jz			.done
		jmp 		.donenonl
.done:
%endmacro

; =====================================
; function readString
;		- args : ( string )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- string address in memory
section		.text
readString:
    subprogram.prologue
		mov			ecx, [ebp+.arg_string]		; adresse de la chaine pascal (lg, data)
		inc 		ecx
		readtileol	.buffer, 255
		mov			ecx, [ebp+.arg_string]		; adresse de la chaine pascal (lg, data)
		mov 		edx, esi
		mov 		byte [ecx], dl
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size	equ	4
.arg_string	equ 8 + 0
; variables locales et temporaires
.vars_size	equ 0
.temps_size	equ 0
section 	.data
.buffer 	db 0
; =====================================

; =====================================
; function readChar
;		- args : ( char )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- char address in memory
section		.text
readChar:
    subprogram.prologue
		mov			esi, [ebp+.arg_char]
		clib_prolog 16
		call		_getchar
		clib_epilog 16
		mov 		byte [esi], al
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size	equ	4
.arg_char	equ 8 + 0
; variables locales et temporaires
.vars_size	equ 0
.temps_size	equ 0
; =====================================

; =====================================
; function readInt
;		- args : ( int )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- int address in memory
section		.text
readInt:
    subprogram.prologue
		mov			esi, [ebp+.arg_int]
		clib_prolog 16
		mov 		dword [esp + 4], .buffer
		mov 		dword [esp + 0], .format
		call		_scanf
		clib_epilog 16
		mov 		eax, dword [.buffer]
		mov 		word [esi], ax
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size	equ	4
.arg_int	equ 8 + 0
; variables locales et temporaires
.vars_size	equ 0
.temps_size	equ 0
section		.data
.format			db "%d", 0
.buffer			dd 0
; =====================================
