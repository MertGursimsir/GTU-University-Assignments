`define DELAY 20
module register_test();
reg regWrite;
reg [3:0] reg_1, reg_2, write_addr;
reg [15:0] write_data;

wire [15:0] data_1, data_2;

register_block regist(.regWrite(regWrite), .reg_1(reg_1), .reg_2(reg_2), .write_addr(write_addr), .write_data(write_data), .data_1(data_1), .data_2(data_2));

initial begin 
reg_1 = 4'b0000; reg_2 = 4'b0001; write_addr = 4'b0010; write_data = 16'h0000;  regWrite = 1'b0;
#`DELAY;

reg_1 = 4'b0011; reg_2 = 4'b0100; write_addr = 4'b0101; write_data = 16'hFFFF;  regWrite = 1'b1;
#`DELAY;

reg_1 = 4'b0101; reg_2 = 4'b0101; write_addr = 4'b0000; write_data = 16'h0000;  regWrite = 1'b0;
#`DELAY;


end

initial
begin
$monitor("REGISTER Results: First Reg: %4b, Read Data 1: %16b, Second Reg: %4b, Read Data 2: %16b, Reg Write: %1b, Write Address: %4b, Write Data: %16b", reg_1, data_1, reg_2, data_2, regWrite, write_addr, write_data);
end

endmodule