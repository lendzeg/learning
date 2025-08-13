// Module: Synchronous ALU of 4 bits
// Author: Nelson Rodriguez
// Project: Silicluster 2025

module alu_4bits(
    input wire       clk,
    input wire [3:0] a,
    input wire [3:0] b,
    input wire [1:0] sel,
    output reg [3:0] result,
    output reg       carry_out,
    output wire      zero_flag    
);

    // Synchronous logic activated by the clock

    always @(posedge clk) begin
        case (sel)
            // 00: Addition
            2'b00: {carry_out, result} <= a + b;

            // 01: Substraction
            2'b01: {carry_out, result} <= a - b; // carry_out works as "borrow"

            // 10: AND
            2'b10: begin
                result <= a & b;
                carry_out <= 1'b0;
            end

            // 11: OR
            2'b11: begin
                result <= a | b;
                carry_out <= 1'b0;
            end

            // Default state for unused combinations
            default: begin
                result <= 4'b0000;
                carry_out <= 1'b0;
            end
        endcase
    end

    // Flag to indicate if the result is zero
    assign zero_flag = (result == 4'b0000);

endmodule