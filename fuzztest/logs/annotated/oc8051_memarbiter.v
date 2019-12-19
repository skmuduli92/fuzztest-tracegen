	// verilator_coverage annotation
	/*
	 * oc8051_memarbiter
	 *
	 * Written by Pramod Subramanyan.
	 * psubrama@princeton.edu
	 *
	 * 3-port arbiter for the OC8051 XRAM.
	 *
	 */
	
	// synopsys translate_off
	`include "oc8051_timescale.v"
	// synopsys translate_on
	
	module oc8051_memarbiter8(
	    clk, 
	    rst, 
	    selected_port,
	    // port A.
	    stb_A,
	    wr_A, 
	    ack_A,
	    addr_A, 
	    data_in_A, 
	    data_out_A,
	    // port B.
	    stb_B,
	    wr_B, 
	    ack_B,
	    addr_B, 
	    data_in_B, 
	    data_out_B,
	    // port C.
	    stb_C,
	    wr_C,
	    ack_C,
	    addr_C,
	    data_in_C,
	    data_out_C,
	    // port D.
	    stb_D,
	    wr_D,
	    ack_D,
	    addr_D,
	    data_in_D,
	    data_out_D,
	    // port E.
	    stb_E,
	    wr_E,
	    ack_E,
	    addr_E,
	    data_in_E,
	    data_out_E,
	    // memory (XRAM) port.
	    stb,
	    wr,
	    ack,
	    addr,
	    data_in,
	    data_out
	);
%000001	input            clk;
 000335	input            rst;
	
	// port A.
 000192	input            stb_A;
 000192	output           ack_A;
 000064	input            wr_A;
 000416	input [15:0]     addr_A;
 000214	input [7:0]      data_in_A;
 000804	output [7:0]     data_out_A;
	
	// port B.
 000012	input            stb_B;
 000256	output           ack_B;
%000008	input            wr_B;
 000246	input [15:0]     addr_B;
 000359	input [7:0]      data_in_B;
 000804	output [7:0]     data_out_B;
	
	// port C.
%000000	input            stb_C;
%000000	output           ack_C;
%000000	input            wr_C;
%000000	input [15:0]     addr_C;
%000000	input [7:0]      data_in_C;
 000804	output [7:0]     data_out_C;
	
	// port D.
%000000	input            stb_D;
%000000	output           ack_D;
%000000	input            wr_D;
%000000	input [15:0]     addr_D;
%000000	input [7:0]      data_in_D;
 000804	output [7:0]     data_out_D;
	
	// port E.
%000000	input            stb_E;
%000000	output           ack_E;
%000000	input            wr_E;
%000000	input [15:0]     addr_E;
%000000	input [7:0]      data_in_E;
 000804	output [7:0]     data_out_E;
	
	// XRAM (memory) port.
 000204	output           stb;
 000072	output           wr;
 000448	input            ack;
 000720	output [15:0]    addr;
 000578	output [7:0]     data_in;
 000804	input [7:0]      data_out;
	
	localparam PORT_A = 3'd0;
	localparam PORT_B = 3'd1;
	localparam PORT_C = 3'd2;
	localparam PORT_D = 3'd3;
	localparam PORT_E = 3'd4;
	
 000012	output wire [2:0] selected_port;
	
	// Is the arbiter already held, or is it going to make a new choice?
 000448	reg arbiter_state;      
%000004	reg [2:0] arbit_holder;
	
	// arbitration muxes.
	wire stb        = selected_port == PORT_A ? stb_A     : 
	                  selected_port == PORT_B ? stb_B     :
	                  selected_port == PORT_C ? stb_C     : 
	                  selected_port == PORT_D ? stb_D     : stb_E;
	
	wire wr         = selected_port == PORT_A ? wr_A      : 
	                  selected_port == PORT_B ? wr_B      :
	                  selected_port == PORT_C ? wr_C      :
	                  selected_port == PORT_D ? wr_D      : wr_E;
	
	wire [15:0] addr = selected_port == PORT_A ? addr_A    :
	                   selected_port == PORT_B ? addr_B    :
	                   selected_port == PORT_C ? addr_C    : 
	                   selected_port == PORT_D ? addr_D    : addr_E;
	
	wire [7:0] data_in = selected_port == PORT_A ? data_in_A : 
	                     selected_port == PORT_B ? data_in_B :
	                     selected_port == PORT_C ? data_in_C : 
	                     selected_port == PORT_D ? data_in_D : data_in_E;
	
	wire ack_A      = selected_port == PORT_A ? ack : 1'b0;
	wire ack_B      = selected_port == PORT_B ? ack : 1'b0;
	wire ack_C      = selected_port == PORT_C ? ack : 1'b0;
	wire ack_D      = selected_port == PORT_D ? ack : 1'b0;
	wire ack_E      = selected_port == PORT_E ? ack : 1'b0;
	
	wire [7:0] data_out_A = data_out;
	wire [7:0] data_out_B = data_out;
	wire [7:0] data_out_C = data_out;
	wire [7:0] data_out_D = data_out;
	wire [7:0] data_out_E = data_out;
	
	// selection logic.
	localparam STATE_INUSE = 1'd1;
	localparam STATE_IDLE  = 1'd0;
	
	// The next state of the arbiter.
	// If currently in use, and we got an ack, then transition to idle.
 000449	wire arbiter_state_inuse_next = ack ? STATE_IDLE : STATE_INUSE;
	
	// If current idle and someone made a request, transition to inuse.
 000640	wire arbiter_state_idle_next  = 
	        ((stb_A || stb_B || stb_C || stb_D || stb_E) && !ack) ? STATE_INUSE : STATE_IDLE;
	// Next state of the arbiter.
 000640	wire arbiter_state_next = 
	        (arbiter_state == STATE_IDLE)  ? arbiter_state_idle_next  :
	        (arbiter_state == STATE_INUSE) ? arbiter_state_inuse_next : 1'bX;
	
	// Do we select a new winner for the arbitration? Answer is yes if we are
	// currently idle and won't be idle in the next cycle.
 000640	wire arbit_select_winner = (arbiter_state == STATE_IDLE) && (arbiter_state_next == STATE_INUSE);
	
	// Who is the new winner? D has the lowest priority, then C then B then A.
 000012	wire [2:0] arbit_winner = (!stb_A && !stb_B && !stb_C && !stb_D && stb_E) ? PORT_E :
	                          (!stb_A && !stb_B && !stb_C && stb_D)           ? PORT_D :
	                          (!stb_A && !stb_B && stb_C)                     ? PORT_C :
	                          (!stb_A && stb_B)                               ? PORT_B : PORT_A;
	                    
	// Who is the current holder of the arbitration?      
%000004	wire [2:0] arbit_holder_next = arbit_select_winner ? arbit_winner : arbit_holder;
	
	// The selected port is the current cycle winner if we are idle
	// and the current holder if we are in use.
	assign selected_port = (arbiter_state == STATE_IDLE) ? arbit_winner : arbit_holder;
	
	always @(posedge clk)
	begin
	    if (rst) begin
	        arbiter_state       <= STATE_IDLE;
	        arbit_holder        <= PORT_A;
	    end
	    else begin
	        arbiter_state       <= arbiter_state_next;
	        arbit_holder        <= arbit_holder_next;
	    end
	end
	endmodule
	
