	// verilator_coverage annotation
	module modexp(clk, rst, start, ready, m, e, n, c);
	  parameter [15:0] W = 2048;
	  
 000336	  input clk, rst;
	
	  input  [W-1:0] m;
	  input  [W-1:0] e;
	  input  [W-1:0] n;  
	  output [W-1:0] c;  // c = M^e mod n
	
%000000	  input start;
%000001	  output ready;
	
	  localparam IDLE  = 3'b000;
	  localparam BUSY1 = 3'b001;
	  localparam WAIT1 = 3'b010;
	  localparam BUSY2 = 3'b011;
	  localparam WAIT2 = 3'b100;
	
%000000	  reg[2:0] state;
	
%000011	  reg [15:0] i;
%000011	  wire [15:0] i_next;
	
	  reg [W-1:0] c;
	  wire [W-1:0] c_next;
	  wire [W-1:0] p;
	  wire [W-1:0] sq;
	
%000001	  wire sq_ready;
%000000	  wire sq_start;
%000001	  wire m_ready;
%000000	  wire m_start;
	
%000001	  wire state_idle = state == IDLE;
%000000	  wire state_busy1 = state == BUSY1;
%000000	  wire state_wait1 = state == WAIT1;
%000000	  wire state_busy2 = state == BUSY2;
%000000	  wire state_wait2 = state == WAIT2;
	
%000000	  wire ei = e[i[10:0]];
	
%000000	  wire [2:0] state_next_idle = start ? BUSY1 : IDLE;
	
%000000	  wire [2:0] state_next_busy1 = m == 0 ? IDLE
	                              : (c == 1 && ei == 0) ? BUSY1
	                              : WAIT1;
	
%000001	  wire [2:0] state_next_wait1 = !sq_ready ? WAIT1
	                              : ei ? BUSY2
	                              : (i == 0) ? IDLE
	                              : BUSY1;
	
%000001	  wire [2:0] state_next_wait2 = !m_ready ? WAIT2
	                              : (i == 0) ? IDLE
	                              : BUSY1;
	
%000000	  wire [2:0] state_next = state_idle? state_next_idle
	                        : state_busy1 ? state_next_busy1
	                        : state_wait1 ? state_next_wait1
	                        : state_busy2 ? WAIT2
	                        : state_next_wait2;
	
	  wire ready = (state == IDLE);
	
	  modmul #(.W(W)) square(
	    .clk        (clk),
	    .rst        (rst),
	    .start      (sq_start),
	    .ready      (sq_ready),
	    .a          (c),
	    .b          (c),
	    .n          (n),
	    .p          (sq)
	  );
	
	  modmul #(.W(W)) mult(
	    .clk        (clk),
	    .rst        (rst),
	    .start      (m_start),
	    .ready      (m_ready),
	    .a          (c),
	    .b          (m),
	    .n          (n),
	    .p          (p)
	  );
	
%000000	  wire next_busy = state_next == BUSY1;
	
	  assign i_next = (state_idle && next_busy) ? W-2
	                : (next_busy) ? i-1
	                : i;
	
	  assign c_next = m == 0 ? 0
	                : (state_idle && next_busy) ? (e[W-1] ? m : 1)
	                : (sq_ready && state_wait1) ? sq
	                : (m_ready && state_wait2) ? p
	                : c;
	
	  assign sq_start = state == BUSY1;
	  assign m_start = state == BUSY2;
	
	  always @(posedge clk)
	  begin
	    if (rst) begin
	      i         <= W-1;
	      state     <= IDLE;
	      c         <= 1;
	    end
	    else begin
	      i         <= i_next;
	      state     <= state_next;
	      c         <= c_next;
	    end
	  end
	endmodule
	
