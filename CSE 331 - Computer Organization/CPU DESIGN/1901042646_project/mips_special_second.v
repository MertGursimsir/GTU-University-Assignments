`define DELAY 50
module mips_special_second();
reg [9:0] PC;
reg clk;

_16_bit_mips_single test(.PC(PC), .clk(clk));

initial begin 
clk = 1'b1; PC = 10'b0000010000;
#`DELAY;
clk = 1'b1; PC = 10'b0000010001;
#`DELAY;
clk = 1'b1; PC = 10'b0000010010;
#`DELAY;
end

endmodule