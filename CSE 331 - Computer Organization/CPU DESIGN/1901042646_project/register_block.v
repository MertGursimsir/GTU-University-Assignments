module register_block(
	input [3:0] reg_1, reg_2, write_addr,
	input [15:0] write_data,
	input regWrite,
	output reg [15:0] data_1, data_2
);

reg [15:0] registers [15:0];

initial begin
	$readmemb("C:/Users/Mert/Desktop/register.txt", registers);
end

always @(*) begin
	if(regWrite) begin
		registers[write_addr] <= write_data[15:0];
		$writememb("C:/Users/Mert/Desktop/register.txt", registers);
	end
end

always @(*)begin
	data_1 = registers[reg_1];
	data_2 = registers[reg_2];
end



endmodule