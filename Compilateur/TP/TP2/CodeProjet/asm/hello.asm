%include "asm/include/macros.mac"
%include "asm/include/write.mac"
%include "asm/include/read.mac"

global _main

; =====================================
section		.text
hello:
    subprogram.prologue
; write ('Please tell me your name: ');
	push 				dword __ch1
	subprogram.call		writeString
; readln (name);
	push 				dword name
	subprogram.call		readString
; writeln ('Hello, ',name,'!');
	push 				dword __ch2
	subprogram.call		writeString
	push 				dword name
	subprogram.call		writeString
	byte.push 			'!'
	subprogram.call		writeChar
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
name			db 0
				times 255 db 0
; chaines de caracteres statiques
__ch1			db 26, "Please tell me your name: "
__ch2			db 7, "Hello, "

; =====================================
section    .text
_main:
    program.prologue
	subprogram.call		hello
	program.epilogue
