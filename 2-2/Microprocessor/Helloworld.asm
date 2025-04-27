.MODEL      SMALL
 .STACK      100H
 .DATA


 MSG DB 'HELLO! Gandu Mahi$'
 .CODE
 MAIN PROC
 ; initialize DS
 MOV AX, @DATA
 MOV DS, AX
 ; display message
 LEA DX, MSG
 MOV AH, 9
 INT 21H
 ; return to DOS
 MOV AH, 4CH
 INT 21H
 MAIN ENDP
 END MAIN