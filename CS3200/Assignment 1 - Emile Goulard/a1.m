%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 1

    Summary:
        Computes the Coffee Cup Problem using Newton's Law of Cooling
        Formula. It will then plot these computations using both Euler
        Approximation and Actual Solution formulas.
        
        -Ti is the initial temperature 
        -Ts is the air temperature 
        -r is the cooling constant 
        -totalTime is the amount of time measured for the function to take place (in minutes)
        -numOfTimeSteps is simply the number of steps to calculate
%}
function [ ] = a1(Ti, Ts, r, totalTime, numOfTimeSteps)
    
 %---- Newton's Law of Cooling Variables And Functions ---- 
    t = linspace(0, totalTime, numOfTimeSteps);
    T = zeros(1, numOfTimeSteps);
    T(1) = Ti; %initial timestamp
    K = (t(2) - t(1)) * r;
    
     %Euler Approximation computation of temperature over time
        for i = 1:numOfTimeSteps-1
            T(i+1) = T(i) - K * (T(i) - Ts);
        end
    
     %Actual Solution for Newton's Law of Cooling for Analysis
        Tsol = Ts + (Ti - Ts) * exp(-r*t);
    
 %---- Graph Components ----

 % This purely compares the step sizes using Euler Approximation and Actual
 % Solution. 
 % 
 % Because these are based on the values provided in Assignment 1,
 % I made these formulas have constant integers to ensure nothing gets
 % changed by variables
 figure(1);
    title('Euler Approximation vs Actual Solution for Step Sizes Provided');
    hold on;

    %Step Sizes from Examples (converted from seconds to minutes)
    %i.e. [30s 15s 10s 5s 1s 0.5s 0.25s]
    stepSizeArr = [0.5 0.25 0.166667 0.0833333 0.0166667 0.00833333 0.004166667];
    stepSizeLength = 7;

    %Euler Approximation Step Size Plots - Green Squares
        for i = 1:stepSizeLength
            stepFunction = 84 + stepSizeArr(i) * -0.025 * (84 - 19);
            plot(stepSizeArr(i), stepFunction, 'gs', 'lineWidth', 2);
        end

    %Analytical Step Size Plots - Blue Circles
        for j = 1:stepSizeLength
            stepFunction = 19 + (84 - 19) * exp(-0.025 * stepSizeArr(j));
            plot(stepSizeArr(j), stepFunction, 'bo', 'lineWidth', 2);
        end

    %Euler Plot - Red Line
        plot(t, T, 'r', 'lineWidth', 2);

    %Legend
    xlabel("Time (t)");
    ylabel("Coffee Temperature (Celsius)");
    box on;
    grid on;

 
 %This purely compares the Euler Approximation to the actual solution to
 %Newton's Law of Cooling. This does NOT inlcude the example Step Sizes
 %from the Assignment, that is in Figure 1.
 figure(2);
    title('Euler Approximation vs. Actual Solution');
    hold on;

    %Euler Plot
        plot(t, T, 'bo', 'lineWidth', 1);

    %Analytical Plot
        x_plot = t(1:numOfTimeSteps/50:end); 
        y_plot = Tsol(1:numOfTimeSteps/50:end);
            plot(x_plot, y_plot, 'r', 'lineWidth', 2);
    
    %Legend
    legend('Euler Approximation', 'Actual Solution', 'Location', 'southwest');
    xlabel("Time (t)");
    ylabel("Coffee Temperature (Celsius)");
    box on;
    grid on;

end
