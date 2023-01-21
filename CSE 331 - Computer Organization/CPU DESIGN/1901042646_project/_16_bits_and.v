module _16_bits_and(Res, A, B);
input [15:0] A, B;
output [15:0] Res;

and A0(Res[0], A[0], B[0]);
and A1(Res[1], A[1], B[1]);
and A2(Res[2], A[2], B[2]);
and A3(Res[3], A[3], B[3]);
and A4(Res[4], A[4], B[4]);
and A5(Res[5], A[5], B[5]);
and A6(Res[6], A[6], B[6]);
and A7(Res[7], A[7], B[7]);
and A8(Res[8], A[8], B[8]);
and A9(Res[9], A[9], B[9]);
and A10(Res[10], A[10], B[10]);
and A11(Res[11], A[11], B[11]);
and A12(Res[12], A[12], B[12]);
and A13(Res[13], A[13], B[13]);
and A14(Res[14], A[14], B[14]);
and A15(Res[15], A[15], B[15]);

endmodule