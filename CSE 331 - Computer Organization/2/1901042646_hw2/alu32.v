module alu32(A, B, ALUop, Result);
input [31:0] A, B;
input [2:0] ALUop;
output [31:0] Result;

//Temporary results
wire [31:0] ADD, SUBT, MULT, XOR, AND, OR, SLT, NOR;
wire Set, CoutA, CoutS, GarbageA, GarbageS;

//ADD
_32_bit_adder add_nums(A, B, ADD, 1'b0, CoutA, GarbageA);

//SUB
_32_bit_subtractor sub_nums(A, B, SUBT, CoutS, GarbageS);

//MULT
////////////////////////////////////////////////
////////////////////////////////////////////////

//XOR
_32_bits_xor xor_nums(XOR, A, B);

//AND
_32_bits_and and_nums(AND, A, B);

//OR
_32_bits_or or_nums(OR, A, B);

//SLT
_32_bit_set_less_than slt_nums(Set, A, B);

//NOR
_32_bits_nor nor_nums(NOR, A, B);

//MUX
_8x1_mux M0(ADD[0], SUBT[0], MULT[0], XOR[0], AND[0], OR[0], Set, NOR[0], ALUop, Result[0]);
_8x1_mux M1(ADD[1], SUBT[1], MULT[1], XOR[1], AND[1], OR[1], 1'b0, NOR[1], ALUop, Result[1]);
_8x1_mux M2(ADD[2], SUBT[2], MULT[2], XOR[2], AND[2], OR[2], 1'b0, NOR[2], ALUop, Result[2]);
_8x1_mux M3(ADD[3], SUBT[3], MULT[3], XOR[3], AND[3], OR[3], 1'b0, NOR[3], ALUop, Result[3]);
_8x1_mux M4(ADD[4], SUBT[4], MULT[4], XOR[4], AND[4], OR[4], 1'b0, NOR[4], ALUop, Result[4]);
_8x1_mux M5(ADD[5], SUBT[5], MULT[5], XOR[5], AND[5], OR[5], 1'b0, NOR[5], ALUop, Result[5]);
_8x1_mux M6(ADD[6], SUBT[6], MULT[6], XOR[6], AND[6], OR[6], 1'b0, NOR[6], ALUop, Result[6]);
_8x1_mux M7(ADD[7], SUBT[7], MULT[7], XOR[7], AND[7], OR[7], 1'b0, NOR[7], ALUop, Result[7]);
_8x1_mux M8(ADD[8], SUBT[8], MULT[8], XOR[8], AND[8], OR[8], 1'b0, NOR[8], ALUop, Result[8]);
_8x1_mux M9(ADD[9], SUBT[9], MULT[9], XOR[9], AND[9], OR[9], 1'b0, NOR[9], ALUop, Result[9]);
_8x1_mux M10(ADD[10], SUBT[10], MULT[10], XOR[10], AND[10], OR[10], 1'b0, NOR[10], ALUop, Result[10]);
_8x1_mux M11(ADD[11], SUBT[11], MULT[11], XOR[11], AND[11], OR[11], 1'b0, NOR[11], ALUop, Result[11]);
_8x1_mux M12(ADD[12], SUBT[12], MULT[12], XOR[12], AND[12], OR[12], 1'b0, NOR[12], ALUop, Result[12]);
_8x1_mux M13(ADD[13], SUBT[13], MULT[13], XOR[13], AND[13], OR[13], 1'b0, NOR[13], ALUop, Result[13]);
_8x1_mux M14(ADD[14], SUBT[14], MULT[14], XOR[14], AND[14], OR[14], 1'b0, NOR[14], ALUop, Result[14]);
_8x1_mux M15(ADD[15], SUBT[15], MULT[15], XOR[15], AND[15], OR[15], 1'b0, NOR[15], ALUop, Result[15]);
_8x1_mux M16(ADD[16], SUBT[16], MULT[16], XOR[16], AND[16], OR[16], 1'b0, NOR[16], ALUop, Result[16]);
_8x1_mux M17(ADD[17], SUBT[17], MULT[17], XOR[17], AND[17], OR[17], 1'b0, NOR[17], ALUop, Result[17]);
_8x1_mux M18(ADD[18], SUBT[18], MULT[18], XOR[18], AND[18], OR[18], 1'b0, NOR[18], ALUop, Result[18]);
_8x1_mux M19(ADD[19], SUBT[19], MULT[19], XOR[19], AND[19], OR[19], 1'b0, NOR[19], ALUop, Result[19]);
_8x1_mux M20(ADD[20], SUBT[20], MULT[20], XOR[20], AND[20], OR[20], 1'b0, NOR[20], ALUop, Result[20]);
_8x1_mux M21(ADD[21], SUBT[21], MULT[21], XOR[21], AND[21], OR[21], 1'b0, NOR[21], ALUop, Result[21]);
_8x1_mux M22(ADD[22], SUBT[22], MULT[22], XOR[22], AND[22], OR[22], 1'b0, NOR[22], ALUop, Result[22]);
_8x1_mux M23(ADD[23], SUBT[23], MULT[23], XOR[23], AND[23], OR[23], 1'b0, NOR[23], ALUop, Result[23]);
_8x1_mux M24(ADD[24], SUBT[24], MULT[24], XOR[24], AND[24], OR[24], 1'b0, NOR[24], ALUop, Result[24]);
_8x1_mux M25(ADD[25], SUBT[25], MULT[25], XOR[25], AND[25], OR[25], 1'b0, NOR[25], ALUop, Result[25]);
_8x1_mux M26(ADD[26], SUBT[26], MULT[26], XOR[26], AND[26], OR[26], 1'b0, NOR[26], ALUop, Result[26]);
_8x1_mux M27(ADD[27], SUBT[27], MULT[27], XOR[27], AND[27], OR[27], 1'b0, NOR[27], ALUop, Result[27]);
_8x1_mux M28(ADD[28], SUBT[28], MULT[28], XOR[28], AND[28], OR[28], 1'b0, NOR[28], ALUop, Result[28]);
_8x1_mux M29(ADD[29], SUBT[29], MULT[29], XOR[29], AND[29], OR[29], 1'b0, NOR[29], ALUop, Result[29]);
_8x1_mux M30(ADD[30], SUBT[30], MULT[30], XOR[30], AND[30], OR[30], 1'b0, NOR[30], ALUop, Result[30]);
_8x1_mux M31(ADD[31], SUBT[31], MULT[31], XOR[31], AND[31], OR[31], 1'b0, NOR[31], ALUop, Result[31]);

endmodule