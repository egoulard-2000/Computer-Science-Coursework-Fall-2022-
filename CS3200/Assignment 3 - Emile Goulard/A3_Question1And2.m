%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 3

    Summary:
        Answers Question 1 and Question 2 on Assignment 3 pdf. All code for
        implementation is located inside the
        'A3_IntergralQuadratureClass.m' file.

        To run Question 1 and show the results in the command window,
        simply specify which figure number you want to insert to retrieve
        the corresponding Newton-Cotes [wi,xi] pairs.

        To run Question 2 and show the results in the command window,
        simply insert value 4 for figureNum in the parameter. The other
        parameters have no direct affect on the results.
        
%}
function [ ] = A3_Question1And2(a, b, N, figureNum)

% ------ Question 1 ------

    if figureNum == 1 %Composite Midpoint Rule [wi,xi] pairs
        A3_IntegralQuadratureClass.CMidpointRule(a, b, N);
    end
    
    if figureNum == 2 %Composite Trapezoidal Rule [wi,xi] pairs
        A3_IntegralQuadratureClass.CTrapezoidalRule(a, b, N);
    end
    
    if figureNum == 3 %Composite Simpsons Rule [wi,xi] pairs
        A3_IntegralQuadratureClass.CSimpsonRule(a, b, N);
    end

% ------ Question 2 ------ 

    if figureNum == 4 %Gaussian Quadrature
        disp('Gaussian Quadrature for finding [wi,xi] pairs (N=2,3,4,5)');
        disp(' ');
        for N=2:5
            A3_IntegralQuadratureClass.GaussianQuadrature(N);
        end
    end
end