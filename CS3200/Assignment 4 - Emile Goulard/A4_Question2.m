%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 4

    Summary:
        Answers Question 2 on the Assignment.

        This function approximates pi/4 using the Leibniz Series Formula.
        It will then plot the rate of convergence for said series using 
        Shanks Transformation.

        -'numberOfDecimalPlaces' represents the number of siginficant 
        decimal places. It should be kept to a small value to avoid long 
        computation time.
        
%}
function [ ] = A4_Question2(numOfDecimalPlaces)

% ----- This section will approximate pi/4 using the Leibniz Formula
    format long
    actual = pi/4;
    decimals = 10^numOfDecimalPlaces;

    % Loop here to help find the approximation at some number of decimals
    approx = 0;
    for i=0:decimals
        approx = approx + (-1)^(-i)/(2*i+1);
    end

% ----- Compare the values printed for finding pi/4 by printing them out
    disp('Approximation of pi/4:');
    disp(approx);

    disp('Arctan of 1:');
    disp(atan(1));

    disp('Actual Value of pi/4:');
    disp(actual);

% ----- This section will find the rate of convergence of pi/4
% ----- (I will be using Shanks Transformation to achieve this)
    clear approx;

    % Formula for the i^th term
    approx = @(i) (-1)^(i)/(2*i+1);
    totalSum(1) = approx(0);
    rateOfConvergence(1) = totalSum(1) - actual;
    
    % Store the rate of convergence errors
    for k=2:50
        totalSum(k) = totalSum(k-1) + approx(k-1);
        rateOfConvergence(k) = totalSum(k) - actual;
    end
    
    % Plot the rate of convergence for the odd terms
    plot(rateOfConvergence(1:2:end), 'bo', 'LineWidth', 1.5);

    % Legend
    title('Convergence Plot for Approximating pi/4');
    legend('Rate Of Convergence Plot', 'Location', 'northeast');
    xlabel("Number of Iterations");
    ylabel("Integral Value Error");
    box on;
    grid on;

end