`define DELAY 20
module instruction_test();
reg [9:0] address;
wire [31:0] instr;

instruction_block instr_mod(.address(address), .instr(instr));

initial begin 
address = 10'b0000000000;
#`DELAY;

address = 10'b0000000001;
#`DELAY;

end

initial
begin
$monitor("INSTRUCTION MEMORY Results: Address: %10d, Instruction: %32b", address, instr);
end

endmodule