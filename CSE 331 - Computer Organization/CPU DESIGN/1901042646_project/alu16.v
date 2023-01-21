module alu16(A, B, ALUop, Result, shamt, Zero);
input [15:0] A, B;
input [3:0] shamt;
input [2:0] ALUop;
output [15:0] Result;
output Zero;

//Temporary results
wire [15:0] ADD, SUBT, MULT, SLL, AND, OR, SLT, SRL;
wire Set, CoutA, CoutS, GarbageA, GarbageS;
wire ZeroTemp, CompZeroTemp;

//ADD
_16_bit_adder add_nums(A, B, ADD, 1'b0, CoutA, GarbageA);

//SUB
_16_bit_subtractor sub_nums(A, B, SUBT, CoutS, GarbageS);

//MULT
////////////////////////////////////////////////
////////////////////////////////////////////////

//SLL
_16_bit_shift_left sll_nums(B, shamt, SLL);

//AND
_16_bits_and and_nums(AND, A, B);

//OR
_16_bits_or or_nums(OR, A, B);

//SLT
_16_bit_set_less_than slt_nums(Set, A, B);

//SRL
_16_bit_shift_right srl_nums(B, shamt, SRL);

//MUX
_8x1_mux M0(ADD[0], SUBT[0], MULT[0], SLL[0], AND[0], OR[0], Set, SRL[0], ALUop, Result[0]);
_8x1_mux M1(ADD[1], SUBT[1], MULT[1], SLL[1], AND[1], OR[1], 1'b0, SRL[1], ALUop, Result[1]);
_8x1_mux M2(ADD[2], SUBT[2], MULT[2], SLL[2], AND[2], OR[2], 1'b0, SRL[2], ALUop, Result[2]);
_8x1_mux M3(ADD[3], SUBT[3], MULT[3], SLL[3], AND[3], OR[3], 1'b0, SRL[3], ALUop, Result[3]);
_8x1_mux M4(ADD[4], SUBT[4], MULT[4], SLL[4], AND[4], OR[4], 1'b0, SRL[4], ALUop, Result[4]);
_8x1_mux M5(ADD[5], SUBT[5], MULT[5], SLL[5], AND[5], OR[5], 1'b0, SRL[5], ALUop, Result[5]);
_8x1_mux M6(ADD[6], SUBT[6], MULT[6], SLL[6], AND[6], OR[6], 1'b0, SRL[6], ALUop, Result[6]);
_8x1_mux M7(ADD[7], SUBT[7], MULT[7], SLL[7], AND[7], OR[7], 1'b0, SRL[7], ALUop, Result[7]);
_8x1_mux M8(ADD[8], SUBT[8], MULT[8], SLL[8], AND[8], OR[8], 1'b0, SRL[8], ALUop, Result[8]);
_8x1_mux M9(ADD[9], SUBT[9], MULT[9], SLL[9], AND[9], OR[9], 1'b0, SRL[9], ALUop, Result[9]);
_8x1_mux M10(ADD[10], SUBT[10], MULT[10], SLL[10], AND[10], OR[10], 1'b0, SRL[10], ALUop, Result[10]);
_8x1_mux M11(ADD[11], SUBT[11], MULT[11], SLL[11], AND[11], OR[11], 1'b0, SRL[11], ALUop, Result[11]);
_8x1_mux M12(ADD[12], SUBT[12], MULT[12], SLL[12], AND[12], OR[12], 1'b0, SRL[12], ALUop, Result[12]);
_8x1_mux M13(ADD[13], SUBT[13], MULT[13], SLL[13], AND[13], OR[13], 1'b0, SRL[13], ALUop, Result[13]);
_8x1_mux M14(ADD[14], SUBT[14], MULT[14], SLL[14], AND[14], OR[14], 1'b0, SRL[14], ALUop, Result[14]);
_8x1_mux M15(ADD[15], SUBT[15], MULT[15], SLL[15], AND[15], OR[15], 1'b0, SRL[15], ALUop, Result[15]);

//SET ZERO BIT
or(ZeroTemp, Result[0], Result[1], Result[2], Result[3],
			 Result[4], Result[5], Result[6], Result[7],
			 Result[8], Result[9], Result[10], Result[11],
			 Result[12], Result[13], Result[14], Result[15]);
not(CompZeroTemp, ZeroTemp);
_2x1_mux Z(CompZeroTemp, ZeroTemp, ALUop[0], Zero);

endmodule