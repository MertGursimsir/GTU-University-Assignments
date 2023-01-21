module datapath(
	input [31:0] A,
	input [63:0] P,

	input i_incr,
	input i_clr,
	input shiftR,
	input write,

	output reg i_lt_32,
	output p0,
	output [63:0] Res
);


wire [4:0] i;
wire [31:0] i_incremented;
wire [4:0] newi;

wire [2:0] garbage;

wire [31:0] res, sumMSB;

//ADD TO PRODUCT
_2x1_mux M0(1'd0, A[0], write, res[0]);
_2x1_mux M1(1'd0, A[1], write, res[1]);
_2x1_mux M2(1'd0, A[2], write, res[2]);
_2x1_mux M3(1'd0, A[3], write, res[3]);
_2x1_mux M4(1'd0, A[4], write, res[4]);
_2x1_mux M5(1'd0, A[5], write, res[5]);
_2x1_mux M6(1'd0, A[6], write, res[6]);
_2x1_mux M7(1'd0, A[7], write, res[7]);
_2x1_mux M8(1'd0, A[8], write, res[8]);
_2x1_mux M9(1'd0, A[9], write, res[9]);
_2x1_mux M10(1'd0, A[10], write, res[10]);
_2x1_mux M11(1'd0, A[11], write, res[11]);
_2x1_mux M12(1'd0, A[12], write, res[12]);
_2x1_mux M13(1'd0, A[13], write, res[13]);
_2x1_mux M14(1'd0, A[14], write, res[14]);
_2x1_mux M15(1'd0, A[15], write, res[15]);
_2x1_mux M16(1'd0, A[16], write, res[16]);
_2x1_mux M17(1'd0, A[17], write, res[17]);
_2x1_mux M18(1'd0, A[18], write, res[18]);
_2x1_mux M19(1'd0, A[19], write, res[19]);
_2x1_mux M20(1'd0, A[20], write, res[20]);
_2x1_mux M21(1'd0, A[21], write, res[21]);
_2x1_mux M22(1'd0, A[22], write, res[22]);
_2x1_mux M23(1'd0, A[23], write, res[23]);
_2x1_mux M24(1'd0, A[24], write, res[24]);
_2x1_mux M25(1'd0, A[25], write, res[25]);
_2x1_mux M26(1'd0, A[26], write, res[26]);
_2x1_mux M27(1'd0, A[27], write, res[27]);
_2x1_mux M28(1'd0, A[28], write, res[28]);
_2x1_mux M29(1'd0, A[29], write, res[29]);
_2x1_mux M30(1'd0, A[30], write, res[30]);
_2x1_mux M31(1'd0, A[31], write, res[31]);

_32_bit_adder incr_i(.A(P[63:32]), .B(res), .S(sumMSB), .CIn(garbage[0]), .COut(garbage[1]), .C30(garbage[2]));

//SHIFT RIGHT
assign Res[30:0] = P[31:1];
assign Res[63:31] = {1'b0, sumMSB};

//INCREMENT i
_32_bit_adder increment_i(.A({27'd0, i}), .B(32'd1), .S(i_incremented), .CIn(garbage[0]), .COut(garbage[1]), .C30(garbage[2]));
_2x1_mux MU0(i[0], i_incremented[0], i_incr, newi[0]);
_2x1_mux MU1(i[1], i_incremented[1], i_incr, newi[1]);
_2x1_mux MU2(i[2], i_incremented[2], i_incr, newi[2]);
_2x1_mux MU3(i[3], i_incremented[3], i_incr, newi[3]);
_2x1_mux MU4(i[4], i_incremented[4], i_incr, newi[4]);

//i_lt_32?
_32_bit_set_less_than SLT(i_lt_32, {27'd0, newi}, 32'd32);

//clear
_2x1_mux MUX0(newi[0], 1'b0, i_clr, newi[0]);
_2x1_mux MUX1(newi[1], 1'b0, i_clr, newi[1]);
_2x1_mux MUX2(newi[2], 1'b0, i_clr, newi[2]);
_2x1_mux MUX3(newi[3], 1'b0, i_clr, newi[3]);
_2x1_mux MUX4(newi[4], 1'b0, i_clr, newi[4]);
assign i = 4'b0000;

assign p0 = Res[0];

endmodule