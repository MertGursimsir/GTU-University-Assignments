module _2x1_mux(I0, I1, S, RES);
input I0, I1, S;
output RES;

wire T0, T1, not_S;

not N0(not_S, S);
and A0(T0, I0, not_S);
and A1(T1, I1, S);

or O0(RES, T0, T1);

endmodule