//      // verilator_coverage annotation
        
        // dff.sv
        
        `timescale 1us/1us
        
        module dff #(parameter width = 4) (
 000041     output logic [width-1:0] q,
 000400     input logic clk, 
 000041     input logic [width-1:0] d
        );
        
 000200 always @(posedge clk) begin
 000200     q <= d;
        end
        
        endmodule
        
        
