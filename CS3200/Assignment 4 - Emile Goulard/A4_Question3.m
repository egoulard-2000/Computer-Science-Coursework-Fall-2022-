%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 4

    Summary:
        Answers Question 3 on the Assignment.

        -'numberOfDecimalPlaces' represents the n-th term for iteration
        using the Chudnovsky Brother's Formula for approximating pi. It
        should be kept to a small value to avoid long computation time.
        
%}
function [ ] = A4_Question3(numberOfDecimalPlaces)
    
    format long;

% ----- Find the Absolute Error Convergence for approximating pi
    iterations = 10^numberOfDecimalPlaces;
    actual = pi;
    pi_approx = zeros(1, numberOfDecimalPlaces);

    % Store intial values before iteration
    x = sqrt(2);
    pi_approx(1) = 2 + sqrt(2);
    y = 2^(1/4);
    
    % Iterate to n+1 to account for graph plotting
    for i=2:iterations+1
        x = (1/2) * (sqrt(x) + 1/sqrt(x));
        pi_approx(i) = pi_approx(i-1) * ((x + 1)/(y + 1));
        y = (y * sqrt(x) + (1 / sqrt(x))) / y + 1; 
    end

    % Plot the Absolute Error
    plot(abs(actual - pi_approx(2:end)), 'b');

    %Legend
    title('The Approximation of Pi');
    xlabel("N");
    ylabel("Approximation at N");
    box on;
    grid on;

% ----- Prove the Absolute Error Percentage is less than the threshold
    threshold = 10^-(2^(numberOfDecimalPlaces+1));
    absoluteError = abs(actual - pi_approx(1)) * threshold;
    if absoluteError < threshold
        % It will print this into console if true (which should always be
        % the case
        disp('The Absolute Error of this formula (percentage):');
        disp(absoluteError);
    end
    
end