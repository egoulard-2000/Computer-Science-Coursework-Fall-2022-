%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 5

    Summary:
        This function runs the 1D Heat Equation code from
        "HeatEquationClass.m" to plot for the different subdivsion
        methods for finding the diffusion of heat of our CPU Processor.

%}
function [ ] = A5()

% ---- (N = 8, 16, 32, 64 & delta time = 0.01s)
    figure(1);
    hold on;
    for i=0:3
        N = 8*2^i;
        deltaT = 0.01;
        HeatEquationClass.Calculate(N, deltaT, true);
    end

% ---- (delta time = 0.1s, 0.01s, 0.001s & N = 32)
    figure(2);
    hold on;
    for i=1:3
        N = 32;
        deltaT = 10^(-i);
        HeatEquationClass.Calculate(N, deltaT, false);
    end

end