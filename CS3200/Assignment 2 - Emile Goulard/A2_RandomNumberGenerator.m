%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 2

    Summary:
        This code is meant for executing to answer Question 1.
        It compares the results of my random number generator to the
        built in 'rand' method provided by MATLAB. 

        -numOfRandValues (n): is how many values you wish to randomly generate.
        
%}
function [ ] = A2_RandomNumberGenerator(numOfRandValues)
  
    %Calls my RNG method
    A2_RNGClass.MyRNG(numOfRandValues);
    
    %Calls Built-In RNG method
    A2_RNGClass.BuiltInRNG(numOfRandValues);

end