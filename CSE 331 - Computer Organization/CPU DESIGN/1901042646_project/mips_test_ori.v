`define DELAY 20
module mips_test_ori();
reg [9:0] PC;
reg clk;

_16_bit_mips_single test(.PC(PC), .clk(clk));

initial begin 
clk = 1'b1; PC = 10'b0000001011;
#`DELAY;

end

endmodule