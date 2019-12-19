// DESCRIPTION: Verilator generated Verilog
// Wrapper module for DPI protected library
// This module requires libverilated_secret.a or libverilated_secret.so to work
// See instructions in your simulator for how to use DPI libraries

module verilated_secret (
        input logic [31:0]  a
        , input logic [31:0]  b
        , output logic [31:0]  x
        , input logic clk
    );
    
    // Checks to make sure the .sv wrapper and library agree
    import "DPI-C" function void verilated_secret_protectlib_check_hash (int protectlib_hash__V);
    
    // Creates an instance of the secret module at initial-time
    // (one for each instance in the user's design) also evaluates
    // the secret module's initial process
    import "DPI-C" function chandle verilated_secret_protectlib_create (string scope__V);
    
    // Updates all non-clock inputs and retrieves the results
    import "DPI-C" function longint verilated_secret_protectlib_combo_update (
        chandle handle__V
        , input logic [31:0]  a
        , input logic [31:0]  b
        , output logic [31:0]  x
    );
    
    // Updates all clocks and retrieves the results
    import "DPI-C" function longint verilated_secret_protectlib_seq_update (
        chandle handle__V
        , output logic [31:0]  x
        , input logic clk
    );
    
    // Need to convince some simulators that the input to the module
    // must be evaluated before evaluating the clock edge
    import "DPI-C" function void verilated_secret_protectlib_combo_ignore (
        chandle handle__V
        , input logic [31:0]  a
        , input logic [31:0]  b
    );
    
    // Evaluates the secret module's final process
    import "DPI-C" function void verilated_secret_protectlib_final (chandle handle__V);
    
    chandle handle__V;
    
    logic [31:0]  x_combo__V;
    logic [31:0]  x_seq__V;
    logic [31:0]  x_tmp__V;
    
    time last_combo_seqnum__V;
    time last_seq_seqnum__V;
    
    // Hash value to make sure this file and the corresponding
    // library agree
    localparam int protectlib_hash__V =
    1254736918;
    
    initial begin
        verilated_secret_protectlib_check_hash(protectlib_hash__V);
        handle__V = verilated_secret_protectlib_create($sformatf("%m"));
    end
    
    // Combinatorialy evaluate changes to inputs
    always @(*) begin
        last_combo_seqnum__V = verilated_secret_protectlib_combo_update(
            handle__V
            , a
            , b
            , x_combo__V
        );
    end
    
    // Evaluate clock edges
    always @(edge(clk)) begin
        verilated_secret_protectlib_combo_ignore(
            handle__V
            , a
            , b
        );
        last_seq_seqnum__V <= verilated_secret_protectlib_seq_update(
            handle__V
            , x_tmp__V
            , clk
        );
        x_seq__V <= x_tmp__V;
    end
    
    // Select between combinatorial and sequential results
    always @(*) begin
        if (last_seq_seqnum__V > last_combo_seqnum__V) begin
            x = x_seq__V;
        end else begin
            x = x_combo__V;
        end
    end
    
    final verilated_secret_protectlib_final(handle__V);
    
endmodule
