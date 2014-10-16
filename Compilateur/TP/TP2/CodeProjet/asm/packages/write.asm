
%include "asm/include/macros.mac"

; =====================================
global writeString
global writeString.args_size

global writeInt
global writeInt.args_size

global writeFloat
global writeFloat.args_size

global writeChar
global writeChar.args_size

global writeBoolean
global writeBoolean.args_size

global newLine
global newLine.args_size
; =====================================

extern _printf
extern _putchar
extern _fflush

; =====================================
; function writeString
;		- args : ( string )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- string address in memory
section		.text
writeString:
    subprogram.prologue
		mov		esi, [ebp+.arg_string]		; adresse de la chaine pascal (lg, data)
		mov 	ecx, 0
		mov		cl, [esi]					; ecx <-- longueur de la chaine
		inc 	esi							; eax <-- adresse effective des donnees
		mov 	edi, .buffer
		rep		movsb
		mov 	byte [edi], 0
		clib_prolog 16
		mov 	dword [esp+4], .buffer
		mov 	dword [esp+0], .format
		call _printf
		mov 	dword [esp+0], 0
		call _fflush
		clib_epilog 16
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size	equ	4
.arg_string	equ 8 + 0
; variables locales et temporaires
.vars_size	equ 0
.temps_size	equ 0
section		.data
.buffer		times 257 db 0
.format			db "%s", 0
; =====================================

; =====================================
; function writeInt
;		- args : ( int )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- int value
section		.text
writeInt:
    subprogram.prologue
		mov		edx, ebp
; convert int to string
		clib_prolog 16
		mov 	ebx, 0
		mov 	bx, [edx+.arg_int]
		mov 	word [esp + 4], bx
		mov 	dword [esp + 0], .format
		call 	_printf
		mov 	dword [esp+0], 0
		call _fflush
		clib_epilog 16
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ	2
.arg_int		equ 8 + 0
; variables locales et temporaires
.vars_size		equ 0
.temps_size		equ 0
section		.data
.format			db "%hd", 0
; =====================================

; =====================================
; function writeLong
;		- args : ( long )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- long value
section		.text
writeLong:
    subprogram.prologue
		mov		edx, ebp
; convert int to string
		clib_prolog 16
		mov 	ebx, [edx+.arg_int]
		mov 	dword [esp + 4], ebx
		mov 	dword [esp + 0], .format
		call 	_printf
		mov 	dword [esp+0], 0
		call _fflush
		clib_epilog 16
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ	4
.arg_int		equ 8 + 0
; variables locales et temporaires
.vars_size		equ 0
.temps_size		equ 0
section		.data
.format			db "%d", 0
; =====================================

; =====================================
; function writeFloat
;		- args : ( float )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- float value
section		.text
writeFloat:
    subprogram.prologue 1
		mov		edx, ebp
; convert int to string
		clib_prolog 16
		fld 	dword [edx+.arg_flt]
		fstp	qword [.buffer]
		mov 	ebx, .buffer
		mov 	ecx, [ebx+4]
		mov 	dword [esp + 8], ecx
		mov 	ecx, [ebx+0]
		mov 	dword [esp + 4], ecx
		mov 	dword [esp + 0], .format
		call 	_printf
		mov 	dword [esp+0], 0
		call _fflush
		clib_epilog 16
	subprogram.epilogue 1
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ	4
.arg_flt		equ 8 + 0
; variables locales et temporaires
.vars_size		equ 0
.temps_size		equ 0
section		.data
.format			db "%f", 0
.buffer			dq 0.0
.fpu.state 		times 108 db 0
; =====================================

; =====================================
; function writeChar
;		- args : ( 8bits value )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- char value
section		.text
writeChar:
    subprogram.prologue
		mov		edx, ebp
; convert int to string
		clib_prolog 16
		mov 	ebx, 0
		mov 	bl, [edx+.arg_char]
		mov 	dword [esp + 0], ebx
		call 	_putchar
		mov 	dword [esp+0], 0
		call _fflush
		clib_epilog 16
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ	1
.arg_char		equ 8 + 0
; variables locales et temporaires
.vars_size		equ 0
.temps_size		equ 0
; =====================================

; =====================================
; function writeHex32
;		- args : ( 32bits value )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- 32bits value
section		.text
writeHex32:
    subprogram.prologue
		mov		edx, ebp
		clib_prolog 16
		mov 	ebx, [edx+.arg_hex]
		mov 	dword [esp + 4], ebx
		mov 	dword [esp + 0], .format
		call 	_printf
		mov 	dword [esp+0], 0
		call _fflush
		clib_epilog 16
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ	4
.arg_hex		equ 8 + 0
; variables locales et temporaires
.vars_size		equ 0
.temps_size		equ 0
section		.data
.format			db "0x%08x", 0
; =====================================

; =====================================
; function writeBoolean
;		- args : ( 8bits value )
;		- return : void
;	at beginning, stack contains :
;		- old value of EBP
;		- return address
;		- boolean value
section		.text
writeBoolean:
    subprogram.prologue
		mov		edx, ebp
		clib_prolog 16
		mov 	ebx, 0
		mov 	bl, [edx+.arg_bool]
		cmp 	ebx, 0
		je 		.fdisp
		mov 	dword [esp + 0], .true
		jmp		.display
.fdisp:
		mov 	dword [esp + 0], .false
.display:
		call 	_printf
		mov 	dword [esp+0], 0
		call _fflush
		clib_epilog 16
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ	1
.arg_bool		equ 8 + 0
; variables locales et temporaires
.vars_size		equ 0
.temps_size		equ 0
section		.data
.true			db "true", 0
.false			db "false", 0
; =====================================


section		.text
newLine:
    subprogram.prologue
		mov		edx, ebp
		clib_prolog 16
		mov 	dword [esp + 0], .format
		call 	_printf
		mov 	dword [esp+0], 0
		call _fflush
		clib_epilog 16
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ		0
.result_size	equ 0
; variables locales et temporaires
.vars_size		equ 	0
.temps_size		equ 0
section		.data
.format 		db 0xa, 0
