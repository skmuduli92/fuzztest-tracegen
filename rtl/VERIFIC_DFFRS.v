/*verilator coverage_off */
module VERIFIC_DFFRS (clk, s, r, d, q);
  input clk, d, s, r;
  output reg q ;
  always @(posedge clk, posedge s, posedge r)
    if (r) q <= 0;
    else if (s) q <= 1;
    else q <= d;
endmodule // VERIFIC_DFFRS
/* verilator coverage_on */
