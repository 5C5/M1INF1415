%include "asm/include/macros.mac"
%include "asm/include/write.mac"
%include "asm/include/read.mac"

%include "asm/include/debugger.mac"

global _main

section		.text
pgcd:
				subprogram.prologue
		;	__temp000 = a = b
				mov					byte [ebp - 1 - .__temp000], 0
				mov					ax, [ebp+8+.a]
				mov					bx, [ebp+8+.b]
				cmp					ax, bx
				jnz					.not001
				mov					byte [ebp - 1 - .__temp000], 1
.not001:
		;	si __temp000 aller a alors002
				cmp					byte [ebp - 1 - .__temp000], 1
				jz 					.alors002
		;	aller a sinon002
				jmp					.sinon002
.alors002:
		;	renvoyer a
				mov					ebx, dword [ ebp + 8 + .result ]
				mov					ax, word [ ebp + 8 + .a ]
				mov					word [ebx], ax
		;	aller a finsi002
				jmp					.finsi002
.sinon002:
		;	__temp001 = a > b
				mov					byte [ebp - 1 - .__temp001], 0
				mov					ax, [ebp+8+.a]
				mov					bx, [ebp+8+.b]
				cmp					ax, bx
				jle					.not002
				mov					byte [ebp - 1 - .__temp001], 1
.not002:
		;	si __temp001 aller a alors001
				cmp					byte [ebp - 1 - .__temp001], 1
				jz 					.alors001
		;	aller a sinon001
				jmp					.sinon001
.alors001:
		;	empiler			& __temp3
				mov					eax, ebp
				add					eax, - 1 - .__temp003
				push				eax
		;	empiler			b
				word.push			[ ebp + 8 + .b ]
		;	__temp2 = a - b
				mov					ax, word [ ebp + 8 + .a ]
				sub 				ax, word [ ebp + 8 + .b ]
				mov					word [ ebp - 1 - .__temp002 ], ax
		;	empiler			__temp2
				word.push			[ ebp - 1 - .__temp002 ]
		;	appeler			pgcd
				subprogram.call 	pgcd
		;	renvoyer		__temp3
				mov					ebx, dword [ ebp + 8 + .result ]
				mov					ax, word [ ebp - 1 - .__temp003 ]
				mov					word [ebx], ax
		;	aller a finsin001
				jmp					.finsi001
.sinon001:
		;	empiler			& __temp5
				mov					eax, ebp
				add					eax, - 1 - .__temp005
				push				eax
		;	__temp4 = b - a
				mov					ax, word [ ebp + 8 + .b ]
				sub 				ax, word [ ebp + 8 + .a ]
				mov					word [ ebp - 1 - .__temp004 ], ax
		;	empiler			__temp4
				word.push			[ ebp - 1 - .__temp004 ]
		;	empiler			a
				word.push			[ ebp + 8 + .a ]
		;	appeler			pgcd
				subprogram.call 	pgcd
		;	renvoyer		__temp5
				mov					ebx, dword [ ebp + 8 + .result ]
				mov					ax, word [ ebp - 1 - .__temp005 ]
				mov					word [ebx], ax
.finsi001:
.finsi002:
	subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ	4 + 4
.a				equ 0
.b				equ 2
.result 		equ 4
; variables locales et temporaires
.vars_size		equ 0
.temps_size		equ 10
.__temp000		equ 0
.__temp001		equ 1
.__temp002		equ 2
.__temp003		equ 4
.__temp004		equ 6
.__temp005		equ 8
; -------------------------------------

; =====================================
section		.text
calculpgcd:
				subprogram.prologue
		;	ecrire ( ... )
				push 				dword __ch1
				subprogram.call		writeString
		;	lire ( x )
				push 				dword x
				subprogram.call		readInt
		;	ecrire ( ... )
				push 				dword __ch2
				subprogram.call		writeString
		;	lire y
				push 				dword y
				subprogram.call		readInt
		;	empiler 		& __temp6
				mov					eax, ebp
				add					eax, - 1 - .__temp006
				push				eax
		;	empiler			y
				word.push			[ y ]
		;	empiler			x
				word.push			[ x ]
		;	appeler			pgcd
				subprogram.call 	pgcd
		;	resultat = __temp6
				mov					ax, word [ ebp - 1 - .__temp006 ]
				mov					word [ resultat ], ax
		;	ecrire ( ... )
				push 				dword __ch3
				subprogram.call		writeString
		;	ecrire ( ... )
				word.push			[x]
				subprogram.call		writeInt
		;	ecrire ( ... )
				push 				dword __ch4
				subprogram.call		writeString
		;	ecrire ( ... )
				word.push			[y]
				subprogram.call		writeInt
		;	ecrire ( ... )
				push 				dword __ch5
				subprogram.call		writeString
		;	ecrire ( ... )
				word.push			[resultat]
				subprogram.call		writeInt
		;	sautdeligne
				subprogram.call		newLine
		;	fin
				subprogram.epilogue
; -------------------------------------
section		.bss
; decalage pour acceder aux arguments
.args_size		equ	0
; variables locales et temporaires
.vars_size		equ 0
.temps_size		equ 2
.__temp006		equ 0
; -------------------------------------
section		.data
; variables globales
x				dw 0
y				dw 0
resultat		dw 0
; chaines de caracteres statiques
__ch1			db 27, "Saisir la premiere valeur: "
__ch2			db 26, "Saisir la seconde valeur: "
__ch3			db 11, "le pgcd de "
__ch4			db 7, " et de "
__ch5			db 5, " est "

; =====================================
section    .text
_main:
    program.prologue
	subprogram.call		calculpgcd
	program.epilogue
