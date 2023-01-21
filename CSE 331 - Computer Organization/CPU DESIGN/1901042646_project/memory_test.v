`define DELAY 20
module memory_test();
reg [15:0] address, data;
reg wEn;

wire [15:0] outData;

memory_block mem(.address(address), .data(data), .wEn(wEn), .outData(outData));

initial begin 
address = 16'h0000; data = 16'h0F0F; wEn = 1'b1;
#`DELAY;

address = 16'h0000; data = 16'h0000; wEn = 1'b0;
#`DELAY;

end

initial
begin
$monitor("MEMORY Results: Address: %16d, Data: %16b, WriteEnable = %1b, Output: %16b", address, data, wEn, outData);
end

endmodule