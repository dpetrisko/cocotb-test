
// dff.sv

`timescale 1us/1us

module dff #(parameter width = 4) (
    output logic [width-1:0] q,
    input logic clk, 
    input logic [width-1:0] d
);

always @(posedge clk) begin
    q <= d;
end

endmodule

