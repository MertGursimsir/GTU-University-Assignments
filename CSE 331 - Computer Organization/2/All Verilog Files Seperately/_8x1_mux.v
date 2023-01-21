module _8x1_mux(I0, I1, I2, I3, I4, I5, I6, I7, S, RES);
input I0, I1, I2, I3, I4, I5, I6, I7;
input [2:0] S;
output RES;

wire [5:0] temp;

_2x1_mux M0(I0, I1, S[0], temp[0]);
_2x1_mux M1(I2, I3, S[0], temp[1]);
_2x1_mux M2(I4, I5, S[0], temp[2]);
_2x1_mux M3(I6, I7, S[0], temp[3]);

_2x1_mux M4(temp[0], temp[1], S[1], temp[4]);
_2x1_mux M5(temp[2], temp[3], S[1], temp[5]);

_2x1_mux M6(temp[4], temp[5], S[2], RES);

endmodule