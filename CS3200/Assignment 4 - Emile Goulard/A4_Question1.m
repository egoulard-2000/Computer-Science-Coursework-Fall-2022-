%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 4

    Summary:
        Answers Question 1 on the Assignment.

        This function plots the Absolute and Relative Errors for 
        approximating N Factorial (n!)
        
%}
function [ ] = A4_Question1()

    e = exp(1); % Euler's Number
    n = 10;
    labels = 1:n;

% ----- Find the Absolute Error for N
   figure(1);
    title("Absolute Error of Stirling's Approximation for N Factorial", 'FontSize', 10);
    hold on;
    absoluteError = zeros(1, n);
    actualSolution = zeros(1, n);

    % Store the Absolute Error at N for each iteration
    for i=1:n
        actualSolution(i) = factorial(i);
        stirlingApprox = sqrt(2 * pi * i) * (i / e)^i;

        % Calculates its percentage 
        absoluteError(i) = abs(actualSolution(i) - stirlingApprox) * 100;
    end

    % Plot the Absolute Error
    plot(absoluteError, 'b', 'LineWidth', 1);
    plot(absoluteError(labels), 'ro', 'LineWidth', 1.5); % Make points at N

    % Legend
    xlabel("N");
    ylabel("Error at N (percentage)");
    box on;
    grid on;

% ----- Find the Relative Error for N
   figure(2);
    title("Relative Error of Stirling's Approximation for N Factorial", 'FontSize', 10);
    hold on;
    relativeError = zeros(1, n);
    actualSolution = zeros(1, n);

    % Store the Relative Error at N for each iteration
    for i=1:n
        actualSolution(i) = factorial(i);
        stirlingApprox = sqrt(2 * pi * i) * (i / e)^i;

        % Calculates its percentage
        relativeError(i) = abs((actualSolution(i) - stirlingApprox)/actualSolution(i)) * 100;
    end

    % Plot the Relative Error
    plot(relativeError, 'b', 'LineWidth', 1);
    plot(relativeError(labels), 'ro', 'LineWidth', 1.5); % Make points at N

    % Legend
    xlabel("N");
    ylabel("Error at N (percentage)");
    box on;
    grid on;

end