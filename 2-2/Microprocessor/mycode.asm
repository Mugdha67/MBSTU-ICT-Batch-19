.model small
.stack 100h
.code    

main proc
    ;mov ah,2
    ;mov dl,'?'
    ;int 21h  
    
    mov ah,1
    int 21h
    mov bl,al
     
       ;print    
 MOV AH, 2 
MOV DL, 0ah
INT 21H 
MOV DL,0dh
INT 21H 
         mov dl,bl
         int 21h
         
         ;dos exit
         mov ah,4ch
         int 21h
           
    main endp 
end main