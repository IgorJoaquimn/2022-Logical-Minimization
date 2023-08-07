module testbench;
  reg [3:0] a, b,other;
  reg [7:0] c, d;
  integer x,z;
  initial
    begin
      $dumpfile("dump.vcd");
  		$dumpvars(1);
    end

  wire o0,o1,o2,o3,o4,o5,o6,o7;
  // instantiate the module connecetions
  multiplicador m( .a(a[3]), .b(a[2]), .c(a[1]), .d(a[0]),.e(b[3]), .f(b[2]), .g(b[1]), .h(b[0]), .o0(o0), .o1(o1), .o2(o2), .o3(o3), .o4(o4), .o5(o5), .o6(o6), .o7(o7));
  
  initial
    begin
      c = 0;
      d = 0;
      for	(x =0; x <= 15; x = x + 1) begin 
        for	(z =0; z <= 15; z = z + 1) begin
          a = x;
          b = z;
          other = z-1;
          c[7] = o0;
          c[6] = o1;
          c[5] = o2;
          c[4] = o3;
          c[3] = o4;
          c[2] = o5;
          c[1] = o6;
          c[0] = o7;
          #2;
          d = x*z;
          $monitor($time,"  %b%b",a,other," %b", c, " expected %b", d);
        end 
      end 
    end
endmodule
