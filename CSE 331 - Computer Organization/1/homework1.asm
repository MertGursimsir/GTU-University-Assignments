	.data
intArray: .space 400

sizePrompt: .asciiz "Please enter size of the array between 2 and 100: "
kPrompt: .asciiz "Please enter integer k between 1 and 100: "
elementPrompt: .asciiz "Please enter elements one by one between 1 and 100:\n"
element: .asciiz ". element --> "
textPairs: .asciiz "Pairs:\n"
textCount: .asciiz "Count: "

	.text
	.globl main
main: 
readSize:
	li $v0, 4		#System call code for print prompt
	la $a0, sizePrompt	#Address of prompt to print
	syscall			#Print
	
	li $v0, 5		#System call code for read integer
	syscall			#Read integer
	move $t3, $v0		#Move size to t3

	slti $s0, $t3, 101	#Check if input exceeds the limits or not
	beq $s0, $zero, readSize
	slti $s1, $t3, 2
	bne $s1, $zero, readSize
	
readK:
	li $v0, 4		#System call code for print prompt
	la $a0, kPrompt		#Address of prompt to print
	syscall			#Print
	
	li $v0, 5		#System call code for read integer
	syscall			#Read integer
	move $t4, $v0		#Move k to t4
	
	slti $s0, $t4, 101	#Check if input exceeds the limits or not
	beq $s0, $zero, readK
	slti $s1, $t4, 1
	bne $s1, $zero, readK
	
	li $v0, 4		#System call code for print prompt
	la $a0, elementPrompt	#Address of prompt to print
	syscall			#Print
	
	add $t0, $zero, $zero	#Clear the t0 register -> i
	add $t5, $zero, $zero	#Clear the t5 register -> index
forElements:
	slt $t8, $t0, $t3	#$t8 = 0 if $t0 >= $t3 (i >= n)
	beq $t8, $zero, exitForElements	#Exit if i >= n
	
readElement:
	li $v0, 1
	move $a0, $t0
	syscall
	li $v0, 4		#System call code for print prompt
	la $a0, element		#Address of prompt to print
	syscall			#Print
	li $v0, 5		#System call code for read integer
	syscall			#Read integer
	slti $s0, $v0, 101	#Check if input exceeds the limits or not
	beq $s0, $zero, readElement
	slti $s1, $v0, 1
	bne $s1, $zero, readElement
	
	sw $v0, intArray($t5)	#Store value to array
	addi $t5, $t5, 4	#Increment index by 4 for integer
	
	addi $t0, $t0, 1	#i += 1
	j forElements		#Repeat the loop
	
exitForElements:	
	li $v0, 4		#System call code for print pairs
	la $a0, textPairs	#Address of text to print
	syscall			#Print
	
	move $a0, $t3		#Move size to first argument register
	la $a1, intArray	#Move array address to second argument register
	move $a2, $t4		#Move k to third argument register
	jal divisibleSumPairs	#Call divisibleSumPairs procedure
	
	move $s0, $v0		#Move returned value (count) to s0
	j finish		#Go to finish label
	
divisibleSumPairs:
	move $t3, $a0		#Move arguments to t registers
	move $t4, $a2
	add $t0, $zero, $zero	#Clear the t0 register -> i
	add $t2, $zero, $zero	#Clear the t2 register -> count
outerFor:
	slt $t8, $t0, $t3	#$t8 = 0 if $t0 >= $t3 (i >= n)
	beq $t8, $zero, exit	#Exit if i >= n
	addi $t1, $t0, 1	#j = i + 1
innerFor:
	slt $t8, $t1, $t3	 #$t8 = 0 if $t1 >= $t3 (j >= n)
	beq $t8, $zero, exitInner#Exit inner loop if j >= n
	sll $t6, $t0, 2		 #t6 = i * 4
	sll $t7, $t1, 2		 #t7 = j * 4
	lw $s0, intArray($t6)	 #s0 = array[i]
	lw $s1, intArray($t7)	 #s1 = array[j]
	add $s2, $s0, $s1	 #s2 = array[i] + array[j]
	div $s2, $t4		 #HI = (array[i]+array[j])%k
	mfhi $t9		 #t9 = HI
	beq $t9, $zero, pairs	 #We have pair, add it to count under pairs
	addi $t1, $t1, 1	 #j += 1
	j innerFor		 #Continue with next elements
pairs:
	addi $t2, $t2, 1	 #Incrementing count by 1
	move $a0, $s0		 #Move array[i] to $a0
	li $v0, 1		 #System call code for print array[i]
	syscall			 #Print
	li $a0, 45		 #Load "-" character to a0
	li $v0, 11  		 #Syscall number for printing character
	syscall			 #Print character
	move $a0, $s1		 #Move array[j] to $a0
	li $v0, 1		 #System call code for print array[j]
	syscall			 #Print
	li $a0, 10		 #Load end-of-line character to a0
	li $v0, 11  		 #Syscall number for printing character
	syscall			 #Print
	addi $t1, $t1, 1	 #j += 1
	j innerFor		 #Continue with next elements
exitInner:
	addi $t0, $t0, 1	#i += 1
	j outerFor		#Jump to outer loop
exit:
	move $v0, $t2		#Move count to $v0, to return register
	jr $ra

finish:
	li $v0, 4		#System call code for print count text
	la $a0, textCount	#Address of text to print
	syscall			#Print
	move $a0, $s0		#Move count to $a0
	li $v0, 1		#System call code for print count
	syscall			#Print
