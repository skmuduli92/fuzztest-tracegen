	// verilator_coverage annotation
	module oc8051_symbolic_cxrom(
	    clk,
	    rst,
	    word_in,
	    cxrom_addr,
	    pc1,
	    pc2,
	    cxrom_data_out,
	    op_valid,
	    op0_out,
	    op1_out,
	    op2_out
	);
 000336	    input clk, rst;
%000000	    input [31:0] word_in;
%000000	    input [15:0] cxrom_addr;
%000000	    input [15:0] pc1;
%000000	    input [15:0] pc2;
	
%000000	    output [31:0] cxrom_data_out;
%000001	    output op_valid;
%000000	    output [7:0] op0_out;
%000000	    output [7:0] op1_out;
%000000	    output [7:0] op2_out;
	
%000000	    reg [7:0] regarray [15:0];
%000004	    reg [15:0] regvalid;
	
%000000	    wire [3:0] addr0 = cxrom_addr[3:0];
%000001	    wire [3:0] addr1 = cxrom_addr[3:0] + 1;
%000001	    wire [3:0] addr2 = cxrom_addr[3:0] + 2;
%000002	    wire [3:0] addr3 = cxrom_addr[3:0] + 3;
	
%000000	    wire [7:0] bytein0 = word_in[7:0];
%000000	    wire [7:0] bytein1 = word_in[15:8];
%000000	    wire [7:0] bytein2 = word_in[23:16];
%000000	    wire [7:0] bytein3 = word_in[31:24];
	
	    always @(posedge clk) begin
	        if (rst) begin
	            regvalid <= 16'b0;
	        end
	        else begin
	            if (!regvalid[addr0]) begin
	                regarray[addr0] <= bytein0;
	                regvalid[addr0] <= 1;
	            end
	            if (!regvalid[addr1]) begin
	                regarray[addr1] <= bytein1;
	                regvalid[addr1] <= 1;
	            end
	            if (!regvalid[addr2]) begin
	                regarray[addr2] <= bytein2;
	                regvalid[addr2] <= 1;
	            end
	            if (!regvalid[addr3]) begin
	                regarray[addr3] <= bytein3;
	                regvalid[addr3] <= 1;
	            end
	        end
	    end
	
%000000	    wire [7:0] byteout0 = regvalid[addr0] ? regarray[addr0] : bytein0;
%000000	    wire [7:0] byteout1 = regvalid[addr1] ? regarray[addr1] : bytein1;
%000000	    wire [7:0] byteout2 = regvalid[addr2] ? regarray[addr2] : bytein2;
%000000	    wire [7:0] byteout3 = regvalid[addr3] ? regarray[addr3] : bytein3;
	
	    assign cxrom_data_out = { byteout3, byteout2, byteout1, byteout0 };
	    
%000000	    wire [3:0] pc10 = pc1[3:0];
%000001	    wire [3:0] pc11 = pc1[3:0] + 1;
%000001	    wire [3:0] pc12 = pc1[3:0] + 2;
%000002	    wire [3:0] pc13 = pc1[3:0] + 3;
%000001	    wire pc1_valid = regvalid[pc10] && regvalid[pc11] && regvalid[pc12] && regvalid[pc13];
	
%000000	    wire [3:0] pc20 = pc2[3:0];
%000001	    wire [3:0] pc21 = pc2[3:0] + 1;
%000001	    wire [3:0] pc22 = pc2[3:0] + 2;
%000002	    wire [3:0] pc23 = pc2[3:0] + 3;
%000001	    wire pc2_valid = regvalid[pc20] && regvalid[pc21] && regvalid[pc22] && regvalid[pc23];
	
	    assign op_valid = pc1_valid && pc2_valid;
	    assign op0_out = regvalid[pc10] ? regarray[pc10] : 8'b0;
	    assign op1_out = regvalid[pc11] ? regarray[pc11] : 8'b0;
	    assign op2_out = regvalid[pc12] ? regarray[pc12] : 8'b0;
	
%000000	    wire [7:0] regarray0  = regarray[0];
%000000	    wire [7:0] regarray1  = regarray[1];
%000000	    wire [7:0] regarray2  = regarray[2];
%000000	    wire [7:0] regarray3  = regarray[3];
%000000	    wire [7:0] regarray4  = regarray[4];
%000000	    wire [7:0] regarray5  = regarray[5];
%000000	    wire [7:0] regarray6  = regarray[6];
%000000	    wire [7:0] regarray7  = regarray[7];
%000000	    wire [7:0] regarray8  = regarray[8];
%000000	    wire [7:0] regarray9  = regarray[9];
%000000	    wire [7:0] regarray10 = regarray[10];
%000000	    wire [7:0] regarray11 = regarray[11];
%000000	    wire [7:0] regarray12 = regarray[12];
%000000	    wire [7:0] regarray13 = regarray[13];
%000000	    wire [7:0] regarray14 = regarray[14];
%000000	    wire [7:0] regarray15 = regarray[15];
	endmodule
	
