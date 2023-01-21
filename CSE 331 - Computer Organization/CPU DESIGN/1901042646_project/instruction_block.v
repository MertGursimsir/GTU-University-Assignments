module instruction_block(
	input [9:0] address,
	output reg [31:0] instr
);

reg [31:0] instructions [1023:0];

initial begin
	$readmemb("C:/Users/Mert/Desktop/instruction.txt", instructions);
end

always @(*)begin
	instr = instructions[address];
end

endmodule