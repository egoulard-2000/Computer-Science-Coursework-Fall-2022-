%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 3

    Summary:
        This code is meant to run the following Newton-Cotes methods for
        finding [wi, xi] pairs.
        
        DO NOT RUN THIS CLASS! It is a helper class for
        'A3_Question1And2.m' to answer Questions 1 and 2.
        
%}
classdef A3_IntegralQuadratureClass
    methods (Static)
    %---- Composite Midpoint Rule ---- 
        function CMidpointRule(a, b, N)
            N_Values = zeros(1, N);
            x = zeros(1, N);
            w = zeros(1, N);

            deltaX = (b - a) / N;
    
            %Find the appropriate wi and xi values for N
            x(1) = a + (1 - 0.5) * deltaX;
            w(1) = deltaX;
            N_Values(1) = 1;
            for i=2:2:N
                x(i) = a + (i - 0.5) * deltaX;
                w(i) = deltaX;
                N_Values(i) = i;
            end
            
            %Display the table
            clc
            disp('Composite Midpoint Rule Table');
            disp(' ');
            T1 = table(N_Values(:),w(:),x(:),'VariableNames',{'N','wi','xi'});
            disp(T1);
        end

    %---- Composite Trapezoidal Rule ----
        function CTrapezoidalRule(a, b, N) 
            N_Values = zeros(1, N);
            x = zeros(1, N);
            w = zeros(1, N);
            deltaX = (b - a) / (N - 1);
    
            N_Values(1) = 1;
            x(1) = a + (1 - 1) * deltaX;
            w(1) = deltaX / 2;

            %Find the appropriate wi and xi values for N
            for i=2:2:N-1
                x(i) = a + (i - 1) * deltaX;
                w(i) = deltaX;
                N_Values(i) = i;
            end

            %Fencepost the final values that weren't iterated over
            x(N) = a + (N - 1) * deltaX;
            w(N) = deltaX / 2;
            N_Values(N) = N;

            %Display the table
            clc
            disp('Composite Trapezoidal Rule Table');
            disp(' ');
            T1 = table(N_Values(:),w(:),x(:),'VariableNames',{'N','wi','xi'});
            disp(T1);
        end

    %---- Composite Simpson's Rule ---- 
        function CSimpsonRule(a, b, N)
            N_Values = zeros(1, 2*N+1);
            x = zeros(1, 2*N+1);
            w = zeros(1, 2*N+1);
            deltaX = (b - a) / (2 * N);

            x(1) = a + (1 - 1) * deltaX;
            w(1) = deltaX / 3;
            N_Values(1) = 1;

            %Find the appropriate wi and xi values for N
            for i=2:2:2*N
                x(i) = a + (i - 1) * deltaX;

                %check if i is even or odd and set the w(i) value
                if mod(i, 2) == 0
                    w(i) = (4 * deltaX) / 3;
                else
                    w(i) = (2 * deltaX) / 3;
                end

                N_Values(i) = i;
            end

            %Fencepost the final values that weren't iterated over
            x(2*N+1) = a + (2*N+1 - 1) * deltaX;
            w(2*N+1) = deltaX / 3;
            N_Values(2*N+1) = 2*N+1;

            %Display the table
            clc
            disp('Composite Simpsons Rule Table');
            disp(' ');
            T1 = table(N_Values(:),w(:),x(:),'VariableNames',{'N','wi','xi'});
            disp(T1);
        end
        
    %---- Gaussian Quadrature 
        function GaussianQuadrature(N)
            format long
            if N == 2
                N_Values = zeros(1, N);
                for i=1:N
                    N_Values(i) = N;
                end

                x = zeros(1, N);
                w = zeros(1, N);

                x(1) = 1 / sqrt(3);
                w(1) = double(1.0000);

                x(2) = -1 / sqrt(3);
                w(2) = double(1.0000);

                disp('Gaussian Quadrature Rule [wi, xi] pairs for N = 2');
                disp(' ');
                T1 = table(N_Values(:),w(:),x(:),'VariableNames',{'N','wi','xi'});
                disp(T1);

            end

            if N == 3
                N_Values = zeros(1, N);
                for i=1:N
                    N_Values(i) = N;
                end

                x = zeros(1, N);
                w = zeros(1, N);

                x(1) = 0;
                w(1) = 8 / 9;

                x(2) = sqrt(3 / 5);
                w(2) = 5/9;

                x(3) = -sqrt(3 / 5);
                w(3) = 5/9;

                disp('Gaussian Quadrature Rule [wi, xi] pairs for N = 3');
                disp(' ');
                T1 = table(N_Values(:),w(:),x(:),'VariableNames',{'N','wi','xi'});
                disp(T1);
            end

            if N == 4
                N_Values = zeros(1, N);
                for i=1:N
                    N_Values(i) = N;
                end

                x = zeros(1, N);
                w = zeros(1, N);

                x(1) = sqrt((3 - 2 * sqrt(6/5)) / 7);
                w(1) = (18 + sqrt(30)) / 36;

                x(2) = -sqrt((3 - 2 * sqrt(6/5)) / 7);
                w(2) = (18 + sqrt(30)) / 36;

                x(3) = sqrt((3 + 2 * sqrt(6/5)) / 7);
                w(3) = (18 - sqrt(30)) / 36; 

                x(4) = -sqrt((3 + 2 * sqrt(6/5)) / 7);
                w(4) = (18 - sqrt(30)) / 36; 

                disp('Gaussian Quadrature Rule [wi, xi] pairs for N = 4');
                disp(' ');
                T1 = table(N_Values(:),w(:),x(:),'VariableNames',{'N','wi','xi'});
                disp(T1);
            end

            if N == 5
                N_Values = zeros(1, N);
                for i=1:N
                    N_Values(i) = N;
                end

                x = zeros(1, N);
                w = zeros(1, N);

                x(1) = 0;
                w(1) = 128 / 225;

                x(2) = (1 / 3) * sqrt(5 - 2 * sqrt(10 / 7));
                w(2) = (322 + 13 * sqrt(70)) / 900;

                x(3) = -(1 / 3) * sqrt(5 - 2 * sqrt(10 / 7));
                w(3) = (322 + 13 * sqrt(70)) / 900;

                x(4) = (1 / 3) * sqrt(5 + 2 * sqrt(10 / 7));
                w(4) = (322 - 13 * sqrt(70)) / 900; 

                x(5) = -(1 / 3) * sqrt(5 + 2 * sqrt(10 / 7));
                w(5) = (322 - 13 * sqrt(70)) / 900; 

                disp('Gaussian Quadrature Rule [wi, xi] pairs for N = 5');
                disp(' ');
                T1 = table(N_Values(:),w(:),x(:),'VariableNames',{'N','wi','xi'});
                disp(T1);
            end
        end
    end
end