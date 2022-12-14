%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 2

    Summary:
        This code is meant to generate two different graphs: my random
        number generator and the built-in random number generator provided
        by MATLAB. It will then output two separate figures for comparison.
        
        DO NOT RUN THIS CLASS! It is a helper class for
        'A2_RandomNumberGenerator.m' to answer Question 1.
        
%}
classdef A2_RNGClass
    methods (Static)
        function MyRNG(numOfRandValues)
            %---- My PRNG Generator ---- 
            figure(1);
                %Setup seed and values generated array
                vals = zeros(1, numOfRandValues);
                start = 0;
                vals(1) = start;
            
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
                
              %---- Plotting Random Values ---- 
                x = 0:1:numOfRandValues;
                bar(x);
                bar(vals);
                xlabel("Number of Random Values");
                ylabel("The Value Generated");
                title("Emile's Random Number Generator");
        end
        function BuiltInRNG(numOfRandValues)
            %---- Built in PRNG Generator -----
            figure(2);
                %Setup values generated array
                vals = zeros(1, numOfRandValues);
            
                %Loop and generate random numbers for 'n' amount of times
                fprintf('Random Values Generated: \n');
                for i = 1:numOfRandValues
                    vals(i) = rand;
                end
                fprintf('%.0f,\n', vals);
            
                x = 0:1:numOfRandValues;
                bar(x);
                bar(vals);
                xlabel("Number of Random Values");
                ylabel("The Value Generated");
                title("Built-in Random Number Generator");
        end
    end
end