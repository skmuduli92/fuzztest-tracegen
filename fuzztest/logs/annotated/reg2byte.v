	// verilator_coverage annotation
	/*
	 * This wrapper was written by Pramod Subramanyan.
	 *
	 * Email: pramod.subramanyan@gmail.com
	 */ 
	
	// synopsys translate_off
	`include "oc8051_timescale.v"
	// synopsys translate_on
	
	module reg2byte(clk, rst, en, wr, addr, data_in, data_out, reg_out);
%000001	    input           clk;
 000335	    input           rst;
%000000	    input           en;
%000008	    input           wr;
 000335	    input           addr;
 000214	    input   [7:0]   data_in;
%000000	    output  [7:0]   data_out;
%000000	    output  [15:0]  reg_out;
	
	    reg     [15:0]  reg_out;
	
%000004	    wire wr0  = en && wr && addr == 0;
%000004	    wire wr1  = en && wr && addr == 1;
	
%000001	    wire [7:0] reg0_next = wr0 ? data_in : reg_out[7:0];
%000003	    wire [7:0] reg1_next = wr1 ? data_in : reg_out[15:8];
	
%000000	    wire [7:0] data_out_mux = 
	                    addr == 1'd0 ? reg_out[7:0] : reg_out[15:8];
	    assign data_out = data_out_mux;
	
	    always @(posedge clk)
	    begin
	        if (rst) begin
	            reg_out <= 16'b0;
	        end
	        else begin
	            reg_out[7:0]     <= reg0_next;
	            reg_out[15:8]    <= reg1_next;
	        end
	    end
	endmodule
	
