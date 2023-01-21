module alu_control(
input [2:0] AluOP,
input [5:0] Func,

output [2:0] AluCtr
);

wire alu_op_not_0, alu_op_not_1, alu_op_not_2;
wire func_not_0, func_not_1, func_not_2, func_not_3, func_not_4, func_not_5;
wire r_type;
wire t0, t1, t2, t3, t4, t5, t6, t7, t8;

not N0(alu_op_not_0, AluOP[0]);
not N1(alu_op_not_1, AluOP[1]);
not N2(alu_op_not_2, AluOP[2]);

not N3(func_not_0, Func[0]);
not N4(func_not_1, Func[1]);
not N5(func_not_2, Func[2]);
not N6(func_not_3, Func[3]);
not N7(func_not_4, Func[4]);
not N8(func_not_5, Func[5]);

and A0(r_type, alu_op_not_0, AluOP[1], alu_op_not_2);

//0
and A1(t0, r_type, Func[1], func_not_3);
and A2(t1, r_type, Func[0]);
and A3(t2, r_type, func_not_5, func_not_1);
or O0(AluCtr[0], AluOP[0], t0, t1, t2);

//1
and A4(t3, r_type, func_not_5);
and A5(t4, r_type, Func[3]);
and A6(t8, AluOP[1], AluOP[2]);
or O1(AluCtr[1], t3, t4, t8);

//2
and A7(t5, r_type, Func[3]);
and A8(t6, r_type, Func[2]);
and A9(t7, r_type, Func[1], func_not_5);
or O2(AluCtr[2], AluOP[2], t5, t6, t7);

endmodule