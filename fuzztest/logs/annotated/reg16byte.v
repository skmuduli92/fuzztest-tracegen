	// verilator_coverage annotation
	/*
	 * This wrapper was written by Pramod Subramanyan.
	 *
	 * Email: pramod.subramanyan@gmail.com
	 */ 
	
	// synopsys translate_off
	`include "oc8051_timescale.v"
	// synopsys translate_on
	
	module reg16byte(clk, rst, en, wr, addr, data_in, data_out, reg_out);
%000001	    input           clk;
 000335	    input           rst;
%000000	    input           en;
 000064	    input           wr;
 000306	    input   [3:0]   addr;
 000214	    input   [7:0]   data_in;
%000000	    output  [7:0]   data_out;
%000000	    output  [127:0] reg_out;
	
	    reg     [127:0] reg_out;
	
%000004	    wire wr0  = en && wr && addr == 0;
%000004	    wire wr1  = en && wr && addr == 1;
%000004	    wire wr2  = en && wr && addr == 2;
%000004	    wire wr3  = en && wr && addr == 3;
%000004	    wire wr4  = en && wr && addr == 4;
%000004	    wire wr5  = en && wr && addr == 5;
%000004	    wire wr6  = en && wr && addr == 6;
%000004	    wire wr7  = en && wr && addr == 7;
%000004	    wire wr8  = en && wr && addr == 8;
%000004	    wire wr9  = en && wr && addr == 9;
%000004	    wire wr10 = en && wr && addr == 10;
%000004	    wire wr11 = en && wr && addr == 11;
%000004	    wire wr12 = en && wr && addr == 12;
%000004	    wire wr13 = en && wr && addr == 13;
%000004	    wire wr14 = en && wr && addr == 14;
%000004	    wire wr15 = en && wr && addr == 15;
	
%000000	    wire    [7:0]   reg0_next = wr0   ? data_in : reg_out[7:0];
%000003	    wire    [7:0]   reg1_next = wr1   ? data_in : reg_out[15:8];
%000003	    wire    [7:0]   reg2_next = wr2   ? data_in : reg_out[23:16];
%000008	    wire    [7:0]   reg3_next = wr3   ? data_in : reg_out[31:24];
%000003	    wire    [7:0]   reg4_next = wr4   ? data_in : reg_out[39:32];
%000010	    wire    [7:0]   reg5_next = wr5   ? data_in : reg_out[47:40];
%000008	    wire    [7:0]   reg6_next = wr6   ? data_in : reg_out[55:48];
%000011	    wire    [7:0]   reg7_next = wr7   ? data_in : reg_out[63:56];
%000002	    wire    [7:0]   reg8_next = wr8   ? data_in : reg_out[71:64];
%000009	    wire    [7:0]   reg9_next = wr9   ? data_in : reg_out[79:72];
%000008	    wire    [7:0]   reg10_next = wr10 ? data_in : reg_out[87:80];
%000010	    wire    [7:0]   reg11_next = wr11 ? data_in : reg_out[95:88];
%000006	    wire    [7:0]   reg12_next = wr12 ? data_in : reg_out[103:96];
%000010	    wire    [7:0]   reg13_next = wr13 ? data_in : reg_out[111:104];
%000010	    wire    [7:0]   reg14_next = wr14 ? data_in : reg_out[119:112];
%000013	    wire    [7:0]   reg15_next = wr15 ? data_in : reg_out[127:120];
	
%000000	    wire [7:0] data_out_mux = 
	                    addr == 4'd0  ? reg_out[7:0]     :
	                    addr == 4'd1  ? reg_out[15:8]    :
	                    addr == 4'd2  ? reg_out[23:16]   :
	                    addr == 4'd3  ? reg_out[31:24]   :
	                    addr == 4'd4  ? reg_out[39:32]   :
	                    addr == 4'd5  ? reg_out[47:40]   :
	                    addr == 4'd6  ? reg_out[55:48]   :
	                    addr == 4'd7  ? reg_out[63:56]   :
	                    addr == 4'd8  ? reg_out[71:64]   :
	                    addr == 4'd9  ? reg_out[79:72]   :
	                    addr == 4'd10 ? reg_out[87:80]   :
	                    addr == 4'd11 ? reg_out[95:88]   :
	                    addr == 4'd12 ? reg_out[103:96]  :
	                    addr == 4'd13 ? reg_out[111:104] :
	                    addr == 4'd14 ? reg_out[119:112] :
	                    reg_out[127:120];
	    assign data_out = data_out_mux;
	
	    always @(posedge clk)
	    begin
	        if (rst) begin
	            reg_out <= 128'b0;
	        end
	        else begin
	            reg_out[7:0]     <= reg0_next;
	            reg_out[15:8]    <= reg1_next;
	            reg_out[23:16]   <= reg2_next;
	            reg_out[31:24]   <= reg3_next;
	            reg_out[39:32]   <= reg4_next;
	            reg_out[47:40]   <= reg5_next;
	            reg_out[55:48]   <= reg6_next;
	            reg_out[63:56]   <= reg7_next;
	            reg_out[71:64]   <= reg8_next;
	            reg_out[79:72]   <= reg9_next;
	            reg_out[87:80]   <= reg10_next;
	            reg_out[95:88]   <= reg11_next;
	            reg_out[103:96]  <= reg12_next;
	            reg_out[111:104] <= reg13_next;
	            reg_out[119:112] <= reg14_next;
	            reg_out[127:120] <= reg15_next;
	        end
	    end
	endmodule
	
