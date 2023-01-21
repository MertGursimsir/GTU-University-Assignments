module _16_bit_adder(A, B, S, CIn, COut, C14);
input [15:0] A, B;
input CIn;
output [15:0] S;
output COut, C14;

wire [14:0] C;

full_adder FA0(S[0], C[0], A[0], B[0], CIn);
full_adder FA1(S[1], C[1], A[1], B[1], C[0]);
full_adder FA2(S[2], C[2], A[2], B[2], C[1]);
full_adder FA3(S[3], C[3], A[3], B[3], C[2]);
full_adder FA4(S[4], C[4], A[4], B[4], C[3]);
full_adder FA5(S[5], C[5], A[5], B[5], C[4]);
full_adder FA6(S[6], C[6], A[6], B[6], C[5]);
full_adder FA7(S[7], C[7], A[7], B[7], C[6]);
full_adder FA8(S[8], C[8], A[8], B[8], C[7]);
full_adder FA9(S[9], C[9], A[9], B[9], C[8]);
full_adder FA10(S[10], C[10], A[10], B[10], C[9]);
full_adder FA11(S[11], C[11], A[11], B[11], C[10]);
full_adder FA12(S[12], C[12], A[12], B[12], C[11]);
full_adder FA13(S[13], C[13], A[13], B[13], C[12]);
full_adder FA14(S[14], C14, A[14], B[14], C[13]);
full_adder FA15(S[15], COut, A[15], B[15], C14);

endmodule