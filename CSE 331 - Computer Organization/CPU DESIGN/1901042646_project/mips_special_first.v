`define DELAY 50
module mips_special_first();
reg [9:0] PC;
reg clk;

_16_bit_mips_single test(.PC(PC), .clk(clk));

initial begin 
clk = 1'b1; PC = 10'b0000001101;
#`DELAY;
clk = 1'b1; PC = 10'b0000001110;
#`DELAY;
clk = 1'b1; PC = 10'b0000001111;
#`DELAY;
end

endmodule