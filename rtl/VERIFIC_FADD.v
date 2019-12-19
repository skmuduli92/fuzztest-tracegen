/*verilator coverage_off */
module VERIFIC_FADD (cin, a, b, o,cout);
  input cin, a, b;
  output cout, o;
  assign {cout, o} = cin + a + b;
endmodule // VERIFIC_FADD
/* verilator coverage_on */
