// Testbench for alu_4bits

`timescale 1ns / 1ps

module tb_alu_4bits;

    // DUT Inputs
    reg clk_tb;
    reg [3:0] a_tb;
    reg [3:0] b_tb;
    reg [1:0] sel_tb;

    // DUT Outputs
    wire [3:0] result_tb;
    wire       carry_out_tb;
    wire       zero_flag_tb;

    // Instantiate the ALU
    alu_4bits DUT (
        .clk(clk_tb),
        .a(a_tb),
        .b(b_tb),
        .sel(sel_tb),
        .result(result_tb),
        .carry_out(carry_out_tb),
        .zero_flag(zero_flag_tb)
    )

    // Clock generation (50 MHz)
    initial begin
        clk_tb = 0;
        forever #10 clk_tb = ~clk_tb; // 20 ns clock period
    end

    // Test sequence
    initial begin
        // Initialize inputs
        a_tb = 0; b_tb = 0; sel_tb = 0;
        @(posedge clk_tb); // Wait for clock edge

        // Test 1: Addition (5 + 3 = 8)
        a_tb = 4'd5; b_tb = 4'd3; sel_tb = 2'b00;
        @(posedge clk_tb);

        // Test 2: Addition with carry (10 + 7 = 17 -> carry_out = 1)
        a_tb = 4'd10; b_tb = 4'd7; sel_tb = 2'b00;
        @(posedge clk_tb);

        // Test 3: Subtraction (9 - 4 = 5)
        a_tb = 4'd9; b_tb = 4'd4; sel_tb = 2'b01;
        @(posedge clk_tb);

        // Test 4: Subtraction with 0 result (5 - 5 = 0)
        a_tb = 4'd5; b_tb = 4'd5; sel_tb = 2'b01;
        @(posedge clk_tb);

        // Test 5: AND (12 & 10 = 8) -> (1100 & 1010 = 1000)
        a_tb = 4'b1100; b_tb = 4'b1010; sel_tb = 2'b10;
        @(posedge clk_tb);

        // Test 6: OR (12 | 10 = 14) -> (1100 | 1010 = 1110)
        a_tb = 4'b1100; b_tb = 4'b1010; sel_tb = 2'b11;
        @(posedge clk_tb);

        // End of test sequence
        #20;
        $finish;

    end

    // Monitor outputs
    initial begin
        $monitor("T=%0t | sel=%b a=%d b=%d -> result=%d carry=%b zero=%b",
                 $time, sel_tb, a_tb, b_tb, result_tb, carry_out_tb, zero_flag_tb);
    end

endmodule