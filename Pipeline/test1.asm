#Testing comments
#This should jump the add
		beq $1, $1, 0x1
add $1, $1, $2
#This should jump back to add the first time not second
beq $1, $14, 0xfffffffe #test comment on end

addi $31, $31, 0x0fff
#test an uninitialized register
sub $8,     $1, $31
#attempt load word. Shouldnt load
lw $1, 0($27)
#add large negative numbers together, check overflow should get 1
add $1, $4, $5
#add negative number
addi $1, $10, -15