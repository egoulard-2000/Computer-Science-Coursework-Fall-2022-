%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 2

    Summary:
        Solves the solution to the one dimensional integral in Question 2.
        
        -numOfRandValues: the number of random values to output (n)
        -isMyRNG: 
            if true, computes the solution using My RNG creation.
            if false, computes the solution using MATLAB's Built-In RNG
        
%}
function [ ] = A2_MonteCarloMethod(numOfRandValues, isMyRNG)
    
    a = 0;
    b = 1;
    integralApprox = zeros(1, numOfRandValues);

    %---- My PRNG Generator ---- 
    figure(1);
        %Setup seed and values generated array
        vals = zeros(1, numOfRandValues);
        start = 0;
        vals(1) = start;
    
        %---- Use 'my' RNG formula if set to true ---- 
            if isMyRNG == true
                titleVer = "Emile's";
                format longG
                dateSerialNumber = now; %Grab today's date and convert to a serial number
                
                %Loop and generate random numbers for 'n' amount of times
                fprintf('Random Values Generated: \n');
                for i = 1:numOfRandValues
                    start = i + 1;
                    dateSerialNumber = dateSerialNumber * start; %garbage code to keep the serial number random
                    randValue = sign(dateSerialNumber) * (abs(dateSerialNumber) - floor(abs(dateSerialNumber))); %keep it to decimal form
                    vals(i) = abs(randValue); %stores rand value to plot
                    dateSerialNumber = now * now; %reset to a smaller value but still keep it random
    
                    %These checks are here to avoid undefined values
                    if vals(i) <= 0
                        vals(i) = vals(i) + 0.1;
                    end

                    if vals(i) >= 1
                        vals(i) = vals(i) - 0.1;
                    end
                end
                fprintf('%.0f,\n', vals);
            
        %---- Otherwise, use the built-in RNG formula ---- 
            else
                titleVer = "Built-In";
                %Loop and generate random numbers for 'n' amount of times
                fprintf('Random Values Generated: \n');
                for i = 1:numOfRandValues
                    vals(i) = rand;
                end
                fprintf('%.0f,\n', vals);
            end
    
        %---- Now compute the integral using the Monte Carlo approach
            sum = 0;
            for i = 1:numOfRandValues
                x = vals(i);
                y = log(x^2) * log((1 - x)^2);
                sum = sum + y;
                integralApprox(i) = ((b - a) / i) * sum;
            end
        
        %Plot the 'my' randomly generated values 
        x = 0:1:numOfRandValues;
        bar(x);
        bar(vals);
        
        %Then plot the integral approximation
        hold on;
        bar(integralApprox, 0.2);
        hold off;

        grid on
        xlabel("Number of Random Values");
        ylabel("The Value Generated");
        legend({'Random Number Generated','Integral Approximation'},'Location','northwest')

        %(This was done to make it easier to see which graph is which
        %without errors...)
        titleName = strcat(titleVer, " Random Number Generator");
        title(titleName);
        
end