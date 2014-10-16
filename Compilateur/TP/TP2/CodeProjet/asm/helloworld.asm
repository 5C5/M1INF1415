%include "asm/include/macros.mac"
%include "asm/include/write.mac"

global _main

; =====================================
section		.text
helloworld:
    subprogram.prologue
; writeln ('Hello world!');
	push 				dword __ch1
	subprogram.call		writeString
	subprogram.call		newLine
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size	equ	0
; variables locales et temporaires
.vars_size	equ 0
.temps_size	equ 0
; -------------------------------------
section		.data
; variables globales
; chaines de caracteres statiques
__ch1			db 12, "Hello world!"


; =====================================
section    .text
_main:
    program.prologue
	subprogram.call		helloworld
	program.epilogue
