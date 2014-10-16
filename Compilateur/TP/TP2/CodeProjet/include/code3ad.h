#ifndef __CODE_3_AD__
#define __CODE_3_AD__

typedef enum {
  OPCODE_NOP = 0,  /*        nop (ne rien faire) */
  OPCODE_END       /*        fin                 */
  OPCODE_CLL ,     /*        appeler x           */
  OPCODE_RESV,     /*        reserver x          */
  OPCODE_RET ,     /*        retourner x         */
  OPCODE_RETV ,    /*        renvoyer x          */

  OPCODE_ADD ,     /*        x := y + z          */
  OPCODE_SUB ,     /*        x := y - z          */
  OPCODE_MUL ,     /*        x := y * z          */
  OPCODE_DIV ,     /*        x := y / z          */
  OPCODE_NEG ,     /*        x := - y            */

  OPCODE_AND ,     /*        x := y & z          */
  OPCODE_OR  ,     /*        x := y | z          */
  OPCODE_NOT ,     /*        x := ! y            */

  OPCODE_LT ,      /*        x := y < z          */
  OPCODE_GT ,      /*        x := y > z          */
  OPCODE_LE ,      /*        x := y <= z         */
  OPCODE_GE ,      /*        x := y >= z         */
  OPCODE_EQ ,      /*        x := y == z         */
  OPCODE_NEQ ,     /*        x := y != z         */

  OPCODE_CPY ,     /*        x := y              */
  OPCODE_PTR ,     /*        x := & y            */
  OPCODE_RRT ,     /*        x := * y            */
  OPCODE_RLT ,     /*        * x := y            */

  OPCODE_JMP ,     /*        aller a x           */
  OPCODE_JMPC ,    /*        si x aller a y      */

  OPCODE_PSH ,     /*        push x              */
  OPCODE_PSP ,     /*        push & x            */
  OPCODE_PSR ,     /*        push * x            */
  OPCODE_POP ,     /*        pop x               */
  OPCODE_PPR ,     /*        pop * x             */

  OPCODE_OUT ,     /*        ecrire x            */
  OPCODE_IN  ,     /*        lire x              */
  OPCODE_NL  ,     /*        sautdeligne         */
} CodeInstruction;

#endif