module _2x1_16_bit_mux(I0, I1, S, RES);
input [15:0] I0, I1;
input S;
output [15:0] RES;


_2x1_mux MUX0(I0[0], I1[0], S, RES[0]);
_2x1_mux MUX1(I0[1], I1[1], S, RES[1]);
_2x1_mux MUX2(I0[2], I1[2], S, RES[2]);
_2x1_mux MUX3(I0[3], I1[3], S, RES[3]);
_2x1_mux MUX4(I0[4], I1[4], S, RES[4]);
_2x1_mux MUX5(I0[5], I1[5], S, RES[5]);
_2x1_mux MUX6(I0[6], I1[6], S, RES[6]);
_2x1_mux MUX7(I0[7], I1[7], S, RES[7]);
_2x1_mux MUX8(I0[8], I1[8], S, RES[8]);
_2x1_mux MUX9(I0[9], I1[9], S, RES[9]);
_2x1_mux MUX10(I0[10], I1[10], S, RES[10]);
_2x1_mux MUX11(I0[11], I1[11], S, RES[11]);
_2x1_mux MUX12(I0[12], I1[12], S, RES[12]);
_2x1_mux MUX13(I0[13], I1[13], S, RES[13]);
_2x1_mux MUX14(I0[14], I1[14], S, RES[14]);
_2x1_mux MUX15(I0[15], I1[15], S, RES[15]);

endmodule