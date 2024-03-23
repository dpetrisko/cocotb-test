
// dff.sv

`timescale 1us/1us

typedef struct
{
  logic a;
  logic b;
  logic c;
  logic d;
} mystruct_s;

module dff #(parameter width = 4) (
    output mystruct_s q,
    input logic clk, 
    input mystruct_s d
);

always @(posedge clk) begin
    q <= d;
end

endmodule

