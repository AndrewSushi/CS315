test1:
	@printf "OUTPUTS FOR TEST FILES\n"
	@printf "—————————————————————————————————\n"
	@gcc assignment2.c
	@printf "inSample1.txt:\n"
	@./a.out < inSample1.txt
	@printf "—————————————————————————————————\n"
	@printf "inSample2.txt:\n"
	@./a.out < inSample2.txt
	@printf "—————————————————————————————————\n"
	@printf "inLarge1.txt:\n"
	@./a.out < inLarge1.txt
	@printf "—————————————————————————————————\n"
	@printf "inLarge2.txt:\n"
	@./a.out < inLarge2.txt
	@printf "—————————————————————————————————\n"

test2:
	@printf "OUTPUTS FOR TEST FILES\n"
	@printf "—————————————————————————————————\n"
	@gcc assignment2.c
	@printf "inSample1.txt:\n"
	@cat inSample1.txt | ./a.out
	@printf "—————————————————————————————————\n"
	@printf "inSample2.txt:\n"
	@cat inSample2.txt | ./a.out
	@printf "—————————————————————————————————\n"
	@printf "inLarge1.txt:\n"
	@cat inLarge1.txt | ./a.out
	@printf "—————————————————————————————————\n"
	@printf "inLarge2.txt:\n"
	@cat inLarge2.txt | ./a.out
	@printf "—————————————————————————————————\n"