module memory_block(
	input [15:0] address,
	input [15:0] data,
	input wEn,
	output reg [15:0] outData
);

reg [15:0] datas [65535:0];

initial begin
	$readmemb("C:/Users/Mert/Desktop/memory.txt", datas);
end

always @(*) begin
	if(wEn) begin
		datas[address] <= data[15:0];
		$writememb("C:/Users/Mert/Desktop/memory.txt", datas);
	end
end

always @(*)begin
	outData = datas[address];
end



endmodule