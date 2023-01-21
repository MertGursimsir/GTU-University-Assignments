`define DELAY 20
module mips_test_lw();
reg [9:0] PC;
reg clk;

_16_bit_mips_single test(.PC(PC), .clk(clk));

initial begin 
clk = 1'b1; PC = 10'b0000000111;
#`DELAY;

end

endmodule