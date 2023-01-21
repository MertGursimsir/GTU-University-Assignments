module control(
	input go,
	input reset,
	input CLK,
	input p0,
	input i_lt_32,
	output reg i_incr,
	output reg i_clr,
	output reg shiftR,
	output reg write
);

localparam 	S0 = 3'b000,
			S1 = 3'b001,
			S2 = 3'b010,
			S3 = 3'b011,
			S4 = 3'b100,
			S5 = 3'b101;

	
reg	[2:0] present_state;
reg	[2:0] next_state = S0;


//State Register
always @(posedge CLK)
	begin
	if(reset)
		present_state <= S0;
	else
		present_state <= next_state;
	end

//Next State Logic
always @(*)
	begin
		next_state = S0;
		case(present_state)
	
				S0:
					begin
					if(go)
						next_state = S1;			
					end
					
				
				S1:
					begin
						next_state = S2;
					end
					
				
				S2:
					begin
						if (p0)
							next_state = S3;
						else
							next_state = S4;
					end
					
				
				S3:
					begin
						next_state = S4;
					end
					
				S4:
					begin
						if (i_lt_32)
							next_state = S5;
						else
							next_state = S0;
					end
				S5:
					begin
						next_state = S2;
					end
				
			endcase
	end

//Outputs
always @(*)
		begin
			i_clr = 1'b0;
			i_incr = 1'b0;
			shiftR = 1'b0;
			write = 1'b0;
			case(present_state)
							
				S1:
					begin
						i_clr = 1'b1;
					end

				S3:
					begin	
						write = 1'b1;
					end

				S4:
					begin
						shiftR = 1'b1;
					end

				S5:
					begin
						i_incr = 1'b1;
					end
						
			endcase
			
		end				


endmodule
