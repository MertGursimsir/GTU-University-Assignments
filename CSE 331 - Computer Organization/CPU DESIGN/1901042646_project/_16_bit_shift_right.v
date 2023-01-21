module _16_bit_shift_right(A, Shift, Result);
input [15:0] A;
input [3:0] Shift;
output [15:0] Result;

assign Result = A >> Shift;

endmodule